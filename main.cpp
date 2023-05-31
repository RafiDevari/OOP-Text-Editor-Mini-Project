/*

!!CREATED AT 15/05/2023 -> M THORIQ
!!EDITED AT 16/05/2023 -> IBRA RIZQY
!!EDITED AT 30/05/2023 -> RAFI DEVARI

Kelompok  : Ibra Rizqy Siregar (221402104)
            Ravi Devari (221402063)
            M. Thoriq (221402119)
            Azura Sevina (221402013)
Nama File : main.cpp
Deskripsi : Teks editor sederhana yang mempunyai fitur utama membuat file, membaca file, dan mengedit file.
*/ 

#include "new.hpp"   //create.hpp berisi fungsi untuk membuat file baru
#include "edit.hpp"     //edit.hpp berisi fungsi untuk mengubah isi file
#include "read.hpp"     //read.hpp berisi fungsi untuk membaca file
#include "textinterface.hpp"  //textinterface.hpp berisi fungsi-fungsi untuk mempercantik tampilan program
                                
using namespace std;

int main()
{
    int input;  //variabel integer input sebagai input yang diminta dari user untuk mengakses menu 
            //berupa angka dari 1 sampai dengan 5

    while(true)
    {
        system("cls");  //agar tampilan di terminal terlihat lebih rapi dengan menghapus teks
                        //yang tidak dibutuhkan

        Tampilan UI;    //deklarasi objek dari class Tampilan yang diambil dari textinterface.hpp
        UI.editorTheme();   //Memulai tampilan dengan theme dari Color
        UI.garis();       //Tampilan "="yang ada di di bawah untuk membatasi user input dan programnya
        UI.kosong();       //memberi "|" di ujung program dan memberi spasi untuk membuat "|" diujung program
        UI.printCtr("Welcome"); //untuk membuat tulisan welcome berada di tengah
        UI.kosong();
        UI.printCtr("Select a menu :");//untuk membuat tulisan Selec a menu berada di tengah
        UI.kosong();
        UI.printCtr("1. New");//untuk membuat tulisan New berada di tengah
        UI.kosong();
        UI.printCtr("2. Read");//untuk membuat tulisan Read berada di tengah
        UI.kosong();
        UI.printCtr("3. Edit");//untuk membuat tulisan Edit berada di tengah
        UI.kosong();
        UI.printCtr("4. Theme");//untuk membuat tulisan Theme berada di tengah
        UI.kosong();
        UI.printCtr("5. Exit");//untuk membuat tulisan Exit berada di tengah
        UI.kosong();
        UI.garis();
        cout << "Pilihan: ";    //meminta input pilihan menu
        cin >> input;

        New create;         //membuat objek baru dari setiap class yang berbeda
        Read open;
        Edit update;

        switch (input)      //switch case untuk menjalankan fungsi yang akan digunakan sesuai input
        {
            case 1:
                create.create();   //memanggil fungsi create dari create.hpp
                break;
            case 2:
                open.reads();    //memanggil fungsi reads dari read.hpp
                break;
            case 3:
                update.edit();     //memanggil fungsi edit dari edit.hpp
                break;
            case 4:
                UI.colorSetting();  //memanggil fungsi colorSetting dari textinterface.hpp melalui objek
                break;
            case 5:
                exit(0);    //mengakhiri dan menutup program
            default:
                cout << "Menu tidak tersedia\n";        //kondisi jika input yang diminta tidak sesuai
                cout << "Press enter to continue...\n"; //dengan input yang tersedia
                while (true)    
                {
                    int c = _getch();   
                    if (c == '\r')  //tombol enter untuk melanjutkan program agar input diminta kembali
                        break;
                    else
                        continue;
                }
                    break;
            }
        }
    return 0;
}
