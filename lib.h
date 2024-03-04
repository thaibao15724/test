#include <iostream>
#include <cstdlib>
using namespace std;

// Khai bao ham
class students
{
private:
    class student;

private:
    student *studentList;
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

private:
    class student
    {
    private:
        string name;
        float score;
        friend class students;

    public:
        student() {}
        student(string name, float score)
        {
            this->name = name;
            this->score = score;
        }
    };
};

void run(students *);