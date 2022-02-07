#include <stdio.h>
int a[50], n, item;
void linearsearch()
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == item)
        {
            printf("%d found at position %d\n", item, i + 1);
            break;
        }
    }
    if (i == n)
        printf("Element not found\n");
}
void binarysearch()
{
    int low, high, mid, i;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == item)
        {
            printf("%d found at position %d\n", item, mid + 1);
            break;
        }
        else if (a[mid] < item)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (low > high)
        printf("Element not found\n");
}
void main()
{
    int choice, j;
    while (1)
    {
        printf("1. Linear search\n2. Binary search\nPress any other number to exit\n");
        scanf("%d", &choice);
        if (choice == 1 || choice == 2)
        {
            printf("Enter the number of elements in the array\n");
            scanf("%d", &n);
            printf("Enter the elements\n");
            j = 0;
            while (j < n)
                scanf("%d", &a[j++]);
            switch (choice)
            {
            case 1:
                printf("Enter the item to be searched\n");
                scanf("%d", &item);
                linearsearch();
                break;

            case 2:
                printf("Enter the item to be searched\n");
                scanf("%d", &item);
                int temp;
                for (int i = 0; i < n; i++)
                {
                    for (j = i + 1; j < n; j++)
                    {
                        if (a[i] > a[j])
                        {
                            temp = a[i];
                            a[i] = a[j];
                            a[j] = temp;
                        }
                    }
                }
                printf("The sorted array is: ");
                for (int j = 0; j < n; j++)
                    printf("%d ", a[j]);
                printf("\n");
                binarysearch();
            }
        }
        else
            break;
    }
}