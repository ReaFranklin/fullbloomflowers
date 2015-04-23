#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


void Menu();	//prints the menu
void newprod();	
void searchprod();
void viewprod();
void cls();

struct item{
    int   id_num;
    char  name[20];
    float price;
	int	 quantity;
    char size_avail[3];
};

int main(void)
{	//The program will continue running until option 4 selected                                   
	int z;  
	
	//until the person logs in successfully
    	while(z != 1)
	{	z = login();	}
    	
    	Menu;
    	return 0;
}

int login()
{	//declare necessary variables
	char userName[] = "BridalBliss", uName[10];
	char passCode[] = "", pCode[10];
	//print login message
	printf("\t\tLOGIN\n\n");
	//get user name
	printf("Enter username: ");
	scanf("%s", uName);
	getchar();
	//get password
	printf("\nEnter password: ");
	scanf("%s", pCode);
	getchar();
	//if user name and password match
	if((strcmp(uName, userName)==0)&&(strcmp(pCode, passCode)==0))
	{	//print success message 
		printf("\n\n\nSuccessfully logged in!")
		//grant access
		return 1;
	}else
	{	//display sorry message 
		printf("\n\n\nNo match; try again!")
		//deny access
		return 0;
	}
}

void Menu()      //Main Menu to select option
{
    int choice;
    printf("\n**********************************************");
    printf("\n \t  MAIN MENU ");
    printf("\n**********************************************");
    printf("\n1. Add a new customer");
    printf("\n2. View a customer's preferences");
    printf("\n3. Add a new wedding planner");
    printf("\n4. View the list of planners");
    printf("\n5. Exit");
    printf("\n**********************************************");
    printf("\n\nPlease enter your option < 1 | 2 | 3 | 4 | 5 >: ");
    scanf("%d", &choice);
    getchar();

    switch(choice){
    case 1:
        addCustomer();
        break;
    case 2:
        viewCustomer();
        break;
    case 3:
        addPlanner();
        break;
    case 4:
        listPlanners();
        break;
    case 5:
        printf("\n*** Thanks for using the program! Goodbye. ***");
        exit(0);
        break;
    default:
        printf("\nOoops! Let's try that again with 1, 2, 3, 4, or 5 to exit.");
        break;
    }
}

void newprod()                        //Add new products to inventory
{   
    int x;
    struct item product;
	FILE* fPtr;

    printf("\n===Add New Product to Inventory===");
    printf("\n\nPlease enter the following information.");

	/*get product info*/
	//get product id
    printf("\n\nItem ID Number: ");
    scanf("%d", &product.id_num);
	getchar();
	//get product name
    printf("Name\t: ");
    scanf("%s", product.name);
	getchar();

    printf("Price\t: ");
    scanf("%f", &product.price);
	getchar();

    printf("Quantity\t: ");
    scanf("%d", &product.quantity);
	getchar();

    printf("Size\t: ");
    scanf("%s", &product.size_avail);
	getchar();

	/*save product info*/
	//open file for appending
	fPtr = fopen("inventory.txt", "a+");
	//check file opened successfully
	if(fPtr == NULL)
	{
		printf("\n\n Your Inventory File cannot found.");
		return;
	}
	//write product info to file
	fprintf(fPtr, "%d %s %.2f %d %s\n", product.id_num, product.name, product.price, product.quantity, product.size_avail);
	//close file
	fclose(fPtr);

	/*confirm product saved*/
    printf("\nYour product has been added to inventory.");
	getchar();

	cls();

}


void searchprod()
{
	/*declare necessary variables*/
	FILE* fPtr;
	struct item product;
	char name[20];
	int match = 0;

	/*get search criteria from user*/
	printf("What is the name of the item you're looking for: ");
	scanf("%s", name);
	getchar();

	/*search file for matching record*/
	//open file for reading
	fPtr = fopen("inventory.txt", "r");
	//check file opened successfully
	if(fPtr == NULL)
	{
		printf("\n\n Your Inventory File cannot found.");
		return;
	}
	//get a record from file
	do{
		//get a record from file
		fscanf(fPtr, "%d %s %.2f %d %s\n", product.id_num, product.name, product.price, product.quantity, product.size_avail);
		//compare record to search criteria
		match = strcmp(name, product.name);
	}while( (match != 0) && (!feof(fPtr)) );

	/*display results of search*/
	if(match == 0)
	{
		printf("%d %s %.2f %d %s\n", product.id_num, product.name, product.price, product.quantity, product.size_avail);
	}else
	{
		printf("\n\nNo match found for %s. Sowee!", name);
	}

}
void viewprod()
{}


void cls()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
