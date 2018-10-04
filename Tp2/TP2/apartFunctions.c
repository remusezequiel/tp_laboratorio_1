#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apartFunctions.h"

/***************FUNCTIONS********************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
/***********GET FUNCTIONS********************************************************************/
//(1)FUNCTION getInt
int getInt(char* message)
{
    int number;

    printf(" %s", message);
    scanf(" %d", &number);

    return number;
}
//(2)FUNCTION getFloat
float getFloat(char* message)
{
    float number;

    printf(" %s", message);
    scanf(" %f", &number);

    return number;
}
//(3)FUNCTION getChar
char getChar(char* message)
{
    char character;

    printf(" %s", message);
    fflush(stdin);
    scanf(" %c", &character);

    return character;
}
//(4)FUNCTION getString
void getString(char* message,char* chargeArray)
{
    printf(" %s", message);
    fflush(stdin);
    scanf (" %s", chargeArray);
}
/*********************************************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
/**********VALIDATION FUNCTIONS***************************************************************/
//(5)FUNCTION itsNumericIntString
int itsNumericIntString(char* array, int size)//size-1 porque el ultimo caracter siempre es '/0'
{
    int turnBack;
    int i;

    for(i = 0 ; i < size-1; i++)
    {
        turnBack = 1;
        if(array[i] < '0' || array[i] > '9')
        {
            turnBack = 0;
        }
    }

    return turnBack;
}
//(6)FUNCTION itsNumericFloatString
int itsNumericFloatString(char* array, int size)//size-1 porque el ultimo caracter siempre es '/0'
{
    int turnBack;
    int pointCounter;
    int i;

    for(i = 0 ; i < size-1; i++)
    {
        turnBack = 1;
        if (array[i] == '.' && pointCounter == 0)
       {
           pointCounter++;
           i++;
           continue;

       }
       if(array[i] < '0' || str[i] > '9')//itsNumeric==0
       {
           turnBack = 0;
       }

    }

    return turnBack;
}
//(7)FUNCTION itsLetterString
int itsLetterString(char* array, int size)//size-1 porque el ultimo caracter siempre es '/0'
{
    int turnBack;
    int i;

    for(i = 0; i < size-1; i++)//size-1 porque el ultimo caracter siempre es '/0'
    {
        turnBack = 1;
        if((array[i] < 'a' || array[i] > 'z') && (array[i] < 'A' || array[i] > 'Z'))
        {
            turnBack = 0;
        }
    }
    return turnBack;
}
/**********************************************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
/**********GET VALIDATION FUNCTIONS************************************************************/

//(8)FUNCTION getWordArray
int getWordArray(char* message,char* chargeArray)
{
    int turnBack;
    char auxArray[300];

    turnBack = 0;//si no es solo palabras devuelve 0

    getArray(message,auxArray);//tomo el array con la funcion getArray

    if(itsLetterString(auxArray) == 0)//valido con la funcion itsLettersString
    {
        strcpy(chargeArray,aux);
        turnBack = 1;
    }

    return turnBack;
}
//(9)FUNCTION getNumericString
int getNumericString(char* message,char* chargeArray)
{
    int turnBack;
    char auxMessage[300];

    turnBack = 0;

    getArray(message,auxChargeArray); //Se utiliza la funcion getArray para cargar en la variable
                                      //Auxiliar el string que escribe el usuario
    if(itsNumericFloatString(aux)) //si cumple las condiciones de ser numerico
    {
        strcpy(chargeArray,auxChargeArray);//copio la carga auxiliar en la real
        turnBack = 1;//si es numerico, entonces devuelve 1
    }
    return turnBack;
}
/**********************************************************************************************/

