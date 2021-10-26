#ifndef GODDESSAnalysis_h
#define GODDESSAnalysis_h

#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <TROOT.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TChain.h>
#include <TTree.h>
#include <TMath.h>
#include <TCutG.h>
#include <TH2.h>
#include <TStyle.h>

// Header file for the classes stored in the TTree if any.

class GODDESSAnalysis {

	public:
	
		int main();
		void SortAndAnalyze(Int_t );

		//Input file and tree
		TFile			*fin;
		TTree          *fChain;   //!pointer to the analyzed TTree or TChain
		// Leaves on the input file
		Int_t           BB10Mul;
		Int_t           BB10Det[128];   //[BB10Mul]
		Int_t           BB10Strip[128];   //[BB10Mul]
		Int_t           BB10Channel[128];   //[BB10Mul]
		Int_t           BB10ADC[128];   //[BB10Mul]
		Float_t         BB10Energy[128];   //[BB10Mul]
		Int_t           QQQ5Mul;
		Char_t          QQQ5Upstream[128];   //[QQQ5Mul]
		Int_t           QQQ5Det[128];   //[QQQ5Mul]
		Int_t           QQQ5Ring[128];   //[QQQ5Mul]
		Int_t           QQQ5RingChannel[128];   //[QQQ5Mul]
		Int_t           QQQ5Sector[128];   //[QQQ5Mul]
		Int_t           QQQ5SectorChannel[128];   //[QQQ5Mul]
		Int_t           QQQ5RingADC[128];   //[QQQ5Mul]
		Float_t         QQQ5RingEnergy[128];   //[QQQ5Mul]
		Int_t           QQQ5SectorADC[128];   //[QQQ5Mul]
		Float_t         QQQ5SectorEnergy[128];   //[QQQ5Mul]
		Float_t         QQQ5Angle[128];   //[QQQ5Mul]
		Int_t           SX3Mul;
		Char_t          SX3Upstream[128];   //[SX3Mul]
		Int_t           SX3Det[128];   //[SX3Mul]
		Int_t           SX3Sector[128];   //[SX3Mul]
		Int_t           SX3SectorChannel[128];   //[SX3Mul]
		Int_t           SX3SectorADC[128];   //[SX3Mul]
		Float_t         SX3SectorEnergy[128];   //[SX3Mul]
		Int_t           SX3Strip[128];   //[SX3Mul]
		Int_t           SX3StripLeftChannel[128];   //[SX3Mul]
		Int_t           SX3StripRightChannel[128];   //[SX3Mul]
		Int_t           SX3StripLeftADC[128];   //[SX3Mul]
		Int_t           SX3StripRightADC[128];   //[SX3Mul]
		Float_t         SX3StripEnergy[128];   //[SX3Mul]
		Int_t           icdE;
		Int_t           icE;
		Int_t           icWireX;
		Int_t           icWireY;
		Float_t         icPositionX;
		Float_t         icPositionY;
		Float_t         icPositionWeightedX;
		Float_t         icPositionWeightedY;
		Int_t           tdcIC;
		Int_t           tdcGRETINA;
		Int_t           tdcRF;
		Int_t           tdcSilicon;
		ULong64_t       timeStamp;
		ULong64_t       GRETINATimeStamp;
		Bool_t			foundGRETINA;
		Int_t			xtalsMul;
		Float_t			xtals_xlab[128];
		Float_t			xtals_ylab[128];
		Float_t			xtals_zlab[128];
		Float_t			xtals_cc[128];
		Float_t			xtals_edop[128];
		Float_t			xtals_edopMaxInt[128];
		Float_t			xtals_edopSeg[128];
		Float_t			xtals_edopXtal[128];
		Int_t			xtals_crystalNum[128];
		Int_t			xtals_quadNum[128];
		Float_t			xtals_t0[128];
		ULong64_t		xtals_timestamp[128];

		Long64_t current;

		//Output file and tree
		TFile* fout;
		TTree* tree;
		bool IC_PID, Si_PID, elastic_protons;
		float TDC_IC, TDC_GRETINA, TDC_RF, TDC_Si, IC_dE, IC_Eres, uQQQ5_Angle[128], uQQQ5_Energy[128], dQQQ5_Angle[128], dQQQ5_dE[128], dQQQ5_E1[128], dQQQ5_E2[128], dQQQ5_Energy, uSX3_Angle[128], uSX3_Energy[128], dSX3_Angle[128], dSX3_Energy[128], BB10_Energy[128], Egamma[128];
		std::vector<float> Si_Angle, Si_Energy, uQQQ5_Ex, dQQQ5_Ex, uSX3_Ex, dSX3_Ex; //These need to be vectors
		int IC_x, IC_y;

		// Some static variables for the code
		double m1 = 133.911369*931.494013*1000.0; // mass of beam, 134Te
		double m2 = 2.0141077785*931.494013*1000.0; // target mass, d
		double m3 = 1.00782503207*931.494013*1000.0; // ejectile mass, p
		double m4 = 134.91645 * 931.494013*1000.0; // recoil mass, 135Te
		double Q = 1.042*1000.0; //ground state Q-value
		double PI = 4.0*atan(1.0); // Pi is a very special number, used by clever people who like circles. Basically just 3. B.S.J.
		double T1 = 1150.63*1000.0; // Energy of 1177 MeV 134Te after passing halfway through 621 ug/cm^2 CD2 target, inclined at 27 degrees.
		double Ereact = 1149.994*1000.0; // Maximum energy of 135Te assuming a reaction at the center of the 621 ug/cm^2 CD2 target, inclined at 27 degrees
		double beta = 0.1343765*1000.0; //Beta doppler correction parameter for Ereact
		double barrel_radius = 98.; //barrel radius in mm

		//Some quick kinematic calculations
		double E1 = T1 + m1;
		double p1 = TMath::Sqrt(E1*E1 - m1*m1);
		double E3, p3;

		/*
		Double_t Etot_134Te = Ebeam+m134Te; //134Te total energy
		Double_t Etot_lab = Etot_134Te+md;  //total energy in the lab frame???
		Double_t Etot_cm = sqrt((m134Te*m134Te)+(md*md)+2.*Etot_134Te*md);  // total energy in the CM frame
		Double_t p1 = sqrt(Ebeam*Ebeam+(2.0*m134Te*Ebeam));
		*/

		//Arrays to store calibration parameters
		double uQQQ5fAngleCal[32], dQQQ5fAngleCal[32], uQQQ5bEnCal_slope[4][4], uQQQ5bEnCal_offset[4][4], dQQQ5bEnCal_slope[3][4], dQQQ5bEnCal_offset[3][4], uQQQ5fEnCal_slope[4][32], uQQQ5fEnCal_offset[4][32], dQQQ5fEnCal_slope[3][32], dQQQ5fEnCal_offset[3][32], BB10EnCal_slope[8][8], BB10EnCal_offset[8][8], uSX3bPedestals[12][4], dSX3bPedestals[12][4], uSX3fPedestals_left[12][4], uSX3fPedestals_right[12][4], dSX3fPedestals_left[12][4], dSX3fPedestals_right[12][4], uSX3fGains[12][4], dSX3fGains[12][4], uSX3bEnCal_slope[12][4][4], uSX3bEnCal_offset[12][4][4], dSX3bEnCal_slope[12][4][4], dSX3bEnCal_offset[12][4][4], uSX3fEnCal_slope[12][4][4],uSX3fEnCal_offset[12][4][4], dSX3fEnCal_slope[12][4][4], dSX3fEnCal_offset[12][4][4], uSX3fPosCal_left[12][4], uSX3fPosCal_right[12][4], dSX3fPosCal_left[12][4], dSX3fPosCal_right[12][4];

		//Intermediate values
		float uQQQ5f_Energy, uQQQ5b_Energy, dQQQ5f_Energy, dQQQ5b_Energy, dQQQ5_dE_Angle_sum, dQQQ5_E1_Angle_sum, dQQQ5_E2_Angle_sum, uSX3f_L, uSX3f_R, uSX3b_Energy, uSX3f_Energy, uSX3f_Position, dSX3f_L, dSX3f_R, dSX3b_Energy, dSX3f_Energy, dSX3f_Position, telescope_energy;
		int dQQQ5_dE_hit, dQQQ5_E1_hit, dQQQ5_E2_hit;

		int prevRunNumber;

};

#endif
