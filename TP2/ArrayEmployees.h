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

////////////////////////PROTOTYPES////////////////////////////////////
/**:::::::::::::*TP2 ARRAYEMPLOYEES FUNCTION:::::::::::**/
int initEmployees(Employee*,int);
void addEmployeeint(Employee* array, int size,int id, char* name,char* lastName,
float salary,int sector);
int findEmployeeById(Employee*,int,int);
int removeEmployee(Employee*,int,int);
int sortEmployees(Employee*,int,int);
int printEmployees(Employee*,int);
/********************************************************/

//*************OTHER FUNCTIONS***************************/
int findVoidId(Employee*,int);

/**::::::::::::::::CHARGE FUNCTIONS::::::::::::::::::::**/
int chargeEmployer(Employee*,int);
int takeOffSystemEmployee(Employee*,int);
int editEmployers(Employee*,int);
int order(Employee* array,int size);
int averageReport(Employee* array,int size);
/********************************************************/

/**::::::::::::::::ORDER FUNCTIONS:::::::::::::::::::::**/
void alphabeticOrder_A_Z(Employee*, int);
void alphabeticOrder_Z_A(Employee*,int);////
void downUpNumberOrder(Employee*,int);/////
void upDownNumberOrder(Employee*,int);////
/********************************************************/

float average(Employee* array,int size);
float TotalSalary(Employee* array,int size);
int employersOverAverage(Employee* array,int size);
/**::::::::::::::::PRINT FUNCTIONS:::::::::::::::::::::**/
void printOneEmployee(Employee );
void editOptionMenu();
void orderMenu();
void infoMenu();
/********************************************************/
void hardcode(Employee* array, int size);
void pauseAndClean();
void clear();
////////////////////////////////////////////////////////////////////////////







