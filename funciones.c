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


    int numero = pop(pila);
    push(&aux, numero);
    printf("\n\n\tPRIMER PASO: \nnumero = pop(pila) %i // push(&aux, numero) %i\n", numero);

    printf("\n\t..:: COMIENZO WHILE ORDENAMIENTO ::.. \n while( *pila != NULL)\n");
        while( *pila != NULL)
        {   
            numero = pop(pila);

            printf("\nWHILE aux != NULL && numero >= aux->numero\n");

            while(aux!= NULL && numero <= aux->numero)
            {       
                printf("\n\t push(&aux2), pop(&aux)) %i\n", aux->numero);
                push(&aux2, pop(&aux));
            }
            printf("\nFINALIZO WHILE aux != NULL && numero >= aux->numero\n\n");
            
            push(&aux, numero);
            printf("\n ..::AL NUM[%i] LO GUARDO EN AUX::..\n",numero);

            printf("\nWhile(aux2 != NULL) \n");
            while(aux2 != NULL)
            {   
                printf("\n\t push(&aux), pop(&aux2)) %i\n", aux2->numero);
                push(&aux, pop(&aux2));
            }
            printf("\nFINALIZA While(aux2 != NULL) //\n");
        }

        printf("\n\t..:: FINALIZA WHILE ORDENAMIENTO ::.. \n");

        printf("\nwhile(aux != NULL) \n");
        while(aux != NULL)
        {
            printf("\n\t push(pila), pop(&aux)) %i\n", aux->numero);
            push(pila, pop(&aux));
        }
        printf("\nFINALIZA while(aux != NULL) \n");
}
