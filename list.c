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

List * createList() 
{
  List * lista = (List *)malloc(sizeof(List));
  lista -> head = NULL;
  lista -> tail = NULL;
  lista -> current = NULL;
  return lista;
}

void * firstList(List * list)
{
  (list -> current) = (list -> head);
  if (list -> head == NULL)
  {
    return NULL;
  }
  return (list -> current -> data);
}


void * nextList(List * list) 
{
  if (list -> current == NULL) //*por si la lista está vacía
  {
    return NULL;
  }
  (list -> current) = (list -> current -> next);
  if (list -> current == NULL)//*para ver si está en el últimmo elemento (ya que estaría apuntanto a la nada)
  {
    return NULL;
  }
  return (list -> current -> data);//*pasando todos los casos se retorna
}
/* Programe las funciones `void * lastList(List * list)` y `void * prevList(List * list)`.
   * La primera retorna el dato del último elemento en la lista y actualiza el current al nodo correspondiente. 
   * La segunda función retorna el dato del nodo anterior a current y actualiza el current para que apunte a ese nodo.*/

void * lastList(List * list) 
{
  (list -> current) = (list -> tail);
  if (list -> tail == NULL)
  {
    return NULL;
  }
  return (list -> current -> data);
}

void * prevList(List * list) 
{
  
  (list -> current -> prev) = (list -> current);
  if ((list -> current) == NULL)
  {
    return NULL;
  }
  return (list -> current -> data);

}

void pushFront(List * list, void * data) {
}/* antes del head*/

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}/*tail y normalito*/

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}


void * popCurrent(List * list)
{
  void * datoEliminado;
  if ((list -> current) == NULL)
  {
    return NULL;
  }
  datoEliminado = (list -> current -> data);
  if ((list -> current -> next) == NULL)
  {
    (list -> current) = (list -> current -> prev);
    (list -> current -> next) = NULL;
    free (list -> current -> next);
    (list -> tail) = (list -> current);
    return datoEliminado;
  }

  if ((list -> current) == (list -> head))
  {
    (list -> current) = (list -> current -> next);
    (list -> current -> prev) = NULL;
    free (list -> current -> prev);
    (list -> head) = (list -> current);
    return datoEliminado;
  }
  (list-> current -> prev -> next) = (list-> current -> next);
  (list -> current -> next -> prev) = (list -> current->prev);
  (list -> current) = NULL;
  free (list->current);
  return datoEliminado;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}