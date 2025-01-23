// program to generate progress bars

#include<stdio.h>
#include<stdlib.h>	// helps to run command on system using system function
#include<unistd.h>	// used for sleep function
#include<time.h>	// to acces time. here using to seed  random value

// constant variable for global use
const int BAR_LENGTH = 50;
const int MAX_TASK = 5;

// structure for the property of progress bar 
typedef struct{
	int id;
	int progress;
	int step;
}Task;

// function to print the progress bar
void printbar(Task task){
	
	// calculate the bar length
	int bars_to_show = (task.progress * BAR_LENGTH) / 100;
	
	printf("Task %d: [", task.id);
	int i;
	for(i = 0; i < BAR_LENGTH; i++){
		if(i < bars_to_show){
			printf("=");
		}else{
			printf(" ");
		}
	}
	
	printf("] %d%%\n", task.progress);
}

int main(){
	
	Task tasks[MAX_TASK];
	srand(time(NULL));	// seeding random with time
	
	// loop for initialization
	int i;
	for(i = 0; i < MAX_TASK; i++){
		
		tasks[i].id = i + 1;
		tasks[i].progress = 0;
		tasks[i].step = rand() % 5 + 1;
	}
	
	// variable assuming task is not completed
	int task_incomplete = 1;
	
	// loop to print progress bars. runs till task is not completed
	while(task_incomplete){
		// assume task is completed
		task_incomplete = 0;
		
		// clears the screen
		system("cls");
		
		// loop to print tasks
		int i;
		for(i = 0; i < MAX_TASK; i++){
			
			tasks[i].progress += tasks[i].step;		// adding progress
			
			// check if task is completed
			if(tasks[i].progress > 100){
				
				// assign tesk value to 100 if it goes beyond
				tasks[i].progress = 100;
				
			}else{
				
				// task is not completed if the progress value is less than 100
				task_incomplete = 1;
			}
			
			// print bar
			printbar(tasks[i]);
		}
		
		sleep(1);	// sleep for a second
	}
	
	// print when all task is completed
	printf("\nAll Tasks Completed !");
	
return 0;
}




