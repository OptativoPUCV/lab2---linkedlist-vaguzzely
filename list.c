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


void * lastList(List * list) {
    return NULL;
}

void * prevList(List * list) {
    return NULL;
}

void pushFront(List * list, void * data) {
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
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
/*6. Programe la función `void* popCurrent(List * list)`, la cual elimina el nodo que está en la posición del current de la lista enlazada, y además retorna el **dato** del nodo eliminado.
> **Nota**: El current debe quedar apuntando al nodo siguiente del eliminado.

Las funciones `pushBack`, `popFront` y `popBack` se pueden implementar usando `popCurrent` y `pushCurrent` (búsquelas en el código).    head, null, tail, normalito   */
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
  (list -> current) = (list -> current -> next);
  (list -> current -> prev) = NULL;
  free (list -> current -> prev);
  return datoEliminado;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}