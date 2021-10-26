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

Double_t gaus_and_pol0 ( Double_t *x, Double_t *par )
{
    return (par[0] * TMath::Exp ( -0.5 * ( pow ( x[0] - (par[1]), 2 ) / pow ( par[2], 2 ) ) ) ) + 4;
}



int BeamEnergy_gammaAnalysis()
{


    TCutG *GamLine = new TCutG("GamLine",6);
    GamLine->SetPoint(0,0.101086,11.4267);
    GamLine->SetPoint(1,0.100833,10.9276);
    GamLine->SetPoint(2,0.158495,-12.6261);
    GamLine->SetPoint(3,0.158647,-11.8776);
    GamLine->SetPoint(4,0.100985,11.6762);
    GamLine->SetPoint(5,0.101086,11.4267);    








    TCanvas* c1 = new TCanvas("c1", "c1", 400, 400);
    TCanvas* c2 = new TCanvas("c2", "c2", 400, 400);


    TH2D* gamma_test = new TH2D("gamma_test", "gamma_test", 720, 0, 360, 75, 550, 700);

    TGraph* mean_difference = new TGraph(500);

    string line;
    double thetaGamma, enGamma;
    vector<double> gamEn_vect;
    vector<double> gamAngle_vect;
    double gamma_correction;

    ifstream gammaVector ( "BeamEnergy_gamma_output_file.txt" );

    if ( !gammaVector )
    {
        cout << "Cannot open gamma info file, you doughnut..." << endl;
        return 1;
    }

    //=====================READING IN THE CALIBRATION FILE=========================
    while ( getline ( gammaVector,line ) )
    {

        istringstream in ( line );
        in >> thetaGamma >> enGamma;

        gamEn_vect.push_back(enGamma);
        gamAngle_vect.push_back(thetaGamma);

        gamma_test->Fill(thetaGamma, enGamma);

    }



	// ================ Histograms and Canvases ==================
    TH1D* gam_proj_7 = new TH1D("gam_proj_7", "gam_proj_7", 120, 550, 700);
    TH1D* gam_proj_8 = new TH1D("gam_proj_8", "gam_proj_8", 120, 550, 700);
    TH1D* gam_proj_9 = new TH1D("gam_proj_9", "gam_proj_9", 120, 550, 700);
    TH1D* gam_proj_10 = new TH1D("gam_proj_10", "gam_proj_10", 120, 550, 700);
    TH1D* gam_proj_11 = new TH1D("gam_proj_11", "gam_proj_11", 120, 550, 700);
    TH1D* gam_proj_12 = new TH1D("gam_proj_12", "gam_proj_12", 120, 550, 700);
    TH1D* gam_proj_13 = new TH1D("gam_proj_13", "gam_proj_13", 120, 550, 700);
    TH1D* gam_proj_14 = new TH1D("gam_proj_14", "gam_proj_14", 120, 550, 700);
    TH1D* gam_proj_15 = new TH1D("gam_proj_15", "gam_proj_15", 120, 550, 700);
    TH1D* gam_proj_16 = new TH1D("gam_proj_16", "gam_proj_16", 120, 550, 700);


    TF1* gaus_fit = new TF1("gaus_fit", "gaus(0)", 550, 700);
    double mean_7, mean_8, mean_9, mean_10, mean_11, mean_12, mean_13, mean_14, mean_15, mean_16;
    double std_dev_8, std_dev_12;

    int count = 0;
    //Finding correct beam energy
    for(double beta_loop=0.1; beta_loop<0.16; beta_loop=beta_loop+0.0002)
    {

        //Filling the histograms for each angular bin
        for(int event = 0; event < gamEn_vect.size(); event++)
        {
            gamma_correction = gamEn_vect.at(event) * (1. - beta_loop*cos(gamAngle_vect.at(event)*(3.14159/180.))) / (sqrt( 1. - pow(beta_loop,2) ));

            if( gamAngle_vect.at(event)>= 70 && gamAngle_vect.at(event)< 80 ) gam_proj_7->Fill(gamma_correction);
            if( gamAngle_vect.at(event)>= 80 && gamAngle_vect.at(event)< 90 ) gam_proj_8->Fill(gamma_correction);
            if( gamAngle_vect.at(event)>= 90 && gamAngle_vect.at(event)< 100 ) gam_proj_9->Fill(gamma_correction);
            if( gamAngle_vect.at(event)>= 100 && gamAngle_vect.at(event)< 110 ) gam_proj_10->Fill(gamma_correction);
            if( gamAngle_vect.at(event)>= 110 && gamAngle_vect.at(event)< 120 ) gam_proj_11->Fill(gamma_correction);
            if( gamAngle_vect.at(event)>= 120 && gamAngle_vect.at(event)< 130 ) gam_proj_12->Fill(gamma_correction);
            if( gamAngle_vect.at(event)>= 130 && gamAngle_vect.at(event)< 140 ) gam_proj_13->Fill(gamma_correction);
            if( gamAngle_vect.at(event)>= 140 && gamAngle_vect.at(event)< 150 ) gam_proj_14->Fill(gamma_correction);
            if( gamAngle_vect.at(event)>= 150 && gamAngle_vect.at(event)< 160 ) gam_proj_15->Fill(gamma_correction);
            if( gamAngle_vect.at(event)>= 160 && gamAngle_vect.at(event)< 170 ) gam_proj_16->Fill(gamma_correction);

        }


        gaus_fit->SetParLimits(1, 550, 700);
        gaus_fit->SetParLimits(2, 0, 8.5);
        gam_proj_7->Fit("gaus_fit", "rq");
        mean_7 = gaus_fit->GetParameter(1);

        gaus_fit->SetParLimits(1, 550, 700);
        gaus_fit->SetParLimits(2, 0, 8.5);
        gam_proj_8->Fit("gaus_fit", "rq");
        mean_8 = gaus_fit->GetParameter(1);
        std_dev_8 = gaus_fit->GetParameter(2);

        gaus_fit->SetParLimits(1, 550, 700);
        gaus_fit->SetParLimits(2, 0, 8.5);
        gam_proj_9->Fit("gaus_fit", "rq");
        mean_9 = gaus_fit->GetParameter(1);

        gaus_fit->SetParLimits(1, 550, 700);
        gaus_fit->SetParLimits(2, 0, 8.5);
        gam_proj_10->Fit("gaus_fit", "rq");
        mean_10 = gaus_fit->GetParameter(1);

        gaus_fit->SetParLimits(1, 550, 700);
        gaus_fit->SetParLimits(2, 0, 8.5);
        gam_proj_11->Fit("gaus_fit", "rq");
        mean_11 = gaus_fit->GetParameter(1);

        gaus_fit->SetParLimits(1, 550, 700);
        gaus_fit->SetParLimits(2, 0, 8.5);
        gam_proj_12->Fit("gaus_fit", "rq");
        mean_12 = gaus_fit->GetParameter(1);
        std_dev_12 = gaus_fit->GetParameter(2);

        gaus_fit->SetParLimits(1, 550, 700);
        gaus_fit->SetParLimits(2, 0, 8.5);
        gam_proj_13->Fit("gaus_fit", "rq");
        mean_13 = gaus_fit->GetParameter(1);

        gaus_fit->SetParLimits(1, 550, 700);
        gaus_fit->SetParLimits(2, 0, 8.5);
        gam_proj_14->Fit("gaus_fit", "rq");
        mean_14 = gaus_fit->GetParameter(1);

        gaus_fit->SetParLimits(1, 550, 700);
        gaus_fit->SetParLimits(2, 0, 8.5);
        gam_proj_15->Fit("gaus_fit", "rq");
        mean_15 = gaus_fit->GetParameter(1);

        gaus_fit->SetParLimits(1, 550, 700);
        gaus_fit->SetParLimits(2, 0, 8.5);
        gam_proj_16->Fit("gaus_fit", "rq");
        mean_16 = gaus_fit->GetParameter(1);

        if(std_dev_8*2.355 <= 20 && std_dev_12*2.355 <= 20 && GamLine->IsInside(beta_loop, 1.0*(mean_8 - mean_12))) 
        {
            mean_difference->SetPoint(count, beta_loop, 1.0*(mean_8 - mean_12));

        }



        cout << beta_loop << "   " << mean_8 - mean_12 << "   " << std_dev_8*2.355 << "  " << std_dev_12*2.355 << endl;

        gam_proj_7->Reset("ICESM");
        gam_proj_8->Reset("ICESM");
        gam_proj_9->Reset("ICESM");
        gam_proj_10->Reset("ICESM");
        gam_proj_11->Reset("ICESM");
        gam_proj_12->Reset("ICESM");
        gam_proj_13->Reset("ICESM");
        gam_proj_14->Reset("ICESM");
        gam_proj_15->Reset("ICESM");
        gam_proj_16->Reset("ICESM");

        count++;


    }


    TF1* lin_fit = new TF1("lin_fit", "pol1", 0.1, 0.16);

    mean_difference->Fit("lin_fit", "r");

    double intercept = lin_fit->GetParameter(0);
    double grad = lin_fit->GetParameter(1);

    double intercept_err = lin_fit->GetParError(0);
    double grad_err = lin_fit->GetParError(1);

    double BeamEnergyResult = -((1.0*intercept) / (1.0*grad));

    double BeamEnergyResult_err = BeamEnergyResult * sqrt( pow(((1.0*intercept_err)/(1.0*intercept)),2) + pow(((1.0*grad_err)/(1.0*grad)),2) );


    cout << "Beam beta =  " << BeamEnergyResult << " +/- " << BeamEnergyResult_err << endl;



    c1->cd();
    gamma_test->Draw("COLZ");

    c2->cd();
    mean_difference->Draw("AP");

	return 0;
}
