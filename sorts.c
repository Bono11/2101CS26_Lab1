#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    int *ptr;
    ptr=(int *)malloc(n*sizeof(int));
    printf("Enter array elements\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", ptr+i);
    }
    printf("The array to be sorted in ascending is \n {");
    for(int i=0;i<n;i++)
    {
        printf("%d", *(ptr+i));
        if(i!=n-1)printf(",");
    }
    printf("}\n");
    while(1)
    {
    int op;
    printf("Select which sort you would like\n 1 Insertion \t\t 2 Selection \n 3 Bubble \t\t 4 Merge \n 5 Quick \nPlease make a choice\n");
    scanf("%d", &op);
    switch(op)
    {
        case 1:
        {int posi, temp;
        for(int c=0; c<n-1;c++)
        {
            posi=c;
            for (int d = c + 1; d < n; d++)
            {
                if(*(ptr+posi)>*(ptr+d))
                posi=d;
            }
            if(posi!=c)
            {
                temp=*(ptr+c);
                *(ptr+c)=*(ptr+posi);
                *(ptr+posi)=temp;
            }
        }}
        break;
        default:
        printf("\n Please make a valid choice\n");
        continue;
    }
    break;
    }
    printf("\nSorted array in asending order is\n{");
    for(int i=0;i<n;i++)
    {
        printf("%d", *(ptr+i));
        if(i!=n-1)printf(",");
    }
    printf("}\n");
}