#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List *lista = (List *) malloc(sizeof(List));
    lista->head = NULL;
    lista->tail = NULL;
    lista->current = NULL;
    return lista;
}

void * firstList(List * list) {
    if (list == NULL || list->head == NULL) {
        return NULL;
    }

    list->current = list->head;
    return (void *)list->current->data;
}

void * nextList(List * list) {
    if (list == NULL || list->current == NULL || list->current->next == NULL) {
        return NULL;
    }

    list->current = list->current->next;
    return (void *)list->current->data;
}

void * lastList(List * list) {
    if (list == NULL || list->tail == NULL)
    {
        return NULL;
    }
    list->current = list->tail;
    return (void *)list->current->data;
}

void * prevList(List * list) {
    if (list == NULL || list->current == NULL || list->current->prev == NULL){
      return NULL;
    }
    list->current = list->current->prev;
    return (void *)list->current->data;
}

void pushFront(List * list, void * data) {
    if (list == NULL) {
        return;
    }
    Node * new = createNode(data);
    if (list->head == NULL){
        list->head = new;
    }
    else{
        new->next = list->head;
        list->head->prev = new;
        list->head = new;
    }
}

void pushBack(List * list, void * data) {
    if (list == NULL) {
        return;
    }
    Node * new = createNode(data);
    if (list->tail == NULL)
    {
        list->tail = new;
    }
    else
    {
        new->prev = list->tail;
        list->tail->next = new;
        list->tail = new;
    }
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}