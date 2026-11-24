// Task 2: Read the fruits list from "fruit.txt" and add "Fresh Fruits" in the same file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string line, last = "";

    // 1) Read the list contents
    ifstream in("fruit.txt");
    if (!in.is_open())
    {
        cout << "Error opening the file (put fruit.txt in the project folder)";
        return 0;
    }
    cout << "File content before:" << endl;
    while (getline(in, line))
    {
        cout << line << endl;
        if (line != "") last = line;
    }

    // check if the file already ends with a new line (using seekg)
    in.clear();
    in.seekg(-1, ios::end);
    char c = in.get();
    bool endsWithNewLine = (c == '\n');
    in.close();

    // 2) Append "Fresh Fruits" at the end of the same file (only once)
    if (last != "Fresh Fruits")
    {
        ofstream out("fruit.txt", ios::app);
        if (!endsWithNewLine) out << endl;
        out << "Fresh Fruits";
        out.close();
    }

    // 3) Show the final result
    cout << "\nFile content after:" << endl;
    ifstream res("fruit.txt");
    while (getline(res, line))
        cout << line << endl;
    res.close();

    return 0;
}
