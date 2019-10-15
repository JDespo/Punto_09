#include "funciones.h"


int main()
{
    STR_NODO *pila = NULL;
    int nNum []= {8, 4, 3, 5, 9, 1, 6};
    
    printf("\nLos numeros a ordenar son : ");
   
    int i = 0;
    while(i < 7)
    {
        printf("  [%i] ", nNum[i]);
        push(&pila, nNum[i]);
        i++;
    }

    STR_NODO *aux = NULL;
    STR_NODO *aux2 = NULL;

        while( pila != NULL)
        {
            
            int numero = pop(&pila);
            if(aux == NULL)
            {
                push(&aux, numero);
                printf("\nNULL: AUX->NUM: %i\n",aux->numero);
            }
            else{
                printf("\nAUX->NUM: %i\n",aux->numero);
                printf("NUM: %i\n",numero);
                while(numero >= aux->numero)
                {
                    printf("WHILE AUX->NUM: %i\n",aux->numero);
                    
                    push(&aux2, pop(&aux));
                    printf("\npushaux2 -> pop aux %i\n",aux2->numero);
                    
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
            push(&pila, pop(&aux));
        }

    while(pila != NULL)
    {
        printf("Pila Num: %i\n", pop(&pila));
    }
}