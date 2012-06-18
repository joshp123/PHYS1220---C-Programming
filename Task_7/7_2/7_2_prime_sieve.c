/*
Prime sieve

Task 7.3

*/

#include <stdio.h>

int main() {
	int n,a,b,l,c;
	printf("For what numbers do you want to calculate primes below?\n");
	scanf("%d", &n);
	double primes[n];
	primes[1]=0; /* 1 is not prime */
	for(a=2;a<=n;a++){
		primes[a]=1;
	}
	for(a=2;a<=n;a++){
		/*printf("Running on multiples of %i \n",a);*/
		for(b=a*2;b<=n;b+=a){
			primes[b] = 0;
			/*printf("removing %i \n", b);*/
		}
	}
	printf("The prime numbers below %f are:\n", n );
	int primecount = 0;
	double primes2[1500];
	for(c=1;c<=n;c++){
	/* printf("%ith value in primes: %i \n",c, primes[c]);*/
		if(primes[c] != 0){
			primes2[primecount] = c;
			primecount++;
	}
	}
	double acc = 0;
	for (int i = 0; i < primecount; ++i)
	{
		acc = acc + primes[i];
	}
	printf("Sum of primes below %f are = %f \n",n,acc);
	return 0;
}