/* 17243510078 MÇ - HW3 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//a structure for counts
typedef struct{
	int lines,forloop,whileloop,dowhileloop;
}counter;

int main(){
	int is_ended = 0;
	
	do{
	FILE *fileptr;
	char filename[50]; //test or test.cpp
	char extension[10]; //.cpp
	counter count = {0}; //sets all struct variables to zero
	int skipNextWhile = 0; //controlling while skips
	
	printf("Write the program name e.g:(test.cpp): ");
	gets(filename); //reads filename from user
	
	if(strchr(filename,'.') == NULL){ //if user forgot the enter extension with dot. I need to ask him what is the extension of file
		printf("Please enter the file extension e.g(c, cpp, txt, dat): ");
		gets(extension); 
		strcat(filename,"."); // add dot automatically
		strcat(filename,extension); //merge two string like (filename and .txt to filename.txt)
	}

	fileptr = fopen(filename,"r"); //only read
	if(fileptr == NULL){
		//Check the pointer if it is not exist then rewind do-while loop
		printf("File does not exist..\n\n");
		continue;
	}
	
	//Calculating part
	while(!feof(fileptr)){
		char achar = fgetc(fileptr); //reads char by char
		if(achar == '\n'){ //if there is \n character so its a new line.
			count.lines++;
		}
	}
	
	rewind(fileptr); //reset pointer
	while(!feof(fileptr)){
		char str[300];
		//fscanf(fileptr,"%s",str); //it doesnt takes spaces. its useful for different type writing such as for_( , for(, for___( => (_=space)
		fgets(str,300,fileptr); // This takes all line with spaces. I prefered this one because there is maybe a comment in the line So,I can delete them.
		
		//this block deletes comments from a line
		char *commentPtr = strstr(str, "//"); //finds first occurence of '//' and puts to this pointer \0
		if (commentPtr != NULL) {
			//printf("%d, %s",*commentPtr,commentPtr);
		    *commentPtr = '\0';
		}		
		//printf("%s\n",str);//just check string
		
		
		//I need to remove empty spaces in a line because I want to check statements with paranthesis. such as 'for('
		//Maybe developer used something like this > printf("This is for students.");
		//I dont want to count this.
		int charcount = 0; 
    	for(int i=0; i<strlen(str); i++){
    		if(str[i] != ' '){ //if it is not an empty space
				str[charcount] = str[i];
				charcount++;
    		}
		}
    	str[charcount] = '\0';//end of line
    	
    	//printf("%s\n",str);//just check string
		
		if(strstr(str,"for(") != NULL){ //finds starts with 'for('
			count.forloop++;
		}
		if(strstr(str,"do{") != NULL){ //finds starts with 'do{'
			count.dowhileloop++;
			skipNextWhile = 1; //I want to skip next while
		}
		if(strstr(str,"while(") != NULL){ //finds start with 'while('
			if(skipNextWhile) //if it is true then skips and resets its original value
			skipNextWhile = 0;
			else
			count.whileloop++;
		}
	}
	
	//outputs
	printf("---------------------------------------\n");
	printf("Program named \"%s\" contains:\n",filename);
	printf("%d lines of code\n",count.lines);
	printf("%d for loops\n",count.forloop);
	printf("%d while loops\n",count.whileloop);
	printf("%d do-while loops\n",count.dowhileloop);
	printf("---------------------------------------\n");
	fclose(fileptr);
	
	printf("Do you want to read & analyze another file (Y/N) ? > ");
	char con = getchar();
	con = tolower(con);
	if(con == 'n'){
		is_ended = 1;
		printf("\n> Good bye..");
	}else{
		char enter = getchar(); //skip enter
	}
	
	}while(!is_ended);
	
	return -1;
}
