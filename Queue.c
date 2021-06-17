#include <stdio.h>
#define size 10

int queue[size];
int front = -1;
int rear = -1;

void enqueue()
{
    int val;
    if (rear == size - 1)
        printf("Queue is full");
    else
    {
        printf("Enter the value?");
        scanf("%d", &val);
        rear += 1;
        queue[rear] = val;
        if (front == -1)
            front = 0;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
        printf("Queue is Empty\n");
    else if (front == rear)
    {
        printf("Deleted Elemrnt %d\n", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {

        printf("Deleted Elemrnt %d\n", queue[front]);
        front += 1;
    }
}

void display()
{

    int i;
    if (rear == -1)
    {
        printf("\nEmpty queue\n");
    }
    else
    {
        printf("\nprinting values .....\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
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
        printf("\n1.insert\n2.delete\n3.Show\n4.Exit");
        printf("\n Enter your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            enqueue();
            break;
        }
        case 2:
        {
            dequeue();
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