// File:	Student.c
// Author(S):	Sebastian Sopola
// Description:	functions for -> 2. Memory size is to be determined by the user. 
//              		 3. Fill student information according to user and check for uniqness of student ids. 
//              		 4. Feature update/modify functionality for student information. Calculate average of gpa of all students
//              		 5. Feature read from file 
//				 6. Write to file



#include "Student.h"


// initialize struct with variables we want to store about students
struct student {
	char name[NAMESIZE];
	int id;
	float gpa;

};

bool presentChoice() {

	// variable to keep asking for yes or no until it is given
	bool answer = false;

	// initialize choice which will be then passed to determine which path to take
	bool choice = false;
	printf("Would you like to add student information otherise you are directed to read student information from file? YES|NO \n");
	
	// read user input
	char input[ANSWERSIZE];
	
	// loop till user answers yes or no
	while ( answer == false ) {
		// check for user input as a string
		if ( fgets(input, ANSWERSIZE, stdin) != NULL ) {
			//printf("string is [%s] and lenght [%ld]\n\n",input, strlen(input));
		
			// take newline character out of string, IMPORTANT!
			input[strcspn(input, "\n")] = '\0';
			
			// if answer is yes, result of method is 0
			if ( strcmp(input,"yes") == 0 ) {
				choice = true;
				answer = true;
				
			// if answer is no, result of method is 0
			} else if ( strcmp(input,"no") == 0 ) {
				choice = false;
				answer = true;
				
			// if answer is not one of the given options
			} else {
				while ( getchar() != '\n' );
				printf("You didn't answer yes or no. Please enter yes or no: \n");
				
			}
			
		} else {
			while ( getchar() != '\n' );
			printf("Error reading input. Please try again: \n");
		}
	}
	return choice;
}


   
// function to ask for the number of students
int totalStudents(){

	int total = 0;
	
	// status to allow the number of students to be passed on when correctly given
	bool status = false;
	
	while ( status == false ) {
	
		// ask the number of students to be inserted
		printf("Enter the number of students: \n");
		if ( scanf("%d", &total) == 1 ) {
			status = true;
			while ( getchar() != '\n' );
			
		// when the amount is incorrectly given, this path is taken
		} else {
			printf("Traceback ( most recent call last):\n");
			printf("File: 'Student.c', line 82, in <module>\n");
			printf("   raise: The number of students wasn't inserted correctly\n\n");
			while ( getchar() != '\n' );
		}
	
	}
	
	return total;
}


// function to create array and return pointer to allocated memory array for further use
struct student* createArray( int totalStudents ) {

	// create struct memory pointer
	struct student *memoryPointer = NULL;
	
	// allocate memory for array of structs of fixed size of 20 students, later SIZE Will be asked from user !!!
	memoryPointer = ( struct student *) malloc(totalStudents * sizeof(struct student) );
	
	// check successfulity of memory allocation
	if ( memoryPointer == NULL ) {
		printf("\n\nTraceback ( most recent call last):\n");
		printf("File: 'Student.c', line 107, in <module>\n");
		printf("   raise: Memory allocation was unsuccessfull due to unkown error\n");
		return 0;
	}
	
	return memoryPointer;
}


// function to ask student information and check that it fits program requirements
int askStudentInformation(struct student *arrayPointer, int totalStudents ) {
    int id = 0;
    int index = 0;
    float gpa = 0.0;
    char name[NAMESIZE];
    bool duplicateID = false;

    // ask for user input
    for ( index = 0; index < totalStudents; index++) {
        printf("Enter name of student %d: ", index + 1);
        scanf("%30s", name);
        
        // loop for id till program gets correct one
        do {
            printf("Enter ID of student %d (6 digits): ", index + 1);
            
            // check that inserted id is in program requirements
            if (scanf("%d", &id) != 1 || id < 100000 || id > 999999) {
                printf("Error: ID must be 6 digits.\n");
                while (getchar() != '\n');
                continue;
            }

            duplicateID = false;
            
            // loop for added students number of times
            for ( int index2 = 0; index2 < index; index2++) {
            
            	// in case any of added students' id is newly given id, pop up error message
                if (arrayPointer[index2].id == id) {
                    printf("Error: ID %d is already in use. Please enter a new ID.\n", id);
                    duplicateID = true;
                    break;
                }
            }
            
            // in case duplicateID was discovered, continue
            // else: break the loop to ask for gpa next
            if (duplicateID) {
                continue;
            }
            break;
            
        // loop indefinetly until program makes out of the loop upon no id duplicates
        } while (1);

	// loop for gpa till program gets correct one
        do {
            printf("Enter GPA of student %d (between 0.00 and 5.00): ", index + 1);
            
            // check that inserted gpa fits program requirements
            if (scanf("%f", &gpa) != 1 || gpa < 0.00 || gpa > 5.00) {
                printf("Error: GPA must be between 0.00 and 5.00.\n");
                while (getchar() != '\n');
                continue;
            }
            break;
            
       	// loop indefinetly until program makes out of the loop upon correct gpa 
        } while (1);

        // in case everything is fine, add student name,id and gpa to struct at correct index
        arrayPointer[index].id = id;
        arrayPointer[index].gpa = gpa;
        strcpy(arrayPointer[index].name, name);
    }
    // return 0 to mark that this function ran successfully
    return 0;
}

// function to write student information to file
int writeStudentsToFile( struct student *arrayPointer, int totalStudents ) {

	FILE *filePointer = NULL;
	
	// open the file
	filePointer = fopen("StudentInformation.txt","a");
	
	// check was file opened correctly
	if ( filePointer == NULL ) {
		printf("There was issue opening the file...\n");
		exit(1);
	}
	
	// loop through all students to add them to file
	for (int index = 0; index < totalStudents; index++) {
		fprintf(filePointer, "Name: %s, ID: %d, GPA: %.2f\n", 
		(arrayPointer + index)->name, 
		(arrayPointer + index)->id, 
		(arrayPointer + index)->gpa);
		        
        }
	
	fclose(filePointer);
	
	// return 0 to mark that this function ran successfully
	return 0;
}



// function to show student information
void showStudentInformation( struct student *memoryPointer, int totalStudents ) {
	for ( int index = 0; index < totalStudents; index++) {
		printf("Name [%s] ID [%d] GPA [%.2f]\n",(memoryPointer + index)->name, 
							(memoryPointer + index)->id,
							(memoryPointer + index)->gpa);
	}
	printf("\n\n");
}



// function read information from file if user so chooses
void readFromFile() {
	FILE *readFilePointer = NULL;
	char string[NAMESIZE];
	readFilePointer = fopen("StudentInformation.txt", "a+");
	
	// check is file reading successfull
	if ( readFilePointer == NULL ) {
		printf("Traceback ( most recent call last):\n");
		printf("File: 'Student.c', line 239, in <module>\n");
		printf("   raise: Student information could not be read from file due to unknows issue\n\n");
	}
	
	// loop through file in 50 character cycles, while we don't meet end of file
	while ( fgets(string, NAMESIZE, readFilePointer ) != NULL ) {
		printf("%s", string);
	}
	
	// close file after it is read
	fclose(readFilePointer);
	
}


// function to update student information
int changeStudentInfo(struct student *memoryPointer, int totalStudents) {

    int studentID = 0;
    int index = 0;

    // loop to ask for student ID until a valid ID is entered
    while (true) {
        // ask user for the ID of the student to update
        printf("Enter the ID of the student to update: ");
        if (scanf("%d", &studentID) == 1) {
            // search for the student with the given ID
            for (index = 0; index < totalStudents; index++) {
                if ((memoryPointer + index)->id == studentID) {
                    // student found, exit the loop
                    break;
                }
            }
            if (index < totalStudents) {
                // student found, exit the loop
                break;
            } else {
                printf("Error: Student with ID %d not found.\n", studentID);
            }
        } else {
            // clear input buffer if invalid input is entered
            while (getchar() != '\n');
            printf("Invalid input. Please enter a valid student ID.\n");
        }
    }

    // ask user for the updated information
    printf("Enter the updated name of the student: ");
    scanf("%30s", (memoryPointer + index)->name);

    // ask user for the updated GPA of the student
    float updatedGPA = 0;
    while (true) {
        printf("Enter the updated GPA of the student (between 0.00 and 5.00): ");
        if (scanf("%f", &updatedGPA) == 1 && updatedGPA >= 0.00 && updatedGPA <= 5.00) {
            break;
        }
        // clear input buffer if invalid input is entered
        while (getchar() != '\n');
        printf("Invalid input. Please enter a valid GPA between 0.00 and 5.00.\n");
    }
    (memoryPointer + index)->gpa = updatedGPA;

    printf("Student information updated.\n");
    return 0;
}


float averageGpa( struct student *memoryPointer, int totalStudents ) {
	float average = 0.0;
	
	for ( int index = 0; index < totalStudents; index++) {
		average = average + (memoryPointer + index)->gpa;
	}

	average = average / totalStudents;
	
	return average;
}


void showAverage( float average ) {

	printf("Average of all GPAs is [%.2f]! Hurraa!\n\n",average);

}


void testFunction() {

	printf("Hi, I am going to get you !\n\n");


}















