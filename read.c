#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "read.h"

/*function to add  the space */
void add_space(char *string )
{
	int len ,idx ;

	/*find the length of the string*/
	len = strlen(string);

	/*loop should run up to 32 charecter*/
	for(idx = len ; idx < 32 ; idx++)
	{
		/*insert space after character*/
		string[idx] = ' ' ;

	}
	/*string content ended with null*/
	string[idx] ='\0';
}

/*funtcion to read the data*/
int read_information(Read_Info *readinfo)
{
	int size , idx;
	char buff[32];
	switch(readinfo->n_option)
	{
		case 1:
			/*enter the name*/
			printf("Enter the Name :");
			scanf("%s",buff);

			/*add the space*/
			add_space(buff);

			size = strlen(buff);

			/*dynamic memory allocation*/
			readinfo->new_data = (char *)malloc(sizeof(char*)*size);

			/*copy the buffer content to new data*/
			strcpy(readinfo->new_data ,buff);
			break;

		case 2:

			/*enter the mail id*/
			printf("Enter the MailId :");
			scanf("%s",buff);

			/*add the space*/
			add_space(buff);

			size = strlen(buff);

			/*dynamic memory allocation*/
			readinfo->new_data = (char *)malloc(sizeof(char*)*size);

			/*copy the buffer content to new data*/
			strcpy(readinfo->new_data ,buff);
			break;

		case 3:

			/*enter the city*/
			printf("Enter the city :");
			scanf("%s",buff);

			/*add the space*/
			add_space(buff);
			size = strlen(buff);

			/*dynamic memory allocation*/
			readinfo->new_data = (char *)malloc(sizeof(char*)*size);

			/*copy the buffer content to new data*/
			strcpy(readinfo->new_data ,buff);
			break;

		case 4:

			/*enter the phone number*/
			printf("Enter the phone num :");
			scanf("%s",buff);

			/*check for error*/
			if (strlen(buff) != 10)
			{
				printf("invalied phone number\n");

				return 0;
			}
			else
			{
				idx = 0;
				/*check it numbers between 0 to 9*/
				while (buff[idx] >= 48 && buff[idx] <= 57)
				{
					idx++;
				}

			/*add the space*/
				add_space(buff);

				size = strlen(buff);

			/*dynamic memory allocation*/
				readinfo->new_data = (char *)malloc(sizeof(char*)*size);

			/*copy the buffer content to new data*/
				strcpy(readinfo->new_data ,buff);

			}
			break ;
	}
}
/*read the inputs to do the insert ,search ,edit ,delete and display*/
int read_data(Address_Book *addressbook , Read_Info *readinfo ,int n_option)
{
	int size ,idx ;
	char buff[32];
	switch(n_option)
	{
		case 1:
			/*read the name and store into buffer*/
			printf("Enter the Name :");
			scanf("%s",buff);

			/*add the space*/
			add_space(buff);

			size = strlen(buff);

			/*dynamic memoey allocation*/
			addressbook->name = (char *)malloc(sizeof(char*)*size);

			/*copy the buff content points to the addressbook*/
			strcpy(addressbook->name ,buff);

			/*enter the mail id*/
			printf("Enter the MailId :");
			scanf("%s",buff);

			/*add the space*/
			add_space(buff);

			size = strlen(buff);

			/*dynamic memoey allocation*/
			addressbook->mailid = (char *)malloc(sizeof(char*)*size);

			/*copy the buff content points to the addressbook*/
			strcpy(addressbook->mailid ,buff);


			printf("Enter the city :");
			scanf("%s",buff);

			/*add the space*/
			add_space(buff);

			size = strlen(buff);

			/*dynamic memoey allocation*/
			addressbook->city = (char *)malloc(sizeof(char*)*size);

			/*copy the buff content points to the addressbook*/
			strcpy(addressbook->city ,buff);

			printf("Enter the phone num :");
			scanf("%s",buff);


			size = strlen(buff);

			if (strlen(buff) != 10)
			{
				printf("invalied phone number\n");

				return 0;
			}
			else
			{
				idx = 0;
				while (buff[idx] >= 48 && buff[idx] <= 57)
				{
					idx++ ;
				}

			/*add the space*/
				add_space(buff);

			/*dynamic memoey allocation*/
				addressbook->phone = (char *)malloc(sizeof(char*)*size);

			/*copy the buff content points to the addressbook*/
				strcpy(addressbook->phone ,buff);

			}

			break ;

		case 2 :

			/*enter the name*/
			printf("Enter the Data :");
			scanf("%s",buff);

			/*add the space*/
			add_space(buff);

			size = strlen(buff);

			/*dynamic memoey allocation*/
			readinfo->iname = (char *)malloc(sizeof(char*)*size);

			/*copy the buff content points to the addressbook*/
			strcpy(readinfo->iname ,buff);

			printf("Edit is done by :\n\t 1.Name\n\t 2.Mailid\n\t 3.city\n\t 4.phone\n");
			scanf("%d",&readinfo->n_option);

			read_information( readinfo);
			break;


		case 3:
			/*enter the options for search*/
			printf("Search is done by :\n\t 1.Name\n\t 2.Mailid\n\t 3.city\n\t 4.phone\n");
			scanf("%d",&readinfo->n_option);
			
			/*functio for read the information*/
			read_information( readinfo);

			break;


		case 4:
			/*Enter the name*/
			printf("Enter the Name :");
			scanf("%s",buff);

			/*add the space*/
			add_space(buff);

			size = strlen(buff + 1);

			/*dynamic memoey allocation*/
			readinfo->iname = (char *)malloc(sizeof(char*)*size);

			/*copy the buff content points to the addressbook*/
			strcpy(readinfo->iname ,buff);

			break;
	}
}





