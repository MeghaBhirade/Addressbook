#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "read.h"

/*function to read inputs to delete*/
int read_inputs_delete(Address_Book *array ,Read_Info *readinfo ,int *count)
{

	int idx ;
	char temp[2] ,buff[32];

	for (idx = 0 ; feof(readinfo->fptr) == 0; idx++)
	{
		(*count)++;	

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
	fclose(readinfo->fptr);
}
/*function to skip the array positions if newly entered data is identical*/
int skip_position(Address_Book *array ,Read_Info*readinfo ,int count)
{
	int idx;
	char delimeter[5] = "//" ;
	char delimeter1 = '\n' ;

	/*open the file into writemode*/
	readinfo->fptr = fopen(readinfo->filename,"w");

	/*Error handling*/
	if (readinfo->fptr == NULL)
	{
		perror("fopen");

		fprintf(stderr ,"ERROR :unable to open file %s\n",readinfo->filename);
		return 0;
	}

	for (idx = 0; idx < (count-1) ;idx++)
	{
		/*compare the array content and newly entered data
		 if it is identical skip that content and write remaining content into file*/
		if (strcmp(readinfo->iname ,array[idx].name) == 0 )
		
			continue ;

		/*write the name*/
		fwrite(array[idx].name , 1 , 32 ,readinfo->fptr );
		fwrite(delimeter , 1 , 2 , readinfo->fptr);

		/*write the mailid*/
		fwrite(array[idx].mailid , 1 , 32 ,readinfo->fptr );
		fwrite(delimeter , 1 , 2 , readinfo->fptr);

		/*write the city*/
		fwrite(array[idx].city , 1 , 32 ,readinfo->fptr );
		fwrite(delimeter , 1 , 2 , readinfo->fptr);

		/*wrtite the phone number*/
		fwrite(array[idx].phone , 1 , 32 ,readinfo->fptr );
		fwrite(&delimeter1 , 1 , 1 , readinfo->fptr);
	}
		/*close the file*/
		fclose(readinfo->fptr);
	
}
/*function to delete the contact*/
int delete_contact(Address_Book *addressbook , Read_Info *readinfo ,int option)
{
	int limit = 20;
	int count = 0;
	Address_Book array[limit];
	
	/*function call to read inputs from user*/
	read_data(addressbook ,readinfo ,option);

	/*open the file into read more*/
	readinfo->fptr = fopen(readinfo->filename,"r");

	/*error handling*/
	if (readinfo->fptr == NULL)
	{
		perror("fopen");

		fprintf(stderr ,"ERROR :unable to open file %s\n",readinfo->filename);
		return 0;
	}
	/*function to read inputs for delete*/
	read_inputs_delete(array ,readinfo ,&count);

	/*function call to skip the array position*/
    skip_position(array ,readinfo ,count);

	
}
