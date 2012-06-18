#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int GetFileLineCount(char *filename){
	FILE *fin;
	fin = fopen(filename,"r");
	int linecount =1;
	char c;
	while((c = fgetc(fin)) != EOF){
		if (c == '\n'){
			linecount++;
		}
	}
	if(fgets(fin)=='\n' || getline(fin)==-1)
		linecount--;
	fclose(fin);
	return linecount;
}

int main(int argc, char *argv[]){
	FILE *fin = fopen("data.csv","r");
	GetFileLineCount(fin);
	return 0;
}