/* Program to demonstrate for loops:
Ex 6.1 */
include <stdio.h>
int main() {
	int i;
	float data, sum;
	sum=0.0;
	for(i=0; i<10; ++i) {
		printf("Enter data %d: \n", i);
		scanf("%f", &data);
		sum = sum+data
	}
	printf("Average is %f\n",sum/10);
}