// shit code from least squares fit.c that i'm forgetting about

/*
Function to get data in the form x, y, errors on y, from a txt (if passed type = 1) or csv file (type = 2)
*/

dataset GetInputFromFile(int type){
	printf("Commencing file open routine\n");//delme
	FILE *fin;
	int i;
	float data[256];
	dataset output;
	if(type == 1){
		fin = fopen("data.txt", "r");
		printf("openinig text file\n");//delme
	}
	else {
		fin = fopen("data.csv", "r");
		printf("opening csv\n"); //delme
	}
	if(fin==0) {
		printf("Could not open file.\n");
		// return;
	}
	output.length = 1 // DO SHIT HERE BLARHG
	for(i=0;i<10;++i){
		fscanf(fin, "%f", &data[i]);
		printf("%f\n",data[i]);
	}
	// printf("data: %f \n",data);
	fclose(fin);
	for(i = 0;i<length;i++){
		output.x[i] = data[i];
	}
	for(i = length;i<(length*2);i++){
		output.y[i] = data[i];
	}
	for(i = (length*2);i<=(length*3);i++){
		output.x[i] = data[i];
	}
	return output;
}
// float getfloat(void){
// 	float input;
// 	int valid;
// 	valid = 0;
// 	while(valid==0){
// 		valid = fscanf("%f", &input);
// 		flush();
// 		if(valid==0){
// 			printf("Please enter a valid number!\n");
// 		}
// 	}
// 	return input;
// }

// int getint(void){
// 	int input;
// 	int valid;
// 	valid = 0;
// 	while(valid==0){
// 		valid = scanf("%f", &input);
// 		flush();
// 		if(valid==0){
// 			printf("Please enter a valid number!\n");
// 		}
// 	}
// 	return input;
//}