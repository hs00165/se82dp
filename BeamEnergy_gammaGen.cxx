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






int BeamEnergy_gammaGen()
{



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


    //2D Gates:

    //Elastic scattered deuterons, Energy vs Angle
    // 07/28/21
    TCutG *ElasticDeuterons = new TCutG("ElasticDeuterons",15);
    ElasticDeuterons->SetPoint(0,51.0316,15033.4);
    ElasticDeuterons->SetPoint(1,49.4209,14557.2);
    ElasticDeuterons->SetPoint(2,50.4206,12835.6);
    ElasticDeuterons->SetPoint(3,54.975,10015.1);
    ElasticDeuterons->SetPoint(4,58.474,7450.99);
    ElasticDeuterons->SetPoint(5,62.3063,4740.37);
    ElasticDeuterons->SetPoint(6,66.5274,2505.93);
    ElasticDeuterons->SetPoint(7,71.8593,2579.19);
    ElasticDeuterons->SetPoint(8,69.5266,3787.99);
    ElasticDeuterons->SetPoint(9,66.1942,5436.34);
    ElasticDeuterons->SetPoint(10,61.9176,8073.7);
    ElasticDeuterons->SetPoint(11,57.6965,11443.7);
    ElasticDeuterons->SetPoint(12,52.8644,14813.6);
    ElasticDeuterons->SetPoint(13,51.0871,15070);
    ElasticDeuterons->SetPoint(14,51.0316,15033.4);


    TCutG *AllElastics = new TCutG("AllElastics",8);
    AllElastics->SetPoint(0,52.691,14249.5);
    AllElastics->SetPoint(1,50.4751,13972.3);
    AllElastics->SetPoint(2,48.5834,7319.25);
    AllElastics->SetPoint(3,65.5,404.082);
    AllElastics->SetPoint(4,80.4169,1628.57);
    AllElastics->SetPoint(5,70.7425,14138.6);
    AllElastics->SetPoint(6,53.3936,14249.5);
    AllElastics->SetPoint(7,52.691,14249.5);





















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
	//
	// === GRETINA ===
	const Int_t NMAX = 44;
    bool  foundGRETINA = 0;
    int   xtalsMul = 0;
    float xtals_xlab[NMAX] = {0};
    float xtals_ylab[NMAX] = {0};
    float xtals_zlab[NMAX] = {0};
    float xtals_cc[NMAX] = {0};
    float xtals_edop[NMAX] = {0};
    float xtals_edopMaxInt[NMAX] = {0};
    float xtals_edopSeg[NMAX] = {0};
    float xtals_edopXtal[NMAX] = {0};
    int   xtals_crystalNum[NMAX] = {0};
    int   xtals_quadNum[NMAX] = {0};
    float xtals_t0[NMAX] = {0};
    long long  xtals_timestamp[NMAX] = {0};
    //
    // === Analysis parameters ===
    double qValue = 0;
    double angleChad, angleRaj, angleVIKAR;
    double angle;
    double prog_pos;
    double bar_width = 70.0;
    double thetaGamma = 0;
    double beta = 0.1300615; //initial=0.1329615
    double gamma_correction;
    vector<double> gamEn_vect;
    vector<double> gamAngle_vect;

    double angleChad_array[32] = {163.3007417,161.9958232,160.7099375,
    159.4439374,158.1985721,156.9744885,155.7722342,154.5922604,
    153.4349264,152.3005038,151.1891819,150.1010729,149.0362173,
    147.9945898,146.9761046,145.9806213,145.0079502,144.0578578,
    143.1300712,142.2242838,141.3401591,140.4773353,139.6354293,
    138.81404,138.012752,137.2311385,136.4687639,135.7251869,134.999962,
    134.292642,133.6027798,132.9299296};

    double angleRaj_array[32] = {164.808269,163.4356005,162.1088218,
    160.8277935,159.5921795,158.4014741,157.2550275,156.1520699,
    155.0917333,154.0730718,153.0950797,152.1567076,151.2568762,
    150.3944892,149.5684434,148.7776382,148.0209828,147.297403,
    146.6058462,145.9452856,145.3147239,144.7131956,144.1397691,
    143.5935483,143.0736732,142.5793211,142.1097063,141.6640801,
    141.2417311,140.8419845,140.4642012,140.107778};

    //double angleVIKAR_array[32] = {161.4726143,159.8423721,158.2767681,
//156.7751355,155.3364701,153.959492,152.6427027,151.3844349,150.1828982,
//149.0362173,147.9424656,146.8996932,145.9059497,144.9593038,144.0578578,
//143.1579315,142.3832138,141.6064842,140.8679031,140.1658722,139.4988646,
//138.8654264,138.2641758,137.6938028,137.1530679,136.6408,136.1558953,
//135.6973143,135.2640801,134.8552759,134.4700423,134.1075758};


    double angleVIKAR_array[32] = {163.0744381,161.5650356,160.1107911,
158.7113492,157.3660886,156.074164,154.834546,153.646057,
152.5074042,151.4172087,150.3740307,149.3763921,148.4227951,
147.5117381,146.6417294,145.770761,145.0190016,144.2634355,
143.543236,142.857086,142.2037171,141.5819122,140.9905062,140.4283872,
139.8944958,139.3878257,138.9074222,138.4523815,138.0218496,137.6150214,
137.2311385,136.8694885};



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
    TFile write("analysis_output/BeamEnergy_output.root", "recreate");

	// ================ Histograms and Canvases ==================
    TH2D* kinematics = new TH2D("kinematics", "kinematics", 360, 0, 180, 500, 0, 20000);
    TH2D* qValue_vs_angle = new TH2D("qValue_vs_angle", "qValue_vs_angle", 360,0,180, 500, -10000, 10000);
    TH2D* Excitation_vs_angle = new TH2D("Excitation_vs_angle", "Excitation_vs_angle", 360,0,180,500,-5000,15000);
    TH2D* gamEn_vs_gamAngle = new TH2D("gamEn_vs_gamAngle", "gamEn_vs_gamAngle", 720, 0, 360, 20000, 0, 10000);
    TH2D* gamEn_vs_gamAngle_Elastics = new TH2D("gamEn_vs_gamAngle_Elastics", "gamEn_vs_gamAngle_Elastics", 720, 0, 360, 20000, 0, 10000);
    TH2D* gammaEx_matrix = new TH2D("gammaEx_matrix", "gammaEx_matrix", 500,0,10000, 8000, 0, 10000);

    TH1D* gam_proj_7 = new TH1D("gam_proj_7", "gam_proj_7", 120, 620, 680);
    TH1D* gam_proj_8 = new TH1D("gam_proj_8", "gam_proj_8", 120, 620, 680);
    TH1D* gam_proj_9 = new TH1D("gam_proj_9", "gam_proj_9", 120, 620, 680);
    TH1D* gam_proj_10 = new TH1D("gam_proj_10", "gam_proj_10", 120, 620, 680);
    TH1D* gam_proj_11 = new TH1D("gam_proj_11", "gam_proj_11", 120, 620, 680);
    TH1D* gam_proj_12 = new TH1D("gam_proj_12", "gam_proj_12", 120, 620, 680);
    TH1D* gam_proj_13 = new TH1D("gam_proj_13", "gam_proj_13", 120, 620, 680);
    TH1D* gam_proj_14 = new TH1D("gam_proj_14", "gam_proj_14", 120, 620, 680);
    TH1D* gam_proj_15 = new TH1D("gam_proj_15", "gam_proj_15", 120, 620, 680);
    TH1D* gam_proj_16 = new TH1D("gam_proj_16", "gam_proj_16", 120, 620, 680);


    int BB10_counter = 0;
    double rawPos, calPos;

	//Getting the number of entries to loop through
	unsigned long long int nEntries = Chain->GetEntries();

    ofstream gamma_output_file;
    gamma_output_file.open ("BeamEnergy_gamma_output_file.txt");


	//Looping through each event:
	for ( unsigned long long int i=0; i<nEntries; i++ )
    {
    	Chain->GetEntry(i);





        // ===========================================================================
        // ===========================================================================
        // ==                                                                       ==
        // ==                             Super X3 processing                       ==
        // ==                                                                       ==
        // ===========================================================================
        // ===========================================================================
        if(SX3Mul >= 1)
        {
            for(int j=0; j<SX3Mul; j++)
            {
                if(SX3Det[j] <= 11 && SX3Strip[j] <= 3 && icE >= 800. && icdE >= 800.) //No weird events with wrong channels make it through
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

                    if(xtalsMul >= 1 && xtalsMul <= 3 && SX3Upstream[j]==1)
                    {
                        for(int k=0; k<xtalsMul; k++)
                        {
                            if(xtals_zlab[k] >= 0) thetaGamma = (180./3.14159) * atan(sqrt(pow(xtals_xlab[k],2) + pow(xtals_ylab[k],2))/xtals_zlab[k]);
                            if(xtals_zlab[k] < 0) thetaGamma = 180. + (180./3.14159) * atan(sqrt(pow(xtals_xlab[k],2) + pow(xtals_ylab[k],2))/xtals_zlab[k]);

                            gamma_correction = (1. - beta*cos(thetaGamma*(3.14159/180.))) / (sqrt( 1. - pow(beta,2) ));

                            gamEn_vs_gamAngle->Fill(thetaGamma, xtals_edop[k]);
                            gammaEx_matrix->Fill(3593.0 - qValue, xtals_edop[k]);


                        }
                    }


                    if(xtalsMul >= 1 && xtalsMul <= 3 && AllElastics->IsInside(angle, BSX3_En))
                    {
                        for(int k=0; k<xtalsMul; k++)
                        {

                            if(xtals_zlab[k] >= 0) thetaGamma = (180./3.14159) * atan(sqrt(pow(xtals_xlab[k],2) + pow(xtals_ylab[k],2))/xtals_zlab[k]);
                            if(xtals_zlab[k] < 0) thetaGamma = 180. + (180./3.14159) * atan(sqrt(pow(xtals_xlab[k],2) + pow(xtals_ylab[k],2))/xtals_zlab[k]);

                            gamma_correction = (1. - beta*cos(thetaGamma*(3.14159/180.))) / (sqrt( 1. - pow(beta,2) ))*xtals_cc[k];

                            gamEn_vs_gamAngle_Elastics->Fill(thetaGamma, xtals_cc[k]);

                            if(xtals_cc[k] >= 550 && xtals_cc[k] <= 700)
                            {
                                gamEn_vect.push_back(thetaGamma);
                                gamAngle_vect.push_back(xtals_cc[k]);

                                gamma_output_file << thetaGamma << setw(15) << xtals_cc[k] << endl;
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
        if(QQQ5Mul >= 1)
        {
            for(int j=0; j<QQQ5Mul; j++)
            {
                if(QQQ5Det[j] <= 4 && QQQ5Ring[j] <= 31 && icE >= 800. && icdE >= 800.) //No weird events with wrong channels make it through
                {

                    //Debugging QQQ5 angle
                    angleChad = angleChad_array[QQQ5Ring[j]];
                    angleRaj = angleRaj_array[QQQ5Ring[j]];
                    angleVIKAR = angleVIKAR_array[QQQ5Ring[j]];

                    //Calculating the event Q value
                    qValue = rel_q_value (angleVIKAR, QQQ5RingEnergy[j]);

                    //Filling histograms
                    kinematics->Fill(angleVIKAR, QQQ5RingEnergy[j]);
                    qValue_vs_angle->Fill(angleVIKAR, qValue);
                    Excitation_vs_angle->Fill(angleVIKAR, 3593.0 - qValue);


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



    kinematics->Write();
    qValue_vs_angle->Write();
    Excitation_vs_angle->Write();
    gamEn_vs_gamAngle->Write();
    gamEn_vs_gamAngle_Elastics->Write();
    gammaEx_matrix->Write();



	return 0;
}
