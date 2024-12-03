//Hash operations of integer values
#include <stdio.h>
#define length 10
int count=0;

// Insertion operation
void hashInsert(int value, int a[]){
  if(count==length){
    printf("\nHash Table Full\n");
  }
  else{
    int index=value%length;
    printf("\nThe index value of %d is %d\n",value,index);
    a[index]=value;
    printf("\nInserted\n\n");
    count++;
  }
}

// Display Operation
void hashDisplay(int a[]){
	int i;
  if(count==1){
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
    int a[length]={0,0,0,0,0,0,0,0,0,0};
	int ch,value;
    do{
      printf("Hash Table\n1. Insert\n2. Delete\n3. Searching\n4. Display\n5. Exit\nEnter your Choice:");
      scanf("%d",&ch);
      switch(ch){
	        case 1:
	          printf("Enter the value:");
	          scanf("%d",&value);
	          hashInsert(value,a);
	          break;
	        case 4:
	          hashDisplay(a);
	          break;
        }
      printf("Enter any key to continue....\n\n");
      getch();
    }while(ch!=5);
}
