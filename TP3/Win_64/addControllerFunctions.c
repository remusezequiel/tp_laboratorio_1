#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "valid.h"
#include "addControllerFunctions.h"

//FUNCTION optionMenuMain
void optionMenuMain(void)
{
    largeLine();
    printf("\t  MENU DE OPCIONES \n");
    largeLine();
    printf("\t  1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). \n");
    printf("\t  2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("\t  3. Alta de empleado.\n");
    printf("\t  4. Modificar datos de empleado. \n");
    printf("\t  5. Baja de empleado. \n");
    printf("\t  6. Listar empleados. \n");
    printf("\t  7. Ordenar empleados.\n");
    printf("\t  8. Guardar los datos de los empleados en el archivo data.csv (modo texto). \n");
    printf("\t  9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("\t 10. Salir. \n");
    largeLine();
}
//FUNCTION optionMenuEdit
void optionMenuEdit(void)
{
    line();
    printf("\t  MENU DE OPCIONES \n");
    line();
    printf("\t  1. Nombre. \n");
    printf("\t  2. Horas de trabajo.\n");
    printf("\t  3. Sueldo.\n");
    printf("\t  4. Salir. \n");
    line();
}
//FUNCTION print_lineSpacing
void print_lineSpacing(char* message)
{
    line();
    printf(" %s",message);
    line();
}
//FUNCTION request_Id
int request_Id(int id)
{
    getValidInt("*Ingrese el numero de identificacion: \n",
                "\n!->Error!. EL caracter ingresado no es un numero",
                "\n!->Error!. Rango no valido!. 0 a 9999999",&id,0,9999999);
    return id;
}
char* request_nombre(char* nombre)
{
   getValidString("*\t Ingrese el nombre del empleado: \t",
               "\n!->ERROR!. Ingrese solo letras \n",
               "\n!->ERROR!. Limite maximo de caracteres \n",
               nombre,50);
   return nombre;
}
//FUNCTION request_horasTrabajadas
int request_horasTrabajadas(int horasTrabajadas)
{
    getValidInt("*\t Ingrese la cantidad de horas trabajadas: \t",
                        "\n!->ERROR!. El caracter ingresado no es un numero! \n",
                        "\n!->ERROR!. El rango valido es de : 15 hs a 100 hs \n",
                        &horasTrabajadas,15,100);
    return horasTrabajadas;
}
//FUNCTION request_sueldo
int request_sueldo(int sueldo)
{
    getValidInt("*\t Ingrese el sueldo del empleado: \t",
                "\n!->ERROR!. El caracter ingresado no es un numero! \n",
                "\n!->ERROR!. El rango valido es de : 10000 a 50000 \n",
                &sueldo,10000,50000);

    return sueldo;
}
//FUNCTION pauseAndClean
void pauseAndClean()
{
    system("pause");
    system("cls");
}
void clear()
{
    system("cls");
}
