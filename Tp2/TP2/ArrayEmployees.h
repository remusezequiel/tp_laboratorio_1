#define DOWN 1 //SIGNIFICA BAJA
#define UP 0 //SIGNIFICA ALTA

#define EMPLOYEE_LEN 51

//Estos los escogi al azar ya que la funcion que habia hecho valida extremos
#define LOW_FLOAT 0.0001
#define HI_FLOAT 1000000.1
#define LOW_SECTOR 0
#define HI_SECTOR 10


////////STRUCTS TYPES///////
typedef struct
{
    int id;
    char name[EMPLOYEE_LEN];
    char lastName[EMPLOYEE_LEN];
    float salary;
    int sector;
    int isEmpty;

}Employee;
////////////////////////////

////////////PROTOTYPES////////////////////////////////////

int initEmployees(Employee*,int);
int generateNextId(void);
int findVoidId(Employee* ,int );
int findEmployeeById(Employee* ,int ,int );
int removeEmployee(Employee*,int,int);

/*****************ORDER FUNCTIONS********************/
void alphabeticOrder_A_Z(Employee*  , int );
void alphabeticOrder_Z_A(Employee*  , int );////
void downUpNumberOrder(Employee*  , int );/////
void upDownNumberOrder(Employee*  , int );////
int sortEmployees(Employee* ,int ,int );
/****************************************************/

/****************CHARGE FUNCTIONS********************/
int addEmployee(Employee*,int,int,char,char,float,int);
int chargeEmployer(Employee* , int );
/****************************************************/

/*****************PRINT FUNCTIONS********************/
void printOneEmployee(Employee );
int printEmployees(Employee*,int);
/****************************************************/
/////////////////////////////////////////////////////////////







