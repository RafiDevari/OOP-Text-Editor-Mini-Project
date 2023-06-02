/*

!!CREATED AT 25/05/2023 -> IBRA RIZQY
!!EDITED AT 30/05/2023 -> RAFI DEVARI

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

//class utama pada hitung.hpp diturunkan menjadi class Read
class Read
{
    private:    
        string line;        //Variabel untuk menyimpan setiap baris saat kita menginput yang nantinya akan dimasukkan ke file tertentu menggunakan fstream.
        string filename;    //variabel yang menyimpan nama file
        string extension;   //variabel yang menyimpan nama ekstensi file

        vector<string> lines;
    public:
        void reads();
};

void Read::reads() {   //Fungsi untuk membaca file              
    //menginput nama file untuk di baca
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
    
    system("cls");

    for (int i = 0; i < lines.size(); ++i) {  //menampilkan setiap isi line
        cout << lines[i] << '\n';
    }

    ifstream files(filename);
    if (!files.is_open()) {
        cerr << "Error opening file" << endl;
        exit(0);
    }

    int count = 0; //Penghitung character
    int itter = 0; //Penghitung baris
    string lined;
    while (getline(files, lined)) { //Perulangan untuk mengecek file sampai terakhir
        count += lined.length();
        itter++;
    }
    
    cout << "\033[95m";
    cout << "File ini memiliki karakter sebanyak " << "\033[35m" << count << "\033[95m" << endl;
    cout << "File ini memiliki line sebanyak " << "\033[35m" << itter << "\033[95m" << endl;
    cout << "------------------------------------" << endl;
    
    files.close();
    cout << "\nPress enter to continue...";  //meminta user untuk menginput ENTER
    while (true)
    {
        char c = _getch();
        if (c == '\r')
            break;                          //Akan keluar dari loop saat menginput ENTER
        else
            continue;
    }
    
    file.close();

    ofstream output_file(filename);   //memasukkan isi file yang ingin diubah
    for (const auto& l : lines) {  //Sintaks untuk looping pada C++ modern yang akan merujuk pada elemen yang ada pada lines yaitu vektor dari string bukan menyalin karena iya menggunakan alamatnya
        output_file << l << '\n';  //Auto memungkinkan kompiler untuk menentukan tipe data yang sesuai untuk variabel berdasarkan tipe data elemen dalam kumpulan data.
    }                              //Lalu loop ini akan menulis setiap baris dari vektor ke file yang ditentukan.
}
