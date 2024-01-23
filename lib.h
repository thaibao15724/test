#include <iostream>
#include <cstdlib>
using namespace std;

// Khai bao ham
class students
{
private:
    string *names;
    int count;
    int capacity;

public:
    students();
    ~students();
    void ensureCapacity(int);
    void addStudent(string);
    void removeStudent(string);
    void display();
};

void run(students *);