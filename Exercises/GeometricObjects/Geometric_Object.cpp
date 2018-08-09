
#include "Geometric_Object.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;


// ***** Point *****

Point *Point::clone() const
{
    return new Point{ *this };
}

std::string Point::to_string() const
{
    return "Point@5[x=" + std::to_string(x) + ",y=" + std::to_string(y) + "]\n";
}

// ***** Line *****

Line *Line::clone() const
{
    return new Line{ *this };
}

double Line::get_length() const
{
    return sqrt( pow( x2 - x1, 2 ) + pow( y2 - y1, 2 ) );
}

std::string Line::to_string() const
{
    return "Line@4[x1=" + std::to_string(x1) + ",y1=" + std::to_string(y1) +
                          std::to_string(x2) + ",y2=" + std::to_string(y2) + "]\n";
}

// ***** Circle *****
Circle *Circle::clone() const
{
    return new Circle{ *this };
}

double Circle::get_radius() const
{
    return radius;
}

double Circle::get_area() const
{
    return 3.14 * radius * radius;
}

double Circle::get_perimeter() const
{
    return 2.0 * radius * 3.14;
}

std::string Circle::to_string() const
{
    return "Circle@6[r=" + std::to_string(radius) + "]\n";
}

// ***** Circular Cylinder *****

Circular_Cylinder *Circular_Cylinder::clone() const
{
    return new Circular_Cylinder{ *this };
}

double Circular_Cylinder::get_height() const
{
    return height;
}


 double Circular_Cylinder::get_area() const
 {
     return 1.0;
     //return Circle::get_perimeter() * height + 2 * Circle::get_area();
 }
 
 double Circular_Cylinder::get_volume() const
 {
     return 1.0;
     //return Circle::get_area() * height;
 }

std::string Circular_Cylinder::to_string() const
{
    return "Circular_Cylinder@17[r=" + std::to_string(radius) +
                              ", h=" + std::to_string(height) + "]\n";
}


// ***** Rectangle *****

Rectangle *Rectangle::clone() const
{
    return new Rectangle{ *this };
}

double Rectangle::get_sideA() const
{
    return a;
}

double Rectangle::get_sideB() const
{
    return b;
}

double Rectangle::get_area() const
{
    return a * b;
}

double Rectangle::get_perimeter() const
{
    return ( a * 2 ) + ( b * 2 );
}

std::string Rectangle::to_string() const
{
    return "Rectangle@9[side1=" + std::to_string(a) +
                     ", side2=" + std::to_string(b) + "]\n";
}

// ***** Rectangular prism *****

Rectangular_Prism *Rectangular_Prism::clone() const
{
    return new Rectangular_Prism{ *this };
}

double Rectangular_Prism::get_volume() const
{
    return Rectangle::get_area() * height;
}

double Rectangular_Prism::get_area() const
{
    return 2 * Rectangle::get_area() + Rectangle::get_sideA() * height * 2 + Rectangle::get_sideB() * height * 2;
}

std::string Rectangular_Prism::to_string() const
{
    return "Rectangular_Prism@17[side1=" + std::to_string(a) +
                              ", side2=" + std::to_string(b) +
                                  ", h=" + std::to_string(height) + "]\n";
}

// ***** Triangle *****
Triangle *Triangle::clone() const
{
    return new Triangle{ *this };
}

double Triangle::get_sideA() const
{
    return a;
}

double Triangle::get_sideB() const
{
    return b;
}

double Triangle::get_sideC() const
{
    return c;
}

double Triangle::get_area() const
{
    return ( a * b ) / 2.0;
}

double Triangle::get_perimeter() const
{
    return ( a * 2 ) + ( b * 2 );
}

std::string Triangle::to_string() const
{
    return "Triangle@8[side1=" + std::to_string(a) +
                             ", side2=" + std::to_string(b) +
                             ", side3=" + std::to_string(c) + "]\n";
}

// ***** Triangular Prism *****
Triangular_Prism *Triangular_Prism::clone() const
{
    return new Triangular_Prism{ *this };
}

double Triangular_Prism::get_area() const
{
    return b * height + a * height + c * height + Triangle::get_area() * 2.0;
}

double Triangular_Prism::get_volume() const
{
    return ( Triangle::get_area() * height ) / 2.0;
}

std::string Triangular_Prism::to_string() const
{
    return "Triangular_Prism@16[side1=" + std::to_string(a) +
                             ", side2=" + std::to_string(b) +
                             ", side3=" + std::to_string(c) +
                             ", height="+ std::to_string(height) + "]\n";
}











