// Task 1: Read student data (Full name, ID, Grade) and save it in "Student.txt"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string name;
    int id;
    float grade;

    // getline first (full name has spaces), then cin >> for the numbers
    cout << "Enter Full Name: ";
    getline(cin, name);

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Grade: ";
    cin >> grade;

    ofstream myfile("Student.txt");
    if (!myfile.is_open())
    {
        cout << "Error, file is not opened";
    }
    else
    {
        myfile << "Full Name: " << name << endl;
        myfile << "ID: " << id << endl;
        myfile << "Grade: " << grade << endl;
        cout << "\nData saved successfully in Student.txt" << endl;
    }
    myfile.close();

    return 0;
}
