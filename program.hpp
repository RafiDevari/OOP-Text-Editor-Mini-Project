/*
Nama File : program.hpp
Deskripsi : File ini berisi class yang akan di include dalam new.hpp, edit.hpp, dan read.hpp
*/ 
#include <string>
#include <conio.h>
using namespace std;

//class program untuk menurunkan 2 variabel yang nantinya akan dipakai oleh file yang bersangkutan
class Program   
{
    protected:
        string line;        //Variabel untuk menyimpan setiap baris saat kita menginput yang nantinya akan dimasukkan ke file tertentu menggunakan fstream.
        string filename;    //variabel yang menyimpan nama file
        string extension;   //variabel yang menyimpan nama ekstensi file
};