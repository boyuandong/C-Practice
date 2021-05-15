// PieceWorker.h
class PieceWorker : public Employee
{
    private:
        double wagePerPiece;
        int quantity;
    public:
        PieceWorker(const long, const char*,double=0.0, int=0);
        ~PieceWorker(){}
        void setWage(double);
        void setQuantity(int);
        virtual double earnings()const;
        virtual void print()const;
};