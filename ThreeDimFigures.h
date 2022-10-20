#pragma once
#include "Figures.h"
using namespace std;

class ThreeDimFigures: public Figures{
private:
    string type;
    string sizes;
    float volume;
    string projection;

public:
    ThreeDimFigures();
    ThreeDimFigures(string type, string sizes, float volume, string projection);
    ThreeDimFigures(const ThreeDimFigures &threedimfigures);
    ~ThreeDimFigures();

    void set_type_figure(string type);
    string get_type_figure();
    void set_volume(string type, string sizes);
    float get_volume();
    void set_projection(string projection);
    string get_projection();
    void set_sizes(string sizes);
    string get_sizes();

    FigureType get_type() override;
    string describe() override;

    friend std::istream& operator>> (std::istream &in, ThreeDimFigures &threedimfigures);
};