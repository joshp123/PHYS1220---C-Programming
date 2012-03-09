// task 8.1
// writing to a table or something idk

#include <stdio.h>

int main() {
	FILE *fout;
	int miles;
	float km;
	fout = fopen("tables.txt","w");
	for(miles=0;miles<=10;++miles){
		km=1.609*miles;
		fprintf(fout, "%d miles is %f km\n",miles,km );
	}
	fclose(fout);
	return 0;
}