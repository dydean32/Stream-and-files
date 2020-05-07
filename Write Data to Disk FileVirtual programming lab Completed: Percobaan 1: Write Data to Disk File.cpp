#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
  /*Deklasrasi variabel sesuai dengan contoh program*/
  char nama[100];
  string kota;
  int nim;
  float berat;
  float tinggi;
  /*Membuat objek stream dan file disk bernama Nama[NIM].txt*/
  ofstream out("18101046.txt");
  /*Input data ke variabel*/
  cout<<"INPUT DATA PASSIEN";
  cout<<endl;
  cout<<"Tuliskan Nama anda: ";
  cin.get(nama,100);
  cout<<"Tuliskan asal kota anda: ";cin>>kota;
  cout<<"Tuliskan berat anda: ";cin>>berat;
  cout<<"Tuliskan tinggi anda (dalam m): ";cin>>tinggi;
  /*Menuliskan data ke file disk melalui objek stream*/
  out<<nama<<endl<<kota<<endl<<berat<<endl<<tinggi;
  cout<<"\nData berhasil ditulis";
return 0;
}
