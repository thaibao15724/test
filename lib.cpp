#include "lib.h"

// Dinh nghia ham

students::students()
{
    this->count = 0;
    this->capacity = 10;
    this->studentList = new student[capacity];
}

students::~students()
{
    delete[] studentList;
}

void students::ensureCapacity(int n)
{
    if (n <= capacity)
        return;
    capacity = capacity * 3 / 2;
    student *new_studentList = new student[capacity];
    for (int i = 0; i < count; ++i)
    {
        new_studentList[i] = studentList[i];
    }
    delete[] studentList;
    this->studentList = new_studentList;
}

void students::addStudent(string name, float score)
{
    ensureCapacity(this->count + 1);
    student tmp(name, score);
    this->studentList[this->count++] = tmp;
}

void students::display()
{
    for (int i = 0; i < this->count; ++i)
    {
        cout << this->studentList[i].name << " " << this->studentList[i].score << '\n';
    }
}

void students::removeStudent(string name)
{
    bool ok = true;
    for (int i = 0; i < this->count; ++i)
    {
        if (name == studentList[i].name)
        {
            this->count--;
            for (int j = i; j < this->count; ++j)
            {
                studentList[j].name = studentList[j + 1].name;
            }
            ok = false;
            break;
        }
    }
    if (ok)
        cout << "Student name does not exist\n";
}

void students::bestStudent()
{
    float max = studentList[0].score;
    for (int i = 1; i < count; ++i)
    {
        if (studentList[i].score > max)
            max = studentList[i].score;
    }
    for (int i = 0; i < count; ++i)
    {
        if (studentList[i].score == max)
            cout << studentList[i].name << " " << studentList[i].score << '\n';
    }
}

void run(students *stu)
{
    while (true)
    {
        string s;
        cout << "1. Add a new student\n";
        cout << "2. Display the list of all students and their scores\n";
        cout << "3. Display the best student(s)'s\n";
        cout << "4. Remove a student\n";
        cout << "0. Exit the program\n";
        cout << "Choose the above functionalities: ";
        cin >> s;
        system("cls");
        if (s == "1")
        {
            string name;
            float score;
            cout << "Student name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Score: ";
            cin >> score;
            while (score < 0 || score > 10)
            {
                cout << "Invalid score. Please enter again: ";
                cin >> score;
            }
            stu->addStudent(name, score);
        }
        else if (s == "2")
            stu->display();
        else if (s == "3")
            stu->bestStudent();
        else if (s == "4")
        {
            string name;
            cout << "Student name: ";
            cin.ignore();
            getline(cin, name);
            stu->removeStudent(name);
        }
        else
            break;
    }
}