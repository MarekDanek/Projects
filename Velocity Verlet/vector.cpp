#include "vector.h"
#include <cmath>

//public function
Vector::Vector() : x(0.0), y(0.0) {}

Vector::Vector(double x_, double y_) : x(x_), y(y_) {}

double Vector::set_x(double x_)
{
    x = x_;
}

double Vector::get_x(){
    return x;
}

double Vector::set_y(double y_){
    return y = y_;
}

double Vector::get_y(){
    return y;
}

double Vector::lenVector(){
    return std::sqrt(x*x + y*y);
}

double Vector::SquareLenVector(){
    return x*x + y*y;
}

Vector Vector::ScaleVector(double s){
    return Vector(x * s, y * s);
}

//private function
Vector Vector::operator+(const Vector& other) const {
    return Vector(x + other.x, y + other.y);
}

Vector Vector::operator-(const Vector& other) const {
    return Vector(x - other.x, y - other.y);
}

Vector Vector::operator*(const double& s) const {
    return Vector(x * s, y * s);
}