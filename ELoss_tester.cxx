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

double ANGLEproton_distance_through_target(double theta, double phi)
{

    double target_norm[3] = {0, 0.454, -0.891};
    double half_targ = 1.604; //um


    double proton_vector[3] = {sin(phi)*cos(theta), sin(phi)*sin(theta), cos(phi)};

    double numerator = (target_norm[0]*proton_vector[0]) + (target_norm[1]*proton_vector[1]) + (target_norm[2]*proton_vector[2]);
    double denominator = sqrt( pow(proton_vector[0],2) + pow(proton_vector[1],2) + pow(proton_vector[2],2));
    double angle = acos( (numerator*1.)/(denominator*1.) );

    double material_length = half_targ / cos(angle);

    return abs(material_length);


}




void ELoss_tester()
{

	char pic_name[200];
	char title[200];

	TCanvas *c1 = new TCanvas("c1", "c1", 1000, 700);

	// ================ Histograms and Canvases ==================
    //TGraph2D* E_loss = new TGraph2D(304);

    TGraph2D* E_loss[200];

    int i =0;
    double test;
    double final_energy;
    // double energy = 2.0;
    int energy_counter = 0;

    Int_t nb = 99;

    gStyle->SetPalette(55);
	//TColor::InvertPalette();



	for(double energy=8; energy>0; energy=energy-0.1)
	{

		 E_loss[energy_counter] = new TGraph2D(98596);

		for(double phi_it = 0; phi_it <= 3.14159; phi_it=phi_it+0.01)
		{
			for(double theta_it = 0; theta_it <= 2*3.14159; theta_it=theta_it+0.02)
			{

				final_energy = proton_energy_loss(energy, ANGLEproton_distance_through_target(theta_it, phi_it));

				E_loss[energy_counter]->SetPoint(i,theta_it, phi_it, ((energy-final_energy)/energy)*100);

				

				i++;

			}
			
		}

		cout << energy << endl;

		sprintf(pic_name,"plots/proton_energy_loss/ELoss%d.png",int(energy_counter));
		sprintf(title,"Proton energy = %d keV",int(energy*1000));

		c1->cd();
		E_loss[energy_counter]->SetMaximum(100);
		E_loss[energy_counter]->SetMinimum(0.1);
		gPad->SetLogz();
		E_loss[energy_counter]->SetNpx(314);
		E_loss[energy_counter]->SetNpy(314);
		E_loss[energy_counter]->Draw("colz");
		E_loss[energy_counter]->SetTitle(title);
		c1->Update();
		c1->SaveAs(pic_name);

		energy_counter++;


	}

	







	return;
}