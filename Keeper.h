#include <fstream>
#include <sstream>
#include <string>
#include "Figures.h"
#include "FlatFigures.h"
#include "ThreeDimFigures.h"

using namespace std;

struct Node{
    Figures *figures;
    Node *next;
};

class Keeper{
private:
    Node *head = NULL;
    Node *tail = NULL;
    int count;
    string *split(string str, string delimiter, int count);
    int get_count_arguments(string str);

public:
    Keeper();
    ~Keeper();

    void add(Figures *new_figure);
    void print();
    void remove(int num);
    void upload(std::fstream &in, string path);
    void load(std::fstream &in, string path);
    void free();
    void edit(int num);
    Figures *get(int num);
};