#pragma once
#include <iostream>
#include "Student.h"
using namespace std;

class Group {
	char* faculty = nullptr;
	char* course = nullptr;
	int st_amount = 0;
	Student* group = nullptr;
public:
	Group();
	Group(const char* newF, const char* newC);
	Group(const Group& obj);
	Group(Group&& obj) noexcept;
	void f_set(const char* newF);
	void c_set(const char* newC);
	const char* f_get() const;
	const char* c_get() const;
	int am_get() const;
	void add_Student(const Student& student);
	void del_Student(int index);
	void list_Students();
	~Group();
};