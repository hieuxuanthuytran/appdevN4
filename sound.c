#include <stdio.h>
#include <math.h>
#include "sound.h"
#include "screen.h"
#include "comm.h"

WAVheader readwavhdr(FILE *fp){
	WAVheader myh;
	fread(&myh, sizeof(myh), 1, fp);
	return myh;
}

void displayWAVhdr(WAVheader h){
	printf("Chunk ID: ");
	for(int i=0; i<4; i++) printf("%c", h.chunkID[i]);
	printf("\n");
	printf("Chunk size: %d\n", h.chunkSize);
	printf("Num of Channels: %d\n", h.numChannels);
	printf("Sample rate: %d\n", h.sampleRate);
	printf("Block align: %d\n", h.blockAlign);
	printf("Bits per sample: %d\n", h.bitsPerSample);
	// ... to be continued

}

/*	In this function we will read sound samples from the opened file
	the samples are calculated in to decibel value using Root Mean Square
	(RMS) formula. We will display a 5-sec recorded sound into bar chart
	our sound file uses sample rate of 16000, for 5 seconds, there are
	5*16000 = 800000 samples, we want to display them into 160 bars */

void wavdata(WAVheader h, FILE *fp){
	
	short samples[500];		// to read 500 samples from wav file
	int peaks=0, flag=0; 
	float dBValueMax=0;
	Position p;
	for(int i=0; i<160; i++){
		fread(samples, sizeof(samples), 1, fp);
		double sum = 0.0;	// accumulate the sum
		for(int j=0; j<500; j++){
			sum = sum + samples[j]*samples[j];
		}
		double re = sqrt(sum/500);
		
#ifdef SDEBUG

	printf("db[%d] = %f\n", i+1, 20*log10(re));

#else
		// display bar for re value
	
	double dBValue = 20*log10(re);
		if(dBValueMax<dBValue){
			dBValueMax = dBValue;
		}
		else{
			dBValueMax = dBValueMax;
		}
		if(dBValue>60){
			if(dBValue>70){		
				setfgcolor(RED);
			}
			if(flag == 0){
				flag = 1;
				peaks++;
			}
		}
		else{ 
		setfgcolor(WHITE);
		flag =0;
		}
		drawbar(i+1, (int)20*log10(re)/3);
			
#endif

	}
	
	gotoXY(1,1); printf("Sample Rate: %d\n", h.sampleRate);
	gotoXY(1,75); printf("Duration: %f s\n", (float)h.subchunk2Size/h.byteRate);
	gotoXY(1,150); printf("Peaks: %d\n", peaks);
	getchar();
	gotoXY(2, 75); printf("The maximum dB Value: %f\n", dBValueMax);

	char poststr[100];

	/* The number of peaks and maximum decibel value are sent to URL as a HTTP POST string */
	
	sprintf(poststr, "peaks=%d&dBValueMax=%f", peaks, dBValueMax);
	senddata(poststr, URL);
	gotoXY(3,1);
	printf("HTTP post is sent to %s\n", URL);
	getchar();
}

//end of file
