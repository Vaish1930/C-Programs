#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
int len;
struct node *root = NULL;

void addBegin()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data in node");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if (root == NULL)
    {
        root = temp;
        temp->next = root;
        root->prev = temp;
    }
    else
    {
        struct node *p = root;
        do
        {
            p = p->next;
        } while (p->next != root);
        p->next = temp;
        temp->prev = p->next;
        temp->next = root->next;
        root = temp;
    }
    printf("Node inserted at beginning");
}

void addEnd()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data in node");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if (root == NULL)
    {
        root = temp;
        temp->next = root;
        root->prev = temp;
    }
    else
    {
        struct node *p;
        p = root;
        do
        {
            p = p->next;
        } while (p->next != root);
        p->next = temp;
        temp->prev = p;
        temp->next = root;
        root->prev = temp;
    }
    printf("\nNode inserted at End");
}

int length()
{
    struct node *p;
    p = root;
    len = 0;
    if (p)
    {
        do

        {
            len++;
            p = p->next;

        } while (p != root);
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

int delete ()
{
    int len = length();
    struct node *temp;
    temp = root;
    int loc;
    printf("Enter location");
    scanf("%d", &loc);
    if (loc > len)
    {
        printf("Invalid Location ");
        return 0;
    }
    if (loc == 1)
    {
        if (len == 1)
        {

            temp->next = NULL;
            root = NULL;
            free(temp);
        }
        else
        {
            struct node *p;
            p = root;
            do
            {
                p = p->next;
            } while (p->next != root);
            p->next = temp->next;
            temp->next->prev = p;
            root = temp->next;
            temp->next = NULL;
            temp->prev = NULL;
            free(temp);
        }
    }
    else
    {
        struct node *p;
        int i = 1;
        while (i < loc - 1)
        {
            i++;
            temp = temp->next;
        }
        p = temp->next;
        p->next->prev = temp;
        temp->next = p->next;
        p->next = NULL;
        p->prev = NULL;
        free(p);
    }
    printf("Node Deleted ");
}

void display()
{
    struct node *p;
    p = root;
    printf("Elements are \n");
    do
    {
        printf("\n");
        printf("%d", p->data);
        p = p->next;
    } while (p != root);
}

int main()
{
    int choice = 0;
    printf("\n----------------------------------------------\n");
    while (choice != 6)
    {
        printf("\nChose one from the below options...\n");
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
