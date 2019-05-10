#include <stdio.h>
#include <stdlib.h>

#include "ArrayEmployees.h"
#include "variousfunctions.h"

#define LEN 5

/****************COMENTARIO APARTE********************************************************

*****************************************************************************************/
/******************************CONSIGNA***************************************************
NOMBRE: Ezequiel
APELLIDO: Remus
DIVISION: 1G

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
    hardcode(employer,LEN);

/*_______________________________________________________________________________________*/
    // Carga datos de test
    do
    {
        //MOSTRAR MENU DE OPCIONES
        optionMenu();
        //PIDO Y GUARDO LA OPCION
        opcion = getOption("Ingrese una opcion del menu: \n","\n!->ERROR!. No es una opcion valida\n",1,4);
        //PEDIR OPCION
        switch(opcion)
        {
            case 1: // OPCION (1)
                printf("ALTAS \n");
                chargeEmployer(employer,LEN);
               // printEmployees(employer,LEN);
            break;
            case 2: // OPCION (2)
                //FUNCIONES DE LA OPCION
                printf("MODIFICAR\n");
                editEmployers(employer,LEN);
            break;
            case 3: // OPCION (3)
                //FUNCIONES DE LA OPCION
                takeOffSystemEmployee(employer,LEN);
            break;
            case 4: // OPCION (4)
                //FUNCIONES DE LA OPCION
                do{
                    printf("INFORMAR\n");
                    infoMenu();
                    opcion = getOption("Ingrese una opcion del menu: \n","\n!->ERROR!. No es una opcion valida\n",1,3);
                    switch(opcion)
                    {
                        case 1:
                                order(employer,LEN);
                            break;
                        case 2:
                                averageReport(employer,LEN);
                            break;
                        case 3:
                                printf("\t\a*Salida!\n");
                            break;
                    }
                }while(opcion!=3);
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

    }while(opcion != 5);

    return 0;

}


