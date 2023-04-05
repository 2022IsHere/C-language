// File:	Exercise8.c
// Author(S):	Sebastian Sopola
// Description:	1. run program to allocate memory to add student information conserning name, id and gpa. 
//              2. Memory size is to be determined by the user. 
//              3. Fill student information according to user and check for uniqness of student ids. 
//              4. Feature update/modify functionality for student information. Calculate average of gpa of all students
//              5. Feature read from file 
//		6. Write to file

// PROGRAM CONSTRAINTS: WHEN TOTAL AMOUNT OF STUDENTS IS GIVEN, THERE IS NO GOING BACK ADDING MORE IN LATER DATE



#include "Student.h"





int main() {
	
	// CHECK THAT MY CODE USES ->id notation



	// questions for teacher:
	// 1. do we or do we not need to declare functions with parameters because sometimes I have to, why ? 
	// 2. what is with float numbers and 1.00000 precision presentation even if number is truly with 1.00 precision why to change it ?
	// 3. 

	

	testFunction();
	
	// check user choise, YES is same as true | NO is same as false
	if ( presentChoice() == true ) {
		
		int students = 0;
		
		// ask for the number of students
		students = totalStudents();
		
		// create struct with allocated memory of size students
		struct student *Pointer = createArray(students);
		
		// call function to fill memory with student information
		askStudentInformation(Pointer, students);
		
		// call function show what is inside allocated memory
		showStudentInformation(Pointer,students);
		
		// call function to allow student information modification
		changeStudentInfo(Pointer,students);
		
		// call function show what is inside allocated memory
		showStudentInformation(Pointer,students);
		
		// call function to calculate average of all GPAs
		float average = 0.0;
		average = averageGpa(Pointer, students);
		showAverage(average);
		
		// write student information to file
		writeStudentsToFile(Pointer,students);
		
		// read from file to check that new information was successfully added
		readFromFile();
		
		// release memory after everything
		free(Pointer);
	} else {
		readFromFile();
	}


	return 0;
}




















