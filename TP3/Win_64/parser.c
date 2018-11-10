#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

///parser_EmployeeFromText FUNCTION
/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int // 0->si no realiza el analisis sintactico
 *             // 1-> si realiza el analisis sintactico
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
//:::::::::::::::::Variable:::::::::::::::::::::::::::::::::::::::::::://
    char bId[500],bNombre[500],bHorasTrabajadas[500],bSueldo[500];
    int len,turnBack;
    Employee* auxPemployer;
//:::::::::::::::::Code::::::::::::::::::::::::::::::::::::::::::::::://
    turnBack=0;
    if(pArrayListEmployee!=NULL && pFile!=NULL)
    {
        while(!feof(pFile))
        {
            len=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                       bId,bNombre,bHorasTrabajadas,bSueldo);
            if(len!=4)
            {
                break;
            }
            else if (len==4)
            {
                auxPemployer=employee_newParametros(bId,bNombre,bHorasTrabajadas,bSueldo);
                if(auxPemployer!=NULL)
                {
                    ll_add(pArrayListEmployee,auxPemployer);
                    turnBack=1;
                }
            }
        }
    }
//:::::::::::::::::EndCode:::::::::::::::::::::::::::::::::::::::::::://
    return turnBack;
}
///parser_EmployeeFromBinary FUNCTION
/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
//:::::::::::::::::Variable:::::::::::::::::::::::::::::::::::::::::::://
    int len,turnBack;
    Employee* auxPemployer=employee_new();
//:::::::::::::::::Code::::::::::::::::::::::::::::::::::::::::::::::://
    turnBack=0;
    if(pArrayListEmployee!=NULL && pFile!=NULL)
    {
        while(!feof(pFile))
        {
            len=fread(auxPemployer,sizeof(Employee),1,pFile);
            if(len!=4)
            {
                break;
            }
            else if (len==4)
            {
                if(auxPemployer!=NULL)
                {
                    ll_add(pArrayListEmployee,auxPemployer);
                    turnBack=1;
                }
            }
        }
    }
//:::::::::::::::::EndCode:::::::::::::::::::::::::::::::::::::::::::://
    return turnBack;
}

