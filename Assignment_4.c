
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int reg;
    char name[30];
    struct node *next;
};

struct node *add(struct node *head)
{
    struct node *p, *q;
    p = malloc(sizeof(struct node));

    printf("Enter registration number and name: ");
    scanf("%d%s", &p->reg, p->name);
    p->next = NULL;

    if(head == NULL)
        return p;

    q = head;
    while(q->next != NULL)
        q = q->next;

    q->next = p;
    return head;
}

struct node *removeStudent(struct node *head, int key)
{
    struct node *p = head, *prev = NULL;

    while(p != NULL && p->reg != key)
    {
        prev = p;
        p = p->next;
    }

    if(p == NULL)
        printf("Student not found\n");
    else
    {
        if(prev == NULL)
            head = p->next;
        else
            prev->next = p->next;

        free(p);
        printf("Student removed\n");
    }

    return head;
}

void display(struct node *head)
{
    struct node *p = head;

    if(head == NULL)
        printf("List is empty\n");

    while(p != NULL)
    {
        printf("%d %s\n", p->reg, p->name);
        p = p->next;
    }
}

void count(struct node *head)
{
    int n = 0;
    struct node *p = head;

    while(p != NULL)
    {
        n++;
        p = p->next;
    }

    printf("Total students = %d\n", n);
}

struct node *sort(struct node *head)
{
    struct node *p, *q;
    int r;
    char temp[30];

    for(p = head; p != NULL; p = p->next)
    {
        for(q = p->next; q != NULL; q = q->next)
        {
            if(p->reg > q->reg)
            {
                r = p->reg;
                p->reg = q->reg;
                q->reg = r;

                strcpy(temp, p->name);
                strcpy(p->name, q->name);
                strcpy(q->name, temp);
            }
        }
    }

    return head;
}

struct node *reverse(struct node *head)
{
    struct node *prev = NULL, *curr = head, *next;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main()
{
    struct node *head = NULL;
    int ch, key;

    while(1)
    {
        printf("\n1.Add 2.Remove 3.Display 4.Count");
        printf("\n5.Sort 6.Reverse 7.Exit\n");
        scanf("%d", &ch);

        if(ch == 1)
            head = add(head);
        else if(ch == 2)
        {
            printf("Enter registration number: ");
            scanf("%d", &key);
            head = removeStudent(head, key);
        }
        else if(ch == 3)
            display(head);
        else if(ch == 4)
            count(head);
        else if(ch == 5)
            head = sort(head);
        else if(ch == 6)
            head = reverse(head);
        else if(ch == 7)
            break;
        else
            printf("Invalid choice\n");
    }

    return 0;
}
