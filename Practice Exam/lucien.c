#include <stdio.h>
#include <math.h>
 
int main() {
 
        int i,n;
        float h,a,b;
        printf("What is the left end point of integration?\n");
        scanf("%f",&a);
 
        printf("What is the right end point of integration?\n");
        scanf("%f",&b);
 
        printf("What is the desired number of meshpoints?\n");
        scanf("%d",&n);
        printf("A = %d, B = %d \n",a,b );
        h=(b-a)/2;
        printf("h= %d\n",h);

        return 0;
}