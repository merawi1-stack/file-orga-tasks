#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Person
{
    string name;
    int age;
};

int main()
{
    // ---------- Part 1: write persons to the file ----------
    int n;
    cout << "How many persons do you want to add? ";
    cin >> n;
    cin.ignore();               // remove the newline left by cin

    ofstream out("persons.txt");
    if (!out)
    {
        cout << "Unable to create the file";
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        Person p;
        cout << "Person " << i + 1 << " name: ";
        getline(cin, p.name);
        cout << "Person " << i + 1 << " age: ";
        cin >> p.age;
        cin.ignore();
        out << p.name << endl << p.age << endl;
    }
    out.close();

    // ---------- Part 2: load into vector, find youngest / oldest ----------
    ifstream in("persons.txt");
    if (!in)
    {
        cout << "Unable to open the file";
        return 1;
    }
    vector<Person> persons;
    Person p;
    while (getline(in, p.name))
    {
        in >> p.age;
        in.ignore();
        persons.push_back(p);
    }
    in.close();

    if (persons.empty())
    {
        cout << "No data in file.";
        return 0;
    }

    int youngest = 0, oldest = 0;
    for (int i = 1; i < persons.size(); i++)
    {
        if (persons[i].age < persons[youngest].age) youngest = i;
        if (persons[i].age > persons[oldest].age)   oldest = i;
    }

    ofstream res("results.txt");
    res << "Youngest: " << persons[youngest].name << " - " << persons[youngest].age << endl;
    res << "Oldest: "   << persons[oldest].name   << " - " << persons[oldest].age   << endl;
    res.close();

    cout << "Results saved in results.txt" << endl;
    cout << "Youngest: " << persons[youngest].name << " - " << persons[youngest].age << endl;
    cout << "Oldest: "   << persons[oldest].name   << " - " << persons[oldest].age   << endl;
    return 0;
}
