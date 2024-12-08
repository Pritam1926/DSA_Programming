//Hash operations of integer values
#include <stdio.h>
#define length 10
int count=0,top=-1;
int a[length]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int key[length];

// Insertion operation
void hashInsert(int value){
  if(count==length){
    printf("\nHash Table Full\n");
  }
  else{
    int i;
	int index=value%length;
    for(i=0;i<=top;i++){
    	if(key[i]==index){
    		printf("\nInsert not Possiable\n\n");
    		return;
		}
	}
	printf("\nThe index value of %d is %d\n",value,index);
	a[index]=value;
	printf("\nInserted\n\n");
	key[++top]=index;
	count++;
    
  }
}
// Delete Operation
void hashDelete(int value){
	if(count==0){
		printf("\nHash Table Empty\n\n");
	}
	else{
		int index=value%length;
		if(a[index]==value){
			a[index]=-1;
			printf("\nValue Deleted\n\n");
			count--;
		}
		else{
			printf("\nDelete not Possiable\n\n");
		}
	}
}
// Searching Operation
void hashSearch(int value){
	if(count==0){
		printf("\nHash Table Empty\n\n");
	}
	else{
		int index=value%length;
		if(a[index]==value){
			printf("\nValue found at %d position\n\n",index);
		}
		else{
			printf("\nValue not found\n\n");
		}
	}
}
// Display Operation
void hashDisplay(){
	int i;
  if(count==0){
    printf("\nHash Table Empty\n");
  }
  else{
  	printf("\n");
    for(i=0;i<length;i++){
      printf("%d ",a[i]);
    }
    printf("\n\n");
  }
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
