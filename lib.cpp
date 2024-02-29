#include "lib.h"

// Dinh nghia ham

students::students()
{
    this->count = 0;
    this->capacity = 10;
    this->names = new string[capacity];
    this->scores = new float[capacity];
}

students::~students()
{
    delete[] names;
    delete[] scores;
}

void students::ensureCapacity(int n)
{
    if (n <= capacity)
        return;
    capacity = capacity * 3 / 2;
    string *new_names = new string[capacity];
    float *new_scores = new float[capacity];
    for (int i = 0; i < count; ++i)
    {
        new_names[i] = names[i];
        new_scores[i] = scores[i];
    }
    delete[] names;
    delete[] scores;
    this->names = new_names;
    this->scores = new_scores;
}

void students::addStudent(string name, float score)
{
    ensureCapacity(this->count + 1);
    this->names[this->count++] = name;
    this->scores[this->count - 1] = score;
}

void students::display()
{
    for (int i = 0; i < this->count; ++i)
    {
        cout << this->names[i] << " " << this->scores[i] << '\n';
    }
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

void students::bestStudent()
{
    float max = scores[0];
    for (int i = 1; i < count; ++i)
    {
        if (scores[i] > max)
            max = scores[i];
    }
    for (int i = 0; i < count; ++i)
    {
        if (scores[i] == max)
            cout << names[i] << " " << scores[i] << '\n';
    }
}

void run(students *stu)
{
    while (true)
    {
        string s;
        cout << "1. Add a new student\n";
        cout << "2. Display the list of all students and their scores\n";
        // cout << "3. Remove a student\n";
        cout << "3. Display the best student(s)'s\n";
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
        // else if (s == "3")
        // {
        //     string name;
        //     cout << "Student name: ";
        //     cin.ignore();
        //     getline(cin, name);
        //     stu->removeStudent(name);
        // }
        else if (s == "3")
            stu->bestStudent();
        else
            break;
    }
}