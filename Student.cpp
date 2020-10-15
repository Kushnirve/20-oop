#include "Student.h"

Student::Student() {
    name = nullptr;
    b_date = 0;
}

Student::Student(const char* _name, int _b_date) {
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
    b_date = _b_date > 0 ? _b_date : 0;
}

Student::Student(const Student& obj) :Student() {
    cout << "Copy constructor" << endl;
    if (obj.name) this->name = _strdup(obj.name);
    this->b_date = obj.b_date;
}

Student::Student(Student&& obj) noexcept {
    cout << "Move constructor" << endl;
    name = obj.name;
    b_date = obj.b_date;
    obj.name = nullptr;
    obj.b_date = 0;
}

void Student::n_set(const char* _name) {
    delete[] name;
    if (_name) name = _strdup(_name);
    else name = nullptr;
}

void Student::d_set(int _b_date) {
    if (_b_date >= 0) b_date = _b_date;
}

const char* Student::n_get() const {
    return name;
}

int Student::d_get() const {
    return b_date;
}

void Student::print() const {
    cout << "Student" << endl;
    cout << "Name: " << (name ? name : "Noname") << endl;
    cout << "b_date: " << b_date << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

Student::~Student() {
    delete[] name;
}