#include <stdio.h> //input,output
#include <string.h> //strstr,strcmp,strcpy,strlen
#include <ctype.h> //converts
int i, x, totalPerson, any_result; //global variables
//i for people loops, x for  char arrays loops, totalPerson for number of person, any_result for results count printed on the screen

typedef struct{
	int id;
	char fullname[20];
	char dance_style[20];
	char city[10];
}person; //typedef usage easier than the other struct one usage for me.

void input_People(person p[]){
	for(i=0;i<totalPerson;i++){ //the user should enter the information of people (for all of them)
		printf("-------------------------------------------\n");
		printf("Enter information about person %d, (%d/%d)\n",i+1,i+1,totalPerson); //shows a status indicator to help the user.
		printf("-------------------------------------------\n");
		printf("Enter name and surname: ");
		char enter = getchar(); //to avoid enter character before use gets() otherwise it will skip it
		gets(p[i].fullname);
		printf("Enter ID: ");
		scanf("%d",&p[i].id);
		printf("Enter dance style: ");
		scanf("%s",p[i].dance_style);
		printf("Enter city: ");
		scanf("%s",p[i].city);
	}
}

void search_city(person p[]){ //SEARCH BY CITY
	char search_term[10];
	printf("Please enter the city to be searched: ");
	scanf("%s",search_term);
	
	//I am converting all characters to lowercase. If the user enters a different type of character (full uppercase, mixed etc), this program will still work.
	for(x=0;x<strlen(search_term);x++) search_term[x] = tolower(search_term[x]);
	
	for(i=0;i<totalPerson;i++){ //loop for all user records
		//I dont want to change any original user data. So I need to define a new variable which I can convert characters in it. (to make a more accurate search)
		char currentCity[10];
		strcpy(currentCity,p[i].city);
		for(x=0;x<strlen(currentCity);x++) currentCity[x] = tolower(currentCity[x]); //same before (same technic used for search_term)
		
		if(strcmp(currentCity,search_term) == 0){ //it just compares two lowercase word and there are the same it returns 0.
			printf("> %s likes %s with ID %d\n",p[i].fullname,p[i].dance_style,p[i].id); //output
			any_result++; //counts how many results are there
		}
	}
}

void search_dancing_style(person p[]){ //SEARCH BY DANCING STYLE
	char search_term[10];
	printf("Please enter the dancing style to be searched: ");
	scanf("%s",search_term);
	for(x=0;x<strlen(search_term);x++) search_term[x] = tolower(search_term[x]);
	
	for(i=0;i<totalPerson;i++){
		//same thing in search_city function copied original data to a new variable to make them all to lowercase.
		char currentDstyle[20];
		strcpy(currentDstyle,p[i].dance_style);
		for(x=0;x<strlen(currentDstyle);x++) currentDstyle[x] = tolower(currentDstyle[x]);
		
		if(strcmp(currentDstyle,search_term) == 0){ //same thing compares two words
			printf("> %s lives in %s with ID %d\n",p[i].fullname,p[i].city,p[i].id);
			any_result++;
		}
	}
}

void search_first_char_of_city(person p[]){ //SEARCH BY FIRST CHAR OF A CITY
	printf("Please enter the first character of the city to be searched: ");
	char search_term = getchar(); //This time I just read a character
	
	for(i=0;i<totalPerson;i++){
		if( tolower( p[i].city[0] ) == tolower(search_term) ){ //this time, I just compared only the first character of words. (by converting them to lowercase)
			printf("> %s who lives in %s likes %s with ID %d\n",p[i].fullname,p[i].city,p[i].dance_style,p[i].id);
			any_result++;
		}
	}
}

int main(){
	char search_type[27]; // (the longest one "first character of the city" has 27 characters)
	int _is_program_ended = 0; //the user can continue as they want. This variable needed for do,while loop
	
	printf("Enter the number of people: ");
	scanf("%d",&totalPerson); //user enters a number of person
	
	//Determine array with structure.
	person p[totalPerson]; //defines total person array with structure
	
	input_People(p); //input_People function gets all information about people from the user to variable p.
	
	//do while loop. It will turn many times as long as the user enters 'dancing','style','first','char' or 'city' special keywords.
	do{
		any_result = 0; //evertime it must be equal the zero because there is no results.
		char enter = getchar(); //before use gets() we need to clear enter character
		printf("\nWhat do you want to search (city, dancing style, first character of the city): ");
		gets(search_type); // gets a word or full sentence for search type..
	
		//I am converting all characters to lowercase. If the user enters a different type of character (full uppercase, mixed etc), this program will still work.
		for(i=0;i<strlen(search_type);i++) search_type[i] = tolower(search_type[i]);
	
		//searching some constant characteristic keywords in the entered word or sentence (search_type) to decide what to do by using strstr function
		//In C programming Switch-Case doesnt work with string(char arrays) conditions. Therefore, I used one of the string function with if else.
		if(strstr(search_type,"dancing") != NULL || strstr(search_type,"style") != NULL){ // if in the sentence there is any word 'dancing' or 'style' just enters inside
			//I am sending an array with all structure within (all people) to function
			search_dancing_style(p);
			printf("%s",(any_result == 0 ? "> No results found..\n" : ""));//if there are no results then writes this.
		}else if(strstr(search_type,"first") != NULL || strstr(search_type,"char") != NULL){ // if in the sentence there is any word 'first' or 'char' just enters inside
			search_first_char_of_city(p);
			printf("%s",(any_result == 0 ? "> No results found..\n" : ""));
		}else if(strstr(search_type,"city") != NULL){ // this is the final statement. if in the sentence there is any word 'city' just enters inside.
			//if user enters 'first city', previous one will work. Because it is ELSE IF statement.
			search_city(p);
			printf("%s",(any_result == 0 ? "> No results found..\n" : ""));//if there are no results then writes this.
		}else{
			_is_program_ended = 1; //this means the program ended. do-while loop will end because _is_program_ended is not equal to zero anymore.
			printf("\nBye...\n");
		}
	}while(_is_program_ended == 0);

	return 0;
}
