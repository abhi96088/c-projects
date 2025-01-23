// clock showing current time and date

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	
	time_t rawtime;
	struct tm *current_time;
	char time_buffer[50];
	char date_buffer[100];
	
	while(1){
	
	system("cls");
	
	time(&rawtime);
	current_time = localtime(&rawtime);
	
	strftime(time_buffer, sizeof(time_buffer), "%I:%M:%S %p", current_time);
	strftime(date_buffer, sizeof(date_buffer), "%A, %B %d %Y", current_time);	
	
	printf("Current Time Is : %s", time_buffer);
	printf("\nDate Is : %s\n", date_buffer);
	
	sleep(1);
	
	}
	
return 0;
}
