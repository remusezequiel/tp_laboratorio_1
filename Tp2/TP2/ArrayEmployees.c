#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

//FUNCTION INITEMPLOYEES
/** \brief indicar que todas las posiciones del array están vacías, esta función pone la bandera
 *       (isEmpty) en TRUE en todas las posiciones del array
 *
 * \param Employee*
 * \param int
 * \return int
 *
 */
int initEmployees(Employee* array,int size);
{
      int retorno = 0, i; /// Valor que retorna si esta todo mal
    if(array != NULL && size>0)
    {
        retorno = 1;
        for (i=0; i<size; i++)
        {
            array[i].isEmpty = TRUE;//inicializo todo el vector con el estado en TRUE
        }
    }
    return retorno;

}
//FUNCTION generateNextId
/** \brief
 *
 * \return int
 *
 */
int generateNextId(void)
{
    int id = -1;
    id ++;
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
    int retorno = -1, i;
    if(array != NULL && size>0)
    {
        for (i=0; i<size; i++)
        {
            if (array[i].isEmpty == TRUE)//si el estado del struct corresponde al dado de baja
            {
                retorno = i;//retorno el valor del indice. Luego, al otorgarle a una variable
                break;		//el valor que otorga esta funcion es el del primer lugar en estado libre
            }
        }
    }
    return retorno;
}


/**************ADD*****************************************************************/
//FUNCTION addEmployee
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
    int auxId;
    int index;

    if(array != NULL && size > 0)
    {
        index = findVoidId(array, size);//busco un espacio libre en el vector
        if(index != TRUE)
        {
            auxId = abonados_findNextId(pAbonados, length);
            strcpy(array[index].name,name);
            strcpy(array[index].lastName,lastName);
            array[index].salary = salary;
            array[index].sector = sector;
            array[index].isEmpty = FALSE;

            return 0;
        }

    }
    return -1;
}
int chargeEmployer(Employee* array, int size)//EN ESTE CASO ES UN STRUCT EPersona
{
    Employee auxEmployer;//se crea un auxiliar del tipo struct
    int turnBack = 0;
    int index = findVoidId(array, size);//se trae al primer elemento del struct con estado sin ingresar

    if (index>-1 && index <= size)//si el [i] del array va de 0 en adelante
    {
		//INGRESO EL NOMBRE (con todo array puede hacerse el strlen)
        do
        {
            printf("Ingrese su nombre: ");
            fflush(stdin);
            gets(auxEmployer.name);
        } while (strlen(auxEmployer.name) == 0);//Esto es para que si no se ingresa nada volver a llamar
		//INGRESO EL APELLIDO
        do
        {
            printf("Ingrese su apellido: ");
            fflush(stdin);
            gets(auxEmployer.lastName);
        } while (strlen(auxEmployer.lastName) == 0);//Esto es para que si no se ingresa nada volver a llamar


        /// IMPORTANT
        auxEmployer.id = generarNextId();//Le doy el siguiente id libre al auxiliar
        auxEmployer.isEmpty = FALSE;        //doy el alta al auxiliar
        array[index] = auxEmployer;   //al array en el indice vacio le pongo el valor del auxiliar
        /// IMPORTANT ^^

        retorno = 1;
    }
    else
    {
        printf("No HAY ESPACIO!\n");
    }
    return retorno;
}

/**********************************************************************************/

//FUNCTION findEmployeeById
/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id.
 *
 * \param Employee*
 * \param int
 * \param int
 * \return int
 *
 */
int findEmployeeById(Employee* array,int size,int serchingId);
{
    int retorno = -1, i;

    if(array != NULL && size>0)
    {
        for (i=0; i<size; i++)//itero el array
        {
            if (array[i].id == serchingId)//cuando se cumpla esta condicion
            {
                retorno = i;//devuelvo el valor del indice
                break;
            }
        }
    }
    return retorno;
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
int removeEmployee(Employee* array,int size,int id);
{
    int retorno = -1;
    int indice;

    if(size > 0 && array != NULL)
    {
        retorno = -2;
        indice = findEmployeeById(array,size,id);//busco por id. Tomo el valor del ide en la variable indice.

        if(indice >= 0)//si el indice es valido
        {
            array[indice].estado = TRUE;//se da baja al elemento del array correspondiente al indice
			retorno = 1;

			printf(" \a La baja se realizo satisfactoriamente \n");
		}
        else
        {
            printf("No se encontro el Id \n");//sino, informa que no se a encontrado el indice
        }
	}

    return retorno;

}

/*****************ORDER FUNCTIONS********************/
//FUNCTION alphabeticOrder_A_Z
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
void downUpNumberOrder(Employee* array , int size)
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
}
//FUNCITION alphabeticOrder_Z_A
void upDownNumberOrder(Employee* array , int size)
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

}
//FUNCTION sortEmployees
/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
 *
 * \param  Employee*
 * \param int
 * \param int
 * \return int
 *
 */
int sortEmployees(Employee* array,int size,int orderOption);
{
    int turnBack;
    int opcion;

    printf("Ingrese una opcion: \n");
    scanf("%d", &opcion);

    switch(opcion)
    {
        case 1:
            alphabeticOrder_A_Z(array,size);
            downUpNumberOrder(array,size);
            turnBAck = 0;
        break;
        case 2:
            alphabeticOrder_Z_A(array,size);
            upDownNumberOrder(array,size);
            turnBAck = 1;
        break;
        default:
            printf("Ingrese una opcion valida");
    }
    return retorno;
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
void printOneEmployee(Employee employer);
{
    printf("_________________________________________________\n");
    printf(" %6d", employer.id);
    printf(" %15s", employer.name);
    printf(" %15s", employer.lastname);
    printf(" %10f", employer.salary);
    printf(" %6d\n", employer.sector);
    printf(" %6d\n", employer.isEmpty);
}

//FUNCTION printEmployees
int printEmployees(Employee* array, int size)
{
    int i;
    printf("LISTA DE ALUMNOS: \n");
    printf("____________________________________________________________________________\n");
    printf(" id \t NOMBRE \t APELLIDO \t SALARIO \t SECTOR \t ESTADO  \n");
    for(i=0; i<size; i++)
    {
        if(array[i].estado == 0)
        {
            printOneEmployee(array[i]);
        }
    }
    printf("____________________________________________________________________________\n");

    return 0;
}

/****************************************************/















