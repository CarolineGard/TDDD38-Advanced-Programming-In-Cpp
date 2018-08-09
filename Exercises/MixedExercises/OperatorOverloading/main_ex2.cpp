// OPERATOR OVERLOADING, EX 2

/*
Construct a class named ifcharstream with operator[] overloaded for reading characters from a text file randomly.
A file name is to be given when an ifcharstream object is created, and a file stream for both reading and writing
is to be opened and bound to the given file.
*/

#include <iostream>
#include <istream>
#include <fstream>
#include <cstdio>
#include <stdexcept>

using namespace std;

const string DIR = "/Users/kakan/Documents/LINKOPING/TDDD38-AdvancedCpp/exercises/MixedExercises/OperatorOverloading/Ex2/Ex2/";

class ifcharstream
{
public:
    ifcharstream() = default;
    ifcharstream(const string &fileName);
    
    char operator[](streampos pos) const;
    void close();
    
private:
    mutable ifstream file_;
    bool open_{ false };
};

ifcharstream::ifcharstream(const string &fileName)
{
    file_.open( fileName.c_str(), ios::in | ios::binary );
    
    if(file_)
        open_ = true;
    
    else
        cout << "Could not open the file: " << fileName << endl;
}

void ifcharstream::close()
{
    if(open_)
    {
        file_.close();
        open_ = false;
    }
}

char ifcharstream::operator[](streampos pos) const
{
    if (!open_)
    {
        cout << "No file opened" << endl;
        return '0';
    }
    char c;
    file_.seekg(pos);
    file_.read(&c, sizeof(char));
    return c;
}

int main()
{
    // Creating example file
    char data[]{ "0123456789abcdefghijklmnopqrstuvxyzABC" };
    constexpr unsigned n_char{ sizeof(data) - 1 }; //why???????????????????
    
    ofstream output{ DIR + "TEMP.TXT", ios::binary };
    if (output.is_open()) {
        
        for (auto it = begin(data); it != end(data); ++it)
            output.write( it, sizeof(char) );
    
        output.close();
    }
    else {
        cout << "Failed to create file" << endl;
        return 0;
    }
    
    // Read from file
    ifcharstream input{ DIR + "TEMP.TXT" };
    
    int pos_nr;
    
    do {
        cout << "Give a position number in the range 0 to " << n_char - 1 << ": ";
        cin >> pos_nr;
        
        if (pos_nr < n_char)
            cout << "At position: " << pos_nr << " : " << input[pos_nr] << endl;
            
        else
            cout << "Not a valid number!" << endl;
        
    } while (pos_nr < n_char);
    
    input.close();
    
    return 0;
}
