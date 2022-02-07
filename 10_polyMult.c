#include <stdio.h>
#include <malloc.h>
#include <limits.h>

struct node
{
    int exp, coeff;
    struct node *next;
};

void addnode(struct node *head, int coeff, int exp)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->exp = exp;
    temp->coeff = coeff;
    temp->next = head->next;
    head->next = temp;
}

struct node *prod(struct node *a, struct node *b)
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->coeff = INT_MAX, head->exp = INT_MAX, head->next = NULL;
    for (struct node *p = a; p != NULL; p = p->next)
    {
        for (struct node *q = b; q != NULL; q = q->next)
        {
            int coeff = (p->coeff) * (q->coeff);
            int exp = (p->exp) + (q->exp);
            struct node *ptr = head;
            while (ptr->next != NULL && (ptr->exp) > exp)
            {
                if ((ptr->next)->exp >= exp)
                    ptr = ptr->next;
                else
                    break;
            }

            if (ptr->exp == exp)
            {
                int sum = ptr->coeff + coeff;
                if (sum != 0)
                    ptr->coeff = sum;
                else
                {
                    struct node *temp = head;
                    while (temp->next != ptr)
                        temp = temp->next;
                    temp->next = ptr->next;
                    free(ptr);
                }
            }
            else if (ptr->exp > exp)
                addnode(ptr, coeff, exp);
        }
    }

    return head->next;
}

struct node *polyinput()
{
    struct node *head = NULL, *ptr = NULL;
    int n;
    printf("\nEnter the number of terms:");
    scanf("%d", &n);
    printf("\nEnter each of the terms as coeff _space_ exp :");
    while (n--)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        printf("\nInput term:");
        temp->next = NULL;
        int c, e;
        scanf("%d", &c);
        temp->coeff = c;
        scanf("%d", &e);
        temp->exp = e;

        if (head == NULL)
        {
            head = temp;
            ptr = temp;
        }
        else
        {
            ptr->next = temp;
            ptr = ptr->next;
        }
    }
    return head;
}

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        if (ptr->coeff != 0)
            printf("%dx^%d", ptr->coeff, ptr->exp);
        if (ptr->next != NULL)
            printf(" + ");
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    struct node *a = NULL, *b = NULL, *c = NULL;
    a = polyinput();
    b = polyinput();
    printf("Polynomial 1 : ");
    display(a);
    printf("Polynomial 2 : ");
    display(b);
    c = prod(a, b);
    printf("The product of the two polynomials is : ");
    display(c);
    return 0;
}