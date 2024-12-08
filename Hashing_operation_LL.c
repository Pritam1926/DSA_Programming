#include<stdio.h>
#include<stdlib.h>
#define length 5
struct node{
	int data;
	struct node *next;
};
struct node *HT[length]={NULL,NULL,NULL,NULL,NULL};
// insertion operation
void hashInsert(int value){
	//create a node
	struct node *node=(struct node*)malloc(sizeof(struct node));
	node->data= value;
	node->next=NULL;
	//hash function
	int key= value%length;
	//if hash key empty
	if(HT[key]==NULL){
		HT[key]=node;
		printf("\nInserted\n");
	}
	// if collision
	else{
		struct node *p=HT[key];
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=node;
		printf("\nInserted\n");
	}
}

void hashDelete(int value){
	int key=value%length;
	if(HT[key]==NULL){
		printf("\nEmpty\n");
	}
	else{
		struct node *p=HT[key],*q;
		if(p->data==value){
			HT[key]=p->next;
			free(p);
			printf("\nDeleted\n");
		}
		else{
			while(p!=NULL){
				if(p->data==value){
					q->next=p->next;
					free(p);
					printf("\nDeleted1\n");
					return;
				}
				q=p;
				p=p->next;
			}
		}
	}
}

void hashSearch(int value){
	int key=value%length;
	if(HT[key]==NULL){
		printf("\nEmpty\n");
	}
	else{
		struct node *p=HT[key];
		while(p!=NULL){
			if(p->data==value){
				printf("\nValue Found\n");
				return;
			}
			p=p->next;
		}
		printf("\nValue not Found\n");
	}
}

void hashDisplay(){
	int i;
	printf("\n");
	for(i=0; i<length; i++){
		printf("HT[%d]->",i);
		struct node *p=HT[i];
		while(p!=NULL){
			printf("%d->",p->data);
			p=p->next;
		}
		printf("NULL\n");
	}
	printf("\n");
}
int main()
{
	int ch,value;
    do{
      printf("Hash Table\n1. Insert\n2. Delete\n3. Searching\n4. Display\n5. Exit\nEnter your Choice:");
      scanf("%d",&ch);
      switch(ch){
	        case 1:
	          printf("Enter the value:");
	          scanf("%d",&value);
	          hashInsert(value);
	          break;
	        
	        case 2:
	          printf("Enter the Delete value:");
	          scanf("%d",&value);
	          hashDelete(value);
	          break;
	        
	        case 3:
	          printf("Enter the Search value:");
	          scanf("%d",&value);
	          hashSearch(value);
	          break; 
	        
	        case 4:
	          hashDisplay();
	          break;
        }
      printf("Enter any key to continue....\n\n");
      getch();
    }while(ch!=5);
}
