# PROJECT TITLE: Monte Carlo Numerical Simulations for the use of Multidirectional Oxygen A-band Measurements in Estimating Cloud Top Height and Cloud Geometric Thickness for Arctic Mixed-Phase Clouds 

Principle Investigator:	Lt Col Kyle Fitch, Air Force Istitute of Technology

Intern:	Chance Starr, University at Buffalo

## This github has the following components:

Code - Downloadable files, see this README.md for how to use. https://github.com/fitch09/Arctic_cloud_RTM

README.md - A guide to downloading the files, pushing to this github, software neccessary to run and edit these files, a complete list of all files contained in the code section as well as what they do and how to use them. https://github.com/fitch09/Arctic_cloud_RTM/blob/main/README.md

Wiki - An article about the motivation and goals of this project, the methodology, as well as the current model specs with notes for what the final model will contain. https://github.com/fitch09/Arctic_cloud_RTM/wiki

Milestones - A list of stages that should be completed in order to keep track of the route we are taking to complete this project.  https://github.com/fitch09/Arctic_cloud_RTM/milestones

Issues - Current issues with the project that need to be fixed for the final publication.  Issues are tied into the stages and all have a stage number, see milestones to decide the order to work on each issue.  https://github.com/fitch09/Arctic_cloud_RTM/issues



# How to download and push this repository.
Please see this github's wiki page for a complete description of the project: https://github.com/fitch09/Arctic_cloud_RTM/wiki

## To Download Files

Open a terminal on your computer and type the following line in, and click enter:

git clone https://github.com/fitch09/Arctic_cloud_RTM.git

Now you have this github repository downloaded onto you computer!  If you see an error message, make sure you are hooked up to the internet.  This is not the only thing that can go wrong, but it is the most common!

Now, type the following command into the terminal, pressing enter after:

cd Arctic_cloud_RTM

Now you are inside the folder you just downloaded!  Type the following command to see all the folders you now have access to: ls

Now, you may go down to the 'Files Contained in this Repository and How to use them.' section of this read me which will tell you detailed instructions on how to run everything.

## To Push to this Github Repository

Open a terminal on your computer inside the github directory folder that you clone'd in above, and type the following lines in, clicking enter after each, in the order listed below to push to the main branch:

NOTE: The following three lines of code are ONLY recommended if you are adding completely new files, NOT editing existing ones!

git add *

git commit -m "SHORT MESSAGE, WILL APPEAR ON GITHUB"

git push origin main

NOTE: If you fear your push will break existing code, use the following commands instead to create a new branch:

git checkout -b NewBranchName

git add *

git commit -m "SHORT MESSAGE, WILL APPEAR ON GITHUB"

git push origin NewBranchName

# Software Necessary to run and edit these files.

## Software you need to install for main program
1) MCARaTS Version 10 (Very important, NOT Version 9.  At the time this code was written, Version 10.0.3 was used.) https://sites.google.com/site/mcarats/download
2) GrADS (At the time this code was written, Version 2.2.1 was used.) http://cola.gmu.edu/grads/downloads.php

## Software you need to install for phase function mie program to run
3) libradtran http://www.libradtran.org/doku.php?id=download
4) ifort (fortran installer) https://software.intel.com/content/www/us/en/develop/tools/oneapi/components/fortran-compiler.html#gs.9cilhc

## Software necessary to edit these files
A terminal text editor is required to run these files.  I prefer emacs myself: https://www.gnu.org/software/emacs/download.html

### To edit a file type the following command:

emacs FILENAME

Example: emacs WaterV2.conf

### To create a new blank file in emacs:

emacs NEWFILENAME_ThatDoesntExist_rememberToAddFileExtention

Example: emacs HellowWorld.txt

File Extensions are endless, for mcarats files use .conf for main program after your file name, for text files use .txt, etc.

### Basic Emacs Commands:

Save: Ctrl + x followed by Ctrl + s

Exit: Ctrl + x followed by Ctrl + c

# Files Contained in this Repository and How to use them.

## Mcarats Folder



## Phase Function Folder

The program mie.inp is the first step to generating the phase functions.  Take all the files contained in this folder and located where you installed libradtran.  Place all these files in the folder libRadtran-2.0.4/bin.  This will make running them possible.  If duplicate files exist, rewrite it with the one in this github.

### To run and set up for Mcarats software

emacs mie.inp

See where it says refrac, place either the word water or the word ice after it for each refractive index respectivly.  Where it says r_eff place the particle size you wish to use in micrometers directly after, file is preset to 10 micrometer particles.  You may also specify the wavelength, which is also preset in the contained file for the oxygen A-band wavelength of 763.

Save the mie.inp file and exit to return to the command line in the folder this file is contained in.  Run the following lines of code in order:

./mie < mie.inp > mie.out
./phase -c -d -s 0.1 mie.out > phase.dat

Now you have the phase functions for the water and ice clouds respectivly.  However, they contain an extra center column that should not be fed into Mcarats.  I have included two programs that will help get this file into the proper format, but the user is free to invent there own methods to do this.  Hand editing is not a real option however as each phase function contains 1801 entries.

The matlab file phase.m contains the following lines of code to edit out the middle column:
phase = readmatrix('phase.dat');
plot(phase(:,1),phase(:,3))
T = table(phase(:,1), phase(:,3))
writetable(T, 'phaseFunction.txt')

The C++ program FixPhaseFunctions.cpp takes the output file of the matlab program phaseFunction.txt and turns the commas into two spaces to be used in the Fortran language Mcarats software, outputing phaseFunction.sca, to match the example .sca file included with Mcarats.

To run the c++ program on the output of the matlab program, ensure they are in a folder together and run the following lines of code:

g++ FixPhaseFunction.cpp -o FixPhase.out
./FixPhase.out

Now you will have a file named phaseFunction.sca.  The final step is to place a few lines of code at the vary top of the file: 

emacs phaseFunction.sca

Place these lines of code at the top:
"
            
            %mdlphs
            # a comment line
            1801  # naa (# of angles)
            1801  # np (# of P data)
            # ang, phs for ipf=1
"
After this, save and close the file.  If you are putting mupltiple phase functions in the same file, place just this line in front of the second phase function: # ang, phs for ipf=2 and so forth.
