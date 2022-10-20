#include <iostream>
#include <fstream>
#include "Keeper.h"
#include "input.hpp"

using namespace std;
void show_menu();

int main() {
    Keeper keeper;
    fstream in;
    bool is_exit(false);
    int act, choise;
    string path = "out.txt";

    show_menu();
    while (!is_exit) {
        cout << "\nEnter action: "; act = input<int>();
        system("cls"); show_menu();
        
        if (act == 1) {
        cout << "Select the type of figure (1 - FlatFigure, 2 - ThreeDimFigure): "; 
        choise = input<int>();
        if (choise == Figures::Flat_Figure) {
            FlatFigures *flatfigure = new FlatFigures;
            cin >> *flatfigure;
            flatfigure->set_square(flatfigure->get_image(), flatfigure->get_sizes());
            keeper.add(flatfigure);
        }else if (choise == Figures::Three_Dim_Figure) {
            ThreeDimFigures *threedimfigure = new ThreeDimFigures;
            cin >> *threedimfigure;
            threedimfigure->set_volume(threedimfigure->get_type_figure(), threedimfigure->get_sizes());
            keeper.add(threedimfigure);
        }
        }
        else if (act == 2) {
        try {
            keeper.print();
        } catch(const exception& e) {
            std::cerr << e.what() << endl;
        }
        }
        else if (act == 3) {
        cout << "Enter the figure number: "; choise = input<int>();
        try {
            keeper.edit(choise);
        } catch(const exception& e) {
            cerr << e.what() << endl;
        }
        }
        else if (act == 4) {
        cout << "Enter the figure number: "; choise = input<int>();
        try {
            keeper.remove(choise);
        } catch(const exception& e) {
            cerr << e.what() << endl;
        }
        }
        else if (act == 5) keeper.load(in, path);
        else if (act == 6) keeper.upload(in, path);
        else if (act == 7) {
        try {
            keeper.free();
        } catch(const exception& e) {
            cerr << e.what() << endl;
        }
        }
        else if (act == 8) {
        try {
            is_exit = true;
            keeper.free();
        } catch(const exception& e) {}
        }
    }
    return 0;
}

void show_menu() {
    cout << "1 - add a new figure\n2 - print a list of figures\n3 - edit the figure\n" <<
    "4 - delete the figure\n5 - load a list of figures from the file\n" <<
    "6 - upload a list figures to the file\n7 - delete all figures\n8 - exit\n\n";
}