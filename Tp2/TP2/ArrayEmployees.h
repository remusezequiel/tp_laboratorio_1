#define TRUE 1 //SIGNIFICA BAJA
#define FALSE 0 //SIGNIFICA ALTA

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;




int initEmployees(Employee*,int);
int generateNextId(void);
int findVoidId(Employee* ,int );
int findEmployeeById(Employee* ,int ,int );
int removeEmployee(Employee*,int,int);

/*****************ORDER FUNCTIONS********************/
void alphabeticOrder_A_Z(Employee*  , int );
void alphabeticOrder_Z_A(Employee*  , int );
void downUpNumberOrder(Employee*  , int );
void upDownNumberOrder(Employee*  , int );
int sortEmployees(Employee* ,int ,int );
/****************************************************/


int addEmployee(Employee*,int,int,char,char,float,int);
void printOneEmployee(Employee );
int printEmployee(Employee*,int);









