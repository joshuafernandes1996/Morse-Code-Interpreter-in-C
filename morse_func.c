/* Author: Denver(1605) and Joshua(1615)
   Program: To Convert Morse code to English
   Date created: Yesterday
   date Modified: Today
*/
#include<stdio.h>
#include<stdlib.h>
#include"morse.h"

void intro()
{
 printf("======================================================================\n");
 printf("||            -------------------------------------------------     ||\n");
 printf("||            |   ROLLNO:1605   | Author: Denver Da Rocha   |       ||\n");
 printf("||            |   ROLLNO:1615   | Author: Joshua Fernandes  |       ||\n");
 printf("||            -------------------------------------------------     ||\n");
 printf("======================================================================\n");
}

Listtype Create(int (*compare)(int ,int ),void (*print)(char)) //creating the tree
{
	Listtype List;
	List=(Listtype)malloc(sizeof(headertype));
	if(List==NULL)
	{
		printf("\nSpace could not be allocated");
		exit(1);
	}
	List->root=NULL;
	List->count=0;
	List->compare=compare;
	return List;
}



Listtype Insert(Listtype List,int number, char letter) //inserting into the tree
{
	NodePtrType parent,cur,newnode;
	parent=NULL;
	cur=List->root;
	newnode=(NodePtrType)malloc(sizeof(NodeType));
	if(newnode==NULL)
	{
		printf("\nSpace could not be allocated");
		exit(1);
	}
	else
	{
		newnode->info=letter;
		newnode->data=number;
		newnode->dot=NULL;
		newnode->dash=NULL;
	}
	if(List->root==NULL)
	{
		List->root=newnode;
	}
	else
	{
		while(cur!=NULL)
		{
			if((List->compare)(cur->data,number)<=0)
			{
				parent=cur;
				cur=cur->dash;
			}	
			else
			{
				parent=cur;
				cur=cur->dot;
			}
		}
	
		if((List->compare)(parent->data,number)<=0)
			parent->dash=newnode;
		else
			parent->dot=newnode;
	}
	
	List->count++;
	return List;
}







void interpret(Listtype List,char morse[],char english[]) //interpretation function
{
	int i=0;
	int c=0;
	NodePtrType temp;
 
 	while(morse[i]!='\0')
 	{
 	temp=List->root;
 		while(morse[i]!='_')
 		{
 			if(morse[i]=='.')
 				temp=temp->dot;
			else if(morse[i]=='-')
				temp=temp->dash;
			else if(morse[i]=='\0')
				break;
			else if(morse[i]=='/')
				break;
				i++;
			}
		english[c]=temp->info;
		if(morse[i]=='/')
		{
		c++;
		english[c]=' ';
		}
		c++;
		i++;
	}

english[c]='\0';
}









void terminate()
{
		printf("\n\n<----------Thank You For Using The Convertor---------->\n\n");
}











