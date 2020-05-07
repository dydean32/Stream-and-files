#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
//Mendeklarasikan Variabel array
char nama[100];
string kota;
int berat;
float BMI;
float tinggi;
char pil;
int i=0;
/*membuat objek stream*/
ofstream out;
//Membuka file disk NIM.txt
out.open("18101046.txt");
/*Buat konstruksi pengulangan untuk memasukan data*/
cout<<"input DATA PASIEN"<<endl;
cout<<"Tekan enter untuk memulai";
//Buat konstruksi pengulangan untuk memasukan data/
do
{
    //Input data ke variabel

    cout<<endl;
    cin.ignore();
    cout<<"Tuliskan nama anda: ";cin.get(nama,100);
    cout<<"Tuliskan asal kota anda: ";cin>>kota;
    cout<<"Tuliskan berat anda: ";cin>>berat;
    cout<<"Tuliskan tinggi anda (dalam m) : ";cin>>tinggi;
    //Menuliskan data ke file melalui objek stream
    cout<<"tambah data lagi(y/t)?";
    cin>>pil;
    out<<nama<<endl<<kota<<endl<<berat<<endl<<tinggi;
}while(pil=='y');
//Tutup akses file disk
out.close();
cout<<"Data ditulis ke File!!!"<<endl;
//Membuat objek stream
ifstream in;
//membuka disk file
in.open("18101046.txt");
/*Buat konstruksi pengulangan untuk membaca data*/
while(!in.eof())
{
    //Membaca data
    in.getline(nama,100);
	in>>kota>>berat>>tinggi;
	BMI = berat/(tinggi*tinggi);
    //Menampilkan output sesuai soal
    i++;
    cout<<endl;
	cout<<"Data ke "<<i<<endl;
    cout<<"Nama     : "<<nama<<endl;
    cout<<"Kota     : "<<kota<<endl;
	cout<<"Berat    : "<<berat<<endl;
	cout<<"Tinggi   : "<<tinggi<<endl;
	cout<<"BMI      :"<<BMI<<endl;
}
//tutup akses disk file
in.close();
return 0;
}
