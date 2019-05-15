#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);//Funciones que solo se usen dentro del LinkedList(Funciones privadas)
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

///ll_newLinkedList FUNCTION______________________________________________________________________________________////////////////////////////////////
/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
///:::::::::::::VARIABLES:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    LinkedList* this;//Puntero a una lista linkeada
///:::::::::::::::::::::::CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    this = (LinkedList *)malloc(sizeof(LinkedList));//Guarda espacio para una lista
    if(this != NULL)
    {
        this->size=0;//crea el tamaño en 0
        this->pFirstNode = NULL;//pone el primer nodo en NULL
    }
    return this;
}
///ll_len FUNCTION________________________________________________________________________________________________////////////////////////////////////
/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
///:::::::::::::VARIABLES:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    int returnAux = -1;//Si es nulo devuelve -1
///:::::::::::::::::::::::CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    if(this!=NULL)//si no es nulo
    {
        returnAux=this->size;//retorna el size
    }

    return returnAux;
}
///getNode FUNCTION_______________________________________________________________//////////////////////////////////////////////////////////////////////////
/** \brief Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
///:::::::::::::VARIABLES:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    Node* pNode = NULL;
    Node* b_pNode;//Declaro un buffer tipo puntero a nodo
    int i=0;//iterador
///:::::::::::::::::::::::CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))//si se cumplen estas condiciones
    {
        b_pNode = this->pFirstNode;//se le asigna el valor del primer nodo de la lista al buffer del nodo
        while(i<nodeIndex)//Mientras el indice sea menor al indice del nodo a obtener va a entrar al bucle
        {
            b_pNode = b_pNode->pNextNode;//el buffer tomara el valor del siguiente nodo hasta que no se cumpla la condicion, es decir hasta que i==nodeIndex
            i++;
        }
        pNode = b_pNode;//Una vez cumplido el ciclo se le asigna el valor del buffer obtenido en el bucle al nodo que retornara la funcion
    }
    return pNode;
}
///test_getNode FUNCTION_________________________________________________________//////////////////////////////////////////////////////////////////////////
/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}
///addNode FUNCTION_______________________________________________________________//////////////////////////////////////////////////////////////////////////
/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                       (0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
///:::::::::::::VARIABLES:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    int returnAux = -1;
///:::::::::::::::::::::::CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))//Si se dan estas condiciones
    {
        Node* new_pNode = (Node*)malloc(sizeof(Node));//Reservo memoria para un nuevo nodo
        Node* next_pElement = NULL;//Siguiente elemento
        Node* previous_pElement = NULL;//Elemento anterior
        next_pElement=getNode(this,nodeIndex);//A este puntero a nodo le lotordamos el nodo obtenido a partir de la funcion get mediante los parametros anterirmente pasados a la funcion
        new_pNode->pNextNode = next_pElement;//Al nodo del heap se le pasa el valor obtenido mediante el get
        if(nodeIndex==0)//Ahora, si el indice es cero
        {
            this->pFirstNode=new_pNode;//Entonces el nodo va a ser el primer nodo de la lista
        }
        else if(nodeIndex>0 && nodeIndex <= ll_len(this))//si el indice no es el 0
        {
            previous_pElement = getNode(this, nodeIndex-1);//Se va a obtener el nodo anterior, es decie el del indice -1
            previous_pElement->pNextNode = new_pNode;//Al campo pNextNode de la estructura nodo de el elemento obtenido se le asigna el lugar de memoria
        }
        new_pNode->pElement = pElement;//Al elemento guardado en new_pNode se le asigna el valor de pElemento
        this->size = this->size + 1;//El tamaño de la lista se incrementa en uno
        returnAux = 0;//Retornara 0 si se guarda correctamente
    }
///:::::::::::::::::::::::END CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    return returnAux;
}
///test_addNode FUNCTION_______________________________________________________________//////////////////////////////////////////////////////////////////////////
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                      ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}
///ll_add FUNCTION_______________________________________________________________//////////////////////////////////////////////////////////////////////////
/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
///:::::::::::::VARIABLES:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    int returnAux = -1;
    int len;//Declaracion de la variable destinada a obtener el valor de la cantidad de elementos de la lista
///:::::::::::::::::::::::CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    if(this != NULL)
    {
       len = ll_len(this);//Cuento la lista
       addNode(this, len, pElement);//Se agrega un nodo a la lista en el indice indicado por la cantidad de elementos que tiene la lita
       returnAux = 0;//La funcion devuelve 0 Si esta todo ok
    }
///:::::::::::::::::::::::END CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    return returnAux;
}
///ll_get FUNCTION_______________________________________________________________//////////////////////////////////////////////////////////////////////////
/** \brief Permite obtener un nodo en un índice especificado
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
///:::::::::::::VARIABLES:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    void* returnAux = NULL;//Si esta todo m,al, retorna NULL
    Node* pNode=NULL;//Declaro un puntero a nodo
///:::::::::::::::::::::::CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        pNode=getNode(this,index);//Hago un getNode sobre el indice pasado como parametro
        returnAux=pNode->pElement;//Retorno el elemento del nodo obtenido
    }
///:::::::::::::::::::::::END CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    return returnAux;
}
///ll_set FUNCTION_________________________________________________________________________________//////////////////////////////////////////////////
/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
///:::::::::::::VARIABLES:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    int returnAux = -1;
    Node* pNode=NULL;//Declaro un puntero a nodo
///:::::::::::::::::::::::CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        pNode=getNode(this,index);//Obtengo el nodo para modificar
        pNode->pElement=pElement;//Al nodo obtenido le Asigno el valor pasado como parametro
        returnAux=0;//Si esta todo vien retorna 0
    }
///:::::::::::::::::::::::END CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    return returnAux;
}
///ll_remove FUNCTION_____________________________________________________________________________________///////////////////////////////////////////
/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
///:::::::::::::VARIABLES:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    int returnAux = -1;
    Node* remove_pNode=NULL;//Declaracion del puntero a nodo donde se guarda el nodo (que representa al elemento) a borrar
    Node* next_pElement = NULL;//Siguiente Nodo
    Node* previous_pElement = NULL;//Anterior Nodo
///:::::::::::::::::::::::CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    if(this!= NULL && index >= 0 && index<ll_len(this))
    {
        remove_pNode=getNode(this, index);//Obtenemos a partir del indice pasado a la funcion cual es el nodo a borrar
        next_pElement=remove_pNode->pNextNode;//Al siguiente nodo le pedimos que se pare en el nodo siguiente al
        if(index==0)
        {   //En el caso que el nodo a eliminar sea el primer nodo
            this->pFirstNode=remove_pNode;
        }
        else
        {  //En el caso que no sea el indice 0
            previous_pElement=getNode(this,index-1);//Tomo el nodo anterior al indice que se ingresa por parametro
            previous_pElement->pNextNode = next_pElement;//Le asigno el next_pElement al nodo que representa al nodo anterior al ingresado por parametro
        }
        free(remove_pNode);//Borro de la memoria lo que esta en remove_pNode
        this->size = this->size - 1;//Se reduce el size del LinkedList
        returnAux=0;
    }
///:::::::::::::::::::::::END CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    return returnAux;
}

///ll_clear FUNCTION__________________________________________________________________________///////////////////////////////
/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
///:::::::::::::VARIABLES:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    int returnAux = -1;
    int i;//iterador
    int len;//representara al tamaño del linkedList
///:::::::::::::::::::::::CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    if(this != NULL)
    {
        len=ll_len(this);//Cuento cuantos elementos hay en la lista
        while(i<len)//Mientras el contador es emnor a la cantidad de elementos presentes en el linkedList
        {
            ll_remove(this,i);//Hago un remove de cada elemento
            i++;
        }
        returnAux=0;//Cuando termina el proceso retorna 0
    }
///:::::::::::::::::::::::END CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    return returnAux;
}
///ll_deleteLinkedList FUNCTION__________________________________________________________________////////////////////////////
/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
///:::::::::::::VARIABLES:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    int returnAux = -1;
///:::::::::::::::::::::::CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
     if(this != NULL)
    {//Si se cumplen las condiciones
        ll_clear(this);//Hago un clear de la linkedList pasada como parametro
        free(this);//Libero la memoria de toda la linkedList
        returnAux = 0;//Devuelvo 0
    }
///:::::::::::::::::::::::END CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    return returnAux;
}
///ll_indexOf FUNCTION___________________________________________________________________________////////////////////////////
/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
///:::::::::::::VARIABLES:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    int returnAux = -1;
    int i=0;//Iterador
    int len ;//Representa la cantidad de elementos de la linkedList
    Node* pNodo=NULL;
///:::::::::::::::::::::::CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    if(this!=NULL)
    {
        len=ll_len(this);//Cuento cuantos elementos hay en la lista
        while(i<len)//MIentras se cumpla esto
        {
            pNodo=getNode(this,i);//Obtendo el nodo del indice "i"
            if(pNodo->pElement==pElement)
            {//Si el elemento del nodo obtenido es igual al elemento del parametro
                returnAux=i;//Devuelvo el indice del elemento
                break;
            }
            i++;
        }
    }
///:::::::::::::::::::::::END CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    return returnAux;
}
///ll_isEmpty FUNCTION___________________________________________________________________________////////////////////////////
/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
///:::::::::::::VARIABLES:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    int returnAux = -1;
///:::::::::::::::::::::::CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    if(this!=NULL)
    {//si se cumple la condicion
        if(this->size>0)
        {//Si el size es mayor que 0
            returnAux=0;//retorno 0
        }
        else
        {//Si es menor o igual a 0
            returnAux=1;//retorno 1
        }
    }
///:::::::::::::::::::::::END CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    return returnAux;
}
///ll_push FUNCTION______________________________________________________________________________////////////////////////////
/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
///:::::::::::::VARIABLES:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    int returnAux = -1;
///:::::::::::::::::::::::CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
     if(this!=NULL && index>=0 && index<=ll_len(this))
     {//Si se cumplen las condiciones agrego un elemento en el inice pasado por parametro
        addNode(this, index, pElement);
        returnAux=0;//Retorno 0 si esta todo bien
     }
///:::::::::::::::::::::::END CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    return returnAux;
}
///ll_pop FUNCTION______________________________________________________________________________/////////////////////////////
/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
///:::::::::::::VARIABLES:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    void* returnAux = NULL;//Retorna NULL si no se cumplen las condiciones
///:::::::::::::::::::::::CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    if(this!=NULL && index>=0 && index<=ll_len(this))
    {//Si se cumplen las condiciones
        returnAux=ll_get(this,index);//Primero retorno el puntero del indice pasado como parametro.
        ll_remove(this,index);//Despues lo borro. Si primero lo borrase no podria retornarlo.
    }
///:::::::::::::::::::::::END CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    return returnAux;
}
///ll_contains FUNCTION_______________________________________________________________________///////////////////////////////
/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
///:::::::::::::VARIABLES:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    int returnAux = -1;
///:::::::::::::::::::::::CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    if(this != NULL)
    {
        if(ll_indexOf(this,pElement)!=-1)
        {//Si el indice del elemento contiene al elemento
            returnAux=1;//la funcion va retornar 1
        }
        else
        {//Si el indice del elemento no Contiene al elemento
            returnAux=0;//la funcion va retornar 0
        }
    }
///:::::::::::::::::::::::END CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    return returnAux;
}
///ll_contains FUNCTION_______________________________________________________________________///////////////////////////////
/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
///:::::::::::::VARIABLES:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    void* pElement;//Declaro un tipo generico para representar a un elemento
    int returnAux = -1;
    int i;//iterador
    int len;//Representa la cantidad de elementos de la linkedList
///:::::::::::::::::::::::CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;//Si los elementos de (this2) estan contenidos en la lista (this)
        len=ll_len(this2);//Me fijo cuantos elementos hay en la lista 2
        for(i = 0; i<len; i++)
        {
            pElement=ll_get(this2,i);//Tomo el elemento "i" de la lista 2
            if(!ll_contains(this,pElement))
            {//Si la lista 1 no contiene al elemento "i" de la lista 2
                returnAux = 0;//si los elementos de (this2) NO estan contenidos en la lista (this)
            }
        }
    }
///:::::::::::::::::::::::END CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    return returnAux;
}
///ll_subList FUNCTION_________________________________________________________//////////////////////
/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
///:::::::::::::VARIABLES:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    LinkedList* cloneArray = NULL;
///:::::::::::::::::::::::CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///


///:::::::::::::::::::::::END CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    return cloneArray;
}


///ll_clone FUNCTION______________________________________________________________///////////////////
/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
///:::::::::::::VARIABLES:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    LinkedList* cloneArray = NULL;
///:::::::::::::::::::::::CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///

///:::::::::::::::::::::::END CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
///:::::::::::::VARIABLES:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    int returnAux =-1;
///:::::::::::::::::::::::CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///

///:::::::::::::::::::::::END CODE:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::///
    return returnAux;
}

