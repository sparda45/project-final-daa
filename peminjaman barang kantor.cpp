#include <iostream> // Di gunakan untuk menjalankan perintah input dan output. seperti cin, cout.
#include <conio.h> // Di gunakan untuk membuat antarmuka dengan pengguna. seperti getch
#include <string.h> // Di gunakan untuk membaca String
#include <dos.h> // Di gunakan untuk membuat perintah delay.
#include<iomanip> // Digunakan untuk ngerapihin spasi membuat table
#include<cstdlib> // Header yang berisi fungsi-fungsi umum termasuk manajemen pengelolaan memori, pembuatan angka acak, berkomunikasi dengan environment, aritmatika, pencarian, pengurutan, dan konversi. 
using namespace std; //Menggunakan skope std sebagai Nama skope untuk penggunaan instruksi, misalnya std::cin std::cout 

//prototype
void login();
void menu();
void menukel();
void menupnj();
void mainpinjam();
void inputbarang();
void tampilbarang();
void transpinjam();
void pengembalian();
void laporanbarang();
void dafmemb();
void menmemb();
void vmemb();
void pinmemb();
void vpm();
void blkm();
void hapusbrg();
void hapusmember();
void editb();
void edm();

//variabel
int jmlbuk,a,c,e,f,g,h,i,jmlpin,hs,lp,kodepin,stok,stoktambah,hsmem,lama,discmem,q,r,kpm,j,k,l,v,denda,lpin,lampin;
int b =-1,d =-1, m = -1, p =-1;
char yn,ch,temp,yb;
	
// mendefinisikan struct
struct member{//membuat struct untuk member
	int kodmemb;
	string namemb;
	string ptmemb;
	string almemb;
	string notelpmemb;
	char statmemb;	
}brgmemb [100]; //dekkarasi
	
struct pinmemb{//membuat struct pinjam member
	int kopinj,p,kb,tb,tp,dp,km,tpin,tbalik,tbl;
	char statp;
}pmemb[100];

struct barang{ //membuat struktur barang
	int kodeB,sewa,stock,pt,kt;
	string Nama;
	int b;
}barang[100]; //deklarasikan

struct pinjam{//membuat struktur pinjam
	int kodepinjam,d,kB,tglpin,tglbalik,dipinjam,tblk,kM,telat;
	string Namap;
	string pt;
	string alamat;
	string notlp;
	char status;
}pinjambrg[100]; //deklarasikan

void login(){ 	//membuat username dan password
	string user = "";
	string pass = "";
	cout<<"\n\n\n\n\n\n\n\n";
	cout<<"\t\t PT RenGaTia DyaMond\n\n";
	cout<<"\t\t -------  Aplikasi Penyewaan Fasilitas Kantor --------\n\n";
	cout <<"\t\t Jl. Permai Bangsa No.10, RT.1/RW.2, Jakarta Selatan \n\n",
	cout << "\t\t ===================================================\n\n" << endl;
	cout << "\t\t\t  Username : "; cin>>user;
	cout << "\t\t\t  Password : ";
	ch = _getch();
    while(ch != 13){ //character 13 is enter
    pass.push_back(ch);
    cout << '*';
    ch = _getch();
    }
    cout<<endl;
	if(user == "kel7" && pass == "123"){
		cout << "\n\n\t\t\tAnda berhasil login. \n" << endl;
		system("pause");
		system("cls");
		menu();
	}else{
		cout<<"\n\n\t\t\tUsername/Password Anda Salah\n"<<endl;
   	    system("pause");
   	    system("cls");
	 	login();
	}
}

void menu(){
	system("cls");
	int pil; 
	do{
	cout << " ------------------------------------------------ "<<endl;
	cout<<	"\t\tMenu Utama	       			   "<<endl;
    cout << " ------------------------------------------------ "<<endl<<endl;
    cout<<"[1]. Menu Kelola Barang       \n";
    cout<<"[2]. Menu Peminjaman       \n";
    cout<<"[3]. Log Out               \n";
    cout<<"----------------------\n";
    cout<<"Masukan Pilihan anda[ 1 s.d. 3 ] = ";cin>>pil; 
    
	if(pil ==1){ //input barang 
		menukel();}
	else if( pil == 2 ){ ///menu peminjaman utama
		mainpinjam();}
	else if(pil == 3){ //keluar
		cout<<"-- Anda Telah Logout -- \n";
		system("pause");
		system("cls");
		login();
	}else{ //jika inputan semua salah 
		system("cls");
	 menu();
	}
}while(pil <1 && pil >3);	
}


void menukel(){
	system("cls");
	int no;
	cout << " ------------------------------------------------ "<<endl;
	cout<<	"\t\tMenu Kelola Barang	       			   "<<endl;
    cout << " ------------------------------------------------ "<<endl<<endl;
    cout<<"[1]. Input Barang       \n";
    cout<<"[2]. Tampil Data Barang    \n";
    cout<<"[3]. Edit Data   \n";
	cout<<"[4]. Hapus Data  \n";
 	cout<<"[5]. Kembali Ke Main Menu    \n";
 	
    cout<<"=======================\n";
    cout<<"Masukan Pilihan anda[ 1 s.d. 5] = ";cin>>no; 
	if(no ==1){ //input barang 
		inputbarang();}
	else if( no == 2 ){ // melihat daftar barang yang sudah di masukkan
		tampilbarang();}
		else if(no == 3){ // edit harga
		 editb();}
	else if(no == 4){ // hapus data
	hapusbrg();}
		else if(no == 5){ // kembali ke menu utama
		menu();}
}
void mainpinjam(){
	system("cls");
	int no;
	cout << " ------------------------------------------------ "<<endl;
	cout<<	"\t\tMenu Peminjaman	       			   "<<endl;
    cout << " ------------------------------------------------ "<<endl<<endl;
  	cout<<"[1]. Member      \n";
    cout<<"[2]. Non-Member    \n";
    cout<<"[3]. Kembali Ke Main Menu  \n";
    cout<<"=======================\n";
    cout<<"Masukan Pilihan anda[ 1 s.d. 3] = ";cin>>no; 
    if(no ==1){  //menu member 
		menmemb();}
	else if( no == 2 ){ //menu nonmember
		menupnj();}
	else if(no == 3){ //menu utama
	menu();}
}
void menupnj(){
	system("cls");
	int num;
	cout << " ------------------------------------------------ "<<endl;
	cout<<	"\t\tMenu Peminjaman Non Member	       			   "<<endl;
    cout << " ------------------------------------------------ "<<endl<<endl;
  	cout<<"[1]. Peminjaman      \n";
    cout<<"[2]. Pengembalian    \n";
    cout<<"[3]. Laporan   \n";
    cout<<"[4]. Kembali Ke Menu Utama Peminjaman   \n";
    cout<<"=======================\n";
    cout<<"Masukan Pilihan anda[ 1 s.d. 4] = ";cin>>num; 
    if(num ==1){ //transaksi peminjaman nonmemb 
		transpinjam();}
	else if( num == 2 ){ // pengembalian nonmemb
		pengembalian();}
	else if(num == 3){ //melihat laporan barang setelah transaksi
	laporanbarang();}
	else if(num == 4){ // kembali ke menu peminjaman utama
		mainpinjam();}	
}

void menmemb(){
	system("cls");
	int num;
	cout << " ------------------------------------------------ "<<endl;
	cout<<	"\t\tMenu Khusus Member       			   "<<endl;
    cout << " ------------------------------------------------ "<<endl<<endl;
    cout<<"[1]. Daftar Member      \n";
    cout<<"[2]. Tampil Data Member    \n";
    cout<<"[3]. Edit Member    \n";
    cout<<"[4]. Hapus Member    \n";
    cout<<"[5]. Pinjam Member    \n";
  	cout<<"[6]. Pengembalian Member    \n";
  	cout<<"[7]. Laporan Member    \n";
 	cout<<"[8]. Kembali Ke Menu Utama Peminjaman    \n";
    cout<<"=======================\n";
    cout<<"Masukan Pilihan anda[ 1 s.d. 8] = ";cin>>num; 
	if(num ==1){ //daftar/ register member
		dafmemb();}
	else if(num == 2){  //melihat daftar member 
		vmemb();}
		else if(num == 3){ //edit data member
		edm();}
		else if(num == 4){ //hapus data member
		hapusmember();}
	else if(num == 5){  // transaksi peminjaman member
		pinmemb();}
		else if(num == 6){  // transaksi pengembalian member
		blkm();}
	else if(num == 7){ //melihat laporan barang setelah transaksi
		vpm();}
		else if(num == 8){ // kembali ke menu peminjaman utama
	mainpinjam();}
}

void inputbarang(){
	system("cls");
	system("cls");
		cout<<"\n"<<endl;	
		cout << "\t ----------------------------------------------- "<<endl;
		cout<<	"\t\t\tInput Barang      			   "<<endl;//input barang berdasarkan jumlah  barang yang mau di input
    	cout << "\t ----------------------------------------------- "<<endl;
		cout<<endl;
		b++;
			cout<<" Masukan data barang Ke : "<<b+1<<endl; 
			cout<<" Kode barang \t\t: ";scanf("%d%c", &barang[b].kodeB, &temp);
			cout<<" Nama barang\t\t: ";getline(cin,barang[b].Nama);
			cout<<" Harga Sewa \t\t: ";scanf("%d%c", &barang[b].sewa, &temp);
			cout<<" Jumlah barang\t\t: ";scanf("%d%c", &barang[b].stock, &temp);
			cout<<endl;
			cout<<"Apakah Anda Ingin Menambahkan Data Lagi ? (y/n): ";cin>>yn;
			if(yn=='y'||yn=='Y'){
				inputbarang();}
			else{
				cout << "\n\n Data Berhasil Disimpan \n" << endl;
				system("pause");
				system("cls");
				menukel();
			}
		{
			cout << "\n\n Data Berhasil Disimpan \n" << endl;
			system("pause");
			system("cls");
			menukel();
		}		
}

void tampilbarang(){
	system("cls");
	
		cout<<"\n"<<endl;
		cout << "\t ----------------------------------------------- "<<endl;
		cout<<	"\t\t\tDaftar Barang      			   "<<endl;//daftar barang setelah diinput
    	cout << "\t ----------------------------------------------- "<<endl;
		cout<<endl;
		cout<<"|---------------------------------------------------------------------------------------------|\n";
		cout<<"|  No    Kode Barang         Nama barang         Harga Sewa    Jumlah barang    Barang Keluar |\n";
		cout<<"|---------------------------------------------------------------------------------------------|\n";
		for(c=0;c<=b;c++){
			stok = barang[c].stock;
			barang[c].pt= pinjambrg[c].dipinjam +pmemb[c].dp;
			if((pinjambrg[c].status == 'y') || (pinjambrg[c].status == 'Y')){
				stok= barang[c].stock-barang[c].pt;}
			else if ((pmemb[c].statp == 'y') || (pmemb[c].statp == 'Y')){
				stok= barang[c].stock-barang[c].pt;}	
			else if((pinjambrg[c].status == 'n') || (pinjambrg[c].status == 'N')){
				pinjambrg[c].dipinjam=0;
				stok= barang[c].stock+pinjambrg[c].dipinjam;
				barang[c].pt=0;}
			else if ((pmemb[c].statp == 'b') || (pmemb[c].statp == 'B')){
				pmemb[c].dp=0;
				stok= barang[c].stock+pmemb[c].dp;
				barang[c].pt=0;}
			cout<<"| "<<setw(2)<<c+1<<setw(11)<<barang[c].kodeB<<setw(25)<<barang[c].Nama<<setw(17)<<barang[c].sewa<<setw(14)<<stok<<setw(16)<<barang[c].pt<<"       |";
			cout<<endl;
		}
		
		{
		cout<<endl;
		system("pause");
		system("cls");
		menukel();}
}

void hapusbrg(){
	int kh;
	 system ("cls");
  cout<<"\n PENGHAPUSAN DATA PADA DATA BARANG\n";
  cout<<" __\n\n";
  
  cout<<" Masukan Kode Barang : "; cin>>kh;
     cout<<endl;
	for(c=0;c<=b;c++){
	if(barang[c].kodeB == kh){
		for(j=c;j<b+1;j++){
			barang[j]=barang[j+1];	
		}
		cout<<" DATA BERHASIL DI HAPUS\n\n";
		b--;
	}}
	{
		cout<<endl;
		system("pause");
		system("cls");
		menukel();}
}

void editb(){
int keb;
	int plh;
	system ("cls");
  cout<<"\n Pengeditan Data Barang\n";
  cout<<" __\n\n";
  
  cout<<" Masukan kode  barang : "; cin>>keb;
     cout<<endl;
	for(c=0;c<=b;c++){
	if(barang[c].kodeB == keb){
		cout<<" [1].Edit Stok "<<endl;
		cout<<" [2].Edit Harga "<<endl;
		cout<<" [3].Edit Keduanya "<<endl;
		cout<<" [4].Batalkan Edit "<<endl;
		cout<<"masukkan pilihan anda (1-4): ";
		cin>>plh;
		if(plh==1){
		cout<<" Nama barang \t\t\t: "<<barang[c].Nama<<endl;
		cout<<" Stock Barang \t\t\t: "<<barang[c].stock<<endl;
		for(l=c;l<=c;l++){
			cout << " Masukkan Stock Terbaru\t\t: "; cin >>barang[l].stock;	
			cout<<" DATA BERHASIL DIEDIT\n\n";
		}}
		else if(plh==2){
		cout<<" Nama barang \t\t\t: "<<barang[c].Nama<<endl;
		cout<<" Harga Barang \t\t\t: "<<barang[c].sewa<<endl;
		for(l=c;l<=c;l++){
			cout << " Masukkan Harga Baru \t\t: "; cin >>barang[l].sewa ;	
			cout<<" DATA BERHASIL DIEDIT\n\n";
		}}
		else if(plh==3){
		cout<<" Nama barang \t\t\t: "<<barang[c].Nama<<endl;
		cout<<" Stock Barang \t\t\t: "<<barang[c].stock<<endl;
		cout<<" Harga Barang \t\t\t: "<<barang[c].sewa<<endl;
		for(l=c;l<=c;l++){
			cout << " Masukkan Stock Terbaru\t\t: "; cin >>barang[l].stock;	
			cout << " Masukkan Harga Baru \t\t: "; cin >>barang[l].sewa ;	
			cout<<" DATA BERHASIL DIEDIT\n\n";
		}}
		else if(plh==4){
		menukel();
		}
		}
	}
	{
		cout<<endl;
		system("pause");
		system("cls");
		menukel();
	}
}	

void transpinjam(){
		d++;
		system("cls");
				cout<<"\n"<<endl;
				cout << "\t ------------------------------------------------ "<<endl;
				cout<<	"\t\t\tTransaksi Peminjaman     			   "<<endl;//input barang berdasarkan jumlah  barang yang mau di input
		    	cout << "\t ------------------------------------------------ "<<endl;
				cout<<endl;
				cout<<" Masukan data Pinjaman Ke \t: "<<d+1<<endl;
				cout<<" Kode Pinjaman \t\t\t: ";scanf("%d%c", &pinjambrg[d].kodepinjam, &temp);
				cout<<" Kode barang \t\t\t: ";scanf("%d%c", &pinjambrg[d].kB, &temp);
						
				for(c=0;c<=b;c++){
					if(barang[c].kodeB == pinjambrg[d].kB){
						cout<<" Nama barang \t\t\t: "<<barang[c].Nama<<endl;
					
				cout<<" PT Penyewa barang \t\t: ";getline(cin,pinjambrg[d].pt);
				cout<<" Nama perwakilan Penyewa barang : ";getline(cin,pinjambrg[d].Namap);
				cout<<" Alamat Penyewa \t\t: ";getline(cin, pinjambrg[d].alamat);
				cout<<" Kontak Penyewa \t\t: ";getline(cin, pinjambrg[d].notlp);
				cout<<" Tanggal Pinjam (DDMMYYYY)\t: ";scanf("%d%c", &pinjambrg[d].tglpin, &temp);
				cout<<" Tanggal Balik (DDMMYYYY)\t: ";scanf("%d%c", &pinjambrg[d].tglbalik, &temp);
				lp = (pinjambrg[d].tglbalik-pinjambrg[d].tglpin)/1000000;
				cout<<" Lama Pinjaman \t\t\t: "<<lp<<" Hari"<<endl;
				cout<<" Banyak barang yang di pinjam  \t: ";scanf("%d%c", &pinjambrg[d].dipinjam, &temp);
				cout<<endl;
				if(pinjambrg[d].dipinjam>stok){
					cout<<"Stok Barang tidak cukup, tidak bisa melakukan peminjaman"<<endl;
					pinjambrg[d].dipinjam=0;
					d--;
					system("pause");
					system("cls");
					
					menupnj();
				}else{				
				hs = pinjambrg[d].dipinjam*barang[d].sewa;
				cout<<" Harga Sewa \t\t\t: "<<hs;
				cout<<endl;
				cout<<" Status dipinjam (y) ? \t\t: ";cin>>pinjambrg[d].status;
				cout<<endl;}
			} else if (barang[c].kodeB != pinjambrg[d].kB){
						cout<<"\n Data barang Tidak Ditemukan \n";
						system("pause");
						system("cls");
						d--;
						menupnj();
					}	
			cout<<"Apakah Anda Ingin Menambahkan Data Lagi ? (y/n) :";cin>>yn;
			if(yn=='y'||yn=='Y'){
				transpinjam();
			}else{
				cout << "\n\n Data Berhasil Disimpan \n" << endl;
				system("pause");
				system("cls");
				menupnj();}
			
				}
}


void pengembalian(){
	system("cls");
	cout<<"\n"<<endl;	
		cout << "\t ------------------------------------------------ "<<endl;
		cout <<	"\t\t\tTransaksi Pengembalian    			   "<<endl;//input barang berdasarkan jumlah  barang yang mau di input
    	cout << "\t ------------------------------------------------ "<<endl;
			cout<<"\t\t\tMasukan kode Peminjaman :";cin>>kodepin; //memasukan kode peminjaman 
			cout<<"\t\t\t\n"<<endl;
			cout<<endl;
			for(f=0;f<=d;f++){ 
				if(pinjambrg[f].kodepinjam==kodepin){
					cout<<" Nama Penyewa barang \t\t:"<<pinjambrg[f].Namap;
					cout<<endl;
					cout<<" Alamat Penyewa \t\t:"<<pinjambrg[f].alamat;
					cout<<endl;
					cout<<" Kontak Penyewa \t\t:"<<pinjambrg[f].notlp;
					cout<<endl;
					if(barang[f].kodeB==pinjambrg[f].kB){
						cout<<" Nama barang \t\t\t:"<<barang[f].Nama<<endl;
					}
					cout<<" Tanggal Pinjam (DDMMYYYY)\t:"<<pinjambrg[f].tglpin;
					cout<<endl;
					cout<<" Tanggal Balik (DDMMYYYY)\t:";scanf("%d%c", &pinjambrg[d].tblk, &temp);
					cout<<endl;
					lpin = (pinjambrg[f].tblk-pinjambrg[f].tglpin)/1000000; 
					cout<<" Lama Pinjaman \t\t\t:"<<lpin<<" Hari"<<endl;
					
					if (lpin > lp){
					cout<<" Anda Telat      \t\t:"<<lpin-lp<<" Hari"<<endl;
					denda = (lpin-lp)*10000;
					cout<<" Dikenakan denda  \t\t:Rp"<<denda<<endl;}
					else {					
					denda=0;}
					cout<<" banyak barang yang di pinjam  \t:"<<pinjambrg[f].dipinjam;
					cout<<endl;
					hs = (pinjambrg[f].dipinjam*barang[f].sewa)+denda;
					cout<<" Harga Sewa \t\t\t:"<<hs<<endl;
					cout<<" Status \t\t\t: "<<pinjambrg[f].status;
					if((pinjambrg[f].status == 'y') || (pinjambrg[f].status == 'Y')){
						cout<<" (di Pinjam) "<<endl;
					}else{
						cout<<" (di kembalikan) "<<endl;
					}
					cout<<endl;
					cout<<" Sudah di kembalikan ? (y/n) : ";cin>>yn;
					if((yn == 'Y') || (yn == 'y')){
						cout<<" ganti status ( input n ) :";
						cin>>pinjambrg[f].status;
						cout << "\n\n Data Berhasil Disimpan \n" << endl;
						system("pause");
						system("cls");
						menupnj();
					}else{
						cout << "\n\n Data Berhasil Disimpan \n" << endl;
						system("pause");
						system("cls");
						menupnj();
					}
				}else{
					cout << "\n\n Data Tidak Di temukan \n" << endl;
					cout<<" Apakah ingin mengulang kembali ? (y/n) : ";cin>>yn;
					if(yn == 'Y' || yn == 'y'){
						system("cls");
						pengembalian();	
					}else{
						system("cls");
						menu();	}
				}
			}
}

void laporanbarang(){
	system("cls");
			cout<<"\n"<<endl;	
			cout<<"\t ------------------------------------------------ "<<endl;
			cout<<"\t\t\tlaporan peminjaman \n"; 
			cout<<"\t ------------------------------------------------ "<<endl;
			cout<<"\t\t\t\n"<<endl;
			cout<<"|-----------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
			cout<<"|  No    Kode Peminjaman         Nama barang       Nama Peminjam            Alamat         Tanggal Pinjam        Tanggal Balik          Status             Qty    |\n";
			cout<<"|-----------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
			for(g=0;g<=d;g++){ 
				if(pinjambrg[g].kB==barang[g].kodeB){
					cout<<"| "<<setw(2)<<g+1<<setw(11)<<pinjambrg[g].kodepinjam<<setw(25)<<barang[g].Nama<<setw(17)<<pinjambrg[g].Namap
					<<setw(25)<<pinjambrg[g].alamat<<setw(18)<<pinjambrg[g].tglpin<<setw(22)<<pinjambrg[g].tglbalik
					<<setw(10)<<pinjambrg[g].status;
					
					if((pinjambrg[g].status == 'y') || (pinjambrg[g].status == 'Y')){
						cout<<" (borrowed) ";
					}else{
						cout<<" (returned) ";
					}
					cout<<setw(12)<<pinjambrg[g].dipinjam<<"      |";	
					cout<<endl;
				}
			}
			{	
		system("pause");
		system("cls");
		menupnj();}
}

void dafmemb(){
		
		system("cls");
		cout<<"\n"<<endl;
		cout << "\t ------------------------------------------------ "<<endl;
		cout<<	"\t\t\tDaftar member			   "<<endl;//menu untuk daftar member
    	cout << "\t ------------------------------------------------ "<<endl;
		cout<<endl;	
		m++;
				cout<<" Daftar member ke : "<<m+1<<endl;
				cout<<" Kode member \t\t\t:";scanf("%d%c", &brgmemb[m].kodmemb, &temp);
				cout<<" Nama  pt  \t\t\t:";
				fflush(stdin);
				getline(cin,brgmemb[m].ptmemb);
				cout<<" Nama  perwakilan pt \t\t:";getline(cin,brgmemb[m].namemb);
				cout<<" Alamat Penyewa \t\t:";getline(cin, brgmemb[m].almemb);
				cout<<" Kontak Penyewa \t\t:";getline(cin, brgmemb[m].notelpmemb);
				
				cout<<" Apakah Anda Ingin Menambahkan Data Lagi ? (y/n) :";cin>>yn;
			if(yn=='y'||yn=='Y'){
				dafmemb();
			}else{
				cout << "\n\n Data Berhasil Disimpan \n" << endl;
				system("pause");
				system("cls");
				menmemb();
			}
}

void vmemb(){
	system ("cls");
	
	cout<<"\n"<<endl;
		cout << "\t ----------------------------------------------- "<<endl;
		cout<<	"\t\t\tDaftar Member      			   "<<endl;//input barang berdasarkan jumlah  barang yang mau di input
    	cout << "\t ----------------------------------------------- "<<endl;
		cout<<endl;
		cout<<"|------------------------------------------------------------------------------------------------------------|\n";
		cout<<"|  No    Kode Member           Nama PT         Nama Perwakilan PT       Kontak Member       Alamat Member    |\n";
		cout<<"|------------------------------------------------------------------------------------------------------------|\n";
		for(i=0; i<=m;i++){
			cout<<"| "<<setw(2)<<i+1<<setw(11)<<brgmemb[i].kodmemb<<setw(22)<<brgmemb[i].ptmemb<<setw(20)<<brgmemb[i].namemb<<setw(27)<<brgmemb[i].notelpmemb<<setw(20)<<brgmemb[i].almemb<<"     |";
			cout<<endl;
	}
	{
	system("pause");
	system("cls");
	menmemb();	}
}

void pinmemb(){
	p++;
	system("cls");
	cout<<"\n"<<endl;
	cout << "\t ------------------------------------------------ "<<endl;
	cout<<	"\t      Transaksi Peminjaman  khusus member   		 "<<endl;//input barang berdasarkan jumlah  barang yang mau di input
    cout << "\t ------------------------------------------------ "<<endl;
	cout<<endl;
	cout<<" Kode Pinjaman \t\t\t: ";scanf("%d%c", &pmemb[p].kopinj, &temp);
	cout<<" Kode Member \t\t\t: ";scanf("%d%c", &pmemb[p].km, &temp);
	cout<<" Kode Barang \t\t\t: ";scanf("%d%c", &pmemb[p].kb, &temp);
	
	for(c=0;c<=b;c++){
	if(barang[c].kodeB == pmemb[p].kb){
	cout<<" Nama Barang \t\t\t: "<<barang[c].Nama<<endl;
	for(i=0; i<=m;i++){
	if(brgmemb[i].kodmemb == pmemb[p].km){
	cout<<" Nama PT \t\t\t: "<<brgmemb[i].ptmemb<<endl;
	cout<<" Nama Perwakilan PT \t\t: "<<brgmemb[i].namemb<<endl;
		cout<<" Kontak Member \t\t\t: "<<brgmemb[i].notelpmemb<<endl;
		cout<<" Alamat Member \t\t\t: "<<brgmemb[i].almemb<<endl;	
				cout<<" Tanggal Pinjam (DDMMYYYY)\t: ";scanf("%d%c", &pmemb[p].tpin, &temp);
				cout<<" Tanggal Balik (DDMMYYYY)\t: ";scanf("%d%c", &pmemb[p].tbalik, &temp);
				lama = (pmemb[p].tbalik-pmemb[p].tpin)/1000000;
				cout<<" Lama Pinjaman \t\t\t: "<<lama<<" Hari"<<endl;
				cout<<" banyak barang yang di pinjam  \t: ";scanf("%d%c", &pmemb[p].dp, &temp);
				if(pmemb[r].dp>stok){
					cout<<"Stok Barang tidak cukup, tidak bisa melakukan peminjaman"<<endl;
					p--;
					pmemb[r].dp=0;
					system("pause");
					system("cls");
					menupnj();
					}else{		
				discmem = (pmemb[p].dp*barang[p].sewa)*0.2;
				hsmem = (pmemb[p].dp*barang[p].sewa)- discmem;
				cout<<" Harga Sewa \t\t\t: "<<hsmem;
				cout<<endl;
				cout<<" Status dipinjam (y) ? \t\t: ";cin>>pmemb[p].statp;
				cout<<endl;}
			} else if (brgmemb[i].kodmemb != pmemb[p].km){
						cout<<"\n Data Member Tidak Ditemukan \n";
						system("pause");
						system("cls");
						menmemb();}
			
		}	} else if (barang[c].kodeB != pmemb[p].kb){
						cout<<"\n Data BARANG Tidak Ditemukan \n";
						system("pause");
						system("cls");
						menmemb();}	
						
			cout<<"Apakah Anda Ingin Menambahkan Data Lagi ? (y/n) :";cin>>yn;
			if(yn=='y'||yn=='Y'){
				pinmemb();
			}else{
				cout << "\n\n Data Berhasil Disimpan \n" << endl;
				system("pause");
				system("cls");
				menmemb();}
			}}
				
				
void blkm(){
	system("cls");
	cout<<"\n"<<endl;	
		cout << "\t ------------------------------------------------ "<<endl;
		cout<<	"\t\t\tTransaksi Pengembalian    			   "<<endl;//input barang berdasarkan jumlah  barang yang mau di input
    	cout << "\t ------------------------------------------------ "<<endl;
			cout<<"\t\t\tMasukan kode Peminjaman :";cin>>kpm; //memasukan kode peminjaman 
			cout<<"\t\t\t\n"<<endl;
			cout<<endl;
			for(r=0;r<=p;r++){ 
				if(pmemb[r].kopinj==kpm){
					cout<<" Nama pt penyewa \t\t:"<<brgmemb[r].ptmemb;
					cout<<endl;
						cout<<" Nama perwakilan penyewa \t:"<<brgmemb[r].namemb;
					cout<<endl;
					cout<<" Alamat Penyewa \t\t:"<<brgmemb[r].almemb;
					cout<<endl;
					cout<<" Kontak Penyewa \t\t:"<<brgmemb[r].notelpmemb;
					cout<<endl;
					if(barang[r].kodeB==pmemb[r].kb){
						cout<<" Nama barang \t\t\t:"<<barang[r].Nama<<endl;
					}
					cout<<" Tanggal Pinjam (DDMMYYYY)\t:"<<pmemb[r].tpin;
					cout<<endl;
					cout<<" Tanggal Balik (DDMMYYYY)\t:";scanf("%d%c", &pmemb[r].tbl, &temp);
					cout<<endl;
					lampin = (pmemb[r].tbl-pmemb[r].tpin)/1000000;
					cout<<" Lama Pinjaman \t\t\t:"<<lampin<<" Hari"<<endl;
					cout<<endl;
					if (lampin > lama){
					cout<<" Anda Telat      \t\t:"<<lampin-lama<<" Hari"<<endl;
					denda = (lampin-lama)*10000;
					cout<<" Dikenakan denda  \t\t:Rp"<<denda<<endl;}
					else {					
					denda=0;}
					cout<<" banyak barang yang di pinjam  \t:"<<pmemb[r].dp;
					cout<<endl;	
					discmem = (pmemb[r].dp*barang[r].sewa)*0.2;
					hsmem = ((pmemb[r].dp*barang[r].sewa)-discmem)+denda;
					cout<<" Harga Sewa \t\t\t:"<<hsmem;
					cout<<endl;
				
					cout<<" Status dibalik (b) ? \t\t:";cin>>pmemb[r].statp;
					cout<<endl;
					if((pmemb[r].statp == 'b') || (pmemb[r].statp == 'B')){
						cout<<" (di Pinjam) "<<endl;
					}else{
						cout<<" (di kembalikan) "<<endl;
					}
					cout<<endl;
					cout<<" Sudah di kembalikan ? (y/n) : ";cin>>yb;
					if((yb == 'b') || (yb == 'B')){
						cout<<" ganti status ( input n ) :";
						cin>>pmemb[r].statp;
						cout << "\n\n Data Berhasil Disimpan \n" << endl;
						system("pause");
						system("cls");
						menmemb();
					}else{
						cout << "\n\n Data Berhasil Disimpan \n" << endl;
						system("pause");
						system("cls");
						menmemb();
					}
				}else{
					cout << "\n\n Data Tidak Di temukan \n" << endl;
					cout<<" Apakah ingin mengulang kembali ? (y/n) : ";cin>>yn;
					if(yn == 'Y' || yn == 'y'){
						system("cls");
						blkm();	
					}else{
						system("cls");
						menu();	}
				}
			}
}
		
void hapusmember(){
int khm;
	 system ("cls");
  cout<<"\n PENGHAPUSAN DATA MEMBER\n";
  cout<<" __\n\n";
  
  cout<<" Masukan Kode  Member : "; cin>>khm;
     cout<<endl;
	for(i=0; i<=m;i++){
	if(brgmemb[i].kodmemb  == khm){
		for(k=i;k<m+1;k++){
			brgmemb[k]=brgmemb[k+1];
		}
		cout<<" DATA BERHASIL DI HAPUS\n\n";
		m--;
	}	
}
	{
		cout<<endl;
		system("pause");
		system("cls");
		menmemb();}			
}


void edm(){
int kem;

system ("cls");
  cout<<"\n PENGEDITAN DATA MEMBER\n";
  cout<<" __\n\n";
  
  cout<<" masukan kode  member : "; cin>>kem;
     cout<<endl;
	for(i=0; i<=m;i++){
	if(brgmemb[i].kodmemb  == kem){
	
cout<<" Nama PT \t\t\t: "<<brgmemb[i].ptmemb<<endl;
		cout<<" Nama Perwakilan PT \t\t: "<<brgmemb[i].namemb<<endl;
		cout<<" Alamat Member \t\t\t: "<<brgmemb[i].almemb<<endl;
		cout<<" Kontak Member \t\t\t: "<<brgmemb[i].notelpmemb<<endl;	
	
	for(v=i;v<=i;v++){
		cout<<"=====================\n\n";
		cout<<" Nama  PT  \t\t\t:";
				fflush(stdin);
				getline(cin,brgmemb[v].ptmemb);
				cout<<" Nama  perwakilan PT \t\t:";getline(cin,brgmemb[v].namemb);
				cout<<" Alamat Member \t\t\t:";getline(cin, brgmemb[v].almemb);
				cout<<" Kontak Member \t\t\t:";getline(cin, brgmemb[v].notelpmemb);				
		}
	cout<<" DATA BERHASIL DIEDIT\n\n";
	}
}
	{
		cout<<endl;
		system("pause");
		system("cls");
		menmemb();
	}
}


void vpm(){
	system("cls");
	q++;
			cout<<"\n"<<endl;	
			cout<<"\t ------------------------------------------------ "<<endl;
			cout<<"\t\t\tlaporan peminjaman \n"; 
			cout<<"\t ------------------------------------------------ "<<endl;
			cout<<"\t\t\t\n"<<endl;
			cout<<"|-------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
			cout<<"|  No    Kode Peminjaman       Nama barang       Nama Peminjam            Alamat         Tanggal Pinjam        Tanggal Balik          Status            Qty   |\n";
			cout<<"|-------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
		for(q=0;q<=p;q++){ 
				if(pmemb[q].kb==barang[q].kodeB){
				cout<<"| "<<setw(2)<<q+1<<setw(11)<<pmemb[q].kopinj<<setw(25)<<barang[q].Nama<<setw(17)<<brgmemb[q].namemb
					<<setw(25)<<brgmemb[q].almemb<<setw(18)<<pmemb[q].tpin<<setw(22)<<pmemb[q].tbalik
					<<setw(10)<<pmemb[q].statp;
					
					if((pmemb[q].statp == 'y') || (pmemb[q].statp == 'Y')){
						cout<<" (borrowed) ";
					}else{
						cout<<" (returned) ";
					}
					cout<<setw(9)<<pmemb[q].dp<<"     |";	
					cout<<endl;
}	

}
system("pause");
		system("cls");
		menmemb();
}
					
int main(){
	login();
	menu(); //mulai menu
}
