#pragma once
#include <stdio.h>
#include<stdlib.h>
#include <mm_malloc.h>
#include<math.h>
#include<time.h>
#define SIZE 10
//prototypes
void addToLeft();
void printTheNodes();
void printTheNodesBackwards();
void addToRight();
void addMiddleAfter();
void addMiddleBefore();
void menu();
void deleteNodeFromStart(int print);
void deleteNodeFromEnd();
void deleteAnyNode();
void deleteAllNode();
void printNumbers();
void replaceNumber();
int sizeof_list();
void swap(int * num1, int * num2);
void bubblesort();
int randomNum();
void isPrime();
void countNumbers();
void removeData();
typedef struct Node Nodeptr;

typedef struct Node{
    int data;
    Nodeptr* next;
    Nodeptr* previous;
} Nodeptr;

Nodeptr * startNode;
Nodeptr * endNode;

void printTheNodes() {
   
   if (startNode == NULL && endNode == NULL )
   {
       puts("List is empty");
       return;
   }
       
    Nodeptr *currentPtr = startNode;     
    
    while (currentPtr != NULL)
    {   
        printf("%d ", currentPtr->data);
        printf("--> ");
        currentPtr = currentPtr->next;
    }
    printf("NULL \n");
    puts("===========================");

   
}

void printTheNodesBackwards() {

 if (startNode == NULL && endNode == NULL )
   {
       puts("no node no print sorry");
       return;
   }
       
    Nodeptr *currentPtr = endNode;     
    
    while (currentPtr != NULL)
    {   
        printf("%d ", currentPtr->data);
        printf("--> ");
        currentPtr = currentPtr->previous;
    }
    printf("NULL \n");
    puts("===========================");


}

void addToLeft() {

    Nodeptr * currenNodeleft = (Nodeptr *)malloc(sizeof(Nodeptr));

    if(startNode == NULL & endNode == NULL){

        startNode = currenNodeleft;
        endNode = currenNodeleft;

        printf("what is the data : ");
        scanf("%d", &currenNodeleft->data);

        currenNodeleft->next = NULL;
        currenNodeleft->previous =NULL;
        printTheNodes();
    }
    else {
        printf("what is the data : ");
        scanf("%d",&currenNodeleft->data);
        
        currenNodeleft->next = startNode ;
        currenNodeleft->previous =NULL;
        
        startNode->previous = currenNodeleft;
        startNode = currenNodeleft;
         printTheNodes();
    }

}

void addToRight(){

    Nodeptr * currentNode = (Nodeptr *)malloc(sizeof(Nodeptr));

    if(startNode == NULL && endNode == NULL){
        
        //this is the first node
        startNode = currentNode;
        endNode = currentNode;
        
        //get data from
        printf("What is the data  : ");
        scanf("%d",&currentNode->data);
        
        currentNode->next =NULL;
        currentNode->previous = NULL;
        printTheNodes();
    }else {
        // get data from user
        printf("What is the data  : ");
        scanf("%d",&currentNode->data);

        currentNode->previous = endNode;
        currentNode->next = NULL;
        
        endNode->next = currentNode;
        endNode = currentNode;

        printTheNodes();
    }



}

void addMiddleAfter() {

    if(startNode == NULL && endNode == NULL){
        // no nodes
        printTheNodes();
        return;
    }
    
    int data;
    puts("After which data?");
    scanf("%d",&data);
    
    //search
    Nodeptr * current = startNode;
    
    while(current != NULL){
        
        if(data == current->data){
            //found it!
            if(current == endNode){
                addToRight();
                break;
            }
            Nodeptr * newNode = (Nodeptr *)malloc(sizeof(Nodeptr));
            //get data from user
            printf("What is the data? : ");
            scanf("%d",&newNode->data);
            Nodeptr * currentNext = current->next;
            
            current->next = newNode;
            newNode->previous = current;
            newNode->next = currentNext;
            currentNext->previous = newNode;
            printTheNodes();
            return;
            
        }
        
        current = current->next;
    }

    if(startNode == endNode){
        addToRight();
        return;
    }
    
    puts("Check your data its not in the list");
}

void addMiddleBefore() {
    

}

void deleteNodeFromStart(int print){
    
    
    if(startNode == endNode){
        //there is only 1 node
        free(startNode);
        startNode= NULL;
        endNode=NULL;
    }else{
    Nodeptr *tempPtr = startNode->next;
    tempPtr->previous = NULL;
    free(startNode);
    }
    if(print == 1){
    printTheNodes();
    }
}
void deleteNodeFromEnd(){
    Nodeptr *tempPtr = endNode->previous;
    tempPtr->next = NULL;
    free(endNode);
    endNode = tempPtr;

    printTheNodesBackwards();
}
void deleteAnyNode(){
    
    if(startNode == NULL && endNode == NULL){
        // no nodes
        printTheNodes();
        return;
    }
    int data;
    puts("Which data?");
    scanf("%d",&data);
    
    //search
    Nodeptr * current = startNode;
    
    while(current != NULL){
        
        if(data == current->data){ //found it!
            
            
            Nodeptr * currentNext = current->next;
            Nodeptr * currentPriv = current->previous;
            

            currentNext->previous = currentPriv; //a
            currentPriv->next = currentNext; // b
            
            free(current);
            printTheNodes();

            return;
            
        }
        
        current = current->next;
        
    }

}
void deleteAllNode(){
    
    while(startNode != NULL){
    deleteNodeFromStart(0);
    }
    puts("list is empty");
}
void printNumbers(int oddOrEven){
    

    if (startNode == NULL)
    {
        puts("list is empty");
        return;
    }
    Nodeptr * currentPtr = startNode;

    
    while (currentPtr != NULL){

        if (currentPtr->data %2 == oddOrEven)
        {
            printf("%d --> ",currentPtr->data);
        }
           currentPtr = currentPtr->next; 
    }
    puts("");
    
}
void replaceNumber(){
    
    if(startNode == NULL && endNode == NULL){
            // no nodes
            printTheNodes();
            return;
        }
        
        // get the mistake data from user
        int data;
        puts("which data do you want to replace ?");
        scanf("%d",&data);
        
        //search
        Nodeptr * current = startNode;
        
        while(current != NULL){
            
            if(data == current->data){
                //found it!

                // printf("Provide the new data : ");
                // scanf("%d",&current->data);
                
                 current->data = randomNum();
                printTheNodes();

                return;
                }
            current = current->next;             

            }
        puts("sorry it doesn't exist in the list.");

}

void swap(int *num1, int *num2){
    int temp;
    if(*num1 > *num2){
        temp = *num1;
        *num1=*num2;
        *num2= temp;
    }
    
}

int sizeof_list() {
   int size = 0;
   Nodeptr *link;

   if(startNode == NULL) {
      printf("\n Size of list is  %d try again \n", size);
      return 0;
   }

   link = startNode;            
   while(link != NULL) {
      size++;
      link = link->next;
   }
   return size;
}

void bubblesort(){
    Nodeptr * current = startNode;
    Nodeptr * currentNext;
    int temp;
    int count = sizeof_list();
    puts("\n-----------bubble sort-----------");
    
    for (int i = 0; i < count; i++){
        current = startNode;
        for (int j = 0; j < count-i-1; j++)
        {   
            currentNext = current->next;
            if(current->data > currentNext->data){
                temp = current->data;
                current->data = currentNext->data;
                currentNext->data = temp;
            }
            current = current->next;
        }
    }
    printTheNodes();
}

int randomNum(){
    // uniqie number
    srand((signed int)time(NULL));

    return rand()%100;
}
int prime(long number){
    if (number < 2 ) return 0;
    if (number == 2) return 1;

    for (int i = 2; i <= (int)sqrt(number) ; i++){
        if(number % i == 0)
        return 0;
    }
    return 1;
    
}
void isPrime(){

    for (int i = 0, counter = 0; counter < 10002 ; i++)
    {
        if(prime(i) == 1 ){
            counter ++;
            if (counter == 10001)   
            {
                printf("the  value is %d \n\n", i);
                break;
            } 
        }
    }   
}
void countNumbers(){
    int num;
    Nodeptr * current = startNode;
    int count = sizeof_list();
    int cnt =0;
    
    
    printf("Which data do you want to count number? ");
    scanf("%d", &num);

    for (int i = 0; i < count; i++)
    {
        if (num == current->data)
        {
            cnt++;    
        }
        current =current->next;       
    }
    printf("%d is %d times \n", num, cnt) ;  
}
void removeData(){
    int num;
    int count = sizeof_list();
    Nodeptr * current = startNode;
    


    printf("Which data do you want remove? ");
    scanf("%d",&num);

    for (int i = 0; i < count; i++)
    {
        if (num == current->data)
        {
            free(current);    
        }
        current =current->next;       
    }
    printTheNodes();
}
    
    
       



void menu() {
    puts("");
    printf("--------------------------------------------------"); 
        printf("\t\t1-  Add a node to left\n");
        printf("\t\t2-  Add a node to right\n");
        printf("\t\t3-  Add a node to middle after a node\n");
        printf("\t\t4-  Add a node to middle before a node\n");
        printf("\t\t5-  Printf the list forward\n");
        printf("\t\t6-  Printf the list backward\n");
        printf("\t\t7-  Delete a node (startNode)\n");
        printf("\t\t8-  Delete a node (end)\n");
        printf("\t\t9-  Delete any node \n");
        printf("\t\t10- Delete all node \n");
        printf("\t\t11- Print odd Numbers \n");
        printf("\t\t12- Print Even Numbers \n");
        printf("\t\t13- Replace the Number\n");
        printf("\t\t14- Bubble Sort\n");
        printf("\t\t0- exit\n");
        printf("--------------------------------------------------");
    printf("? :  ");
}