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



int BB10_calibrator()
{



	// Creating the Chain of runs to use
	TChain* Chain = new TChain ( "data" );

    //================== CD2 Runs ====================
    //================================================
/*
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run001_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run002_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run003_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run004_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run005_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run006_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run007_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run008_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run009_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run010_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run011_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run012_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run013_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run014_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run015_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run016_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run017_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run018_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run019_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run020_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run021_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run022_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run023_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run024_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run025_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run026_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run027_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run028_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run029_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run030_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run031_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run032_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run033_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run034_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run035_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run036_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run037_combined.root");
	Chain->Add("/mnt/se82dp_2/se82dp_data/Run038_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run039_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run040_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run041_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run042_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run043_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run044_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run045_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run046_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run047_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run048_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run049_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run050_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run051_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run052_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run053_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run054_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run055_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run056_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run057_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run058_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run059_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run060_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run061_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run062_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run063_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run064_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run065_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run066_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run067_combined.root");




    Chain->Add("/mnt/se82dp_2/se82dp_data/Run095_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run096_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run097_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run098_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run099_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run100_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run101_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run102_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run103_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run104_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run105_combined.root");

*/


    //================== CH2 Runs ====================
    //================================================
    /*
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run068_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run069_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run070_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run071_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run072_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run073_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run074_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run075_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run076_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run077_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run078_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run079_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run080_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run081_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run082_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run083_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run084_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run085_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run086_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run087_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run088_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run089_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run090_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run091_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run092_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run093_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_data/Run094_combined.root");
    */



    //============== Calibration Runs ================
    //================================================
    Chain->Add("/mnt/se82dp_2/cal_merged/Run301.root");     //alpha_dEcal_0deg.ldf         --Good for upstream QQQ5's
    Chain->Add("/mnt/se82dp_2/cal_merged/Run302.root");     //alpha_dEcal_60deg.ldf
    Chain->Add("/mnt/se82dp_2/cal_merged/Run303.root");     //alpha_dEcal_120deg.ldf
    Chain->Add("/mnt/se82dp_2/cal_merged/Run304.root");     //alpha_dEcal_180deg.ldf
    Chain->Add("/mnt/se82dp_2/cal_merged/Run305.root");     //alpha_dEcal_240deg.ldf
    Chain->Add("/mnt/se82dp_2/cal_merged/Run306.root");     //alpha_dEcal_300deg.ldf


    //SX3 Energy Calibration
    string line;
    double BSX3_Encal[2][12][4][2] = {0};
    double temp_intercept, temp_slope;
    int temp_det, temp_strip, temp_sector;

    ifstream BSX3Up_Encal_params ( "cal/cal_params/BSX3Up_Encal.dat" );

    if ( !BSX3Up_Encal_params )
    {
        cout << "Cannot open upstream Super X3 energy calibration file, you doughnut..." << endl;
        return 1;
    }

    //=====================READING IN THE CALIBRATION FILE=========================
    while ( getline ( BSX3Up_Encal_params,line ) )
    {
        istringstream in ( line );
        in >> temp_det >> temp_strip >> temp_sector >> temp_intercept >> temp_slope;

        BSX3_Encal[1][temp_det][temp_sector][0] = temp_intercept;
        BSX3_Encal[1][temp_det][temp_sector][1] = temp_slope;
    }


    ifstream BSX3Dn_Encal_params ( "cal/cal_params/BSX3Dn_Encal.dat" );

    if ( !BSX3Dn_Encal_params )
    {
        cout << "Cannot open downstream Super X3 energy calibration file, you doughnut..." << endl;
        return 1;
    }

    //=====================READING IN THE CALIBRATION FILE=========================
    while ( getline ( BSX3Dn_Encal_params,line ) )
    {
        istringstream in ( line );
        in >> temp_det >> temp_strip >> temp_sector >> temp_intercept >> temp_slope;

        BSX3_Encal[0][temp_det][temp_sector][0] = temp_intercept;
        BSX3_Encal[0][temp_det][temp_sector][1] = temp_slope;
    }



    //BB10 Energy Calibration
    double BB10_Encal[12][8][2] = {0};

    ifstream BB10_Encal_params ( "cal/cal_params/BB10_Encal.dat" );

    if ( !BB10_Encal_params )
    {
        cout << "Cannot open upstream BB10 energy calibration file, you doughnut..." << endl;
        return 1;
    }

    //=====================READING IN THE CALIBRATION FILE=========================
    while ( getline ( BB10_Encal_params,line ) )
    {
        istringstream in ( line );
        in >> temp_det >> temp_strip >> temp_intercept >> temp_slope;

        

        BB10_Encal[temp_det][temp_strip][0] = temp_intercept;
        BB10_Encal[temp_det][temp_strip][1] = temp_slope;
    }



	// ===================== Data variables =====================
	// 
	//  === BB10 ===
	int   BB10Mul = 0;
    int   BB10Det[512] = {0};
	int   BB10Strip[512] = {0};
	int   BB10Channel[512] = {0};
	int   BB10ADC[512] = {0};
	float BB10Energy[512] = {0};
    double BB10_En;
	//
	// === QQQ5 ===
	int   QQQ5Mul = 0;
	int   QQQ5Upstream[512] = {0};
	int   QQQ5Det[512] = {0};
	int   QQQ5Ring[512] = {0};
	int   QQQ5RingChannel[512] = {0};
	int   QQQ5Sector[512] = {0};
	int   QQQ5SectorChannel[512] = {0};
	int   QQQ5RingADC[512] = {0};
	float QQQ5RingEnergy[512] = {0};
	int   QQQ5SectorADC[512] = {0};
	float QQQ5SectorEnergy[512] = {0};
	float QQQ5Angle[512] = {0};
	//
	// === SX3 ===
	int   SX3Mul = 0;
	int   SX3Upstream[36] = {0};
	int   SX3Det[36] = {0};
	int   SX3Sector[36] = {0};
	int   SX3SectorChannel[36] = {0};
	int   SX3SectorADC[36] = {0};
	float SX3SectorEnergy[36] = {0};
	int   SX3Strip[36] = {0};
	int   SX3StripLeftChannel[36] = {0};
	int   SX3StripRightChannel[36] = {0};
	int   SX3StripLeftADC[36] = {0};
	int   SX3StripRightADC[36] = {0};
	float SX3StripEnergy[36] = {0};
    double BSX3_En = 0;
	//
	// === IC ===
	int   icdE = 0;
	int   icE = 0;
	int   icWireX = 0;
	int   icWireY = 0;
	float icPositionX = 0;
	float icPositionY = 0;
	float icPositionWeightedX = 0;
	float icPositionWeightedY = 0;
	//
	// === TDC ===
	int   tdcIC = 0;
	int   tdcGRETINA = 0;
	int   tdcRF = 0;
	int   tdcSilicon = 0;
	unsigned long long timeStamp = 0;
	unsigned long long GRETINATimeStamp = 0;
	//
	// === GRETINA ===
	bool  foundGRETINA = 0;
	int   xtalsMul = 0;
    float xtals_xlab[10] = {0};
	float xtals_ylab[10] = {0};
	float xtals_zlab[10] = {0};
	float xtals_cc[10] = {0};
	float xtals_edop[10] = {0};
	float xtals_edopMaxInt[10] = {0};
	float xtals_edopSeg[10] = {0};
	float xtals_edopXtal[10] = {0};
	int   xtals_crystalNum[10] = {0};
	int   xtals_quadNum[10] = {0};
	float xtals_t0[10] = {0};
	long long  xtals_timestamp[10] = {0};

    double prog_pos;
    double bar_width = 70.0;


    Chain->SetBranchAddress("BB10Mul",&BB10Mul);
    Chain->SetBranchAddress("BB10Det",BB10Det);
    Chain->SetBranchAddress("BB10Strip",BB10Strip);
    Chain->SetBranchAddress("BB10Channel",BB10Channel);
    Chain->SetBranchAddress("BB10ADC",BB10ADC);
    Chain->SetBranchAddress("BB10Energy",BB10Energy);



    // ================ QQQ5 Branch Addresses ===================
    Chain->SetBranchAddress("QQQ5Mul",&QQQ5Mul);
    Chain->SetBranchAddress("QQQ5Upstream",QQQ5Upstream);
    Chain->SetBranchAddress("QQQ5Det",QQQ5Det);
    Chain->SetBranchAddress("QQQ5Ring",QQQ5Ring);
    Chain->SetBranchAddress("QQQ5RingChannel",QQQ5RingChannel);
    Chain->SetBranchAddress("QQQ5Sector",QQQ5Sector);
    Chain->SetBranchAddress("QQQ5SectorChannel",QQQ5SectorChannel);
    Chain->SetBranchAddress("QQQ5RingADC",QQQ5RingADC);
    Chain->SetBranchAddress("QQQ5RingEnergy",QQQ5RingEnergy);
    Chain->SetBranchAddress("QQQ5SectorADC",QQQ5SectorADC);
    Chain->SetBranchAddress("QQQ5SectorEnergy",QQQ5SectorEnergy);


    // =================== SX3 Branch Address ==================
    Chain->SetBranchAddress("SX3Mul",&SX3Mul);
    Chain->SetBranchAddress("SX3Upstream",SX3Upstream);
    Chain->SetBranchAddress("SX3Det",SX3Det);
    Chain->SetBranchAddress("SX3Sector",SX3Sector);
    Chain->SetBranchAddress("SX3SectorChannel",SX3SectorChannel);
    Chain->SetBranchAddress("SX3SectorADC",SX3SectorADC);
    Chain->SetBranchAddress("SX3SectorEnergy",SX3SectorEnergy);
    Chain->SetBranchAddress("SX3Strip",SX3Strip);
    Chain->SetBranchAddress("SX3StripLeftChannel",SX3StripLeftChannel);
    Chain->SetBranchAddress("SX3StripRightChannel",SX3StripRightChannel);
    Chain->SetBranchAddress("SX3StripLeftADC",SX3StripLeftADC);
    Chain->SetBranchAddress("SX3StripRightADC",SX3StripRightADC);
    Chain->SetBranchAddress("SX3StripEnergy",SX3StripEnergy);


    // =================== IC Branch Address ===================
    Chain->SetBranchAddress("icdE",&icdE);
    Chain->SetBranchAddress("icE",&icE);
    Chain->SetBranchAddress("icWireX",&icWireX);
    Chain->SetBranchAddress("icWireY",&icWireY);
    Chain->SetBranchAddress("icPositionX",&icPositionX);
    Chain->SetBranchAddress("icPositionY",&icPositionY);
    Chain->SetBranchAddress("icPositionWeightedX",&icPositionWeightedX);
    Chain->SetBranchAddress("icPositionWeightedY",&icPositionWeightedY);


    // =================== TDC Branch Address ==================
    Chain->SetBranchAddress("tdcIC",&tdcIC);
    Chain->SetBranchAddress("tdcGRETINA",&tdcGRETINA);
    Chain->SetBranchAddress("tdcRF",&tdcRF);
    Chain->SetBranchAddress("tdcSilicon",&tdcSilicon);
    Chain->SetBranchAddress("timeStamp",&timeStamp);
    Chain->SetBranchAddress("GRETINATimeStamp",&GRETINATimeStamp);



    // ================= GRETINA Branch Address ================
    Chain->SetBranchAddress("foundGRETINA",&foundGRETINA);
    Chain->SetBranchAddress("xtalsMul",&xtalsMul);
    Chain->SetBranchAddress("xtals_xlab",xtals_xlab);
    Chain->SetBranchAddress("xtals_ylab",xtals_ylab);
    Chain->SetBranchAddress("xtals_zlab",xtals_zlab);
    Chain->SetBranchAddress("xtals_cc",xtals_cc);
    Chain->SetBranchAddress("xtals_edop",xtals_edop);
    Chain->SetBranchAddress("xtals_edopMaxInt",xtals_edopMaxInt);
    Chain->SetBranchAddress("xtals_edopSeg",xtals_edopSeg);
    Chain->SetBranchAddress("xtals_edopXtal",xtals_edopXtal);
    Chain->SetBranchAddress("xtals_crystalNum",xtals_crystalNum);
    Chain->SetBranchAddress("xtals_quadNum",xtals_quadNum);
    Chain->SetBranchAddress("xtals_t0",xtals_t0);
    Chain->SetBranchAddress("xtals_timestamp",xtals_timestamp);


    //Output root file for histograms
    TFile write("cal/BB10_cal_hists.root", "recreate");
    //Output .dat file for calibration parameters
    ofstream BB10EncalParametersFile;
    BB10EncalParametersFile.open ("cal/cal_params/BB10Encal_Parameters_OUTPUT.txt");



	// ================ Histograms and Canvases ==================
	TCanvas* c1 = new TCanvas("c1","c1",400,400);



    TH2D* ADC_vs_Ch= new TH2D("ADC_vs_Ch", "ADC_vs_Ch", 150, 0, 150, 1000, 0, 10000);
    TH2D* En_vs_Ch= new TH2D("En_vs_Ch", "En_vs_Ch", 150, 0, 150, 1000, 0, 10000);


    //Creating the histograms 
    char E_spec_HistName[512];
    TH1D *BB10_E_spec[12][8];
    for(int d=0;d<12;d++)
    {
        for(int s=0;s<8;s++)
        {
            sprintf(E_spec_HistName,"BB10_En_Det%dStrip%d",d,s);

            BB10_E_spec[d][s] = new TH1D(E_spec_HistName,E_spec_HistName,2000,0,4000);
        }
    }  
    

    char ADC_spec_HistName[512];
    TH1D *BB10_ADC_spec[12][8];
    for(int d=0;d<12;d++)
    {
        for(int s=0;s<8;s++)
        {
            sprintf(ADC_spec_HistName,"BSX3_ADC_Det%dStrip%d",d,s);

            BB10_ADC_spec[d][s] = new TH1D(ADC_spec_HistName,ADC_spec_HistName,1000,1000,4000);
        }
    }  
    





    int BB10_counter = 0;


	//Getting the number of entries to loop through
	unsigned long long int nEntries = Chain->GetEntries();


	//Looping through each event:
	for ( unsigned long long int i=0; i<nEntries; i++ )
    {
    	Chain->GetEntry(i);






        if(BB10Mul>=1)
        {
            for(int j=0; j<BB10Mul; j++)
            {
                BB10_En = (BB10ADC[j] * BB10_Encal[BB10Det[j]][BB10Strip[j]][1]) + BB10_Encal[BB10Det[j]][BB10Strip[j]][0];


                //Filling individual 1D histograms of BB10 ADC value
                BB10_ADC_spec[BB10Det[j]][BB10Strip[j]]->Fill(BB10ADC[j]);

                //ADC vs channel number
                ADC_vs_Ch->Fill((BB10Det[j]*8) + BB10Strip[j], BB10ADC[j]);

                //Calibrated Energy vs channel number
                En_vs_Ch->Fill((BB10Det[j]*8) + BB10Strip[j], BB10_En);

                // cout << (BB10Det[j]*8) + BB10Strip[j] << "               " << BB10_En << "               " << BB10ADC[j] << endl;



            }
        }






        //Progress update
        if(floor(1.0*i/100000) == 1.0*i/100000)
        {
            std::cout << "[";
            prog_pos = bar_width*(1.0*i/nEntries);
            for(int h=0; h<bar_width; h++)
            {
                if(h<=prog_pos) std::cout << "=";
                else std::cout << " ";
            }
            std::cout << "]" << int((1.0*i/nEntries)*100.0) << "%";
        }
        std::cout << "\r";




    }




    //Analyzing ADC peaks from each individual QQQ5 channel
    double fit_min_range[5], fit_max_range[5];
    double cal_peak_pos[5] = {5423, 5685, 6288, 6778, 8784};
    char calPlot_GraphName[512];
    TGraph *calPlot[12][8];

    for(int d=0;d<12;d++)
    {
        for(int s=0;s<8;s++)
        {
            BB10_ADC_spec[d][s]->Draw();

            // Searching the histogram for the largest 5 peaks, with a threshold of 30%
            TSpectrum* spec = new TSpectrum(5);
            Int_t nPeaks = spec->Search(BB10_ADC_spec[d][s],1, "", 0.3);
            Double_t *raw_peak_pos = spec->GetPositionX();

            // Sorting the array from smallest to largest
            sort(raw_peak_pos, raw_peak_pos+5);

            // Fitting the ADC peaks and extracting the centroid
            for(int t=0; t<5; t++){
                fit_min_range[t] = raw_peak_pos[t]-8;
                fit_max_range[t] = raw_peak_pos[t]+15;
            }
            // 8784 keV Peak
            TF1* peak8784 = new TF1 ( "peak8784","gaus(0)",fit_min_range[4], fit_max_range[4] );
            BB10_ADC_spec[d][s]->Fit ( "peak8784", "r" );
            // 6778 keV Peak
            TF1* peak6778 = new TF1 ( "peak6778","gaus(0)",fit_min_range[3], fit_max_range[3] );
            BB10_ADC_spec[d][s]->Fit ( "peak6778", "r" );
            // 6288 keV Peak
            TF1* peak6288 = new TF1 ( "peak6288","gaus(0)",fit_min_range[2], fit_max_range[2] );
            BB10_ADC_spec[d][s]->Fit ( "peak6288", "r" );
            // 5685 keV Peak
            TF1* peak5685 = new TF1 ( "peak5685","gaus(0)",fit_min_range[1], fit_max_range[1] );
            BB10_ADC_spec[d][s]->Fit ( "peak5685", "r" );
            // 5423 keV Peak
            TF1* peak5423 = new TF1 ( "peak5423","gaus(0)",fit_min_range[0], fit_max_range[0] );
            BB10_ADC_spec[d][s]->Fit ( "peak5423", "r" );

            // Linear regression of measured ADC peak values
            // against known alpha energies
            calPlot[d][s] = new TGraph(5,raw_peak_pos, cal_peak_pos);
            sprintf(calPlot_GraphName,"calPlotUp_Det%dStrip%d",d,s);
            calPlot[d][s]->SetName(calPlot_GraphName);
            calPlot[d][s]->SetMarkerStyle(23);
            TF1* cal_fit = new TF1 ( "cal_fit", "pol1", 0, 5000);
            calPlot[d][s]->Fit ( "cal_fit", "r" );
            cout << "p0:   " << cal_fit->GetParameter(0) << "    p1:    " << cal_fit->GetParameter(1) << endl; 
            calPlot[d][s]->Write();

            // Writing out the calibration parameters to file:
            // Det         Ring        Intercept     Slope
            BB10EncalParametersFile << d << setw(15) << s << setw(15) << cal_fit->GetParameter(0) << setw(15) << cal_fit->GetParameter(1) << endl;
            
        }
    }
    





    //Writing out the histograms
    En_vs_Ch->Write();
    ADC_vs_Ch->Write();


    for(int d=0;d<12;d++)
    {
        for(int s=0;s<8;s++)
        {
            BB10_ADC_spec[d][s]->Write();
        }
    }


    


	return 0;
}
