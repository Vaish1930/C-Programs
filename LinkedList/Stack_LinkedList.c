
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

struct node* top;

void pop() {
  struct node* t;
  if (top == NULL)
    printf("Stack underflow");
  else {
    t = top;
    top = top->next;
    free(t);
    t = NULL;
  }
}

void Push() {
  struct node* new = (struct node*)malloc(sizeof(struct node));
  printf("Input Data");
  scanf("%d", &new->data);
  new->next = top;
  top = new;
}

void display() {
  struct node* temp;
  temp = top;
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
    printf("\n1.Pop \n2.Push \n3.Display  \n4.Exit");
    printf("\n Enter your choice \n");
    scanf("%d", &choice);
    switch (choice) {
      case 1: {
        pop();
        break;
      }
      case 2: {
        Push();
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