
#include "Geometric_Object.h"
#include "Serializeable.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include <iterator>

using namespace std;

int main()
{
    vector<Geometric_Object*> objects {
        new Point{ 3.0, 2.0 },
        new Line{ 1.0, 2.0, 3.0, 5.0 },
        new Circle{ 3.0 },
        new Rectangle{ 4.0, 2.0 },
        new Triangle{ 2.0, 3.0, 3.0 },
        new Circular_Cylinder{ 3.0, 5.0 },
        new Rectangular_Prism{ 1.0, 4.0, 2.0 },
        new Triangular_Prism{ 3.0, 2.0, 2.0, 7.0 }
    };
    
    for (auto obj : objects)
    {
        Cloneable *copy{ obj->clone() };
        
        if (copy != nullptr)
        {
            cout << "\nType: " << typeid(*copy).name() << endl;
            
            // Point
            Point *point{ dynamic_cast<Point*>(copy) };
            if (point)
                cout << "Point: " << point->x << " " << point->y << endl;
            
            // Line
            Line *line{ dynamic_cast<Line*>(copy) };
            if (line)
                cout << "Length: " << line->get_length() << endl;
            
            // Plane
            Plane *plane{ dynamic_cast<Plane*>(copy) };
            if (plane)
            {
                cout << "Area: " << plane->get_area() << endl;
                cout << "Perimeter: " << plane->get_perimeter() << endl;
            }
            
            // Solid
            Solid *solid{ dynamic_cast<Solid*>(copy) };
            if (solid)
            {
                cout << "Area: "   << solid->get_area() << endl;
                cout << "Volume: " << solid->get_volume() << endl;
            }
            
            // Serializeable version
            Serializeable *serializable{ dynamic_cast<Serializeable*>(copy) };
            if (serializable)
            {
                cout << "Serializable: " << serializable->str() << endl;
            }
            
            delete copy;
        }
    }
    
    // Releasing the memory for the dynamic objects in the vector
    
    // Destroy the copy
    transform( begin( objects ), end( objects ), begin( objects ), []( Geometric_Object *p )
    {
        delete p;
        return nullptr;
    });
    
    // Clear the vector
    for_each( begin( objects ), end( objects ), []( Geometric_Object *&p )
    {
        delete p;
        return nullptr;
    });
    
    return 0;
}
