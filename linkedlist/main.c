#include <stdio.h>
#include "myFunctions.h"



extern Nodeptr * startNodeNode;
extern Nodeptr * endNode;

int main()
{
    //it may give you some error or warnings for some compilers
    //no init
    int choice;
    startNode = NULL;
    endNode = NULL;
    
    do
    {
        printf("\t\tWelcome, please select one\n");
        puts("");

        printf("--------------------------------------------------\n"); 
        printf("\t\t1  - Add a node to left\n");
        printf("\t\t2  - Add a node to right\n");
        printf("\t\t3  - Add a node to middle after a node\n");
        printf("\t\t4  - Add a node to middle before a node\n");
        printf("\t\t5  - Printf the list forward\n");
        printf("\t\t6  - Printf the list backward\n");
        printf("\t\t7  - Delete a node (startNode)\n");
        printf("\t\t8  - Delete a node (end)\n");
        printf("\t\t9  - Delete any node \n");
        printf("\t\t10 - Delete all node \n");
        printf("\t\t11 - Print odd Numbers \n");
        printf("\t\t12 - Print Even Numbers \n");
        printf("\t\t13 - Replace the Number\n");
        printf("\t\t14 - Bubble Sort\n");
        printf("\t\t 0 - exit\n");
        printf("--------------------------------------------------\n"); 
        puts("99 - Extend the menu | ");

        scanf("%d", &choice);
        
        switch (choice)
        {
            case 99:
                menu();
                break;
            case 1:
                //puts("under construction");
                addToLeft();
                break;
            case 2:
                //puts("under construction");
                addToRight();
                break;
            case 3:
                //puts("under construction");
                addMiddleAfter();
                break;
            case 4:
                //puts("under construction");
                addMiddleBefore();
                break;
            case 5:
                //puts("under construction");
                printTheNodes();
                break;
            case 6:
                //puts("under construction");
                printTheNodesBackwards();
                break;
            case 7:
                deleteNodeFromStart(1);
                break;
            case 8:
                deleteNodeFromEnd();
                break; 
            case 9:
                deleteAnyNode();
            
            case 10:
                deleteAllNode();
                break;
            case 11:
                printNumbers(1); //odd numbers
                break;
            case 12:
                printNumbers(0); // even numbers
                break;
            case 13:
                replaceNumber();
                break;
            case 14:
                bubblesort();
                break;
            case 15:
                // isPrime();
                countNumbers();
                break;
            case 16:
                removeData();
                break;
            case 0:
                break;
            default:
                printf("please enter a valid number\n\n");
                break;
        }
        
    } while (choice != 0);
    
    
   
    return 0;
}

