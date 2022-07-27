#include <stdio.h>  
#include <math.h>  
#include <stdlib.h>  
  
int main()  
{  
    int op, n1, n2;  
    float res;  
    char ch;  
    do  
    {  
        printf (" Select an operation to perform the calculation in C Calculator: ");  
        printf (" \n 1 Addition \n 7 Exit \n \n Please, Make a choice ");      
          
        scanf ("%d", &op);   
       
    switch (op)  
    {  
        case 1:    
            printf (" You chose: Addition");  
            printf ("\n Enter First Number: ");  
            scanf (" %d", &n1);  
            printf (" Enter Second Number: ");  
            scanf (" %d", &n2);  
            res = n1 + n2; 
            printf (" Addition of two numbers is: %.2f", res);  
            break; 
        case 7:  
            printf (" You chose: Exit");  
            exit(0);   
            break;              
        default:  
            printf(" Something is wrong!! ");  
            break;                        
    }  
    printf (" \n \n  ");  
    } while (op != 7);  
  
    return 0;        
}  
