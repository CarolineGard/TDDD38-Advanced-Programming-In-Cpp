/*
 * demangle.h    Name demangle
 */
#ifndef DEMANGLE_H
#define DEMANGLE_H
#include <typeinfo>
#include <string>

std::string demangle_name(std::type_info const& typeinfo);

#endif
