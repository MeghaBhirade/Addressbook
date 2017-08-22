#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "read.h"

/*function to insert data into addressbook*/
int insert_data_to_addressbook(Address_Book *addressbook ,Read_Info*readinfo ,int option)
{
	char* delimeter = "//" ;
	char delimeter1 = '\n' ;

	/*open the file into append mode*/
	readinfo->fptr = fopen(readinfo->filename,"a+");

	/*error handling*/
	if (readinfo->fptr == NULL)
	{
		perror("fopen");

		fprintf(stderr ,"ERROR :unable to open file %s\n",readinfo->filename);
		return 0;
	}

		/*function to read the content fro user*/
		read_data(addressbook ,readinfo , option); 

		/*write the name*/
		fwrite(addressbook->name , 1 , 32 ,readinfo->fptr );
		fwrite(delimeter , 1 , 2 , readinfo->fptr);

		/*write the mailid*/
		fwrite(addressbook->mailid , 1 , 32 ,readinfo->fptr );
		fwrite(delimeter , 1 , 2 , readinfo->fptr);

		/*write the city*/
		fwrite(addressbook->city , 1 , 32 ,readinfo->fptr );
		fwrite(delimeter , 1 , 2 , readinfo->fptr);

		/*wrtite the phone number*/
		fwrite(addressbook->phone , 1 , 32 ,readinfo->fptr );
		fwrite(&delimeter1 , 1 , 1 , readinfo->fptr);

		/*close the file*/
		fclose(readinfo->fptr);

}

