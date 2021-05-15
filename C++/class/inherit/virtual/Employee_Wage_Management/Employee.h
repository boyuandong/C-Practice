// Employee.h
class Employee
{
private:
    long number;
    char name[20];
public:
    Employee(const long, const char *);
    virtual ~Employee();                        // virtual destructor
    const char * getName()const;
    const long getNumber()const;
    virtual double earnings()const = 0;         // Pure virtual fun, get the monthly earnings
    virtual void print()const;                  // virtural fun, print number, name
    Employee *next;                             // By adding this, can create a linked list
};

