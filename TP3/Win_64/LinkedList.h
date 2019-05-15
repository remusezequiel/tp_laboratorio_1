/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif

//Publicas
LinkedList* ll_newLinkedList(void);///constructor
int ll_len(LinkedList* this);///cuenta cuantos elementos hay en la lista
Node* test_getNode(LinkedList* this, int nodeIndex);//
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);//
int ll_add(LinkedList* this, void* pElement);///Agrega un elemento a la lista
void* ll_get(LinkedList* this, int index);///agarra un elemento de la lista
int ll_set(LinkedList* this, int index,void* pElement);///Guarda un elemento en la lista
int ll_remove(LinkedList* this,int index);///Borra un elemento de la lista
int ll_clear(LinkedList* this);///Vacia la lista
int ll_deleteLinkedList(LinkedList* this);///destruye la lista
int ll_indexOf(LinkedList* this, void* pElement);///Me devuelve el indice e un elemento
int ll_isEmpty(LinkedList* this);///
int ll_push(LinkedList* this, int index, void* pElement);///
void* ll_pop(LinkedList* this,int index);///
int ll_contains(LinkedList* this, void* pElement);///
int ll_containsAll(LinkedList* this,LinkedList* this2);///
LinkedList* ll_subList(LinkedList* this,int from,int to);///Crea una sublista desde el parametro from hasta el parametro to
LinkedList* ll_clone(LinkedList* this);///Clona una lista
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);///Ordena una lista segun las condiciones indicadas en el puntero a la funcion
