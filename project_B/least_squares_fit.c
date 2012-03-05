/*

Project B: Parameters of a least squares fit

Takes data from a file / user input and calculates a least squares fit of them, returns equation in the form y = mx + c

this terrible source code available free for you to do whatever the hell with at http://github.com/joshp123 (idk why you would but whatever it was useful for version control)

*/

#include <stdio.h>
#include <math.h>
#include <string.h>

// Structure for the final result. returns m and c values and errors on both, i.e. y = mx + c 
typedef struct {
	float m;
	float merr;
	float c;
	float cerr;
}	graph;

// Structure for the input data - length, arrays of x, y, and y errors 

typedef struct{
	int length;
	double x[1000];
	double y[1000];
	double yerr[1000];
} dataset;

// Functions to flush to end of line

void flush(){  // LCC complier only plays nice when you use flush(void) instead of flush()  . GCC on the other hand does not. welp that's my cool compiler story for today
	while(getchar()!='\n'){}
}

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
	fclose(fin);
	return linecount;
}

/*
Function to read 3 columns of data in from a file.

Gets input from a .csv or .txt file formatted in the form:
x1, y1, yerr1
x2, y2, yerr2
x3, y3, yerr3

etc.

(This is how excel saves stuff in the .csv format, which is why this is actually useful.)

It returns data in the struct "output" as described above.

*/

dataset GetInput(char *filename, int verbose){
	FILE *fin;
	int i;
	dataset output;
	if(verbose == 1){
		printf("Opening %s\n",filename);
	}
	
	fin = fopen(filename, "r");

	if(fin==0){
		if(verbose == 1) {
			printf("Could not open file. Either you typed it wrong or it doesn't exist!\n");
		}
		return;
	}

	// file open routine complete, get linecount

	output.length = GetFileLineCount(filename);
	if (verbose ==1){
		printf("Counted %d lines. Reading in data\n",output.length);
	}

	// number of data points counted, now to read in the actual data (and create a couple of temporary arrays)

	float x[output.length],y[output.length],yerr[output.length];
	
	for (i = 0; i < output.length; ++i){
		int invalid = fscanf(fin, "%f,%f,%f", &x[i], &y[i], &yerr[i]);
		if(invalid !=3){
			printf("Error found on line number %d.\nThis is usually caused by non-numeric data detected in file or having more than 3 columns present. Please verify your data!\nNB: if the last line of your file is blank, \nProgram exiting.",i);
			return;
		}
		if (yerr[i] == 0){
			if (verbose == 1){
				printf("Your data contains errors that are equal to zero. This is invalid.\nProgram exiting.\n");
			}
			return;
		}
	}	 

	fclose(fin);

	// map temp stuff to actual output stuff to compensate for fscanf being hella gay

	for (int i = 0; i < output.length; ++i)
	{
		output.x[i] = x[i];
		output.y[i] = y[i];
		output.yerr[i] = yerr[i];
	}

	if (verbose == 1){
		printf("Your dataset has %d constituent points:\n\n",output.length);
		for (i = 0; i < output.length; ++i)
		{
			printf("x = %.4f\ty = %.4f\ty error = %.4f\n",output.x[i],output.y[i],output.yerr[i]);
		}
		printf("\n");
	}

	return output;
}

/*
Function to calculate the actual least squares parameters given a set of data
*/

graph LeastSquares(int length, double x[], double y[], double yerr[]){
	float p,q,r,s,t,delta,m; // p,q,r,s,t,delta as given in formulae; m = 1/e^2
	int i;
	graph result;
	m = 0;
	p = 0;
	q = 0;
	r = 0;
	s = 0;
	t = 0;
	delta = 0;
	for(i = 0; i<length; i++){
		m = (1/(yerr[i]*yerr[i]));
		p = p + m;
		q = q + ((x[i])*(m));
		r = r + ((y[i])*(m));
		s = s + ((x[i]*x[i])*(m));
		t = t + ((x[i]*y[i])*(m));
	}
	delta = (p*s) - (q*q);
	result.m = ((p*t)-(q*r))/(delta);
	result.c = ((r*s)-(q*t))/(delta);
	result.merr = (sqrt(p/delta))/length;
	result.cerr = (sqrt(s/delta))/length;
	return result;
}

int main(int argc, char *argv[]){
	char filename[256];
	int verbose = 0;
	// process command line args

	if ((argc > 1 && strcmp(argv[1],"-help") == 0) || argc == 1){  // display help message if either no arguments passed or "-help" passed
		printf("\n\nThis program calculates the least squares fit of a set of data. \nSupported file format is .csv. \nCurrently only supports comma as delimiter.\n\nDefault usage is: leastsquares.exe \"filename\" [-v]\n\n\t-help \tDisplays this help message\n\t-v\tVerbose mode: displays errors/status, prints the\n\t\tdata that it reads for verification purposes.\n\n");
		return 0;
	}

	else if(argc > 1){
		strcpy(filename,argv[1]);
		if (argc > 2){
			if(strcmp(argv[2],"-v") == 0){
				verbose = 1;
			}
		}	
	}
	// command line args processed, now go ~do shit~

	dataset input;
	graph output;
	input = GetInput(filename,verbose); // go open the file
	output = LeastSquares(input.length,input.x,input.y,input.yerr);
	if(isnan(output.m) == 0 && isnan(output.merr) == 0 && isnan(output.c) == 0 && isnan(output.cerr) == 0){
		printf("The least squares fit of this data is: y = (%.2f \361 %.2f)x + (%.2f \361 %.2f) \n",output.m,output.merr,output.c,output.cerr);
	}
	return 0;
}
