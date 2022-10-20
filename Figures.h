#pragma once
#include <iostream>

class Figures{
public:
    enum FigureType {
        Flat_Figure = 1,
        Three_Dim_Figure
        };

    Figures();
    ~Figures();
    virtual FigureType get_type() = 0;
    virtual std::string describe() = 0;
    void checkCondition(bool condition, std::string message);
};