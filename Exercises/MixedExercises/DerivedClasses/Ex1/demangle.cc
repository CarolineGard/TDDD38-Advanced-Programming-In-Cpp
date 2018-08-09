/*
 * demangle.cc    Name demangle
 */
#include <cxxabi.h>
#include <typeinfo>
#include <string>
using namespace std;
using abi::__cxa_demangle;

string demangle_name(type_info const& typeinfo)
{
   int status;
   char* name = __cxa_demangle(typeinfo.name(), 0, 0, &status);

   if (name)
   {
      string ret(name);
      free(name);
      return ret;
   }

   if (status == 0)
      return "error code = 0: success";
   else if (status == -1)
      return "error code = -1: memory allocation failure";
   else if (status == -2)
      return "error code = -2: invalid mangled name";
   else if (status == -3)
      return "error code = -3: invalid arguments";
   else
      return "error code unknown - who knows what happened";
}
