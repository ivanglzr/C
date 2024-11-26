#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Reserva memoria
    newNode->data = data;   // Asigna el valor al nodo
    newNode->next = NULL;   // Inicializa el puntero como NULL
    return newNode;
}

Node* insertAtHead(Node* head, int data){
  Node* newNode = createNode(data);
  newNode->next = head;

  return newNode;
}

Node* insertAtTail(Node* head, int data){
  Node* newNode = createNode(data);

  if (head == NULL) {
    return newNode;
  }

  Node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = newNode;

  return head;
}

void printList(Node* head) {
  Node* temp = head;
  while (temp != NULL) {
    printf(" %d ->", temp->data);
    temp = temp->next;
  }
}


int main() {
  Node* newNode = createNode(7);

  Node* temp = newNode;

  int i = 0;
  while(i < 10) {
    temp = insertAtTail(temp, i);

    i++;
  }

  Node* temp2 = temp;

  int j = 0;
  while (j > -10) {
    temp2 = insertAtHead(temp2, j);

    j--;
  }

  printList(temp2);

  return 0;
}