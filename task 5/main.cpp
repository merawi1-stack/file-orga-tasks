#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // ios::app -> every record is added at the end of students.txt
    ofstream file("students.txt", ios::app);
    if (!file)
    {
        cout << "Unable to open the file";
        return 1;
    }

    char name[20];
    int id;
    float grade;
    char more = 'y';

    while (more == 'y' || more == 'Y')
    {
        cout << "Name: ";
        cin.getline(name, 20);
        cout << "ID: ";
        cin >> id;
        cout << "Grade: ";
        cin >> grade;

        // record format:  Name, ID, Grade $
        file << name << ", " << id << ", " << grade << " $" << endl;

        cout << "Add more records? (y/n): ";
        cin >> more;
        cin.ignore(1000, '\n');   // clear the newline before next getline
    }
    file.close();
    cout << "Records saved in students.txt" << endl;
    return 0;
}
