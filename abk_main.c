#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "read.h"

int main()
{
	int option , count;
	char ch;
	Address_Book addressbook;
	Read_Info readinfo ;
	do
	{
		/*select the options*/
		printf("1. Add Contact\n");
		printf("2. Edit Contact\n");
		printf("3. Search Contact\n");
		printf("4. Delete Contact\n");
		printf("5. Disply Contact\n");
		printf("6. Exit\n");

		printf("\n");
		printf("Please select an option: ");
		scanf("%d" ,&option);

		switch(option)
		{
			case 1:
				/*Enter the file name*/
				printf("Enter the file :");
				scanf("%s",readinfo.filename);
				
				/*function to insert data into addesssbook*/
				insert_data_to_addressbook(&addressbook ,&readinfo ,option);

				break;

			case 2:
				/*Enter the file*/
				printf("Enter the file :");
				scanf("%s",readinfo.filename);
				
				/*function callto edit contact*/
				edit_contact(&addressbook , &readinfo ,option);	
				break;

			case 3:

				/*Enter the file name*/
				printf("Enter the file :");
				scanf("%s",readinfo.filename);

				/*function to search data into addesssbook*/
				search_contact(&addressbook ,&readinfo ,option);
				break;

			case 4:

				/*Enter the file name*/
				printf("Enter the file :");
				scanf("%s",readinfo.filename);
				
				/*function call to delete contact*/
				delete_contact(&addressbook ,&readinfo ,option);
				break;

			case 5:

				/*Enter the file name*/
				printf("Enter the file :");
				scanf("%s",readinfo.filename);

				/*function to display the content*/
				display_data(&readinfo);
				break;

			case 6:
				return 0;

				break;

			/*chcek for default option*/
			default :
				printf("check option\n");
				break;
		}
		/*if you want to continue check for option*/
		printf("Do you want to continue :");
		scanf("\n%c",&ch);

	}while(ch == 'y');

	return 0;
}

