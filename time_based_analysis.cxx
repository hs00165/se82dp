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






void time_based_analysis()
{

    TCanvas* c1 = new TCanvas("c1", "c1", 800, 800);
    c1->Divide(2,2);
    TCanvas* c2 = new TCanvas("c2", "c2", 800, 800);

    //TCUTS:
    TCutG *Se82_locus_IC = new TCutG("Se82_locus_IC",8);
    Se82_locus_IC->SetPoint(1,771.045,1211.05);
    Se82_locus_IC->SetPoint(2,774.776,1097.68);
    Se82_locus_IC->SetPoint(3,1157.24,1002.35);
    Se82_locus_IC->SetPoint(4,1269.18,1074.49);
    Se82_locus_IC->SetPoint(5,1222.54,1138.91);
    Se82_locus_IC->SetPoint(6,1069.55,1174.98);
    Se82_locus_IC->SetPoint(7,1034.1,1172.4);



	// Creating the Chain of runs to use
	TChain* Chain = new TChain ( "data" );

    //================== CD2 Runs ====================
    //================================================

    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run001_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run002_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run003_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run004_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run005_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run006_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run007_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run008_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run009_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run010_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run011_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run012_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run013_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run014_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run015_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run016_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run017_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run018_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run019_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run020_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run021_combined.root");
    
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run022_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run023_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run024_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run025_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run026_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run027_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run028_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run029_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run030_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run031_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run032_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run033_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run034_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run035_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run036_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run037_combined.root");
	Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run038_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run039_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run040_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run041_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run042_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run043_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run044_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run045_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run046_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run047_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run048_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run049_combined.root");
    
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run050_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run051_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run052_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run053_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run054_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run055_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run056_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run057_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run058_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run059_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run060_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run061_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run062_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run063_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run064_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run065_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run066_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run067_combined.root");




    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run095_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run096_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run097_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run098_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run099_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run100_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run101_combined.root");
    
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run102_combined.root");
    
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run103_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run104_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run105_combined.root");

    
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
    //Chain->Add("/mnt/se82dp_2/cal_merged/Run203.root");     //alpha_Ecal_120deg01.ldf
    //Chain->Add("/mnt/se82dp_2/cal_merged/Run204.root");     //alpha_Ecal_180deg02.ldf
    //Chain->Add("/mnt/se82dp_2/cal_merged/Run205.root");     //alpha_Ecal_240deg02.ldf
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


    //SX3 Energy Calibration
    double BSX3_Encal[2][12][4][2] = {0};
    double temp_intercept, temp_slope;
    int temp_sector;

    ifstream BSX3_Encal_params ( "cal/cal_params/BSX3Up_Encal.dat" );

    if ( !BSX3_Encal_params )
    {
        cout << "Cannot open upstream Super X3 energy calibration file, you doughnut..." << endl;
        return 1;
    }

    //=====================READING IN THE CALIBRATION FILE=========================
    while ( getline ( BSX3_Encal_params,line ) )
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
    int time = 0;
    int prev_time = 0;
    int prev_prev_time = 0;
    int cumulative_time = 0;
    int time_flag = 0;

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
    //
    // === Analysis parameters ===
    double qValue = 0;
    double angleChad, angleRaj, angleVIKAR;
    double angle;
    double prog_pos;
    double bar_width = 70.0;
    double thetaGamma = 0;
    double beta = 0.1329615;
    double gamma_correction;


    //QQQ5 Angle calculations
    double ring_radius[32] = {2.6475,2.9,3.1475,3.39,3.6275,3.86,
4.0875,4.31,4.5275,4.74,4.9475,5.15,5.3475,5.54,5.7275,5.919,
6.0875,6.26,6.4275,6.59,6.7475,6.9,7.0475,7.19,7.3275,7.46,
7.5875,7.71,7.8275,7.94,8.0475,8.15};
    double QQQ5_angle[32];

    double QQQ5_zOffset = 8.5;

    for(int t=0; t<32; t++)
    {
        QQQ5_angle[t] = 180.0 - (atan(ring_radius[t]/QQQ5_zOffset)*(180./3.14159));
    }
    



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
    Chain->SetBranchAddress("QQQ5Angle",QQQ5Angle);


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
    TFile write("analysis_output/time_based_analysis.root", "recreate");

	// ================ Histograms and Canvases ==================
    TH2D* kinematics = new TH2D("kinematics", "kinematics", 360, 0, 180, 500, 0, 20000);
    TH2D* qValue_vs_angle = new TH2D("qValue_vs_angle", "qValue_vs_angle", 360,0,180, 500, -10000, 10000);
    TH2D* Excitation_vs_angle = new TH2D("Excitation_vs_angle", "Excitation_vs_angle", 360,0,180,2000,-5000,15000);
    TH2D* gamEn_vs_gamAngle = new TH2D("gamEn_vs_gamAngle", "gamEn_vs_gamAngle", 360, 0, 360, 8000, 0, 10000);
    TH2D* gammaEx_matrix = new TH2D("gammaEx_matrix", "gammaEx_matrix", 500,0,10000, 8000, 0, 10000);

    TH2D* ic_dE_E = new TH2D("ic_dE_E", "ic_dE_E", 4000, 0, 4000, 2000, 0, 2000);

    TH1D* Ex = new TH1D("Ex", "Ex", 200,-5000,8000);
    TH1D* Ex_SX3 = new TH1D("Ex_SX3", "Ex_SX3", 500,-5000,15000);
    TH1D* Ex_QQQ5 = new TH1D("Ex_QQQ5", "Ex_QQQ5",500,-5000,15000);

    TH1D* Si_TDC = new TH1D("i_TDC", "Si_TDC", 100, 800, 1500); 
    TH1D* IC_TDC = new TH1D("IC_TDC", "IC_TDC", 4000, 0, 4000);

    TH1D* timeStamp_hist = new TH1D("timeStamp_hist", "timeStamp_hist", 5000,0,10000000);
    TH2D* timeStamp_hist2D = new TH2D("timeStamp_hist2D", "timeStamp_hist2D", 5000,0,10000000, 5000, 0, 10000);


    // Time dependent histograms
    char time_IC_histName[200];
    char time_kinematics_histName[200];
    char time_IC_TDC_histName[200];
    char time_Si_TDC_histName[200];
    char time_Ex_histName[200];


    TH2D *time_IC_spec[200];
    TH2D *time_kinematics_spec[200];
    TH1D *time_IC_TDC_spec[200];
    TH1D *time_Si_TDC_spec[200];
    TH1D *time_Ex_spec[200];


    for(int run=0;run<200;run++)
    {
        sprintf(time_IC_histName,"IC_Run%d",run);
        sprintf(time_kinematics_histName,"Kinematics_Run%d",run);
        sprintf(time_IC_TDC_histName,"IC_TDC_Run%d",run);
        sprintf(time_Si_TDC_histName,"Si_TDC_Run%d",run);
        sprintf(time_Ex_histName,"Excitation_En-Run%d",run);



        time_IC_spec[run] = new TH2D(time_IC_histName,time_IC_histName, 3500, 500, 4000, 1800, 200, 2000);
        time_kinematics_spec[run] = new TH2D(time_kinematics_histName,time_kinematics_histName, 360, 0, 180, 500, 0, 20000);
        time_IC_TDC_spec[run] = new TH1D(time_IC_TDC_histName,time_IC_TDC_histName, 4000, 0, 4000); 
        time_Si_TDC_spec[run] = new TH1D(time_Si_TDC_histName,time_Si_TDC_histName, 100, 800, 1500); 
        time_Ex_spec[run] = new TH1D(time_Ex_histName,time_Ex_histName, 200,-5000,8000); 

    }


    int BB10_counter = 0;
    double rawPos, calPos;

	//Getting the number of entries to loop through
	unsigned long long int nEntries = Chain->GetEntries();

    string runNumber_str;
    int runNumber;


	//Looping through each event:
	for ( unsigned long long int i=0; i<nEntries/10; i++ )
    {
    	Chain->GetEntry(i);

        // Getting run number from the TChain
        runNumber_str = Chain->GetFile()->GetName();
        runNumber = stoi(runNumber_str.substr(31,3));




        // ===========================================================================
        // ===========================================================================
        // ==                                                                       ==
        // ==                             TDC processing                            ==
        // ==                                                                       ==
        // ===========================================================================
        // ===========================================================================
        time_IC_TDC_spec[runNumber]->Fill(tdcIC);
        time_Si_TDC_spec[runNumber]->Fill(tdcSilicon);

        Si_TDC->Fill(tdcSilicon);
        IC_TDC->Fill(tdcIC);




        // ===========================================================================
        // ===========================================================================
        // ==                                                                       ==
        // ==                             Super X3 processing                       ==
        // ==                                                                       ==
        // ===========================================================================
        // ===========================================================================
        if(SX3Mul == 1)
        {
            for(int j=0; j<SX3Mul; j++)
            {
                if(SX3Det[j] <= 11 && SX3Strip[j] <= 3 && tdcSilicon >= 1000 && tdcSilicon <= 1300) //No weird events with wrong channels make it through
                {
                    //Calibrating SX3 Position
                    rawPos = (SX3StripRightADC[j]*SX3_gains[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]] - SX3StripLeftADC[j]) / (SX3StripRightADC[j]*SX3_gains[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]] + SX3StripLeftADC[j]);
                    calPos = (rawPos - SX3_posEdges[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]][0]) / (1.0*(SX3_posEdges[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]][1] - SX3_posEdges[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]][0]));
                    //Calibrating BSX3 Energy
                    BSX3_En = (SX3SectorADC[j] * BSX3_Encal[1][SX3Det[j]][SX3Sector[j]][1]) + BSX3_Encal[1][SX3Det[j]][SX3Sector[j]][0];



                    //Calculating the event Q value
                    angle = getSX3Angle(SX3Upstream[j], calPos);
                    qValue = rel_q_value (angle, BSX3_En);

                    //Filling histograms
                    kinematics->Fill(angle, BSX3_En);
                    qValue_vs_angle->Fill(angle, qValue);
                    Excitation_vs_angle->Fill(angle, 3593.0 - qValue);

                    time_kinematics_spec[runNumber]->Fill(angle, BSX3_En);

                    Ex_SX3->Fill(3593.0 - qValue);

                    time_Ex_spec[runNumber]->Fill(3593.0 - qValue);
                    Ex->Fill(3593.0 - qValue);














                    if(xtalsMul >= 1 && xtalsMul <= 3 && SX3Upstream[j]==1)
                    {
                        for(int k=0; k<xtalsMul; k++)
                        {
                            if(xtals_zlab[k] >= 0) thetaGamma = (180./3.14159) * atan(sqrt(pow(xtals_xlab[k],2) + pow(xtals_ylab[k],2))/xtals_zlab[k]);
                            if(xtals_zlab[k] < 0) thetaGamma = 180. + (180./3.14159) * atan(sqrt(pow(xtals_xlab[k],2) + pow(xtals_ylab[k],2))/xtals_zlab[k]);

                            gamma_correction = (1. - beta*cos(thetaGamma*(3.14159/180.))) / (sqrt( 1. - pow(beta,2) ));

                            if(SX3Upstream[j] == 1) gamEn_vs_gamAngle->Fill(thetaGamma, xtals_edop[k]);
                            if(SX3Upstream[j] == 1) gammaEx_matrix->Fill(3593.0 - qValue, xtals_edop[k]);


                        }
                    }


                }
            }
        }


        // ===========================================================================
        // ===========================================================================
        // ==                                                                       ==
        // ==                              QQQ5 processing                          ==
        // ==                                                                       ==
        // ===========================================================================
        // ===========================================================================
        if(QQQ5Mul == 1)
        {
            for(int j=0; j<QQQ5Mul; j++)
            {
                if(QQQ5Det[j] <= 4 && QQQ5Ring[j] <= 31 && tdcSilicon >= 1000 && tdcSilicon <= 1300) //Se82_locus_IC->IsInside(icE, icdE)
                {

                    //Calculating the event Q value
                    qValue = rel_q_value (QQQ5_angle[QQQ5Ring[j]], QQQ5RingEnergy[j]);

                    //Filling histograms
                    kinematics->Fill(QQQ5_angle[QQQ5Ring[j]], QQQ5RingEnergy[j]);
                    qValue_vs_angle->Fill(QQQ5_angle[QQQ5Ring[j]], qValue);
                    Excitation_vs_angle->Fill(QQQ5_angle[QQQ5Ring[j]], 3593.0 - qValue);

                    time_kinematics_spec[runNumber]->Fill(QQQ5_angle[QQQ5Ring[j]], QQQ5RingEnergy[j]);

                    Ex_QQQ5->Fill(3593.0 - qValue);

                    time_Ex_spec[runNumber]->Fill(3593.0 - qValue);
                    Ex->Fill(3593.0 - qValue);


                    if(xtalsMul >= 1 && xtalsMul <= 3 && QQQ5Upstream[j] == 1)
                    {
                        for(int k=0; k<xtalsMul; k++)
                        {
                            if(QQQ5Upstream[j] == 1) gammaEx_matrix->Fill(3593.0 - qValue, xtals_edop[k]);


                        }
                    }


                }
            }
        }


        // ===========================================================================
        // ===========================================================================
        // ==                                                                       ==
        // ==                               IC processing                           ==
        // ==                                                                       ==
        // ===========================================================================
        // ===========================================================================
        if(icE >= 0. && icdE >= 0.)
        {

            ic_dE_E->Fill(icE, icdE);

            time_IC_spec[runNumber]->Fill(icE, icdE);

        }














        // ===========================================================================
        // ===========================================================================
        // ==                                                                       ==
        // ==                         TimeStamp processing                          ==
        // ==                                                                       ==
        // ===========================================================================
        // ===========================================================================
/*
        // cout << "   test   " << floor(timeStamp/10000000.0) << endl;

        time = int(floor(timeStamp/10000000.0));

        if(floor(timeStamp/10000000.0) < int(prev_time))
        {
            time_flag++;
            if( time_flag == 4 )
            {
                cout << "debug!!" << endl;
                cumulative_time = cumulative_time + prev_time;
            }
        }

        if(time_flag==5)
        {
            time_flag = 0;
        }

        cout << time << "  " << cumulative_time << "   " << prev_time << "  " << prev_prev_time <<  endl;

        timeStamp_hist->Fill(time + cumulative_time);
        timeStamp_hist2D->Fill(time + cumulative_time, floor(i/10000));


        prev_prev_time = prev_time;
        prev_time = time;
*/

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

    char pic_name[200];

    for(int run=0;run<106;run++)
    {
        sprintf(pic_name,"plots/IC_vs_time/IC_Run%d.png",run);

        time_Ex_spec[run]->SetLineColor(kRed);
        time_IC_TDC_spec[run]->SetLineColor(kRed);
        time_Si_TDC_spec[run]->SetLineColor(kRed);

        c1->cd(1);
        time_IC_spec[run]->Draw("COLZ");
        gPad->SetLogz();

        c1->cd(2);
        gPad-> SetLogy();
        Ex->GetYaxis()->SetRangeUser(1, 3000);
        Ex->Draw();
        time_Ex_spec[run]->Draw("SAME");

        c1->cd(3);
        gPad-> SetLogy();
        IC_TDC->GetYaxis()->SetRangeUser(1, 100000);
        IC_TDC->Draw();
        time_IC_TDC_spec[run]->Draw("SAME");

        c1->cd(4);
        gPad-> SetLogy();
        Si_TDC->GetYaxis()->SetRangeUser(1, 1000000);
        Si_TDC->Draw();
        time_Si_TDC_spec[run]->Draw("SAME");


        c1->SaveAs ( pic_name );

    }













    kinematics->Write();
    ic_dE_E->Write();
    qValue_vs_angle->Write();
    Excitation_vs_angle->Write();
    gamEn_vs_gamAngle->Write();
    gammaEx_matrix->Write();

    Si_TDC->Write();
    IC_TDC->Write();
    timeStamp_hist->Write();
    timeStamp_hist2D->Write();

    c2->cd();
    Ex_SX3->Draw();
    Ex_QQQ5->Draw("SAME");



	return;
}
