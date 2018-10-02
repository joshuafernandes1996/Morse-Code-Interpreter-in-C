/* Author: Denver(1605) and Joshua(1615)
   Program: To Convert Morse code to English
   Date created: Yesterday
   date Modified: Today
*/
#include<stdio.h>
#include<stdlib.h>
#include"morse.h"

int compare(int x,int y) // comparing the associated numbers
{
	if(x==y)
		return 0;
	if(x<y)
		return -1;
	if(x>=y)
		return 1;
}
void print(char x) //to print
{
	printf("%c",x);
	return;
}
int main()
{ 	
	char morse[100]; //stores the codes from the user
	int f;
	char english[100]; //stores the coverted message letter by letter
	int i;
	Listtype List;
	List=Create(compare,print); //creating the tree
	int choice;

//below associates each letter to a number
  char letter[]={'*','E','T','I','A','N','M','S','U','R','W','D','K','G','O','H','V','F','*','L','*','P','J','B','X','C','Y','Z','Q','*','*'};
  int number[]={1000,900,1100,800,950,1010,1110,700,810,940,960,1005,1020,1105,2000,600,705,805,815,935,945,955,965,1003,1009,1015,1025,1103,1109,1900,3000};
  
  				
					for(i=0;i<=30;i++)      // inserting into the tree
				List=Insert(List,number[i],letter[i]); 

						intro(); //intro function call

do
	{
		printf("\n-------------------------------------------------------------------------------------------------------");
		printf("\n====================MORSE CODE CONVERTOR TO ENGLISH====================\n\n1:Convert\n2.Exit\n");
		printf("(Note: If * appears the input is wrong)\n(Note: Seperate your words by / and alphabets by _ )");
		printf("\nEnter Your Choice: ");
		scanf("%d",&choice);
		if(isdigit(choice))
		{
			printf("\nEnter Valid Choice");
		
		}
		else
		{
		switch(choice)
		{
			
				
			case 1:	printf("\nEnter the Morse code:");
				scanf("%s",morse);
				interpret(List,morse,english);
				printf("\nEquivalent English Message: %s\n",english);
				break;
				
			case 2: terminate();
				break;
				
			default:
				printf("\nInvalid Choice\n");
		}
		}
	
	}while(choice!=2);
	

return 0;
}
