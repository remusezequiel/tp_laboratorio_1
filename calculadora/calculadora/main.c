#include <stdio.h>
#include <stdlib.h>
/******************COMENTARIOS***********************************************************************
 * La calculadora toma valores flotantes y devuelve valores flotantes, exepto cuando se factoriza.
 * Hay una funcion para cada tarea realizada. Es decir, una que pide que ingreses la opcion, otra
 * para ingresar un numero y luego una para cada operacion matematica.
 *
 * -> NOMBRE Y APELLIDO: EZEQUIEL REMUS
 * -> DIVICION: 1° C
****************************************************************************************************/

//****************DECLARACION DE FUNCIONES***********************************************************
int ingresarOpcion(void);
float ingresarNumero (void);
float sumar(float,float);
float resta(float,float);
float producto(float,float);
float division(float,float);
int factorial(int);
//***************************************************************************************************

//*****************FUNCION PRINCIPAL*****************************************************************
int main()
{
    //VARIABLES:
    int numeroFactorial;
    float numeroUno;
    float numeroDos;
    int opcion;

    //SE DAN A CONOCER LAS OPCIONES
    printf("Ingrese una de las siguientes opciones:\n");
    printf("1) Suma\n");
    printf("2) Resta\n");
    printf("3) Producto\n");
    printf("4) Divicion\n");
    printf("5) Factorial\n");

    //SENTENCIAS:
    do
    {
        opcion = ingresarOpcion();                //LLAMO A LA FUNCION INGRESAR OPCION

        switch(opcion)
        {
            case 1:                               //CASO DE LA SUMA
                printf("Estas sumando\n");

                numeroUno = ingresarNumero();     //LLAMO A LA FUNCION INGRESAR NUMERO
                numeroDos = ingresarNumero();     //LLAMO A LA FUNCION INGRESAR NUMERO

                sumar(numeroUno,numeroDos);       //LLAMO A LA FUNCION SUMA
            break;
            case 2:                               //CASO DE LA RESTA
                printf("Estas restando");

                numeroUno= ingresarNumero();      //LLAMO A LA FUNCION INGRESAR NUMERO
                numeroDos= ingresarNumero();      //LLAMO A LA FUNCION INGRESAR NUMERO

                resta(numeroUno,numeroDos);       //LLAMO A LA FUNCION RESTA
            break;
            case 3:
                printf("Estas multiplicando");

                numeroUno= ingresarNumero();      //LLAMO A LA FUNCION INGRESAR NUMERO
                numeroDos= ingresarNumero();      //LLAMO A LA FUNCION INGRESAR NUMERO

                producto(numeroUno,numeroDos);    //LLAMO A LA FUNCION PRODUCTO
            break;
            case 4:
                printf("Estas dividiendo");

                numeroUno= ingresarNumero();      //LLAMO A LA FUNCION INGRESAR NUMERO
                numeroDos= ingresarNumero();      //LLAMO A LA FUNCION INGRESAR NUMERO

                division(numeroUno,numeroDos);    //LLAMO A LA FUNCION DIVICION
            break;
            case 5:
                printf("Estas factorizando");

                numeroFactorial= ingresarNumero();//LLAMO A LA FUNCION INGRESAR NUMERO

                factorial(numeroFactorial);      //LLAMO A LA FUNCION FACTORIAL
                break;
            default :
                printf("no es una opcion valida");
        }

        system("pause");

    }while(opcion < 6);

    return 0;
}
//***************************************************************************************************

//****************************FUNCIONES**************************************************************
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

    printf("La suma es: %f\n", suma);

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

    printf("La resta es: %f \n", resta);

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

    printf("El producto es: %f\n", producto);

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

    printf("La division es: %f\n", division);

    return division;
}

/**FUNCION FACTORIAL*********************************************************************************
*\brief Recive un numero, lo factoriza y devuelve el resultado
*\param numeroUno y numeroDos
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

    printf("El factorial del numero es: %d \n", factorial);

    return factorial;
}







