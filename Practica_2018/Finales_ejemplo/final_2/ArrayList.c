#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void** pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));//pido espacio para el array una sola vez

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );//pido espacio para los datos, pElements
        if(pElements != NULL)
        {
            this->size=0;
            this->maxId=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            this->map = al_map;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int flag=1;

    if(this!=NULL && pElement!=NULL)
    {
        if(this->size==this->reservedSize)
        {
            if(resizeUp(this)==0)//creo el nuevo espacio de memoria
            {
            }
            else
            {
                flag=0;
            }
        }

        if(flag==1)
        {
            *(this->pElements+this->size)=pElement;// si no necesita mas espacio lo asigno directo
            this->size++;
            returnAux=0;
        }

    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;

    if (this!=NULL)
    {
        free(*this->pElements);
        free(this);
        returnAux=0;
    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;
    if (this!=NULL)
    {
        returnAux=this->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;
    if (this!=NULL)
    {
        if(index<this->size)
        {
            returnAux=*(this->pElements+index);
        }

    }
    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int flag=0;
    if (this!=NULL && pElement!=NULL)
    {
        for (i=0; i<this->reservedSize; i++)
        {
            if(pElement==*(this->pElements+i))
            {
                returnAux =1;
                flag=1;
                break;
            }
        }
        if (flag==0)
        {
            returnAux=0;
        }

    }
    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;
    int i;

    if (this!=NULL && pElement!=NULL)
    {
        if(index<this->size & index>=0)
        {
            *(this->pElements+index)=pElement;
            returnAux=0;
        }

    }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;
    int aux;
    int i;
    if (this!=NULL)
    {
        returnAux=contract(this, index);
        if (returnAux!=-1)
        {
            this->size--;
            resizeDown(this);
        }

    }

    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;
    if (this!=NULL)
    {
        this->size=0;
        resizeDown(this);
        returnAux=0;
    }
    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;

    int i;

    if (this!=NULL)
    {
        returnAux=al_newArrayList();
        if(returnAux!=NULL)
        {
            for(i=0; i<(this->reservedSize); i++)
            {
                if (*(this->pElements+i)!=NULL)
                {
                    al_add(returnAux,*(this->pElements+i));
                }
            }
        }
    }

    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;
    int flag=0;
    int i;

 //printf("DATOS------index :%d--------size: %d------reservedSize: %d\n\n", index, this->size, this->reservedSize);


    if(this!=NULL && pElement!=NULL )
    {
      // printf("EL PUNTERO NO ES NULL------index :%d--------size: %d------reservedSize: %d\n\n", index, this->size, this->reservedSize);

        if ((index>=0 && index<this->size)|| this->size==index)
        {
          //   printf("-----index :%d--------size: %d------reservedSize: %d\n\n", index, this->size, this->reservedSize);

            if (index==this->size)
            {
                returnAux= al_add(this, pElement);
               //  printf("ADD------index :%d--------size: %d------reservedSize: %d\n\n", index, this->size, this->reservedSize);
            }
            else
            {
                if (expand(this,index)==0)
                {
                    returnAux= al_set(this, index, pElement);
                    this->size++;
                  //  printf("SETTTTTTT------index :%d--------size: %d------reservedSize: %d\n\n", index, this->size, this->reservedSize);
                }

            }

        }//if index>=0 && index<=this->size
        //  else
        // printf("INDEX INVALIDO------index :%d--------size: %d------pelement: %p\n", index, this->size, pElement);


    }//if NULLS

    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
*/
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    if(this!=NULL && pElement!=NULL)
    {
        for(i=0; i<this->size; i++)
        {
            if( pElement==*(this->pElements+i))
            {
                returnAux=i;
                break;
            }
        }
        returnAux=i;
    }
    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if( this->size==0)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL && index >=0 && index<=this->size)
    {
        returnAux=*(this->pElements+index);
        al_remove(this,index);
    }


    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
*/
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    void* returnAux = NULL;
    int i;
    int auxFrom;
    int auxTo;
    int j;

    if(this!=NULL)
    {
      //  printf("from: %d, to: %d size:%d \n", from, to, this->size);
        if (from <this->size &&from >=0 && to<=this->size&& to>=0 &&from<=to)
            {
        returnAux=al_newArrayList();
        if(returnAux!=NULL)
        {

                 for(i=0; i<to; i++)
                {
                    if (*(this->pElements+from+i)!=NULL )
                    {
                    al_add(returnAux,*(this->pElements+from+i));
                    }
                }
            }
        }

    }
    return returnAux ;
}

/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int returnAux = -1;
    int contador=0;
    int i ;

    if(this!=NULL&& this2!=NULL)
    {
        if( this->size >= 0 && this2->size >= 0 )
        {
            returnAux=0;

            for(i=0; i<this->size; i++)
            {
                if (*(this->pElements+i)==*(this2->pElements+i))
                {
                    contador++;
                }
            }



            if (contador==this2->size)
            {
                returnAux=1;

            }
            // printf("this: %d ---- this2: %d --contador:%d  --retorno:%d  \n",this->size, this2->size, contador, returnAux);
        }

    }

    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    int i;
    int j;
    int* auxiliar;
    int contador=0;

    if(this!=NULL&& pFunc!=NULL && (order==0 || order==1))
    {
         auxiliar=(void*)malloc(sizeof(int));
        if (auxiliar !=NULL)
        {
            for(i=0; i<this->size-1; i++)
            {
                for(j=i+1; j<this->size; j++)
                {
                    if (order==0) //UP
                    {
                        if( pFunc(*(this->pElements+i), *(this->pElements+j))==-1)
                        {
                            auxiliar=al_get(this, i);
                            al_set (this, i, al_get(this, j));
                            al_set (this, j, auxiliar);
                        }
                        returnAux=0;
                    }

                    if (order==1) //DOWN
                    {
                        if( pFunc(*(this->pElements+i), *(this->pElements+j))==1)
                        {
                           /* auxiliar=*(this->pElements+i);
                            *(this->pElements+i)= *(this->pElements+j);
                            *(this->pElements+j)=auxiliar;*/

                            auxiliar=al_get(this, i);
                            al_set (this, i, al_get(this, j));
                            al_set (this, j, auxiliar);

                        }
                        returnAux=0;
                    } //for j
                }
            } //for i
        }


    }

return returnAux;
}

/** \brief FILTRAR objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
ArrayList* al_filter(ArrayList* this, int (*pFunc)(void*))
{
    int i;
    int size=0;
    int* auxiliar;

    ArrayList*lista;
    int contador=0;

    if(this!=NULL&& pFunc!=NULL)
    {
        lista=al_newArrayList();
        auxiliar=(void*)malloc(sizeof(int));
        if (auxiliar !=NULL && lista!=NULL)
        {
            for (i=0; i<(this->len(this)); i++)
            {
                if(pFunc(*(this->pElements+i)))
                {
                    auxiliar=al_get(this, i);
                    size++;
                    if (resizeUp(lista)==-1)
                    {
                        break;
                    }
                    else
                    {
                       al_add(lista, auxiliar);
                    }
                }

            }

        } //for j
    }

return lista;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    int auxsize;
    void** aux;

    if (this!=NULL)
    {
        if(this->size==this->reservedSize)//si el size es igual al espacio reservado
        {
            auxsize=this->reservedSize+AL_INCREMENT;
            aux=(void**)realloc(this->pElements, sizeof(void*)*auxsize);
            if (aux!=NULL)
            {
                this->pElements=aux;
                this->reservedSize=auxsize;
                returnAux=0;
            }
        }

    }
    else
    {
        returnAux=-1;
    }
    return returnAux;
}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1;
    int aux;
    int i;
    int flag=0;

    if (this!=NULL)
    {
        if (resizeUp(this)==0);//creo el nuevo espacio de memoria
        {
            if(index<=this->size )
            {
                for(i=(this->size-1); i>=index; i--)
                {
                    this->pElements[i+1]=this->pElements[i];
                    flag=1;
                }
                returnAux=0;
            }
        }

    }

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;
    int aux;
    int i;
    int flag;

    if (this!=NULL)
    {
        if(index <this->size)
        {
            flag=1;
            for(i=index; i<this->size; i++)
            {
                this->pElements[i]=this->pElements[i+1];
                returnAux=0;

            }
        }
        if (flag ==1)
        {
            resizeDown(this);
        }
    }



    return returnAux;
}

/** \brief contract the number of elements in pList in the difference between the size and the reserve sized
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeDown(ArrayList* this)
{
    int returnAux = -1;
    int auxsize;
    void** aux;

    if (this!=NULL)
    {

        if((this->reservedSize-this->size)>AL_INCREMENT );
        {
            auxsize=AL_INCREMENT+this->size;

            aux=(void**)realloc(this->pElements, sizeof(void*)*auxsize);
            if (aux!=NULL)
            {
                this->pElements=aux;
                this->reservedSize=auxsize;
                returnAux=0;
            }
        }

    }
    return returnAux;
}


/** \brief calcula sueldo objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_map(ArrayList* this, int (*pFunc)(void*))
{
    int returnAux = -1;
    int i;

    if(this!=NULL&& pFunc!=NULL)
    {

            for(i=0; i<this->len(this); i++)
            {
                 if( pFunc(*(this->pElements+i)))
                        {
                        returnAux=0;
                        }

            }



    }
    return returnAux;
}
