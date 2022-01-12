# Analysis scripts and their purpose

list the codes and their functions here


## Analysis Shell
To start analyzing data straight-off-the-bat, the two files you need to use/adjust are analysis_shell.cxx and analysis_functions.cxx
analysis_functions.cxx is a file full of useful functions such as calculating the 3D hit position of the 
ejectile, or the energy loss of a proton through Silicon etc.

analysis_shell.cxx loads the merged runs (ie, the _combined.root files), calibrates and performs operations on the data event-by-event, 
filling useful histograms such as the kinematics, excitation spectra, particle-gamma matrices etc.

NOTE: when adjusting this to use your own data, you will need to remember a few things:
1) You need to use different calibration parameters. These can be adjusted in the cal/cal_params directory.
	- There are a few useful programs in the root directory that can do some automated calibration (documentation to come)
2) You need to change the directory of the data files being pulled to wherever you keep them.






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
