#include <iostream>
#include <fstream>
#include <cstdio>   // remove, rename
using namespace std;

int main()
{
    // 1) create grades.txt and write five integer grades
    ofstream out("grades.txt");
    if (!out)
    {
        cout << "Unable to create the file";
        return 1;
    }
    int g;
    cout << "Enter 5 grades: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> g;
        out << g << endl;
    }
    out.close();

    // 2) read and print using a correct loop
    ifstream in("grades.txt");
    if (in.fail())
    {
        cout << "Unable to open the file";
        return 1;
    }
    cout << "\nGrades in file:\n";
    while (in >> g)
        cout << g << endl;
    in.close();

    // 3) ask for a grade to delete, copy the rest to temp file
    int del;
    cout << "\nEnter the grade you want to delete: ";
    cin >> del;

    in.open("grades.txt");
    ofstream temp("temporary.txt");
    bool found = false;
    while (in >> g)
    {
        if (g == del && !found)   // delete first match only
            found = true;
        else
            temp << g << endl;
    }
    in.close();
    temp.close();

    // 4) replace the original file
    if (!found)
    {
        remove("temporary.txt");
        cout << "Error: grade not found, nothing deleted." << endl;
        return 0;
    }
    if (remove("grades.txt") == 0 && rename("temporary.txt", "grades.txt") == 0)
        cout << "Success: grade deleted." << endl;
    else
        cout << "Error: could not update the file." << endl;

    // show the file after deletion
    in.open("grades.txt");
    cout << "\nGrades after deletion:\n";
    while (in >> g)
        cout << g << endl;
    in.close();
    return 0;
}
