#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <random>
#include <cassert>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <list>
#include <functional>
#include <algorithm>

#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TROOT.h"
#include "analysis_functions.cxx"


Double_t peak_fit_function ( Double_t *x, Double_t *par )
{
    return ( par[0] * TMath::Exp ( -0.5 * ( pow ( x[0] - (par[1]), 2 ) / pow ( par[2], 2 ) ) ) )
    + ( par[3] * TMath::Exp ( -0.5 * ( pow ( x[0] - (par[4]), 2 ) / pow ( par[5], 2 ) ) ) );

}

Double_t normalizing_function ( Double_t *x, Double_t *par )
{
    return par[0] * x[0];
}

Double_t fit2D(Double_t *x, Double_t *par) 
{
    return (par[0]*x[0]) + (par[1]*x[1]);
}


void angular_distribution_analyzer_back_sub()
{

    // Fit with Minuit2
    ROOT::Math::MinimizerOptions::SetDefaultMinimizer("Minuit2");
    ROOT::Math::MinimizerOptions::SetDefaultMaxFunctionCalls(1000000);
    ROOT::Math::MinimizerOptions::SetDefaultMaxIterations(1000000);
    ROOT::Math::MinimizerOptions::SetDefaultTolerance(0.001);

	double SX3_bin_width, QQQ5_bin_width, temp_double;
	vector<double> SX3_bin_center_vect;
    vector<double> QQQ5_bin_start_vect;
	int number_of_SX3_bins, number_of_QQQ5_bins;
	double ex_bin_width;
    double QQQ5_z_offset;
	int bin_location_flag = 0;


	TFile *f = new TFile("analysis_output/angular_distribution_histograms.root");
    TFile *file2 = new TFile("analysis_output/CH2_angular_distribution_histograms.root");



	ifstream config_file ( "analysis_output/angular_distribution_config.dat" );

 	string line, temp_string;
    //=====================READING IN THE CALIBRATION FILE=========================
    while ( getline ( config_file,line ) )
    {
    	istringstream in ( line );

    	if(line.find("Number_of_SX3_bins") != std::string::npos)
    	{
        	in >> temp_string >> number_of_SX3_bins;

    	}
        if(line.find("Number_of_QQQ5_bins") != std::string::npos)
        {
            in >> temp_string >> number_of_QQQ5_bins;

        }
    	if(line.find("SX3_bin_width") != std::string::npos)
    	{
        	in >> temp_string >> SX3_bin_width;
    	}
        if(line.find("QQQ5_bin_width") != std::string::npos)
        {
            in >> temp_string >> QQQ5_bin_width;
        }

    	if(line.find("Excitation_bin_width") != std::string::npos)
    	{
        	in >> temp_string >> ex_bin_width;
    	}

        if(line.find("QQQ5_z_offset") != std::string::npos)
        {
            in >> temp_string >> QQQ5_z_offset;
        }

        if(line.find("QQQ5_bin_start=") != std::string::npos)
        {
            temp_double = 0.;
            in >> temp_string >> temp_double;
            QQQ5_bin_start_vect.push_back(temp_double);   
        }

		if(line.find("SX3_bin_center=") != std::string::npos)
    	{
    		temp_double = 0.;
    		in >> temp_string >> temp_double;
    		SX3_bin_center_vect.push_back(temp_double);        	
        }

    }
    config_file.close();


    // Normalizing to the beam current and target thickness
    // From the results of beam_rate_analysis.cxx I have deduced that 
    // each elastic scattering particle corresponds to
    // NbNt of 5.9784x10^24
    // therefore for the entire experiment, NbNt = 9.81605x10^29

    double NbNt = 9.81605*pow(10,29);
    // double NbNt = 4.2402*pow(10,29);



    // ==========================================================
    // =======================   SX3s   =========================
    // ==========================================================



    double SX3_bin_center[number_of_SX3_bins];
    for(int i=0; i<number_of_SX3_bins; i++)
    {
		SX3_bin_center[i] = SX3_bin_center_vect.at(i);
    }


    TH1D * Ex_AngularBin_SX3[number_of_SX3_bins];
    TH1D * CH2_Ex_AngularBin_SX3[number_of_SX3_bins];

    char angular_bin_name[number_of_SX3_bins];
    char angular_bin_name_CH2[number_of_SX3_bins];

    // cout << "number of SX3 bins:  " << number_of_SX3_bins << endl;

    for(int i=1; i<=number_of_SX3_bins; i++)
    {

        // cout << "debug?  " << endl;
        sprintf(angular_bin_name,"SX3_Angular_bin_%d",i);

        

        Ex_AngularBin_SX3[i] = (TH1D*)f->Get(angular_bin_name);
        CH2_Ex_AngularBin_SX3[i] = (TH1D*)file2->Get(angular_bin_name);
        // CH2_Ex_AngularBin_SX3[i]->Scale(5.5197);

        


        // Performing background subtraction
        for(int j=0; j<Ex_AngularBin_SX3[i]->GetNbinsX(); j++ )
        {
            Ex_AngularBin_SX3[i]->SetBinContent(j, Ex_AngularBin_SX3[i]->GetBinContent(j) - (CH2_Ex_AngularBin_SX3[i]->GetBinContent(j)*5.5197));
        }

    }





    TF1* peak_fit[number_of_SX3_bins];
    char peak_fit_name[number_of_SX3_bins];
    double SX3_bin_counts[number_of_SX3_bins];
    double SX3_bin_counts_err[number_of_QQQ5_bins];
    double background_area;

    for(int i=1; i<= number_of_SX3_bins; i++)
    {

    	// cout << "test" << i << endl;
    	sprintf(peak_fit_name,"peak_fit_%d",i);
    	peak_fit[i] = new TF1 ( peak_fit_name,"peak_fit_function",-500, 1200, 6 );

    	peak_fit[i]->SetParameters ( 15, 600, 140, 5, 1100, 140 );

        peak_fit[i]->SetParLimits(1,460, 660);
        peak_fit[i]->SetParLimits(4,1000, 1200);

    	peak_fit[i]->SetParLimits(2,120, 160);
        peak_fit[i]->SetParLimits(5,120, 160);

        Ex_AngularBin_SX3[i]->Fit ( peak_fit_name, "rq" );
    
        //Extracting number of counts in each bin
	    SX3_bin_counts[i-1] = sqrt ( 2 * 3.14159 ) * peak_fit[i]->GetParameter(2) * ( peak_fit[i]->GetParameter(0) / ex_bin_width );
    
        //calculating the (square-root) uncertainty
        SX3_bin_counts_err[i-1] =   sqrt( SX3_bin_counts[i-1] );
    }









    //Calculating solid angles of each bin
    double SX3_bin_SA[number_of_SX3_bins];
    for(int i=0; i< number_of_SX3_bins; i++)
    {
    	SX3_bin_SA[i] =  get_solid_angle("Upstream_SX3", SX3_bin_center[i], SX3_bin_width, -1.0);
	    cout << "SX3 bin info: " << i << "   " << "  SA: " << SX3_bin_SA[i] << "  bin center=  " << SX3_bin_center[i] << endl;

    }


	//Calculating the RELATIVE angular distribution
	double SX3_ang_dist[number_of_SX3_bins];
    double SX3_ang_dist_err[number_of_SX3_bins];
    double SX3_ang_dist_err_COPY[number_of_SX3_bins];
	for(int i=0; i< number_of_SX3_bins; i++)
    {
    	SX3_ang_dist[i] = (SX3_bin_counts[i]/SX3_bin_SA[i]) * ( pow(10,27) / NbNt );
    	SX3_ang_dist_err[i] = (SX3_ang_dist[i] * (SX3_bin_counts_err[i]/SX3_bin_counts[i]));
        SX3_ang_dist_err_COPY[i] = SX3_ang_dist_err[i];

	}

	TGraphErrors* Angular_Distribution_SX3 = new TGraphErrors(number_of_SX3_bins, SX3_bin_center, SX3_ang_dist, 0, SX3_ang_dist_err);




    // ===========================================================
    // =======================   QQQ5s   =========================
    // ===========================================================


    TH1D * Ex_AngularBin_QQQ5[number_of_QQQ5_bins];
    TH1D * CH2_Ex_AngularBin_QQQ5[number_of_QQQ5_bins];

    char angular_bin_name_QQQ5[number_of_QQQ5_bins];

    // cout << "number of QQQ5bins:  " << number_of_QQQ5_bins << endl;

    for(int i=1; i<=number_of_QQQ5_bins; i++)
    {

        // cout << "debug?  " << endl;
        sprintf(angular_bin_name_QQQ5,"QQQ5_Angular_bin_%d",i);

        Ex_AngularBin_QQQ5[i] = (TH1D*)f->Get(angular_bin_name_QQQ5);
        CH2_Ex_AngularBin_QQQ5[i] = (TH1D*)file2->Get(angular_bin_name_QQQ5);

        // Performing background subtraction
        for(int j=0; j<Ex_AngularBin_QQQ5[i]->GetNbinsX(); j++ )
        {
            Ex_AngularBin_QQQ5[i]->SetBinContent(j, Ex_AngularBin_QQQ5[i]->GetBinContent(j) - (CH2_Ex_AngularBin_QQQ5[i]->GetBinContent(j)*5.5197) );
        }
    }

    TF1* peak_fit_QQQ5[number_of_QQQ5_bins];
    char peak_fit_name_QQQ5[number_of_QQQ5_bins];
    double QQQ5_bin_counts[number_of_QQQ5_bins];
    double QQQ5_bin_counts_err[number_of_QQQ5_bins];

    for(int i=1; i<= number_of_QQQ5_bins; i++)
    {

        // cout << "test" << i << endl;
        sprintf(peak_fit_name_QQQ5,"peak_fit_%d",i);
        peak_fit_QQQ5[i] = new TF1 ( peak_fit_name_QQQ5,"peak_fit_function",-500, 1200, 6 );

        peak_fit_QQQ5[i]->SetParameters ( 15, 580, 140, 5, 1100, 140 );
        peak_fit_QQQ5[i]->SetParLimits ( 0, 0, 10000);

        peak_fit_QQQ5[i]->SetParLimits(1,460, 660);
        peak_fit_QQQ5[i]->SetParLimits(4,1000, 1200);

        peak_fit_QQQ5[i]->SetParLimits(2,100, 150);
        peak_fit_QQQ5[i]->SetParLimits(5,100, 150);



        //peak_fit_QQQ5[i]->FixParameter(2,135.);

        Ex_AngularBin_QQQ5[i]->Fit ( peak_fit_name_QQQ5, "rq" );

        //Extracting number of counts in each bin
        QQQ5_bin_counts[i-1] = sqrt ( 2 * 3.14159 ) * peak_fit_QQQ5[i]->GetParameter(2) * ( peak_fit_QQQ5[i]->GetParameter(0) / ex_bin_width );
    
        //calculating the (square-root) uncertainty
        QQQ5_bin_counts_err[i-1] =   sqrt( QQQ5_bin_counts[i-1]  );

        // cout << QQQ5_bin_counts[i-1] << " +/- " << QQQ5_bin_counts_err[i-1] << endl;

    }



    //QQQ5 Angle calculations
    double ring_radius[32] = {2.6475,2.9,3.1475,3.39,3.6275,3.86,
        4.0875,4.31,4.5275,4.74,4.9475,5.15,5.3475,5.54,5.7275,5.919,
        6.0875,6.26,6.4275,6.59,6.7475,6.9,7.0475,7.19,7.3275,7.46,
        7.5875,7.71,7.8275,7.94,8.0475,8.15}; //cm
    double QQQ5_angle[32];
    for(int t=0; t<32; t++)
    {
        QQQ5_angle[t] = 180.0 - (atan(ring_radius[t]/QQQ5_z_offset)*(180./3.14159));
    }



    double QQQ5_bin_start[number_of_QQQ5_bins];
    double QQQ5_bin_center_angle[number_of_QQQ5_bins];

    for(int i=0; i<number_of_QQQ5_bins; i++)
    {
        QQQ5_bin_start[i] = QQQ5_bin_start_vect.at(i);
        QQQ5_bin_center_angle[i] = QQQ5_angle[(int)(QQQ5_bin_start[i]+(QQQ5_bin_width/2))];
    }


    double QQQ5_SA[number_of_QQQ5_bins];
    // double QQQ5_start_strips[8] = {0, 4, 8, 12, 16, 20, 24, 28};
    for(int i=0; i< number_of_QQQ5_bins; i++)
    {
        QQQ5_SA[i] =  get_solid_angle("Upstream_QQQ5", QQQ5_bin_start[i], QQQ5_bin_width, QQQ5_z_offset);
        cout << "QQQ5 bin info: " << i << "   " << QQQ5_bin_start[i] << "  SA: " << QQQ5_SA[i] << "  bin center=  " << QQQ5_bin_center_angle[i] << endl;
    }


    //Calculating the RELATIVE angular distribution
    double QQQ5_ang_dist[number_of_QQQ5_bins];
    double QQQ5_ang_dist_err[number_of_QQQ5_bins];
    for(int i=0; i< number_of_QQQ5_bins; i++)
    {
        QQQ5_ang_dist[i] = (QQQ5_bin_counts[i]/QQQ5_SA[i]) * ( pow(10,27) / NbNt );
        QQQ5_ang_dist_err[i] = (QQQ5_ang_dist[i] * (QQQ5_bin_counts_err[i]/QQQ5_bin_counts[i]));
    }

    TGraphErrors* Angular_Distribution_QQQ5 = new TGraphErrors(number_of_QQQ5_bins, QQQ5_bin_center_angle, QQQ5_ang_dist, 0, QQQ5_ang_dist_err);


    


    vector<int> ignored_bins{ 2, 13, 14};
    // vector<int> ignored_bins{};

    int total_number_of_bins = number_of_SX3_bins + number_of_QQQ5_bins;

    int ignore_bin_flag = 0;

    vector<double> total_ang_dist_temp;
    vector<double> total_ang_dist_err_temp;
    vector<double> total_angles_temp;

    

    // Combining the SX3 and QQQ5 angular distribution into one
    for(int i=0; i<total_number_of_bins; i++)
    {

        // Removing bins to be ignored
        ignore_bin_flag=0;
        for(int k=0; k<ignored_bins.size(); k++)
        {
            if(ignored_bins.at(k) == i) ignore_bin_flag=1;
        }

        if(i < number_of_SX3_bins && ignore_bin_flag==0)
        {
            total_ang_dist_temp.push_back(SX3_ang_dist[i]);
            total_ang_dist_err_temp.push_back(SX3_ang_dist_err[i]);

            total_angles_temp.push_back(SX3_bin_center[i]);
        }
        if(i >= number_of_SX3_bins && ignore_bin_flag==0)
        {
            total_ang_dist_temp.push_back(QQQ5_ang_dist[i-number_of_SX3_bins]);
            total_ang_dist_err_temp.push_back(QQQ5_ang_dist_err[i-number_of_SX3_bins]);

            total_angles_temp.push_back(QQQ5_bin_center_angle[i-number_of_SX3_bins]);
        }
    }

    // Turning the temporary vectors into arrays for plotting and normalizing
    double total_ang_dist[total_ang_dist_temp.size()];
    double total_ang_dist_err[total_ang_dist_temp.size()];
    double total_angles[total_ang_dist_temp.size()];
    for(int i=0; i<total_ang_dist_temp.size(); i++)
    {
        total_ang_dist[i] = total_ang_dist_temp.at(i);
        total_ang_dist_err[i] = total_ang_dist_err_temp.at(i);
        total_angles[i] = total_angles_temp.at(i);
    }




    TGraphErrors* total_ang_dist_plot = new TGraphErrors(total_number_of_bins, total_angles, total_ang_dist, 0, total_ang_dist_err);


    // Normalizing the Theoretical cross sections to the observed
    // ==========================================================



    //TWOFNR 3s1/2 kinematics
    ifstream gState_kinematics ( "3s1h_FR-ADWA.txt" );

    int u=0;
    double xK0[200];
    double yK0[200];

    while ( getline ( gState_kinematics,line ) )
    {
        istringstream in ( line );
        in >> xK0[u] >> yK0[u];
        u++;
    }
    TGraph* kin_line_3s1h = new TGraph ( u,xK0,yK0 );

    vector<double> angle_3s1h;
    vector<double> xsec_3s1h;
    for(int i = u-1; i > -1; i--) 
    {
        angle_3s1h.push_back(xK0[i]);
        xsec_3s1h.push_back(yK0[i]);
    }

    CubicSpline spline_3s1h(angle_3s1h, xsec_3s1h);
    double DWBA_3s1h_xsection[total_number_of_bins];
    for(int i = 0; i < total_number_of_bins; i++) {
        DWBA_3s1h_xsection[i] = spline_3s1h(total_angles[i]);
        cout << total_angles[i] << "   " << DWBA_3s1h_xsection[i] << endl;
    }

    TGraphErrors* norm_3s1h = new TGraphErrors(total_number_of_bins, DWBA_3s1h_xsection, total_ang_dist, 0, total_ang_dist_err);

    TF1 *linFit_3s1h = new TF1("linFit_3s1h", "normalizing_function", 0, 10, 1);
    linFit_3s1h->SetParLimits(0, 0., 400.);
    norm_3s1h->Fit("linFit_3s1h", "rq");

    cout << "3s1h normalizing parameter:   " << linFit_3s1h->GetParameter(0) << endl;
    double S_3s1h = linFit_3s1h->GetParameter(0);

    double DWBA_3s1h_xsection_NORM[angle_3s1h.size()];
    double DWBA_3s1h_angle[angle_3s1h.size()];
    for(int i=0; i<angle_3s1h.size(); i++)
    {
        DWBA_3s1h_xsection_NORM[i] = (xsec_3s1h.at(i)*S_3s1h);
        DWBA_3s1h_angle[i] = angle_3s1h.at(i);
    }

    TGraph* normalized_3s1h = new TGraph(u,DWBA_3s1h_angle,DWBA_3s1h_xsection_NORM );










    //TWOFNR 2d5/2 kinematics
    ifstream gState_kinematics2 ( "2d5h_FR-ADWA.txt" );

    int u2=0;
    double xK02[200];
    double yK02[200];

    while ( getline ( gState_kinematics2,line ) )
    {
        istringstream in ( line );
        in >> xK02[u2] >> yK02[u2];
        u2++;
    }
    TGraph* kin_line_2d5h = new TGraph ( u2,xK02,yK02 );

    vector<double> angle_2d5h;
    vector<double> xsec_2d5h;
    for(int i = u2-1; i > -1; i--) 
    {
        angle_2d5h.push_back(xK02[i]);
        xsec_2d5h.push_back(yK02[i]);
    }

    CubicSpline spline_2d5h(angle_2d5h, xsec_2d5h);
    double DWBA_2d5h_xsection[total_number_of_bins];
    for(int i = 0; i < total_number_of_bins; i++) {
        DWBA_2d5h_xsection[i] = spline_2d5h(total_angles[i]);
        cout << total_angles[i] << "   " << DWBA_2d5h_xsection[i] << "   " << total_ang_dist[i] << "  " << total_ang_dist_err[i] << endl;
    }
    
    TGraphErrors* norm_2d5h = new TGraphErrors(total_number_of_bins, DWBA_2d5h_xsection, total_ang_dist, 0, total_ang_dist_err);

    TF1 *linFit_2d5h = new TF1("linFit_2d5h", "normalizing_function", 1, 7, 1);
    linFit_2d5h->SetParLimits(0, 0., 400.);
    linFit_2d5h->SetParameter(0, 200);
    norm_2d5h->Fit("linFit_2d5h", "rq");

    cout << "2d5h normalizing parameter:   " << linFit_2d5h->GetParameter(0) << endl;
    double S_2d5h = linFit_2d5h->GetParameter(0);

    double DWBA_2d5h_xsection_NORM[angle_2d5h.size()];
    double DWBA_2d5h_angle[angle_2d5h.size()];
    for(int i=0; i<angle_2d5h.size(); i++)
    {
        DWBA_2d5h_xsection_NORM[i] = (xsec_2d5h.at(i)*S_2d5h);
        DWBA_2d5h_angle[i] = angle_2d5h.at(i);
    }

    TGraph* normalized_2d5h = new TGraph(u2,DWBA_2d5h_angle,DWBA_2d5h_xsection_NORM );



    TCanvas* c0 = new TCanvas("c0", "c0", 400, 400);

    c0->cd();
    norm_3s1h->Draw("A*");





    // ===================================================================================
    //
    //        Minimizing a linear combination of both the 3s1h and 2d5h states
    //
    // ===================================================================================

    TGraph2DErrors *comb_fit_2D = new TGraph2DErrors(total_number_of_bins, DWBA_3s1h_xsection, DWBA_2d5h_xsection, total_ang_dist, 0, 0, total_ang_dist_err);
    TF2 *f2 = new TF2("f2",fit2D,0,50,0,50, 2);
    f2->SetParameters(0.5, 0.5);
    f2->SetParLimits(0, 0.0, 100);
    f2->SetParLimits(1, 0, 100);

    comb_fit_2D->Fit("f2");
    cout << "====================================================================" << endl;
    cout << "                             RESULTS                                " << endl;
    cout << endl;
    cout << "  3s1/2 norm factor =" << setw(10) << f2->GetParameter(0) << endl;
    cout << "  2d5/2 norm factor =" << setw(10) << f2->GetParameter(1) << endl;


    // Normalizing the DWBA angular distributions
    vector<double> abs_xsection_3s1h;
    vector<double> abs_xsection_2d5h;

    double DWBA_3s1h_xsection_LinCom[angle_3s1h.size()];
    for(int i=0; i<angle_3s1h.size(); i++)
    {
        DWBA_3s1h_xsection_LinCom[i] = (xsec_3s1h.at(i)*f2->GetParameter(0));

        //filling vector of absolute x section
        abs_xsection_3s1h.push_back( xsec_3s1h.at(i)*f2->GetParameter(0) );
    }
    TGraph* LinCom_3s1h = new TGraph(u2,DWBA_3s1h_angle,DWBA_3s1h_xsection_LinCom );


    double DWBA_2d5h_xsection_LinCom[angle_2d5h.size()];
    for(int i=0; i<angle_2d5h.size(); i++)
    {
        DWBA_2d5h_xsection_LinCom[i] = (xsec_2d5h.at(i)*f2->GetParameter(1));
        
        //filling vector of absolute x section
        abs_xsection_2d5h.push_back( xsec_2d5h.at(i)*f2->GetParameter(1) );

    }
    TGraph* LinCom_2d5h = new TGraph(u2,DWBA_2d5h_angle,DWBA_2d5h_xsection_LinCom );

    cout << "RATIO:  " << (1.0*f2->GetParameter(0)) / (1.0*f2->GetParameter(1)) << endl;

    double DWBA_combined_LinCom[angle_2d5h.size()];
    for(int i=0; i<angle_2d5h.size(); i++)
    {
        DWBA_combined_LinCom[i] = (xsec_2d5h.at(i)*f2->GetParameter(1)) + (spline_3s1h( angle_2d5h.at(i) )*f2->GetParameter(0));
    }
    TGraph* Total_LinCom = new TGraph(u2,DWBA_2d5h_angle,DWBA_combined_LinCom );


    // Integrating the two xsections in the 500 keV peak across the angles in
    // the QQQ5 detectors:

    double integral_3s1h = integrate_func(angle_3s1h, abs_xsection_3s1h, 135.8, 163.4);
    double integral_2d5h = integrate_func(angle_2d5h, abs_xsection_2d5h, 135.8, 163.4);
    cout << "3s1h INTEGRAL in QQQ5:   " << integral_3s1h << endl;
    cout << "2d5h INTEGRAL in QQQ5:   " << integral_2d5h << endl;
    cout << "3s1h:2d5h INTEGRAL ratio:   " << integral_3s1h / integral_2d5h << endl;























	//Output root file for histograms
    TFile write("analysis_output/angular_distribution_result.root", "recreate");

    Angular_Distribution_SX3->Write();



    TCanvas* c1 = new TCanvas("c1", "c1", 400, 400);
    TCanvas* c2 = new TCanvas("c2", "c2", 400, 400);
    TCanvas* c3 = new TCanvas("c3", "c3", 400, 400);
    TCanvas* c4 = new TCanvas("c4", "c4", 400, 400);
    TCanvas* c5 = new TCanvas("c5", "c5", 400, 400);

    c1->Divide(3,3);
    c4->Divide(3,3);



    for(int k=1; k<=number_of_SX3_bins; k++)
    {
        c1->cd(k);
        Ex_AngularBin_SX3[k]->GetXaxis()->SetRangeUser(-500, 1800);
        Ex_AngularBin_SX3[k]->Draw();
    }



    for(int k=1; k<=number_of_QQQ5_bins; k++)
    {
        c4->cd(k);
        Ex_AngularBin_QQQ5[k]->GetXaxis()->SetRangeUser(-500, 1800);
        Ex_AngularBin_QQQ5[k]->Draw();
    }

    

    TMultiGraph *observed_anglular_distributions = new TMultiGraph();
    observed_anglular_distributions->SetTitle("Observed relative angular distribution for peak at 500-600 keV");
    TLegend *ang_dist_leg = new TLegend(0.1, 0.52, 0.45, 0.9);
    Angular_Distribution_SX3->SetMarkerColor(kRed);
    Angular_Distribution_QQQ5->SetMarkerColor(kBlue);
    Angular_Distribution_SX3->SetMarkerStyle(23);
    Angular_Distribution_QQQ5->SetMarkerStyle(23);
    normalized_3s1h->SetLineColor(kRed);
    normalized_2d5h->SetLineColor(kBlue);

    c2->cd();
    observed_anglular_distributions->Add(Angular_Distribution_SX3, "p");
    observed_anglular_distributions->Add(Angular_Distribution_QQQ5, "p");
    observed_anglular_distributions->Add(normalized_3s1h, "l");
    observed_anglular_distributions->Add(normalized_2d5h, "l");
    ang_dist_leg->AddEntry(Angular_Distribution_SX3, "SX3's");
    ang_dist_leg->AddEntry(Angular_Distribution_QQQ5, "QQQ5's");
    ang_dist_leg->AddEntry(normalized_3s1h, "3s1h");
    ang_dist_leg->AddEntry(normalized_2d5h, "2d5h");
    observed_anglular_distributions ->GetXaxis()->SetTitle("Lab angle [Degrees]");
    observed_anglular_distributions ->GetYaxis()->SetTitle("RELATIVE angular disribution [arb]");
    observed_anglular_distributions ->GetXaxis()->SetRangeUser(90, 180);
    observed_anglular_distributions->Draw("a");
    ang_dist_leg->SetBorderSize(0);
    ang_dist_leg->Draw();
    observed_anglular_distributions->Draw();
    c2->Update();

    TMultiGraph *TWOFNR_plot = new TMultiGraph();
    TWOFNR_plot->SetTitle("TWOFNR transfers to states at ~600 keV - unit Spectroscopic factors");
    TLegend *TWOFNR_leg = new TLegend(0.1, 0.52, 0.45, 0.9);
    kin_line_3s1h->SetLineColor(kRed);
    kin_line_2d5h->SetLineColor(kBlue);

    c3->cd();
    TWOFNR_plot->Add(kin_line_3s1h, "l");
    TWOFNR_leg->AddEntry(kin_line_3s1h, "3s1/2", "l");
    TWOFNR_plot->Add(kin_line_2d5h, "l");
    TWOFNR_leg->AddEntry(kin_line_2d5h, "2d5/2", "l");
    TWOFNR_plot->Add(Angular_Distribution_SX3, "AC*");
    TWOFNR_leg->AddEntry(Angular_Distribution_SX3, "500-600 keV peak", "AC*");
    TWOFNR_plot ->GetXaxis()->SetTitle("Lab angle [Degrees]");
    TWOFNR_plot ->GetYaxis()->SetTitle("d#sigma/d#Omega `[mb/sr]");
    TWOFNR_plot->Draw("a");
    TWOFNR_leg->SetBorderSize(0);
    TWOFNR_leg->Draw();
    TWOFNR_plot->Draw();
    c3->Update();

    TMultiGraph *observed_anglular_distributions_LinCom = new TMultiGraph();
    observed_anglular_distributions_LinCom->SetTitle("Observed relative angular distribution for peak at 500-600 keV");
    TLegend *ang_dist_leg_LinCom = new TLegend(0.1, 0.52, 0.45, 0.9);
    // Angular_Distribution_SX3->SetMarkerColor(kRed);
    // Angular_Distribution_QQQ5->SetMarkerColor(kBlue);
    Angular_Distribution_SX3->SetMarkerStyle(23);
    Angular_Distribution_QQQ5->SetMarkerStyle(23);
    LinCom_3s1h->SetLineColor(kRed);
    LinCom_2d5h->SetLineColor(kBlue);
    LinCom_3s1h->SetLineWidth(2);
    LinCom_2d5h->SetLineWidth(2);

    c5->cd();
    observed_anglular_distributions_LinCom->Add(total_ang_dist_plot, "p");
    observed_anglular_distributions_LinCom->Add(LinCom_3s1h, "l");
    observed_anglular_distributions_LinCom->Add(LinCom_2d5h, "l");
    observed_anglular_distributions_LinCom->Add(Total_LinCom, "l");
    ang_dist_leg_LinCom->AddEntry(total_ang_dist_plot, "This measurement");
    //ang_dist_leg_LinCom->AddEntry(Angular_Distribution_QQQ5, "QQQ5's");
    ang_dist_leg_LinCom->AddEntry(normalized_3s1h, "3s1h");
    ang_dist_leg_LinCom->AddEntry(normalized_2d5h, "2d5h");
    ang_dist_leg_LinCom->AddEntry(Total_LinCom, "Combined");
    observed_anglular_distributions_LinCom ->GetXaxis()->SetTitle("Lab angle [Degrees]");
    observed_anglular_distributions_LinCom ->GetYaxis()->SetTitle("RELATIVE angular disribution [arb]");
    observed_anglular_distributions_LinCom ->GetXaxis()->SetRangeUser(90, 180);
    observed_anglular_distributions_LinCom->Draw("a");
    ang_dist_leg_LinCom->SetBorderSize(0);
    ang_dist_leg_LinCom->Draw();
    observed_anglular_distributions_LinCom->Draw();
    c5->Update();


	return;
}