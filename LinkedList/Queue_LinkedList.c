
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *f, *r;

void dequeue() {
  struct node *p;
  if (f == NULL)
    printf("Queue is Empty");
  else {
    p = f;
    f = f->next;
    free(p);
    p = NULL;
  }
}

void enqueue() {
  struct node *new = (struct node *)malloc(sizeof(struct node));
  printf("Input Data");
  scanf("%d", &new->data);
  new->next = NULL;
  if (f == NULL)
    f = r = new;
  else
    r->next = new;
  r = new;
}

void display() {
  struct node *temp;
  temp = f;
  if (temp == NULL) {
    printf("Currently stack is Empty");
  } else {
    printf("Node data is :  ");
    while (temp != NULL) {
      printf("\n%d", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  int choice = 0;
  printf("\n----------------------------------------------\n");
  while (choice != 4) {
    printf("Chose one from the below options...\n");
    printf("\n1.enqueue \n2.dequeue \n3.Display  \n4.Exit");
    printf("\n Enter your choice \n");
    scanf("%d", &choice);
    switch (choice) {
      case 1: {
        enqueue();
        break;
      }
      case 2: {
        dequeue();
        break;
      }
      case 3: {
        display();
        break;
      }
      case 4: {
        printf("Exiting....");
        break;
      }
      default: {
        printf("Please Enter valid choice ");
      }
    };
  }
}