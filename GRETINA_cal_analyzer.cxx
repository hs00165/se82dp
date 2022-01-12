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





void GRETINA_cal_analyzer()
{


	// First read in each of the peak files from
	//  cal/GRETINA_cal/*.dat

	// The write to array the info from the files FOR EACH CRYSTAL

	// ie:
	// peakParameters[crystalNum][parameterNumber]
	// where parameter number represents:
	// 0) known peak energy [keV]
	// 1) peak amplitude
	// 2) peak centroid
	// 3) peak std dev
	// 4) peak asymmetry factor
	// 5) peak amplitude ERROR
	// 6) peak centroid ERROR
	// 7) peak std dev ERROR
	// 8) peak asymmetry factor ERROR


	vector<double> peakParameters[100][10];


	string line;
	int temp_crystalNum;
	double temp_double_0, temp_double_1, temp_double_2, temp_double_3, temp_double_4;
	double temp_double_5, temp_double_6, temp_double_7, temp_double_8;


    //=====================READING IN THE Y88 FILE=========================
    ifstream Y88_file ( "cal/GRETINA_cal/Y88_peaks.dat" );
    while ( getline ( Y88_file,line ) )
    {
        istringstream in ( line );

        in >> temp_crystalNum >> temp_double_0 >> temp_double_1 >> temp_double_2 >> temp_double_3 >> temp_double_4 >> temp_double_5 >> temp_double_6 >> temp_double_7 >> temp_double_8;

        peakParameters[temp_crystalNum][0].push_back(temp_double_0);
        peakParameters[temp_crystalNum][1].push_back(temp_double_1);
        peakParameters[temp_crystalNum][2].push_back(temp_double_2);
        peakParameters[temp_crystalNum][3].push_back(temp_double_3);
        peakParameters[temp_crystalNum][4].push_back(temp_double_4);
        peakParameters[temp_crystalNum][5].push_back(temp_double_5);
        peakParameters[temp_crystalNum][6].push_back(temp_double_6);
        peakParameters[temp_crystalNum][7].push_back(temp_double_7);
        peakParameters[temp_crystalNum][8].push_back(temp_double_8);
    }
    Y88_file.close();

    //=====================READING IN THE Eu152 FILE=========================
    ifstream Eu152_file ( "cal/GRETINA_cal/Eu152_peaks.dat" );
    while ( getline ( Eu152_file,line ) )
    {
        istringstream in ( line );

        in >> temp_crystalNum >> temp_double_0 >> temp_double_1 >> temp_double_2 >> temp_double_3 >> temp_double_4 >> temp_double_5 >> temp_double_6 >> temp_double_7 >> temp_double_8;

        peakParameters[temp_crystalNum][0].push_back(temp_double_0);
        peakParameters[temp_crystalNum][1].push_back(temp_double_1);
        peakParameters[temp_crystalNum][2].push_back(temp_double_2);
        peakParameters[temp_crystalNum][3].push_back(temp_double_3);
        peakParameters[temp_crystalNum][4].push_back(temp_double_4);
        peakParameters[temp_crystalNum][5].push_back(temp_double_5);
        peakParameters[temp_crystalNum][6].push_back(temp_double_6);
        peakParameters[temp_crystalNum][7].push_back(temp_double_7);
        peakParameters[temp_crystalNum][8].push_back(temp_double_8);
    }
    Eu152_file.close();

    //=====================READING IN THE Ta182 FILE=========================
    ifstream Ta182_file ( "cal/GRETINA_cal/Ta182_peaks.dat" );
    while ( getline ( Ta182_file,line ) )
    {
        istringstream in ( line );

        in >> temp_crystalNum >> temp_double_0 >> temp_double_1 >> temp_double_2 >> temp_double_3 >> temp_double_4 >> temp_double_5 >> temp_double_6 >> temp_double_7 >> temp_double_8;

        peakParameters[temp_crystalNum][0].push_back(temp_double_0);
        peakParameters[temp_crystalNum][1].push_back(temp_double_1);
        peakParameters[temp_crystalNum][2].push_back(temp_double_2);
        peakParameters[temp_crystalNum][3].push_back(temp_double_3);
        peakParameters[temp_crystalNum][4].push_back(temp_double_4);
        peakParameters[temp_crystalNum][5].push_back(temp_double_5);
        peakParameters[temp_crystalNum][6].push_back(temp_double_6);
        peakParameters[temp_crystalNum][7].push_back(temp_double_7);
        peakParameters[temp_crystalNum][8].push_back(temp_double_8);
    }
    Ta182_file.close();

    //=====================READING IN THE Co56 FILE=========================
    ifstream Co56_file ( "cal/GRETINA_cal/Co56_peaks.dat" );
    while ( getline ( Co56_file,line ) )
    {
        istringstream in ( line );

        in >> temp_crystalNum >> temp_double_0 >> temp_double_1 >> temp_double_2 >> temp_double_3 >> temp_double_4 >> temp_double_5 >> temp_double_6 >> temp_double_7 >> temp_double_8;

        peakParameters[temp_crystalNum][0].push_back(temp_double_0);
        peakParameters[temp_crystalNum][1].push_back(temp_double_1);
        peakParameters[temp_crystalNum][2].push_back(temp_double_2);
        peakParameters[temp_crystalNum][3].push_back(temp_double_3);
        peakParameters[temp_crystalNum][4].push_back(temp_double_4);
        peakParameters[temp_crystalNum][5].push_back(temp_double_5);
        peakParameters[temp_crystalNum][6].push_back(temp_double_6);
        peakParameters[temp_crystalNum][7].push_back(temp_double_7);
        peakParameters[temp_crystalNum][8].push_back(temp_double_8);
    }
    Co56_file.close();

    //=====================READING IN THE Co60 FILE=========================
    ifstream Co60_file ( "cal/GRETINA_cal/Co60_peaks.dat" );
    while ( getline ( Co60_file,line ) )
    {
        istringstream in ( line );

        in >> temp_crystalNum >> temp_double_0 >> temp_double_1 >> temp_double_2 >> temp_double_3 >> temp_double_4 >> temp_double_5 >> temp_double_6 >> temp_double_7 >> temp_double_8;

        peakParameters[temp_crystalNum][0].push_back(temp_double_0);
        peakParameters[temp_crystalNum][1].push_back(temp_double_1);
        peakParameters[temp_crystalNum][2].push_back(temp_double_2);
        peakParameters[temp_crystalNum][3].push_back(temp_double_3);
        peakParameters[temp_crystalNum][4].push_back(temp_double_4);
        peakParameters[temp_crystalNum][5].push_back(temp_double_5);
        peakParameters[temp_crystalNum][6].push_back(temp_double_6);
        peakParameters[temp_crystalNum][7].push_back(temp_double_7);
        peakParameters[temp_crystalNum][8].push_back(temp_double_8);
    }
    Co60_file.close();

    //=====================READING IN THE Am243 FILE=========================
    ifstream Am243_file ( "cal/GRETINA_cal/Am243_peaks.dat" );
    while ( getline ( Am243_file,line ) )
    {
        istringstream in ( line );

        in >> temp_crystalNum >> temp_double_0 >> temp_double_1 >> temp_double_2 >> temp_double_3 >> temp_double_4 >> temp_double_5 >> temp_double_6 >> temp_double_7 >> temp_double_8;

        peakParameters[temp_crystalNum][0].push_back(temp_double_0);
        peakParameters[temp_crystalNum][1].push_back(temp_double_1);
        peakParameters[temp_crystalNum][2].push_back(temp_double_2);
        peakParameters[temp_crystalNum][3].push_back(temp_double_3);
        peakParameters[temp_crystalNum][4].push_back(temp_double_4);
        peakParameters[temp_crystalNum][5].push_back(temp_double_5);
        peakParameters[temp_crystalNum][6].push_back(temp_double_6);
        peakParameters[temp_crystalNum][7].push_back(temp_double_7);
        peakParameters[temp_crystalNum][8].push_back(temp_double_8);
    }
    Am243_file.close();





    TFile write("cal/GRETINA_cal_graphs.root", "recreate");

    // Now loop over each crystal.
    // Within that loop, nest another,
    // looping over the energy peaks

    TGraphErrors* crystalEnergyResponse[100];
    TGraphErrors* crystalCalDivergence[100];




    for(int crystalNum=0; crystalNum<100; crystalNum++) {


        crystalEnergyResponse[crystalNum] = new TGraphErrors(peakParameters[crystalNum][0].size());
        crystalCalDivergence[crystalNum] = new TGraphErrors(peakParameters[crystalNum][0].size());


        for(int i=0; i<peakParameters[crystalNum][0].size(); i++) {


            crystalEnergyResponse[crystalNum]->SetPoint(i, peakParameters[crystalNum][2].at(i), peakParameters[crystalNum][0].at(i));
            crystalCalDivergence[crystalNum]->SetPoint(i, peakParameters[crystalNum][2].at(i), peakParameters[crystalNum][0].at(i)-peakParameters[crystalNum][2].at(i));


            crystalEnergyResponse[crystalNum]->SetPointError(i, peakParameters[crystalNum][6].at(i), 0);
            crystalCalDivergence[crystalNum]->SetPointError(i, peakParameters[crystalNum][6].at(i), peakParameters[crystalNum][6].at(i));

        }






        crystalEnergyResponse[crystalNum]->Write();
        crystalCalDivergence[crystalNum]->Write();
    }



    






	return;
}