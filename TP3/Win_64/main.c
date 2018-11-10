#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "valid.h"
#include "addControllerFunctions.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
/******************************************************************
*   ALUMNO: EZEQUIEL REMUS                                        *
*   DICICION: 1/C                                                 *
*        OBSERVACIONES:                                           *
*   -> El archivo que se carga es "dataNew".                      *
*   -> EL archivo en el que se guardan los datos en formato txt   *
*   es el archivo "dataTxt".                                      *
*   -> El archivo en el que se guardan los datos en bin es        *
*   el archivo "dataBin".                                         *
*                                                                 *
*   La funcion que cumple la divicion de archivos de esa forma    *
*   es la de ver mejor como se modifican los datos al momento     *
*   que estos se salvan.                                          *
*******************************************************************/
int main()
{
/*:::::::::::::Color de consola::::::::::::::::::::::::::**/
    system("color 1F");
/*:::::::::::::Variables::::::::::::::::::::::::::::::::**/
    int option;
    LinkedList* listaEmpleados=ll_newLinkedList();
/*::::::::::PRECENTACION:::::::::::::::::::::::::::::::**/
    line();
    printf("\n\tTRABAJO PRACTICO N°3:\n");
    line();
/*::::::::::::::::::::::::::::::::::::::::CODIGO::::::::::::::::::::::::::::::::::::::**/
    do{
        optionMenuMain();
        option=getOption("Ingrese una opcion: \n","ERROR!.Opcion incorrecta",1,10);
            switch(option)
            {
                //1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
                case 1://
                    controller_loadFromText("dataNew.csv",listaEmpleados);
                break;
                //2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
                case 2://
                    controller_loadFromBinary("dataNew.csv",listaEmpleados);
                break;
                //3. Alta de empleado
                case 3://
                    controller_addEmployee(listaEmpleados);
                break;
                //4. Modificar datos de empleado
                case 4://
                    controller_editEmployee(listaEmpleados);
                break;
                //5. Baja de empleado
                case 5://
                    controller_removeEmployee(listaEmpleados);
                break;
                //6. Listar empleados
                case 6://
                    controller_ListEmployee(listaEmpleados);
                break;
                //7. Ordenar empleados
                case 7://
                    controller_sortEmployee(listaEmpleados);
                break;
                //8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
                case 8://
                    controller_saveAsText("dataTxt.csv",listaEmpleados);
                break;
                //9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
                case 9:
                    controller_saveAsBinary("dataBin.csv",listaEmpleados);
                break;
                default:
                    ll_deleteLinkedList(listaEmpleados);
            }
    //10. Salir
    }while(option != 10);
/*:::::::::::::::::::::::::FIN_CODIGO::::::::::::::::::::::::::::::::::::::**/
    return 0;
}
