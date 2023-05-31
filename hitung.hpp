#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

class Hitung
{
    public :
        int hitungChar(string);
};

int Hitung::hitungChar(string filename) {

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    int count = 0;
    string line;
    while (getline(file, line)) {
        count += line.length();
    }

    
    file.close();

    return count;
}