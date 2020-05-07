#include <iostream>
#include <fstream>
#include <string>
using namespace std;
////////////////////////////////////////////////////////////////
//Membuat Kelas
class siswa
{
private:
    //Deklarasikan variabel
    char nama[100];
    float nilai[4], rata;
public:
    //Buat member fungsi untuk input data
    void get()
    {
    //input nama
    cin.ignore();   //untuk membersihkan buffer
    //Gunakan Pengulangan untuk input tugas 1-4
    cout<<endl;
    cout<<"Tuliskan nama: ";cin.getline(nama,100);
    int i;
    for(i=0;i<4;i++)
    {
    	cout<<" Input tugas ke-"<<i+1<<": ";cin>>nilai[i];
	}

    }
    //Buat member fungsi untuk menampilkan data
    void dipslay()
    {
    //Tampilkan nama
    cout<<" Nama: "<<nama;
    cout<<endl;
    //buat pengulangan untuk tampilkan tugas
    int i;
    for(i=0;i<4;i++)
    {
    	cout<<"Nilai tugas ke-"<<i+1<<":"<<nilai[i];
    	cout<<endl;
	}
    //Tampilkan rata-rata
    rata=(nilai[0]+nilai[1]+nilai[2]+nilai[3])/4;
    cout<<"Nilai rata rata= "<<rata<<endl;
    }
};
////////////////////////////////////////////////////////////////
int main()
{
siswa d1;       //Membuat objek
fstream dd;       //Membuat objek stream
int j=1;
char pil;

//Membuka file disk dan Mengatur Mode bit
dd.open("18101046.txt", ios::app | ios::out | ios::in | ios::binary );
//memmbuat pengulangan untuk input objek
cout << "\nTuliskan Data Siswa, \nTekan enter untuk memulai";
do
{
    //Memanggil member fungsi untuk input data
    d1.get();
    //Menulis ke file disk
    dd.write( (char*) (&d1), sizeof(d1) );
    cout<<"Tuliskan data baru lagi (y/t)?";
    cin>>pil;
}while(pil=='y');
dd.seekg(0);  //meletakkan pointer di awal data
//Baca data pertama
dd.read( (char*) (&d1), sizeof(d1) );
//Pengulangan dengan syarat eof()
while(!dd.eof())
{
    //Tampilkan data
    cout<<"\nData ke-"<<j++<<":";
    cout<<endl;
    d1.dipslay();
    dd.read((char*)(&d1),sizeof(d1));
}
//tutup file disk
dd.close();
cout << endl;
return 0;
}
