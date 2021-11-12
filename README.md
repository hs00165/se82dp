# Analysis scripts and their purpose

list the codes and their functions here

## To analyze angular distributions:
0) Edit angular_distribution_config.dat to your choosing

1) Run angular_distribution_generator.cxx in CD2 mode and then in CH2 mode
	(remember to switch the output file to "[CH2_]angular_distribution_histograms.cxx" as well as the input files)
	This generates the excitation spectra for each angular bin
	

2) Run solid_angle_calculator.cxx
	This uses the config file to calculate the solid angle of each bin
	NOTE: the loss of solid angle due to shadowing from the target ladder is accounted for!
	this generates a file: angular_distribution_solid_angles.dat

3) Run angular_distribution_analyzer_500keV.dat / angular_distribution_analyzer_2500keV.dat
	This uses the two .dat files generated in stes 1 and 2 and the angular-excitation spectra 		to calculate the absolute differential cross section, and deduce spectroscopic factors
