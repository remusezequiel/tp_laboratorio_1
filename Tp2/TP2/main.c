#include <stdio.h>
#include <stdlib.h>

#include "ArrayEmployees.h"
#include "variousfunctions.h"

#define LEN 5

/****************COMENTARIO APARTE********************************************************
    1)ESTE TRABAJO NO ESTA TERMINADO DEBIDO A QUE NO ESTABA ENTERADO NI DE LA FECHA DE
    ENTREGA NI DE QUE LA CONSIGNA ESTABA SUBIDA. LO EMPESE EL MISMO DIA DE LA FECHA.
    DISCULPE LAS MOLESTIAS Y EL COMENTARIO.

    2)AL VER QUE EN EL PDF ESTABAN LAS FUNCIONES DECLARADAS CON CIERTOS NOMBRES Y EN
    INGLES, TRATE DE HACER TODAS LAS FUNCIONES EN INGLES, EVITANDO COMENTARIOS EN INGLES
    YA QUE NO TENGO UN INGLES SUMAMENTE BUENO Y ME PODIA EXPLICAR DE MALA MANERA
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
    int opcion;

    // Tipo struct y se inicializa
    Employee employer[LEN];///VARIABLE
    initEmployees(employer,LEN);///FUNCION INICIALIZADORA

/*_______________________________________________________________________________________*/
    // Carga datos de test


    do
    {

        //MOSTRAR MENU DE OPCIONES
        optionMenu();
        //PIDO Y GUARDO LA OPCION
        opcion = getOption();
        //PEDIR OPCION
        switch(opcion)
        {
            case 1: // OPCION (1)
                printf("ALTAS \n");
                chargeEmployer(employer,LEN);
                printEmployees(employer,LEN);
            break;
            case 2: // OPCION (2)
                //FUNCIONES DE LA OPCION
                printf("MODIFICAR\n");
            break;
            case 3: // OPCION (3)
                //FUNCIONES DE LA OPCION
                printf("BAJA");
                //removeEmployee(myEmployer,LEN);
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
                //linea();
                printf("\n NO ES UNA OPCION VALIDA!!!\n");
                //linea();

                break;
        }

    }while(opcion != 6);

    return 0;

}


