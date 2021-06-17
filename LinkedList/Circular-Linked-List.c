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
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("Enter node data = ");
    scanf("%d", &tmp->data);
    tmp->next = NULL;
    if (root == NULL)
    {
        root = tmp;
        tmp->next = root;
    }
    else
    {
        struct node *p = root;
        do
        {
            p = p->next;
        } while (p->next != root);
        p->next = tmp;
        tmp->next = root;
        root = tmp;
    }
    printf("Node had been added to the beginning.\n");
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

void addEnd()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data in the node : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (root == NULL)
    {
        root = temp;
        temp->next = root;
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
        temp->next = root;
    }
    printf("Node had been added to the beginning.\n");
}

void addAfter()
{
    int loc, i = 1;
    printf("Enter location after which you want to insert the node\n");
    scanf("%d", &loc);
    if (loc > length())
    {
        printf("Invalid Location");
    }
    else
    {
        struct node *temp;
        struct node *p = root;
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter data in node :");
        scanf("%d", &temp->data);
        temp->next = NULL;
        while (i < loc)
        {
            p = p->next;
            i++;
        }
        temp->next = p->next;
        p->next = temp;
    }
    printf("Node had been addded to the list at location %d.\n", loc);
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
            root = temp->next;
            temp->next = NULL;
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
        temp->next = p->next;
        p->next = NULL;
        free(p);
    }
    printf("Node Deleted ");
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
