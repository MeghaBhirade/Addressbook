#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "read.h"

/*function to read inputs to edit data*/
int read_inputs_edit(Address_Book *array ,Read_Info *readinfo, int option, int limit)
{

	int byte_read , idx , jdx ,count = 0;
	char temp[2] ,buff[32];

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
	fseek(readinfo->fptr, 0L, SEEK_SET);
}

/*function to find array position*/
int arr_position(Address_Book *array ,Read_Info *readinfo ,int limit)
{
	int idx;

	for (idx =0 ; idx < limit ; idx++)
	{
		/*compare the array content and newly enteres data
		 if is identical break loop and returns the index*/
		if (strcmp(readinfo->iname, array[idx].name) == 0)
		{
			break;
		}
	}
	/*return index*/
	readinfo->array_pos = idx;
}

/*function to write new content*/
int write_new_data(Address_Book *array ,Read_Info *readinfo ,int limit )
{
	int idx = 0 ;
	long position;
	char delimeter[5] = "//";
	char newline  = '\n';

	arr_position(array ,readinfo , limit);

	switch(readinfo->n_option)
	{
		case 1:
			/*set position for name and enter new data*/
			position = (readinfo->array_pos *134) + readinfo->array_pos;
			fseek(readinfo->fptr ,position ,SEEK_SET);
			fwrite(readinfo->new_data  , 1 , 32 ,readinfo->fptr);
			break;

		case 2:
			/*set position for mailid and enter new data*/
			position = (readinfo->array_pos *134) + 32 + readinfo->array_pos;
			fseek(readinfo->fptr ,position ,SEEK_SET);
			fwrite(&delimeter , 1 , 2 , readinfo->fptr);
			fwrite(readinfo->new_data , 1 , 32 ,readinfo->fptr);
			break;

		case 3:
			/*set position for city and enter new data*/
			position = (readinfo->array_pos *134) + 66 + readinfo->array_pos;
			fseek(readinfo->fptr , position ,SEEK_SET);
			fwrite(&delimeter , 1 , 2 , readinfo->fptr);
			fwrite(readinfo->new_data , 1 ,32 ,readinfo->fptr);
			break;

		case 4:
			/*set position for phone num and enter new data*/
			position = (readinfo->array_pos *134) + 100 + readinfo->array_pos ;
			fseek(readinfo->fptr, position , SEEK_SET);
			fwrite(&delimeter , 1 , 2 , readinfo->fptr);
			fwrite(readinfo->new_data , 1 , 32 ,readinfo->fptr);
			fwrite(&newline , 1 , 1 , readinfo->fptr);
			break;
	}
}
/*main function to edit contact*/
int edit_contact(Address_Book *addressbook , Read_Info *readinfo ,int option)
{
	int limit = 20;

	Address_Book array[limit];

	/*function call to read the data from user*/
	read_data(addressbook ,readinfo ,option);

	/*open the file in read+ mode*/
	readinfo->fptr = fopen(readinfo->filename,"r+");

	/*error handling*/
	if (readinfo->fptr == NULL)
	{
		perror("fopen");

		fprintf(stderr ,"ERROR :unable to open file %s\n",readinfo->filename);
		return 0;
	}

	/*function call to get inputts to edit*/
	read_inputs_edit(array ,readinfo , option ,limit);

	/*function call to write new ccontent*/
	write_new_data(array ,readinfo , limit);

	/*close the file pointer*/
	fclose(readinfo->fptr);
}

