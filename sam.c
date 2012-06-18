/* Program to demonstrate the if construct */
#include <stdio.h>
int main () {
	int miles,yards,success;
	float km;
	printf("Enter number of miles: ");
	success=scanf("%d",&miles);
	
	if(success==0) {
		printf("You must enter a number!\n");
		return 0;
	}
	
	printf("Enter number of yards: ");
	success=scanf("%d",&yards);
	
	if(success==0) {
		printf("You must enter a number!\n");
		return 0;
	}
	km = 1.609 * (miles+yards/1760.0);
	printf("%d miles and %d yards\n",miles,yards);
	printf("in metric is %f km\n",km);
	return 0;
}