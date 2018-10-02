#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define LEN 1000

/****************COMENTARIO APARTE********************************************************
    ESTE TRABAJO NO ESTA TERMINADO DEBIDO A QUE NO ESTABA ENTERADO NI DE LA FECHA DE
    ENTREGA NI DE QUE LA CONSIGNA ESTABA SUBIDA. LO EMPESE EL MISMO DIA DE LA FECHA.
    DISCULPE LAS MOLESTIAS Y EL COMENTARIO.
*****************************************************************************************/
/******************************CONSIGNA***************************************************
NOMBRE: Ezequiel
APELLIDO: Remus
DIVISION: 1.C

1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
    de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
    o Salario o Sector
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
    A. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
    B. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.

*****************************************************************************************/


int main()
{
      system("color 1F");

/*________________________________VARIABLES_______________________________________________*/
    Employee myEmployer[LEN];
    int opcion;

    // Tipo struct y se inicializa


/*_______________________________________________________________________________________*/
    // Carga datos de test


    do
    {
        system("clr");
        //MOSTRAR MENU DE OPCIONES

        printf("\n \t MENU DE OPCIONES \n");
        printf(" \t 1.ALTAS \n");
        printf(" \t 2.MODIFICACIONES \n");
        printf(" \t 3.BAJAS \n");
        printf("\t 4.INFORMES \n");
        printf("\t 5.SALIR \n");

        //PEDIR OPCION
        switch(opcion)
        {
            case 1: // OPCION (1)
                printf("ALTAS \n");
                addEmployee(myEmployer,LEN)
            break;
            case 2: // OPCION (2)
                //FUNCIONES DE LA OPCION
                printf("MODIFICAR\n");
            break;
            case 3: // OPCION (3)
                //FUNCIONES DE LA OPCION
                printf("BAJA");
                removeEmployee(myEmployer,LEN);
            break;
            case 4: // OPCION (4)
                //FUNCIONES DE LA OPCION
                printf("INFORMAR");
            break;
            case 5: // OPCION (5)
                //FUNCIONES DE LA OPCION
                printf("SALIR");
            break;
            default:
                linea();
                printf("\n NO ES UNA OPCION VALIDA!!!\n");
                linea();
                pause();
                break;
        }

    }while(menuOpcionElegida != 9);

    return 0;

}


