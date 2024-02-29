#include <iostream>
#include <cstdlib>
using namespace std;

// Khai bao ham
class students
{
private:
    string *names;
    float *scores;
    int count;
    int capacity;

public:
    students();
    ~students();
    void ensureCapacity(int);
    void addStudent(string, float);
    void removeStudent(string);
    void display();
    void bestStudent();
};

void run(students *);