
#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H

#include "Cloneable.h"
#include "Serializeable.h"

#include <cmath>
#include <string>

class Geometric_Object : public Cloneable, public Serializeable
{
public:
    //Geometric_Object() = default;
    ~Geometric_Object() = default;
    
protected:
    Geometric_Object() = default;
    Geometric_Object(const Geometric_Object&) = default;
    
};

//abstract classes
struct Plane
{
    Plane() = default;
    ~Plane() = default;
    
    virtual double get_area() const = 0;
    virtual double get_perimeter() const = 0;
};

struct Solid
{
    Solid() = default;
    ~Solid() = default;
    
    virtual double get_area() const = 0;
    virtual double get_volume() const = 0;
};

class Point final: public Geometric_Object
{
public:
    Point() = default;
    Point( double a, double b ) : x{ a }, y{ b } {}
    
    ~Point() = default;
    
    double x { 0 };
    double y { 0 };
    
    Point *clone() const override;
    
protected:
    std::string to_string() const override;
    
};

class Line final: public Geometric_Object
{
public:
    Line() = default;
    Line(double a1, double b1, double a2, double b2) : x1{ a1 }, y1{ b1 }, x2{ a2 }, y2{ b2 } {}
    
    ~Line() = default;
    
    double x1{ 0 };
    double y1{ 0 };
    double x2{ 0 };
    double y2{ 0 };
    
    double get_length() const;
    
    Line *clone() const override;
    
protected:
    std::string to_string() const override;
    
};

class Circle : public Geometric_Object, public Plane
{
public:
    Circle() = default;
    Circle( double r ) : radius{ r } {}
    
    ~Circle() = default;
    
    double get_radius() const;
    double get_area() const override;
    double get_perimeter() const override final;
    
    Circle *clone() const override;
    
protected:
    double radius{ 1.0 };
    std::string to_string() const override;
    
};

class Circular_Cylinder final : public Circle, public Solid
{
public:
    Circular_Cylinder() = default;
    Circular_Cylinder( double r, double h ) : Circle{ r }, height{ h } {}
    
    ~Circular_Cylinder() = default;
    
    double get_area() const override;
    double get_volume() const override;
    double get_height() const;
    
    Circular_Cylinder *clone() const override;

private:
    double height{ 1.0 };
    std::string to_string() const override;
};


class Rectangle : public Geometric_Object, public Plane
{
public:
    Rectangle() = default;
    Rectangle( double s1, double s2 ) : a{ s1 }, b{ s2 } {}
    
    ~Rectangle() = default;
    
    Rectangle *clone() const override;
    
    double get_sideA() const;
    double get_sideB() const;
    double get_area() const override;
    double get_perimeter() const override;
    
protected:
    std::string to_string() const override;
    
    double a{ 1.0 };
    double b{ 1.0 };
    
};

class Rectangular_Prism final: public Rectangle, public Solid
{
public:
    Rectangular_Prism() = default;
    Rectangular_Prism( double a, double b, double h ) : Rectangle{ a, b }, height{ h } {}
    
    ~Rectangular_Prism() = default;
    
    Rectangular_Prism *clone() const override;
    
    double get_volume() const override;
    double get_area() const override;
    
protected:
    std::string to_string() const override;
    
private:
    double height{ 1.0 };
    
};


class Triangle : public Geometric_Object, public Plane
{
public:
    Triangle() = default;
    Triangle( double s1, double s2, double s3 ) : a{ s1 }, b{ s2 }, c{ s3 } {}
    
    ~Triangle() = default;
    
    Triangle *clone() const override;
    
    double get_sideA() const;
    double get_sideB() const;
    double get_sideC() const;
    double get_area() const override;
    double get_perimeter() const override;

protected:
    double a{ 1.0 };
    double b{ 1.0 };
    double c{ 1.0 };
    
private:
    std::string to_string() const override;
};

class Triangular_Prism final: public Triangle, public Solid
{
public:
    Triangular_Prism() = default;
    Triangular_Prism( double a, double b, double c, double h ) : Triangle{ a, b, c }, height{ h } {}
    
    ~Triangular_Prism() = default;
    
    Triangular_Prism *clone() const override;
    
    double get_area() const override;
    double get_volume() const override;
    
private:
    double height{ 1.0 };
    std::string to_string() const override;
};


#endif /* Geometric_Object_h */


