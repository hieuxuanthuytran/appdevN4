#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(void){
	//Row and Col value are sent to URL as a HTTP POST string 
	Position cur = getscreensize();
	char poststr[100];
	sprintf(poststr, "row=%d&col=%d", cur.row, cur.col);
	senddata(poststr, URL);
	gotoXY(1,1);
	clearscreen();
	printf("Screen size, ROW-%d, COL-%d\n", cur.row, cur.col);
	printf("HTTP post is sent to %s\n", URL);
	getchar();   //waiting for the user to press a key
	getchar();
	
	
	/*for(int i=0; i<cur.row; i++){
		setcolors(GREEN, BLACK);
		float step = (float)cur.col/cur.row;
		gotoXY(i+1, step*i+1);
		drawobject(4,5);
		printf("\n");	
	//	setcolors(RED, BLACK);
	//	gotoXY(25-i, 1.6*i+1);
	//	printf("HELLO\n");
		usleep(500000);
	}*/


/*	for(int i=1; i<=25; i++){
		setcolors(RED, BLACK);
		clearscreen();
		gotoXY(25-i,1.6*i+1);
		printf("HELLO\n");
		usleep(500000);		
	}

	for(int i=20; i>0; i--){
		setcolors(RED, GREEN);
		clearscreen();
		gotoXY(20, 4*i);
		printf("HELLO\n");
		usleep(500000);
	}
*/
/*	for(int i=25; i>0; i--){
		setcolors(GREEN, BLACK);
		clearscreen();
		gotoXY(i,80-1.6*i);
		drawobject(4,5);
		printf("\n");
		setcolors(RED, BLACK);
		gotoXY(25-i+1,80-1.6*i);
		printf("HELLO\n");
		usleep(500000);
	}
*/

	//printf("the following message will be in RED color\n");
/*	gotoXY(14, 35);
	setfgcolor(MAGENTA);
	printf("E2000127\n");
	getchar();
	drawbar(30, 30);
	drawbar(50, 30);
*/
	getchar();
	resetcolors();
	clearscreen();
	//printf("This line is back to default color\n");
	FILE *fp;
	fp = fopen("test.wav", "r");
	WAVheader h = readwavhdr(fp);
	displayWAVhdr(h);
	getchar();
	clearscreen();
	getchar();
	wavdata(h, fp);	// to calculate dB values and display them as a barchart
	fclose(fp);
}
