#include "lib.h"

// Dinh nghia ham

students::students()
{
    this->count = 0;
    this->capacity = 10;
    this->names = new string[capacity];
}

students::~students()
{
    delete[] names;
}

void students::ensureCapacity(int n)
{
    if (n <= capacity)
        return;
    capacity = capacity * 3 / 2;
    string *new_names = new string[capacity];
    for (int i = 0; i < count; ++i)
    {
        new_names[i] = names[i];
    }
    delete[] names;
    this->names = new_names;
}

void students::addStudent(string name)
{
    ensureCapacity(this->count + 1);
    this->names[this->count++] = name;
}

void students::display()
{
    for (int i = 0; i < this->count; ++i)
    {
        cout << this->names[i] << " ";
    }
    cout << '\n';
}

void students::removeStudent(string name)
{
    bool ok = true;
    for (int i = 0; i < this->count; ++i)
    {
        if (name == names[i])
        {
            this->count--;
            for (int j = i; j < this->count; ++j)
            {
                names[j] = names[j + 1];
            }
            ok = false;
            break;
        }
    }
    if (ok)
        cout << "Student name does not exist\n";
}

void run(students *stu)
{
    while (true)
    {
        string s;
        cout << "1. Add a new student\n";
        cout << "2. Display the list of all students\n";
        cout << "3. Remove a student\n";
        cout << "0. Exit the program\n";
        cout << "Choose the above functionalities: ";
        cin >> s;
        system("cls");
        if (s == "1")
        {
            string name;
            cout << "Student name: ";
            cin.ignore();
            getline(cin, name);
            stu->addStudent(name);
        }
        else if (s == "2")
            stu->display();
        else if (s == "3")
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