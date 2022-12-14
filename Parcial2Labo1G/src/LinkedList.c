#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    if(this==NULL)
    {
    	this = (LinkedList*)malloc(sizeof(LinkedList));
    	if(this!=NULL)
    	{
    		this->size=0;
    	}
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
	{
    	returnAux=this->size;
	}
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode=NULL;
	int i;
	int cant=ll_len(this);
	if(this!=NULL && (nodeIndex<cant && nodeIndex>=0)&&cant>0)
	{
		pNode=this->pFirstNode;

		for(i=0;i<nodeIndex;i++)
		{
			pNode=pNode->pNextNode;
		}

	}
	return pNode;
}

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


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nodo= (Node*)malloc(sizeof(Node));
    Node* pNode;
    int cant = ll_len(this);

    if(this!=NULL && (nodeIndex<=cant && nodeIndex>=0))
    {
    	if(nodo!=NULL)
    	{
    		if(nodeIndex==0)
    		{
    			pNode=getNode(this,nodeIndex);
    			nodo->pNextNode=pNode;
    			this->pFirstNode=nodo;
    			returnAux=0;
    		}
    		else
    		{
    			pNode=getNode(this,nodeIndex-1);
				nodo->pNextNode=pNode->pNextNode;
				pNode->pNextNode=nodo;
				returnAux=0;
    		}
    		if(returnAux==0)
    		{
    			nodo->pElement=pElement;
    			cant++;
    			this->size=cant;
    		}

    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	addNode(this, ll_len(this), pElement);
    	returnAux=0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;

    int cant=ll_len(this);
    Node* pNode;
    pNode=getNode(this,index);

    if(pNode!=NULL && (index<cant && index>=0))
    {
    	returnAux=pNode->pElement;

    }
    return returnAux;
}


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
    int returnAux = -1;
    int cant=ll_len(this);
    Node* pNode;

	if(this!=NULL && index<cant && index>=0)
	{
		pNode = getNode(this, index);
		if(pNode!=NULL)
		{
			pNode->pElement=pElement;
			returnAux=0;
		}
	}
	return returnAux;
}


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
	int status = -1;
	int cant=ll_len(this);
	Node* pNode;
	Node* nodo;

	if(this!=NULL && index<cant && index>=0)
	{
		if(index == 0)
		{
			pNode = getNode(this, index);
			if(pNode != NULL)
			{
				this->pFirstNode = pNode->pNextNode;

				nodo = pNode;

				status = 0;
			}
		}
		else
		{
			pNode = getNode(this, index-1);
			if(pNode != NULL)
			{

				nodo = pNode->pNextNode;
				if(index == ll_len(this)-1)
				{
					pNode->pNextNode = NULL;
				}
				else
				{
					pNode->pNextNode = nodo->pNextNode;
				}
				status = 0;
			}
		}

		if(status == 0)
		{
			free(nodo->pElement);
			free(nodo);
			this->size--;
		}

	}

	return status;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1,i;
    int cant=ll_len(this);
    if(this!=NULL && cant>=0)
	{
    	for(i=0;i<cant;i++)
    	{
    		returnAux=ll_remove(this,i);
    		if(returnAux==-1)
    		{
    			break;
    		}
    	}
	}

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    int cant=ll_len(this);
    if(this!=NULL && cant>=0)
   	{

    	returnAux=ll_clear(this);
    	if(returnAux==0)
    	{
    		free(this);
    	}
   	}

    return returnAux;
}

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
    int returnAux = -1,i;
    int cant=ll_len(this);
    Node* pNode;
	if(this!=NULL)
	{
		for(i=0;i<cant;i++)
		{
			pNode=getNode(this, i);
			if(pNode!=NULL)
			{
				if(pNode->pElement==pElement)
				{
					returnAux=i;
					break;
				}
			}
		}

	}
    return returnAux;
}

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
    int returnAux;
    int cant=ll_len(this);
    if(this!=NULL&&cant>0)
    {
    	returnAux=0;
    }
    else
    {
    	if(this!=NULL)
    	{
    		returnAux=1;
    	}
    	else
    	{
    		returnAux=-1;
    	}
    }
    return returnAux;
}

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
    int returnAux = -1;
    int cant = ll_len(this);
    if(this!=NULL && (index<=cant && index>=0)&&cant>=0)
    {
		if(addNode(this, index, pElement)==0)
		{
			returnAux=0;
		}
    }
    return returnAux;
}


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
	void* returnAux = NULL;
	int cant = ll_len(this);
	if(this!=NULL && (index<=cant && index>=0)&&cant>=0)
	{
		returnAux=ll_get(this, index);
		if(returnAux!=NULL)
		{
			ll_remove(this, index);
		}
}

    return returnAux;
}


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
    int returnAux = -1;


    if(this!=NULL)
    {
    	if(ll_indexOf(this, pElement)==-1)
    	{
    		returnAux=0;
    	}
    	else
    	{
    		returnAux=1;
    	}
    }
    return returnAux;
}

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
    int returnAux = -1,i;
    void* pElemento;
    if(this!=NULL&&this2!=NULL)
    {
    	returnAux=0;
    	for(i=0;i<ll_len(this2);i++)
    	{
    		pElemento=ll_get(this2, i);
    		returnAux=ll_contains(this, pElemento);
    		if(returnAux==0)
    		{
    			break;
    		}
    	}
    }

    return returnAux;
}

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
    LinkedList* cloneArray = NULL;
    int i;
    void* estado;
    if(this!=NULL && from>=0 && from <=to  && to <=ll_len(this))
	{
    	cloneArray=ll_newLinkedList();
    	for(i=from;i<to;i++)
    	{
    		estado=ll_get(this, i);
    		if(estado!=NULL)
    		{
    			ll_add(cloneArray,estado);
    		}
    	}

	}
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray=NULL;

    cloneArray=ll_subList(this, 0, ll_len(this));
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
    int returnAux =-1,i,j;
    int cant = ll_len(this);
    void* pElement1;
    void* pElement2;

    if(this!=NULL && cant>0 && pFunc!=NULL && (order==0||order ==1))
    {
    	if(cant>=2)
    	{
    		for(i=0;i<cant-1;i++)
			{
				returnAux=1;
				for(j=i+1;j<cant;j++)
				{
					pElement1=ll_get(this, i);
					pElement2=ll_get(this, j);
					if(pElement1 !=NULL && pElement2 !=NULL)
					{
						if(order==1)
						{
							if(pFunc(pElement1,pElement2)>0)
							{
								ll_set(this, i, pElement2);
								ll_set(this, j, pElement1);
								returnAux=0;
							}
						}
						else
						{
							if(pFunc(pElement1,pElement2)<0)
							{
								ll_set(this, i, pElement2);
								ll_set(this, j, pElement1);
								returnAux=0;
							}
						}
					}
				}
				if(returnAux!=0)
				{
					break;
				}
			}
    	}
    	returnAux=0;
    }

    return returnAux;

}
LinkedList* ll_map (LinkedList* this, void*(*pFunc) (void* element))
{
    int lenList;
    void *auxElement;

    if(this != NULL && pFunc != NULL)
    {
        lenList=ll_len(this);
        if(lenList>0)
        {
          for(int i=0;i<lenList;i++)
          {
            auxElement=ll_get(this,i);

            if(auxElement != NULL)
            {
            	pFunc(auxElement);
            }
          }
        }
    }
    return this;
}
LinkedList* ll_filter (LinkedList* this, int (*pFunc) (void* element))
{
    LinkedList *filterList=NULL;
    int lenList;
    void *auxElement;

    if(this != NULL && pFunc != NULL)
    {
        filterList=ll_newLinkedList();

        lenList=ll_len(this);//INDEX DE ULTIMO ELEMENTO VA A SER MENOR AL TOTAL DE LOS ELEMENTOS.N-1
        if(filterList != NULL && lenList>0)
        {
          for(int i=0;i<lenList;i++)
          {
            auxElement=ll_get(this,i);

            if(auxElement != NULL && pFunc(auxElement)==1)
            {
             ll_add(filterList, auxElement);
            }
          }
        }
    }
    return filterList;
}
