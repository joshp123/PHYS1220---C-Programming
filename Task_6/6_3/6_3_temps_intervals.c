/*
Temperatures conversion w/for loops and inputs and shit yo

Task 6.3

*/

#include <stdio.h>
int main(){
	int success;
	float c1,c2,k,f,i;
	printf("Here you can print a list of temperatures in celcius, farenheit and kelvin at 10C intervals.\n");
	printf("Enter first temp to be converted: ");
	success = scanf("%f", &c1);
	if(success==0){
		printf("You must enter a number!\n");
		return 0;
	}
	if(c1 < -273.0){
		printf("This temp is below absolute zero!\n");
		return 0;
	}
	printf("Enter last temp to be converted: ");
	success = scanf("%f", &c2);
	if(success==0){
		printf("You must enter a number!\n");
		return 0;
	}
	if(c2 < -273.0){
		printf("This temp is below absolute zero!\n");
		return 0;
	}
	for(i = c1; i <=c2; i+=10){
		k = i+273.15; 
		f = ((9.0/5.0)*i)+32;
		printf("%f degrees c is:\n%f degrees kelvin and:\n%f degrees farenheit \n\n",i,k,f);
	}
	return 0;
}
