#include <string>
#include <iostream>
#include <array>
#include <vector>

void test_script_chad()
{

    TFile *fin = new TFile("data/Run038_combined.root","READ");

    TTree *chain = (TTree*)fin->Get("data");
	// List of branches
	TBranch        *b_BB10Mul;   //!
	TBranch        *b_BB10Det;   //!
	TBranch        *b_BB10Strip;   //!
	TBranch        *b_BB10Channel;   //!
	TBranch        *b_BB10ADC;   //!
	TBranch        *b_BB10Energy;   //!
	TBranch        *b_QQQ5Mul;   //!
	TBranch        *b_QQQ5Upstream;   //!
	TBranch        *b_QQQ5Det;   //!
	TBranch        *b_QQQ5Ring;   //!
	TBranch        *b_QQQ5RingChannel;   //!
	TBranch        *b_QQQ5Sector;   //!
	TBranch        *b_QQQ5SectorChannel;   //!
	TBranch        *b_QQQ5RingADC;   //!
	TBranch        *b_QQQ5RingEnergy;   //!
	TBranch        *b_QQQ5SectorADC;   //!
	TBranch        *b_QQQ5SectorEnergy;   //!
	TBranch        *b_QQQ5Angle;   //!
	TBranch        *b_SX3Mul;   //!
	TBranch        *b_SX3Upstream;   //!
	TBranch        *b_SX3Det;   //!
	TBranch        *b_SX3Sector;   //!
	TBranch        *b_SX3SectorChannel;   //!
	TBranch        *b_SX3SectorADC;   //!
	TBranch        *b_SX3SectorEnergy;   //!
	TBranch        *b_SX3Strip;   //!
	TBranch        *b_SX3StripLeftChannel;   //!
	TBranch        *b_SX3StripRightChannel;   //!
	TBranch        *b_SX3StripLeftADC;   //!
	TBranch        *b_SX3StripRightADC;   //!
	TBranch        *b_SX3StripEnergy;   //!
	TBranch        *b_icdE;   //!
	TBranch        *b_icE;   //!
	TBranch        *b_icWireX;   //!
	TBranch        *b_icWireY;   //!
	TBranch        *b_icPositionX;   //!
	TBranch        *b_icPositionY;   //!
	TBranch        *b_icPositionWeightedX;   //!
	TBranch        *b_icPositionWeightedY;   //!
	TBranch        *b_tdcIC;   //!
	TBranch        *b_tdcGRETINA;   //!
	TBranch        *b_tdcRF;   //!
	TBranch        *b_tdcSilicon;   //!
	TBranch        *b_timeStamp;   //!
	TBranch			*b_GRETINATimeStamp;
	TBranch			*b_foundGRETINA;
	TBranch			*b_xtalsMul;
	TBranch			*b_xtals_xlab;
	TBranch			*b_xtals_ylab;
	TBranch			*b_xtals_zlab;
	TBranch			*b_xtals_cc;
	TBranch			*b_xtals_edop;
	TBranch			*b_xtals_edopMaxInt;
	TBranch			*b_xtals_edopSeg;
	TBranch			*b_xtals_edopXtal;
	TBranch			*b_xtals_crystalNum;
	TBranch			*b_xtals_quadNum;
	TBranch			*b_xtals_t0;
	TBranch			*b_xtals_timestamp;
	chain->SetBranchAddress("BB10Mul", &BB10Mul, &b_BB10Mul);
	chain->SetBranchAddress("BB10Det", BB10Det, &b_BB10Det);
	chain->SetBranchAddress("BB10Strip", BB10Strip, &b_BB10Strip);
	chain->SetBranchAddress("BB10Channel", BB10Channel, &b_BB10Channel);
	chain->SetBranchAddress("BB10ADC", BB10ADC, &b_BB10ADC);
	chain->SetBranchAddress("BB10Energy", BB10Energy, &b_BB10Energy);
	chain->SetBranchAddress("QQQ5Mul", &QQQ5Mul, &b_QQQ5Mul);
	chain->SetBranchAddress("QQQ5Upstream", QQQ5Upstream, &b_QQQ5Upstream);
	chain->SetBranchAddress("QQQ5Det", QQQ5Det, &b_QQQ5Det);
	chain->SetBranchAddress("QQQ5Ring", QQQ5Ring, &b_QQQ5Ring);
	chain->SetBranchAddress("QQQ5RingChannel", QQQ5RingChannel, &b_QQQ5RingChannel);
	chain->SetBranchAddress("QQQ5Sector", QQQ5Sector, &b_QQQ5Sector);
	chain->SetBranchAddress("QQQ5SectorChannel", QQQ5SectorChannel, &b_QQQ5SectorChannel);
	chain->SetBranchAddress("QQQ5RingADC", QQQ5RingADC, &b_QQQ5RingADC);
	chain->SetBranchAddress("QQQ5RingEnergy", QQQ5RingEnergy, &b_QQQ5RingEnergy);
	chain->SetBranchAddress("QQQ5SectorADC", QQQ5SectorADC, &b_QQQ5SectorADC);
	chain->SetBranchAddress("QQQ5SectorEnergy", QQQ5SectorEnergy, &b_QQQ5SectorEnergy);
	chain->SetBranchAddress("QQQ5Angle", QQQ5Angle, &b_QQQ5Angle);
	chain->SetBranchAddress("SX3Mul", &SX3Mul, &b_SX3Mul);
	chain->SetBranchAddress("SX3Upstream", SX3Upstream, &b_SX3Upstream);
	chain->SetBranchAddress("SX3Det", SX3Det, &b_SX3Det);
	chain->SetBranchAddress("SX3Sector", SX3Sector, &b_SX3Sector);
	chain->SetBranchAddress("SX3SectorChannel", SX3SectorChannel, &b_SX3SectorChannel);
	chain->SetBranchAddress("SX3SectorADC", SX3SectorADC, &b_SX3SectorADC);
	chain->SetBranchAddress("SX3SectorEnergy", SX3SectorEnergy, &b_SX3SectorEnergy);
	chain->SetBranchAddress("SX3Strip", SX3Strip, &b_SX3Strip);
	chain->SetBranchAddress("SX3StripLeftChannel", SX3StripLeftChannel, &b_SX3StripLeftChannel);
	chain->SetBranchAddress("SX3StripRightChannel", SX3StripRightChannel, &b_SX3StripRightChannel);
	chain->SetBranchAddress("SX3StripLeftADC", SX3StripLeftADC, &b_SX3StripLeftADC);
	chain->SetBranchAddress("SX3StripRightADC", SX3StripRightADC, &b_SX3StripRightADC);
	chain->SetBranchAddress("SX3StripEnergy", SX3StripEnergy, &b_SX3StripEnergy);
	chain->SetBranchAddress("icdE", &icdE, &b_icdE);
	chain->SetBranchAddress("icE", &icE, &b_icE);
	chain->SetBranchAddress("icWireX", &icWireX, &b_icWireX);
	chain->SetBranchAddress("icWireY", &icWireY, &b_icWireY);
	chain->SetBranchAddress("icPositionX", &icPositionX, &b_icPositionX);
	chain->SetBranchAddress("icPositionY", &icPositionY, &b_icPositionY);
	chain->SetBranchAddress("icPositionWeightedX", &icPositionWeightedX, &b_icPositionWeightedX);
	chain->SetBranchAddress("icPositionWeightedY", &icPositionWeightedY, &b_icPositionWeightedY);
	chain->SetBranchAddress("tdcIC", &tdcIC, &b_tdcIC);
	chain->SetBranchAddress("tdcGRETINA", &tdcGRETINA, &b_tdcGRETINA);
	chain->SetBranchAddress("tdcRF", &tdcRF, &b_tdcRF);
	chain->SetBranchAddress("tdcSilicon", &tdcSilicon, &b_tdcSilicon);
	chain->SetBranchAddress("timeStamp", &timeStamp, &b_timeStamp);
	chain->SetBranchAddress("GRETINATimeStamp", &GRETINATimeStamp, &b_GRETINATimeStamp);
	chain->SetBranchAddress("foundGRETINA", &foundGRETINA, &b_foundGRETINA);
	chain->SetBranchAddress("xtalsMul", &xtalsMul, &b_xtalsMul);
	chain->SetBranchAddress("xtals_xlab", &xtals_xlab, &b_xtals_xlab);
	chain->SetBranchAddress("xtals_ylab", &xtals_ylab, &b_xtals_ylab);
	chain->SetBranchAddress("xtals_zlab", &xtals_zlab, &b_xtals_zlab);
	chain->SetBranchAddress("xtals_cc", &xtals_cc, &b_xtals_cc);
	chain->SetBranchAddress("xtals_edop", &xtals_edop, &b_xtals_edop);
	chain->SetBranchAddress("xtals_edopMaxInt", &xtals_edopMaxInt, &b_xtals_edopMaxInt);
	chain->SetBranchAddress("xtals_edopSeg", &xtals_edopSeg, &b_xtals_edopSeg);
	chain->SetBranchAddress("xtals_edopXtal", &xtals_edopXtal, &b_xtals_edopXtal);
	chain->SetBranchAddress("xtals_crystalNum", &xtals_crystalNum, &b_xtals_crystalNum);
	chain->SetBranchAddress("xtals_quadNum", &xtals_quadNum, &b_xtals_quadNum);
	chain->SetBranchAddress("xtals_t0", &xtals_t0, &b_xtals_t0);
	chain->SetBranchAddress("xtals_timestamp", &xtals_timestamp, &b_xtals_timestamp);
    









	return;
}