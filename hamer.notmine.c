// Least squares regression program

#include <stdio.h> //include the functin libraries needed
#include <math.h>

int main () { //main function
FILE *dat; //name file in use
float x[200] , y[200], e[200], p = 0.0, q = 0.0, r =0.0, s = 0.0, t = 0.0, delta, a, b, errora, errorb; //define all floats
int i, points; // define all ints
printf("This program will calculate the least squares regression line \nfor a set of data pairs (x ,y) where there are errors in y\n"); //inform user of program funtion
printf("The line is of the form y = a + bx\n");
printf("The data will be read from the file data.txt \n"); //inform user of the file to be read
printf("The first line of this file should include only the number of data pairs \n"); //inform user of important information about file setup
printf("All x data should then be listed followed the the corresponding y data \n"); //cont
printf("Errors in y should be enetered last \n"); //cont
printf("Each data point should be listed on a new line, there should be no empty lines \n\n"); //cont
dat=fopen("data.txt","r"); // open file
if (dat == 0) { //if function to terminate program is file doesn't exist
printf("Error: Cannot open data file!\n"); // error message
return 0; // terminates program if if function is fulfilled
}
fscanf(dat,"%d",&points); //scan in number of data points
if (points < 2) { //if function to terminate program if stated number of data points is less than 2
printf("Error: There must be atleast 2 data points!\n"); //error message
return 0; //terminates program if if function is fulfilled
}
for (i = 0 ; i < points; ++i) { //scan in x values
fscanf(dat, "%f", &x[i]);
}
for (i = 0 ; i < points; ++i) { // scan in y values
fscanf(dat,"%f", &y[i]);
}
for (i = 0 ; i < points ; ++i) { // scan in errors
fscanf(dat,"%f", &e[i]);
if (e[i] == 0) { //if statement for error if an error in y value is 0
printf("Error: Errors can not be zero!\n"); // error message
printf("This table may help to find the error in your data file\n\n"); //helpful program function
printf("x	 y	 error in y\n"); // table (headers)
for (i = 0 ; i < points ; ++i) {
printf("%.2f	 %.2f	 %.2f\n", x[i], y[i], e[i]); // table (body)
}
return 0; //terminates program if if function is fulfilled
}
}
printf("For the purpose of checking if data has been entered into the file correctly \na table is shown below (all figures are shown to 2 decimal places)\n\n");
/*line above is to make the program more user friendly*/
printf("Number of data pairs: %d\n\n",points); // states the number of data pairs (for human error checking)
printf("x	 y	 error in y\n"); //prints a table for error checking by user (headers)
for (i = 0 ; i < points ; ++i) {
printf("%.2f	 %.2f	 %.2f\n", x[i], y[i], e[i]); //table (body)
}
for (i = 0 ; i<points ; ++i) { //compute p
p = p + (1/(e[i]*e[i]));
}
for ( i = 0 ; i<points ; ++i) { //compute q
q = q + (x[i]/(e[i]*e[i]));
}
for ( i = 0 ; i<points ; ++i) { //compute r
r = r + (y[i]/(e[i]*e[i]));
}
for ( i = 0 ; i<points ; ++i) { // compute s
s = s + ((x[i]*x[i])/(e[i]*e[i]));
}
for ( i = 0 ; i<points ; ++i) { //compute t
t= t + ((x[i]*y[i])/(e[i]*e[i]));
}
delta = (p*s) - (q*q); //compute delta
a = (r*s - q*t)/delta; //compute a
b = (p*t - q*r)/delta; //conpute b
errora = sqrt(s/delta); // compute error in a
errorb = sqrt(p/delta); //compute error in b
printf("\ny = %f + %fx\n\n",a, b); //print result y = a + xb
printf("Error in a = + or - %f\nError in b = + or - %f\n", errora, errorb); //print errors
return 0; //terminate program and return zero at end if program runs correctly
}