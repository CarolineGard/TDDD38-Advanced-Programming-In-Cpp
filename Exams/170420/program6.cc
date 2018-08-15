#include <sstream>
#include <iterator>
#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <memory>
using namespace std;

// Given, should not be changed
struct Image_Data
{
    Image_Data(string const & line)
    {
        istringstream iss{line};
        iss >> type;
        for ( int d; iss >> d; )
        {
            args.push_back(d);
        }
    }
    string type;
    vector<int> args;
};

// Add your classes here
class Image
{
public:
    virtual ~Image() = default;
    virtual int size() = 0;
    
protected:
    Image(int w, int h) : width_{ h }, height_{ h } {}
    int width_;
    int height_;
};

class PNG : public Image
{
public:
    int size() override
    {
        return width_ * height_ * 1.5;
    }
    
    static PNG *parse(Image_Data const &d)
    {
        if (d.type != "PNG")
            return nullptr;
        
        return new PNG{ d.args[0], d.args[1] };
    }
    
    const int get_height_() { return height_; }
    const int get_width_()  { return width_; }
    
private:
    PNG(int w, int h) : Image{ w, h } {}
};


class BMP : public Image
{
public:
    int size() override
    {
        return width_ * height_ * 3;
    }
    
    static BMP *parse(Image_Data const &d)
    {
        if (d.type != "BMP")
            return nullptr;
        
        return new BMP{ d.args[0], d.args[1] };
    }
    
private:
    BMP(int w, int h) : Image{ w, h } {}
};

class JPG : public Image
{
public:
    
    int size() override
    {
        return width_ * height_ * 3 * ( quality_ / 100.0 );
    }
    
    static JPG *parse(Image_Data const &d)
    {
        if (d.type != "JPG")
            return nullptr;
        
        return new JPG{ d.args[0], d.args[1], d.args[2] };
    }
    
private:
    JPG(int w, int h, int q) : Image{ w, h }, quality_{ q } {}
    int quality_;
};

/*
 * Given code. No modifications allowed unless specified!
 */
Image* error_printer(Image_Data const & d)
{
    cout << "!!! " << d.type << " is an invalid file format !!!\n";
    return nullptr;
}
int main()
{
    vector<unique_ptr<Image>> images;
    vector<function<Image*(Image_Data const &)>> funs { PNG::parse,
                                                        JPG::parse,
                                                        BMP::parse,
                                                        error_printer};
    cout << "Enter one line for each image on the format \"type [type specific data]\". Exit with \"q\".\n\n";

    for ( string line; getline(cin, line); )
    {
        if ( line == "q" )
        {
            break;
        }
        Image_Data data{line};
        for ( auto && f: funs )
        {
            if (auto ptr = f(data))
            {
                images.emplace_back(ptr);
                break;
            }
        }
    }

    // Additions allowed below (calculate and print sum)

    int total_size = 0;
    for ( auto && x : images)
    {
        total_size += x->size();
    }
    cout << "Total size: " << total_size << " Bytes \n\n";

}
