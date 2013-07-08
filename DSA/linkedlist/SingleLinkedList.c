/**
 * SingleLinkedList.c -- Single Linked List and Queue, Stack using it.
 *
 * Author: Leon (yong.he1982(at)gmail.com)
 * Date  : 2013-07-08 [Monday, 189]
 */

#include <stdio.h>
#include <stdlib.h>

typedef void(*DISPLAY)(void*);
typedef int(*COMPARE)(void*, void*);

/******************************************
 * Simple Single Linked List with methods *
 ******************************************/

typedef struct _node
{
    void *data;
    struct _node *next;
} Node;

typedef struct _linkedList
{
    Node *head;
    Node *tail;
    Node *current;
} LinkedList;

/*
 * Initializes the linked list
 */
void initializeList(LinkedList *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}

/*
 * Adds data to the linked list’s head
 */
void addHead(LinkedList* list, void* data)
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    if (list->head == NULL) {
        list->tail = node;
        node->next = NULL;
    } else {
        node->next = list->head;
    }
    list->head = node;
}

/*
 * Adds data to the linked list’s tail
 */
void addTail(LinkedList* list, void* data)
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
}

/*
 * Removes a node from the linked list
 */
void delete(LinkedList* list, Node* node)
{
    if (node == list->head) {
        if (list->head->next == NULL) {
            list->head = list->tail = NULL;
        } else {
            list->head = list->head->next;
        }
    } else {
        Node *tmp = list->head;
        while (tmp != NULL && tmp->next != node) {
            tmp = tmp->next;
        }
        if (tmp != NULL) {
            tmp->next = node->next;
        }
    }
    free(node);
}

/*
 * Returns a pointer to the node containing a specific data item
 */
Node *getNode(LinkedList* list, COMPARE compare, void* data)
{
    Node *node = list->head;
    while (node != NULL) {
        if (compare(node->data, data) == 0) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

/*
 * Displays the linked list
 */
void displayLinkedList(LinkedList* list, DISPLAY display)
{
    printf("\nLinked List\n");
    Node *current = list->head;
    while (current != NULL) {
        display(current->data);
        current = current->next;
    }
}

/***********************************
 * Use LinkedList to support Queue *
 ***********************************/
typedef LinkedList Queue;

void initializeQueue(Queue *queue)
{
    initializeList(queue);
}

void enqueue(Queue *queue, void *node)
{
    addHead(queue, node);
}

void *dequeue(Queue *queue)
{
    Node *tmp = queue->head;
    void *data;

    if (queue->head == NULL) {
        data = NULL;
    } else if (queue->head == queue->tail) {
        queue->head = queue->tail = NULL;
        data = tmp->data;
        free(tmp);
    } else {
        while (tmp->next != queue->tail) {
            tmp = tmp->next;   /* find the last but one */
        }
        queue->tail = tmp;
        tmp = tmp->next;
        queue->tail->next = NULL;
        data = tmp->data;
        free(tmp);
    }
    return data;
}


/***********************************
 * Use LinkedList to support Stack *
 ***********************************/
typedef LinkedList Stack;

void initializeStack(Stack *stack)
{
    initializeList(stack);
}

void push(Stack *stack, void* data)
{
    addHead(stack, data);
}

void *pop(Stack *stack)
{
    Node *node = stack->head;
    if (node == NULL) {
        return NULL;
    } else if (node == stack->tail) {
        stack->head = stack->tail = NULL;
        void *data = node->data;
        free(node);
        return data;
    } else {
        stack->head = stack->head->next;
        void *data = node->data;
        free(node);
        return data;
    }
}

int main(int argc, char* argv[])
{

    return 0;
}
