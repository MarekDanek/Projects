

class Vector
{
    public:                    
        Vector();
        Vector(double x_, double y_);   
        double set_x(double x_);
        double get_x();
        double set_y(double y_);     
        double get_y();
        double lenVector();
        double SquareLenVector();
        Vector ScaleVector(double s);
        
    private:
        double x;
        double y;
        Vector operator+(const Vector& other) const;
        Vector operator-(const Vector& other) const;
        Vector operator*(const double& other) const; 

};

