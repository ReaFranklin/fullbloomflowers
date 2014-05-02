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
{						 //The program will continue running until option 4 selected                                   
    int z;  

    for(z=0;; z++)
	{
       Menu();
    }
    return 0;
}

void Menu()      //Main Menu to select option
{
    int choice;
    printf("\n**********************************************");
    printf("\n \t  MAIN MENU ");
    printf("\n**********************************************");
    printf("\n1. Add a new product");
    printf("\n2. Delete an existing product");
    printf("\n3. View the product list");
    printf("\n4. Exit");
    printf("\n**********************************************");
    printf("\n\nPlease enter your option < 1 | 2 | 3 | 4 >: ");
    scanf("%d", &choice);

    switch(choice){
    case 1:
        newprod();
        break;
    case 2:
        searchprod();
        break;
    case 3:
        viewprod();
        break;
    case 4:
        printf("\n*** Thanks for using the program! Goodbye. ***");
        exit(0);
        break;
    default:
        printf("\nError! Wrong Number is Entered\nPlease Try Again");
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

/*Searches inventory for an existing product*/
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
	//close file
	fclose(fPtr);

	/*display results of search*/
	if(match == 0)
	{
		printf("%d %s %.2f %d %s\n", product.id_num, product.name, product.price, product.quantity, product.size_avail);
	}else
	{
		printf("\n\nNo match found for %s. Sowee!", name);
	}

}

/*Displays all the inventory items on screen*/
void viewprod()
{
	/*declare necessary variables*/
	FILE* fPtr;
	struct item product;
	
	/*print all records to the screen*/
	//open file for reading
	fPtr = fopen("inventory.txt", "r");
	//check file opened successfully
	if(fPtr == NULL)
	{
		printf("\n\n Your Inventory File cannot found.");
		return;
	}
	//get a record from file
	while(!feof(fPtr))
	{
		//get a record from file
		fscanf(fPtr, "%d %s %.2f %d %s\n", product.id_num, product.name, product.price, product.quantity, product.size_avail);
		//print record to screen
		printf("%d %s %.2f %d %s\n", product.id_num, product.name, product.price, product.quantity, product.size_avail);
	}
	//close file
	fclose(fPtr);
}


void cls()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
