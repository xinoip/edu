#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Person structure
typedef struct Person {
	char *id;
	char *name;
	char *surname;
	char *email;
} Person;

int determineType(char *str, const int size);
Person createPerson(char *id, char *name, char *surname, char *email);
int getLine(FILE *fp);
void readDataFromFile(Person *records, FILE *fp);
void writeDataToFile(Person *records, FILE *fp, const int recordSize);

//Returns numbers between 1-4 depending on "type" of string that is passed
//1 for id, 2 for name, 3 for surname, 4 email
int determineType(char *str, const int size) {

	/* Counters for upper case letters and digit characters */
	int countUpper = 0, countDigit = 0;

	/*	Main iteration for the string
		I checked the every character in string for determining the "type" of string
		If any of character in the string is '@' character then it is email
		For checking other types i counted the upper case letters and digit character */
	for(int i = 0; i < size; i++) {
		if(str[i] == '@') {
			return 4;
		} else if(str[i] >= 'A' && str[i] <= 'Z') {
			countUpper++;
		} else if(str[i] >= '0' && str[i] <= '9') {
			countDigit++;
		} 
	}

	/*	If upper case letters are equal to string length than string is all upper case
		Then it is  surname */
	if(strlen(str) == countUpper) {
		return 3;
	}

	/*	If digit character quantity equals to string length than string is all digits
		Then it is id */
	if(strlen(str) == countDigit) {
		return 1;
	}

	/* Other than all condition i can say that string is name */
	return 2;
}

//Function to create person and return it as a Person struct
Person createPerson(char *id, char *name, char *surname, char *email) {

	/* Person to return */
	Person r;
	/* Pointer to access */
	Person *rPtr = &r;

	/* Allocating datas that are passed to the function */
	rPtr->id = malloc(sizeof(char) * strlen(id));
	strcpy(rPtr->id, id);
	
	rPtr->name = malloc(sizeof(char) * strlen(name));
	strcpy(rPtr->name, name);
	
	rPtr->surname = malloc(sizeof(char) * strlen(surname));
	strcpy(rPtr->surname, surname);
	
	rPtr->email = malloc(sizeof(char) * strlen(email));
	strcpy(rPtr->email, email);
	
	return r;

}

//Function to get lines quantity of a desired file
int getLine(FILE *fp) {

	/* Line counter and temporary char buffer */
	int line = 1;
	char ch;

	fp = fopen("disorderedList.txt", "r");

	/* Every time that char buffer gets '\n' character increment the counter*/
	while(!feof(fp)) {
	 
	  ch = fgetc(fp);

	  if(ch == '\n') {

	    line++;

	  }

	}

	return line;

}

//Function reads data from desired file and puts the data into passed structure array
void readDataFromFile(Person *records, FILE *fp) {

	/* Initialize the file pointer to actual file */
	fp = fopen("disorderedList.txt", "r");
	if(fp == NULL) {
		printf("FILE NOT FOUND!\n");
		exit(0);
	}

	/* Index number for managing the structure array of persons*/
	int recordsIndex = 0;

	/* All 4 data types that will be filled and the buffer thats coming from file*/
	char *id, *name, *surname, *email, *tmp;

	tmp = malloc(sizeof(char));

	/* Read till the end of file, every loop will get 1 person from the file */
	while(!feof(fp)) {
		
		/* 4 datas for every line*/
		for(int i = 0; i < 4; i++) {
			
			/* Scan the file until hitting to a blank space */
			fscanf(fp, "%s", tmp);

			/* Switch statement to put the buffer into corresponding data variable */
			switch(determineType(tmp, strlen(tmp))) {
				case 1:
					id = malloc(sizeof(char) * strlen(tmp));
					strcpy(id, tmp);
				break;
				case 2:
					name = malloc(sizeof(char) * strlen(tmp));
					strcpy(name, tmp);
				break;
				case 3:
					surname = malloc(sizeof(char) * strlen(tmp));
					strcpy(surname, tmp);
				break;
				case 4:
					email = malloc(sizeof(char) * strlen(tmp));
					strcpy(email, tmp);
				break;
			}

			/* Reset the buffer */
			memset(tmp, '\0', strlen(tmp));

		}

		/* Create and add the person to array with gathered data */
		records[recordsIndex] = createPerson(id, name, surname, email);
		recordsIndex++;

		/* Reset the data variables for new persons */
		memset(id, '\0', strlen(id));
		memset(name, '\0', strlen(name));
		memset(surname, '\0', strlen(surname));
		memset(email, '\0', strlen(email));

	} //END OF WHILE

}

//Function writes data to desired file from the passed array of person structures
void writeDataToFile(Person *records, FILE *fp, const int recordSize) {

	/* Initialize the file pointer to actual file */
	fp = fopen("orderedList.txt", "w");

	/* Variables for spacing correctly while writing */
	int idLen, nameLen, surnameLen;

	/* For writing purpose i decided to give 12 spaces for every data */
	fprintf(fp, "ID  \t\tNAME\t\tSURNAME  \tEMAIL\n");

	/* Loop iterates through person array and writes 1 person in new file for every loop */
	for(int i = 0; i < recordSize; i++) {
		
		/* Initialize the variables with corresponding datas */
		idLen = strlen(records[i].id);
		nameLen = strlen(records[i].name);
		surnameLen = strlen(records[i].surname);

		/* 	To give 12 spaces to every data i used the variables idLen, nameLen, surName
			Using these variables i determined how many blank space is needed */
		fprintf(fp, "%s", records[i].id);
		for(int i = 0; i < 12 - idLen; i++) {
			fprintf(fp, " ");
		}	

		fprintf(fp, "%s", records[i].name);
		for(int i = 0; i < 12 - nameLen; i++) {
			fprintf(fp, " ");
		}

		fprintf(fp, "%s", records[i].surname);
		for(int i = 0; i < 12 - surnameLen; i++) {
			fprintf(fp, " ");
		}

		/* I don't need to add blank spaces for email because it is last data on table */
		fprintf(fp, "%s\n", records[i].email);

	}

}

int main() {

	/* Only file pointer that is used in the program */
	FILE *fp;

	/* Get the record size by counting lines and allocate the person array */
	int recordSize = getLine(fp);
	Person *records = malloc(sizeof(Person) * recordSize);

	/* Read data */
	readDataFromFile(records, fp);
	/* Write data */
	writeDataToFile(records, fp, recordSize);

}