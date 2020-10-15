#include "Group.h"

Group::Group() = default;

Group::Group(const char *newF, const char* newC) {
	faculty = _strdup(newF);
	course = _strdup(newC);
}

Group::Group(const Group &st) {
	cout << "Copy Constructor" << endl;
	faculty = _strdup(st.faculty);
	course = _strdup(st.course);
	st_amount = st.st_amount;
	group = new Student[st_amount];
	for (int i = 0; i < st_amount; ++i) {
		group[i].n_set(st.group[i].n_get());
		group[i].d_set(st.group[i].d_get());
	}
}

Group::Group(Group&& st) noexcept {
	cout << "Move Constructor" << endl;
	faculty = st.faculty;
	course = st.course;
	st_amount = st.st_amount;
	st.faculty = nullptr;
	st.course = nullptr;
	st.st_amount = 0;
}

void Group::f_set(const char* newF) {
	delete[] faculty;
	faculty = _strdup(newF);
}

void Group::c_set(const char* newC) {
	delete[] course;
	course = _strdup(newC);
}

const char* Group::f_get() const {
	return faculty;
}

const char* Group::c_get() const{
	return course;
}

int Group::am_get() const{
	return st_amount;
}

void Group::add_Student(const Student& student) {
	if (st_amount == 0) group = new Student[1];
	else {
		Student* tmp = new Student[st_amount + 1];
		for (int i = 0; i < st_amount; ++i) {
			tmp[i].d_set(group[i].d_get());
			tmp[i].n_set(group[i].n_get());
		}
		delete[]group;
		group = tmp;
	}
	group[st_amount].n_set(student.n_get());
	group[st_amount].d_set(student.d_get());
	st_amount++;
}

void Group::del_Student(int deleted) {
	Student* tempObj = new Student[st_amount - 1]; // shorten the array
	for (int i = 0; i < st_amount - 1; i++) {
		if (i >= deleted) {
			tempObj[i].d_set(group[i + 1].d_get());
			tempObj[i].n_set(group[i + 1].n_get());
		}
		else {
			tempObj[i].d_set(group[i].d_get());
			tempObj[i].n_set(group[i].n_get());
		}
	}
	delete[] group; // deallocate memory
	group = tempObj;
}

void Group::list_Students() {
	cout << f_get() << endl;
	cout << c_get() << endl;
	cout << am_get() << endl;
	for (int i = 0; i < st_amount - 1; i++) {
		cout << group[i].d_get() << endl;
		cout << group[i].n_get() << endl;
	}
}

Group::~Group() {
	if (faculty != nullptr) delete[] faculty;
	if (course != nullptr) delete[] course;
	if (st_amount) delete[] group;
	cout << "Destructor" << endl;
}