#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Context classes

// Base context
class Context
{
public:
    Context() : id{count_++} {}
    //Context() { id = count_++; }

    Context(Context const &) = delete;
    Context operator=(Context const&) = delete;
    virtual ~Context() = default;

    void reset()
    {
        id = ++count_;
    }

    virtual ostream &print(ostream &os) const
    {
        return os << "Context " << '[' << id << ']';
    }

private:
    //static int count_;
    static int count_;
    int id;
};

//Need to define static data members outside of class
//since only one definition is allowed in the compiler
int Context::count_{0};


class NamedContext : public Context
{
public:
    NamedContext(string const &n) : Context{}, name_{n} {}

    void set_name(string const &n) { name_ = n; }

    ostream &print(ostream &os) const override
    {
        os << "Named ";
        Context::print(os);
        os << ' ' << '"' << name_ << '"';
        return os;
    }

private:
    string name_;
};

class Event
{
public:
    Event() = default;
    Event(Event const &) = delete;
    virtual ~Event() = default;

    virtual void apply(Context &c) = 0;
};


class RenameEvent : public Event
{
public:
    RenameEvent(string const &n) : name_{n} {}

    void apply(Context &c) override
    {
        c.print(cout);
        cout << " is reset to: ";
        auto name = dynamic_cast<NamedContext*>(&c);
        if (name)
            name->set_name(name_);

        c.reset();
        c.print(cout);
    }

private:
    string name_;
};

class ResetEvent : public Event
{
public:

    void apply(Context &c) override
    {
        c.print(cout);
        cout << " is reset to: ";
        c.reset();
        c.print(cout);
    }
};

void apply_events(Context & c, vector<Event*> const v)
{
    for (auto & event : v)
    {
        event->apply(c);
        cout << endl;
    }
}

int main()
{

    Context c { };
    NamedContext nc { "My Context" };

    vector<Event*> v { new ResetEvent(), new RenameEvent("My Event") };

    apply_events(c, v);
    apply_events(nc, v);

    return 0;
}



