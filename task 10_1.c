/* Program illustrating while */
#include <stdio.h>

int main() {
	int j, sum;
	sum = 0;
	j = 0;
	while(sum<=1000){
		++j;
		sum = sum+j;
	}
	printf("After %d terms sum is %d\n",j,sum);
	return 0;
}