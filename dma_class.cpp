#include <iostream>

using namespace std;

class Student
{

private:
    char name[30];
    int s1, s2;

public:
    void getData()
    {
        cout << "Enter name and marks of two subjects ";
        cin >> name >> s1 >> s2;
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
