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

    printf("\n Ingrese un numero: \n");
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

    printf("\n Ingrese una opcion: \n");
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

    division=(float)numeroUno/(float)numeroDos;

    return division;
}

/**FUNCION FACTORIAL*********************************************************************************
*\brief Recive un numero, lo factoriza y devuelve el resultado
*\param EL parametro va a ser numero. Aca numero tomara el valor ingresado
    (numeroUno o numeroDos) y va a realizar las operaciones
*\return El valor del factorial
*****************************************************************************************************/
int factorial(float numero)
{
    int factorial = 1;
    int enteroDelNumero;

    enteroDelNumero=(int)numero;

    if (numero == 0)
    {
        factorial = 1;
    }
    else if ((numero - enteroDelNumero) == 0 )
    {
        for (numero = numero; numero >= 1; numero--)
        {
            factorial = factorial * numero;
        }
    }
    return factorial;
}

/********************************************************************************************/
