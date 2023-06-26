#include <iostream>
#include <conio.h> //untuk getch
#include <math.h> //untuk pow
#include <iomanip> // untuk setw

using namespace std;

int main()
{
    int i=1, derajat;
    double koef[6],fbawah,fatas,fc,error,c, syarat,err,b_bawah, b_atas;
    cout << "=====================================================" << endl;
    cout << "\t\t METODE BISEKSI (derajat 5)" << endl;
    cout << "=====================================================" << endl;
    cout << " Pangkat tertinggi (derajat) persamaan : ";cin >> derajat;

    for (i=derajat; i>=0; i--)
    {
        cout << " Masukkan koefisien x^"<<i<<" : "; cin >> koef[i];
    }
    cout << "-----------------------------------------------------" << endl;

    i=1;
    do
    {
        cout << " Masukkan nilai batas bawah : "; cin >> b_bawah;
        cout << " Masukkan nilai batas atas  : "; cin >> b_atas;

        cout << "-----------------------------------------------------" << endl;
        //Menghitung f(batas bawah)
        fbawah =(koef[5]*pow(b_bawah,5))+(koef[4]*pow(b_bawah,4))+(koef[3]*pow(b_bawah,3))+(koef[2]*pow(b_bawah,2))+(koef[1]*pow(b_bawah,1))+(koef[0]*pow(b_bawah,0));
        cout << " f(b-bawah) = "<< fbawah << endl;

        //Menghitung f(batas atas)
        fatas =(koef[5]*pow(b_atas,5))+(koef[4]*pow(b_atas,4))+(koef[3]*pow(b_atas,3))+(koef[2]*pow(b_atas,2))+(koef[1]*pow(b_atas,1))+(koef[0]*pow(b_atas,0));
        cout << " f(b-atas)  = "<< fatas << endl << endl;

        syarat=fbawah*fatas;
        cout << " fbawah * fatas = " << syarat;

        getch(); //menahan layar
        system("cls");

    } while (fbawah*fatas >= 0); //Menghitung syarat f(batas bawah)*f(batas atas) < 0 (akar ada diantara selang batas bawah dan atas)



    //c adalah nilai tengah antara batas atas & batas bawah
    c =((b_bawah+b_atas)/2.0);
    cout << " c   = "<< c << endl;

    //Mencari nilai f(c)
    fc = (koef[5]*pow(c,5))+(koef[4]*pow(c,4))+(koef[3]*pow(c,3))+(koef[2]*pow(c,2))+(koef[1]*pow(c,1))+(koef[0]*pow(c,0));
    cout << " f(c)= " <<fc<< endl << endl;

    cout << " Masukkan nilai error :"; cin >> error;

    getch(); //menahan layar
    system("cls");

    cout << "\t\t\t\t METODE BISEKSI" << endl;
    cout << "==============================================================================================" << endl;
    cout << "|    i    |   b_bawah   |   b_atas   |    c    |   f(b_bawah)   |   f(b_atas)   |    f(c)    |" << endl;
    cout << "==============================================================================================" << endl;
    do
    {
    c =((b_bawah+b_atas)/2.0);
    fc = (koef[5]*pow(c,5))+(koef[4]*pow(c,4))+(koef[3]*pow(c,3))+(koef[2]*pow(c,2))+(koef[1]*pow(c,1))+(koef[0]*pow(c,0));

    cout << "|" << setw(9) << i << "|";
    cout << setw(13) << b_bawah << "|";
    cout << setw(12) << b_atas << "|";
    cout << setw(9)  << c << "|";
    cout << setw(16) << fbawah << "|";
    cout << setw(15) << fatas << "|";
    cout << setw(12) << fc << "|";
    cout << endl;


    if(fbawah*fc<0)
		{
			b_atas=c;
		}
		else if (fbawah*fc>0)
		{
			b_bawah=c;
		}
		else
		{
		    break;
		}

    err = b_atas-b_bawah;

    i++;

    } while (err>error);

    cout << endl;
    cout << " Jumlah iterasi : "<<i;
    return 0;
}
