/* 17243510078 MÇ - HW1*/
#include <stdio.h>
#include <conio.h>
//I defined some variables as global variable so I can reach them in each function. In this way, I don't need to define them again..
int i, mt, highest_index = 0;

//input function
void get_student_grades(int sem[][10]){
	for(i=0; i<4; i++){ //just because 4 section
		printf("Enter grades of section %d: ",i+1);
		for(mt=0; mt<10; mt++){ //just because each of section has 10 students
			scanf("%d",&sem[i][mt]);
			
			//if there is an invalid value for grade, just go the previous index and continue (grades must be between 0 and 100 for consistent average)
			if(sem[i][mt] < 0 || sem[i][mt] > 100) mt--;
		}
	}
}

//average function
void calculate_semester_avg(int sem[][10],float sem_avg[]){	
	for(i=0; i<4; i++){
		int sum = 0;
		
		for(mt=0; mt<10; mt++)
		sum += sem[i][mt];
		
		//I just used type casting for convert int to float because average can has decimal and float/int can be a trouble at desktop/console programming. 
		//Also, I saw the sample run results with decimal numbers
		sem_avg[i] = (float)sum/10;
		
		//It just checking last score and puts index on it if the new value is greater than before
		if(sem_avg[i] > sem_avg[highest_index]) highest_index = i;
	}
}

//output function. this is extra but i hope it doesn't affect my score
void print_results(float avg[], int hindex){
	printf("-----------------------------\n");
	printf("The averages of the sections:\n");
	for(i=0; i<4; i++){
		printf("Section %d: %.1f\n",i+1,avg[i]);
	}
	printf("-----------------------------\n");
	printf("Section %d has the highest average: %.1f\n",(hindex+1),avg[hindex]);
}

main(){
	//I'm declaring one multi-dimensional array for semester and grades, other one just for averages of section. I set values to zero just for precaution
	int semester[4][10] = {0};
	float semester_avg[4] = {0};
	
	//get student grades for each section and set them to semester array
	get_student_grades(semester);
	
	//call function to calculate average and find the highest one's index
	calculate_semester_avg(semester,semester_avg);
	
	//call function to write all results and highest average
	print_results(semester_avg, highest_index);
	
	//I used this command just for executable file (.exe) to see what results are
	getch();
}



