# --------------Appdev Development Project 2020-------------

# This project is for I-IT-1N students to understand what procedure and what tools are needed in an application development.

General Description of the Application

	This application will be comprised of many parts, related to the knowledge and tasks assigned during the course.
	Currently, the application is shown in the following specific parts:
	
		1: Print my ID with the colour. Ex: Green.
		2: Animate two objects on the zigzag path. (25 rows x 80 columns)
		3: Measure the number of row and column, then animate 1 object on that values.
		4: Row and Col values are sent to URL as a HTTP POST string.
		5: Generate 100 random numbers between 0 and 99 and displays them in a 10x10 matrix on the screen.
		6: Open a sound file (.wav), read it, calculate dB values, and display them as a bar chart.
		7: Complete wavdata() function with comm.c module so that it will count the number of peaks, 
		and also maximum decibel value and send both data as a HTTP POST string to a PHP program, 
		which records the information with a time stamp in a file.
	
		… to be continued!

Table of contents:

	1. Configuration instructions.
	2. Installation instructions.
	3. Operating instructions.
	4. File manifest.
	5. Copyright and licensing information.
	6. Contact information.
	7. Credits and acknowledgements.
	
#1. Configuration instructions.

	At first, you need the following two software tools available on your computer: 
	* (a)Text Editor: It will be used to display the source codes of this program. Ex: Windows Notepad, OS Edit command, Brief, Epsilon, EMACS, and vim or vi.
	* (b)The C Compiler: The compiler compiles the source codes into final executable programs. The most frequently used and free available compiler is the GNU C/C++ compiler.
	* (c)Git: is a free and open-source distributed version control system designed to handle everything from small to very large projects with speed and efficiency.

#2. Installation instructions.

To set up the environment for C programming language:
* Installation on UNIX/Linux: If you are using Linux or UNIX, then check whether GCC is installed on your system by entering the following command from the command line −
		$ gcc -v
+ If you have GNU compiler installed on your machine, then it should print a message as follows −
		Using built-in specs.
		Target: i386-redhat-linux
		Configured with: ../configure --prefix=/usr .......
		Thread model: posix
		gcc version 4.1.2 20080704 (Red Hat 4.1.2-46)
+ If GCC is not installed, then you will have to install it yourself using the detailed instructions available at https://gcc.gnu.org/install/
* Installation on Mac OS: If you use Mac OS X, the easiest way to obtain GCC is to download the Xcode development environment.
Xcode is currently available at developer.apple.com/technologies/tools/.
Installation on Windows: To install GCC on Windows, you need to install MinGW at www.mingw.org.
While installing Min GW, at a minimum, you must install gcc-core, gcc-g++, binutils, and the MinGW runtime, but you may wish to install more.

* Git-Repository-Download:
Use Git or checkout with SVN using the web URL.
	- GIT Installation: https://git-scm.com/book/en/v2/Getting-Started-Installing-Git
		+ A step by step guide to GIT: https://opensource.com/article/18/1/step-step-guide-git
	- My Git Repository: https://github.com/hieuxuanthuytran/appdevN4

#3. Operating instructions.

In Linux: 
	* Step 1. Open up a terminal.
	* Step 2. Compile the program. 
	Type the command: 
		+ cd appdevN4 -> ls -> make clean -> make -> ./program
+ https://www.w3resource.com/c-programming/compile-and-execute-c-program-in-linux-and-windows.php
+ https://www.geeksforgeeks.org/compiling-a-c-program-behind-the-scenes/

#4. File manifest.
	
* README.md:	this file.
* screen.c :	defines a number of functions for screen manipulation. These functions include erase screen, set color attributes, set cursor location, etc.. using VT100 escape sequences. http://www.termsys.demon.co.uk/vtansi.htm
* screen.h :	has 2 parts that function declarations (the information of cursor position) and constants definitions (colors, bars, …).
* comm.c :	this module contains all the functions for client-server communications (only use libcurl functions). 
* comm.h :	has 2 parts that function declarations and constants definitions.
* makefile :	the makefile tells make how to compile and link a program.
* testcurl.c :	contains all functions as comm.c but it has the specific data that need to transfer.
* Sound.c :	In this function, we will read sound samples from the opened file the samples are calculated into decibel value using Root Mean Square(RMS) formula. 
* Sound.h :	In this file, we define related constants and declare functions for handling sound.
* Main.c :	This module is the main function. It includes 6 parts:
	+ Part 1: Print my ID with the color. Ex: Green.
	+ Part 2: Animate two objects on the zigzag path. (25 rows x 80 columns)
	+ Part 3: Measure the number of row and column, then animate 1 object on that values.
	+ Part 4: Row and Col values are sent to URL as an HTTP POST string.
	+ Part 5: Generate 100 random numbers between 0 and 99 and displays them in a 10x10 matrix on the screen.
	+ Part 6: Open a sound file (.wav), read it, calculate dB values, and display them as a bar chart.
* Raspsound.php :	when you send data as an HTTP POST string to a PHP program, which records the information with a timestamp in this file.

#5. Copyright and licensing information.

	* This application follows the GPLv2 license.
	
#6. Contact information.

	* My name: Hieu Xuan Thuy Tran
	* My email address: tranhieuxuanthuy@gmail.com
	
#7. Credits and acknowledgments.

	Finally, I would like to thank Mr. Chao Gao for his supports as well as the knowledge he taught and especially his patience with his students throughout the course.
