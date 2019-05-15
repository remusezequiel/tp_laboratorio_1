#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

}Employee;

///////////////////////////PROTOTIPOS///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/***********************CONSTRUCTORES**************************************************************************************************************/
Employee* employee_new();//CONSTRUCTOR DE UN EMPLEADO.
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);//CONSTRUYE SEGUN PARAMETROS INDICADOS
void employee_delete(Employee* this);//DESTRUYE UN EMPLEADO
/**********************SETERS**********************************************************************************************************************/
 /*RETORNO DE LAS FUNCIONES
  * \return int // 0 -> no se guarda
  *             // 1 -> se guarda
  *
  */
int employee_setId(Employee* this,int id);//int id SETEA EL ID
int employee_setNombre(Employee* this,char* nombre);//SETEA EL NOMBRE
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);//SETEA LAS HORAS TRABAJADAS
int employee_setSueldo(Employee* this,int sueldo);//SETEA EL SUELDO
/**********************GETERS**********************************************************************************************************************/
 /* RETORNO DE LAS FUNCIONES
 *\return int // 0->no lo toma
 *             // 1->si lo toma
 */
int employee_getId(Employee* this,int* id);//OBTIENE EL VALOR DEL ID
int employee_getNombre(Employee* this,char* nombre);//OBTIENE EL VALOR DEL NOMBRE
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);//OBTIENE EL VALOR DE LAS HORAS DE TRABAJO
int employee_getSueldo(Employee* this,int* sueldo);//OBTIENE EL VALOR DEL SUELDO
/********************APART FUNCTIONS****************************************************************************************************************/
void employee_print(Employee* this);//Imprime los datos de un empleado
Employee* employee_getEmployer(Employee* pEmployer,int id,char* nombre,int horasTrabajadas,int sueldo);//Hace un get de todos los campos de un empleado
Employee* employee_setEmployer(Employee* pEmployer,int id,char* nombre,int horasTrabajadas,int sueldo);//Hace un set de todos los campos de un empleado
int employee_compareByName(void* pEmployeeA,void* pEmployeeB);//compara por los nombres a dos empleados
int employee_compareBySalary(void* pEmployeeA,void* pEmployeeB);//compara por los suledos a dos empleados
int employee_compareByWorkHours(void* pEmployeeA,void* pEmployeeB);//compara por las horas trabajadas a dos empleados
///////////////////////////FIN_PROTOTIPOS///////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif // employee_H_INCLUDED
