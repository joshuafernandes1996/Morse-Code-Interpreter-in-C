/* Author: Denver(1605) and Joshua(1615)
   Program: To Convert Morse code to English
   Date created: Yesterday
   date Modified: Today
*/
typedef struct Node
{
	char info;
	int data;
	struct Node* dot;
	struct Node* dash;
}NodeType;

typedef NodeType * NodePtrType;

typedef struct header
{
	int count;
	struct node* root;
	int (*compare)(int,int);
	int (*print)(char);
}headertype;

typedef headertype* Listtype;


void intro();
Listtype Create(int (*compare)(int ,int ),void (*print)(char));
Listtype Insert(Listtype List,int number,char letter);
void interpret(Listtype List,char morse[],char english[]);
void terminate();
