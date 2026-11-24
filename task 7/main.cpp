#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // 1) create the file with the student names (one name per line)
    ofstream out("names.txt");
    if (!out)
    {
        cout << "Unable to create the file";
        return 1;
    }
    out << "Hadeer Mahmoud" << endl;
    out << "Youssef Ali" << endl;
    out << "Ahmed Mostafa" << endl;
    out << "Esraa Ebrahim" << endl;
    out.close();

    // 2) read the names (getline because names contain spaces)
    ifstream input("names.txt");
    if (!input)
    {
        cout << "Unable to open the file";
        return 1;
    }
    vector<string> data;
    string line;
    while (getline(input, line))
        data.push_back(line);
    input.close();

    // 3) sort ascending
    sort(data.begin(), data.end());

    // 4) print + save sorted names
    ofstream sorted("sorted_names.txt");
    cout << "Names sorted Successfully" << endl;
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << endl;
        sorted << data[i] << endl;
    }
    sorted.close();
    return 0;
}
