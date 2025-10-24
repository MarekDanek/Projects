

class Vector
{
    public:
        Vector();
        void set_x(double x_);
        void get_x();
        void set_y(double y_);     
        void get_y();
        double lenVector();
        double SqaureLenVector();
        Vector ScaleVector();
        
    private:
        double x;
        double y;
        Vector operator+(const Vector& other) const;
        Vector operator-(const Vector& other) const;
        Vector operator*(const double& other) const; 

};

