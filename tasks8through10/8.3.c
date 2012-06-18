// task 8.3
// reading from a table

#include <stdio.h>

int main() {
	FILE *fin;
	int i;
	float data, sum;
	fin = fopen("data 8.3.txt","r");
	if (fin==0) {
		printf("can't open file\n");
	}
	sum=0.0;
	for(i=0; i<10; ++i) {
		fscanf(fin, "%f", &data);
		sum = sum+data;
	}
	printf("Average is %f\n",sum/10);
	fclose(fin);
	return 0;
}