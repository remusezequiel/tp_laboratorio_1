#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "valid.h"
#include "addControllerFunctions.h"

#define TRUE 1
#define FALSE 0

//static int searchId(LinkedList* pArrayListEmployee,int id);

///controller_loadFromText FUNCTION________________________________________________________________________________________//////
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int //  FALSE -> No se carga
 *             //  TRUE -> Se carga
 ***/
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    clear();
/**::::::::::::::::::Variables:::::::::::::::::::::::::::::::::::::::**/
	FILE* pFile;
	int turnBack;
/**::::::::::::::::::::::Code::::::::::::::::::::::::::::::::::::::::**/
	print_lineSpacing(" \t CARGAR ARCHIVO DESDE UN TXT \n");
	pFile=fopen(path, "r");
		if(pFile!=NULL)
		{
            parser_EmployeeFromText(pFile,pArrayListEmployee);
            printf("\n \n Archivo (txt) cargado de forma satisfactoria!. \n \n");
            turnBack=TRUE;
		}
		else
        {
            printf("\n \nError!.Archivo no existente!.\n \n");
            turnBack=FALSE;
        }
	fclose(pFile);
/**:::::::::::::::::::::::EndCode:::::::::::::::::::::::::::::::::::**/
	pauseAndClean();
	return turnBack;
}
///controller_loadFromBinary FUNCTION____________________________________________________________________________________////////
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int //  FALSE -> No se carga
 *             //  TRUE -> Se carga
 ***/
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    clear();
/**::::::::::::::::::Variables:::::::::::::::::::::::::::::::::::::::**/
	FILE* pFile;
	int turnBack;
/**::::::::::::::::::::::Code::::::::::::::::::::::::::::::::::::::::**/
	print_lineSpacing(" \t CARGAR ARCHIVO DESDE UN BIN \n");
	pFile=fopen(path, "rb");//Abro el archivo
		if(pFile!=NULL)//Valido
		{
            parser_EmployeeFromText(pFile,pArrayListEmployee);//Leo los elementos
            printf("\n \n Archivo (bin) cargado de forma satisfactoria!.\n \n");//Luego de leer los elementos, informo
            turnBack=TRUE;//Retorno devuelve true
		}
		else
        {
            printf("\n \n Error!.Archivo no existente!.\n \n");
            turnBack=FALSE;
        }
	fclose(pFile);
/**:::::::::::::::::::::::EndCode:::::::::::::::::::::::::::::::::::**/
	pauseAndClean();
	return turnBack;
}
///controller_addEmployee FUNCTION________________________________________________________________________________________///////
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int //  FALSE -> No se agrega
 *             //  TRUE -> Se agrega
 ***/
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    clear();
/*:::::::::::::Variable:::::::::::::::::::::::::::::::::::**/
    Employee* pEmployer=employee_new();
    int bId,bHorasTrabajadas=0,bSueldo=0;
    char bNombre[50];
    int turnBack, len;
    int bAnswer;
/*:::::::::::::Code:::::::::::::::::::::::::::::::::::::::**/
    if (pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        print_lineSpacing("\t ALTAS \n");
        do//Nombre
        {
            strcpy(bNombre,request_nombre(bNombre));//Pido el nombre
        } while(strlen(bNombre)==0);
        //Horas de trabajo
        bHorasTrabajadas=request_horasTrabajadas(bHorasTrabajadas);//Pido las horas de trabajo
        //Sueldo
        bSueldo=request_sueldo(bSueldo);//Pido el Sueldo
        //Pregunto
        bAnswer=getAnswer("Realmente quiere dar de alta al empleado? (s/n)\n","ERROR DE TIPEO!",'s','n');
        if(bAnswer==1)
        {
            /// IMPORTANT^^
            bId=len;//Le asigno el valor de la lista al id
            pEmployer=employee_setEmployer(pEmployer,bId,bNombre,bHorasTrabajadas,bSueldo);//Hago un set de todos los campos
            ll_add(pArrayListEmployee,pEmployer);//Agrego el empleado a la lista
            /// IMPORTANT ^^
            print_lineSpacing("\n\n Alta realizada satisfactoriamente \n");
            turnBack=TRUE;
        }
        else
        {
            employee_delete(pEmployer);
        }
    }
    else
    {
        printf("No HAY ESPACIO!\n");
        turnBack=FALSE;
    }
/*:::::::::::::EndCode::::::::::::::::::::::::::::::::::::**/
    pauseAndClean();
    return turnBack;
}
///controller_editEmployee FUNCTION______________________________________________________________________________________////////
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int //  FALSE -> No se Modifica
 *             //  TRUE -> Se Modifica
 ***/
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    clear();
/*:::::::::::::Variable:::::::::::::::::::::::::::::::::::**/
    Employee* pEmployer;
    int bId,bHorasTrabajadas,bSueldo;//
    int idToEdit,correctId=0;
    char bNombre[50];
    int turnBack,option,bAnswer,i,len;
/*:::::::::::::Code:::::::::::::::::::::::::::::::::::::::**/
    if (pArrayListEmployee!=NULL)
    {
        do
        {
            print_lineSpacing(" \t MODIFICACIONES \n");//Imprimo el titulo
            optionMenuEdit();//Muestro las opciones que pueden ser modificadas
            option=getOption("Ingrese una opcion: \n","ERROR!.Opcion incorrecta",1,4);//Le pido que ingrese una opcion
            if(option>0 && option<4)
            {
                idToEdit=request_Id(idToEdit);//Pido el id al usuario
                len=ll_len(pArrayListEmployee);//Cuento la cantidad de elementos de la lista
                for(i=0;i<len;i++)//para cada elemento de la lista
                {
                    pEmployer=(Employee*)ll_get(pArrayListEmployee,i);//lo obtengo al empleado en el indice i
                    bId=ll_indexOf(pArrayListEmployee,(Employee*)pEmployer);
                    if(idToEdit==bId)//si el id ingresado por el usuario es el que coinside con el de la lista
                    {
                        idToEdit=correctId;
                        break;
                    }
                }
                print_lineSpacing("Empleado a modificar: \n");//Imprimo el titulo
                print_lineSpacing("ID\tNOMBRE\tHORAS TRABAJADAS\tSUELDO \t \n");//Imprime en formato esl mensaje tipo tabla
                employee_print(pEmployer);//Imprimo al empleado en pantalla
            }
            switch(option)
            {
                case 1://Nombre
                    do//Nombre
                    {
                        strcpy(bNombre,request_nombre(bNombre));//Pido el nombre
                    }while(strlen(bNombre)==0);
                    bAnswer=getAnswer("Realmente quiere realizar el cambio? (s/n)\n",
                                      "ERROR DE TIPEO!",'s','n');
                    if(bAnswer==1)
                    {
                        employee_setNombre(pEmployer,bNombre);
                        printf("Operacion Realizada!\n");
                    }
                    else
                    {
                        printf("Operacion cancelada!\n");
                    }
                break;
                case 2:
                    bHorasTrabajadas=request_horasTrabajadas(bHorasTrabajadas);
                    bAnswer=getAnswer("Realmente quiere realizar el cambio? (s/n)\n",
                                    "ERROR DE TIPEO!",'s','n');
                    if(bAnswer==1)
                    {
                        employee_setHorasTrabajadas(pEmployer,bHorasTrabajadas);
                        printf("Operacion Realizada!\n");
                    }
                    else
                    {
                        printf("Operacion cancelada!\n");
                    }
                break;
                case 3:

                    bSueldo=request_sueldo(bSueldo);
                    bAnswer=getAnswer("Realmente quiere realizar el cambio? (s/n)\n",
                                      "ERROR DE TIPEO!",'s','n');
                    if(bAnswer==1)
                    {
                        employee_setSueldo(pEmployer,bSueldo);
                        printf("Operacion Realizada!\n");
                    }
                    else
                    {
                        printf("Operacion cancelada!\n");
                    }
                break;
                case 4:
                    printf("Salida! \n");
                break;
            }
        }while(option!=4);
        turnBack=TRUE;
    }
/*:::::::::::::EndCode::::::::::::::::::::::::::::::::::::**/
    pauseAndClean();
    return turnBack;
}
///int controller_removeEmployee FUNCTION_______________________________________________________________________________/////////
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int //  FALSE -> No se realiza la baja
 *             //  TRUE -> Se Modifica
 ***/
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    clear();
/*:::::::::::::Variable:::::::::::::::::::::::::::::::::::**/
    Employee* pEmployer = employee_new();//puntero a empleado contruido
    int turnBack,bAnswer;//retorno y valor de la respuesta
    int bId;//auxiliar del id
    int idToRemove=0;//id a borrar
    int i;//iterador
    int len;//Cantidad de elementos de la lista de empleados
/*:::::::::::::Code:::::::::::::::::::::::::::::::::::::::**/
    if(pEmployer!=NULL)
    {
        print_lineSpacing("\t BAJAS \n");//Imprimo el titulo.
        idToRemove=request_Id(idToRemove);//Pido el id al usuario
        len=ll_len(pArrayListEmployee);//Cuento cuantos elementos hay en la lista
        for(i=0;i<len;i++)//para cada elemento de la lista
        {
            pEmployer=(Employee*)ll_get(pArrayListEmployee,i);//lo obtengo al empleado en el indice i
            bId=ll_indexOf(pArrayListEmployee,(Employee*)pEmployer);//Tomo el indice correspondiente a pEmployer en la lista
            if(idToRemove==bId)//si el id ingresado por el usuario es el que coinside con el de la lista
            {
                print_lineSpacing("ID\tNOMBRE\tHORAS TRABAJADAS\tSUELDO \t \n");//Imprime en formato esl mensaje tipo tabla
                employee_print(pEmployer);//implime los datos del empleado pEmployer
                bAnswer=getAnswer("Realmente desea eliminar al empleado de la lista?",
                          "\n !->ERROR!. No ingreso una respuesta valida(s/n)",'s','n');//return:1->si||0->no
                if(bAnswer==1)
                {
                    ll_remove(pArrayListEmployee,idToRemove);//borro el indice de la lista
                    printf("El empleado fue borrado de la lista!\n");
                    turnBack=TRUE;
                    break;
                }
            }
        }
    }
    else
    {
        turnBack=FALSE;
    }
/*:::::::::::::EndCode::::::::::::::::::::::::::::::::::::**/
    pauseAndClean();
    return turnBack;
}
///int controller_ListEmployee FUNCTION_________________________________________________________________________________/////////
/** \brief Listar empleados: Esta funcion recive una lista dinamica
 *         va leyendo de a uno los elementos y los va mostrando, mientras
 *         haya elementos eln la lista.
 * \param pArrayListEmployee LinkedList* -> es una lista dinamica
 *
 * \return int // TRUE-> Lista los empleados
 *             // FALSE-> La lista esta vacia
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    clear();
/*:::::::::::::Variable::::::::::::::::::::::::::::::::::::::::::**/
    Employee* b_pEmployer;//buffer de un empleado de la lista
    int bId=0,bHorasTrabajadas=0,bSueldo=0;//buffers int
    char bNombre[50];//buffer nombre
    int turnBack,listLen,i;//Retorno,cantidad de lista, iterador
/*:::::::::::::Code::::::::::::::::::::::::::::::::::::::::::::::**/
    if(pArrayListEmployee!=NULL)
    {
        listLen=ll_len(pArrayListEmployee);//Me fijo cuantos elementos tiene la lista
        print_lineSpacing("ID\tNOMBRE\tHORAS TRABAJADAS\tSUELDO \t \n");//Imprimo en pantalla el formato para la tabla
        for(i=0;i<listLen;i++)
        {
            b_pEmployer=(Employee*)ll_get(pArrayListEmployee,i);//Agarro cada uno de los empleados de la lista
            if(b_pEmployer!=NULL)
            {
                /**Fijarse porque te tira warnings de inicializacion el llamado a esta funcion*/
                b_pEmployer=employee_getEmployer(b_pEmployer,bId,bNombre,bHorasTrabajadas,bSueldo);//le paso a la funcion los buffers para hacer el get de todos juntos
                employee_print(b_pEmployer);//imprimo un empleado*/
                turnBack=TRUE;
            }
        }
    }
    else
    {
        printf("OPS!!!....La lista esta vacia!.\n");
        turnBack=FALSE;
    }
/*:::::::::::::EndCode::::::::::::::::::::::::::::::::::::**/
    pauseAndClean();
    return turnBack;
}
///controller_sortEmployee FUNCTION________________________________________________________________________________//////////
/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    clear();
/*:::::::::::::Variable:::::::::::::::::::::::::::::::::::**/
    int option;
    int turnBack;
/*:::::::::::::Code:::::::::::::::::::::::::::::::::::::::**/
    do{
        print_lineSpacing("ORDENAR EMPLEADOS\n");//Imprimo el titulo
        optionMenuEdit();
        getValidInt("Ingrese una opcion del menu:\n",
                    "\n!->Error!: El caracter ingresado no es un numero!\n",
                    "\n!->Error!: Los numeros validos a ingresar van del 1 al 4",&option,1,4);
        switch(option)
        {
            case 1: //by name
                getValidInt("Ingrese 1 para orden ascendente 0 para descendente:\n",
                            "\n!->Error!: El caracter ingresado no es un numero!\n",
                            "\n!->Error!: Los numeros validos a ingresar son \"0->ascendente\" y\" 1->descendente\"",&option,0,1);
                if(option==0||option==1)
                {
                    printf("Esto podria tardar un momeno. Por favor, aguarde.\n");
                    ll_sort(pArrayListEmployee,employee_compareByName,option);
                    controller_ListEmployee(pArrayListEmployee);
                    turnBack=TRUE;
                    pauseAndClean();
                }
            break;
            case 2: //horas de trabajo
                option=getValidInt("Ingrese 1 para orden ascendente 0 para descendente:\n",
                                    "\n!->Error!: El caracter ingresado no es un numero!\n",
                                    "\n!->Error!: Los numeros validos a ingresar son \"0->ascendente\" y\" 1->descendente\"",&option,0,1);
                if(option==0||option==1)
                {
                    printf("Esto podria tardar un momeno. Por favor, aguarde.\n");
                    ll_sort(pArrayListEmployee,employee_compareByWorkHours,option);
                    controller_ListEmployee(pArrayListEmployee);
                    turnBack=TRUE;
                    pauseAndClean();
                }
            break;
            case 3: //sueldo
                option=getValidInt("Ingrese 1 para orden ascendente 0 para descendente:\n",
                                    "\n!->Error!: El caracter ingresado no es un numero!\n",
                                    "\n!->Error!: Los numeros validos a ingresar son \"0->ascendente\" y\" 1->descendente\"",&option,0,1);
                if(option==0||option==1)
                {
                    printf("Esto podria tardar un momeno. Por favor, aguarde.\n");//mensaje
                    ll_sort(pArrayListEmployee,employee_compareBySalary,option);//ordena
                    controller_ListEmployee(pArrayListEmployee);//imprime la lista
                    turnBack=TRUE;
                    pauseAndClean();
                }
            break;
        }
    }while(option!=4);
/*:::::::::::::EndCode::::::::::::::::::::::::::::::::::::**/
    system("pause");
    system("cls");
    return turnBack;
}
///controller_saveAsText FUNCTION_________________________________________________________________________________//////////
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
/*:::::::::::::Variable:::::::::::::::::::::::::::::::::::**/
    char bNombre[50];//buffer nombre
    int bId=0,bHorasTrabajadas=0,bSueldo=0;//buffers int
    int turnBack,i;//retorno y iterador
    int len;//cantidad de empleados en la lista
    FILE* pFile;//puntero al archivo
    Employee* b_pEmployer;//buffer de un empleado
/*:::::::::::::Code:::::::::::::::::::::::::::::::::::::::**/
    printf("Cargando los datos...\n");
    pFile=fopen(path,"w");//abro el archivo en modo escritura
        if(pFile!=NULL)//valido al archivo
        {
            if(pArrayListEmployee!=NULL)//valido la lista
            {
                fprintf(pFile,"%s","\n \t \"LISTA EMPLEADOS\" \n");
                b_pEmployer = employee_new();//Creo espacio en la lista para un empleado en el heap
                len=ll_len(pArrayListEmployee);//Cuento los elementos de la lista
                for(i=0;i<len;i++)//itero dentro del array list
                {
                    b_pEmployer=(Employee*)ll_get(pArrayListEmployee,i);//tomo un empleado de la lista
                    employee_getEmployer(b_pEmployer,bId,bNombre,bHorasTrabajadas,bSueldo);//obtengo cada elemento del elemento[i] de la lista
                    fprintf(pFile,"\n%d,%s,%d,%d\n",
                            b_pEmployer->id,b_pEmployer->nombre,
                            b_pEmployer->horasTrabajadas,b_pEmployer->sueldo);//Lo imprimo con el formato indicado en el archivo
                    turnBack=TRUE;
                }
            }
        }
        else
        {
            printf("\n Ops!...El archivo no existe! \n");
            turnBack=FALSE;
        }
    fclose(pFile);
    if(turnBack==TRUE)
    {
        printf("Datos Cargados\n");
    }
/*:::::::::::::EndCode::::::::::::::::::::::::::::::::::::**/
    system("pause");
    system("cls");
    return turnBack;
}
///controller_saveAsBinary FUNCTION_______________________________________________________________________________//////////
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{

/*:::::::::::::Variable:::::::::::::::::::::::::::::::::::**/
    char bNombre[50];//buffer nombre
    int bId=0,bHorasTrabajadas=0,bSueldo=0;//buffers int
    int turnBack,i;//retorno y iterador
    int len;//cantidad de empleados en la lista
    int employerSize;//Cantidad de elementos a escribir
    int write=0;//retorno de fwrite
    FILE* pFile;//puntero al archivo
    Employee* b_pEmployer;//buffer de un empleado
/*:::::::::::::Code:::::::::::::::::::::::::::::::::::::::**/
    line();
    printf("Cargando los datos...\n");
    line();
    pFile=fopen(path,"wb");//abro el archivo en modo escritura
        if(pFile!=NULL)//valido al archivo
        {
            if(pArrayListEmployee!=NULL)//valido la lista
            {
                fprintf(pFile,"%s","\n \t \"LISTA EMPLEADOS\" \n");
                b_pEmployer = employee_new();//Creo espacio en la lista para un empleado en el heap
                len=ll_len(pArrayListEmployee);//Cuento los elementos de la lista
                for(i=0;i<len;i++)//itero dentro del array list
                {
                    b_pEmployer=(Employee*)ll_get(pArrayListEmployee,i);//tomo un empleado de la lista
                    employee_getEmployer(b_pEmployer,bId,bNombre,bHorasTrabajadas,bSueldo);//obtengo cada elemento del elemento[i] de la lista
                    employerSize=strlen((char*)b_pEmployer);//cuento la cantidad de elementos para eso parseamos a char todos los elementos del auxiliar y contamos con strlen
                    write=fwrite (b_pEmployer, sizeof(Employee),employerSize,pFile );//escrivo en el archivo bin
                    turnBack=TRUE;//el retorno sera verdadero
                    if(write<employerSize)//Si lo que se escrive en la linea es menor a el tamaño medido por strlen
                    {
                        line();
                        printf("\n Ops!... No se a sobreescrito el archivo");
                        line();
                        turnBack=FALSE;//el retorno sera falso
                    }
                }
            }
        }
        else
        {
            line();
            printf("\n Ops!...El archivo no existe! \n");
            line();
            turnBack=FALSE;
        }
    fclose(pFile);
    if(turnBack==TRUE)
    {
        printf("Datos Cargados\n");
    }
/*:::::::::::::EndCode::::::::::::::::::::::::::::::::::::**/
    system("pause");
    system("cls");
    return turnBack;
}

////////////APART FUNCTIONS/////////////////////
/*
static int searchId(LinkedList* pArrayListEmployee,int id)
{
	int correctId=0,bId;
	int len;
	int i;
	Employee* pEmployer;
	id=request_Id(id);//Pido el id al usuario
	len=ll_len(pArrayListEmployee);//Cuento la cantidad de elementos de la lista
	for(i=0;i<len;i++)//para cada elemento de la lista
	{
		pEmployer=(Employee*)ll_get(pArrayListEmployee,i);//lo obtengo al empleado en el indice i
		bId=ll_indexOf(pArrayListEmployee,(Employee*)pEmployer);
		if(id==bId)//si el id ingresado por el usuario es el que coinside con el de la lista
		{
			correctId=id;
			break;
		}
	}
	return correctId;
}
*/
