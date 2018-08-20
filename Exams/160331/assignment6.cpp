#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <functional>
#include <memory>


using namespace std;


// Abstract base class
class Score_Variant
{
public:
    virtual ~Score_Variant() = default;
    virtual int score(vector<int> const &) = 0;
    virtual string name() const = 0;
    
protected:
    Score_Variant() = default;
    
private:
    Score_Variant(Score_Variant const &) = delete;
    Score_Variant &operator=(Score_Variant const &) = delete;
};

// Subclasses

class Pair final : public Score_Variant
{
public:
    
    string name() const override
    {
        return "Pair";
    }
    
    int score( vector<int> const &V ) override
    {
        auto d = V;
        sort(begin(d), end(d), greater<int>());
        auto it = adjacent_find(begin(d), end(d));
        if ( it != end(d) )
            return (*it) * 2;
        
        //test
        for (auto x : d )
            cout << x << ' ';
        
        return 0;
    }
};


class Counted_Dice : public Score_Variant
{
public:
    Counted_Dice(int const &d) : die_{ d } {}
    
    int get_number()
    {
        return die_;
    }
    
    int score(vector<int> V)
    {
        int result{ 0 };
        for (auto x : V )
            if ( x == die_ )
                ++result;
        
        return result * die_;
    }

protected:
    Counted_Dice() = default;
    
private:
    int die_;
};

class Ones final: public Counted_Dice
{
public:
    Ones() : Counted_Dice{1} {}
    string name() const override
    {
        return "Ones";
    }
    
    int score(vector<int> const &V) override
    {
        return Counted_Dice::score(V);
    }
    
};

class Twos final: public Counted_Dice
{
public:
    Twos() : Counted_Dice{2} {}
    
    string name() const override
    {
        return "Twos";
    }
    
    int score(vector<int> const &V) override
    {
        return Counted_Dice::score(V);
    }
};


string create_string(vector<int> V)
{
    bool first{true};
    string s;
    for (auto i : V )
    {
        if (first)
        {
            s += to_string(i);
            first = false;
        }
        else
            s += ", " + to_string(i);
    }
    return s;
}

int main()
{
    
    vector<int> dice_nr1 { 1, 2, 3, 2, 1 };
    vector<int> dice_nr2 { 3, 3, 5, 5, 5 };
    
    vector<Score_Variant*> Score_Vector{ new Ones, new Twos, new Pair };
    
    cout << setfill(' ') << setw(16) << left << "Dice" << setw(6) << "Ones" << setw(6) << "Twos" << setw(6) << "Pair" << endl;
    
    cout << setfill(' ') << setw(16) << left << create_string(dice_nr1);
    for (auto x : Score_Vector )
        cout << setw(6) << x->score(dice_nr1);
    cout << endl;
    
    cout << setfill(' ') << setw(16) << left << create_string(dice_nr2);
    for (auto x : Score_Vector )
        cout << setw(6) << x->score(dice_nr2);
    cout << endl;
    
    
    return 0;
}
