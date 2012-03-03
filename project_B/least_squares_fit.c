/*

Project B: Parameters of a least squares fit

Takes data from a file / user input and calculates a least squares fit of them, returns equation in the form y = mx + c

*/

#include <stdio.h>
#include <math.h>

/* Structure for the final result. returns m and c values and errors on both, i.e. y = mx + c */
typedef
 struct {
	float m;
	float merr;
	float c;
	float cerr;
}	graph;

/*structure for the input data - length, arrays of x, y, and y errors */

typedef struct{
	int length;
	double x[1000]; // todo: figure out if you can dynamically extend the arrays if you want to be retarded and use a billion data points or whatever instead of some arbitrary limit
	double y[1000];
	double yerr[1000];
} dataset;

/*Functions to flush to end of line - if we want to ignore "," between values in .csvs we'll probably need to modify this at some point
*/

void flushf(FILE *getfile){  // complier only plays nice when you use void instead of ()  vOv
	while(fgetc(getfile)!='\n'){}
}

void flush(void){  // complier only plays nice when you use void instead of ()  vOv
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

/*this get input from a .csv or .txt file formatted in the form:
x1, y1, yerr1
x2, y2, yerr2
x3, y3, yerr3

etc.

This is smart because it's how excel saves .csv files and excel is nice and easy and yeah you get the idea.	!

TODO: make it so you can call this exe from the commandline being all leastsquares.exe -somefilename.whatever and it opens that. It might even work if you do leastsquares.exe -"C:\gbs\555\foo.bar" but i'll get to that when i do this (see you in 2015). I suppose you could also sorta prompt for it in the program but that's kinda stupid, it would be more sensible to make a GUI and use window's browse thing but now i'm getting carried away

*/

// NB I SWITCHED FROM COLUMS TO ROWS BECAUSE THAT MAKES MORE SENSE, GO CHECK EVERYTHING IS RIGHT YOU FAGGOT

dataset GetInputNew(int type){
	printf("Commencing file open routine\n");//delme
	FILE *fin;
	int i = 0; // i = columns, i.e. # of datapoints
	int a,b,c;
	int j = 0; // j = rows, i.e. # of series. here should never exceed 2 (x has j=0, y has j = 1, yerr has j = 2)
	// int xcount, ycount, yerrcount, - add this line later to verify same number of points on each line
	double data[2][256];
	dataset output;
	if(type == 1){
		fin = fopen("data.txt", "r");
		printf("Opening data.txt file\n");//delme
	}
	else {
		fin = fopen("data.csv", "r");
		printf("Opening data.csv file\n"); //delme
	}
	if(fin==0) {
		printf("Could not open file.	\n");
		// return;
	}
	while((fgetc(fin) != 'EOF') || j <= 2){ // stops at EOF and when j<=2. TODO: add an alert when j > 2 so you can tell the user that they are dumb and should RTFM
		if(fgetc(fin) != '\n'){
			if(fgetc(fin) != ','){
				data[j][i] = fgetc(fin); // todo: check that this is actually a float
				printf("%f \n",data[j][i]);
			}
			elsei
				{++;
				s++; //use s as a total number of values
			}
		}
		else{
			j++;
			i=0;
		}
	}

	fclose(fin);

	// start processing data after here, adding it into arrays etc etc etc

	if (j > 2)	{
		printf("More than 3 data-sets detected. Ignoring all data after the first 3 sets.\n"); // should probably stop it adding it to the temporary array if you have 5k rows or whatever just for the sake of making it a bit faster but whatever i'm lazy and it doesn't really matter
	}
	output.length = c/j;
	printf("Your dataset has %i constituent points\n",output.length);
	for(b = 0; b <= j; b++){
		for(a = 0; a <= i; a++){
			printf("Row %i Column %i : %f\n",b,g,data[g][b]); // disgnostic prints itt TODO: make this sexy by adding a bunch of tabs and shit and making it wrap etc

			switch(b) {  // based on the column it's currently iterating on, picks which output set to do. This is necessary because doing the sumsquares shit on an array of arrays would be kinda gay whereas it's easier if they're 3 separate arrays.
				case 0:
					output.x[a] = data[a][g];
					break;
				case 1:
					output.y[a] = data[a][g];
					break;
				case 2:
					output.yerr[a] = data[a][g];
					break;
	}
		}
	}
	return output;
}

/*
Function to calculate p, q, r, s, t and obtain m and c from them
*/

graph LeastSquares(double x[], double y[], double yerr[], int length){
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

int main(){
	int choice;
	dataset input;
	graph output;
	printf("Is your data in a .txt or a .csv file? Enter 1 for txt, 2 for csv.\n"); // NB .CSV DOESN'T WORK YET. LOL EFFORT
	choice = UserSelection(2); // do userselection function, ensures user only picks 1 or 2
	input = GetInputNew(choice); // go open the file
	output = LeastSquares(input.x,input.y,input.yerr,input.length);
	printf("The least squares fit of this data is: y = (%2f \361 %2f)x + (%2f \361 %2f) \n",output.m,output.merr,output.c,output.cerr);
	return 0;
}
