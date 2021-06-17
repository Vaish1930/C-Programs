#include <stdio.h>
#define size 5

int stack[size];
int top = -1;

void push()
{
    int val;
    if (top == size - 1)
        printf("Stack Overflow");
    else
    {
        printf("Enter the value?");
        scanf("%d", &val);
        top += 1;
        stack[top] = val;
    }
}

void pop()
{
    if (top == -1)
        printf("Stack underflow");
    else
    {
        int k = stack[top];
        printf("Deleted Elemrnt %d\n", k);
        top -= 1;
    }
}

void display()
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
    if (top == -1)
    {
        printf("Stack is empty");
    }
}

int main()
{

    int choice = 0;

    // printf("Input you choice");
    // scanf("%d",&choice);
    printf("\n----------------------------------------------\n");
    while (choice != 4)
    {
        printf("Chose one from the below options...\n");
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
        printf("\n Enter your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
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