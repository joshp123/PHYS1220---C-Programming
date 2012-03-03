/* Program to demonstrate for loops:
Ex 7.1 */
#include <stdio.h>
int main() {
	int i;
	float data[10], sum, sumsq, sumdev, mean;
	sum=0.0;
	sumsq=0.0;
	for(i=0; i<10; ++i) {
		printf("Enter data %d: \n", i);
		scanf("%f", &data[i]);
		sum = sum+data[i];
		sumsq=sumsq+data[i]*data[i];
	}
	mean=sum/10.0;
	printf("Average is %f\n",mean);
	printf("Variance is %f\n",sumsq/10.0-mean*mean);
	sumdev=0.0;
	for(i=0;i<10;++i) {
		sumdev=sumdev+ (data[i]- mean)*(data[i]-mean);
	}
	printf("Variance is %f\n",sumdev/10.0);
	return 0;
}
