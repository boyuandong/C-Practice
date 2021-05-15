// HourlyWorker.h
class HourlyWorker : public Employee
{
private:
    double wage;
    double hours;
public:
    HourlyWorker(const long, const char*, double=0.0, int=0);
    ~HourlyWorker() {}
    void setWage(double);
    void setHours(int);
    virtual double earnings()const;
    virtual void print()const;
};
