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






int SX3_pos_calibrator()
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
    //Chain->Add("/mnt/se82dp_2/cal_merged/calibrated_calibration_runs/Run201.root");     //alpha_Ecal_0deg03.ldf         --Good for upstream QQQ5's
    //Chain->Add("/mnt/se82dp_2/cal_merged/Run202.root");     //alpha_Ecal_60deg01.ldf
    Chain->Add("/mnt/se82dp_2/cal_merged/Run203.root");     //alpha_Ecal_120deg01.ldf
    Chain->Add("/mnt/se82dp_2/cal_merged/Run204.root");     //alpha_Ecal_180deg02.ldf
    Chain->Add("/mnt/se82dp_2/cal_merged/Run205.root");     //alpha_Ecal_240deg02.ldf
    //Chain->Add("/mnt/se82dp_2/cal_merged/Run206.root");     //alpha_Ecal_300deg01.ldf




    //Read in calibration parameters

    // SX3 Gainzz
    string line;
    double SX3_gains[2][12][4] = {0};
    int temp_det, temp_strip;
    double temp_gain;

    ifstream uSX3_gain_params ( "cal/cal_params/uSX3_gains.dat" );

    if ( !uSX3_gain_params )
    {
        cout << "Cannot open upstream Super X3 gains file, you doughnut..." << endl;
        return 1;
    }

    //=====================READING IN THE CALIBRATION FILE=========================
    while ( getline ( uSX3_gain_params,line ) )
    {
        istringstream in ( line );
        in >> temp_det >> temp_strip >> temp_gain;
        SX3_gains[1][temp_det][temp_strip] = temp_gain * (-1.);
    }


    ifstream dSX3_gain_params ( "cal/cal_params/dSX3_gains.dat" );

    if ( !dSX3_gain_params )
    {
        cout << "Cannot open downstream Super X3 gains file, you doughnut..." << endl;
        return 1;
    }

    //=====================READING IN THE CALIBRATION FILE=========================
    while ( getline ( dSX3_gain_params,line ) )
    {
        istringstream in ( line );
        in >> temp_det >> temp_strip >> temp_gain;
        SX3_gains[0][temp_det][temp_strip] = temp_gain * (-1.);
    }



    //SX3 Position Calibration
    double SX3_posEdges[2][12][4][2] = {0};
    double temp_LeftEdge, temp_RightEdge;

    ifstream uSX3_posEdges_params ( "cal/cal_params/uSX3_posEdges.dat" );

    if ( !uSX3_posEdges_params )
    {
        cout << "Cannot open upstream Super X3 edge position file, you doughnut..." << endl;
        return 1;
    }

    //=====================READING IN THE CALIBRATION FILE=========================
    while ( getline ( uSX3_posEdges_params,line ) )
    {
        istringstream in ( line );
        in >> temp_det >> temp_strip >> temp_LeftEdge >> temp_RightEdge;

        SX3_posEdges[1][temp_det][temp_strip][0] = temp_LeftEdge;
        SX3_posEdges[1][temp_det][temp_strip][1] = temp_RightEdge;
    }

    ifstream dSX3_posEdges_params ( "cal/cal_params/dSX3_posEdges.dat" );

    if ( !dSX3_posEdges_params )
    {
        cout << "Cannot open downstream Super X3 edge position file, you doughnut..." << endl;
        return 1;
    }

    //=====================READING IN THE CALIBRATION FILE=========================
    while ( getline ( dSX3_posEdges_params,line ) )
    {
        istringstream in ( line );
        in >> temp_det >> temp_strip >> temp_LeftEdge >> temp_RightEdge;

        SX3_posEdges[0][temp_det][temp_strip][0] = temp_LeftEdge;
        SX3_posEdges[0][temp_det][temp_strip][1] = temp_RightEdge;
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
    TFile write("cal/SX3_LvsR_hists.root", "recreate");

	// ================ Histograms and Canvases ==================
	TCanvas* c1 = new TCanvas("c1","c1",400,400);




    TH2D* En_vs_Ch = new TH2D("En_vs_Ch", "En_vs_Ch", 150, 0, 150, 1000, 0, 10000);

    //Creating the histograms 
    char LvsR_HistName[512];
    TH2D *LvsR_spec[2][12][4];
    for(int u=0;u<2;u++)
    {
        for(int d=0;d<12;d++)
        {
            for(int s=0;s<4;s++)
            {
                if(u==1) sprintf(LvsR_HistName,"SX3_LvsR_Up_Det%dStrip%d",d,s);
                if(u==0) sprintf(LvsR_HistName,"SX3_LvsR_Dn_Det%dStrip%d",d,s);

                LvsR_spec[u][d][s] = new TH2D(LvsR_HistName,LvsR_HistName,2000,0,4000,2000,0,4000);
            }
        }  
    }

    char posRaw_HistName[512];
    TH1D *posRaw_spec[2][12][4];
    for(int u=0;u<2;u++)
    {
        for(int d=0;d<12;d++)
        {
            for(int s=0;s<4;s++)
            {
                if(u==1) sprintf(posRaw_HistName,"SX3_posRaw_Up_Det%dStrip%d",d,s);
                if(u==0) sprintf(posRaw_HistName,"SX3_posRaw_Dn_Det%dStrip%d",d,s);

                posRaw_spec[u][d][s] = new TH1D(posRaw_HistName,posRaw_HistName,400,-1.,1.);
            }
        }  
    }

    char posCal_HistName[512];
    TH1D *posCal_spec[2][12][4];
    for(int u=0;u<2;u++)
    {
        for(int d=0;d<12;d++)
        {
            for(int s=0;s<4;s++)
            {
                if(u==1) sprintf(posCal_HistName,"SX3_posCal_Up_Det%dStrip%d",d,s);
                if(u==0) sprintf(posCal_HistName,"SX3_posCal_Dn_Det%dStrip%d",d,s);

                posCal_spec[u][d][s] = new TH1D(posCal_HistName,posCal_HistName,600,-1.,2.);
            }
        }  
    }
    TH2D* posCal2D_Up = new TH2D("posCal2D_Up", "posCal2D_Up", 50, 0, 50, 600, -1, 2);
    TH2D* posCal2D_Dn = new TH2D("posCal2D_Dn", "posCal2D_Dn", 50, 0, 50, 600, -1, 2);

    char EnRaw_HistName[512];
    TH1D *EnRaw_spec[2][12][4];
    for(int u=0;u<2;u++)
    {
        for(int d=0;d<12;d++)
        {
            for(int s=0;s<4;s++)
            {
                if(u==1) sprintf(EnRaw_HistName,"SX3_EnRaw_Up_Det%dStrip%d",d,s);
                if(u==0) sprintf(EnRaw_HistName,"SX3_EnRaw_Dn_Det%dStrip%d",d,s);

                EnRaw_spec[u][d][s] = new TH1D(EnRaw_HistName,EnRaw_HistName,2000,0,10000);
            }
        }  
    }






    int BB10_counter = 0;
    double rawPos, calPos;

	//Getting the number of entries to loop through
	unsigned long long int nEntries = Chain->GetEntries();


	//Looping through each event:
	for ( unsigned long long int i=0; i<nEntries; i++ )
    {
    	Chain->GetEntry(i);


        if(SX3Mul >= 1)
        {
            for(int j=0; j<SX3Mul; j++)
            {
                if(SX3Det[j] <= 11 && SX3Strip[j] <= 3)
                {

                    //Filling RAW histograms
                    LvsR_spec[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]]->Fill(SX3StripRightADC[j]*SX3_gains[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]], SX3StripLeftADC[j]);
                    if(SX3StripRightADC[j]*SX3_gains[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]] + SX3StripLeftADC[j] >= 1000.0)
                    {
                        posRaw_spec[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]]->Fill((SX3StripRightADC[j]*SX3_gains[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]] - SX3StripLeftADC[j]) / (SX3StripRightADC[j]*SX3_gains[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]] + SX3StripLeftADC[j]));
                    }
                    EnRaw_spec[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]]->Fill(SX3StripRightADC[j]*SX3_gains[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]] + SX3StripLeftADC[j]);

                    //Filling Calibrated Histograms
                    rawPos = (SX3StripRightADC[j]*SX3_gains[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]] - SX3StripLeftADC[j]) / (SX3StripRightADC[j]*SX3_gains[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]] + SX3StripLeftADC[j]);
                    calPos = (rawPos - SX3_posEdges[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]][0]) / (1.0*(SX3_posEdges[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]][1] - SX3_posEdges[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]][0]));

                    if(SX3Upstream[j] == 1) posCal2D_Up->Fill(SX3Strip[j] + (SX3Det[j]*4), calPos);
                    if(SX3Upstream[j] == 0) posCal2D_Dn->Fill(SX3Strip[j] + (SX3Det[j]*4), calPos);
                    posCal_spec[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]]->Fill(calPos);


                }
            }
        }




    }





















    //Writing out the histograms
    posCal2D_Up->Write();
    posCal2D_Dn->Write();

    for(int u=0;u<2;u++)
    {
        for(int d=0;d<12;d++)
        {
            for(int s=0;s<4;s++)
            {
                posCal_spec[u][d][s]->Write();
            }
        }
    }
    for(int u=0;u<2;u++)
    {
        for(int d=0;d<12;d++)
        {
            for(int s=0;s<4;s++)
            {
                LvsR_spec[u][d][s]->Write();
            }
        }
    }
    for(int u=0;u<2;u++)
    {
        for(int d=0;d<12;d++)
        {
            for(int s=0;s<4;s++)
            {
                posRaw_spec[u][d][s]->Write();
            }
        }
    }
    for(int u=0;u<2;u++)
    {
        for(int d=0;d<12;d++)
        {
            for(int s=0;s<4;s++)
            {
                EnRaw_spec[u][d][s]->Write();
            }
        }
    }

    c1->cd();
    posRaw_spec[1][0][1]->Draw();


	return 0;
}
