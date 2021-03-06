#include <stdio.h>
#define N 5
int Q[N], Pr[N];
int r = -1, f = -1;
void enqueue(int data, int p)
{
    int i;
    if ((f == 0) && (r == N - 1))
        printf("Queue is full");
    else
    {
        if (f == -1)
        {
            f = r = 0;
            Q[r] = data;
            Pr[r] = p;
        }
        else if (r == N - 1)
        {
            for (i = f; i <= r; i++)
            {
                Q[i - f] = Q[i];
                Pr[i - f] = Pr[i];
                r = r - f;
                f = 0;
                for (i = r; i > f; i--)
                {
                    if (p > Pr[i])
                    {
                        Q[i + 1] = Q[i];
                        Pr[i + 1] = Pr[i];
                    }
                    else
                        break;
                    Q[i + 1] = data;
                    Pr[i + 1] = p;
                    r++;
                }
            }
        }
        else
        {
            for (i = r; i >= f; i--)
            {
                if (p > Pr[i])
                {
                    Q[i + 1] = Q[i];
                    Pr[i + 1] = Pr[i];
                }
                else
                    break;
            }
            Q[i + 1] = data;
            Pr[i + 1] = p;
            r++;
        }
    }
}
void print()
{
    int i;
    for (i = f; i <= r; i++)
        printf("\nElement = %d\tPriority = %d", Q[i], Pr[i]);
}
int dequeue()
{
    if (f == -1)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("deleted Element = %d\t Its Priority = %d", Q[f], Pr[f]);
        if (f == r)
            f = r = -1;
        else
            f++;
    }
    return 0;
}
int main()
{
    int opt, n, i, data, p;
    printf("Enter Your Choice:-");
    do
    {
        printf("\n\n1 - Insert \n2 - Display \n3 - Delete \n0 - Exit\n\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("\nEnter the number of elements: ");
            scanf("%d", &n);
            printf("\nEnter the elements in data_priority format \n");
            i = 0;
            while (i < n)
            {
                scanf("%d %d", &data, &p);
                enqueue(data, p);
                i++;
            }
            break;
        case 2:
            print();
            break;
        case 3:
            dequeue();
            break;
        case 0:
            break;
        default:
            printf("\nIncorrect Choice");
        }
    } while (opt != 0);
    return 0;
}