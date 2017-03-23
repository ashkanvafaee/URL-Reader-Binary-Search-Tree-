#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "fileReader.h"

FILE* inputStream; 

void openFile(const char* fileName) {
    inputStream = fopen(fileName, "r");
    if(inputStream == 0) { 
        printf("Sorry, could not open %s.\n", fileName);
        exit(-1);
    }
}

void closeFile(void) { 
   fclose(inputStream);
}

void readURL(char* ptr) { 
    int sizeRead;
    sizeRead = fscanf(inputStream, "%s", ptr);
    if(sizeRead == EOF) { 
        *ptr = '\0';
    }
}
