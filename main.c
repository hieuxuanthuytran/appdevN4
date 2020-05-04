#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>		// for rand() function.
#include <time.h> 		// for time() function.
#include "screen.h"
#include "comm.h"
#include "sound.h"

/* This module is main function. It includes 6 parts:
	Part 1: Print my ID with the color. Ex: Green.
	Part 2: Animate two objects on the zigzag path. (25 rows x 80 columns)
	Part 3: Measure the number of row and column, then animate 1 object on that values.
	Part 4: Row and Col value are sent to URL as a HTTP POST string.
	Part 5: Generate 100 random numbers between 0 and 99 and displays them in a 10x10 matrix on the screen.
	Part 6: Open a sound file (.wav), read it, calculate dB values and display them as a barchart.
 */

int main(void){
	
	/* Part 1 */
	
	printf("\nThe following line will be green color\n");
	getchar();
	clearscreen();
	gotoXY(14, 35);
	setfgcolor(GREEN);
	printf("E2000127\n"); 
	getchar();
	drawbar(30, 35);
	drawbar(50, 35);
	getchar();
	resetcolors();
	clearscreen();
	printf("\nThis line is back to default color\n");
	
	/* Part 2 */
	
	for(int i=0; i<=25; i++){
		setcolors(GREEN, BLACK);
		clearscreen();
		gotoXY(i+1, 1.6*i-1);
		drawobject(4,5);
		printf("\n");	
		setcolors(RED, BLACK);
		gotoXY(25-i,1.6*i-1);
		printf("HELLO\n");
		usleep(500000);		
	}

	for(int i=25; i>0; i--){
		setcolors(GREEN, BLACK);
		clearscreen();
		gotoXY(i,80-1.6*i);
		drawobject(4,5);
		printf("\n");
		setcolors(RED, BLACK);
		gotoXY(25-i+1,80-1.6*i);
		printf("HELLO\n");
		usleep(500000);
		clearscreen();
	}

	/* Part 3 */
		
	Position cur = getscreensize();
	for(int i=0; i<cur.row; i++){
		setcolors(GREEN, BLACK);
		clearscreen();
		float step = (float)cur.col/cur.row;
		gotoXY(i+1, step*i+1);
		drawobject(4,5);
		printf("\n");	
		usleep(500000);
	}

	/* Part 4 */
	
	char poststr[100];
	sprintf(poststr, "row=%d&col=%d", cur.row, cur.col);
	senddata(poststr, URL);
	gotoXY(1,1);
	clearscreen();
	printf("Screen size, ROW-%d, COL-%d\n", cur.row, cur.col);
	printf("HTTP post is sent to %s\n", URL);
	getchar();   			//waiting for the user to press a key
	getchar(); 
	
	/* Part 5 */
	
/*	rand() function is intiated by SEED (constant number), if we don't change it, 
	everytime rand() will produce the same sequence of random numbers.
	In order to get "real" randomization, you need to change the SEED.
	Usually, you can use current system time to change the SEED. */
	
	int a;
	printf("RAND_MAX = %d\n", RAND_MAX);
	printf("This is 100 random numbers:\n\n");
	srand(time(NULL));		// change the SEED by current time in second.

	for(int i=0; i<100; i++)
	{
		a = rand()%100;
		if(a<10)
			setfgcolor(RED);	// the number is less than 10, display that num in RED
		else if(i%2==0)
			setfgcolor(GREEN);	// display col 1, 3, 5, 7, 9 in GREEN
		else
			setfgcolor(CYAN);	// others col in CYAN
		printf("%4d",a);		// radom 100 numbers.
		if((i+1)%10==0)			// due to (i+1) start from 0 | to check value i, if we have printed 10 numbers in one line. 
		{
			printf("\n");
		}
	}
	printf("\n");
	getchar(); 
	
	/* Part 6 */	

	FILE *fp;
	fp = fopen("test.wav", "r");
	WAVheader h = readwavhdr(fp);
	displayWAVhdr(h);
	getchar();
	clearscreen();
	getchar();
	wavdata(h, fp);			// to calculate dB values and display them as a barchart
	fclose(fp);
}
