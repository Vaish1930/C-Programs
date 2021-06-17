#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *root = NULL;
int len;

void addBegin()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data in the node  : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->next = root;
        root->prev = temp;
        root = temp;
    }
    printf("Node is inserted at Beginning \n");
}

void addEnd()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data in the node  : \n ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p;
        p = root;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
    printf("Node is inserted at End \n");
}

int length()
{
    len = 0;
    struct node *p;
    p = root;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

void addAfter()
{
    int i = 1, loc;
    struct node *temp;
    printf("Enter location after which you want to add a new node ");
    scanf("%d", &loc);
    if (loc > length())
    {
        printf("\n Invalid Location ! ");
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter data in the node  :  ");
        scanf("%d", &temp->data);
        temp->next = NULL;
        temp->prev = NULL;
        struct node *p = root;
        while (i < loc)
        {
            p = p->next;
            i++;
        }
        temp->next = p->next;
        p->next->prev = temp;
        temp->prev = p;
        p->next = temp;
        printf("Node had been addded to the list at location %d.\n", loc);
    }
}

void delete ()
{
    int loc, i = 1;
    struct node *temp;

    printf("Enter Location of the node which you want to delete\n");
    scanf("%d", &loc);
    if (loc > length())
    {
        printf("Invalid location\n");
    }
    else if (loc == 1)
    {
        temp = root;
        root = temp->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        free(temp);
        printf("Element Deleted at location %d", loc);
    }
    else
    {
        temp = root;
        struct node *p;
        while (i < (loc - 1))
        {
            temp = temp->next;
            i++;
        }
        p = temp->next;
        p->next->prev = temp;
        temp->next = p->next;
        p->next = NULL;
        p->prev = NULL;
        free(p);
        printf("Node at %d location had been deleted successfully.\n", loc);
    }
}

void display()
{
    struct node *temp;
    temp = root;
    if (temp == NULL)
    {
        printf("Currently linked list is Empty");
    }
    else
    {
        printf("Node data is :  ");
        while (temp != NULL)
        {
            printf("\n%d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice = 0;
    printf("\n----------------------------------------------\n");
    while (choice != 6)
    {
        printf("Chose one from the below options...\n");
        printf("\n1.Add At Beginning \n2.Add At End \n3.Add After given Location \n4.Delete  \n5.Display  \n6.Exit");
        printf("\n Enter your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            addBegin();
            break;
        }
        case 2:
        {
            addEnd();
            break;
        }
        case 3:
        {
            addAfter();
            break;
        }
        case 4:
        {
            delete ();
            break;
        }
        case 5:
        {
            display();
            break;
        }
        case 6:
        {
            printf("Exiting....");
            break;
        }
        default:
        {
            printf("Please Enter valid choice ");
        }
        };
    }
}
