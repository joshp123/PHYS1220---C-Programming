/* maths functions yo */
#include <stdio.h>
#include <math.h>
int main() {
	float pi,n,e,a,b,c,ans;
	pi = acos(-1.0);
	n = 10.0;
	e = exp(1);
	a = (n/e);
	b = pow(a,n);
	c = 2*pi*n;
	ans = (sqrt(c)) * b;
	printf("%f factorial is %f\n",n,ans);
	return 0;
}
