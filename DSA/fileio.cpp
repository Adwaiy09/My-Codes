#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Student
{
    int roll;
    char name[30];
    float marks;
};

int main()
{
    vector<Student> vec = {{1, "rahul", 22.5}, {2, "sham", 90}, {3, "ram", 85.5}, {4, "adwaiy", 93.6}, {5, "alan", 11.2}};
    fstream file;
    file.open("students.dat", ios::binary | ios::out);
    for (int i = 0; i < vec.size(); i++)
    {
        file.write(reinterpret_cast<char *>(&vec[i]), sizeof(vec[i]));
    }
    file.close();
    Student s;
    file.open("students.dat", ios::binary | ios::in);
    fstream newFile("newfile.dat", ios::binary | ios::out);
    for (int i = 0; i < vec.size(); i++)
    {
        file.read(reinterpret_cast<char *>(&s), sizeof(s));
        if (s.marks >= 70)
        {
            newFile.write(reinterpret_cast<char *>(&s), sizeof(s));
        }
    }
    file.close();
    newFile.close();
}
