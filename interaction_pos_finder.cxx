

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
#include "CubicSpline.h"

#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TChain.h"

std::vector<double> looper(TCutG* cut, ifstream& data, ifstream& expected_kinematics_file)
{

	TH2D* en_vs_z = new TH2D("en_vs_z", "en_vs_z", 400, -2, 2, 10000, 0, 20);
	TH2D* final_kin = new TH2D("final_kin", "final_kin", 720, 0, 180, 10000, 0, 20);



	Int_t u = 0;
	Double_t xValue[181];
	Double_t yValue[181];
	double zpos, en;
	string line;
	std::vector<double> result;

	vector<double> zposvect;
	vector<double> envect;

	// reading in the .dat file with columns of energy and z position
	// of the experimental data
	while (getline(data, line))
	{
		istringstream in(line);
		in >> en >> zpos;
		
		zposvect.push_back(zpos);
		envect.push_back(en);
	}


	double dr, dz;
	double theta_i1, theta_i2, theta_i3;
	double E_i1, E_i2, E_i3;
	double difference, difference_1, difference_2;
	double theta_f1, theta_f2, theta_f3;
	double theta_calc_1, theta_calc_2;
	int prog_pos;
	int bar_width=68;


	vector<double> theta_theory;
	vector<double> E_theory;
	vector<double> theta_theorynew;
	vector<double> E_theorynew;


	// Reading in the caculated kinematics file
	while (getline(expected_kinematics_file, line))
	{
		istringstream in(line);
		in >> xValue[u] >> yValue[u];

		E_theory.push_back(yValue[u]);
		theta_theory.push_back(xValue[u]);
		// cout << E_theory.at(u) << "    " << theta_theory.at(u) << endl;
		u++;
	}

	// Looping BACK over the values, because Josh's CubicSpline function
	// only works if you give it x values that go smallest to largest - so
	// just correcting for that here.
	for (int t = E_theory.size(); t > -1; t--) {

		E_theorynew.push_back(E_theory[t]);
		theta_theorynew.push_back(theta_theory[t]);
		// cout << E_theory[t] << "  " << theta_theory[t] << endl;
	}

	TGraph* gStateKin = new TGraph(u, xValue, yValue);

	CubicSpline groundStateSpline(E_theorynew, theta_theorynew);


	double diff_saved = 100000.0, rloop_saved, zloop_saved;
	double theta_calc_loop, theta_theory_loop;

	// defining bounds of search for optimal geometry
	int z_lower = -20;
	int z_upper = 50;
	int r_lower = 70;
	int r_upper = 120;

	int total_number_of_loops = (z_upper - z_lower)*(r_upper - r_lower);
	int n = 0;

	TGraph2D* minimization_plot = new TGraph2D(total_number_of_loops);

	

	// Looping through a range of different geometries, and calculating a 
	// "cost" for each loop - how far is the experimental data from the expected 
	// kinematics line?
	for (int zloop = z_lower; zloop < z_upper; zloop++)
	{
		for (int rloop = r_lower; rloop < r_upper; rloop++)
		{
			dr = rloop * 1.0;
			dz = zloop * 1.0;
			difference = 0.0;

			// Looping through events, and calculating the total "difference" (cost)
			// of that particular geometry
			for (int t = 0; t < zposvect.size(); t++)
			{
				// filtering events through which fall into the provided gate for the state of interest.
				if (cut->IsInside(zposvect.at(t), envect.at(t)))
				{

					// Calculating the expected 
					theta_theory_loop = groundStateSpline(envect.at(t));
					theta_calc_loop = 180.0 - (180.0 / 3.14159) * atan((1.0 * dr ) / (1.0 * (dz + abs(zposvect.at(t)*75.) )));

					// Summing the difference between the expected angle, and calculated angle
					// for each event
					difference = difference + abs(theta_theory_loop - theta_calc_loop);
				}
			}

			// Seeing if this loop gives the smallest difference to the
			// predicted kinematics line. If so, save the geometry information.
			if (difference <= diff_saved)
			{
				diff_saved = difference;
				zloop_saved = zloop;
				rloop_saved = rloop;
			}

			minimization_plot->SetPoint(n, zloop, rloop, difference);

			//Progress update
            std::cout << "[";
            prog_pos = bar_width*(1.0*n/total_number_of_loops);
            for(int h=0; h<bar_width; h++)
            {
                if(h<=prog_pos) std::cout << "=";
                else std::cout << " ";
            }
            std::cout << "]" << int((1.0*n/total_number_of_loops)*100.0) << "%";
        
	        std::cout << "\r";

		
			n++;

		}
	}
	cout << endl;
	cout << endl;

	// Looping through events again to generate the finalized kinematics plot 
	// to be displayed to the user.
	for (int t = 0; t < zposvect.size(); t++)
	{
		theta_calc_loop = 180.0 - (180.0 / 3.14159) * atan((1.0 * rloop_saved ) / (1.0 * (zloop_saved + abs(zposvect.at(t)*75.) )));
	
		final_kin->Fill(theta_calc_loop, envect.at(t));
		en_vs_z->Fill(zposvect.at(t), envect.at(t));
	}


	//Creating canvases to display the output data to the user
	TCanvas* c1 = new TCanvas("c1", "c1", 400, 400);
	TCanvas* c2 = new TCanvas("c2", "c2", 400, 400);
	TCanvas* c3 = new TCanvas("c3", "c3", 400, 400);

	c1->cd();
	en_vs_z->Draw();
	cut->Draw("SAME");

	c2->cd();
	final_kin->Draw();
	gStateKin->Draw("SAME");

	c3->cd();
	c3->SetLogz();
	minimization_plot->Draw("colz");
	
	result.push_back(diff_saved);
	result.push_back(zloop_saved);
	result.push_back(rloop_saved);

	return result;
}







void interaction_pos_finder()
{


    //standard spiel
    cout << "=========================================================================" << endl;
    cout << "                        Interaction position finder                      " << endl;
    cout << "=========================================================================" << endl;
    cout << " " << endl;
    cout << "|=======================================================================|" << endl;
    cout << "|                                                                       |" << endl;
    cout << "|  This script will output the radius and z offset that matches         |" << endl;
    cout << "|  the kinematics best.                                                 |" << endl;
    cout << "|                                                              H. Sims  |" << endl;
    cout << "|=======================================================================|" << endl;


    // ============      USER INPUTS HERE     ============

    // STEP 1:
    //--------
    // Type in energy vs z position file location here:
    // Should be in two columns of Energy [MeV] and z position [between 0 and 1]
    // on the detector face.
    ifstream data ( "en_vs_z_SX3.dat");

    // STEP 2:
    //--------
	// Expected kinematics, generated from CaATKIN / Skisickness.com etc.
	// Should be in two columns of angle [Degrees, smallest to largest] vs Energy [MeV]. 
	ifstream expected_kinematics_file("582keV_kinematic_line.txt");

	// STEP 3:
    //--------
    // Draw a TCutG gate around the data in the file provided in step 1
    // that corresponds to the state you are trying to match to the kinematics line provided 
    // in step 2.
	TCutG* kin_gate_1 = new TCutG("kin_gate_1", 17);
	kin_gate_1->SetPoint(0,-0.0171558,10.2165);
	kin_gate_1->SetPoint(1,-0.0145652,8.59307);
	kin_gate_1->SetPoint(2,0.107192,7.24026);
	kin_gate_1->SetPoint(3,0.285942,6.04978);
	kin_gate_1->SetPoint(4,0.526866,4.75108);
	kin_gate_1->SetPoint(5,0.741884,3.99351);
	kin_gate_1->SetPoint(6,0.907681,3.56061);
	kin_gate_1->SetPoint(7,0.99317,3.45238);
	kin_gate_1->SetPoint(8,0.985399,4.53463);
	kin_gate_1->SetPoint(9,0.874004,4.53463);
	kin_gate_1->SetPoint(10,0.690072,5.12987);
	kin_gate_1->SetPoint(11,0.545,5.88745);
	kin_gate_1->SetPoint(12,0.392156,6.9697);
	kin_gate_1->SetPoint(13,0.23413,7.88961);
	kin_gate_1->SetPoint(14,0.0735145,9.45887);
	kin_gate_1->SetPoint(15,-0.00679349,10.1623);
	kin_gate_1->SetPoint(16,-0.0171558,10.2165);


	//Performing the minimization
	std::vector<double> myvec = looper(kin_gate_1, data, expected_kinematics_file);

	double loop1_diff = myvec[0];
	double optimized_z = myvec[1];
	double optimized_r = myvec[2];
	
	cout << "Complete!" << endl;
	cout << endl;
	cout << " The optimized geometry of the SX3 detector, in terms of its" << endl;
	cout << " radius from the beam axis and the z offset from the target." << endl;
	cout << " Z offset:   " << optimized_z << " mm" << endl;
	cout << " Radius:     " << optimized_r << " mm" << endl;
	cout << "" << endl;


    return;

}