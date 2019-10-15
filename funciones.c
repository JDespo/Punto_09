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
                printf("\nNULL: AUX->NUM: %i\n",aux->numero);
            }
            else{
                printf("\nAUX->NUM: %i\n",aux->numero);
                printf("PILA: %i\n",numero);
                while(aux!= NULL && numero >= aux->numero)
                {
                    printf("WHILE AUX->NUM: %i\n",aux->numero);
                    push(&aux2, pop(&aux));
                    printf("\npush aux2 -> pop aux %i\n",aux2->numero);
                }
                
                push(&aux, numero);
                printf("GUARDO NUM EN AUX\n");

                while(aux2 != NULL)
                {   
                    printf("push aux pop aux2\n");
                    push(&aux, pop(&aux2));
                }
            }
        }

        while(aux != NULL)
        {
            push(pila, pop(&aux));
        }
}
