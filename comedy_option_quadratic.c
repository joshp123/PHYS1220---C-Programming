/*

Project A: Quadratic Equation solver

Only 10 times shittier and more annoying than using python! (http://pastebin.com/UTvA79SL implemented in python as a fun break from doing this. this is how painful c is, i literally did the same thing in another language for fun. ;_; )

Current limitations:

- Prints everything to 2 decimal places instead of intelligently detecting whether stuff is an integer or not
- Breaks if you enter a huge integer (eg 10^100 or whatever)

*/

#include <stdio.h>
#include <math.h>
#include <python.h>

/* defining complex number structure */
typedef struct {
	float re;
	float im;
} complex;

/* function to calculate the sqrt of both positive and negative numbers */
complex croot(float x){
	complex root;
	if(x < 0){
		root.im = sqrt(fabs(x));
		root.re = 0;
	}
	else{
		root.re = sqrt(x);
		root.im = 0;
	}
return root;
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

/* Function to flush to end of line */

void flush(void){  // complier only plays nice when you use void instead of ()  vOv
	while(getchar()!='\n'){}
}

/* Function to get input in form of float and check it's legit */
float getfloat(void){
	float input;
	int valid;
	valid = 0;
	while(valid==0){
		valid = scanf("%f", &input);
		flush();
		if(valid==0){
			printf("Please enter a valid number!\n");
		}
	}
	return input;
}

/* Function to calculate and print the roots of a quadratic equation */
int quadratic(float a, float b, float c){
	complex result,descr_root,root1,root2; //luv2declarevariables (not)
	float descr;
	int compl,distinct,s;
	s = 1;
	printf("\nComputing roots of %.2f x\375 + %.2f x + %.2f = 0\n\n",a,b,c); 

	/*
	i could make this pretty and display + 5x and -5x correctly instead of + -5.00 but that would take far too long beacause lol c sucks at concentating strings compared to python. totally not worth the effort
	*/

	descr = (b*b)- 4*a*c; // calculate discriminant
	
	if(descr == 0){
		s = 2;			// s is used to distinguish between the 3 cases: 2 real roots (discriminant +ve), 1 distinct root (discriminant = 0), 2 complex roots, (discriminant -ve). These are given by s = 1,2 and 3 respectively
	}
	else if(descr < 0){
		s = 3;
	}
	descr_root = croot(descr); // get sqrt(b^2 - 4ac) but complex
	root1.re = ((-1*b) + descr_root.re)/(2*a);
	root1.im = (descr_root.im)/(2*a);
	root2.re = ((-1*b) - descr_root.re)/(2*a);
	root2.im = (descr_root.im)/(2*a);
	switch(s) {
		case 1:
			printf("There are 2 distinct, real roots. They are:\n\n\tx = %.2f\n\nand\n\n\tx = %.2f\n",root1.re,root2.re);
			break;
		case 2:
			printf("There is one distinct root. It is:\n\n\tx = %.2f\n",root1.re);
			break;
		case 3:
			printf("There are 2 distinct, complex roots. They are:\n\n\tx = %.2f + %.2f i \n\nand\n\n\tx = %.2f + %.2f i\n",root1.re,root1.im,root2.re,root2.im);
			break;
	}
	return 0;
}

int main(){
	float a,b,c;
	int option;
	printf("Enter the quadratic coefficient:\n");
	a = getfloat();
	printf("\nEnter the linear coefficient:\n");
	b = getfloat();
	printf("\nEnter the constant term:\n");
	c = getfloat();
	printf("Do you want to go for the serious, boring C option or the comedy python imprementation? (type 1 for C, 2 for python\n");
	option = UserSelection(2);
	if(option == 1){
		quadratic(a,b,c);
	}
	else{
		
	}
	return 0;
}
