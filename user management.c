// program to develope an user management system

#include <stdio.h>
#include <string.h>
#include <unistd.h>		// to access terminal property

#define MAX_USERS 10		// no of maximum user can be register
#define CREDENTIAL_LENGTH 30	// length of character in credential fields

// structure of credentials
typedef struct {
	char username[CREDENTIAL_LENGTH];
	char password[CREDENTIAL_LENGTH];
} User;

// array of users of user type structure of size of max user
User users[MAX_USERS];
int user_count = 0;		// initial usercount

// function to register an user
void register_user(){
	
	// check if usercount has not reached to maximum
	if(user_count == MAX_USERS){
		printf("Maximum %d users are supported! No more registration allowed!!\n", MAX_USERS);
		return;
	}
	
	int new_index = user_count;	// getting the userindex
	printf("\nRegister a new User ");
	
	// take input through input_credentials function
	input_credentials(users[new_index].username, users[new_index].password);
	user_count++;
	printf("\nRegistration Successfull!\n");
	
}

// function to login
int login_user(){
	
	// temp arrays to store username and password
	char username[CREDENTIAL_LENGTH];
	char password[CREDENTIAL_LENGTH];
	
	// take input using input_credentials function
	input_credentials(username, password);
	
	int i;
	// loop to iterate over users
	for(i=0; i<user_count; i++){
		
		// compare username and password with existing user credentials
		if(strcmp(username, users[i].username) == 0 &&
		   strcmp(password, users[i].password) == 0){
		
		return i;	// return user index
		}
	}
	
	return -1;	// indicates failed login
}

// function to take input
int input_credentials(char* username, char* password){
	
	printf("\nEnter Username: ");
	fgets(username, CREDENTIAL_LENGTH, stdin);	// take input in file
	fix_fgets_input(username);	// remove \n
	
	printf("Enter Password: ");
	fgets(password, CREDENTIAL_LENGTH, stdin);	// take input in file
	fix_fgets_input(password);	// remove \n
	
return 0;	
}

// function to remove \n and fix fgets input 
int fix_fgets_input(char* string){
	int index = strcspn(string, "\n");
	string[index] = '\0';
	
return 0;
}

int main(){
	int option;
	int user_index;
	
	while(1){
		// print options
		printf("\nwelcome to User Management");
		printf("\n1. Register");
		printf("\n2. Login");
		printf("\n3. Exit");
		printf("\nSelect an option: ");
		scanf("%d", &option);
		getchar(); // consume extra enter
		
		// check option
		switch(option){
			case 1:
				register_user();
				break;
			case 2:
				user_index = login_user();	// store return value
				if(user_index >= 0){
					printf("\nLogin Successful! Welcome, %s!\n", users[user_index].username);
				}else{
					printf("\nLogin Failed! Incorrect Username or Password!!\n");
				}
				break;
			case 3:
				printf("\nExiting Program...\n");
				return 0;
				break;
			default:
				printf("Invalid Option! Please Try Again.\n");
				break;
		}
	}
	return 0;
}

