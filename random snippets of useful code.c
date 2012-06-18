// cool snippets

/*
Function to prompt user for a numerical choice. I.e. pick 1) open .txt file, 2) open.csv file or 3) do nothing. If choice lies outside that range, prompts until valid choice in range is entered.
*/

int UserSelection(int options){
	int valid,input;
	valid = 0;
	while(valid==0){
		valid = scanf("%d", &input);
		flush();
		if(valid<=0 || valid > options){ // if user input is smaller than zero or greater than # of available options, it is not valid, prompt for new input
			printf("Please pick a valid option!\n");
		}
	}
	return input;
}


void flushf(FILE *getfile){  
	while(fgetc(getfile)!='\n'){}
}

void flush(){  // LCC complier only plays nice when you use flush(void) instead of flush()  . GCC on the other hand does not. welp that's my cool compiler story for today
	while(getchar()!='\n'){}
}