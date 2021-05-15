// Manager.h
class Manager : public Employee
{
private:
    double monthlySalary;
public:
    Manager(const long, const char *, double=0.0);
    ~Manager(){}
    void setMonthlySalary(double);
    virtual double earnings()const;
    virtual void print()const;
};
