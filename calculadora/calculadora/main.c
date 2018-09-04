#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
/******************COMENTARIOS***********************************************************************
 * 1 Enunciado
 *   Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
 *  1. Ingresar 1er operando (A=x)
 *  2. Ingresar 2do operando (B=y)
 *  3. Calcular todas las operaciones
 *   a) Calcular la suma (A+B)
 *   b) Calcular la resta (A-B)
 *   c) Calcular la division (A/B)
 *   d) Calcular la multiplicacion (A*B)
 *   e) Calcular el factorial (A!)
 *  4. Informar resultados
 *   a) “El resultado de A+B es: r”
 *   b) “El resultado de A-B es: r”
 *   c) “El resultado de A/B es: r” o “No es posible dividir por cero”
 *   d) “El resultado de A*B es: r”
 *   e) “El factorial de A es: r1 y El factorial de B es: r2”
 *   5. Salir
 *   • Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
 *   que contenga las funciones para realizar las cinco operaciones.
 *   • En el menú deberán aparecer los valores actuales cargados en los operandos A y B
 *   (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
 *   • Deberán contemplarse los casos de error (división por cero, etc)
 *   • Documentar todas las funciones
 * -> NOMBRE Y APELLIDO: EZEQUIEL REMUS
 * -> DIVICION: 1° C
****************************************************************************************************/


//*****************FUNCION PRINCIPAL*****************************************************************
int main()
{
    //VARIABLES:
    //int numeroFactorial;
    float numeroUno;
    float numeroDos;
    int opcion;
    int retornar=0;
    int retornarDos=0;


    //SENTENCIAS:
    do
    {
    //SE DAN A CONOCER LAS OPCIONES
        printf("Ingrese una de las siguientes opciones:\n");
        printf("1. Ingresar 1er operando. \n");
        printf("2. Ingresar 2do operando. \n");
        printf("3. Calcular todas las operaciones. \n");
        printf("4. Informar resultados.\n");
        printf("5. Salir. \n");

        opcion = ingresarOpcion();                //LLAMO A LA FUNCION INGRESAR OPCION

        switch(opcion)
        {
            case 1:                               //CASO QUE INGRESA EL PRIMER NUMERO
                printf("\n Ingresa el primer operando: \n");

                numeroUno = ingresarNumero();     //LLAMO A LA FUNCION INGRESAR NUMERO

                retornar=1;
            break;
            case 2:                               //CASO QUE INGRESA EL SEGUNDO NUMERO

                if(retornar==1)
                {
                    printf("\n Ingresa el segundo operando: \n");
                    numeroDos= ingresarNumero();      //LLAMO A LA FUNCION INGRESAR NUMERo
                    retornarDos = 1;
                    retornar=0;
                }
                else
                {
                    printf("\n Primero debes ingresar el primer operando: \n");
                }
            break;
            case 3:
                printf("\n Estas realizando las operaciones \n");
                if(retornar==0 && retornarDos==1)
                {
                    retornar=1;
                    retornarDos=0;
                    sumar(numeroUno,numeroDos);       //LLAMO A LA FUNCION SUMA
                    resta(numeroUno,numeroDos);       //LLAMO A LA FUNCION RESTA
                    producto(numeroUno,numeroDos);    //LLAMO A LA FUNCION PRODUCTO
                    division(numeroUno,numeroDos);    //LLAMO A LA FUNCION DIVICION
                    factorial((int)numeroUno);      //LLAMO A LA FUNCION FACTORIAL
                }
                else
                {
                    printf("\n Primero debes ingresar el primer operando y el segundo \n");
                }

            break;
            case 4:
                printf("\n Los resultados de las operaciones son: \n");

                if(retornar==1 && retornarDos==0)
                {
                    retornar=0;
                    //ESCRIBO RESULTADOS EN PANTALLA
                    printf("Suma: %f\n", sumar(numeroUno,numeroDos));
                    printf("Resta: %f\n", resta(numeroUno,numeroDos));
                    printf("Producto: %f\n", producto(numeroUno,numeroDos));
                    printf("Division: %f\n", division(numeroUno,numeroDos));
                    printf("Factorial del primer numero: %d\n", factorial(numeroUno));
                    printf("Factorial del segundo numero: %d\n", factorial(numeroDos));
                }
                else
                {
                    printf("\n Primero debes ingresar el primer operando y el segundo \n");
                }
            break;
            case 5:
            break;
            default :
                printf("\n No es una opcion valida\n");
        }
       // system("pause");
    }while(opcion < 5);


    return 0;
}
//***************************************************************************************************









