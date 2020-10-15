#include <iostream>
#include "Group.h"

int main() {
    Student a("Pes", 2);
    Student b("Des", 3);
    Student c("Mes", 4);
    Student d("Kes", 5);
    a.print();
    
    Student	e = a;
    e.print();

    Student	f(d);
    f.print();

    Student	zero = move(c);
    zero.print();
    c.print();

    Group group("House", "Raketa");
    group.add_Student(a);
    group.add_Student(b);
    group.add_Student(zero);
    group.add_Student(d);
    group.del_Student(3);
    d.print();
    group.list_Students();
}