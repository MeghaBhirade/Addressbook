#ifndef ADDRESS_BOOK
#define ADDRESS_BOOK

/*addressbook structuer declaration*/
typedef struct Address_Book
{
	char *name ;

	char *mailid;

	char *phone;

	char *city;
}Address_Book;

/*structure declaration for reading information*/
typedef struct Read_Info
{
	char filename[30];

	FILE *fptr;

	int n_option ;

	char *new_data;

	char *iname;

	int   array_pos;

}Read_Info;

/*function to add the space*/
void add_space(char *string );

/*function to read the data from user*/
int read_data(Address_Book *addressbook ,Read_Info*readinfo , int n_option);

/*function to insert the data into address book*/
int insert_data_to_addressbook(Address_Book *addressbook ,Read_Info*readinfo ,int option);

/*function to search the contact in addressbook*/
int search_contact(Address_Book *addressbook ,Read_Info *readinfo, int option);

/*display the content of addressbook*/
int display_data(Read_Info *readinfo);

/*function to edit the contact from addressbook*/
int edit_contact(Address_Book *addressbook , Read_Info *readinfo ,int option);

/*function to delete the contact*/
int delete_contact(Address_Book *addressbook , Read_Info *readinfo ,int option);
#endif
