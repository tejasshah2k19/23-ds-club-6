#include <iostream>
#include <string.h>

using namespace std;

class Student
{

private:
    char *name;
    int s1, s2;

public:
    void getData()
    {
        char tmp[50];
        cout << "Enter name and marks of two subjects ";
        cin >> tmp >> s1 >> s2;
        int len = strlen(tmp);
        name = new char(len);
        strcpy(name, tmp);
    }

    void display()
    {
        cout << endl
             << name << " " << s1 << " " << s2;
    }
};

int main()
{
    //     Student s;
    //     s.getData();
    //     s.display();
    Student *s = new Student(); // constructor
    s->getData();
    s->display();
    return 0;
}
