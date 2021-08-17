#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *root = NULL;
int len;

void addBegin() {
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  printf("\n Enter node Data : ");
  scanf("%d", &temp->data);
  temp->next = NULL;
  if (root == NULL) {
    root = temp;
  } else {
    temp->next = root;
    root = temp;
  }
  printf("Node is inserted at Beginning \n");
}

void addEnd() {
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  printf("\n Enter node Data : ");
  scanf("%d", &temp->data);
  temp->next = NULL;
  if (root == NULL) {
    root = temp;
  } else {
    struct node *p;
    p = root;
    while (p->next != NULL) {
      p = p->next;
    }
    p->next = temp;
  }
  printf("Node is inserted at End \n");
}

int length() {
  struct node *p;
  p = root;
  while (p != NULL) {
    len++;
    p = p->next;
  }
  return len;
}

void addAfter() {
  int loc, i = 1;
  struct node *temp;
  printf("Enter location after which you want to insert a node");
  scanf("\n%d", &loc);
  if (loc > length()) {
    printf("Wrong Loaction ,input valid location\n");
  } else {
    struct node *p = root;
    while (i < loc) {
      p = p->next;
      i++;
    }
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter node Data : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->next = p->next;
    p->next = temp;
    printf("Node had been addded to the list at location %d.\n", loc);
  }
}

void delete () {
  int loc;
  struct node *temp;

  printf("Enter node location which you want to delete");
  scanf("\n%d", &loc);
  if (loc > length()) {
    printf("Wrong Loaction ,input valid location\n");
  } else if (loc == 1) {
    temp = root;
    root = temp->next;
    temp->next = NULL;
    free(temp);
    printf("Node at location %d had been deleted.\n", loc);
  } else {
    int i;
    struct node *p;
    struct node *temp;
    p = root;
    while (i - 1 < loc) {
      p = p->next;
      i++;
    }
    temp = p->next;
    p->next = temp->next;
    temp->next = NULL;
    free(temp);
    printf("Node at location %d had been deleted.\n", loc);
  }
}

// void reverse() {
//   struct node *prev = NULL;
//   struct node *current = root;
//   struct node *next = NULL;
//   while (current != NULL) {
//     next = current->next;
//     current->next = prev;
//     prev = current;
//     current = next;
//   }
//   root = prev;
// }

void display() {
  struct node *temp;
  temp = root;
  if (temp == NULL) {
    printf("Currently linked list is Empty");
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
  while (choice != 6) {
    printf("Chose one from the below options...\n");
    printf(
        "\n1.Add At Beginning \n2.Add At End \n3.Add After given Location "
        "\n4.delete  \n5.Display  \n6.Exit");
    printf("\n Enter your choice \n");
    scanf("%d", &choice);
    switch (choice) {
      case 1: {
        addBegin();
        break;
      }
      case 2: {
        addEnd();
        break;
      }
      case 3: {
        addAfter();
        break;
      }
      case 4: {
        delete ();
        break;
      }
      case 5: {
        display();
        break;
      }
      case 6: {
        printf("Exiting....");
        break;
      }
      default: {
        printf("Please Enter valid choice ");
      }
    };
  }
}