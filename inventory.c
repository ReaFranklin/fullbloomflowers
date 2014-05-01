#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


void Menu();	//prints the menu
void newprod();	
void deleteprod();
void viewprod();
void cls();

struct item{
    int   id_num;
    char  name[20];
    float price;
	int	 quantity;
    char size_one;
	char size_two;
    char size_three;
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
    printf("\n1. Add a new porduct");
    printf("\n2. Delete an existing product");
    printf("\n3. View the product list");
    printf("\n4. Exit");
    printf("\n**********************************************");
    printf("\nPlease enter your option < 1 | 2 | 3 | 4 >: ");
    scanf("%d", &choice);

    switch(choice){
    case 1:
        newprod();
        break;
    case 2:
        deleteprod();
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
	//open file for appending
	FILE* fPtr = fopen("inventory.txt", "a+");

    printf("\n===Add New Product to Inventory===");
    printf("\n\nPlease enter the following information.");

	/*get product info*/
	//get product id
    printf("\n\n Item ID Number: ");
    scanf("%d", &product.id_num);
	getchar();
	//get product name
    printf("Name\t: ");
    scanf("%s", &product.name);
	getchar();

    printf("Price\t: ");
    scanf("%f", &product.price);
	getchar();

    printf("Quantity\t: ");
    scanf("%d", &product.quantity);
	getchar();

    printf("Size\t: ");
    scanf("%c", &product.size_one);
	getchar();

	printf("Size\t: ");
    scanf("%c", &product.size_two);
	getchar();

	printf("Size\t: ");
    scanf("%c", &product.size_three);
	getchar();

	/*save product info*/
	//check file opened successfully
	if(fPtr == NULL)
	{
		printf("\n\n Your Inventory File cannot found.");
		return;
	}
	//write product info to file
	fprintf(fPtr, "%d %c %f %d %c %c %c", product.id_num, product.name, product.price, product.quantity, product.size_one, product.size_two, product.size_three);
	//close file
	fclose(fPtr);

	/*confirm product saved*/
    printf("\nYour product has been added to inventory.");
	getchar();

	cls();

}


void deleteprod(){}
void viewprod(){}


void cls()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
