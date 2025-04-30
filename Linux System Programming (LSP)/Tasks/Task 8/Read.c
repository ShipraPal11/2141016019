/*NAME - Shipra Pal
REGISTRATION NO.-2141016019

Write a C program to perform the following file operations:
Open an existing file named "data.txt." If it doesn't exist, the program should create it.
Write the string "Hello, File Handling in C!" to the file.
Move the file pointer to the beginning of the file and read the contents back.
Print the contents read from the file to the console.
Close the file.*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp;
	char buffer[100];
	fp = fopen("data.txt", "w+");
	
	if (fp == NULL)
	{
    	perror("Error opening file");
    	return 1;
	}
	
	fputs("Hello, File Handling in C!", fp);
	rewind(fp);
	fgets(buffer, sizeof(buffer), fp);
	printf("File content: %s\n", buffer);
	fclose(fp);
	
	return 0;
}
