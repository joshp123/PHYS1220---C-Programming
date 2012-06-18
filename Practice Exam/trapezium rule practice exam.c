/* trapezium rule bitchez */

#include <stdio.h>
#include <math.h>

float fx(float x){
	float result = exp((-(pow(x,2)))/2);
	return result;
}

int main(){
	float x0, xn, h, result, dx;
	int n;
	printf("What is the left endpoint of integration?\n");
	scanf("%f", &x0);
	printf("What is the right endpoint of integration?\n");
	scanf("%f", &xn);
	printf("And the number of desired meshpoints?\n"); // NB SPELLING IS V IMPORTANT!!!!
	scanf("%d", &n);
	// begin iterating all this shit yo

	h = (xn - x0)/n;
	// do f1 f2 etc

	float fxn = 0;
	for (int i = 1; i < n; ++i) // iterating from f1 to fn-1 (n-1 because stopping when i < n)
	{
		fxn = fxn + fx(x0 + (h*i));
	}
	result = h*(fx(x0/2) + fx(xn/2) + fxn);
	printf("THe value of this integral calculated by the trapeziod blah blah blah is: %f \n",result);
	return 0;
}