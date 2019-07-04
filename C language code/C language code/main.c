//
//  main.c
//  C language code
//
//  Created by Daniel Yuwan Goh on 2019-07-03.
//  Copyright © 2019 Yuwan Go. All rights reserved.
//

#include <stdio.h>

int main()
{
    // Add number from 1 to 100
    int num;
    int sum;
    
    for(num = 1; num <=100; num++){
        sum = sum + num;
    }
    printf("%s","The total is :");
    printf("%d \n",sum);
    
    // result Even number
    for(num =0; num < 100; num +=2){
        printf("%s","The even number is: ");
        printf("%d \n",num);
    }
    
    // result odd number
    for(num=0; num < 100; num++){
        if (num % 2 != 0) {
            printf("%s","The Odd number is: ");
            printf("%d \n",num);
        }
    }
    
    // Take two numbers and add all numbers in between
    
    int low;
    int high;
    
    
    printf("%s","please give me the lower number :");
    scanf("%d", &low);
    printf("%s","please give me the high number :");
    scanf("%d", &high);
    for(num = low ; num <= high ; num ++)
    {
        sum = sum + num;
    }
    
    printf("%s","The total number is: ");
    printf("%d\n", sum);
    
    //funtional number
    int nums;
    int fact = 1;
    scanf("%d",&nums);
    while (nums >= 1){
        fact = fact * nums;
        nums = nums -1;
    }
    printf("%d",fact);
    
    //prime number
    
    int j;
    for (int i = 1; i <100; i++) {
        for (j = 2; j <= i; j++) {
            if (i % j == 0) {
                break;
            }
        }
        if(i == j)
            
            printf("%d \n", i);
    }
    return 0;
}

