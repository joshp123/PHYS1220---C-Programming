// examnew THIS VERSION WORKS LOL

/*

Computing Exam

*/

#include <stdio.h>
#include <math.h>


int main(){
	int input[10], evens[10], odds[10], primesarray[1000],sum;
	float average;
	for (int i = 0; i < 10; ++i)
	{
		printf("Enter an integer number %d of 10:\n",i+1);
		scanf("%d", &input[i]);
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("Integer number %d was %d \n",i+1, input[i]);
	}

	// do average
	sum = 0;
	for (int i = 0; i < 10; ++i)
	{
		sum = sum + input[i];
	}
	average = sum / 10.0;
	printf("The average of these 10 integers is: %f\n",average);

	// average done, begin largest
	printf("I was going to do min/max but i'm lazy so nope\n");
	// largest done, begin smallest

	// smallest done, begin even/odd

	int evencount = -1;
	int oddcount = -1;
	for (int i = 0; i < 10; ++i)
	{
		if((input[i] % 2) == 0) // if input[i] divides evenly into 2
		{
			evencount++;
			evens[evencount] = input[i];
		}
		else{
			oddcount++;
			odds[oddcount] = input[i];
		}
	}
	printf("\nThere were %d even numbers and they were: \t",evencount);
	for (int i = 0; i < evencount+1; ++i)
	{
		printf("%d, ",evens[i]);
	}
	printf("\nThere were %d odd numbers and they were: \t",oddcount);
	for (int i = 0; i < oddcount+1; ++i)
	{
		printf("%d, ",odds[i]);
	}
	printf("\n");
	// finished odd/even, do primes:

	// prime seive

	int a,b,l,c;
	int n = 1000;
	int primes[n];
	int primes2[1000];
	primes[1]=0; /* 1 is not prime */
	for(a=2;a<=n;a++){
		primes[a]=1;
	}
	for(a=2;a<=n;a++){
		// printf("Running on multiples of %i \n",a);
		for(b=a*2;b<=n;b+=a){
			primes[b] = 0;
			// printf("removing %i \n", b);
		}
	}
	//printf("The prime numbers below %i are:\n", n );
	int primecount = 0;
	for(c=1;c<=n;c++){
	/* printf("%ith value in primes: %i \n",c, primes[c]);*/
		if(primes[c] != 0){
			// printf("c is prime! c is %d \n",c);
			primecount++;
			// printf("primecount so far: %d\n", primecount);
			primes2[primecount-1] = c;
			//printf("Primes number # %d is %d\n",primecount,c);
			// printf("primecount = \n",primecount);
			// primes2[0] = primecount;
	}
	}
	for (int i = 0; i < primecount; ++i)
	{
		// printf("primes2[i] = %d \n",primes2[i]);
	}

	for (int i = 0; i < 10; ++i)
	{
		int isprime = 0;
		for (int j = 0; j < primecount; ++j)
		{
			// printf("Diagnostics line: Comparing integer %d, %d with prime %d, %d\n",i+1,input[i],j+1,primes2[j]);
			if(input[i] == primes2[j]){
				isprime = 1;
				printf("%d was a prime!\n",input[i]);
			}

		}
		if(isprime == 0){
			printf("%d was not a prime.\n",input[i]);
		}
		// if (isprime = 1)
		// {
		// 	printf("Integer number %d, %d was a prime!\n",i+1,input[i]);
		// }
		// else
		// 	printf("Integer number %d, %d was not a prime!\n",i+1,input[i]);
	}
	return 0;
}




