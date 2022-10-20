#include "sstream"
#include "ThreeDimFigures.h"

string *split1(string str, string delimiter, int count) {
    int pos, i = 0;
    string* strings = new string[count];
    while ((pos = str.find(delimiter)) != string::npos) {
        strings[i++] = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
    }
    strings[i] = str;
    return strings;
};

ThreeDimFigures::ThreeDimFigures(){
    cout << "Constructor ThreeDimFigure without parametrs" << endl;
}

ThreeDimFigures::ThreeDimFigures(string type, string sizes, float volume, string projection):
    type(type), sizes(sizes), volume(volume), projection(projection){
    cout << "Constructor ThreeDimFigure with parametrs, type: " << type << endl;
}

ThreeDimFigures::ThreeDimFigures(const ThreeDimFigures &threedimfigures):
    type(threedimfigures.type), sizes(threedimfigures.sizes), volume(threedimfigures.volume), projection(threedimfigures.projection){
    cout << "Copy constructor ThreeDimFigure, type: " << threedimfigures.type << endl;
}

ThreeDimFigures::~ThreeDimFigures(){
    cout << "Destructor ThreeDimFigure, type: " << type << endl;
}

void ThreeDimFigures::set_type_figure(string type){
    checkCondition(type.length() <= 0, "the length of the string must be greater than 0");
    this->type = type;
}

string ThreeDimFigures::get_type_figure(){
    return this->type;
}

void ThreeDimFigures::set_volume(string type, string sizes){
    float v;
    if (type == "sphere"){
        float rad = stof(sizes);
        v = 4*3.14*rad*rad;
    }else if (type == "parallelepiped"){
        string* s = split1(sizes, "x", 3);
        float a = stof(s[0]), b = stof(s[1]), c = stof(s[2]);
        v = a*b*c;
    }
    this->volume = v;
}

float ThreeDimFigures::get_volume(){
    return this->volume;
}

void ThreeDimFigures::set_projection(string projection){
    this->projection = projection;
}

string ThreeDimFigures::get_projection(){
    return this->projection;
}

void ThreeDimFigures::set_sizes(string sizes){
    //checkCondition(sizes.length() <= 0,  "sizes must be greater than 0");
    this->sizes = sizes;
}

string ThreeDimFigures::get_sizes(){
    return this->sizes;
}

Figures::FigureType ThreeDimFigures::get_type(){
    return FigureType::Three_Dim_Figure;
}

string ThreeDimFigures::describe(){
    std::stringstream str;
    str << "ThreeDimFigure, " << type << ", " << sizes << ", " << volume << ", " << projection;
    return str.str();
}

std::istream& operator>> (std::istream &in, ThreeDimFigures &threedimfigure){
    cout << "type: ";
    in >> threedimfigure.type;
    cout << "sizes: ";
    in >> threedimfigure.sizes;
    cout << "projection: ";
    in >> threedimfigure.projection;
    return in;
}