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



int run_adder()
{



	// Creating the Chain of runs to use
	TChain* Chain = new TChain ( "data" );




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


    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run085_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run086_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run087_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run088_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run089_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run090_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run091_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run092_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run093_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run094_combined.root");
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
























/*
    //================== CH2 Runs ====================
    //================================================
    
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run068_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run069_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run070_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run071_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run072_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run073_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run074_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run075_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run076_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run077_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run078_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run079_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run080_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run081_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run082_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run083_combined.root");
    Chain->Add("/mnt/se82dp_2/se82dp_sorted/Run084_combined.root");
    */





	return 0;
}
