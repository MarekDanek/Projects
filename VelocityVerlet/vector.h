#pragma once

class Vector
{
    public:                    
        Vector();
        Vector(double x_, double y_);   
        void set_x(double x_);
        double get_x() const;
        void set_y(double y_);     
        double get_y() const;
        double lenVector();
        double SquareLenVector();
        Vector ScaleVector(double s) const;
        
    private:
        double x;
        double y;
        Vector operator+(const Vector& other) const;
        Vector operator-(const Vector& other) const;
        Vector operator*(const double& other) const; 

};

