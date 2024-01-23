#include "lib.h"

int main()
{
    students *studentsList = new students;
    run(studentsList);
    delete studentsList;
    return 0;
}