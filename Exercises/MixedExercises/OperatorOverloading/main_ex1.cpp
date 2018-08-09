//EXERCISE OPERATOR OVERLOADING
/*
 Define a type for storing a persons name (first and last name as two separate strings) and address (street, post code and city as three separate strings). Overload the operator>> and operator<< to read and write, respectively, such data, given a certain format (e.g first and last name in that order on the first line and the three parts of the address on three successive lines). Write a test program which copies a stream of names and addresses.
 */

#include <iostream>
#include <iomanip>

using namespace std;

class Person
{
public:
    Person() = default;
    Person(string n, string s, string st, string p, string c) :
           name{ n }, surname{ s }, street{ st }, postcode{ p }, city{ c } {}
    
    void setName(string n)     { name = n; }
    void setSurname(string s)  { surname = s; }
    void setStreet(string st)  { street = st; }
    void setPostCode(string p) { postcode = p; }
    void setCity(string c)     { city = c; }
    
    string getName(string n)     { return name; }
    string getSurname(string s)  { return surname; }
    string getStreet(string st)  { return street; }
    string getPostCode(string p) { return postcode; }
    string getCity(string c)     { return city; }
    
    friend ostream &operator<<(ostream &os, const Person &p);
    friend istream &operator>>(istream &is, Person &p);
    
private:
    string name;
    string surname;
    string street;
    string postcode;
    string city;
};

ostream &operator<<(ostream &os, const Person &p)
{
    return os << p.name << ' '
              << p.surname << "\n"
              << p.street << "\n"
              << p.postcode << "\n"
              << p.city;
}

istream &operator>>(istream &is, Person &p)
{
    is >> p.name >> p.surname >> ws;
    getline(is, p.street);
    getline(is, p.postcode);
    getline(is, p.city);
    
    return is;
}

int main()
{
    Person p;
    cout << "Write Person:" << endl;
    while ( cin >> p )
    {
        cout << setfill('-') << setw(40) << '-' << setfill(' ') << endl;
        cout << p;
        cout << "\n" << setfill('-') << setw(40) << '-' << setfill(' ') << endl;
        cout << "Write new Person:" << endl;
    }
    
    return 0;
}












