#include <stdio.h>
#include <stdlib.h>

// Estructura de un nodo
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Crear un nodo
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

// Insertar al inicio
Node* insertAtHead(Node* head, int data) {
    Node* newNode = createNode(data);

    if (head != NULL) {
        head->prev = newNode;
    }
    newNode->next = head;

    return newNode;
}

// Insertar al final
Node* insertAtTail(Node* head, int data) {
    Node* newNode = createNode(data);

    if (head == NULL) { // Lista vacía
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Imprimir la lista
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf(" %d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Función principal
int main() {
    Node* initialNode = createNode(0);
    Node* list = initialNode;

    int i = -10;
    while (i < 10) {
        if (i < 0) {
            list = insertAtHead(list, i);
        } else {
            list = insertAtTail(list, i);
        }
        i++;
    }

    printf("Lista doblemente enlazada:\n");
    printList(list);

    return 0;
}
