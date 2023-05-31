/*

!!CREATED AT 25/05/2023 -> RAFI DEVARI
!!EDITED AT 25/05/2023 -> AZURA SEVINA

Nama File : color.hpp
Deskripsi : File ini berisi fungsi untuk mengubah warna tampilan teks editor pada terminal.
            File ini di include di textinteface.hpp.
*/ 
#include <iostream>
using namespace std;

//class Color yang berisi fungsi ubah tema dan fungsi diturunkan ke 
//class Tampilan di textinterface.hpp
class Color     
{
    public :
        int theme;
        void chooseTheme();     //fungsi untuk menerima input theme untuk memilih tema
        void editorTheme();     //fungsi membaca input theme dan mengubah warnanya
        int getInfoColor();     //untuk melakukan tes disaat program ini dibuat
        void tampilanSetting(); //untuk melakukan tes disaat program ini dibuat
};

void Color::chooseTheme()
{
    cout << "Warna apa maunya?\n";  //menu meminta input theme
    cout << "1. Dark Mode\n";
    cout << "2. Light Mode\n";
    cout << "3. Default\n";
    cout << "Pilihan: ";
    cin >> theme;
}

void Color::editorTheme()
{
        switch (theme)  //switch case untuk mengubah warna sesuai dengan input theme
        {
        case 1:     //warna backgroud gelap dengan teks hijau
            cout << "\033[1;32m";   
            cout << "\033[40m";
            break;
        case 2:     //warna backgroud putih dengan teks pink
            cout << "\033[1;95m";   
            cout << "\033[107m";
            break;
        case 3:     //warna terminal default
            cout << "\033[1;13";
            cout << "\033[64m";
            break;
        default:    //jika menginput tidak sesuai menu yang tersedia
            break;
        }
}

int Color::getInfoColor()
{
    return theme;       //untuk melakukan tes disaat program ini dibuat
}
