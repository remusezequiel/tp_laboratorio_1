#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "variousfunctions.h"


/***************FUNCTIONS********************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
/*******************DESIGN FUNCTIONS*********************************************************/
//FUNCTION largeLine
void line(void)
{
    printf("_______________________________\n");
}

//FUNCTION largeLine
void largeLine(void)
{
    printf("__________________________________________________________________\n");
}
//FUNCTION optionMenu
void optionMenu(void)
{
    line();
    printf("\n \t MENU DE OPCIONES \n");
    printf(" \t 1.ALTAS \n");
    printf(" \t 2.MODIFICACIONES \n");
    printf(" \t 3.BAJAS \n");
    printf("\t 4.INFORMES \n");
    printf("\t 5.SALIR \n");
    line();
}
/*********************************************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
/***********GET FUNCTIONS********************************************************************/
//()FUNCTION getInt
/**
 * \brief Pide un número al usuario y devuelve el resultado
 * \param message Es el mensaje de pedido que ve el usuario por pantalla
 * \return Numero ingresado
 *
 */
int getInt(char* message)
{
    int number;

    printf("%s",message);
    scanf("%d",&number);

    return number;
}
//()FUNCTION getFloat
/**
 * \brief Pide un número al usuario y devuelve el resultado
 * \param message Es el mensaje de pedido que ve el usuario por pantalla
 * \return Numero ingresado
 */
float getFloat(char* message)
{
    float number;
    printf("%s",message);
    scanf("%f",&number);
    return number;
}
//()FUNCTION getChar
/**
 * \brief Pide un caracter al usuario y devuelve el resultado
 * \param message Es el mensaje de pedido que ve el usuario por pantalla
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char* message)
{
    char character;

    printf(" %s", message);
    fflush(stdin);
    scanf(" %c", &character);

    return character;
}
//()FUNCTION getString
/**
 * \brief Pide un texto al usuario y lo devuelve
 * \param message Es el mensaje de pedido que ve el usuario por pantalla
 * \param chargeArray es donde se va a cargar el array
 * \return void
 */
void getString(char* message,char* chargeArray)
{
    printf(" %s",message);
    fflush(stdin);
    scanf (" %s", chargeArray);
}
//()FUNCTION getOption
/** \brief Esta funcion pide una opcion al usuario y devuelve el valor que ingresa
 *              el usuario
 * \param void
 * \return el valor de la opcion elegida por el usuario
 *
 */
int getOption(void)
{
	int option;

	printf("Ingrese una opcion");
	scanf(" %d", &option);

	return option;
}


/*********************************************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
/**********VALIDATION FUNCTIONS***************************************************************/

//()FUNCTION itsNumericWhitFloat
/**
 * \brief Verifica si el valor recibido es numérico. Tambien admite floats
 * \param string Array con la cadena a ser analizada
 * \return TRUE -> es númerico / FALSE -> no lo es
 *
 */
int itsNumericWhitFloat(char* string)
{
   int pointCounter=0;
   int i=0;
   int turnBack;

   turnBack = FALSE;
   while(string[i] != '\0')
   {
       if (i == 0 && string[i] == '-')
       {
           i++;
           continue;

       }
       if (string[i] == '.' && pointCounter == 0)
       {
           pointCounter++;
           i++;
           continue;

       }
       if(string[i] < '0' || string[i] > '9')
           turnBack = TRUE;
       i++;
   }

   return turnBack;
}

//()FUNCTION itsNumericString
/**
 * \brief Esta funcion recive un string verifica si es numerico
 * \param string Array que se revisa
 * \return TRUE-> es numerico / FALSE -> no es numerico
 *
 */
int itsNumericString(char* string)
{
   int i=0;
   int turnBack;

   turnBack=FALSE;

   while(string[i] != '\0')
   {
       if (i == 0 && string[i] == '-')
       {
           i++;
           continue;
       }
       if(string[i] < '0' || string[i] > '9')
       {
           turnBack = TRUE;
       }

       i++;
   }

   return turnBack;
}
//FUNCTION isLettersString
/**
 * \brief Esta funcion verifica si el array tiene solo letras
 * \param string es el array que se revisa
 * \return TRUE-> es solo letras / FALSE -> no es solo letras
 *
 */
int isLettersString(char* string)
{
   int i=0;
   int turnBack;

   turnBack = FALSE;

   while(string[i] != '\0')
   {
       if((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
       {
            turnBack = TRUE;
       }

       i++;
   }

   return turnBack;
}

/**********************************************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
/**********GET VALIDATION FUNCTIONS************************************************************/

//()FUNCTION getLetterString
/**
 * \brief Pide un texto al usuario y lo devuelve validado
 * \param message Es el mensaje de pedido que ve el usuario por pantalla
 * \param chargeArray es donde se va a cargar el array que se quiere validar
 * \return TRUE -> contiene letras / FALSE -> no solo contiene letras
 */
int getLetterString(char* message,char* chargeArray)
{
    char auxChargeArray[LEN_AUX];
    int turnBack;

    getString(message,auxChargeArray);
    turnBack = FALSE;

    if(isLettersString(auxChargeArray))
    {
        strcpy(chargeArray,auxChargeArray);

        turnBack = TRUE;
    }

    return turnBack;
}
//()FUNCTION getNumberString
/**
 * \brief Pide un texto numérico al usuario y lo devuelve
 * \param message Es el mensaje de pedido que ve el usuario por pantalla
 * \param chargeArray es donde se va a cargar el array que se quiere validar
 * \return TRUE -> es numerico /FALSE-> no es numerico
 */
int getNumberString(char* message,char* chargeArray)
{
    char auxChargeArray[LEN_AUX];
    int turnBack;

    getString(message,auxChargeArray);
    turnBack = FALSE;

    if(itsNumericString(auxChargeArray))
    {
        strcpy(chargeArray,auxChargeArray);
        turnBack = TRUE;
    }

    return turnBack;
}
//()FUNCTION getStringsOf_float
/**
 * \brief Pide un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param message Es el mensaje de pedido que ve el usuario por pantalla
 * \param chargeArray es donde se va a cargar el array que se quiere validar
 * \return
 */
int getStringsOf_float(char* message,char* chargeArray)
{
    char auxChargeArray[LEN_AUX];
    int turnBack;

    turnBack=FALSE;
    getString(message,auxChargeArray);

    if(itsNumericWhitFloat(auxChargeArray)==TRUE)
    {
        strcpy(chargeArray,auxChargeArray);
        turnBack = TRUE;
    }

    return turnBack;
}
//()FUNCTION getValidInt
/**
 * \brief Pide un numero entero al usuario y lo valida
 * \param message Es el mensaje de pedido que ve el usuario por pantalla
 * \param errorMessage Aca se escribe como parametro un mensaje de error
 * \param downLimitSize Es el limite inferior aceptado
 * \param downLimitSize Es el limite superior aceptado
 * \param number es donde se carga la direccion del numero ingresado
 *
 * \return TRUE -> Es entero/ FALSE -> No es entero
 *
 */
int getValidInt(char* message,char* errorMessage, int* number,int downLimitSize, int upLimitSize)
{
    char auxString[LEN_AUX];
    int turnBack = FALSE;
    int auxNumber;
    int i;

    for(i=0; i<INTENTS; i++)
    {
        if (!getNumberString(message,auxString))
        {
            printf (" %s", errorMessage);
            break;
            continue;
        }

        auxNumber = atoi(auxString);

        if(auxNumber < downLimitSize || auxNumber > upLimitSize)
        {
            printf (" %s",errorMessage);
            continue;
        }

        *number = auxNumber;
        turnBack = 0;

        break;

    }

    return turnBack;

}
//()FUNCTION getValidFloat
/**
 * \brief Pide un numero flotante al usuario y lo valida
 * \param message Es el message a ser mostringado para Pider el dato
 * \param errorMessage Es el message a ser mostringado en caso de error
 * \param downLimitSize Es el limite inferior aceptado
 * \param downLimitSize Es el limite superior aceptado
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return TRUE -> si es valido / FALSE -> si no es float
 *
 */
int getValidFloat(char* message,char* errorMessage, float* input, float downLimitSize, float upLimitSize)
{
    char auxString[LEN_AUX];
    float auxNumber;
    int turnBack = FALSE;
    int i;

    for(i=0 ; i<INTENTS ;i++)
    {
        if (getStringsOf_float(message,auxString)==FALSE)
        {
            printf (" %s", errorMessage);
            break;
            continue;
        }

        auxNumber = atof( auxString );

        if(auxNumber < downLimitSize || auxNumber > upLimitSize)
        {
            printf (" %s", errorMessage);
            continue;
        }

        *input = auxNumber;
        turnBack = TRUE;

        break;
    }


    return turnBack;

}
//()FUNCTION getValidstringing
/**
 * \brief Pide un string y lo valida respecto del tamaño y si es de letras
 * \param message Es el mensaje que se va a mostrar pos pantalla al usuario
 * \param errorMessage Es el message de erroe en caso de que no sea un string de letras
 * \param sizeErrorMessage Es el mensaje de error
 * \param input Array donde se cargará el texto ingresado
 * \param maxSize int Longitud maxima del texto ingresado
 *
 * \return TRUE-> Esta cargado en el programa / FALSE-> no se ingresa o se pasa de los intentos
 *
 */
int getValidString(char* message,char* errorMessage, char* sizeErrorMessage,char* chargeArray, int maxSize)
{
    int i;
    char buffer[1024];
    int turnBack = FALSE;

    for(i=0;i<INTENTS;i++)
    {
        if (getLetterString(message,buffer)==TRUE)
        {
            printf (" %s \n",errorMessage);
            continue;
        }
        if(strlen(buffer) >= maxSize)
        {
            printf (" %s\n",sizeErrorMessage);
            continue;
        }

        turnBack = TRUE;
        strcpy(chargeArray,buffer);

        break;
    }

    return turnBack;
}

/**********************************************************************************************/

