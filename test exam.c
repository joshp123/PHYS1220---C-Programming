#include <stdio.h>
#include <math.h>

int main(){
	int f = 5;
	f = (f>10)?24:3;
	printf("f = %d\n",f);
	f = 20;
	f = (f>10)?24:3;
	printf("f = %d\n",f);
	int a[5];
	for (int i = 0; i < 5; ++i)
	{
		a[i] = 3 * i;
	}
	printf("max (i)\n",max(i));
}