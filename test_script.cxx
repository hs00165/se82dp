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



void test_script()
{



	// Creating the Chain of runs to use
	TChain* Chain = new TChain ( "data" );

	Chain->Add("data/Run038_combined.root");















	// ===================== Data variables =====================
	// 
	//  === BB10 ===
	int   BB10Mul;
	int   BB10Det[36];
	int   BB10Strip[36];
	int   BB10Channel[36];
	int   BB10ADC[36];
	float BB10Energy[36];
	//
	// === QQQ5 ===
	int   QQQ5Mul;
	int   QQQ5Upstream[36];
	int   QQQ5Det[36];
	int   QQQ5Ring[36];
	int   QQQ5RingChannel[36];
	int   QQQ5Sector[36];
	int   QQQ5SectorChannel[36];
	int   QQQ5RingADC[36];
	float QQQ5RingEnergy[36];
	int   QQQ5SectorADC[36];
	float QQQ5SectorEnergy[36];
	float QQQ5Angle[36];
	//
	// === SX3 ===
	int   SX3Mul;
	int   SX3Upstream[36];
	int   SX3Det[36];
	int   SX3Sector[36];
	int   SX3SectorChannel[36];
	int   SX3SectorADC[36];
	float SX3SectorEnergy[36];
	int   SX3Strip[36];
	int   SX3StripLeftChannel[36];
	int   SX3StripRightChannel[36];
	int   SX3StripLeftADC[36];
	int   SX3StripRightADC[36];
	float SX3StripEnergy[36];
	//
	// === IC ===
	int   icdE;
	int   icE;
	int   icWireX;
	int   icWireY;
	float icPositionX;
	float icPositionY;
	float icPositionWeightedX;
	float icPositionWeightedY;
	//
	// === TDC ===
	int   tdcIC;
	int   tdcGRETINA;
	int   tdcRF;
	int   tdcSilicon;
	int   timeStamp;
	int   GRETINATimeStamp;
	//
	// === GRETINA ===
	bool  foundGRETINA;
	int   xtalsMul;
	float xtals_xlab[10];
	float xtals_ylab[10];
	float xtals_zlab[10];
	float xtals_cc[10];
	float xtals_edop[10];
	float xtals_edopMaxInt[10];
	float xtals_edopSeg[10];
	float xtals_edopXtal[10];
	int   xtals_crystalNum[10];
	int   xtals_quadNum[10];
	float xtals_t0[10];
	long  xtals_timestamp[10];

/*

	// ================ BB10 Branch Addresses ===================
	Chain->SetBranchAddress ( "BB10Mul", &BB10Mul );
	Chain->SetBranchAddress ( "BB10Det", &BB10Det );
	Chain->SetBranchAddress ( "BB10Strip", &BB10Strip );
	Chain->SetBranchAddress ( "BB10Channel", &BB10Channel );
	Chain->SetBranchAddress ( "BB10ADC", &BB10ADC );
	Chain->SetBranchAddress ( "BB10Energy", &BB10Energy );


	// ================ QQQ5 Branch Addresses ===================
	Chain->SetBranchAddress ( "QQQ5Mul", &QQQ5Mul );
	Chain->SetBranchAddress ( "QQQ5Upstream", &QQQ5Upstream );
	Chain->SetBranchAddress ( "QQQ5Det", &QQQ5Det );
	Chain->SetBranchAddress ( "QQQ5Ring", &QQQ5Ring );
	Chain->SetBranchAddress ( "QQQ5RingChannel", &QQQ5RingChannel );
	Chain->SetBranchAddress ( "QQQ5Sector", &QQQ5Sector );
	Chain->SetBranchAddress ( "QQQ5SectorChannel", &QQQ5SectorChannel );
	Chain->SetBranchAddress ( "QQQ5RingADC", &QQQ5RingADC );
	Chain->SetBranchAddress ( "QQQ5RingEnergy", &QQQ5RingEnergy );
	Chain->SetBranchAddress ( "QQQ5SectorADC", &QQQ5SectorADC );
	Chain->SetBranchAddress ( "QQQ5SectorEnergy", &QQQ5SectorEnergy );


	// =================== SX3 Branch Address ==================
	Chain->SetBranchAddress ( "SX3Mul", &SX3Mul );
	Chain->SetBranchAddress ( "SX3Upstream", &SX3Upstream );
	Chain->SetBranchAddress ( "SX3Det", &SX3Det );
	Chain->SetBranchAddress ( "SX3Sector", &SX3Sector );
	Chain->SetBranchAddress ( "SX3SectorChannel", &SX3SectorChannel );
	Chain->SetBranchAddress ( "SX3SectorADC", &SX3SectorADC );
	Chain->SetBranchAddress ( "SX3SectorEnergy", &SX3SectorEnergy );
	Chain->SetBranchAddress ( "SX3Strip", &SX3Strip );
	Chain->SetBranchAddress ( "SX3StripLeftChannel", &SX3StripLeftChannel );
	Chain->SetBranchAddress ( "SX3StripRightChannel", &SX3StripRightChannel );
	Chain->SetBranchAddress ( "SX3StripLeftADC", &SX3StripLeftADC );
	Chain->SetBranchAddress ( "SX3StripRightADC", &SX3StripRightADC );
	Chain->SetBranchAddress ( "SX3StripEnergy", &SX3StripEnergy );


	// =================== IC Branch Address ===================
	Chain->SetBranchAddress ( "icdE", &icdE );
	Chain->SetBranchAddress ( "icE", &icE );
	Chain->SetBranchAddress ( "icWireX", &icWireX );
	Chain->SetBranchAddress ( "icWireY", &icWireY );
	Chain->SetBranchAddress ( "icPositionX", &icPositionX );
	Chain->SetBranchAddress ( "icPositionY", &icPositionY );
	Chain->SetBranchAddress ( "icPositionWeightedX", &icPositionWeightedX );
	Chain->SetBranchAddress ( "icPositionWeightedY", &icPositionWeightedY );


	// =================== TDC Branch Address ==================
	Chain->SetBranchAddress ( "tdcIC", &tdcIC );
	Chain->SetBranchAddress ( "tdcGRETINA", &tdcGRETINA );
	Chain->SetBranchAddress ( "tdcRF", &tdcRF );
	Chain->SetBranchAddress ( "tdcSilicon", &tdcSilicon );
	Chain->SetBranchAddress ( "timeStamp", &timeStamp );
	Chain->SetBranchAddress ( "GRETINATimeStamp", &GRETINATimeStamp );


	// ================= GRETINA Branch Address ================
	Chain->SetBranchAddress ( "foundGRETINA", &foundGRETINA );
	Chain->SetBranchAddress ( "xtalsMul", &xtalsMul );
	Chain->SetBranchAddress ( "xtals_xlab", &xtals_xlab );
	Chain->SetBranchAddress ( "xtals_ylab", &xtals_ylab );
	Chain->SetBranchAddress ( "xtals_zlab", &xtals_zlab );
	Chain->SetBranchAddress ( "xtals_cc", &xtals_cc );
	Chain->SetBranchAddress ( "xtals_edop", &xtals_edop );
	Chain->SetBranchAddress ( "xtals_edopMaxInt", &xtals_edopMaxInt );
	Chain->SetBranchAddress ( "xtals_edopSeg", &xtals_edopSeg );
	Chain->SetBranchAddress ( "xtals_edopXtal", &xtals_edopXtal );
	Chain->SetBranchAddress ( "xtals_crystalNum", &xtals_crystalNum );
	Chain->SetBranchAddress ( "xtals_quadNum", &xtals_quadNum );
	Chain->SetBranchAddress ( "xtals_t0", &xtals_t0 );
	Chain->SetBranchAddress ( "xtals_timestamp", &xtals_timestamp );


*/

	// ================ Histograms and Canvases ==================
	TCanvas* c1 = new TCanvas("c1", "c1", 400, 400);

	TH2D* Gamma_ParticleEnergy_Matrix = new TH2D("Gamma_ParticleEnergy_Matrix", "Gamma_ParticleEnergy_Matrix", 1000, 0, 5000, 1000, 0, 5000);











	//Getting the number of entries to loop through
	unsigned long long int nEntries = Chain->GetEntries();


	//Looping through each event:
	for ( unsigned long long int i=0; i<nEntries; i++ )
    {


    		cout << i << "   " << nEntries << endl;

    	Chain->GetEntry ( i );

    /*


    	if(BB10Mul >= 1)
    	{
    		cout << "=== BB10 ===" << endl;
    		cout << setw(18) << "Det" << setw(18) << "Strip" << setw(18) << "Channel" << setw(18) << "ADC" << setw(18) << "Energy" << endl;
    		for(int j=0; j<BB10Mul; j++)
    		{
    			cout << setw(18) << BB10Det[j] << setw(18) << BB10Strip[j] << setw(18) << BB10Channel[j] << setw(18) << BB10ADC[j] << setw(18) << BB10Energy[j] << endl;
    		}
    	}


		if(QQQ5Mul >= 1)
    	{
    		cout << "=== QQQ5 ===" << endl;
    		cout << setw(18) << "Upstream?" << setw(18) << "Det" << setw(18) << "Ring" << setw(18) << "Sector" << setw(18) << "Ring Energy" << setw(18) << "Sector ADC" << endl;
    		for(int j=0; j<QQQ5Mul; j++)
    		{
    			cout << setw(18) << QQQ5Upstream[j] << setw(18) << QQQ5Det[j] << setw(18) << QQQ5Ring[j] << setw(18) << QQQ5Sector[j] << setw(18) << QQQ5RingEnergy[j] << setw(18) << QQQ5SectorADC[j] << endl;
    		}
    	}


    	if(SX3Mul >= 1)
    	{
    		cout << "=== SX3 ===" << endl;
    		cout << setw(18) << "Upstream?" << setw(18) << "Det" << setw(18) << "Strip" << setw(18) << "Sector" << setw(18) << "Strip Left ADC" << setw(18) << "Strip Right ADC" << setw(18) << "Sector ADC" << endl;
    		for(int j=0; j<SX3Mul; j++)
    		{
    			cout << setw(18) << SX3Upstream[j] << setw(18) << SX3Det[j] << setw(18) << SX3Strip[j] << setw(18) << SX3Sector[j] << setw(18) << SX3StripLeftADC[j] << setw(18) << SX3StripRightADC[j] << setw(18) << SX3SectorADC[j] << endl;
    		}
    	}


    	if(xtalsMul >= 1 && xtalsMul <= 100)
    	{
    		cout << "=== GRETINA ===  " << xtalsMul << endl;
    		cout << setw(18) << "X (lab)" << setw(18) << "Y (lab)" << setw(18) << "Z (lab)" << setw(18) << "CC" << setw(18) << "e dop" << setw(18) << "Crystal number" << setw(18) << "Quad number" << endl;
    		for(int j=0; j<xtalsMul; j++)
    		{
    			cout << setw(18) << xtals_xlab[j] << setw(18) << xtals_ylab[j] << setw(18) << xtals_zlab[j] << setw(18) << xtals_cc[j] << setw(18) << xtals_edop[j] << setw(18) << xtals_crystalNum[j] << setw(18) << xtals_quadNum[j] << endl;
    		}
    	}

*/

/*
    	if(xtalsMul >= 10)
    	{
    		for(int a=0; a<xtalsMul; )
    	}

    	if(QQQ5Mul <= 100 && xtalsMul <= 1)
    	{
    		for(int j=0; j<QQQ5Mul; j++)
    		{
    			for(int k=0; k<xtalsMul; k++)
    			{

    				Gamma_ParticleEnergy_Matrix->Fill(QQQ5SectorEnergy[j], xtals_cc[k]);


    			}


    		}
    	}






    	c1->cd();
    	Gamma_ParticleEnergy_Matrix->Draw("COLZ");

*/


    	



    }



	return;
}