

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};

struct node* insert(struct node* root, int data) {
  if (root == NULL) {
    struct node* node = (struct node*)malloc(sizeof(struct node));

    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return node;

  } else {
    struct node* new;

    if (data <= root->data) {
      new = insert(root->left, data);
      root->left = new;
    } else {
      new = insert(root->right, data);
      root->right = new;
    }

    return root;
  }
}

void LevelOrder(struct node* root) {
  struct node* queue[1000];
  int f = 0, r = 1;
  queue[f] = root;

  while (f < r) {
    struct node* element = queue[f++];
    printf("%d ", element->data);

    if (element->left) {
      queue[r++] = element->left;
    }
    if (element->right) {
      queue[r++] = element->right;
    }
  }
}

void postOrder(struct node* root) {
  if (root) {
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
  }
}

void preOrder(struct node* root) {
  if (root) {
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
}

void inOrder(struct node* root) {
  if (root) {
    inOrder(root->left);
    printf("%d ", root->data);

    inOrder(root->right);
  }
}

int main() {
  struct node* root = NULL;
  int data;

  int choice = 0;
  printf("\n----------------------------------------------\n");
  while (choice != 6) {
    printf("Chose one from the below options...\n");
    printf(
        "\n1.Insert \n2.Level Order Traversal \n3.Postorder \n4.Preorder  "
        "\n5.Inorder \n6.Exit");

    printf("\n Enter your choice \n");
    scanf("%d", &choice);
    switch (choice) {
      case 1: {
        printf("Input node data:");
        scanf("%d", &data);
        root = insert(root, data);
        break;
      }
      case 2: {
        LevelOrder(root);
        break;
      }
      case 3: {
        postOrder(root);
        break;
      }
      case 4: {
        preOrder(root);
        break;
      }
      case 5: {
        inOrder(root);
        break;
      }

      case 6: {
        printf("Exiting....");
        break;
      }
      default: {
        printf("Please Enter valid choice ");
      }
    }
  }
  return 0;
}