#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "variousfunctions.h"

#define ILIGIC -1
#define TRUE 1
#define FALSE 0


//()FUNCTION generarNextId
int generarNextId()
{
    static int id = -1;
    id ++;
    return id;
}
//()FUNCION INGRESAO ID
int getId(int size)
{
	int id;
	do
	{
		printf("Ingrese su numero de identificación: \n");
		scanf(" %d", &id);
		if(id>size)
        {
            printf("ERROR, EL ID INGRESADO NO EXISTE!\n");
        }
	}while( id > size );//ya que se auto genera y se suma de a uno
	return id;
}
//FUNCION getOption
int getOption(char* message,char* errorMessage,int lowLimitOption, int hiLimitOption)
{
    int turnBack;
    int option;
    option=getInt(message);
    turnBack=option;
    if(lowLimitOption>option || hiLimitOption<option)
    {
        puts(errorMessage);
        turnBack=FALSE;
    }

    return turnBack;
}
//FUNCION getAnswer
int getAnswer(char* message, char* errorMessage, char afirmativeChar, char negativeChar)
{
	char answer;
	int turnBack;
	printf(" %s",message);
    fflush(stdin);
    scanf(" %c", &answer);
	if(answer!=afirmativeChar && answer!=negativeChar)
    {
        puts(errorMessage);
    }
	if(answer == afirmativeChar)
	{
		turnBack=TRUE;
	}
	else if(answer == negativeChar)
	{
		turnBack=FALSE;
	}
	return turnBack;

}
/***************FUNCTIONS********************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
/*******************DESIGN FUNCTIONS*********************************************************/
//FUNCTION largeLine
void line(void)
{
    printf("__________________________________________\n");
}
//FUNCTION largeLine
void largeLine(void)
{
    printf("____________________________________________________________________________________________________________________\n");
}
//FUNCION lineaPunteada
void lineaPunteada(void)
{
    printf("-------------------------------------------\n");
}
//FUNCTION optionMenuMain
void optionMenu(void)
{
    largeLine();
    printf("\t  MENU DE OPCIONES \n");
    largeLine();
    printf("\t  1. Alta de empleado.\n");
    printf("\t  2. Modificar datos de empleado. \n");
    printf("\t  3. Baja de empleado. \n");
    printf("\t  4. Informes. \n");
    printf("\t  \t 1. Listado de los empleados ordenados alfabeticamente por apellido y sector.\n");
    printf("\t  \t 2. Total y promedio de los salarios y cuantos empleados superan el salario promedio. \n");
    printf("\t  5. Salir. \n");
    largeLine();
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
 * \param message Es el message a ser mostringado
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
 * \param message Mensaje que se muestringa
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
 * \param message Mensaje que se muestringa
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char* message)
{
    char character;

    printf(" %s", message);
    fflush(stdin);
    scanf(" %c \n", &character);

    return character;
}
//()FUNCTION getString
/**
 * \brief Pide un texto al usuario y lo devuelve
 * \param message Es el message a ser mostringado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char* message,char* chargeArray)
{
    printf(" %s",message);
    fflush(stdin);
    scanf (" %s",chargeArray);

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
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int itsNumericWhitFloat(char* string)
{
   int retorno=0;
   int pointCounter=0;
   int i=0;

   while(string[i] != '\0')
   {
       if (i==0 && string[i]=='-')
       {
           i++;
           continue;
       }
       if (string[i]=='.' && pointCounter==0)
       {
           pointCounter++;
           i++;
           continue;

       }
       if(string[i]<'0' || string[i]>'9')
       {
            retorno=1;
       }
       i++;
   }

   return retorno;
}

//()FUNCTION itsNumericString
/**
 * \brief Verifica si el valor recibido es numérico
 * \param string Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
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
 * \brief Verifica si el valor recibido contiene solo letras
 * \param string Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
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
 * \brief Pide un texto al usuario y lo devuelve
 * \param message Es el message a ser mostringado
 * \param input Array donde se cargará el texto ingresado
 * \return TRUE->contiene letras / FALSE->no solo contiene letras
 */
int getLetterString(char* message,char* chargeArray)
{
    char auxChargeArray[LEN_AUX];
    int turnBack;

    getString(message,auxChargeArray);//muestro el mensaje y lo cargo en el auxiliar
    turnBack = FALSE;

    if(isLettersString(auxChargeArray)==TRUE)
    {
        strcpy(chargeArray,auxChargeArray);

        turnBack = TRUE;
    }

    return turnBack;
}
//()FUNCTION getNumberString
/**
 * \brief Pide un texto numérico al usuario y lo devuelve
 * \param message Es el message a ser mostringado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getNumberString(char* message,char* chargeArray)
{
    char auxChargeArray[LEN_AUX];
    int turnBack;

    getString(message,auxChargeArray);
    turnBack = FALSE;

    if(itsNumericString(auxChargeArray)==TRUE)
    {
        strcpy(chargeArray,auxChargeArray);
        turnBack = TRUE;
    }

    return turnBack;
}
//()FUNCTION getStringsOf_float
/**
 * \brief Pide un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param message Es el message a ser mostringado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringsOf_float(char* message,char* chargeArray)
{
    char auxChargeArray[LEN_AUX];

    getString(message,auxChargeArray);

    if(itsNumericWhitFloat(auxChargeArray))
    {
        strcpy(chargeArray,auxChargeArray);
        return 1;
    }
    return 0;
}
//()FUNCTION getLimitedString
/** \brief Esta funcion toma un array, lo cuenta y si se pasa del limite
 *      de caracteres devuelve un error
 * \param message char* mesaje de pedido al usuario
 * \param errorMessage char* mensaje de error que se le muestra al usuario
 * \param array char* es el array donde se va a cargar lo escrito por el usuario
 * \param maxSize int cantidad de caracteres
 * \return int TRUE->Si no se pasa / FALSE -> si se pasa
 *
 */
int getLimitedString(char* message,char* errorMessage,char* array,int maxSize)
{
	char buffer[1024];
	int turnBack;
	int i;


	for(i=0;i<INTENTS;i++)
	{
		getString(message,buffer);
		if(buffer[i]==' ')
        {
            continue;
        }
		if(strlen(buffer) >= maxSize)
		{
			printf ("%s",errorMessage);
			turnBack = FALSE;
		}
		if(strlen(buffer) < maxSize)
		{
			turnBack = TRUE;
			break;
			continue;
		}

	}
	strcpy(array,buffer);
	return turnBack;
}
//()FUNCTION getValidInt
/**
 * \brief Pide un numero entero al usuario y lo valida
 * \param message Es el message a ser mostringado para Pider el dato
 * \param errorMessage Es el message a ser mostringado en caso de error
 * \param downLimitSize Es el limite inferior aceptado
 * \param downLimitSize Es el limite superior aceptado
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int getValidInt(char* message,char* errorMessage,
                char* errorMessageSize, int* number,
                int downLimitSize, int upLimitSize)
{
    char auxString[LEN_AUX];
    int turnBack = FALSE;
    int auxNumber;
    int i;

    for(i=0; i<INTENTS; i++)
    {
        getString(message,auxString);
        if (!isLettersString(auxString))
        {
            printf (" %s", errorMessage);
            continue;
        }

        auxNumber = atoi(auxString);//Se le da el valor del entero guardado en auxString en auxNumber

        if(auxNumber < downLimitSize || auxNumber > upLimitSize)
        {
            printf ("%s",errorMessageSize);
            continue;
        }
        if(isLettersString(auxString) && (auxNumber > downLimitSize || auxNumber < upLimitSize))
        {
            *number = auxNumber;
            turnBack = TRUE;
            break;
        }
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
        if (!getStringsOf_float(message,auxString))
        {
            printf (" %s", errorMessage);
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
 * \return
 *
 */
int getValidString(char* message,char* errorMessage, char* sizeErrorMessage,char* chargeArray, int maxSize)
{
    int i;
    char buffer[1024];
    int turnBack = FALSE;

    for(i=0; i<INTENTS ;i++)
    {
        getString(message,buffer);
        if (isLettersString(buffer)!=FALSE)
        {
            printf ("%s",errorMessage);
            continue;
        }
        if(strlen(buffer) >= maxSize)
        {
            printf ("%s",sizeErrorMessage);
            continue;
        }

        turnBack = TRUE;
        strcpy(chargeArray,buffer);

        break;
    }

    return turnBack;
}

/**********************************************************************************************/

/**********************************************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
/********************SHOW FUNCTIONS************************************************************/
//FUNCION showMessageInt
/** \brief Esta funcion muestra un mensaje y un numero entero en pantalla
 *
 * \param message char* el mensaje que se muestra en pantalla
 * \param showInt int el numero a mostrar en pantalla
 * \return int el numero a mostrar en pantalla
 *
 */
int showMessageInt(char* message,int showInt)
{
    printf("\n %s", message);
    printf(" %d\n", showInt);

    return showInt;
}
//FUNCION showMessageFloat_2
/** \brief Esta funcion Muestra un mensaje en pantaya y luego un float
 *          siendo este con 2 digitos despues de la coma.
 * \param message char* Mensage que se le muestra al usuario
 * \param showFloat float Es el numero que se muestra
 * \return float el numero que se va a mostrar
 *
 */
float showMessageFloat_2(char* message,float showFloat)
{
    printf(" %s", message);
    printf(" %.2f \n", showFloat);

    return showFloat;
}
//FUNCION showMessageFloat_3
/** \brief Esta funcion Muestra un mensaje en pantaya y luego un float
 *          siendo este con 3 digitos despues de la coma.
 * \param message char* Mensage que se le muestra al usuario
 * \param showFloat float Es el numero que se muestra
 * \return float el numero que se va a mostrar
 *
 */
float showMessageFloat_3(char* message,float showFloat)
{
    printf(" %s", message);
    printf(" %.3f \n", showFloat);

    return showFloat;
}
//FUNCION showMessageFloat_4
/** \brief Esta funcion Muestra un mensaje en pantaya y luego un float
 *          siendo este con 4 digitos despues de la coma.
 * \param message char* Mensage que se le muestra al usuario
 * \param showFloat float Es el numero que se muestra
 * \return float el numero que se va a mostrar
 *
 */
float showMessageFloat_4(char* message,float showFloat)
{
    printf(" %s", message);
    printf(" %.4f \n", showFloat);

    return showFloat;
}
//FUNCION showCharacter
/** \brief Esta funcion muestra un mensaje y luego un caracter
 *
 * \param message char* mensaje que se muestra
 * \param character char el caracter a ser mostrado
 * \return char el caracter a ser mostrado
 *
 */
char showCharacter(char* message, char character)
{
    printf(" %s", message);
    printf(" %c\n", character);
    return character;
}

//FUNCION showString
/** \brief Esta funcion muestra un mensaje de error si el array que se quiere
 *      mostrar tiene mas caracteres de los que puede tener
 *
 * \param errorMessage char* mensaje de error a mostrar
 * \param chargeArray char* array ya cargado que se desea mostrar
 * \param chargeArraySize int el tamaño del array cargado que se desea mostrar
 * \return int FALSE-> error / TRUE -> se muestra el array
 *
 */
int showString(char* errorMessage,char* chargeArray,int chargeArraySize)
{
    int turnBack;

    if(strlen(chargeArray)==0 || strlen(chargeArray) > chargeArraySize-1)
    {
        printf(" %s",errorMessage);
        turnBack = FALSE;
    }
    else
    {
        puts(chargeArray);
        turnBack = TRUE;
    }
    return turnBack;
}

/**********************************************************************************************/


