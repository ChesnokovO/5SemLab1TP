#include "Keeper.h"

Keeper::Keeper(){
    std::cout << "Constructor Keeper without parametrs" << endl;
    count = 0;
}

Keeper::~Keeper(){
    cout << "Destructor Keeper" << endl;
    delete head;
    delete tail;
}

void Keeper::add(Figures *new_figure){
    Node *tmp = new Node;
    tmp->figures = new_figure;
    tmp->next = NULL;

    if (head == NULL){
        head = tmp;
        tail = tmp;
        tmp = NULL;
    }
    else{
        tail->next = tmp;
        tail = tmp;
    }
    count++;
    cout << count << endl;
}

void Keeper::print(){
    if(!count) throw std::runtime_error("The list is empty");
    Node *tmp = new Node;
    tmp = head;
    int counter = 1;
    while(tmp != NULL){
        cout << counter++ << ". " << tmp->figures->describe() << endl;
        tmp = tmp->next;
    }
}

void Keeper::remove(int num){
    if (!count) throw std::runtime_error("The list of is empty");
    if (num > count || num < 1)
        throw std::runtime_error("The number should be in the range from 1 to " + std::to_string(count));

    Node *current = new Node;
    Node *previous = new Node;
    current = head;
    if (num == 1)
        head = head->next;

    for (int i = 1; i < num; i++){
        previous = current;
        current = current->next;
    }  
    if (num == count){
        tail = previous;
        previous->next = NULL;
        tail->next = NULL;
    }
    else
        previous->next = current->next;
    count--;
    delete current->figures;
}

void Keeper::upload(std::fstream &in, string path){
    in.open(path, std::ios::out);
    if (in.is_open()){
        Node *tmp = new Node;
        tmp = head;
        while (tmp != NULL){
            in << tmp->figures->describe() << endl;
            tmp = tmp->next;
        }
    }
    else
        cout << "failed to opet the file";
    in.close();
}

string *Keeper::split(string str, string delimiter, int count){
    int pos, i = 0;
    string *strings = new string[count];

    while ((pos = str.find(delimiter)) != string::npos){
        strings[i++] = str.substr(0, pos);
        str.erase(0, pos  + delimiter.length());
    }
    strings[i] = str;
    return strings;
}

int Keeper::get_count_arguments(string str){
    int str_len = str.length();
    int count = 0;
    if(str_len == 0)
        return 0;
    for (size_t i = 0; i < str_len - 1; i++)
        if (str[i] == ',' && str[i+1] == ' ')
            count++;
    return count + 1;
}

void Keeper::edit(int num) {
    string size, type, image, projection;
    Figures::FigureType typeFig;

    typeFig = this->get(num)->get_type();
  
    if (typeFig == Figures::Flat_Figure) {
        FlatFigures *flatfigure =(FlatFigures*)this->get(num);
        cout << "Select what to change:" << endl;
        cout << "1 - type, 2 - size, 3 - image" << endl;
        cin >> num;
        
        if (num == 1){
            cout << "Enter a new type: ";cin >> type; cout << endl;
            cout << "As the shape type has changed, its sizes, image and square are also changing" << endl;
            cout << "New sizes: "; cin >> size;  cout << endl;
            cout << "New image: "; cin >> image; cout << endl;
            flatfigure->set_type(type); flatfigure->set_sizes(size);
            flatfigure->set_image(image); flatfigure->set_square(image, size);
        } else if (num == 2){
            cout << "Enter a new size: "; cin >> size; cout << endl;
            cout << "As the size changes, changes the square of figure" << endl;
            flatfigure->set_sizes(size); flatfigure->set_square(flatfigure->get_image(), size);
        } else if(num == 3){
            cout << "Enter a new image: "; cin >> image; cout << endl;
            cout << "As the image changes, the sizes change with the square" << endl;
            cout << "New sizes: "; cin >> size; cout << endl;
            flatfigure->set_image(image);
            flatfigure->set_sizes(size);
            flatfigure->set_square(image, size);
        }
    }
    else if (typeFig == Figures::Three_Dim_Figure) {
        ThreeDimFigures *threedimfigure = (ThreeDimFigures*)this->get(num);
        cout << "Select what to change:" << endl;
        cout << "1 - type, 2  - sizes, 3 - projection" << endl;
        cin >> num;

        if (num == 1){
            cout << "\nEnter a new type: "; cin >> type; cout << endl;
            cout << "With the change of the shape type, all other parameters also change" << endl;
            cout << "Enter a new sizes: "; cin >> size; cout << endl;
            cout << "Enter a new projection: "; cin >> projection; cout << endl;
            threedimfigure->set_projection(projection); threedimfigure->set_sizes(size);
            threedimfigure->set_type_figure(type); threedimfigure->set_volume(type, size);
        }else if (num == 2){
            cout << "Enter a new size: "; cin >> size; cout << endl;
            cout << "With the change in size, the volume also changes" << endl;
            threedimfigure->set_sizes(size); threedimfigure->set_volume(type, size);
        }else if (num == 3){
            cout <<"Enter a new projection: "; cin >> projection; cout << endl;
            threedimfigure->set_projection(projection);
        }
    }
}

Figures *Keeper::get(int num) {
  if (!count) throw std::runtime_error("the list of figures is empty");
  if (num > count || num < 1) {
    throw std::runtime_error("The number should be in the range from 1 to " + std::to_string(count));
  }
  Node *cur = new Node;
  Node *prev = new Node;
  cur = head;
  if (num == 1) return head->figures;

  for(int i = 1; i < num; i++) {
    prev = cur;
    cur = cur->next;
  }
  return cur->figures;
}

void Keeper::load(std::fstream &in, string path) {
    string line;
    int counter = 0;
    in.open(path, std::ios::in);

    while (getline(in, line)) {
        string *s = split(line, ", ", get_count_arguments(line));
        if (s[0] == "FlatFigure") {
            FlatFigures *flatfigure = new FlatFigures(s[1], s[2], stof(s[3]), s[4]);
            add(flatfigure);
        } else if (s[0] == "ThreeDimFigure") {
            ThreeDimFigures *threedimfigure = new ThreeDimFigures(s[1], s[2], stof(s[3]), s[4]);
            add(threedimfigure);
        }
        ++counter;
    }
    in.close();
}

void Keeper::free() {
    if (!count) throw std::runtime_error("the list of figures is empty");

    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        delete curr->figures;
        delete curr;
        curr = next;
    }
    head = NULL;
    tail = NULL;
    count = 0;
}