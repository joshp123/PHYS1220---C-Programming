/* demonstrating variables and expressions */
#include <stdio.h>
int main(){
	int success;
	float c,k,f;
	printf("Enter temp to be converted: ");
	success = scanf("%f", &c);
	if(success==0){
		printf("You must enter a number!\n");
		return 0;
	}
	if(c < -273.0){
		printf("This temp is below absolute zero!\n");
		return 0;
	}
	k = c+273.15;
	f = ((9.0/5.0)*c)+32;
	printf("%f degrees c is:\n%f degrees kelvin and:\n%f degrees farenheit \n",c,k,f);
	return 0;
}
