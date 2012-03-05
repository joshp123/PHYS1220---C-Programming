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
	double x[1000]; // TODO: figure out if you can dynamically extend the arrays if you want to be retarded and use a billion data points or whatever instead of some arbitrary limit
	double y[1000];
	double yerr[1000];
} dataset;

// Functions to flush to end of line - this is useful for a reason. i'm not entirely sure what that reason is but whatever 

void flushf(FILE *getfile){  
	while(fgetc(getfile)!='\n'){}
}

void flush(){  // LCC complier only plays nice when you use flush(void) instead of flush()  . GCC on the other hand does not. welp that's my cool compiler story for today
	while(getchar()!='\n'){}
	}


/*
Function to prompt user for a numerical choice. I.e. pick 1) open .txt file, 2) open.csv file or 3) do nothing. If choice lies outside that range, prompts until valid choice in range is entered.
*/

int UserSelection(int options){
	int valid,input;
	valid = 0;
	while(valid==0){
		valid = scanf("%d", &input);
		flush();
		if(valid<=0 || valid > options){ // if user input is smaller than zero or greater than # of available options, it is not valid, prompt for new input
			printf("Please pick a valid option!\n");
		}
	}
	return input;
}

int GetFileLineCount(FILE *FILE){
	int linecount;
	// TODO: finish this (iterate over entire file reading \n, and incrementing, break at EOF)

	// TODO: since this scans for \n might be possible to do non-numeric data checking here? idk
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

TODO: make it so you can call this exe from the commandline being all leastsquares.exe -somefilename.whatever and it opens that. It might even work if you do leastsquares.exe -"C:\gbs\555\foo.bar" but i'll get to that when i do this (see you in 2015). I suppose you could also sorta prompt for it in the program but that's kinda stupid, it would be more sensible to make a GUI and use window's browse thing but now i'm getting carried away

omg i acutally did this fuck yeah i'm awesome :sun:

*/

dataset GetInput(char *filename, int verbose){ // either char * or char *filename idk
	printf("Commencing file open routine\n");//delme
	FILE *fin;
	int i;
	// TODO int xcount, ycount, yerrcount, - add this line later to verify same number of points on each line. necessarry? y/n
	dataset output;

	if(verbose == 1){
		printf("Opening %s\n",filename);// diagnostic line
	}
	
	fin = fopen(filename, "r");

	if(fin==0 && verbose == 1) {
		printf("Could not open file.\n");
		return;
	}

	// file open routine complete, get linecount

	output.length = 10; // TEST LINE PLZ REMOVE

	//output.length = GetFileLineCount(fin);

	// number of data points counted, now to read in the actual data

	while(fgetc(fin) != 'EOF'){ // terminates when it hits EOF
		for (i = 0; i < output.length; ++i){
			int valid = fscanf(fin, "%f,%f,%f", &output.x[i], &output.y[i], &output.yerr[i]);
			printf("x = %.2f\ty = %.2f\ty error = %.2f\n",output.x[i],output.y[i],output.yerr[i]); // diagnostic line
			if(valid !=0){
				printf("Non-numeric data detected in file.\n");
			}
			if (output.yerr[i] == 0){
				if (verbose == 1){
					printf("Your data contains errors that are equal to zero. This is invalid. Program exiting\n");
				}
			}
			return;
		}
	}

	fclose(fin);

	if (verbose = 1){
		printf("Your dataset has %i constituent points:\n\n",output.length);
		for (i = 0; i < output.length; ++i)
		{
			printf("x = %.2f\ty = %.2f\ty error = %.2f\n",output.x[i],output.y[i],output.yerr[i]);
		}
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
		q = (q + x[i])/(m);
		r = (r + y[i])/(m);
		s = (s + (x[i]*x[i]))/(m);
		t = (t + (x[i]*y[i]))/(m);
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
	for (int i = 0; i < argc; ++i)
	{
		printf("%s\n",argv[i]); // diagnostic line
	}
	if ((argc > 1 && strcmp(argv[2],"-help") == 0) || argc == 1){  // display help message if either no arguments passed or "-help" passed
		printf("\n\nThis program calculates the least squares fit of a set of data. Supported file format is .csv. Currently only supports comma as delimiter.\n\nDefault usage is: leastsquares.exe \"filename\" [-v]\n\n\t-help \tDisplays this help message\n\t-v\tVerbose mode: displays errors/status, prints the\n\t\tdata that it reads for verification purposes.\n\n");

		// delete this later:
		printf("LAZY MODE TO CHECK THAT MY THIS ACTUALLY WORKS: hit 1 to continue, 2 to gtfo\n");
		int cont = UserSelection(2);
		if (cont == 1){
		}
		else {
			return 0; // leave this in (i.e. exit after help message)
		}
	}

	else if(argc > 1){
		printf("accepting filename\n"); // diagnostic line
		strcpy(filename,argv[1]);
		if (strcmp(argv[2],"-v") == 0){
			printf("verbosity enabled\n"); // diagnostic line
			verbose = 1;

		}
	}
	int choice;
	printf("verbosity = %d \n",verbose);
	// command line args processed, now go ~do shit~

	dataset input;
	graph output;
	// deprecated:
	// printf("This program calculates the least squares fit of a set of data.\nYour data should be in the same directory as this executable,  \n");
	// printf("Is your data in a .txt or a .csv file? Enter 1 for txt, 2 for csv.\n");
	// choice = UserSelection(2); // do userselection function, ensures user only picks 1 or 2

	input = GetInput(filename,verbose); // go open the file
	output = LeastSquares(input.length,input.x,input.y,input.yerr);
	printf("The least squares fit of this data is: y = (%.2f \361 %.2f)x + (%.2f \361 %.2f) \n",output.m,output.merr,output.c,output.cerr);
	return 0;
}
