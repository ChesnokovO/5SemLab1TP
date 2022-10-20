#include <sstream>
#include <math.h>
#include "FlatFigures.h"

string *split(string str, string delimiter, int count) {
    int pos, i = 0;
    string* strings = new string[count];
    while ((pos = str.find(delimiter)) != string::npos) {
        strings[i++] = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
    }
    strings[i] = str;
    return strings;
};

FlatFigures::FlatFigures(){
    cout << "Constructor FlatFigure without parametrs" << endl;
}

FlatFigures::FlatFigures(string type, string size, float Square, string image):
    type(type), size(size), Square(Square), image(image) {
    cout << "Constructor FlatFigure with parametrs, type: " << type << endl;
}

FlatFigures::FlatFigures(const FlatFigures &flatfigure): 
    type(flatfigure.type), size(flatfigure.size), Square(flatfigure.Square), image(flatfigure.image){
    cout << "Copy constructor FlatFigure, type: " << flatfigure.type << endl;
}

FlatFigures::~FlatFigures(){
    cout << "Destructor FlatFigure, type: " << type << endl;
}

void FlatFigures::set_type(string type){
    this->type = type;
}

string FlatFigures::get_Type() {
    return this->type;
}

void FlatFigures::set_square(string image, string size){
    float sq = 0;
    if (image == "circle"){
        float rad = stof(size);
        sq = 3.14 * rad * rad;
    }
        else if (image == "square"){
        float a = stof(size);
        sq = a*a;
    }
    else if(image == "rectangle"){
        string* s1 = split(size, "x", 2);
        float len = stof(s1[0]), wid = stof(s1[1]);
        sq = len * wid;
    }
    else if(image.find("triangle")){
        string* s1 = split(size, "x", 3);
        float a = stof(s1[0]), b = stof(s1[1]), c = stof(s1[2]);
        float p = (a + b + c)/2;
        sq = sqrt(p*(p-a)*(p-b)*(p-c));
    }
    this->Square = sq;
    
}

float FlatFigures::get_square(){
    return this->Square;
}

void FlatFigures::set_image(string image){
    this->image = image;
}

string FlatFigures::get_image(){
    return this->image;
}

void FlatFigures::set_sizes(string size){
    checkCondition(size.length() <= 0, "the length of the string must be greater than 0");
    this->size = size;
}

string FlatFigures::get_sizes(){
    return this->size;
}

Figures::FigureType FlatFigures::get_type(){
    return FigureType::Flat_Figure;
}

string FlatFigures::describe(){
    std::stringstream str;
    str << "FlatFigure, " << type << ", " << size << ", " << Square << ", " << image;
    return str.str();
}

std::istream& operator>> (std::istream &in, FlatFigures &flatfigure){
    cout << "type: ";
    in >> flatfigure.type;
    cout << "image: ";
    in >> flatfigure.image;
    cout << "size: ";
    in >> flatfigure.size;
    return in;
}