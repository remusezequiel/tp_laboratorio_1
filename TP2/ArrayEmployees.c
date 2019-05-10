#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "variousfunctions.h"

#define LEN_EMP 50

static int generateNextId();
void addEmployeeint(Employee* array, int size,int id, char* name,char* lastName,
float salary,int sector)
{
    array[id].id=id;
    strcpy(array[id].name,name);
    strcpy(array[id].lastName,lastName);
    array[id].salary=salary;
    array[id].isEmpty=UP;
}

/**::::::::::::::::::::::::::::::::::*TP2 ARRAYEMPLOYEES FUNCTION*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::**/
//FUNCTION initEmployees____________________________________________________________________________________________//////////////////////////////////////
/** \brief indicar que todas las posiciones del array están vacías, esta función pone la bandera
 *       (isEmpty) en DOWN en todas las posiciones del array.
 *
 * \param Employee*
 * \param int
 * \return int
 *
 */
int initEmployees(Employee* array,int size)
{
    int turnBack = 0, i; /// Valor que retorna si esta todo mal
    if(array != NULL && size>0)
    {
        turnBack = 1;
        for (i=0; i<size; i++)
        {
            //array[i].id=i;
            array[i].isEmpty = DOWN;//inicializo todo el vector con el estado en DOWN
        }
    }
    return turnBack;
}
//FUNCTION findEmployeeById_______________________________________________________________________________________//////////////////////////////////////////
/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id.
 *
 * \param Employee*
 * \param int
 * \param int
 * \return int
 *
 */
int findEmployeeById(Employee* array,int size,int serchingId)
{
    int turnBack = -1, i;

    if(array != NULL && size>0)
    {
        for (i=0; i<size; i++)//itero el array
        {
            if (array[i].id==serchingId)//cuando se cumpla esta condicion
            {
                turnBack = i;//devuelvo el valor del indice
                break;
            }
        }
    }
    return turnBack;
}
//FUNCTION removeEmployee_________________________________________________________________________________________//////////////////////////////////////////
/** \brief
 *
 * \param Employee*
 * \param int
 * \param int
 * \return int
 *
 */
int removeEmployee(Employee* array,int size,int id)
{
    int turnBack = -1;//Retorno
    int index;

    if(size > 0 && array != NULL)
    {
        turnBack = -2;
        index = findEmployeeById(array,size,id);//busco por id. Tomo el valor del ide en la variable index.
        if(index == id )//si el indice es valido
        {
            array[index].isEmpty=DOWN;//se da baja al elemento del array correspondiente al indice
			turnBack=1;
			printf("\n \a La baja se realizo satisfactoriamente! \n");
		}
        else
        {
            printf("No se encontro el Id \n");//sino, informa que no se a encontrado el indice
        }
	}

    return turnBack;

}
//FUNCTION sortEmployees____________________________________________________________________________________________/////////////////////////////////////////
///FUNCTION sortEmployees
/** \brief Sort the elements in the list of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
    int i;
    int j;
    Employee auxiliar;

    switch(order)
    {
        case 1:///Ascendente
            for(i = 1; i < len; i++)//inicializa i en 1
            {
                j = i-1; //inicializa j en 0
                auxiliar = list[i];//agarro el elemento 1 de la lista de empleados

                //Mientras se cumpla la condicion. El list en i ocupara el lugar en j
                while( j>=0 && list[j].sector == auxiliar.sector && stricmp(list[j].lastName, auxiliar.lastName)>0)
                {
                    list[j+1] = list[j];
                    j--;
                }
                list[j+1]= auxiliar;
            }
        break;
        case 2:///Descendente
            for(i = 1; i < len; i++)//inicializa i en 1
            {
                j = i-1; //inicializa j en 0
                auxiliar = list[i];//agarro el elemento 1 de la lista de empleados

                //Mientras se cumpla la condicion. El list en i ocupara el lugar en j
                while( j>=0 && list[j].sector == auxiliar.sector && stricmp(list[j].lastName, auxiliar.lastName)<0)
                {
                    list[j+1] = list[j];
                    j--;
                }
                list[j+1]= auxiliar;
            }
        break;
    }
    return 0;
}
//FUNCTION printEmployees____________________________________________________________________________________________/////////////////////////////////////////
/** \brief Lista en la consola a los empleados existentes
 *
 * \param array Employee*
 * \param size int
 * \return int
 *
 */
int printEmployees(Employee* array, int size)
{
    int i;
    printf("LISTA DE EMPLEADOS: \n");
    printf("____________________________________________________________________________\n");
    printf(" id \t NOMBRE \t APELLIDO \t SALARIO \t SECTOR \t ESTADO  \n");
    for(i=0; i<size; i++)
    {
        if(array[i].isEmpty == UP)
        {
            //printf("\n%s\t\t\t%s\t\t%.2f\t\t%d\t\t%d\n",array[i].name,array[i].lastName,array[i].salary,array[i].sector,array[i].isEmpty);
            printOneEmployee(array[i]);
        }
    }
    printf("____________________________________________________________________________\n");

    return 0;
}
/**********************************************************************************************************************************************************/

/////////////////////////////////////////////////////////////////////
//FUNCTION findVoidId
/** \brief
 *
 * \param array STRUCT*
 * \param size int
 * \return int
 *
 */
int findVoidId(Employee* array,int size)
{
    int turnBack = -1, i;
    if(array != NULL && size>0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==DOWN)//si el estado del struct corresponde al dado de baja
            {
                turnBack=i;//turnBack el valor del index. Luego, al otorgarle a una variable
                break;		//el valor que otorga esta funcion es el del primer lugar en estado libre
            }
        }
    }
    return turnBack;
}
/****************************************"Alta,Baja,Modificar,Ordenar,Promediar" FUNCTIONS****************************************************************************************/
//FUNCTION chargeEmployer_________________________________________________________________________________________//////////////////////////////////////////
/** \brief Da de alta a un empleado en sistema
 *
 * \param array Employee*
 * \param size int
 * \return int
 *
 */
int chargeEmployer(Employee* array, int size)//EN ESTE CASO ES UN STRUCT EPersona
{
    Employee employer;
    int index;
    int turnBack,bAnswer;
    index=findVoidId(array,size);

    getValidString("\n Ingrese el nombre: ","\n\a!->ERROR!.Ingrese solo letras\n","\n\a!->ERROR!.Ingrese hasta 50 caracteres\n",employer.name,LEN_EMP);
    getValidString("\n Ingrese el Apellido:","\n\a!->ERROR!.Ingrese solo letras\n","\n\a!->ERROR!.Ingrese hasta 50 caracteres\n",employer.lastName,LEN_EMP);
    employer.salary=getFloat("\n Ingrese el salario del empleado: \n");
    getValidInt("\n En que sector trabaja: \n","\n\a!->ERROR!.Ingrese solo numeros\n","\n\a!->ERROR!. Los sectores van desde el 1 al 10\n",&employer.sector,0,10);//Tengo problemas con las validaciones
    bAnswer=getAnswer("Realmente desea dar de alta al empleado de la lista?",
                      "\n\a !->ERROR!. No ingreso una respuesta valida(s/n)",'s','n');
    if(bAnswer==1)
    {
        employer.id=generateNextId();
        employer.isEmpty=UP;
        array[index]=employer;
        printOneEmployee(array[index]);
        line();
        printf("Alta realizada de forma satisfactoria");
        line();
        turnBack=0;
    }
    pauseAndClean();
    return turnBack;
}
//FUNCTION takeOffSystemEmployee_________________________________________________________________________________________//////////////////////////////////
/** \brief Representa la funcion baja empleado utilizando la funcion remove
 *
 * \param array Employee*
 * \param size int
 * \return int
 *
 */
int takeOffSystemEmployee(Employee* array,int size)
{
    int id;
    int turnBack=0;
    int bAnswer;

    line();
    printf("BAJA\n");
    line();
    getValidInt("*Ingrese el numero de identificacion: \n",
            "\n\a!->Error!. EL caracter ingresado no es un numero",
            "\n\a!->Error!. Rango no valido!. 0 a 9999999",&id,0,9999999);
     largeLine();
     printf(" id \t NOMBRE \t APELLIDO \t SALARIO \t SECTOR \t ESTADO  \n");
     largeLine();
     printOneEmployee(array[id]);
     bAnswer=getAnswer("Realmente desea dar de baja al empleado de la lista?",
                          "\n !->ERROR!. No ingreso una respuesta valida(s/n)",'s','n');
    if(bAnswer==1)
    {
        turnBack = removeEmployee(array,size,id);
    }

    return turnBack;

}

//FUNCTION editEmployer___________________________________________________________________________________________________//////////////////////////////////
/** \brief Esta funcion permite editar los datos previamente ingresados al sistema
 *
 * \param array Employee*
 * \param size int
 * \return int
 *
 */
int editEmployers(Employee* array,int size)
{
    clear();
    Employee auxEmployer;
    int id;
    int bId;
    int bAnswer;
    int option;
    int turnBack;

    turnBack=0;
    if(array!=NULL && size>=0)
    {
        do
        {
            getValidInt("*Ingrese el numero de identificacion: \n",
                        "\n!->Error!. EL caracter ingresado no es un numero",
                        "\n!->Error!. Rango no valido!. 0 a 9999999",&id,0,9999999);
            bId=findEmployeeById(array,size,id);
            if(array[bId].isEmpty==UP)
            {
                editOptionMenu();
                option = getOption("Ingrese una opcion del menu: \n","\n!->ERROR!. No es una opcion valida\n",1,5);
                switch(option)
                {
                    case 1:
                            getValidString("\n Ingrese el nombre: ","\n!->ERROR!.Ingrese solo letras\n","\n!->ERROR!.Ingrese hasta 50 caracteres\n",auxEmployer.name,LEN_EMP);
                            bAnswer=getAnswer("Realmente desea dar de alta al empleado de la lista?","\n !->ERROR!. No ingreso una respuesta valida(s/n)",'s','n');
                            if(bAnswer==1)
                            {
                                strcpy(array[bId].name,auxEmployer.name);
                                turnBack=1;
                            }
                            else
                            {
                                printf(" \t Operacion Cancelada! \n");
                                turnBack=0;
                            }
                            pauseAndClean();
                        break;
                    case 2:
                            getValidString("\n Ingrese el apellido: ","\n!->ERROR!.Ingrese solo letras\n","\n!->ERROR!.Ingrese hasta 50 caracteres\n",auxEmployer.lastName,LEN_EMP);
                            bAnswer=getAnswer("Realmente desea dar de alta al empleado de la lista?","\n !->ERROR!. No ingreso una respuesta valida(s/n)",'s','n');
                            if(bAnswer==1)
                            {
                                strcpy(array[bId].lastName,auxEmployer.lastName);
                                turnBack=1;
                            }
                            else
                            {
                                printf(" \t Operacion Cancelada! \n");
                                turnBack=0;
                            }
                            pauseAndClean();
                        break;
                    case 3:
                            auxEmployer.salary=getFloat("\n Ingrese el salario del empleado: \n");
                            bAnswer=getAnswer("Realmente desea dar de alta al empleado de la lista?","\n !->ERROR!. No ingreso una respuesta valida(s/n)",'s','n');
                            if(bAnswer==1)
                            {
                                array[bId].salary=auxEmployer.salary;
                                turnBack=1;
                            }
                            else
                            {
                                printf(" \t Operacion Cancelada! \n");
                                turnBack=0;
                            }
                            pauseAndClean();
                        break;
                    case 4:
                            getValidInt("\n En que sector trabaja: \n","\n!->ERROR!.Ingrese solo numeros\n","\n!->ERROR!. Los sectores van desde el 1 al 10\n",&auxEmployer.sector,0,10);//Tengo problemas con las validaciones
                            bAnswer=getAnswer("Realmente desea dar de alta al empleado de la lista?","\n !->ERROR!. No ingreso una respuesta valida(s/n)",'s','n');
                            if(bAnswer==1)
                            {
                                array[bId].sector=auxEmployer.sector;
                                turnBack=1;
                            }
                            else
                            {
                                printf(" \t Operacion Cancelada! \n");
                                turnBack=0;
                            }
                            pauseAndClean();
                        break;
                }
            }
            else
            {
                printf("\a \t El id ingresado no corresponde a un empleado dado de alta!\n");
                turnBack=0;
            }
        }while(option!=5);
    }

    pauseAndClean();
    return turnBack;
}

int order(Employee* array,int size)
{
    clear();
    int option;

    do
    {
        orderMenu();
        option = getOption("Ingrese una opcion del menu: \n","\n!->ERROR!. No es una opcion valida\n",1,3);
        switch(option)
        {
            case 1:
                printf("\tASCENDENTE\n");
                sortEmployees(array,size,1);
                printEmployees(array,size);
                pauseAndClean();
                break;
            case 2:
                printf("\tDESCENDENTE\n");
                sortEmployees(array,size,2);
                printEmployees(array,size);
                pauseAndClean();
                break;
            case 3:
                printf("Salida");
                break;
        }
    }while(option!=3);
    pauseAndClean();
    return 0;
}
int averageReport(Employee* array,int size)
{
    clear();
    int empOverAverage;
    float ave;
    float totalSalary;

    totalSalary=TotalSalary(array,size);
    ave=average(array,size);
    empOverAverage=employersOverAverage(array,size);

    line();
    printf("INFORME DE PROMEDIOS: \n");
    line();
    lineaPunteada();
    printf("La suma de todos los sueldos es: \t | %f\n",totalSalary);
    lineaPunteada();
    printf("El promedio de los sueldos es: \t | %f\n",ave);
    lineaPunteada();
    printf("La cantidad de empleados con el sueldo mayor o igual al promedio es: \t %d\n",empOverAverage);
    lineaPunteada();

    pauseAndClean();
    return 0;
}
/**********************************************************************************************************************************************************/
/** \brief Esta funcion calcula el promedio de los empleados dados de alta y nos retorna el promedio
 *
 * \param array Employee*
 * \param size int
 * \return int
 *
 */
float average(Employee* array,int size)
{
    //Employee employer;
    int employerCounter=0;
    float salaryCollector=0;
    float average;//Promedio de todos los sueldos de los empleados dados de alta
    int i;
    int turnBack;

    if(array!=NULL && size>0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==UP)
            {
                employerCounter++;
                salaryCollector+=array[i].salary;
            }
        }
        average=salaryCollector/employerCounter;
        turnBack=average;
    }
    else
    {
        turnBack=0;
    }

    return turnBack;
}
/// TotalSalary FUNCTION__________________________________________________________________________________________________________/////////////////////////
/** \brief Esta funcion calcula el total de la suma de todos los sueltos
 *          de los empleados dados de alta
 * \param array Employee*
 * \param size int
 * \return int
 *
 */
float TotalSalary(Employee* array,int size)
{
//    Employee employer;
    float salaryCollector=0;
    int i;
    int turnBack;

    if(array!=NULL && size>0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==UP)
            {
                salaryCollector+=array[i].salary;
            }
        }
        turnBack=salaryCollector;
    }
    else
    {
        turnBack=0;
    }

    return turnBack;
}
///employersOverAverage FUNCTION_______________________________________________________________________________/////////////////////////////////////////////
/** \brief Esta funcion calcula cuantos empleados hay con el sueldo mayor al promedio
 *
 * \param array Employee*
 * \param size int
 * \return int
 *
 */
int employersOverAverage(Employee* array,int size)
{
    int turnBack;
    float ave;
    int employersOverAverageCounter=0;
    int i;

    if(array!=NULL && size>0)
    {
        ave=average(array,size);
        for(i=0;i<size;i++)
        {
            if(array[i].salary>=ave)
            {
                employersOverAverageCounter++;
            }
        }
        turnBack=employersOverAverageCounter;
    }
    else
    {
        turnBack=0;
    }

    return turnBack;
}

/*****************************************PRINT FUNCTIONS**************************************************************************************************/
//FUNCTION printOneEmployee
/** \brief
 *
 * \param Employee*
 * \param int
 * \return int
 *
 */
void printOneEmployee(Employee employer)
{
    largeLine();
    printf(" %d", employer.id);
    printf(" %15s", employer.name);
    printf(" %15s", employer.lastName);
    printf(" %10f", employer.salary);
    printf(" %10d", employer.sector);
    printf(" %10d\n", employer.isEmpty);
    largeLine();
}
void editOptionMenu()
{
    largeLine();
    printf("\t  MENU DE OPCIONES PARA MODIFICAR \n");
    largeLine();
    printf("\t  1. Nombre.\n");
    printf("\t  2. Apellido. \n");
    printf("\t  3. Sueldo. \n");
    printf("\t  4. Sector. \n");
    printf("\t  5. Salir. \n");
    largeLine();

}
void orderMenu()
{
    largeLine();
    printf("\t  MENU DE OPCIONES PARA ORDENAR \n");
    largeLine();
    printf("\t  1. Ascendente.\n");
    printf("\t  2. Descendente. \n");
    printf("\t  3. Salir. \n");
    largeLine();
}
void infoMenu()
{
    largeLine();
    printf("\t  MENU DE OPCIONES PARA INFORMAR \n");
    largeLine();
    printf("\t  1. Ordenar.\n");
    printf("\t  2. Promediar. \n");
    printf("\t  3. Salir. \n");
    largeLine();
}
/**********************************************************************************************************************************************************/

void hardcode(Employee* array, int size)
{
    addEmployeeint(array,size,0,"Robert","ito",40000,2);
    addEmployeeint(array,size,1,"Elsa","pallo",20000,3);
    addEmployeeint(array,size,2,"mark","Itos",20000,5);
}

void pauseAndClean()
{
    system("pause");
    system("cls");
}
void clear()
{
    system("cls");
}
static int generateNextId()
{
    static int id = -1;
    id ++;
    return id;
}















