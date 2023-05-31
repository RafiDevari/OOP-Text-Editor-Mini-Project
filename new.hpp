/*

!!CREATED AT 17/05/2023 -> M THORIQ
!!EDITED AT 25/05/2023 -> IBRA RIZQY
!!EDITED AT 29/05/2023 -> RAFI DEVARI
!!EDITED AT 31

Nama File : new.hpp
Deskripsi : File ini berfungsi untuk membuat file baru yang akan disimpan pada folder yang sama.
            File ini di include di main.cpp.
*/ 
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>
#include <conio.h>
#include <windows.h>
using namespace std;

class New
{
    private:
        string line;        //Variabel untuk menyimpan setiap baris saat kita menginput yang nantinya akan dimasukkan ke file tertentu menggunakan fstream.
        string filename;    //variabel yang menyimpan nama file
        string extension;   //variabel yang menyimpan nama ekstensi file

        vector<string> lines;   //Vektor berjenis data string dengan nama lines
    public:
        void create();   //fungsi untuk membuat file baru
};

void moveCursorUp() { //Fungsi untuk memindahkan kursor ke baris atasnya menggunakan API windows dari header file <windows.h>
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    COORD newPos = info.dwCursorPosition;
    newPos.Y -= 1; //Koordinat Y dikurang 1 artinya dia menaikkan 1 baris ke atas //Koordinaat 0,0 berada pada sudut kiri atas layar.
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), newPos);
}

void New::create() {
    system("cls");

    while (true) {
        char c = _getch();
        if (c == 27) { // escape key
            break;
        } else if (c == '\r') { // enter key
            lines.push_back(line);
            line.clear();
        cout << '\n';
        } else if (c == 8) { // backspace key
            if (!line.empty()) {
                line.pop_back();
            cout << '\b' << ' ' << '\b';
            } else if (!lines.empty()) {
                moveCursorUp(); //Mengembalikan kursor saat lines belum empty
                line = lines.back();
                lines.pop_back();
            cout << '\r';
                for (int i = 0; i < line.size(); ++i) {
                cout << ' ';
                }
            cout << '\r' << line;
            }
        } else {
            line += c;
        cout << c;
        }
    }

    system("cls");

    cout << "Enter the name of the file you want to edit: ";
    cin >> filename;

    string extension;
    cout << "Enter the file extension: ";
    cin >> extension;

    filename += "." + extension; //Menggabungkan string dengan string dan memisahkannya dengan (.) sebagai acuan file extensionnya
    ofstream file(filename);

    for (const auto& l : lines) {  //Sintaks untuk looping pada C++ modern yang akan merujuk pada elemen yang ada pada lines yaitu vektor dari string bukan menyalin karena iya menggunakan alamatnya
        file << l << '\n';         //Auto memungkinkan kompiler untuk menentukan tipe data yang sesuai untuk variabel berdasarkan tipe data elemen dalam kumpulan data.
    }                              //Lalu loop ini akan menulis setiap baris dari vektor ke file yang ditentukan.
    file.close();
    ifstream files(filename);
    if (!files.is_open()) {
        cerr << "Error opening file" << endl;
        exit(0);
    }

    int count = 0;
    int itter = 0;
    string lined;
    while (getline(files, lined)) {
        count += lined.length();
        itter++;
    }
    system("cls");
    cout << "File ini memiliki karakter sebanyak " << "\033[35m" << count << "\033[0m" << endl;
    cout << "File ini memiliki line sebanyak " << "\033[35m" << itter << "\033[0m" << endl;
    cout << "Press enter to continue... " << endl;
    while (true)    
                {
                    int c = _getch();   
                    if (c == '\r')  //tombol enter untuk melanjutkan program agar input diminta kembali
                        break;
                    else
                        continue;
                }
}

