// EXERCISES STATEMENTS

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    
    // Ex 1
    
    string line = "abc defgh ijk";
    
    int space_count = 0;
    int i2 = 0;
    int length = sizeof(line);
    
    for (int i = 0; i < length; ++i)
    {
        if (line[i] == ' ' )
            ++space_count;
    }
    cout << space_count << endl;
    space_count = 0;
    
    while (i2 < length)
    {
        if (line[i2] == ' ' )
            ++space_count;
        
        i2++;
    }
    cout << space_count << endl;
    space_count = 0;
    
    
    // Ex 2 - Loop through string using pointer
    
    char line2[]{ "aaa bb ccc d" };
    int length2{ sizeof(line2) };
    
    for (char *p = line2; p != line2 + length2; ++p)
    {
        if (*p == ' ' )
            ++space_count;
    }
    
    cout << space_count << endl;
    space_count = 0;
    
    
    // EX 3 - Use range access functions
    
    for (auto p = begin(line2); p != end(line2); ++p)
    {
        if (*p == ' ' )
            ++space_count;
    }
    
    cout << space_count << endl;
    space_count = 0;
    
    // EX 4 - Use range base for statements
    for (auto c : line2)
    {
        if (c == ' ')
            ++space_count;
    }
    
    cout << space_count << endl;
    space_count = 0;
    
    
    return 0;
}







