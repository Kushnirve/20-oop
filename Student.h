#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Student {
	char* name;
	int b_date;
public:
    Student();
    Student(const char* _name, int _b_date);
    Student(const Student& obj);
    Student(Student&& obj)noexcept;
    void n_set(const char* _name);
    void d_set(int _b_date);
    const char* n_get()const;
    int d_get()const;
    void print()const;
    ~Student();
};