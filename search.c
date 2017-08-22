#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "read.h"

/*function to search data by name*/
int search_by_name(Address_Book *array , Read_Info *readinfo ,int count)
{
	int idx , flag = 1;

	for(idx = 0; idx < count; idx++)
	{
		/*if the entered data and array content is similar then 
		 return the index*/
		if (strcmp(array[idx].name ,readinfo->new_data) == 0)
		{
			flag = 0;
			return idx;
		}
	}
	if (flag)

		return -1;
}

/*function to search data by mailid*/
int search_by_mailid(Address_Book *array , Read_Info *readinfo ,int count)
{
	int idx ,flag = 1;

	for(idx = 0; idx < count; idx++)
	{
		/*if the entered data and array content is similar then 
		 return the index*/
		if (strcmp(array[idx].mailid ,readinfo->new_data) == 0)
		{
			flag = 0;
			return idx;
		}
	}
	if (flag)

		return -1;
}


/*function to search data by city*/
int search_by_city(Address_Book *array , Read_Info *readinfo ,int count)
{
	int idx  ,flag = 1;

	for(idx = 0; idx < count; idx++)
	{
		/*if the entered data and array content is similar then 
		 return the index*/
		if (strcmp(array[idx].city ,readinfo->new_data) == 0)
		{
			flag = 0;
			return idx;
		}
	}
	if (flag)

		return -1;
}


/*function to search data by phone*/
int search_by_phone(Address_Book *array , Read_Info *readinfo,int count )
{
	int idx ,flag = 1;

	for(idx = 0; idx < count; idx++)
	{
		/*if the entered data and array content is similar then 
		 return the index*/
		if (strcmp(array[idx].phone ,readinfo->new_data) == 0)
		{
			flag = 0;
			return idx;
		}
	}
	if (flag)

		return -1;
}

/*function to print searched data*/
void print_search_data(Address_Book *array ,int idx)
{
	/*print the name*/
	printf("Name :%s\n",array[idx].name);

	/*print the mailid*/
	printf("Mail :%s\n",array[idx].mailid);

	/*print the city*/
	printf("City :%s\n",array[idx].city);

	/*print the phone number*/
	printf("Phone :%s\n",array[idx].phone);
}


/*function to search the data*/
int search_data(Address_Book *array ,Read_Info *readinfo ,int count)
{
	int jdx ;

	switch(readinfo->n_option)
	{
		case 1:
		/*if returned index is -1 print name is not found*/	
		jdx = search_by_name(array ,readinfo ,count);

		if (jdx < 0)
		{
			printf("Name is not found\n");
			return -1;
		}
		break;


		case 2:

		/*if returned index is -1 print mail id is not found*/	
		jdx = search_by_mailid(array ,readinfo , count);
		if (jdx < 0)
		{
			printf("Mailid is not found\n");
			return -1;
		}
		break;


		case 3:
		/*if returned index is -1 print city is not found*/	
		jdx = search_by_city(array ,readinfo ,  count);
		if (jdx < 0)
		{
			printf("City is not found\n");
			return -1;
		}
		break;

		case 4:
		jdx = search_by_phone(array ,readinfo , count);
		if (jdx < 0)
		{
			printf("Phone is not found\n");
			return -1;
		}
		break;
	}
	/*function call to print data*/
	print_search_data(array ,jdx);
}

/*function to search the contact in addressbook*/
int search_contact(Address_Book *addressbook ,Read_Info *readinfo, int option)
{

	int byte_read , idx , jdx ,count = 0;
	Address_Book array[100];
	char temp[2] ,buff[32];
	
	/*function call to read the data from user*/
	read_data(addressbook ,readinfo ,option);

	/*open the file in read mode*/
	readinfo->fptr = fopen(readinfo->filename,"r");

	/*error handling*/
	if (readinfo->fptr == NULL)
	{
		perror("fopen");

		fprintf(stderr ,"ERROR :unable to open file %s\n",readinfo->filename);
		return 0;
	}

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
	/*function call to search data*/
	search_data(array ,readinfo ,count -1);

	/*close the file*/
	fclose(readinfo->fptr);

}

