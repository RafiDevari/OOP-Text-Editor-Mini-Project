/*

!!CREATED AT 17/05/2023 -> M THORIQ
!!EDITED AT 25/05/2023 -> IBRA RIZQY, AZURA SEVINA
!!EDITED AT 30/05/2023 -> RAFI DEVARI

*/

#include <iostream>
#include <windows.h>
#include <iostream>
#include "color.hpp"

using namespace std;

class Tampilan : public Color //Inherit class dari library buatan bernama COLOR
{
    private :
        int width, height;
    public :
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        
        Tampilan(){  //Constructor untuk memulai program yang menyesuaikan ukuran window
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
            width = csbi.srWindow.Right - csbi.srWindow.Left;
            height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
        }
        void printCtr(string);
        void right_left();
        void colorSetting(){chooseTheme();}
        void garis();
        void kosong();
        ~Tampilan(){cout << "\033[39m" << "\033[49m";}
};

void Tampilan::garis()     //membuat semacam suatu barrier yang membatasi atas dan bawah program
{
    for (int i = 0; i < width; i++)  //akan terus mencetak "=" sampai lebar terakhir dari program
    {
        cout << "=";
    } cout << endl;
}

void Tampilan::kosong()  //membuat "|" diawal lalu membuat "|" di lebar akhir dari program
{
    cout << "|";
    for (int i = 0; i < width-2; i++)
    {
        cout << " ";
    }
    cout << "|";
    cout << endl;
}

void Tampilan::printCtr(string text)   //akan membuat Text sesuai dengan isi argumen di tengah program
{
    int len;
    len = text.length();
    if (len <= 8)
    {
        cout << "|" ;
        for (int i = 0; i < (width/2)-2; i++)
        {
            cout << " ";
        }
        cout << text;
        
        for (int i = 0; i <= width/2-(len); i++)
        {
            cout << " ";
        }
        cout << "|" << endl;
    }
    else if (len >=9)
    {
        cout << "|";
        for (int i = 0; i < (width/2-(len/2)); i++)
        {
            cout << " ";
        }
        cout << text;
        for (int i = 0; i <= width/2-(len/2)-3; i++)
        {
            cout << " ";
        }
        cout << "|" << endl;
    }

}

