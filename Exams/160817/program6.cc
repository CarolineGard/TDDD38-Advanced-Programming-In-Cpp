/*
 * program6.cc
 */
#include <iostream>
#include <string>
#include <ostream>

using namespace std;

// Define Celestial_Body classes here
class Celestial_Body
{
public:
    Celestial_Body(string const &n, double const &s) : name_{ n }, size_{ s } {}
    virtual ~Celestial_Body() = 0;
    
    string get_name() const
    {
        return name_;
    }
    
    double get_size() const
    {
        return size_;
    }
    
    
protected:
    virtual string type_id() const = 0;
    
    Celestial_Body(Celestial_Body const &) = delete;
    Celestial_Body &operator=(Celestial_Body const &) = delete;
    
private:
    string const name_;
    double const size_;
};

// A pure virtual function is needed to get an abstract base class
Celestial_Body::~Celestial_Body() = default;


class Star final: public Celestial_Body
{
public:
    Star( string const &n, double const &s, string const &g ) : Celestial_Body{ n, s }, galaxy_{ g } {}
    
    string get_galaxy() const
    {
        return galaxy_;
    }
    
    
private:
    string const galaxy_;
    string type_id() const override { return "Star"; }
};

class Planet : public Celestial_Body
{
public:
    Planet(string const &n, double const &s, Celestial_Body &c, double const &ot, bool const p = false )
    : Celestial_Body{ n, s }, parent_{ c }, orbit_time_{ ot }, populated_{ p } {}
    
    Celestial_Body &get_celestial_body() const
    {
        return parent_;
    }
    
    double get_orbit_time() const
    {
        return orbit_time_;
    }
    
    bool is_populated() const
    {
        return populated_;
    }
    
    void populated(bool const p)
    {
        populated_ = p;
    }
    
    
private:
    Celestial_Body &parent_;
    double const orbit_time_;
    bool populated_;
    string type_id() const override { return "Planet"; }
};

class Moon final: public Planet
{
public:
    using Planet::Planet;

};


void print(const Celestial_Body& cb)
{
    // Depending on kind of celestial body, print its correspending data. Output
    // shall be as follows:
    // Helios: star, radius 696342.0 km, belongs to galaxy Milky Way
    // Earth: planet, radius 6371.0 km, belongs to star Helios, orbit time 365.2 days, populated
    // Moon: moon, radius 1737.1 km, belongs to planet Earth, orbit time 27.3 days, not populated
    
    auto star = dynamic_cast<Star const*>(&cb);
    auto planet = dynamic_cast<Planet const*>(&cb);
    auto moon = dynamic_cast<Moon const*>(&cb);
    
    cout << cb.get_name();
    
    if (star)
        cout << ": star";
    
    else if (planet)
        cout << ": planet";
    
    else
        cout << ": moon";
    
    cout << ", radius " << cb.get_size() << " km, belongs to ";
    
    if (star)
        cout << "galaxy " << star->get_galaxy() << endl;
    
    else {
        if (moon)
            cout << "planet ";
        
        else if(planet)
            cout << "star ";
        
        cout << planet->get_celestial_body().get_name()
             << ", orbit time " << planet->get_orbit_time() << " days, "
             << (planet->is_populated() ? "" : "not ") << "populated" << endl;
    }
}

int main()
{
    // Declare statically one object of each of type Star, Planet, and Moon. Use
    // the following data to initialize the objects (use defaults when suitable):
    // Star: name Helios, radius 696342.0, belongs to galaxy Milky Way
    // Planet: name Earth, radius 6371.0, belongs to star Helios, orbit time 365.2 days, populated
    // Moon: name Moon, radius 1737.1, belongs to planet Earth, orbit time 27.3 days, not populated
    Star s{ "Helios", 696342.0, "Milky Way" };
    Planet p{ "Earth",  6371.0, s, 365.2, true };
    Moon m { "Moon", 1737.1, p, 27.3, false };
    
    // Call print() for each object above.
    print(s);
    print(p);
    print(m);
    
   return 0;
}
