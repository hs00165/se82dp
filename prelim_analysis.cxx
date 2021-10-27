
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




void prelim_analysis()
{

    TCanvas *c1 = new TCanvas("c1", "c1", 700, 700);
    TCanvas *c2 = new TCanvas("c2", "c2", 700, 700);
    c1->Divide(1,2);

    //TCUTS:
    //IC_Se82 locus
    TCutG *Se82_locus_IC = new TCutG("Se82_locus_IC",7);
    Se82_locus_IC->SetPoint(0,2800.44,1184.41);
    Se82_locus_IC->SetPoint(1,2542,1109.31);
    Se82_locus_IC->SetPoint(2,2473.08,954.408);
    Se82_locus_IC->SetPoint(3,2809.05,940.327);
    Se82_locus_IC->SetPoint(4,3179.49,1118.69);
    Se82_locus_IC->SetPoint(5,2964.12,1203.18);
    Se82_locus_IC->SetPoint(6,2800.44,1184.41);

    //Downstream deuterons
    TCutG *DS_deuterons = new TCutG("DS_deuterons",22);
    DS_deuterons->SetPoint(0,1119.57,2712.93);
    DS_deuterons->SetPoint(1,372.282,2567.28);
    DS_deuterons->SetPoint(2,1119.57,2006.24);
    DS_deuterons->SetPoint(3,2355.98,1612.44);
    DS_deuterons->SetPoint(4,3144.02,1418.23);
    DS_deuterons->SetPoint(5,4326.09,1213.24);
    DS_deuterons->SetPoint(6,5385.87,1072.98);
    DS_deuterons->SetPoint(7,6730.98,965.089);
    DS_deuterons->SetPoint(8,8293.48,873.382);
    DS_deuterons->SetPoint(9,9665.76,808.647);
    DS_deuterons->SetPoint(10,11676.6,711.544);
    DS_deuterons->SetPoint(11,13755.4,657.599);
    DS_deuterons->SetPoint(12,15114.1,657.599);
    DS_deuterons->SetPoint(13,15100.5,1002.85);
    DS_deuterons->SetPoint(14,13212,1002.85);
    DS_deuterons->SetPoint(15,10494.6,1105.35);
    DS_deuterons->SetPoint(16,7206.52,1310.34);
    DS_deuterons->SetPoint(17,4652.17,1628.62);
    DS_deuterons->SetPoint(18,3470.11,1828.22);
    DS_deuterons->SetPoint(19,2519.02,2173.47);
    DS_deuterons->SetPoint(20,1296.2,2712.93);
    DS_deuterons->SetPoint(21,1119.57,2712.93);

    //Downstream protons with punchthrough
    TCutG *DS_protons = new TCutG("DS_protons",23);
    DS_protons->SetPoint(0,494.565,2151.9);
    DS_protons->SetPoint(1,548.913,1660.99);
    DS_protons->SetPoint(2,1323.37,1304.95);
    DS_protons->SetPoint(3,2315.22,1013.64);
    DS_protons->SetPoint(4,3483.7,830.225);
    DS_protons->SetPoint(5,5453.8,646.809);
    DS_protons->SetPoint(6,3442.93,511.945);
    DS_protons->SetPoint(7,3755.43,339.319);
    DS_protons->SetPoint(8,4638.59,344.713);
    DS_protons->SetPoint(9,8211.96,468.789);
    DS_protons->SetPoint(10,10712,452.605);
    DS_protons->SetPoint(11,11989.1,695.361);
    DS_protons->SetPoint(12,10059.8,776.279);
    DS_protons->SetPoint(13,8687.5,841.014);
    DS_protons->SetPoint(14,7355.98,927.327);
    DS_protons->SetPoint(15,6133.15,1008.25);
    DS_protons->SetPoint(16,4991.85,1126.93);
    DS_protons->SetPoint(17,4027.17,1245.61);
    DS_protons->SetPoint(18,2967.39,1445.21);
    DS_protons->SetPoint(19,2260.87,1623.23);
    DS_protons->SetPoint(20,1241.85,1990.06);
    DS_protons->SetPoint(21,576.087,2157.29);
    DS_protons->SetPoint(22,494.565,2151.9);


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

    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run106_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run107_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run108_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run109_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run110_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run111_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run112_combined.root");


    //================== CH2 Runs ====================
    //================================================
   /*
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run073_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run074_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run075_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run077_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run078_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run079_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run081_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run082_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run083_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run087_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run089_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run090_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run093_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run094_combined.root");
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
    //
    // === Analysis parameters ===
    double qValue = 0.0;
    double excitation = 0.0;
    double angleChad, angleRaj, angleVIKAR;
    double angle;
    double prog_pos;
    double bar_width = 70.0;
    double thetaGamma = 0;
    double thetaGamma_test = 0;
    double beta = 0.1329615;
    double gamma_correction;
    double gamma_correction_test;
    vector<double> hit_pos;
    double initial_energy;
    double corrected_excitation;
    int BB10_counter = 0;
    double rawPos, calPos;
    double angle_IC_corrected = 0;

    double isomer_z_offset = 142.5;


    //QQQ5 Angle calculations
    double ring_radius[32] = {2.6475,2.9,3.1475,3.39,3.6275,3.86,
4.0875,4.31,4.5275,4.74,4.9475,5.15,5.3475,5.54,5.7275,5.919,
6.0875,6.26,6.4275,6.59,6.7475,6.9,7.0475,7.19,7.3275,7.46,
7.5875,7.71,7.8275,7.94,8.0475,8.15}; //cm
    double QQQ5_angle[32];

    //NEW
    double QQQ5_zOffset = 8.6; //cm

    //OLD
    //double QQQ5_zOffset = 8.5;

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
    TFile write("analysis_output/prelim_analysis.root", "recreate");

	// ================ Histograms and Canvases ==================
    TH2D* DS_PID = new TH2D("DS_PID", "DS_PID", 1000, 0, 18000, 1000, 0, 3500 );
    TH2D* kinematics_eloss_corrected = new TH2D("kinematics_eloss_corrected", "kinematics_eloss_corrected", 360, 0, 180, 500, 0, 20000);
    TH2D* kinematics = new TH2D("kinematics", "kinematics", 360, 0, 180, 500, 0, 20000);
    TH1D* Excitation_spec_eloss_corrected = new TH1D("Excitation_spec_eloss_corrected", "Excitation_spec_eloss_corrected", 2500,-10000,15000);
    TH1D* Excitation_spec = new TH1D("Excitation_spec", "Excitation_spec", 2500,-10000,15000);
    TH2D* qValue_vs_angle = new TH2D("qValue_vs_angle", "qValue_vs_angle", 360,0,180, 500, -10000, 10000);
    TH2D* Excitation_vs_angle = new TH2D("Excitation_vs_angle", "Excitation_vs_angle", 360,0,180,800,-5000,15000);
    TH2D* gamEn_vs_gamAngle = new TH2D("gamEn_vs_gamAngle", "gamEn_vs_gamAngle", 360, 0, 360, 8000, 0, 10000);
    TH2D* gammaEx_matrix = new TH2D("gammaEx_matrix", "gammaEx_matrix", 500,0,10000, 8000, 0, 10000);
    TH2D* gammaEx_matrixQQQ5 = new TH2D("gammaEx_matrixQQQ5", "gammaEx_matrixQQQ5", 500,0,10000, 8000, 0, 10000);
    TH2D* gammaEx_matrixSX3 = new TH2D("gammaEx_matrixSX3", "gammaEx_matrixSX3", 500,0,10000, 8000, 0, 10000);

    TH2D* ic_dE_E = new TH2D("ic_dE_E", "ic_dE_E", 4000, 0, 4000, 2000, 0, 2000);

    TH1D* Ex_SX3 = new TH1D("Ex_SX3", "Ex_SX3", 500,-5000,15000);
    TH1D* Ex_QQQ5 = new TH1D("Ex_QQQ5", "Ex_QQQ5",500,-5000,15000);

    TH1D* QQQ5_Si_TDC = new TH1D("QQQ5_Si_TDC", "QQQ5_Si_TDC", 4000, 0, 4000);
    TH1D* QQQ5_IC_TDC = new TH1D("QQQ5_IC_TDC", "QQQ5_IC_TDC", 4000, 0, 4000);
    TH1D* SX3_Si_TDC = new TH1D("SX3_Si_TDC", "SX3_Si_TDC", 4000, 0, 4000); 
    TH1D* SX3_IC_TDC = new TH1D("SX3_IC_TDC", "SX3_IC_TDC", 4000, 0, 4000);


    TH1D* gamma_belowSn = new TH1D("gamma_belowSn", "gamma_belowSn", 8000, 0, 10000);
    TH1D* gamma_aboveSn = new TH1D("gamma_aboveSn", "gamma_aboveSn", 8000, 0, 10000);

    TH2D* kinematics_proton_PID = new TH2D("kinematics_proton_PID", "kinematics_proton_PID", 360, 0, 180, 500, 0, 20000);
    TH2D* kinematics_deuteron_PID = new TH2D("kinematics_deuteron_PID", "kinematics_deuteron_PID", 360, 0, 180, 500, 0, 20000);

    TH3D* hit_position_spectrum = new TH3D("hit_position_spectrum", "hit_position_spectrum", 400, -200, 200, 400, -200, 200, 400, -200, 200);


    TH1D* gamma_z_offset = new TH1D("gamma_z_offset", "gamma_z_offset", 8000, 0, 10000);
    TH1D* gamma_no_offset = new TH1D("gamma_no_offset", "gamma_no_offset", 8000, 0, 10000);

    TH1D* siliconTDC_hist = new TH1D("siliconTDC_hist", "siliconTDC_hist", 4048, 0, 4048);
    TH1D* icTDC_hist = new TH1D("icTDC_hist", "icTDC_hist", 4048, 0, 4048);
    TH1D* grertinaTDC_hist = new TH1D("grertinaTDC_hist", "grertinaTDC_hist", 4048, 0, 4048);


    TH2D* SX3_en_vs_z_hist = new TH2D("SX3_en_vs_z_hist", "SX3_en_vs_z_hist", 400, -10, 10, 500, 0, 20000);


    // Timestamp and TDC histograms
    TH2D* delta_timestamp_vs_Run_hist = new TH2D("delta_timestamp_vs_Run_hist", "delta_timestamp_vs_Run_hist", 120, 0, 120, 500, -100, 400);
    TH2D* tdcGRETINA_vs_Run_hist = new TH2D("tdcGRETINA_vs_Run_hist", "tdcGRETINA_vs_Run_hist", 120, 0, 120, 4096, 0, 4096);

    TH2D* si_ic_vs_Run_hist = new TH2D("si_ic_vs_Run_hist", "si_ic_vs_Run_hist", 120, 0, 120, 2000, 0, 2000);
    TH2D* Energy_vs_si_ic_hist = new TH2D("Energy_vs_si_ic_hist", "Energy_vs_si_ic_hist", 1000, 0, 2000, 2000, 0, 20000);
    TH2D* Energy_vs_delta_timestamp_hist = new TH2D("Energy_vs_delta_timestamp_hist", "Energy_vs_delta_timestamp_hist", 500, -100, 400, 2000, 0, 20000);




    //=============Constructing the bins for the Angular Distribution=============
    //============================================================================


    //======= SX3 ==========

    double SX3_bin_width = 5.; //degrees
    int number_of_SX3_bins = 7;

    double bin1_center = 97.5;
    double bin2_center = 102.5;
    double bin3_center = 107.5;
    double bin4_center = 112.5;
    double bin5_center = 117.5;
    double bin6_center = 122.5;
    double bin7_center = 127.5;


    TH1D* Excitation_AngularBin[number_of_SX3_bins];
    char angular_bin_name[number_of_SX3_bins];

    for(int i=1; i<=number_of_SX3_bins; i++)
    {
        sprintf(angular_bin_name,"Angular_bin_%d",i);
        Excitation_AngularBin[i] = new TH1D(angular_bin_name,angular_bin_name,400,-5000,15000);

    }

    string runNumber_str;
    int runNumber;

    
	//Getting the number of entries to loop through
	unsigned long long int nEntries = Chain->GetEntries();



	//Looping through each event:
	for ( unsigned long long int i=0; i<nEntries; i++ )
    {
    	Chain->GetEntry(i);

        runNumber_str = Chain->GetFile()->GetName();
        runNumber = stoi(runNumber_str.substr(31,3));

        // ===========================================================================
        // ===========================================================================
        // ==                                                                       ==
        // ==                               TDC processing                          ==
        // ==                                                                       ==
        // ===========================================================================
        // ===========================================================================

        if(tdcSilicon != 0) siliconTDC_hist->Fill(tdcSilicon);
        if(tdcIC != 0) icTDC_hist->Fill(tdcIC);
        if(tdcGRETINA != 0) 
        {
            grertinaTDC_hist->Fill(tdcGRETINA);
            tdcGRETINA_vs_Run_hist->Fill(runNumber, tdcGRETINA);
        }

        

        si_ic_vs_Run_hist->Fill(runNumber, tdcSilicon - tdcIC);

        if(xtalsMul >= 1 )
        {
            delta_timestamp_vs_Run_hist->Fill(runNumber, timeStamp - xtals_timestamp[0]);
        }








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
                if(SX3Det[j] <= 11 && SX3Strip[j] <= 3)// && tdcSilicon >= 900 && tdcSilicon <= 1300) //No weird events with wrong channels make it through
                //if(SX3Det[j] <= 11 && SX3Strip[j] <= 3) //No weird events with wrong channels make it through
                {
                    //Calibrating SX3 Position
                    rawPos = (SX3StripRightADC[j]*SX3_gains[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]] - SX3StripLeftADC[j]) / (SX3StripRightADC[j]*SX3_gains[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]] + SX3StripLeftADC[j]);
                    calPos = (rawPos - SX3_posEdges[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]][0]) / (1.0*(SX3_posEdges[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]][1] - SX3_posEdges[SX3Upstream[j]][SX3Det[j]][SX3Strip[j]][0]));
                    //Calibrating BSX3 Energy
                    BSX3_En = (SX3SectorADC[j] * BSX3_Encal[1][SX3Det[j]][SX3Sector[j]][1]) + BSX3_Encal[1][SX3Det[j]][SX3Sector[j]][0];

                    //Applying the proton energy loss through target correcttion.
                    hit_pos = hit_position_3D("SX3", SX3Upstream[j], SX3Det[j], SX3Strip[j], calPos);
                    initial_energy = initial_proton_energy((BSX3_En/1000.0), proton_distance_through_target(hit_pos));
                    

                    //Calculating the event Q value
                    angle = getSX3Angle(SX3Upstream[j], calPos);

                    angle_IC_corrected = IC_corrected_angle(hit_pos.at(0),hit_pos.at(1),hit_pos.at(2), icPositionX, icPositionY);

                    //cout << "ANGLE:  " << angle << "  " << angle_IC_corrected << endl;

                    if( SX3Upstream[j] == 1 ) SX3_en_vs_z_hist->Fill(calPos, initial_energy*1000.0);

                    qValue = rel_q_value (angle_IC_corrected, BSX3_En);
                    excitation = 3593.0 - qValue;
                    corrected_excitation = 3593.0 - rel_q_value (angle_IC_corrected, initial_energy*1000);

                    //Filling histograms
                    kinematics->Fill(angle_IC_corrected, BSX3_En);
                    kinematics_eloss_corrected->Fill(angle_IC_corrected, initial_energy*1000.0);
                    qValue_vs_angle->Fill(angle_IC_corrected, qValue);
                    Excitation_vs_angle->Fill(angle_IC_corrected, corrected_excitation);
                    if(SX3Upstream[j]==1) Excitation_spec->Fill(excitation);
                    if(SX3Upstream[j]==1) Excitation_spec_eloss_corrected->Fill(3593.0 - rel_q_value (angle_IC_corrected, initial_energy*1000));

                    Ex_SX3->Fill(3593.0 - qValue);

                    // Figuring out the TDC stuff
                    SX3_Si_TDC->Fill(tdcSilicon);
                    SX3_IC_TDC->Fill(tdcIC);

                    // if(angle > 1) 
                    // {
                    //     hit_position_spectrum->Fill(hit_pos.at(0), hit_pos.at(2), hit_pos.at(1));
                    // }

                    if( SX3Upstream[j]==1 )
                    {
                        Energy_vs_si_ic_hist->Fill(tdcSilicon - tdcIC, initial_energy*1000.0);
                        

                        if(tdcGRETINA != 0) Energy_vs_delta_timestamp_hist->Fill(tdcIC - tdcGRETINA, initial_energy*1000.0 );
                    }







                    // Filling angular bins
                    //====================    BIN 1   ====================
                    if(angle >= bin1_center-2.5 && angle < bin1_center+2.5)
                    {
                        Excitation_AngularBin[1]->Fill(corrected_excitation);
                    }
                    //====================    BIN 2   ====================
                    if(angle >= bin2_center-2.5 && angle < bin2_center+2.5)
                    {
                        Excitation_AngularBin[2]->Fill(corrected_excitation);
                    }
                    //====================    BIN 3   ====================
                    if(angle >= bin3_center-2.5 && angle < bin3_center+2.5)
                    {
                        Excitation_AngularBin[3]->Fill(corrected_excitation);
                    }
                    //====================    BIN 4   ====================
                    if(angle >= bin4_center-2.5 && angle < bin4_center+2.5)
                    {
                        Excitation_AngularBin[4]->Fill(corrected_excitation);
                    }
                    //====================    BIN 5   ====================
                    if(angle >= bin5_center-2.5 && angle < bin5_center+2.5)
                    {
                        Excitation_AngularBin[5]->Fill(corrected_excitation);
                    }
                    //====================    BIN 6   ====================
                    if(angle >= bin6_center-2.5 && angle < bin6_center+2.5)
                    {
                        Excitation_AngularBin[6]->Fill(corrected_excitation);
                    }
                    //====================    BIN 7   ====================
                    if(angle >= bin7_center-2.5 && angle < bin7_center+2.5)
                    {
                        Excitation_AngularBin[7]->Fill(corrected_excitation);
                    }









                    // //Filling the 3-D hit spectrum
                    // hit_pos = hit_position_3D("SX3", SX3Upstream[j], SX3Det[j], SX3Strip[j], calPos);
                    // if(angle > 1) 
                    // {
                    //     hit_position_spectrum->Fill(hit_pos.at(0), hit_pos.at(1), hit_pos.at(2));

                    //     //cout << "SX3     " << hit_pos.at(0) << "  " <<hit_pos.at(1) << "  " <<hit_pos.at(2) << "  " << calPos << "  " << angle << endl;
                    // }

                    // initial_energy = initial_proton_energy((BSX3_En/1000.0), proton_distance_through_target(hit_pos));


                    // if(SX3Upstream[j]==1) cout << "1       " << angle << "   " << initial_proton_energy((BSX3_En/1000.0), proton_distance_through_target(hit_pos)) << "   " << BSX3_En/1000.0 << endl;
                    // if(SX3Upstream[j]==1) cout << "2       " << angle << "  " << proton_energy_loss(initial_energy, proton_distance_through_target(hit_pos)) << endl;





                    if(xtalsMul >= 1 && xtalsMul <= 3 && SX3Upstream[j]==1)
                    {
                        for(int k=0; k<xtalsMul; k++)
                        {
                            if(xtals_zlab[k] >= 0) thetaGamma = (180./3.14159) * atan(sqrt(pow(xtals_xlab[k],2) + pow(xtals_ylab[k],2))/xtals_zlab[k]);
                            if(xtals_zlab[k] < 0) thetaGamma = 180. + (180./3.14159) * atan(sqrt(pow(xtals_xlab[k],2) + pow(xtals_ylab[k],2))/xtals_zlab[k]);

                            gamma_correction = (1. - beta*cos(thetaGamma*(3.14159/180.))) / (sqrt( 1. - pow(beta,2) ));

                            if(SX3Upstream[j] == 1) gamEn_vs_gamAngle->Fill(thetaGamma, xtals_edop[k]);
                            if(SX3Upstream[j] == 1) gammaEx_matrix->Fill(corrected_excitation, xtals_edop[k]);
                            if(SX3Upstream[j] == 1) gammaEx_matrixSX3->Fill(corrected_excitation, xtals_edop[k]);

                            if(excitation >= 5818.0 && excitation <= 6818.0)
                            {
                                gamma_aboveSn->Fill(xtals_edop[k]);
                            }
                            if(excitation <= 5818.0 && excitation >= 4818.0)
                            {
                                gamma_belowSn->Fill(xtals_edop[k]);
                            }







                            if(xtals_zlab[k] + isomer_z_offset >= 0) thetaGamma_test = (180./3.14159) * atan(sqrt(pow(xtals_xlab[k],2) + pow(xtals_ylab[k],2))/(xtals_zlab[k] + isomer_z_offset));
                            if(xtals_zlab[k] + isomer_z_offset < 0) thetaGamma_test = 180. + (180./3.14159) * atan(sqrt(pow(xtals_xlab[k],2) + pow(xtals_ylab[k],2))/(xtals_zlab[k] + isomer_z_offset));

                            gamma_correction_test = (1. - beta*cos(thetaGamma_test*(3.14159/180.))) / (sqrt( 1. - pow(beta,2) ));

                            gamma_no_offset->Fill(gamma_correction*xtals_cc[k]);
                            gamma_z_offset->Fill(gamma_correction_test*xtals_cc[k]);



                        }
                    }

                    if(BB10Mul >= 1)
                    {
                        for(int l=0; l<BB10Mul; l++)
                        {

                            BB10_En = (BB10ADC[l] * BB10_Encal[BB10Det[l]][BB10Strip[l]][1]) + BB10_Encal[BB10Det[l]][BB10Strip[l]][0];


                            DS_PID->Fill(BSX3_En, BB10_En);

                            if(DS_deuterons->IsInside(BSX3_En, BB10_En))
                            {
                                kinematics_deuteron_PID->Fill(angle, BSX3_En+BB10_En);
                            }

                            if(DS_protons->IsInside(BSX3_En, BB10_En))
                            {
                                kinematics_proton_PID->Fill(angle, BSX3_En+BB10_En);
                            }





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
                if(QQQ5Det[j] <= 4 && QQQ5Ring[j] <= 31 && tdcSilicon >= 900 && tdcSilicon <= 1300) //Se82_locus_IC->IsInside(icE, icdE)
                //if(QQQ5Det[j] <= 4 && QQQ5Ring[j] <= 31) //Se82_locus_IC->IsInside(icE, icdE)
                {
                    hit_pos = hit_position_3D("QQQ5", QQQ5Upstream[j], QQQ5Det[j], QQQ5Ring[j], QQQ5Sector[j]);
                    
                    angle_IC_corrected = IC_corrected_angle(hit_pos.at(0),hit_pos.at(1),hit_pos.at(2), icPositionX, icPositionY);

                    //Calculating the event Q value
                    qValue = rel_q_value (angle_IC_corrected, QQQ5RingEnergy[j]);
                    excitation = 3593.0 - qValue;

                    initial_energy = initial_proton_energy((QQQ5RingEnergy[j]/1000.0), proton_distance_through_target(hit_pos));
                    corrected_excitation = 3593.0 - rel_q_value (angle_IC_corrected, initial_energy*1000.0);

                    //Filling histograms
                    kinematics->Fill(angle_IC_corrected, QQQ5RingEnergy[j]);
                    kinematics_eloss_corrected->Fill(angle_IC_corrected, initial_energy*1000.0);
                    qValue_vs_angle->Fill(angle_IC_corrected, qValue);
                    Excitation_vs_angle->Fill(angle_IC_corrected, corrected_excitation);

                    Ex_QQQ5->Fill(3593.0 - qValue);

                    Excitation_spec->Fill(3593.0 - qValue);
                    Excitation_spec_eloss_corrected->Fill(3593.0 - rel_q_value (angle_IC_corrected, initial_energy*1000.0));

                    QQQ5_Si_TDC->Fill(tdcSilicon);
                    QQQ5_IC_TDC->Fill(tdcIC);


                    //Filling the 3-D hit spectrum
                    // hit_position_spectrum->Fill(hit_pos.at(0), hit_pos.at(2), hit_pos.at(1));

                    //cout << QQQ5_angle[QQQ5Ring[j]] << "   " << proton_distance_through_target(hit_pos) << endl;

                    //cout << "QQQ5    " << hit_pos.at(0) << "  " <<hit_pos.at(1) << "  " <<hit_pos.at(2) << endl;

                    if(xtalsMul >= 1 && xtalsMul <= 3 && QQQ5Upstream[j] == 1)
                    {
                        for(int k=0; k<xtalsMul; k++)
                        {
                            if(QQQ5Upstream[j] == 1) gammaEx_matrix->Fill(corrected_excitation, xtals_edop[k]);
                            if(QQQ5Upstream[j] == 1) gammaEx_matrixQQQ5->Fill(corrected_excitation, xtals_edop[k]);




                            if(excitation >= 5818.0 && excitation <= 6818.0)
                            {
                                gamma_aboveSn->Fill(xtals_edop[k]);
                            }
                            if(excitation <= 5818.0 && excitation >= 4818.0)
                            {
                                gamma_belowSn->Fill(xtals_edop[k]);
                            }



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

    
    DS_PID->Write();
    kinematics->Write();
    kinematics_eloss_corrected->Write();
    Excitation_spec->Write();
    Excitation_spec_eloss_corrected->Write();
    ic_dE_E->Write();
    qValue_vs_angle->Write();
    Excitation_vs_angle->Write();
    gamEn_vs_gamAngle->Write();
    gammaEx_matrix->Write();
    gammaEx_matrixSX3->Write();
    gammaEx_matrixQQQ5->Write();
    gamma_no_offset->Write();
    gamma_z_offset->Write();
    kinematics_deuteron_PID->Write();
    kinematics_proton_PID->Write();
    SX3_en_vs_z_hist->Write();

    QQQ5_Si_TDC->Write();
    QQQ5_IC_TDC->Write();
    SX3_Si_TDC->Write();
    SX3_IC_TDC->Write();
    gamma_aboveSn->Write();
    gamma_belowSn->Write();
    //hit_position_spectrum->Write();

    siliconTDC_hist->Write();
    icTDC_hist->Write();
    grertinaTDC_hist->Write();
    delta_timestamp_vs_Run_hist->Write();
    tdcGRETINA_vs_Run_hist->Write();
    si_ic_vs_Run_hist->Write();
    Energy_vs_si_ic_hist->Write();
    Energy_vs_delta_timestamp_hist->Write();


    // for (int j=1; j<=number_of_SX3_bins; j++)
    // {
    //     Excitation_AngularBin[j]->Write();
    // }
    



    gamma_aboveSn->SetLineColor(kRed);
    gamma_belowSn->SetLineColor(kBlack);


    c2->cd();
    

    std::cout << endl;
    std::cout << "~~fin~~" << endl;

	return;
}
