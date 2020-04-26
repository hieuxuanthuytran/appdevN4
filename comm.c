#include <stdio.h>
#include <i386-linux-gnu/curl/curl.h>
#include "comm.h"

//this module contains all the functions for client-server
//communications, we only use libcurl functions.
//In order to link to libcurl functions, you need to put "-lcurl"
//in linking command.

void senddata(char *postdata, char *url){
	CURL *curl;
	CURLcode res;
	
	/* In windows,this will init the winsock stuff */ 
	curl_global_init(CURL_GLOBAL_ALL);
	
	/* get a curl handle */
	curl = curl_easy_init();
	if(curl){
		/* First set the URL that is about to receive our POST. This URL can
		just as well be a https:// URL if that is what should receive the 
		data. */
		curl_easy_setopt(curl, CURLOPT_URL, url);
		/* Now specify the POST data */
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postdata);

		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if(res != CURLE_OK){
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res));
		}
		
		/* always cleanup */
		curl_easy_cleanup(curl);
	} //end of if
	curl_global_cleanup();
}
