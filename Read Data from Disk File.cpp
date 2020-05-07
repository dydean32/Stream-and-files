#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
/*Mendefinisikan variabel*/
char nama[100];
string kota;
int nim, berat;
float tinggi, BMI;
/*Membuat objek stream dan membuka disk file  
  yang telah ditulis di program percobaan 1 write data */
ifstream in("18101046.txt");
/*Membaca data dari disk file*/
in.getline(nama,100);
in>>kota>>berat>>tinggi;
/*menghitung nilai BMI dengan rumus BMI=berat/(tinggi*tinggi)*/
BMI = berat/(tinggi*tinggi);
/*Menampilkan data sesuai dengan output di soal*/
cout<<"===DATA PASSIEN===";
cout<<endl;
cout<<endl;
cout<<"Nama     : "<<nama<<endl;
cout<<"Berat    : "<<berat<<" Kg"<<endl;
cout<<"Tinggi   : "<<tinggi<<" M";
cout<<endl;
cout<<"BMI      : "<<BMI;
return 0;
}
