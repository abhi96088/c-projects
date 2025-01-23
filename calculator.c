// program for a simple calculator

#include<stdio.h>
#include<math.h>

void printMenu(){
	printf("\nSelect an option from below:\n");
	printf("1. Add\n");
	printf("2. Subtract\n");
	printf("3. Multiply\n");
	printf("4. Divide\n");
	printf("5. Mod\n");
	printf("6. Power\n");
	printf("7. Exit\n");
	printf("\nSelect any one option to continue: ");
}

int main(){
	
	int option, isError;
	double fn, sn;
	double result;
	
	printf("-------------------------------------\n");
	printf("    Welcome to Simple Calculator\n");
	printf("-------------------------------------\n");
	
	while(1){
		
		isError = 0;
		
		printMenu();
		scanf("%d", &option);
	
	
		if(option > 0 && option < 7){
			printf("Enter first number: ");
			scanf("%lf", &fn);
			printf("Enter second number: ");
			scanf("%lf", &sn);
		}else if(option == 7){
			break;
		}else{
			printf("Please enter a valid option!\n\n");
			continue;
		}	
	
		switch(option){
			case 1: {
				result = fn+sn;
				break;
			};
			case 2: {
				result = fn-sn;
				break;
			};
			case 3: {
				result = fn*sn;
				break;
			};
			case 4: {
				if(fn > 0 && sn > 0){
					result = fn/sn;
				}else{
					printf("Please enter a positive number !\n\n");
					isError = 1;
				}
				break;
			};
			case 5: {
				if(fn > 0 && sn > 0){
					result = (int)fn % (int)sn;
				}else{
					printf("Please enter a positive number !\n\n");
					isError = 1;
				}
				break;
			};
			case 6: {
				if(fn > 0 && sn > 0){
					result = pow(fn, sn);
				}else{
					printf("Please enter a positive number !\n\n");
					isError = 1;
				}
				break;
			};
			default: break;
		}
	
		if(isError == 0){
			printf("Result = %2lf\n\n", result);
		}
	
	}
return 0;
}
