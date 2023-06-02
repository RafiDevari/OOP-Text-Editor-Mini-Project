/*

!!CREATED AT 26/05/2023 -> IBRA RIZQY
!!EDITED AT 30/03/2023 -> RAFI DEVARI , M THORIQ

Nama File : edit.hpp
Deskripsi : File ini berfungsi untuk mengubah isi dari file yang sudah ada.
            File ini di include di main.cpp.
*/ 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//class utama pada program.hpp diturunkan menjadi class Edit
class Edit
{
    private:
        string line;        //Variabel untuk menyimpan setiap baris saat kita menginput yang nantinya akan dimasukkan ke file tertentu menggunakan fstream.
        string filename;    //variabel yang menyimpan nama file
        string extension;   //variabel yang menyimpan nama ekstensi file

        vector<string> lines;
    public:
        void edit(); //Fungsi untuk mengedit file
};

void Edit::edit() {

    cout << "Masukkan nama file: ";
    cin >> filename;;

    fstream file(filename);
    if (!file.is_open()) {
        cerr << "Gagal membuka file\n";
        return edit();
    }

    system("cls");
    cout << "Ketik 0 untuk keluar dari edit.\n\n";

    bool ubah = true;
    while (ubah)
    {   
        while (getline(file, line)) {       //memasukkan isi line ke vektor lines
            lines.push_back(line);
        }

        for (int i = 0; i < lines.size(); ++i) {        //menampilkan tiap line dan nomor barisnya
            cout << i + 1 << "| " << lines[i] << '\n';
        }
        int line_number;                                    
        cout << "Masukkan nomor baris yang ingin diubah: ";
        cin >> line_number;
        if (line_number == 0) //Exit condition
        {
            ubah = false;
            break;
        }
        if (line_number >= 1 && line_number <= lines.size()) {  //mengubah isi line yang ingin diganti
            cout << "Masukkan teks baru: ";
            cin.ignore();
            getline(cin, line);
            lines[line_number - 1] = line;
        } else
            cout << "Nomor baris tidak valid\n";
        cout << endl;
    }

    file.close();

    ofstream output_file(filename);       //memasukkan isi file yang ingin diubah
    for (const auto& l : lines) {         //Sintaks untuk looping pada C++ modern yang akan merujuk pada elemen yang ada pada lines yaitu vektor dari string bukan menyalin karena iya menggunakan alamatnya
        output_file << l << '\n';         //Auto memungkinkan kompiler untuk menentukan tipe data yang sesuai untuk variabel berdasarkan tipe data elemen dalam kumpulan data.
    }                                     //Lalu loop ini akan menulis setiap baris dari vektor ke file yang ditentukan.
}
