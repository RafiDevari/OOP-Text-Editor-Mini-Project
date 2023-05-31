/*
Nama File : edit.hpp
Deskripsi : File ini berfungsi untuk melihat (read-only) isi dari file yang sudah ada.
            File ini di include di main.cpp.
*/ 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

//class utama pada program.hpp diturunkan menjadi class Read
class Read : public Program
{
    private:
        vector<string> lines;
    public:
        void reads();
};

void Read::reads() {                //menginput nama file untuk di baca
    cout << "Masukkan nama file: ";
    cin >> filename;

    fstream file(filename);         
    if (!file.is_open()) {
        cerr << "Gagal membuka file\n";
        file.close();
        return reads();
    }

    vector<string> lines;           //memasukkan isi line ke vektor lines
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    for (int i = 0; i < lines.size(); ++i) {  //menampilkan setiap isi line
        cout << lines[i] << '\n';
    }

    cout << "\nPress enter to continue...";  //meminta user untuk menginput ENTER
    while (true)
    {
        char c = _getch();
        if (c == '\r')
            break;
        else
            continue;
    }
    
    file.close();

    ofstream output_file(filename);   //memasukkan isi file yang ingin diubah
    for (const auto& l : lines) {
        output_file << l << '\n';
    }
}