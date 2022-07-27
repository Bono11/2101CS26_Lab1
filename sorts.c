#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
int main()
{
    int n;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    int *ptr;
    ptr = (int *)malloc(n * sizeof(int));
    printf("Enter array elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }
    printf("The array to be sorted in ascending is \n {");
    for (int i = 0; i < n; i++)
    {
        printf("%d", *(ptr + i));
        if (i != n - 1)
            printf(",");
    }
    printf("}\n");
    while (1)
    {
        int op;
        printf("Select which sort you would like\n 1 Selection \t\t 2 Insertion \n 3 Bubble \t\t 4 Merge \n 5 Quick \nPlease make a choice\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
        {
            int posi, temp;
            for (int c = 0; c < n - 1; c++)
            {
                posi = c;
                for (int d = c + 1; d < n; d++)
                {
                    if (*(ptr + posi) > *(ptr + d))
                        posi = d;
                }
                if (posi != c)
                {
                    temp = *(ptr + c);
                    *(ptr + c) = *(ptr + posi);
                    *(ptr + posi) = temp;
                }
            }
        }
        break;

        case 2:
        {
            int i, hold, j;
            for (i = 1; i < n; i++)
            {
                hold = *(ptr + i);
                j = i - 1;
                while (j >= 0 && *(ptr + j) > hold)
                {
                    *(ptr + j + 1) = *(ptr + j);
                    j = j - 1;
                }
                *(ptr + j + 1) = hold;
            }
        }
        break;

        case 3:
        {
            int i = 0, j = 0, tmp;
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n - i - 1; j++)
                {
                    if (*(ptr + j) > *(ptr + j + 1))
                    {
                        tmp = *(ptr + j);
                        *(ptr + j) = *(ptr + j + 1);
                        *(ptr + j + 1) = tmp;
                    }
                }
            }
        }
        break;

        case 4:
        {
            mergeSort(ptr, 0, n-1);
        }
        break;

        default:
            printf("\nPlease make a valid choice\n");
            continue;
        }
        break;
    }
    printf("Sorted array in asending order is\n{");
    for (int i = 0; i < n; i++)
    {
        printf("%d", *(ptr + i));
        if (i != n - 1)
            printf(",");
    }
    printf("}\n");
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

   
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;


    j = 0;

    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
     
        int m = l + (r - l) / 2;


        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}