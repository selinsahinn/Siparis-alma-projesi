// siparis olusturma.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>         //standart giris-cikis fonksiyonlarinin kutuphanesi
#include <windows.h>        //windows kutuphanesi
#include <fstream>          //dosya fonksiyonlarinin kutuphanesi
#include <stdio.h>          //standart giris cikis kutuphanesi
#include <string>           //string kutuphanesi
#include <iomanip>          //matematiksel islem kutuphanesi
#include <cstdio>           //c giris cikis kutuphanesi

using namespace std;            //standart isim uzayi

bool urun_kontrol(int urunKodu);    //urun kontrol anahtar fonksiyonu
bool firma_kontrol(int firmaNo);    //firma kontrol anahtar fonksiyonu
bool musteri_kontrol(int musteriNo);    //musteri kontrol anahtar fonksiyonu
bool siparis_kontrol(int siparisNo);    //siparis kontrol anahtar fonksiyonu

void urun_ekle();       //urun ekleme fonksiyonu
void urun_ara(int urunKodu);    //urun arama fonksiyonu
void urun_listele();    //urun listeleme fonksiyonu
void urun_duzelt(int urunKodu);     //urun duzeltme fonksiyonu
void urun_sil(int urunKodu);        //urun silme fonksiyonu

void musteri_ekle();       //musteri ekleme fonksiyonu
void musteri_ara(int musteriTc);    //musteri arama fonksiyonu
void musteri_duzelt(int musteriTc); //musteri duzeltme fonksiyonu
void musteri_sil(int musteriTc);    //msuteri silme fonksiyonu

void siparis_olustur(int siparisNo);    //siparis olusturma fonksiyonu
void siparis_ara(int siparisNo);        //siparis arama fonksiyonu
void siparis_sil(int siparisNo);        //siparis silme fonksiyonu
void siparis_duzelt(int siparisNo);     //siparis duzeltme fonksiyonu
void siparis_raporla();         //siparis raporlama fonksiyonu

int secim;  //secim adli tamsayi degiskeni tanimlandi

struct bilgiGirisi  //degiskenler yapi icerisinde tanimlandi
{
    string urunAdi, uretici, teminSuresi, uretimTarihi;     //string degiskenler tanimlandi
    int fiyatOzel, fiyatGenel, kdv, stok, siparisAdedi;     //tamsayi degiskenler tanimlandi
    string firmaAdi, firmaTel, firmaSorumlusu, musteriAd, musteriKategorisi, musteriOzel, musteriGenel, adres;     //string degiskenler tanimlandi
    string siparisTarihi, siparisiAlan;     //string degiskenler tanimlandi
    float siparisTutari;    //ondalik sayili degisken tanimlandi
    int urunKodu, firmaNo, musteriNo, siparisNo, musteriTc;     //tamsayi degiskenler tanimlandi
}urun;      //referans


void menu()     //menu fonksiyonu
{
    int firmaNo;    //firma numarasi tamsayisi tanimlandi   
    int urunKodu;   //urun kodu tamsayisi tanimlandi
    int musteriTc;  //musteri tc tamsayisi tanimlandi
    int siparisNo;  //siparis numarasi tamsayisi tanimlandi
    cout << "*********YAPILABILECEK ISLEMLER*********\n";     //ekrana yazdirir
    cout << "1) Urun ekleme" << endl;               //ekrana yazdirir
    cout << "2) Urun arama" << endl;                //ekrana yazdirir
    cout << "3) Urun listeleme" << endl;            //ekrana yazdirir
    cout << "4) Urun duzeltme" << endl;             //ekrana yazdirir
    cout << "5) Urun silme" << endl;                //ekrana yazdirir
    cout << "6) Musteri ekleme" << endl;            //ekrana yazdirir
    cout << "7) Musteri arama" << endl;             //ekrana yazdirir
    cout << "8) Musteri duzeltme" << endl;          //ekrana yazdirir
    cout << "9) Musteri silme" << endl;             //ekrana yazdirir
    cout << "10) Siparis olustur" << endl;          //ekrana yazdirir
    cout << "11) Siparis arama" << endl;            //ekrana yazdirir
    cout << "12) Siparis silme" << endl;            //ekrana yazdirir
    cout << "13) Siparis duzeltme" << endl;         //ekrana yazdirir
    cout << "14) Siparis raporlama" << endl;       //ekrana yazdirir
    cout << "15) Cikis" << endl;                    //ekrana yazdirir 
    cout << "****************************************\n";   //ekrana yazdirir
    cout << "Seciminiz: ";                          //ekrana yazdirir
    cin >> secim;       //secim degiskenini kullanicidan alir
    cout << "Yapacaginiz islem : ";     //konsola yazdirir

    switch (secim)      //secim degiskeninin degerine gore nasýl davranacagini belirtir
    {
    case 1:     //secim degiskeni 1 ise
        urun_ekle();    // urun ekle fonksiyonunu cagirir
        break;      //case'i kirar
    case 2:     //secim degiskeni 2 ise
        cout << "Urun arama \n Urun Kodu: "; cin >> urunKodu;   //kullanidan urun kodunu alir
        urun_ara(urunKodu);    // urun ara fonksiyonunu cagirir
        break;      //case'i kirar
    case 3:     //secim degiskeni 3 ise
        urun_listele();    // urun listele fonksiyonunu cagirir
        break;      //case'i kirar
    case 4:     //secim degiskeni 4 ise
        cout << "Urun duzeltme \n Urun Kodu: "; cin >> urunKodu;    //kullanicidan urun kodunu aldirir
        urun_duzelt(urunKodu);    // urun duzelt fonksiyonunu cagirir
        break;      //case'i kirar
    case 5:     //secim degiskeni 5 ise
        cout << "Urun silme \n Urun Kodu: "; cin >> urunKodu;    //kullanicidan urun kodunu aldirir
        urun_sil(urunKodu);     //urun sil fonksiyonunu cagirir
        break;      //case'i kirar
    case 6:     //secim degiskeni 6 ise
        musteri_ekle();         //musteri ekle fonksiyonunu cagirir
        break;      //case'i kirar
    case 7:     //secim degiskeni 7 ise
        cout << "Musteri arama \n Musteri TC: "; cin >> musteriTc;      //kullanicidan musteriTC tamsayisini alir
        musteri_ara(musteriTc);         //musteri ara fonksiyonunu cagirir
        break;      //case'i kirar
    case 8:     //secim degiskeni 8 ise
        cout << "Musteri duzeltme \n Musteri TC: "; cin >> musteriTc;      //kullanicidan musteriTC tamsayisini alir
        musteri_duzelt(musteriTc);         //musteri duzelt fonksiyonunu cagirir
        break;      //case'i kirar
    case 9:     //secim degiskeni 9 ise
        cout << "Musteri silme \n Musteri TC: "; cin >> musteriTc;      //kullanicidan musteriTC tamsayisini alir
        musteri_sil(musteriTc);         //musteri sil fonksiyonunu cagirir
        break;      //case'i kirar
    case 10:     //secim degiskeni 10 ise
        cout << "Siparis olusturma \n Siparis no: "; cin >> siparisNo;      //kullanicidan siparisNo tamsayisini alir
        siparis_olustur(siparisNo);         //siparis olustur fonksiyonunu cagirir
        break;      //case'i kirar
    case 11:     //secim degiskeni 11 ise
        cout << "Siparis arama \n Siparis no: "; cin >> siparisNo;      //kullanicidan siparisNo tamsayisini alir
        siparis_ara(siparisNo);         //siparis ara fonksiyonunu cagirir
        break;      //case'i kirar
    case 12:     //secim degiskeni 12 ise
        cout << "Siparis silme \n Siparis no: "; cin >> siparisNo;      //kullanicidan siparisNo tamsayisini alir
        siparis_sil(siparisNo);         //siparis sil fonksiyonunu cagirir
        break;      //case'i kirar
    case 13:     //secim degiskeni 13 ise
        cout << "Siparis duzeltme \n Siparis no: "; cin >> siparisNo;      //kullanicidan siparisNo tamsayisini alir
        siparis_duzelt(siparisNo);         //siparis duzelt fonksiyonunu cagirir
        break;      //case'i kirar
    case 14:     //secim degiskeni 14 ise
        siparis_raporla();         //siparis raporla fonksiyonunu cagirir
        break;      //case'i kirar
    case 15:     //secim degiskeni 15 ise
        cout << "Programdan cikmak icin bir tusa basiniz..." << endl;   //konsola yazdirir
        break;      //case'i kirar

    default:        //diger case'ler calismazsa buraya girer
        cout << "Hatali bir islem secitiniz. Lutfen tekrar deneyin!\a" << endl; //konsola yazdirir
        break;      //default'u kirar
    }
}

bool urun_kontrol(int urunKodu) //urun kontrol anahtar fonksiyonu olusturuldu
{
    bool kontrol = 0;       //kontrol adli anahtar degiskeni 0'sa
    ifstream dosyaOku;      //dosyaya giris icin dosyaOku degiskeni
    dosyaOku.open("urun.txt");  //urun dosyasini dosyaOku seklinde acar

    while (!dosyaOku.eof())     //dosyanin basindan sonuna kadar gezdigi surece
    {
        dosyaOku >> urun.urunKodu >> urun.urunAdi >> urun.uretici >> urun.teminSuresi >> urun.uretimTarihi >> urun.fiyatGenel >> urun.fiyatOzel >> urun.kdv >> urun.stok;   //urun referansli degiskenleri dosyadan okur
        if (urun.urunKodu == urunKodu)  //eger urun referanslý urun kodu, urun koduna esitse
        {
            kontrol = 1;        //kontrol degiskenini 1 yapar
        }
    }
    return kontrol;     //kontrol degiskenini dondurur
}

bool firma_kontrol(int firmaNo) //firma kontrol anahtar fonksiyonu olusturuldu
{
    bool kontrol = 0;       //kontrol adli anahtar degiskeni 0'sa
    ifstream dosyaOku;      //dosyaya giris icin dosyaOku degiskeni
    dosyaOku.open("firma.txt");  //firma dosyasini dosyaOku seklinde acar

    while (!dosyaOku.eof())     //dosyanin basindan sonuna kadar gezdigi surece
    {
        dosyaOku >> urun.firmaNo >> urun.firmaAdi >> urun.firmaTel >> urun.firmaSorumlusu >> urun.musteriOzel >> urun.musteriGenel >> urun.adres;   //urun referansli degiskenleri dosyadan okur

        if (urun.firmaNo == firmaNo)  //eger urun referanslý firma kodu, firma koduna esitse
        {
            kontrol = 1;        //kontrol degiskenini 1 yapar
        }
    }
    return kontrol;     //kontrol degiskenini dondurur
}

bool musteri_kontrol(int musteriTc) //musteri kontrol anahtar fonksiyonu olusturuldu
{
    bool kontrol = 0;       //kontrol adli anahtar degiskeni 0'sa
    ifstream dosyaOku;      //dosyaya giris icin dosyaOku degiskeni
    dosyaOku.open("cari.txt");  //cari dosyasini dosyaOku seklinde acar

    while (!dosyaOku.eof())     //dosyanin basindan sonuna kadar gezdigi surece
    {
        dosyaOku >> urun.musteriTc >> urun.musteriAd >> urun.musteriKategorisi >> urun.adres;   //urun referansli degiskenleri dosyadan okur

        if (urun.musteriTc == musteriTc)  //eger urun referanslý musteri tc, musteri tc'ye esitse
        {
            kontrol = 1;        //kontrol degiskenini 1 yapar
        }
    }
    return kontrol;     //kontrol degiskenini dondurur
}

bool siparis_kontrol(int siparisNo) //siparis kontrol anahtar fonksiyonu olusturuldu
{
    bool kontrol = 0;       //kontrol adli anahtar degiskeni 0'sa
    ifstream dosyaOku;      //dosyaya giris icin dosyaOku degiskeni
    dosyaOku.open("siparis.txt");  //siparis dosyasini dosyaOku seklinde acar

    while (!dosyaOku.eof())     //dosyanin basindan sonuna kadar gezdigi surece
    {
        dosyaOku >> urun.siparisNo >> urun.urunKodu >> urun.siparisAdedi >> urun.siparisTarihi >> urun.siparisiAlan >> urun.urunAdi >> urun.uretici >>
            urun.teminSuresi >> urun.uretimTarihi >> urun.fiyatOzel >> urun.fiyatGenel >> urun.kdv >> urun.stok >> urun.siparisTutari;   //urun referansli degiskenleri dosyadan okur

        if (urun.siparisNo == siparisNo)  //eger urun referanslý siparis no, siparis no'ya koduna esitse
        {
            kontrol = 1;        //kontrol degiskenini 1 yapar
        }
    }
    return kontrol;     //kontrol degiskenini dondurur
}

void urun_ekle()        //urun ekle fonksiyonu
{
    int urunKodu;       //urunKodu tamsayisi tanimlandi
    ofstream dosyaYaz;      //dosyaya yazma fonksiyonu
    dosyaYaz.open("urun.txt", ios::app);        //urun.txt dosya yaz seklinde acilir
    cout << "Urun ekle \n Urun Kodu.....:"; cin >> urunKodu;    //urun kodu kullanicidan istenir

    if (urun_kontrol(urunKodu) == 1)    //urun kontrol anahtari dogru ise
    {
        cout << "Bu koda sahip urun bulunmaktadir.\n\a";        //konsola yazdirir
    }
    else    //if sarti saglanmazsa buraya girer
    {
        urun.urunKodu = urunKodu;   //urun referansli urun kodu, urun koduna esittir
        cout << "Urun kodu        : "; cin >> urun.urunKodu;    //kullanicidan ister
        cout << "Urun adi         : "; cin >> urun.urunAdi;    //kullanicidan ister
        cout << "Ureticisi        : "; cin >> urun.uretici;    //kullanicidan ister
        cout << "Temin suresi     : "; cin >> urun.teminSuresi;    //kullanicidan ister
        cout << "Uretim tarihi    : "; cin >> urun.uretimTarihi;    //kullanicidan ister
        cout << "Ozel fiyat       : "; cin >> urun.fiyatOzel;    //kullanicidan ister
        cout << "Genel fiyat      : "; cin >> urun.fiyatGenel;    //kullanicidan ister
        cout << "KDV orani        : "; cin >> urun.kdv;    //kullanicidan ister
        cout << "Stok adedi       : "; cin >> urun.stok;    //kullanicidan ister
        dosyaYaz << urun.urunKodu << "\t" << urun.urunAdi << "\t" << urun.uretici << "\t" << urun.teminSuresi << "\t" << urun.uretimTarihi <<
            "\t" << urun.fiyatOzel << "\t" << urun.fiyatGenel << "\t" << urun.kdv << "\t" << urun.stok << "\n"; //urun referansli degiskenleri dosyaya yazdirir
        cout << "Urun eklenmistir!\n";  //konsola yazdirir
    }
    dosyaYaz.close();       //dosyayi kapatir
}

void urun_ara(int urunKodu) //urun ara fonksiyonu
{
    ifstream dosyaOku;      //dosyaya giris icin dosyaOku degiskeni
    dosyaOku.open("urun.txt");        //urun.txt dosya oku seklinde acilir

    if (urun_kontrol(urun.urunKodu) == 0)   //urun kontrol anahtari 0 ise
    {
        cout << "Urun bulunamamistir.\n";   //konsola yazdirir
    }
    else        //if sarti saglanmaz ise buraya girer
    {
        if (urun_kontrol(urunKodu) == 1)    //urun kontrol anahtari 1 ise
        {
            while (!dosyaOku.eof()) //dosyanin icerigi bitene kadar gezer
            {
                dosyaOku >> urun.urunKodu >> urun.urunAdi >> urun.uretici >> urun.teminSuresi >> urun.uretimTarihi >> urun.fiyatOzel >>
                    urun.fiyatGenel >> urun.kdv >> urun.stok;       //urun referansli degiskenleri dosyadan okur
                if (urun.urunKodu == urunKodu)      //urun referansli urun kodu, urun koduna esitse
                {
                    cout << "Urun kodu        : " << urun.urunKodu << endl;     //ekrana yazdirir
                    cout << "Urun adi         : " << urun.urunAdi << endl;     //ekrana yazdirir
                    cout << "Ureticisi        : " << urun.uretici << endl;     //ekrana yazdirir
                    cout << "Temin suresi     : " << urun.teminSuresi << endl;     //ekrana yazdirir
                    cout << "Uretim tarihi    : " << urun.uretimTarihi << endl;     //ekrana yazdirir
                    cout << "Ozel fiyat       : " << urun.fiyatOzel << endl;     //ekrana yazdirir
                    cout << "Genel fiyat      : " << urun.fiyatGenel << endl;     //ekrana yazdirir
                    cout << "KDV orani        : " << urun.kdv << endl;     //ekrana yazdirir
                    cout << "Stok adedi       : " << urun.stok << endl;     //ekrana yazdirir
                    exit(1);        //cikis yapar
                }
            }
        }
        else    //if sarti saglanmaz ise
        {
            cout << "Urun bulunamadi.\n\a";     //konsola yazdirir
        }
    }
    dosyaOku.close();       //dosya okuma islevi kapatilir
}

void urun_listele()     //urun listele fonksiyonu
{
    ifstream dosyaOku;      //dosyaya giris icin dosya oku fonksiyonu
    dosyaOku.open("urun.txt");  //urun dosyasi dosya okuma seklinde acildi

    cout << "\nUrun kodu-" << "-Urun adi-" << "-Uretici-" << "-Temin s.-" << "-U.tarihi-" << "-G.fiyat-" << "-O.fiyat-" << "-KDV o.-" << "-Stok adedi\n"; //konsola yazdirma
    while (true)    //surekli buraya girer
    {
        dosyaOku >> urun.urunKodu >> urun.urunAdi >> urun.uretici >> urun.teminSuresi >> urun.uretimTarihi >> urun.fiyatGenel >> urun.fiyatOzel >> urun.kdv >> urun.stok;   //dosyadan urun referansli degiskenleri okur
        if (dosyaOku.eof()) //dosyanin sonuna geldiyse kir
            break;  //donguyu kirar
        cout << "\t" << urun.urunKodu << "\t" << urun.urunAdi << "\t" << urun.uretici << "\t" << urun.teminSuresi << "\t" << urun.uretimTarihi <<
            "\t\t" << urun.fiyatGenel << "\t" << urun.fiyatOzel << "\t" << urun.kdv << "\t" << urun.stok << "\n";   //ekrana yazdirir
    }
    dosyaOku.close();       //dosya okuma islevi kapanir
}

void urun_duzelt(int urunKodu)      //urun duzelt fonksiyonu
{
    ifstream dosyaOku;  //dosya okumaya yarar
    ofstream dosyaYaz;  //dosya yazmaya yarar
    dosyaOku.open("urun.txt");  //dosyayi okuma biciminde acar
    dosyaYaz.open("urun_duzelt.txt", ios::app); //dosyayi yazma biciminde acar

    bool kontrol = 0;       //kontrol anahtari 0 

    if (urun_kontrol(urunKodu) == 0)    //urun kontrol anahtari 0 ise
    {
        cout << "Urun bulunamadi. Urun kaydi olusturunuz; \n";  //konsola yazdirma
        urun_ekle();    //urun ekle fonksiyonu cagrilir
    }
    else    //if sarti saglanmaz ise
    {
        kontrol = 1;        //kontrol 1dir
        while (true)    //surekli buraya girer
        {
            dosyaOku >> urun.urunKodu >> urun.urunAdi >> urun.uretici >> urun.teminSuresi >> urun.uretimTarihi >> urun.fiyatOzel >> urun.fiyatGenel >> urun.kdv >> urun.stok;
            //dosyadan urun referansli degiskenleri okur
            if (urun.urunKodu == urunKodu)      //urun referansli urun kodu, urun koduna esitse
            {
                cout << "Urun kodu: " << urun.urunKodu << "\nUrun adi: " << urun.urunAdi << "\nUreticisi: " << urun.uretici
                    << "\nTemin suresi: " << urun.teminSuresi << "\nUretim tarihi: " << urun.uretimTarihi << "\nOzel fiyat: " << urun.fiyatOzel
                    << "\nGenel fiyat: " << urun.fiyatGenel << "\nKDV orani: " << urun.kdv << "\nStok adeti: " << urun.stok;    //konsola yazdirir
                cout << "\n---------------------------------------------";    //konsola yazdirir
                cout << "\nUrun kodu        : "; cin >> urun.urunKodu;    //konsola yazdirir
                cout << "Urun adi         : "; cin >> urun.urunAdi;    //konsola yazdirir
                cout << "Ureticisi        : "; cin >> urun.uretici;    //konsola yazdirir
                cout << "Temin suresi     : "; cin >> urun.teminSuresi;    //konsola yazdirir
                cout << "Uretim tarihi    : "; cin >> urun.uretimTarihi;    //konsola yazdirir
                cout << "Ozel fiyat       : "; cin >> urun.fiyatOzel;    //konsola yazdirir
                cout << "Genel fiyat      : "; cin >> urun.fiyatGenel;    //konsola yazdirir
                cout << "KDV orani        : "; cin >> urun.kdv;    //konsola yazdirir
                cout << "Stok adedi       : "; cin >> urun.stok;    //konsola yazdirir
                if (dosyaOku.eof()) break;  //dosyanin icerigi bitene kadar gezer sonra kirar
                dosyaYaz << urun.urunKodu << "\t" << urun.urunAdi << "\t" << urun.uretici << "\t" << urun.teminSuresi << "\t" <<
                    urun.uretimTarihi << "\t" << urun.fiyatOzel << "\t" << urun.fiyatGenel << "\t" << urun.kdv << "\t" << urun.stok << "\n";    //dosyaya yazdirma komutu
            }
            else    //if sarti saglanmaz ise
            {
                if (dosyaOku.eof()) break;    //dosyanin icerigi bitene kadar gezer sonra kirar
                dosyaYaz << urun.urunKodu << "\t" << urun.urunAdi << "\t" << urun.uretici << "\t" << urun.teminSuresi << "\t" <<
                    urun.uretimTarihi << "\t" << urun.fiyatOzel << "\t" << urun.fiyatGenel << "\t" << urun.kdv << "\t" << urun.stok << "\n";    //dosyaya yazdirma komutu
            }
        }
        dosyaOku.close();   //dosya okuma kapatilir
        dosyaYaz.close();   //dosya yazma kapatilir(hafizada yer tutmamasi icin)

        if (kontrol == 1)   //kontrol 1 ise
        {
            remove("urun.txt"); //urun dosyasi silinir
            rename("urun_duzelt.txt", "urun.txt");  //dosyalar degisir
            cout << "Urun bilgileri guncellenmistir!\n";    //konsola yazdirma
        }
        else    //if sarti saglanmaz ise
        {
            remove("urun_duzelt.txt");  //urun duzeltme dosyasi silinir
        }
    }
}

void urun_sil(int urunKodu)     //urun sil fonksiyonu
{
    ifstream dosyaOku;  //dosya okumaya yarar
    ofstream dosyaYaz;  //dosya yazmaya yarar
    dosyaOku.open("urun.txt");  //dosyayi okuma biciminde acar
    dosyaYaz.open("urun_sil.txt", ios::app); //dosyayi yazma biciminde acar

    bool kontrol = 0;       //kontrol anahtari 0 

    if (urun_kontrol(urunKodu) == 0)    //urun kontrol anahtari 0 ise
    {
        cout << "Bu koda sahip urun bulunmamamaktadir.\n\a";  //konsola yazdirma ve uyari sesi verme
    }
    else    //if sarti saglanmaz ise
    {
        kontrol = 1;        //kontrol 1dir
        while (true)    //surekli buraya girer
        {
            dosyaOku >> urun.urunKodu >> urun.urunAdi >> urun.uretici >> urun.teminSuresi >> urun.uretimTarihi >> urun.fiyatGenel >> urun.fiyatOzel >> urun.kdv >> urun.stok;
            //dosyadan urun referansli degiskenleri okur
            if (urun.urunKodu != urunKodu)      //urun referansli urun kodu, urun koduna esit degilse
            {
                if (dosyaOku.eof()) break;    //dosyanin icerigi bitene kadar gezer sonra kirar
                dosyaYaz << urun.urunKodu << "\t" << urun.urunAdi << "\t" << urun.uretici << "\t" << urun.teminSuresi << "\t" << urun.uretimTarihi << "\t"
                    << urun.fiyatOzel << "\t" << urun.fiyatGenel << "\t" << urun.kdv << "\t" << urun.stok << "\n";    //dosyaya yazdirma komutu
            }
        }
    }
    dosyaOku.close();   //dosya okuma kapatilir
    dosyaYaz.close();   //dosya yazma kapatilir(hafizada yer tutmamasi icin)

    if (kontrol == 1)   //kontrol 1 ise
    {
        remove("urun.txt");     //dosyayi siler
        rename("urun_sil.txt", "urun.txt"); //dosyalari degistirir
        cout << "Urun silinmistir.\n";    //konsola yazdirma
    }
    else    //if sarti saglanmaz ise
    {
        remove("urun_sil.txt");  //urun silme dosyasi silinir
    }
}

void musteri_ekle()     //musteri ekle fonksiyonu
{
    int musteriTc;      //musteriTc tamsaysisi tanimlandi
    ofstream dosyaYaz;      //dosyaya yazma fonksiyonu
    dosyaYaz.open("cari.txt", ios::app);        //cari.txt dosya yaz seklinde acilir
    cout << "Musteri ekle \n Musteri Tc No:....: "; cin >> musteriTc;   //kullanicidan musteri tc'si istenir

    if (musteri_kontrol(musteriTc) == 1)    //urun kontrol anahtari dogru ise
    {
        cout << "Bu TC kimlik numarasina ait musterimiz bulunmaktadir.\n\a";        //konsola yazdirir
    }
    else    //if sarti saglanmazsa buraya girer
    {
        urun.musteriTc = musteriTc;   //urun referansli musteriTc, musteriTc'ye esittir
        cout << "Musteri TC     : "; cin >> urun.musteriTc;    //kullanicidan ister
        cout << "Musteri ad     : "; cin >> urun.musteriAd;    //kullanicidan ister
        cout << "Musteri kategorisi   : "; cin >> urun.musteriKategorisi;    //kullanicidan ister
        cout << "Musteri adresi       : "; cin >> urun.adres;    //kullanicidan ister
        dosyaYaz << urun.musteriTc << "\t" << urun.musteriAd << "\t" << urun.musteriKategorisi << "\t" << urun.adres << "\n"; //urun referansli degiskenleri dosyaya yazdirir
        cout << "Musteri eklenmistir!\n";  //konsola yazdirir
    }
    dosyaYaz.close();      //dosyayi kapatir
}

void musteri_ara(int musteriTc)     //musteri ara fonksiyonu
{
    ifstream dosyaOku;      //dosyaya giris icin dosyaOku degiskeni
    dosyaOku.open("cari.txt");        //cari.txt dosya oku seklinde acilir

    if (musteri_kontrol(musteriTc) == 0)   //cari kontrol anahtari 0 ise
    {
        cout << "Musteri bulunamamistir.\n";   //konsola yazdirir
    }
    else        //if sarti saglanmaz ise buraya girer
    {
        if (musteri_kontrol(musteriTc) == 1)    //urun kontrol anahtari 1 ise
        {
            while (!dosyaOku.eof()) //dosyanin icerigi bitene kadar gezer
            {
                dosyaOku >> urun.musteriTc >> urun.musteriAd >> urun.musteriKategorisi >> urun.adres;      //urun referansli degiskenleri dosyadan okur
                if (urun.musteriTc == musteriTc)      //urun referansli musteriTc, musteriTc'ye esitse
                {
                    cout << "Musteri TC kimlik no     : " << urun.musteriTc << endl;     //ekrana yazdirir
                    cout << "Musteri adi              : " << urun.musteriAd << endl;     //ekrana yazdirir
                    cout << "Musteri kategorisi       : " << urun.musteriKategorisi << endl;     //ekrana yazdirir
                    cout << "Musteri adresi           : " << urun.adres << endl;     //ekrana yazdirir
                }
            }
        }
        else        //if sarti saglanmaz ise buraya girer
        {
            cout << "Musteri bulunamadi.\n\a";     //ekrana yazdirir
        }
    }
    dosyaOku.close();       //dosya okuma islevi kapatilir
}

void musteri_duzelt(int musteriTc)      //musteri duzelt fonksiyonu
{
    ifstream dosyaOku;  //dosya okumaya yarar
    ofstream dosyaYaz;  //dosya yazmaya yarar
    dosyaOku.open("cari.txt");  //dosyayi okuma biciminde acar
    dosyaYaz.open("cari_duzenle.txt", ios::app); //dosyayi yazma biciminde acar

    bool kontrol = 0;       //kontrol anahtari 0 

    if (musteri_kontrol(musteriTc) == 0)    //urun kontrol anahtari 0 ise
    {
        cout << "Musteri kaydi bulunamadi. Kayit olusturunuz;\n";  //konsola yazdirma
        musteri_ekle();    //musteri ekle fonksiyonu cagrilir
    }
    else    //if sarti saglanmaz ise
    {
        kontrol = 1;      //kontrol 1'dir
        while (true)    //surekli buraya girer
        {
            dosyaOku >> urun.musteriTc >> urun.musteriAd >> urun.musteriKategorisi >> urun.adres;   //dosyadan urun referansli degiskenleri okur
            if (urun.musteriTc == musteriTc)      //urun referansli msuteriTc, musteriTc'ye esitse
            {
                cout << "Musteri TC no: " << urun.musteriTc << "\nMusteri adi: " << urun.musteriAd << "\nMusteri kategorisi: " <<
                    urun.musteriKategorisi << "\nAdres: " << urun.adres << "\n\n\nGuncel Bilgiler;\n";    //konsola yazdirir
                cout << "Musteri Tc no        : "; cin >> urun.musteriTc;    //konsola yazdirir
                cout << "Musteri adi          : "; cin >> urun.musteriAd;    //konsola yazdirir
                cout << "Musteri kategorisi   : "; cin >> urun.musteriKategorisi;    //konsola yazdirir
                cout << "Adresi               : "; cin >> urun.adres;    //konsola yazdirir
                if (dosyaOku.eof()) break;      //en son kaydin 2 kere okunup yazilmamasi icin eklendi
                dosyaYaz << urun.musteriTc << "\t" << urun.musteriAd << "\t" << urun.musteriKategorisi << "\t" << urun.adres << "\n";   //dosyaya yazdirma komutu
            }
            else
            {
                if (dosyaOku.eof()) break;     //en son kaydin 2 kere okunup yazilmamasi icin eklendi
                dosyaYaz << urun.musteriTc << "\t" << urun.musteriAd << "\t" << urun.musteriKategorisi << "\t" << urun.adres << "\n";   //dosyaya yazdirma komutu
            }
        }
        dosyaOku.close();   //dosya okuma kapatilir(hafizada yer tutmamasi icin)
        dosyaYaz.close();   //dosya yazma kapatilir(hafizada yer tutmamasi icin)

        if (kontrol == 1)  //kontrol 1 ise
        {
            remove("cari.txt");         //cari dosyasi silinir
            rename("cari_duzenle.txt", "cari.txt");  //dosyalar degisir
            cout << "Musteri bilgileri guncellenmistir!\n";   //konsola yazdirma
            system("PAUSE");    //programi durdurur
        }
        else   //if sarti saglanmaz ise
        {
            remove("cari_duzenle.txt");     //cari duzeltme dosyasi silinir
        }
    }
}

void musteri_sil(int musteriTc)    //musteri sil fonksiyonu
{
    ifstream dosyaOku;  //dosya okumaya yarar
    ofstream dosyaYaz;  //dosya yazmaya yarar
    dosyaOku.open("cari.txt");  //dosyayi okuma biciminde acar
    dosyaYaz.open("cari_sil.txt", ios::app);     //dosyayi yazma biciminde acar

    bool kontrol = 0;      //kontrol anahtari 0

    if (musteri_kontrol(musteriTc) == 0)   //musteri kontrol anahtari 0 ise
    {
        cout << "Bu TC no'ya ait musteri bulunmamaktadir.\n\a";  //konsola yazdirma ve uyari sesi verme
    }
    else   //if sarti saglanmaz ise
    {
        kontrol = 1;     //kontrol 1dir
        while (true)    //surekli buraya girer
        {
            dosyaOku >> urun.musteriTc >> urun.musteriAd >> urun.musteriKategorisi >> urun.adres;   //dosyadan urun referansli degiskenleri okur
            if (urun.musteriTc != musteriTc)      //urun referansli musteriTc, musteriTc'ye esit degilse
            {
                if (dosyaOku.eof()) { break; }    //dosyanin icerigi bitene kadar gezer sonra kirar
                dosyaYaz << urun.musteriTc << "\t" << urun.musteriAd << "\t" << urun.musteriKategorisi << "\t" << urun.adres << "\n";   //dosyaya yazdirma komutu
            }
        }
    }
    dosyaOku.close();   //dosya okuma kapatilir
    dosyaYaz.close();  //dosya yazma kapatilir

    if (kontrol == 1)   //kontrol 1 ise
    {
        remove("cari.txt");     //dosyayi siler
        rename("cari_sil.txt", "cari.txt"); //dosyalari degistirir
        cout << "Musteri silindi.\n";   //konsola yazdirma
    }
    else   //if sarti saglanmaz ise
    {
        remove("cari_sil.txt");  //cari silme dosyasi silinir
    }
}

void siparis_olustur(int siparisNo)     //siparis olustur fonksiyonu
{
    ifstream dosyaOku;  //dosya okumaya yarar
    ofstream dosyaYaz;  //dosya yazmaya yarar
    dosyaOku.open("urun.txt"); //dosyayi okuma biciminde acar
    dosyaYaz.open("siparis.txt", ios::app); //dosyayi yazma biciminde acar

    cout << "Siparis olusturma\n Urun kodu: "; cin >> urun.urunKodu;    //kullanicidan urun kodunu ister

    if (urun_kontrol(urun.urunKodu) == 0)    //urun kontrol anahtari 0 ise
    {
        cout << "Urun kaydi bulunamadi.Kayit olusturunuz;\n";  //konsola yazdirma ve uyari sesi verme
        urun_ekle();    //urun ekle fonksiyonunu cagirir
    }
    cout << "Siparis no       : "; cin >> urun.siparisNo;   //kullanicidan gereken bilgiyi ister
    cout << "\nUrun kodu      : "; cin >> urun.urunKodu;   //kullanicidan gereken bilgiyi ister
    cout << "\nUrun adedi     : "; cin >> urun.siparisAdedi;   //kullanicidan gereken bilgiyi ister
    cout << "\nSiparis tarihi : "; cin >> urun.siparisTarihi;   //kullanicidan gereken bilgiyi ister
    cout << "\nSiparisi alan  : "; cin >> urun.siparisiAlan;   //kullanicidan gereken bilgiyi ister
    cout << "Urun adi         : " << urun.urunAdi << endl;      //konsola yazdirir
    cout << "Ureticisi        : " << urun.uretici << endl;     //konsola yazdirir
    cout << "Temin suresi     : " << urun.teminSuresi << endl;     //konsola yazdirir
    cout << "Uretim tarihi    : " << urun.uretimTarihi << endl;     //konsola yazdirir
    cout << "Ozel fiyat       : " << urun.fiyatOzel << endl;     //konsola yazdirir
    cout << "Genel fiyat      : " << urun.fiyatGenel << endl;     //konsola yazdirir
    cout << "KDV orani        : " << urun.kdv << endl;     //konsola yazdirir
    cout << "Stok adedi       : " << urun.stok << endl;     //konsola yazdirir

    char cevap;         //cevap karakteri tanimlandi
    cout << "Musteri kategorisini belirtiniz.(Genel->G Ozel->O)\n";     //konsola yazdirir
    cin >> cevap;   //kullanicidan cevap secimini ister
    if (cevap == 'O' || cevap == 'o')   //eger cevap o ise
    {
        urun.siparisTutari = urun.fiyatOzel * urun.siparisAdedi;    //siparis tutari hesaplar
        cout << "\nOzel musteri icin siparis tutari : " << urun.siparisTutari;  //konsola yazdirir
    }
    else if (cevap == 'G' || cevap == 'g')   //eger cevap g ise
    {
        urun.siparisTutari = urun.fiyatGenel * urun.siparisAdedi;    //siparis tutari hesaplar
        cout << "\nGenel musteri icin siparis tutari  : " << urun.siparisTutari;  //konsola yazdirir
    }
    else   //yukaridaki(diger) sartlar saglanmazsa
    {
        cout << "\nLutfen musteri kategorisini belirtmek icin O veya G tuslayiniz.";  //konsola yazdirir
    }
    dosyaYaz << urun.siparisNo << "\t" << urun.urunKodu << "\t" << urun.siparisAdedi << "\t" << urun.siparisTarihi <<
        "\t" << urun.siparisiAlan << "\t" << urun.urunAdi << "\t" << urun.uretici << "\t" << urun.teminSuresi << "\t" <<
        urun.uretimTarihi << "\t" << urun.fiyatOzel << "\t" << urun.fiyatGenel << "\t" << urun.kdv << "\t" << urun.stok << "\t" << urun.siparisTutari << "\n";
    //dosyaya urun referansli veriler yazdirilir
    dosyaYaz.close();   //dosya yazma kapatilir
    dosyaOku.close();   //dosya okuma kapatilir
    cout << endl << "Siparis alinmistir.\n";    //konsola yazdirma
}

void siparis_ara(int siparisNo) //siparis ara fonksiyonu
{
    ifstream dosyaOku;    //dosyaya giris icin dosyaOku degiskeni
    dosyaOku.open("siparis.txt");       //siparis.txt dosya oku seklinde acilir

    if (siparis_kontrol(urun.siparisNo) == 0)   //siparis kontrol anahtari 0 ise
    {
        cout << "Siparis bulunamamistir.\n";  //konsola yazdirir
    }
    else       //if sarti saglanmaz ise buraya girer
    {
        if (siparis_kontrol(siparisNo) == 1)   //siparis kontrol anahtari 1 ise
        {
            while (!dosyaOku.eof()) //dosyanin icerigi bitene kadar gezer
            {
                dosyaOku >> urun.siparisNo >> urun.urunKodu >> urun.siparisAdedi >> urun.siparisTarihi >> urun.siparisiAlan >> urun.urunAdi >>
                    urun.uretici >> urun.teminSuresi >> urun.uretimTarihi >> urun.fiyatOzel >> urun.fiyatGenel >> urun.kdv >> urun.stok >> urun.siparisTutari;
                //urun referansli degiskenleri dosyadan okur
                if (urun.siparisNo == siparisNo)     //urun referansli siparisNo, siparisNo'ya esitse
                {
                    cout << "Siparis no       : " << urun.siparisNo << endl;        //konsola yazdirir
                    cout << "Urun kodu      : " << urun.urunKodu << endl;        //konsola yazdirir
                    cout << "Urun adedi     : " << urun.siparisAdedi << endl;        //konsola yazdirir
                    cout << "Siparis tarihi : " << urun.siparisTarihi << endl;        //konsola yazdirir
                    cout << "Siparisi alan  : " << urun.siparisiAlan << endl;        //konsola yazdirir
                    cout << "Urun adi         : " << urun.urunAdi << endl;        //konsola yazdirir
                    cout << "Ureticisi        : " << urun.uretici << endl;        //konsola yazdirir
                    cout << "Temin suresi     : " << urun.teminSuresi << endl;        //konsola yazdirir
                    cout << "Uretim tarihi    : " << urun.uretimTarihi << endl;        //konsola yazdirir
                    cout << "Ozel fiyat       : " << urun.fiyatOzel << endl;        //konsola yazdirir
                    cout << "Genel fiyat      : " << urun.fiyatGenel << endl;        //konsola yazdirir
                    cout << "KDV orani        : " << urun.kdv << endl;        //konsola yazdirir
                    cout << "Stok adedi       : " << urun.stok << endl;        //konsola yazdirir
                    break;      //donguyu kirar
                }
            }
        }
        else   //if sarti saglanmaz ise
        {
            cout << "Siparis kaydi bulunamadi.\a\n";    //konsola yazdirir
        }
    }
    dosyaOku.close();       //dosya okuma islevi kapatilir
}

void siparis_sil(int siparisNo)     //siparis sil fonksiyonu
{
    ifstream dosyaOku;  //dosya okumaya yarar
    ofstream dosyaYaz;  //dosya yazmaya yarar
    dosyaOku.open("siparis.txt");  //dosyayi okuma biciminde acar
    dosyaYaz.open("sip_sil.txt", ios::app);     //dosyayi yazma biciminde acar
    bool kontrol = 0;       //kontrol anahtari 0

    if (siparis_kontrol(siparisNo) == 0)   //siparis kontrol anahtari 0 ise
    {
        cout << "Siparis bulunamadi.\n\a";  //konsola yazdirma ve uyari sesi verme
    }
    else   //if sarti saglanmaz ise
    {
        kontrol = 1;       //kontrol 1dir
        while (true)   //surekli buraya girer
        {
            dosyaOku >> urun.siparisNo >> urun.urunKodu >> urun.siparisAdedi >> urun.siparisTarihi >> urun.siparisiAlan >>
                urun.urunAdi >> urun.uretici >> urun.teminSuresi >> urun.uretimTarihi >> urun.fiyatOzel >> urun.fiyatGenel >> urun.kdv >> urun.stok >> urun.siparisTutari;
            //dosyadan urun referansli verileri okur
            if (urun.siparisNo != siparisNo)        //urun referansli siparisNo,siparisNo'ya esit degilse
            {
                if (dosyaOku.eof()) break;   //dosyanin icerigi bitene kadar gezer sonra kirar
                dosyaYaz << urun.siparisNo << "\t" << urun.urunKodu << "\t" << urun.siparisAdedi << "\t" << urun.siparisTarihi << "\t" << urun.siparisiAlan << "\t" <<
                    urun.urunAdi << "\t" << urun.uretici << "\t" << urun.teminSuresi << "\t" << urun.uretimTarihi << "\t" << urun.fiyatOzel
                    << "\t" << urun.fiyatGenel << "\t" << urun.kdv << "\t" << urun.stok << "\t" << urun.siparisTutari << "\t";    //dosyaya yazdirma komutu
            }
        }
    }
    dosyaOku.close();   //dosya okuma kapatilir
    dosyaYaz.close();  //dosya yazma kapatilir
    if (kontrol == 1)  //kontrol 1 ise
    {
        remove("siparis.txt");    //dosyayi siler
        rename("sip_sil.txt", "siparis.txt"); //dosyalari degistirir
        cout << "Siparis silinmistir.\n";    //konsola yazdirma
    }
    else   //if sarti saglanmaz ise
    {
        remove("sip_sil.txt"); //urun silme dosyasi silinir
    }
}

void siparis_duzelt(int siparisNo)     //siparis duzelt fonksiyonu
{
    ifstream dosyaOku; //dosya okumaya yarar
    ofstream dosyaYaz;  //dosya yazmaya yarar
    dosyaOku.open("siparis.txt");   //dosyayi okuma biciminde acar
    dosyaYaz.open("siparis_duzelt.txt", ios::app);  //dosyayi yazma biciminde acar

    bool kontrol = 0;    //kontrol anahtari 0

    if (siparis_kontrol(siparisNo) == 0)   //siparis kontrol anahtari 0 ise
    {
        cout << "Bu numaraya ait siparis bulunmamaktadir.\n\n";     //konsola yazdirma
    }
    else    //if sarti saglanmaz ise
    {
        kontrol = 1;    //kontrol 1dir
        while (true)   //surekli buraya girer
        {
            dosyaOku >> urun.siparisNo >> urun.urunKodu >> urun.siparisAdedi >> urun.siparisTarihi >> urun.siparisiAlan >> urun.urunAdi >> urun.uretici >> urun.teminSuresi >>
                urun.uretimTarihi >> urun.fiyatOzel >> urun.fiyatGenel >> urun.kdv >> urun.stok >> urun.siparisTutari;  //dosyadan urun referansli verileri okur
            if (urun.siparisNo == siparisNo)        //urun referansli siparisNo,siparisNo'ya esitse
            {
                cout << "Siparis no: " << urun.siparisNo << "Urun kodu: " << urun.urunKodu << "\nSiparis adedi: " << urun.siparisAdedi << "\nSiparis tarihi: " << urun.siparisTarihi
                    << "\nSiparisi alan: " << urun.siparisiAlan << "\nUrun adi: " << urun.urunAdi << "\nUretici: " << urun.uretici << "\nTemin suresi: " << urun.teminSuresi <<
                    "\nUretim tarihi: " << urun.uretimTarihi << "\nOzel fiyat: " << urun.fiyatOzel << "\nGenel fiyat: " << urun.fiyatGenel << "\nKDV orani: " << urun.kdv
                    << "\nStok adedi: " << urun.stok << "\nSiparis tutari...: " << urun.siparisTutari << "\n\n Guncel Bilgiler; \n";    //konsola yazdirir
                cout << "Siparis no       : "; cin >> urun.siparisNo;       //kullanicidan deger alir
                cout << "Urun kodu        : "; cin >> urun.urunKodu;       //kullanicidan deger alir
                cout << "Urun adedi       : "; cin >> urun.siparisAdedi;       //kullanicidan deger alir
                cout << "Siparis tarihi   : "; cin >> urun.siparisTarihi;       //kullanicidan deger alir
                cout << "Siparisi alan    : "; cin >> urun.siparisiAlan;       //kullanicidan deger alir
                cout << "Urun adi         : " << urun.urunAdi << endl;    //konsola yazdirir
                cout << "Ureticisi        : " << urun.uretici << endl;    //konsola yazdirir
                cout << "Temin suresi     : " << urun.teminSuresi << endl;    //konsola yazdirir
                cout << "Uretim tarihi    : " << urun.uretimTarihi << endl;    //konsola yazdirir
                cout << "Ozel fiyat       : " << urun.fiyatOzel << endl;    //konsola yazdirir
                cout << "Genel fiyat      : " << urun.fiyatGenel << endl;    //konsola yazdirir
                cout << "KDV orani        : " << urun.kdv << endl;    //konsola yazdirir
                cout << "Stok adedi       : " << urun.stok << endl;    //konsola yazdirir

                if (dosyaOku.eof())
                {
                    break;
                }
                dosyaYaz << urun.siparisNo << "\t" << urun.urunKodu << "\t" << urun.siparisAdedi << "\t" << urun.siparisTarihi << "\t" << urun.siparisiAlan << "\t" << urun.urunAdi << "\t" << urun.uretici << "\t" << urun.teminSuresi
                    << "\t" << urun.uretimTarihi << "\t" << urun.fiyatOzel << "\t" << urun.fiyatGenel << "\t" << urun.kdv << "\t" << urun.stok << "\t" << urun.siparisTutari << "\t";   //dosyaya yazdirma komutu
            }
            else
            {
                if (dosyaOku.eof())     //dosyanin icerigi bitene kadar gezer
                {
                    break;          //if'i kirar
                }
                dosyaYaz << urun.siparisNo << "\t" << urun.urunKodu << "\t" << urun.siparisAdedi << "\t" << urun.siparisTarihi << "\t" << urun.siparisiAlan << "\t" << urun.urunAdi << "\t" << urun.uretici << "\t" << urun.teminSuresi
                    << "\t" << urun.uretimTarihi << "\t" << urun.fiyatOzel << "\t" << urun.fiyatGenel << "\t" << urun.kdv << "\t" << urun.stok << "\t" << urun.siparisTutari << "\n";   //dosyaya yazdirma komutu
            }
        }
        dosyaOku.close();   //dosya okuma kapatilir
        dosyaYaz.close();   //dosya yazma kapatilir

        if (kontrol == 1)  //kontrol 1 ise
        {
            remove("siparis.txt");      //siparis dosyasi silinir
            rename("siparis_duzelt.txt", "siparis.txt");  //dosyalar degisir
            cout << "Siparis bilgileri duzenlendi!\n";    //konsola yazdirma
        }
        else   //if kosulu saglanmaz ise
        {
            remove("siparis_duzelt.txt");  //siparis duzeltme dosyasi silinir
        }
    }
}

void siparis_raporla()      //siparis raporlama fonksiyonu
{
    ifstream dosyaOku;      //dosyaya giris icin dosya oku fonksiyonu
    dosyaOku.open("siparis.txt");  //siparis dosyasi dosya okuma seklinde acildi

    cout << "\nUrun kodu\t" << "Urun adi\t" << "Siparis tarihi\t" << "Siparisi alan\t" << "Firma no\t" << "Siparis adedi\t" << "Siparis tutari\n";    //konsola yazdirma
    while (true)   //surekli buraya girer
    {
        dosyaOku >> urun.siparisNo >> urun.urunKodu >> urun.siparisAdedi >> urun.siparisTarihi >> urun.siparisiAlan >> urun.urunAdi >> urun.uretici >> urun.teminSuresi >>
            urun.uretimTarihi >> urun.fiyatOzel >> urun.fiyatGenel >> urun.kdv >> urun.stok >> urun.siparisTutari;     //dosyadan urun referansli verileri okur  
        if (dosyaOku.eof())  break;   //dosyanin sonuna kadar gezer ve ardindan kirar       
        cout << urun.siparisNo << "\t" << urun.urunKodu << "\t" << urun.siparisAdedi << "\t" << urun.siparisTarihi << "\t" << urun.siparisiAlan << "\t" << urun.urunAdi << "\t" << urun.uretici << "\t" << urun.teminSuresi
            << "\t" << urun.uretimTarihi << "\t" << urun.fiyatOzel << "\t" << urun.fiyatGenel << "\t" << urun.kdv << "\t" << urun.stok << "\t" << urun.siparisTutari << "\n";  //ekrana yazdirir
    }
    dosyaOku.close();       //dosya okuma islevi kapanir
}


int main()      //ilk calisacak fonksiyon
{
    while (secim != 15) //secim adli degisken 15 olmadigi surece buraya girer
    {
        system("CLS");      //sistemi sifirlar
        menu();             //menu fonksiyonu acilir
        system("PAUSE");    //sistemi durdurur
    }

    return 0;   //program buraya kadar sorunsuz gelirse calisir
}
