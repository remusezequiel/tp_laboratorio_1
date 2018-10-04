#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "variousfunctions.h"

//FUNCTION INITEMPLOYEES
/** \brief indicar que todas las posiciones del array están vacías, esta función pone la bandera
 *       (isEmpty) en DOWN en todas las posiciones del array
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
            array[i].isEmpty = DOWN;//inicializo todo el vector con el estado en DOWN
        }
    }
    return turnBack;

}
//FUNCTION generateNextId
/** \brief
 *
 * \return int
 *
 */
int generateNextId(void)
{
    int id=-1;
    id++;
    return id;
}
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
        for (i=0; i<size; i++)
        {
            if (array[i].isEmpty == DOWN)//si el estado del struct corresponde al dado de baja
            {
                turnBack = i;//turnBack el valor del indice. Luego, al otorgarle a una variable
                break;		//el valor que otorga esta funcion es el del primer lugar en estado libre
            }
        }
    }
    return turnBack;
}


/**************CHARGE FUNCTION******************************************************/

//FUNCTION addEmployee        /**/
/** \brief
 *
 * \param Employee*
 * \param int
 * \param int
 * \param char
 * \param char
 * \param float
 * \param int
 * \return int
 *
 */
int addEmployeeint(Employee* array, int size, int id, char* name,char* lastName,
float salary,int sector)
{
    int index;
    int turnBack;

    if(array != NULL && size > 0)
    {
        turnBack = -1;
        index = findVoidId(array, size);//busco un espacio libre en el vector
        if(index != DOWN)//si el indice esta libre copio los datos
        {
            id = index;//el id auxiliar toma el valor del seguiente indice libre
            id = array[index].id;
            strcpy(array[index].name,name);//lo que entra como name se carga en el array[index]
            strcpy(array[index].lastName,lastName);
            array[index].salary = salary;
            array[index].sector = sector;
            array[index].isEmpty = FALSE;

            turnBack = 0;
        }
    }

    return turnBack;
}
//FUNCTION chargeEmployer    /**/
int chargeEmployer(Employee* array, int size)//EN ESTE CASO ES UN STRUCT EPersona
{
    char  name[LEN_EMP];
    char lastName[LEN_EMP];
    int id;
    float salary;
    int sector;
    int turnBack;

    id=findVoidId(array,size);



    turnBack = getValidString("\n Ingrese el nombre: ","\n ERROR!","\nLongitud maxima 50", name,LEN_EMP);
    if(turnBack == TRUE)
    {
        turnBack = getValidString("\n Ingrese el Apellido: ","\n ERROR!","\nLongitud maxima 50", lastName,LEN_EMP);
        if(turnBack == TRUE)
        {
            salary=getFloat("\n Salario del empleado:");//Tengo problemas con las validaciones
            turnBack = getValidInt("\n En que sector trabaja: ","\n RAngo valido 0 -10", &sector,LOW_SECTOR,HI_SECTOR);
            if(turnBack == TRUE)
            {
                turnBack = addEmployeeint(array,size,id,name,lastName,salary,sector);
            }
        }
    }
    return turnBack;
}
//FUNCTION findEmployeeById
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
            if (array[i].id == serchingId)//cuando se cumpla esta condicion
            {
                turnBack = i;//devuelvo el valor del indice
                break;
            }
        }
    }
    return turnBack;
}
//FUNCTION removeEmployee
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
    int turnBack = -1;
    int indice;

    if(size > 0 && array != NULL)
    {
        turnBack = -2;
        indice = findEmployeeById(array,size,id);//busco por id. Tomo el valor del ide en la variable indice.

        if(indice >= 0)//si el indice es valido
        {
            array[indice].isEmpty = DOWN;//se da baja al elemento del array correspondiente al indice
			turnBack = 1;

			printf(" \a La baja se realizo satisfactoriamente \n");
		}
        else
        {
            printf("No se encontro el Id \n");//sino, informa que no se a encontrado el indice
        }
	}

    return turnBack;

}
/**********************************************************************************/



/*****************ORDER FUNCTIONS********************/

//FUNCTION alphabeticOrder_A_Z
/** \brief
 *
 * \param array Employee*
 * \param size int
 * \return void
 *
 */
void alphabeticOrder_A_Z(Employee* array , int size)
{
    int i;
    int j;
    Employee auxiliar;

    for(i = 1; i < size; i++)//inicializa i en 1
    {
        j = i-1; //inicializa j en 0
        auxiliar = array[i];
        //Mientras se cumpla la condicion. El array en i ocupara el lugar en j
        while( j>=0 && stricmp(array[j].lastName, auxiliar.lastName)>0)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1]= auxiliar;
    }

}
//FUNCITION alphabeticOrder_Z_A
/** \brief
 *
 * \param array Employee*
 * \param size int
 * \return void
 *
 */
void alphabeticOrder_Z_A(Employee* array , int size)
{
    int i;
    int j;
    Employee auxiliar;

    for(i = size -1; i <= 0 ; i--)//inicializa i en 1
    {
        j = size; //inicializa j en 0
        auxiliar = array[i];
        //Mientras se cumpla la condicion. El array en i ocupara el lugar en j
        while( j>=0 && stricmp(array[j].lastName, auxiliar.lastName)>0)
        {
            array[j-1] = array[j];
            j++;
        }
        array[j-1]= auxiliar;
    }

}
//FUNCTION downUpNumberOrder
/*void downUpNumberOrder(Employee* array , int size)
{
    int i;
    int j;
    Employee auxiliar;

    for(i = 1; i < size; i++)//inicializa i en 1
    {
        j = i-1; //inicializa j en 0
        auxiliar = array[i];
        //Mientras se cumpla la condicion. El array en i ocupara el lugar en j
        while( j>=0 && stricmp(array[j].sector, auxiliar.sector)>0)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1]= auxiliar;
    }
}*/
//FUNCITION alphabeticOrder_Z_A
/*void upDownNumberOrder(Employee* array , int size)
{
    int i;
    int j;
    Employee auxiliar;

    for(i = size -1; i <= 0 ; i--)//inicializa i en 1
    {
        j = size; //inicializa j en 0
        auxiliar = array[i];
        //Mientras se cumpla la condicion. El array en i ocupara el lugar en j
        while( j>=0 && stricmp(array[j].sector, auxiliar.sector)>0)
        {
            array[j-1] = array[j];
            j++;
        }
        array[j-1]= auxiliar;
    }

}*/
//FUNCTION sortEmployees
/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
 *
 * \param  Employee*
 * \param int
 * \param int
 * \return int
 *
 */
int sortEmployees(Employee* array,int size,int orderOption)
{
    int turnBack;
    int opcion;

    printf("Ingrese una opcion: \n");
    scanf("%d", &opcion);

    switch(opcion)
    {
        case 1:
            alphabeticOrder_A_Z(array,size);
            //downUpNumberOrder(array,size);
            turnBack = 0;
        break;
        case 2:
            alphabeticOrder_Z_A(array,size);
            //upDownNumberOrder(array,size);
            turnBack = 1;
        break;
        default:
            printf("Ingrese una opcion valida");
    }
    return turnBack;
}

/****************************************************/





/*************PRINT FUNCTIONS************************/
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
    printf("_________________________________________________\n");
    printf(" %6d", employer.id);
    printf(" %15s", employer.name);
    printf(" %15s", employer.lastName);
    printf(" %10f", employer.salary);
    printf(" %6d\n", employer.sector);
    printf(" %6d\n", employer.isEmpty);
}

//FUNCTION printEmployees
int printEmployees(Employee* array, int size)
{
    int i;
    printf("LISTA DE EMPLEADOS: \n");
    printf("____________________________________________________________________________\n");
    printf(" id \t NOMBRE \t APELLIDO \t SALARIO \t SECTOR \t ESTADO  \n");
    for(i=0; i<size; i++)
    {
        if(array[i].isEmpty == 0)
        {
            printOneEmployee(array[i]);
        }
    }
    printf("____________________________________________________________________________\n");

    return 0;
}

/****************************************************/















