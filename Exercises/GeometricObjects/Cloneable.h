#ifndef CLONEABLE_H
#define CLONEABLE_H

// Interface class
// Creates a dynamically allocated copy of the object
// Returns pointer to the new object
struct Cloneable {
    virtual ~Cloneable() = default;
    virtual Cloneable *clone() const = 0;
};

#endif
