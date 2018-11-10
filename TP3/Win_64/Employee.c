#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"
#include "valid.h"

/*****************************CONSTRUCTORES*******************************************/
///employee_new() FUNCTION
/** \brief Inicializa los campos de un empleado segun las
 *      reglas: id=0;nombre="NN";horasTrabajadas=0;sueldo=0.0.
 * \return Employee* Devuelve el valor del empleado inicializado
 *
 */
Employee* employee_new()//CONSTRUCTOR: Construye un espacio en memora para un empleado
{
/*:::::::::::::Variable:::::::::::::::::::::::::::::::::::**/
    Employee* employer=(Employee*)malloc(sizeof(Employee));
/*:::::::::::::Code:::::::::::::::::::::::::::::::::::::::**/
    if(employer!=NULL)
    {
        employer->id=-1;
        strcpy(employer->nombre,"NN");
        employer->horasTrabajadas=-1;
        employer->sueldo=-1;
    }
/*:::::::::::::EndCode::::::::::::::::::::::::::::::::::::**/
    return employer;//Devuelve el valor del puntero a Employee
}
///employee_newParametros FUNCTION_________________________________________________///
/** \brief Esta funcion le otorga los parametros a la funcion
 *      siendo estos tipo string y los castea a teniendo en cuenta
 *      los campos correspondientes del struct
 * \param char* idStr
 * \param char* nombreStr
 * \param char* horasTrabajadasStr
 * \param char* sueldoStr
 * \return Los campos respecivos del empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,
                                 char* horasTrabajadasStr,char* sueldoStr)
{
/*:::::::::::::Variable:::::::::::::::::::::::::::::::::::**/
    Employee* employer;
/*:::::::::::::Code:::::::::::::::::::::::::::::::::::::::**/
    employer=employee_new();
    if(employer!=NULL)
    {
        (employer->id) = atoi(idStr);
        strcpy((employer->nombre), nombreStr);
        (employer->horasTrabajadas) = atoi(horasTrabajadasStr);
        (employer->sueldo) = atoi(sueldoStr);
    }
/*:::::::::::::EndCode::::::::::::::::::::::::::::::::::::**/
    return employer;
}

void employee_delete(Employee* this)//DESTRUYE UN EMPLEADO
{
    free(this);
}
/**********************************************************************************/

/**********************SETERS******************************************************/
///employee_setId FUNCTION_______________________________________________________///
/** \brief Settea (guarda) esl valor del id del empleado
 *
 * \param this Employee*
 * \param id int
 * \return int // 0 -> no se guarda
 *             // 1 -> se guarda
 *
 */
int employee_setId(Employee* this,int id)//int id SETEA EL ID
{
/*:::::::::::::Variable:::::::::::::::::::::::::::::::::::**/
    int turnBack = 0;
/*:::::::::::::Code:::::::::::::::::::::::::::::::::::::::**/
        if(this!=NULL && id>0)
        {
            this->id=id;
            turnBack=1;
        }
/*:::::::::::::EndCode::::::::::::::::::::::::::::::::::::**/
    return turnBack;
}
///employee_setNombre FUNCTION____________________________________________________///
/** \brief settea en nombre de un empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int // 0 -> no se guarda
 *             // 1 -> se guarda
 *
 */
int employee_setNombre(Employee* this,char* nombre)//SETEA EL NOMBR
{
/*:::::::::::::Variable:::::::::::::::::::::::::::::::::::**/
    int turnBack=0;
/*:::::::::::::Code:::::::::::::::::::::::::::::::::::::::**/
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        turnBack=1;
    }
/*:::::::::::::EndCode::::::::::::::::::::::::::::::::::::**/
    return turnBack;
}
///employee_setHorasTrabajadas FUNCTION___________________________________________///
/** \brief Settea las horas trabajadas
 *
 * \param this Employee*
 * \param horasTrabajadas int
  * \return int // 0 -> no se guarda
 *             // 1 -> se guarda
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)//SETEA LAS HORAS TRABAJADAS
{
/*:::::::::::::Variable:::::::::::::::::::::::::::::::::::**/
    int turnBack=0;
/*:::::::::::::Code:::::::::::::::::::::::::::::::::::::::**/
    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas = horasTrabajadas;
        turnBack=1;
    }
/*:::::::::::::EndCode::::::::::::::::::::::::::::::::::::**/
    return turnBack;
}
///employee_setSueldo FUNTION____________________________________________________///
/** \brief Settea el valor del sueldo de un empleado
 *
 * \param this Employee*
 * \param sueldo int
  * \return int // 0 -> no se guarda
 *             // 1 -> se guarda
 *
 */
int employee_setSueldo(Employee* this,int sueldo)//SETEA EL SUELDO
{
/*:::::::::::::Variable:::::::::::::::::::::::::::::::::::**/
    int turnBack=0;
/*:::::::::::::Code:::::::::::::::::::::::::::::::::::::::**/
    if(this!=NULL && sueldo>=0)
    {
        this->sueldo=sueldo;
        turnBack=1;
    }
/*:::::::::::::EndCode::::::::::::::::::::::::::::::::::::**/
    return turnBack;
}
/**********************************************************************************/


/**********************GETERS******************************************************/
///employee_getId FUNCTION________________________________________________________///
/** \brief Obtiene el valor del id del empleado
 *
 * \param this Employee* un empleado
 * \param id int* el id del empleado
 * \return int //0 -> no se obtiene
 *             //1 -> se obtiene
 *
 */
int employee_getId(Employee* this,int* id)//OBTIENE EL VALOR DEL ID
{
/*:::::::::::::Variable:::::::::::::::::::::::::::::::::::**/
    int turnBack=0;
/*:::::::::::::Code:::::::::::::::::::::::::::::::::::::::**/
    if(this!=NULL)
    {
        id =(int*) this->id;
        turnBack=1;
    }
/*:::::::::::::EndCode::::::::::::::::::::::::::::::::::::**/
    return turnBack;
}
///employee_getNombre FUNCTION____________________________________________________///
/** \brief Toma el valor del atributo nombre
 *
 * \param this Employee*
 * \param nombre char*
 * \return int // 0->no lo toma
 *             // 1->si lo toma
 *
 */
int employee_getNombre(Employee* this,char* nombre)//OBTIENE EL VALOR DEL NOMBRE
{
/*:::::::::::::Variable:::::::::::::::::::::::::::::::::::**/
    int turnBack=0;
/*:::::::::::::Code:::::::::::::::::::::::::::::::::::::::**/
    if(this!=NULL)
    {
        strcpy(nombre,this->nombre);
        turnBack=1;
    }
/*:::::::::::::EndCode::::::::::::::::::::::::::::::::::::**/
    return turnBack;
}
///employee_getHorasTrabajadas FUNCTION__________________________________________///
/** \brief Obtiene el valor de las oras de trabajo de un empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int // 0->no lo toma
 *             // 1->si lo toma
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)//OBTIENE EL VALOR DE LAS HORAS DE TRABAJO
{
/*:::::::::::::Variable:::::::::::::::::::::::::::::::::::**/
    int turnBack=0;
/*:::::::::::::Code:::::::::::::::::::::::::::::::::::::::**/
    if(this!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        turnBack=1;
    }
/*:::::::::::::EndCode::::::::::::::::::::::::::::::::::::**/
    return turnBack;
}
///employee_getSueldo FUNCTION___________________________________________________///
/** \brief Obtiene el valor del sueldo
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int // 0->no lo toma
 *             // 1->si lo toma
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)//OBTIENE EL VALOR DEL SUELDO
{
/*:::::::::::::Variable:::::::::::::::::::::::::::::::::::**/
    int turnBack=0;
/*:::::::::::::Code:::::::::::::::::::::::::::::::::::::::**/
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        turnBack=1;
    }
/*:::::::::::::EndCode::::::::::::::::::::::::::::::::::::**/
    return turnBack;
}

///////////////APART FUNCTIONS////////////////////////////////////////////////////////////////
void employee_print(Employee* this)
{
    line();
    printf("%d %10s %10d %15d\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
    line();
}
Employee* employee_getEmployer(Employee* pEmployer,int id,char* nombre,int horasTrabajadas,int sueldo)
{
    employee_getId(pEmployer,&id);
    employee_getNombre(pEmployer,nombre);
    employee_getHorasTrabajadas(pEmployer,&horasTrabajadas);
    employee_getSueldo(pEmployer,&sueldo);

    return pEmployer;
}
Employee* employee_setEmployer(Employee* pEmployer,int id,char* nombre,int horasTrabajadas,int sueldo)
{
    employee_setId(pEmployer,id);
    employee_setNombre(pEmployer,nombre);
    employee_setHorasTrabajadas(pEmployer,horasTrabajadas);
    employee_setSueldo(pEmployer,sueldo);

    return pEmployer;
}



int employee_compareByName(void* pEmployeeA,void* pEmployeeB)
{
    int turnBAck=0;
    char nameA[300];
    char nameB[300];

    employee_getNombre((Employee*)pEmployeeA,nameA);
    employee_getNombre((Employee*)pEmployeeB,nameB);

    if(strcmp(nameA,nameB)==-1)
    {
        turnBAck=-1;
    }
    if(strcmp(nameA,nameB)==1)
    {
        turnBAck=1;
    }

    return turnBAck;
}

int employee_compareBySalary(void* pEmployeeA,void* pEmployeeB)
{
    int turnBAck=0;
    if(((Employee*)pEmployeeA)->sueldo > ((Employee*)pEmployeeB)->sueldo)
    {
        turnBAck=-1;
    }
    if(((Employee*)pEmployeeA)->sueldo < ((Employee*)pEmployeeB)->sueldo)
    {
        turnBAck=1;
    }
    return turnBAck;
}

int employee_compareByWorkHours(void* pEmployeeA,void* pEmployeeB)
{
    int turnBAck=0;
    if(((Employee*)pEmployeeA)->horasTrabajadas > ((Employee*)pEmployeeB)->horasTrabajadas)
    {
        turnBAck=-1;
    }
    if(((Employee*)pEmployeeA)->horasTrabajadas < ((Employee*)pEmployeeB)->horasTrabajadas)
    {
        turnBAck=1;
    }
    return turnBAck;
}











