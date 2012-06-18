// task 9.1 and 9.3 i guess
// functions etc

# include <stdio.h>

float average(float array[], float size){
	int i;
	float sum;
	sum=0.0;
	// size=15;
	for (int i = 0; i < size; ++i){
		sum=sum+array[i];
	}
	return sum/size;
}

float Variance(float array[], float size){
	float var,sum,sumsq,mean;
	sum=0.0;
	sumsq=0.0;
	for(int i=0; i<size; ++i) {
		sum = sum+array[i];
		sumsq=sumsq+array[i]*array[i];
	}
	mean=sum/size;
	var = sumsq/size-(mean*mean);
	return var;
}

int main() {
	printf("this does Variance and Mean - i.e. tasks 9.1 and 9.3 combined\n");
	int i,number;
	float data[10],mean;
	number=10;
	for (int i = 0; i < number; ++i)
	{
		printf("Enter data %d \n",i);
		scanf("%f", &data[i]);
	}
	mean = average(data,number);
	float var = Variance(data,number);
	printf("Average is %f\n",mean);
	printf("Variance is %f\n",var);
	// printf("Number: %d\n",number);
	return 0;
}