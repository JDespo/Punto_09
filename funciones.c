#include "funciones.h"

STR_NODO *crearNodo(int dato)
{
    STR_NODO *nodo=(STR_NODO*)malloc(sizeof(STR_NODO));
    nodo->numero = dato;
    nodo->ste = NULL;

    return nodo;
}

void push(STR_NODO **pila, int dato)
{
    STR_NODO *nodo = crearNodo(dato);
    nodo->ste = *pila;
    *pila = nodo;
}

int pop(STR_NODO **pila)
{
    STR_NODO *aux = *pila;
    int dato = (*pila)->numero;

    *pila = aux->ste;
    free(aux);
    return dato;
}


void ordenarPila(STR_NODO **pila)
{
    STR_NODO *aux = NULL;
    STR_NODO *aux2 = NULL;

        while( pila != NULL)
        {
            
            int numero = pop(pila);
            if(aux == NULL)
            {
                push(&aux, numero);
            }
            else
            {
                while(aux!= NULL && numero >= aux->numero)
                {
                    push(&aux2, pop(&aux));
                }
                
                push(&aux, numero);

                while(aux2 != NULL)
                {   
                    push(&aux, pop(&aux2));
                }
            }
        }

        while(aux != NULL)
        {
            push(pila, pop(&aux));
        }
}
