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



Double_t gaus_and_pol1 ( Double_t *x, Double_t *par )
{
    return par[0] * TMath::Exp ( -0.5 * ( pow ( x[0] - (par[1]), 2 ) / pow ( par[2], 2 ) ) ) + (par[3]*x[0]) + par[4];
}



Double_t asymGaus_and_pol1 ( Double_t *x, Double_t *par )
{
	if(x[0] >= par[1]) {
    	return par[0] * TMath::Exp ( -0.5 * ( pow ( x[0] - (par[1]), 2 ) / pow ( par[2], 2 ) ) ) + (par[3]*x[0]) + par[4];
    }
    if(x[0] < par[1]) {
    	return par[0] * TMath::Exp ( -0.5 * ( pow ( x[0] - (par[1]), 2 ) / pow ( (par[2]*par[5]), 2 ) ) ) + (par[3]*x[0]) + par[4];
    }

}





void GRETINA_calibrator()
{

	TCanvas* c1 = new TCanvas("c1", "c1", 400, 400);




	int sourceSelection;
	vector<double> knownPeakLocations;
	const char* fileString;
	cout << "Please enter which source to analyze:" << endl;
	cout << "1: 88Y  2: 152Eu  3: 182Ta  4: 56Co  5: 60Co  6: 243Am" << endl;
	cin >> sourceSelection;





	ofstream peakOutputFile;
	// Loading peak information depending on the source used!

	// ===== Y88 =====
	if(sourceSelection == 1) {
		fileString = "/mnt/se82dp_2/gretina_cal/Y88.root";
		knownPeakLocations = {898.036, 1836.052};
		peakOutputFile.open ("cal/GRETINA_cal/Y88_peaks.dat");
	}
	// ===== Eu152 =====
	if(sourceSelection == 2) {
		fileString = "/mnt/se82dp_2/gretina_cal/Eu152.root";
		knownPeakLocations = {121.782, 244.6975, 344.2785, 778.904, 964.079, 1085.869, 1112.074, 1408.006};
		peakOutputFile.open ("cal/GRETINA_cal/Eu152_peaks.dat");
	}
	// ===== Ta182 =====
	if(sourceSelection == 3) {
		fileString = "/mnt/se82dp_2/gretina_cal/Ta182.root";
		knownPeakLocations = {1121.298, 1189.046, 1221.399};
		peakOutputFile.open ("cal/GRETINA_cal/Ta182_peaks.dat");
	}
	// ===== Co56 =====
	if(sourceSelection == 4) {
		fileString = "/mnt/se82dp_2/gretina_cal/Co56.root";
		knownPeakLocations = {846.772, 1037.840, 1238.282, 1771.351, 2034.755, 2598.458, 3201.962, 3253.416};
		peakOutputFile.open ("cal/GRETINA_cal/Co56_peaks.dat");
	}
	// ===== Co60 =====
	if(sourceSelection == 5) {
		fileString = "/mnt/se82dp_2/gretina_cal/Co60.root";
		knownPeakLocations = {1173.237, 1332.501};
		peakOutputFile.open ("cal/GRETINA_cal/Co60_peaks.dat");
	}
	// ===== Am243 =====
	if(sourceSelection == 6) {
		fileString = "/mnt/se82dp_2/gretina_cal/Am243.root";
		knownPeakLocations = {74.66};
		peakOutputFile.open ("cal/GRETINA_cal/Am243_peaks.dat");
	}










	int number_of_peaks = knownPeakLocations.size();


    ROOT::Math::MinimizerOptions::SetDefaultMinimizer("Minuit2");
    ROOT::Math::MinimizerOptions::SetDefaultMaxFunctionCalls(1000000);
    ROOT::Math::MinimizerOptions::SetDefaultMaxIterations(1000000);
    ROOT::Math::MinimizerOptions::SetDefaultTolerance(0.001);


	TFile *f = new TFile(fileString);

	TH2D * raw2D_histogram;
	raw2D_histogram = (TH2D*)f->Get("energy_vs_crystalNum");

	//Initializing histograms for the energy projections of each angular bin
	TH1D * crystalEnergy[200];
	char crystalEnergyName[200];

	double fit_min_range;
	double fit_max_range;
	double peakAmplitude, peakCentroid, peakStdDev, peakAsymFactor;
	double peakAmplitudeErr, peakCentroidErr, peakStdDevErr, peakAsymFactorErr;

	// Loop over each crystal to fit the peaks 
	for(int i=0; i<100; i++) {


		sprintf(crystalEnergyName,"crystalEnergy_%d",i);

		crystalEnergy[i] = raw2D_histogram->ProjectionY(crystalEnergyName,i,i+1,"");

		//making sure that there are counts in the crystal (ie, it's being used)
		if(crystalEnergy[i]->GetEntries() >= 10) {


	        // crystalEnergy[i]->Draw();

	        // looping through peaks to be fit
	        for(int peak=0; peak<number_of_peaks; peak++) {

	        	fit_min_range = knownPeakLocations.at(peak) - 15;
	        	fit_max_range = knownPeakLocations.at(peak) + 15;

	        	cout << fit_min_range << "  " << fit_max_range << endl;

		        TF1* gaus_fit = new TF1 ( "gaus_fit",asymGaus_and_pol1,fit_min_range, fit_max_range, 6 );

		        gaus_fit->SetParameter(1, knownPeakLocations.at(peak));
		        gaus_fit->SetParameter(2, 2.);
		        gaus_fit->SetParameter(5, 1.);




		        crystalEnergy[i]->Fit ( "gaus_fit", "r" );

		        peakAmplitude = gaus_fit->GetParameter(0);
		        peakCentroid = gaus_fit->GetParameter(1);
		        peakStdDev = gaus_fit->GetParameter(2);
		        peakAsymFactor = gaus_fit->GetParameter(5);

		        peakAmplitudeErr = gaus_fit->GetParError(0);
		        peakCentroidErr = gaus_fit->GetParError(1);
		        peakStdDevErr = gaus_fit->GetParError(2);
		        peakAsymFactorErr = gaus_fit->GetParError(5);

		        // Writing the fit parameters to file
		        // columns as follows:
		        // Crystal number  |  known peak loc  |  peak amp  |  peak centroid  |  peak std dev  |  peak asym factor (r)  |  amp error  |  centroid error  |  std dev error  |  peak asym factor
		        peakOutputFile << i << setw(15) << knownPeakLocations.at(peak) << setw(15) << peakAmplitude << setw(15) << peakCentroid << setw(15) << peakStdDev << setw(15) << peakAsymFactor << setw(15) << peakAmplitudeErr << setw(15) << peakCentroidErr << setw(15) << peakStdDevErr << setw(15) << peakAsymFactorErr << endl;

	    	}
	  //   	c1->cd();
			// crystalEnergy[i]->Draw();



		}




	}




	peakOutputFile.close();

	return;
}