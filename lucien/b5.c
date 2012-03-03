#include <stdio.h>
#include <math.h>
int main(){
	FILE *fin;

	int i, number;

//open file
	fin=fopen("data.txt","r");
	if(fin==0) {
		printf("Cannot open data file\n");
		return 0;
	}

//find number of variables (first number in .txt file)
	fscanf (fin, "%d\n", &number);

	float x[number],y[number],error[number];
	float p,sumx,sumxsq,sumy,sumxy, intercept, gradient;


//p is the sum of the recriprocal of the errors squared.
	p=0;
	sumx=0;
	sumxsq=0;
	sumy=0;
	sumxy=0;

//calculating values for p, sumx, sumxsq, sumy, sumxy.
//x, y and error data separated by a space in file.

// double farts[4];
// farts[1] = 'q';
// farts[2] = 2;
// farts[3] = 5;
// printf("c sucks lol!!!!\n");
// printf("q %f q %f q %f q\n",isnan(farts[1]),isnan(farts[2]),isnan(farts[3]));

int valid;

	for (i=0; i<number; i++) {
		valid = fscanf (fin, "%f %f %f\n", &x[i], &y[i], &error[i]);
		if(valid==0){
			printf("Your data is not numeric!!!!! fix this you stupid nerd!!!! :(\n");
			printf("quitting program so you can stop being useless and fix your terrible data you pathetic human waste of life!!! \n");
			return	0;
		}
		// printf("%f = x, %f = y,  %f = \361 err \n",x[i], y[i], error[i]);
		if(error[i]==0){
			printf("you have errors equal to zero this is wrong and dr adolf will skin you alive or something idk\n");
			return 0;
		}
		p = p + 1/pow(error[i],2);
		sumx = sumx + x[i]/pow(error[i],2);
		sumxsq = sumxsq + pow(x[i],2)/pow(error[i],2);
		sumy = sumy + y[i]/pow(error[i],2);
		sumxy = sumxy + x[i]*y[i]/pow(error[i],2);
	}

fclose(fin);

// for (i=0; i<number; i++) {
// 	if(isnan(x[i]) == 1) { // TODO: do something with || error[i] != 0 //search file for non-numeric data, terminate program if found.
// 		printf("Non-numeric data in file.\n");
// 		printf("Program Terminated.");
// 		return 0;
// 	}
// 	else{
// 		printf("x data is valid\n");
// 	}
// 	if(isnan(y[i]) == 1) { // TODO: do something with || error[i] != 0 //search file for non-numeric data, terminate program if found.
// 		printf("Non-numeric data in file.\n");
// 		printf("Program Terminated.");
// 		return 0;
// 	}
// 	else{
// 	printf("y data is valid\n");
// 	}

// 	if( isnan(error[i]) == 1 ) { // TODO: do something with || error[i] != 0 //search file for non-numeric data, terminate program if found.
// 		printf("Non-numeric data in file.\n");
// 		printf("Program Terminated.");
// 		return 0;
// 	}
// 	else{
// 	printf("errors data is valid\n");
// 	}
// }

//Formulae from D.G. Rees - Statistics (4th Edition).
// for (i = 0; i < number; i++){

// 	}
	gradient=(sumxy-(sumx*sumy)/p)/(sumxsq-(sumx*sumx)/p);
	intercept=(sumy-gradient*sumx)/p;

	printf("The best line of fit is %fx + %f.\n",gradient,intercept);
	printf("The error in the intercept is \361 %f.\n", pow(sumxsq/(p*sumxsq-sumx*sumx),0.5));
	printf("The error in the gradient is  \361 %f.\n", pow(p/(p*sumxsq-sumx*sumx),0.5));

	fclose(fin);
	return 0;
}
