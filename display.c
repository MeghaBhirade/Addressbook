#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "read.h"

/*function to print the addressbook*/
void print_addressbook(Address_Book *array ,int count)
{
	int idx;

	for (idx = 0 ; idx < count ; idx++)
	{
		printf("*********************************\n");
		/*print the name*/
		printf("Name : %s\n",array[idx].name);

		/*print the mail id*/
		printf("Mail : %s\n",array[idx].mailid);

		/*print the city*/
		printf("city : %s\n",array[idx].city);

		/*print the phonenumber*/
		printf("phone : %s\n",array[idx].phone);
		printf("*********************************\n");
	}
}

/*funtcion to display the file content*/
int display_data(Read_Info *readinfo)
{

	int byte_read , idx ,count = 0;
	Address_Book array[100];
	char temp[2] ,buff[32];

	/*open the file into read mode*/
	readinfo->fptr = fopen(readinfo->filename,"r");

	/*error handling*/
	if (readinfo->fptr == NULL)
	{
		perror("fopen");

		fprintf(stderr ,"ERROR :unable to open file %s\n",readinfo->filename);
		return 0;
	}

	/*display the content upto end of file*/
	for (idx = 0 ; feof(readinfo->fptr) == 0; idx++)
	{
	count++;	
	/*store name*/	
    fread(buff , 1 , 32 ,readinfo->fptr);
	array[idx].name = malloc(strlen(buff));
	strcpy(array[idx].name ,buff);

	/*store mail id*/
	fread(temp ,1 ,2 ,readinfo->fptr);
    fread(buff , 1 , 32 ,readinfo->fptr);
	array[idx].mailid = malloc(strlen(buff));
	strcpy(array[idx].mailid ,buff);

	/*store city*/
	fread(temp ,1 ,2 ,readinfo->fptr);
    fread(buff , 1 , 32 ,readinfo->fptr);
	array[idx].city = malloc(strlen(buff));
	strcpy(array[idx].city ,buff);
	
	/*store phone*/
	fread(temp ,1 ,2 ,readinfo->fptr);
    fread(buff , 1 , 32 ,readinfo->fptr);
	array[idx].phone = malloc(strlen(buff));
	strcpy(array[idx].phone ,buff);
	fread(temp ,1 ,1 ,readinfo->fptr);

	}

	/*function to print address book data*/
	print_addressbook(array ,count - 1);

	/*close the file*/
	fclose(readinfo->fptr);

}




