// task 10.3.c

# include <stdio.h>
# define MILES 26
# define YARDS 385

int main() {
	float km;
	int miles = 26;
	int yards = 385;
	km = (1.609 * MILES + YARDS/1760.0);
	printf("A marathon is %d miles and %d yards\n",miles, yards );
	printf("Or in metric, %f km\n",km);
	return 0;
}
