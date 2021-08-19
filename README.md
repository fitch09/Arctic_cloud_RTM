# PROJECT TITLE: Monte Carlo Numerical Simulations for the use of Multidirectional Oxygen A-band Measurements in Estimating Cloud Top Height and Cloud Geometric Thickness for Arctic Mixed-Phase Clouds 

Principle Investigator:	Lt Col Kyle Fitch, Air Force Istitute of Technology

Intern:	Chance Starr, University at Buffalo

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

Open a terminal on your computer inside the github directory folder that you clone'd in above, and type the following lines in, clicking enter after each, in the order listed below:

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





