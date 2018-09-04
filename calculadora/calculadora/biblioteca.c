//****************************FUNCIONES**************************************************************
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
/**FUNCION INGRESAR NUMERO***************************************************************************
*\brief Solicita un valor y lo devuelve.
*\param Ninguno.
*\return Devuelve El valor ingresado. Luego la variable en main adquiere el valor de "numero".
 *****************************************************************************************************/
float ingresarNumero(void)
{
    float numero;

    printf("\n Ingrese un numero:");
    scanf(" %f", &numero);

    return numero;
}

/**FUNCION INGRESAR OPCION***************************************************************************
*\brief Solicita un valor y lo devuelve.
*\param Ninguno.
*\return Devuelve el valor de la opcion. Luego la variable en main adquiere el valor de "opcion".
*****************************************************************************************************/
int ingresarOpcion(void)
{
    int opcion;

    printf("ingrese una opcion:");
    scanf(" %d", &opcion);

    return opcion;
}

/**FUNCION SUMA**************************************************************************************
*\brief Recive dos numeros, los suma y devuelve el resultado
*\param numeroUno y numeroDos
*\return Devuelve el valor de la suma
*****************************************************************************************************/
float sumar(float numeroUno,float numeroDos)
{
    float suma;

    suma=numeroUno+numeroDos;

    //printf("La suma es: %f\n", suma);

    return suma;
}

/**FUNCION RESTA*************************************************************************************
*\brief Recive dos numeros, los resta y devuelve el resultado
*\param numeroUno y numeroDos
*\return Devuelve el valor de la resta
*****************************************************************************************************/
float resta(float numeroUno,float numeroDos)
{
    float resta;

    resta = numeroUno-numeroDos;

    //printf("La resta es: %f \n", resta);

    return resta;
}

/**FUNCION PRODUCTO**********************************************************************************
*\brief Recive dos numeros, los multiplica y devuelve el resultado
*\param numeroUno y numeroDos
*\return Devuelve el producto
*****************************************************************************************************/
float producto(float numeroUno,float numeroDos)
{
    float producto;

    producto=numeroUno*numeroDos;

    //printf("El producto es: %f\n", producto);

    return producto;
}

/**FUNCION DIVISION**********************************************************************************
*\brief Recive dos numeros, los divide y devuelve el resultado
*\param numeroUno y numeroDos
*\return El valor de la division
*****************************************************************************************************/
float division(float numeroUno,float numeroDos)
{
    float division;

    if(numeroDos!=0)
    {
    division=(float)numeroUno/(float)numeroDos;
    }
    else
    {
        printf("No esta definido dividir por 0");
    }
    //printf("La division es: %f\n", division);

    return division;
}

/**FUNCION FACTORIAL*********************************************************************************
*\brief Recive un numero, lo factoriza y devuelve el resultado
*\param numeroFactorial
*\return El valor del factorial
*****************************************************************************************************/
int factorial(int numeroFactorial)
{
    int factorial = 1;
    int numero;

    numero = numeroFactorial;

    if (numero == 0)
        {
            factorial = 1;
        }
    else
        {
            for (numero = numeroFactorial; numero > 1; numero--)
                {
                    factorial = factorial * numero;
                }
        }

    //printf("El factorial del numero es: %d \n", factorial);

    return factorial;
}
