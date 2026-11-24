// Task 3: Write "Hello Everybody" in "welcome.txt", replace "body" with "one"
//         so the final content is "Hello Everyone"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // 1) Write the original sentence
    fstream file("welcome.txt", ios::out | ios::trunc);
    file << "Hello Everybody";
    file.close();

    // 2) Open for read+write WITHOUT deleting the content, then overwrite "body"
    file.open("welcome.txt", ios::in | ios::out);
    file.seekp(-4, ios::end);      // go back 4 chars from the end (start of "body")
    file << "one";                 // file now: "Hello Everyoney" (one extra char left)
    file.close();

    // 3) Remove the leftover 'y': read the first 14 chars and rewrite the file
    string text;
    ifstream in("welcome.txt");
    getline(in, text);
    in.close();
    text = text.substr(0, 14);     // "Hello Everyone"

    ofstream out("welcome.txt", ios::out | ios::trunc);
    out << text;
    out.close();

    cout << "Final result in welcome.txt: " << text << endl;
    return 0;
}
