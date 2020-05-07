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
    cin.ignore();
    cout<<"Tuliskan nama: ";
	cin.getline(nama,100);
    //Gunakan Pengulangan untuk input tugas 1-4
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
    float jumlah = 0;
    for(i=0;i<4;i++)
    {
    	cout<<"Nilai tugas ke-"<<i+1<<":"<<nilai[i];
    	jumlah=jumlah+nilai[i];
    	cout<<endl;
	}
    //Tampilkan rata-rata
    rata=jumlah/i;
    cout<<"Nilai rata rata= "<<rata<<endl;
    }
    void indeks()
    {
    	if(rata>80)
    	{
    		cout<<"Indeks nilai: A";
    		cout<<endl;
		}else if(rata<=80)
    	{
    		cout<<"Indeks nilai: AB";
    		cout<<endl;
		}else if(rata<=70)
    	{
    		cout<<"Indeks nilai: B";
    		cout<<endl;
		}else if(rata<=65)
    	{
    		cout<<"Indeks nilai: BC";
    		cout<<endl;
		}else if(rata<=60)
    	{
    		cout<<"Indeks nilai: C";
    		cout<<endl;
		}else if(rata<=50)
    	{
    		cout<<"Indeks nilai: D";
    		cout<<endl;
		}else
		{
			cout<<"Indeks nilai: E";
			cout<<endl;
		}
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
//Reset posisi pointer di awal file
dd.seekg(0);
//Baca data pertama
dd.read( (char*) (&d1), sizeof(d1) ); 
while(!dd.eof())
{
	cout<<"\nData ke-"<<j++<<":";
	cout<<endl;
    //Tampilkan nilai dan indeks
    d1.dipslay();
    d1.indeks();
    //baca data lain
    dd.read( (char*) (&d1), sizeof(d1) );
}
//tutup file disk
dd.close();
//buka file disk
dd.open("18101046.txt",ios::in|ios::binary|ios::out);
//Memilih file yang ingin diedit
int s=0;
cout<<"Data mana yang ingin diedit: ";cin>>s;
//Menghitung letak pointer
int pos = (s-1)*sizeof(d1);
dd.seekg(pos);    //Meletakkan posisi pointer 
//melihat posisi pointer sekarang
cout<<"\nPosisi Pointer Sekarang : "<<dd.tellg();
cout<<endl;
cout<<endl;
//Masukkan data objek baru 
d1.get();
//Menulis data ke file
dd.write( (char*) (&d1), sizeof(d1) );
//Tutup disk file
dd.close();
cout << endl;
return 0;
}
