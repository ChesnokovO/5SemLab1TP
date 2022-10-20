#pragma once
#include <iostream>
#include "Figures.h"
using namespace std;

class FlatFigures: public Figures{
private:
    string type;
    string size;
    float Square;
    string image;

public:
    FlatFigures();
    FlatFigures(string type, string size, float Square, string image);
    FlatFigures(const FlatFigures &flatfigure);
    ~FlatFigures();
    
    void set_type(string type);
    string get_Type();
    void set_square(string image, string size);
    float get_square();
    void set_image(string image);
    string get_image();
    void set_sizes(string sizes);
    string get_sizes();

    FigureType get_type() override;
    string describe() override;

    friend std::istream& operator>> (std::istream &in, FlatFigures &flatfigures);
};