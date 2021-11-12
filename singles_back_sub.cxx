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

Double_t gaus_x5 ( Double_t *x, Double_t *par )
{
    return (par[0] * TMath::Exp ( -0.5 * ( pow ( x[0] - (par[1]), 2 ) / pow ( par[2], 2 ) ) ) )
    + (par[3] * TMath::Exp ( -0.5 * ( pow ( x[0] - (par[4]), 2 ) / pow ( par[5], 2 ) ) ) )
    + (par[6] * TMath::Exp ( -0.5 * ( pow ( x[0] - (par[7]), 2 ) / pow ( par[8], 2 ) ) ) )
    + (par[9] * TMath::Exp ( -0.5 * ( pow ( x[0] - (par[10]), 2 ) / pow ( par[11], 2 ) ) ) )
    + (par[12] * TMath::Exp ( -0.5 * ( pow ( x[0] - (par[13]), 2 ) / pow ( par[14], 2 ) ) ) );
}


void singles_back_sub()
{

    TFile *CD2_file = new TFile("analysis_output/CD2_prelim_analysis.root");
    TH1D * CD2_excitation = (TH1D*)CD2_file->Get("Excitation_spec_eloss_corrected");


    TFile *CH2_file = new TFile("analysis_output/CH2_prelim_analysis.root");
    TH1D * CH2_excitation = (TH1D*)CH2_file->Get("Excitation_spec_eloss_corrected");


    // Calculating normalization parameter 
    // ===================================


    //Getting the range to integrate below 0 excitation
    double CD2_integral = CD2_excitation->Integral(0,CD2_excitation->GetXaxis()->FindBin(-1000.));
    double CH2_integral = CH2_excitation->Integral(0,CH2_excitation->GetXaxis()->FindBin(-1000.));


    cout << CD2_integral << "   " << CH2_integral << endl;

    cout << "Scale factor:  " << CD2_integral / CH2_integral << endl;

    CH2_excitation->Scale(CD2_integral / CH2_integral);


    TH1D* background_subtracted = (TH1D*) CD2_excitation->Clone();



    background_subtracted->Reset("ICESM");


    for(int i=0; i<background_subtracted->GetNbinsX(); i++)
    {
        background_subtracted->SetBinContent(i,CD2_excitation->GetBinContent(i) - CH2_excitation->GetBinContent(i));
        background_subtracted->SetBinError(i, sqrt( pow(CD2_excitation->GetBinError(i),2) + pow(CH2_excitation->GetBinError(i),2) ));
    }


    background_subtracted->Scale(1.0);



    CD2_excitation->Rebin(4);
    CH2_excitation->Rebin(4);
    background_subtracted->Rebin(4);

    TF1 *FullFit = new TF1("FullFit", "gaus_x5", 0, 2700, 15);
    // 580 keV doublet
    FullFit->SetParameter(0, 1760);
    FullFit->FixParameter(1, 580);
    FullFit->FixParameter(2, 130);

    // 3/2+ @ 1100 keV
    FullFit->SetParameter(3, 280);
    FullFit->FixParameter(4, 1100);
    FullFit->FixParameter(5, 130);

    // 5/2+ @ 1331 keV
    FullFit->SetParameter(6, 200);
    FullFit->FixParameter(7, 1331);
    FullFit->FixParameter(8, 130);

    // 5/2+ @ 1665 keV
    FullFit->SetParameter(9, 160);
    FullFit->FixParameter(10, 1665);
    FullFit->FixParameter(11, 130);

    // Whole bunch o' stuff @ 2550 keV?
    FullFit->SetParameter(12, 1520);
    FullFit->SetParameter(13, 2500);
    FullFit->SetParameter(14, 130);

    background_subtracted->Fit("FullFit", "r");

    TF1 *fit_580 = new TF1("fit_580", "gaus(0)", FullFit->GetParameter(1)-500, FullFit->GetParameter(1)+500);
    fit_580->FixParameter(0,FullFit->GetParameter(0));
    fit_580->FixParameter(1,FullFit->GetParameter(1));
    fit_580->FixParameter(2,FullFit->GetParameter(2));
    fit_580->SetLineColor(kBlue);



    TF1 *fit_1100 = new TF1("fit_1100", "gaus(0)", FullFit->GetParameter(4)-500, FullFit->GetParameter(4)+500);
    fit_1100->FixParameter(0,FullFit->GetParameter(3));
    fit_1100->FixParameter(1,FullFit->GetParameter(4));
    fit_1100->FixParameter(2,FullFit->GetParameter(5));
    fit_1100->SetLineColor(kGreen);
 


    TF1 *fit_1331 = new TF1("fit_1331", "gaus(0)", FullFit->GetParameter(7)-500, FullFit->GetParameter(7)+500);
    fit_1331->FixParameter(0,FullFit->GetParameter(6));
    fit_1331->FixParameter(1,FullFit->GetParameter(7));
    fit_1331->FixParameter(2,FullFit->GetParameter(8));
    fit_1331->SetLineColor(kMagenta);


    TF1 *fit_1665 = new TF1("fit_1665", "gaus(0)", FullFit->GetParameter(10)-500, FullFit->GetParameter(10)+500);
    fit_1665->FixParameter(0,FullFit->GetParameter(9));
    fit_1665->FixParameter(1,FullFit->GetParameter(10));
    fit_1665->FixParameter(2,FullFit->GetParameter(11));
    fit_1665->SetLineColor(kCyan);


    TF1 *fit_2550 = new TF1("fit_2550", "gaus(0)", FullFit->GetParameter(13)-500, FullFit->GetParameter(13)+500);
    fit_2550->FixParameter(0,FullFit->GetParameter(12));
    fit_2550->FixParameter(1,FullFit->GetParameter(13));
    fit_2550->FixParameter(2,FullFit->GetParameter(14));
    fit_2550->SetLineColor(kRed);


    FullFit->SetLineStyle(10);
    FullFit->SetLineColor(kBlack);








    TCanvas* c1 = new TCanvas("c1", "c1", 400, 400);
    TCanvas* c2 = new TCanvas("c2", "c2", 400, 400);

    c1->cd();
    CD2_excitation->Draw();
    CH2_excitation->Draw("SAME");

    c2->cd();
    background_subtracted->Draw();
    fit_580->Draw("SAME");
    fit_1100->Draw("SAME");
    fit_1331->Draw("SAME");
    fit_1665->Draw("SAME");
    fit_2550->Draw("SAME");



    return;
}