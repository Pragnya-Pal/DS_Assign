
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coe, exp;
    struct node *next;
};

struct node *create()
{
    struct node *head, *p, *last;
    int n, i;

    head = malloc(sizeof(struct node));
    head->next = head;
    last = head;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        p = malloc(sizeof(struct node));

        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &p->coe, &p->exp);

        last->next = p;
        p->next = head;
        last = p;
    }

    return head;
}

void display(struct node *head)
{
    struct node *p = head->next;

    if(p == head)
    {
        printf("0\n");
        return;
    }

    while(p != head)
    {
        printf("%dx^%d", p->coe, p->exp);
        p = p->next;

        if(p != head)
            printf(" + ");
    }

    printf("\n");
}

struct node *add(struct node *a, struct node *b)
{
    struct node *c, *p, *q, *t, *last;

    c = malloc(sizeof(struct node));
    c->next = c;
    last = c;

    p = a->next;
    q = b->next;

    while(p != a && q != b)
    {
        t = malloc(sizeof(struct node));

        if(p->exp == q->exp)
        {
            t->coe = p->coe + q->coe;
            t->exp = p->exp;
            p = p->next;
            q = q->next;
        }
        else if(p->exp > q->exp)
        {
            t->coe = p->coe;
            t->exp = p->exp;
            p = p->next;
        }
        else
        {
            t->coe = q->coe;
            t->exp = q->exp;
            q = q->next;
        }

        last->next = t;
        t->next = c;
        last = t;
    }

    while(p != a)
    {
        t = malloc(sizeof(struct node));
        t->coe = p->coe;
        t->exp = p->exp;
        last->next = t;
        t->next = c;
        last = t;
        p = p->next;
    }

    while(q != b)
    {
        t = malloc(sizeof(struct node));
        t->coe = q->coe;
        t->exp = q->exp;
        last->next = t;
        t->next = c;
        last = t;
        q = q->next;
    }

    return c;
}

int main()
{
    struct node *p, *q, *sum;

    printf("Enter first polynomial:\n");
    p = create();

    printf("Enter second polynomial:\n");
    q = create();

    printf("First polynomial: ");
    display(p);

    printf("Second polynomial: ");
    display(q);

    sum = add(p, q);

    printf("Sum: ");
    display(sum);

    return 0;
}
