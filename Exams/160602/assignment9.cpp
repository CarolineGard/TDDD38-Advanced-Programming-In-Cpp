#include <memory>
#include <vector>
#include <iostream>

using namespace std;

const int ROOM_TEMP = 22;

// Base Class
class Sauna
{
public:
    virtual ~Sauna() = default;
    
    Sauna *clone() const
    {
        return get_clone();
    }
    
    friend ostream &operator<<(ostream &os, Sauna const &s)
    {
        os << s.str() << " " << ((s.is_on()) ? "[ON]": "[OFF]")
           << ", current temperature: " << s.get_temperature() << endl;
        
        return os;
    }
    
    void set_temperature(double const &t)
    {
        temp_ = t;
    }
    
    double get_temperature() const
    {
        return temp_;
    }
    
    bool is_on() const { return on_; }
    
    void turn_on() {
        on_ = true;
        temp_ = default_temp_;
    }
    
    void turn_off() {
        on_ = false;
        temp_ = ROOM_TEMP;
    }
    
protected:
    Sauna(double t = ROOM_TEMP) : default_temp_{ t } {}
    Sauna(Sauna const &) = default;
    Sauna &operator=(Sauna const &) = delete;
    
private:
    virtual string str() const = 0;
    virtual Sauna *get_clone() const = 0;
    
    double temp_{ROOM_TEMP};
    double default_temp_;
    bool on_{ false };
};

// Subclasses
class Steam_Heater : public Sauna
{
public:
    Steam_Heater() : Sauna{ 38 } {}

private:
    Steam_Heater(Steam_Heater const &) = default;
    
    std::string str() const override
    {
        return "Steam sauna";
    }
    
    Steam_Heater *get_clone() const override
    {
        return new Steam_Heater{*this};
    }
};

class Wood_Heater: public Sauna
{
public:
    Wood_Heater() : Sauna{} {}
    
    Wood_Heater *get_clone() const override
    {
        return new Wood_Heater{*this};
    }
    
    void add_logs(int nr)
    {
        set_temperature(get_temperature() + (5*nr));
    }
    
    std::string str() const override
    {
        return "Wood-burning sauna";
    }
};


class Electrical_Heater: public Sauna
{
public:
    Electrical_Heater() : Sauna{ 85 } {}
    
    Electrical_Heater *get_clone() const override
    {
        return new Electrical_Heater{*this};
    }
    
    std::string str() const override
    {
        return "Electrical sauna";
    }
    
private:
};

void do_stuff(unique_ptr<Sauna> const &s)
{
    s->turn_on();
    
    auto wood = dynamic_cast<Wood_Heater*>(s.get());
    if (wood)
        wood->add_logs(10);
        
    cout << *s << endl;
}

int main()
{
    vector<shared_ptr<Sauna>> V {
        make_shared<Steam_Heater>(),
        make_shared<Wood_Heater>(),
        make_shared<Electrical_Heater>()
    };
    
    for (auto x : V)
        cout << *x << endl;
    
    for (auto x : V)
        do_stuff(unique_ptr<Sauna>{x->clone()});
    
    return 0;
}
