/*
 *
 * Linked List Example
 * github.com/skittlexyz
 *
 */

// Including libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Colors for pretty printf
#define COLOR "\x1B[36m"
#define RESET "\x1B[0m"

// Linked list size
#define SIZE 25

// Defining the random number generation parameters
#define MIN 0
#define MAX 1000

// Creating the node structure
struct Node {
  int value;
  struct Node *next;
};

// Generating random numbers based on the seed
int generateRandomNumber(int min, int max) {
  return min + rand() % (max - min + 1);
}

// Freeing the linked list allocated memory
void freeLinkedList(struct Node *head) {
  struct Node *current = head; // Getting the first node
  // Freeing the linked list memory node by node until it's empty
  while (current != NULL) {
    struct Node *temp = current;
    current = current->next;
    free(temp);
  }
}

// Printing the linked list nodes one by one
void printLinkedList(struct Node *head) {
  struct Node *current = head; // Getting the first node
  while (current != NULL) {    // Printing nodes from the linked list one by one
                               // until there's none left
    if (current->next != NULL)
      printf(COLOR "Next Address: " RESET "%p" COLOR " Current Value: " RESET
                   "%d\n",
             current->next, current->value);
    else
      printf(COLOR "Next Address: " RESET "EmptyNode" COLOR
                   " Current Value: " RESET "%d\n",
             current->value);
    current = current->next;
  }
}

// Appending nodes to the linked list
void appendNode(struct Node **head, int value) {
  struct Node *newNode = (struct Node *)malloc(
      sizeof(struct Node)); // Allocating memory for a single node
  // Checking if the allocation was sucessful
  if (newNode == NULL) {
    fprintf(stderr, "Memory allocation failed!\n");
    exit(EXIT_FAILURE);
  }
  // Associating the value with the node and setting the next node address
  newNode->value = value;
  newNode->next = NULL;
  if (*head == NULL) {
    *head = newNode;
  } else {
    struct Node *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

int main(void) {
  srand(time(0));                 // Generating seed for random numbers
  struct Node *linkedList = NULL; // Creating linked list head
  for (int i = 0; i < SIZE;
       i++) { // Appending nodes to the linked list head with random values
    appendNode(&linkedList, generateRandomNumber(MIN, MAX));
  }
  // Printing title bar
  printf(COLOR "==========" RESET " Linked List Example " COLOR
               "==========\n" RESET);
  printf(COLOR "         " RESET " github.com/skittlexyz " COLOR
    "         \n\n" RESET);
  printLinkedList(linkedList); // Printing the linked list nodes one by one
  freeLinkedList(linkedList);  // Freeing the linked list allocated memory
  printf(COLOR "\n==================" RESET " End " COLOR
               "==================" RESET); // Printing end bar
  return 0;
}
