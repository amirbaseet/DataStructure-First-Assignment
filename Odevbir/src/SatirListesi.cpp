#include <iostream>
#include <SatirListesi.hpp>
#include <iomanip>
#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
using namespace std;
SatirListesi::SatirListesi()
{
    ilk = 0;
    Dugum_Ortalama = 0;
    Dugum_Sayisi = 0;
}
SatirListesi::~SatirListesi()
{
    cout << this << "\t~SatirListesi()" << endl;
    if (this->ilk == 0)
        return;
    Dugum *gecici = this->ilk;
    for (int i = 0; i < this->Dugum_Sayisi_Getir(); i++)
    {
        Dugum *silinecek = gecici;
        gecici = gecici->sonraki;
        cout << silinecek << " Dugum adresi silindi SatirListesi::~SatirListesi()\n";
        delete silinecek;
    }
}
int SatirListesi::Dugum_Sayisi_Getir() const
{

    return Dugum_Sayisi;
}
double SatirListesi::Ortalama_getir() const
{

    return Dugum_Ortalama;
}
void SatirListesi::Ort_Hesapla()
{
    Dugum *gec = ilk;
    double ortalama = 0;
    int Dugum_Sayisi = Dugum_Sayisi_Getir();
    // if (Dugum_Sayisi == 0)
    // { /* Eger dugum Sayisi 0 ise 0 dondur 0/sayi olmamasi icin*/
    //     Dugum_Ortalama = 0;
    // }
    // else
    // {
    for (int i = 0; i < Dugum_Sayisi; i++)
    {
        ortalama += gec->veri;
        gec = gec->sonraki;
    }
    ortalama /= Dugum_Sayisi;
    Dugum_Ortalama = ortalama;
    // }
}

void SatirListesi::Dugum_Ekle(const int veri)
{
    /*
    ilk once Dugum sinifindan yeni bir isaretci tanitiyorum sonra
     "heap"te Dugum sinifindan yeni bir nesne ugretmek
     sonra ilk kosulumuzda satirListesisin ilk dugum var mi onu kontrol ediyorum
     yoksa son dugume gidip yeni dugume olusturup son dugumin sonrakine yeni dugumun adresini atma
     ve yeni dugumun oncekinin adresine son dugumun adresini atma
    */
    Dugum *yeni = new Dugum(veri);
    if (ilk == 0)
    {
        ilk = yeni;
    }
    else
    {
        Dugum *gec = ilk;
        // burda bir while dongu olusturdum SatirListesi nin son dugume gitmemize saglar
        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }

        gec->sonraki = yeni;
        yeni->onceki = gec;
    }
    Dugum_Sayisi++; // dugumun sayisi bir arttirdim
}
bool ::SatirListesi::ilk_D_varmi()
{
    bool test = false;
    if (ilk != 0)
    {
        test = true;
    }

    return test;
}
int SatirListesi::Dugum_Sil_rastgele()
{
    int Silinecek_index_rastgele;
    if (ilk == 0)
    {
        /*burda  SatirListesi nin dugum sayisi kontrol ediyiorum
        eger hic bir dugum yoksa silme yapmaz*/
        Silinecek_index_rastgele = 0;
    }
    int Dis_Dugum_sayisi = Dugum_Sayisi_Getir();
    if (Dis_Dugum_sayisi == 1)
    {
        Silinecek_index_rastgele = 1;
    }
    else
    {
        // burda silinecek dugumun indeksi rastgele olarak getiriyorum
        /* rastgele olmasini sagliyorum her defa ayni deger olmamasi */
        srand(time(NULL));
        Silinecek_index_rastgele = rand() % Dis_Dugum_sayisi + 1;
    }
    return Silinecek_index_rastgele;
}

void ::SatirListesi::Dugum_Sil(Dugum *silinecek_Dugum)
{
    int Dis_dugum_sayisi = this->Dugum_Sayisi_Getir(); // disarda dugum sayi tutan biri
    if (Dis_dugum_sayisi == 0)                         // beni yeniden yap cunku return yapmiyor
    {
        /*burda  SatirListesi nin dugum sayisi kontrol ediyiorum
        eger hic bir dugum yoksa silme yapmaz*/
        // return;
        cout << "\n\n\n\nBURDAYIIIIM 119\n\n\n\n\n";
    }
    if (Dis_dugum_sayisi == 1)
    {
        /* Eger Tek Dugum varsa
        ilk Dugum silinip ilk e 0 atma*/
        cout << "\n\n\n\nBURDAYIIIIM 124\n\n\n\n\n";

        delete ilk;
        ilk = 0;
        Dugum_Sayisi--;
    }

    else
    {

        // get Dugum by index cagirdim bu
        // Dugum *silinecek_Dugum = silinecek_Dugum;

        Dugum *silinecekOnceki = silinecek_Dugum->onceki;

        Dugum *silinecekSonraki = silinecek_Dugum->sonraki;

        /*eger silinecek dugumun sonraki nin varsa
           ozaman silineceksonraki dugum oncekinin degeri
           silinecek oncekinin degeri olacaktir */
        if (silinecekSonraki)
            silinecekSonraki->onceki = silinecekOnceki;
        /*Eger silinecek Dugumun Onceki varsa o zaman
        silinicekoncekinin sonraki =silinecek sonraki
        yoksa ilk =silinecek sonraki*/
        if (silinecekOnceki)
            silinecekOnceki->sonraki = silinecekSonraki;
        else
            ilk = silinecekSonraki;

        delete silinecek_Dugum; // silinecek dugum silip ve Dugum sayisi bir azaltik
        Dugum_Sayisi--;
    }
    Ort_Hesapla();
}

Dugum * ::SatirListesi::get_D_byindeks(int indeks)
{
    Dugum *gec = ilk;

    for (int i = 0; i < indeks - 1; i++)
    {
        gec = gec->sonraki;
    }
    return gec;
}
void ::SatirListesi::YD_Sat_Dugm_Yazdir(int mesafe)
{
    Dugum *gec = this->ilk;
    cout << setfill(' ');
    while (gec != 0)
    {
        cout << setw(mesafe) << ""
             << "---------------" << endl;
        cout << setw(mesafe) << "|" << setw(3) << gec << setw(2) << "|" << endl; // ilk once "|"Yazdir sonra 3 uncu basamakta gec yazdir
        cout << setw(mesafe) << ""
             << "---------------" << endl;
        cout << setw(mesafe) << "|" << setw(7) << gec->veri << setw(8) << "|" << endl;
        cout << setw(mesafe) << ""
             << "---------------" << endl;
        // Duzgun bir sekilde cikabilmesi icin if gec son dugum ise once"|"Yazdir sonra 7 inci basamakta gec yazdir
        // sonra 8inci basamakta"|" yazdir

        cout << setw(mesafe) << "|" << setw(14) << gec->sonraki << "|" << endl
             << endl;
        gec = gec->sonraki;
    }
}

ostream &operator<<(ostream &os, SatirListesi &Liste)
{

    Dugum *gec = Liste.ilk;

    while (gec != 0)
    {
        os << "----------------" << endl;
        os << "|" << setw(3) << gec << setw(2) << "|" << endl; // ilk once "|"Yazdir sonra 3 uncu basamakta gec yazdir
        os << "----------------" << endl;
        os << "|" << setw(7) << gec->veri << setw(8) << "|" << endl;
        os << "----------------" << endl;
        // Duzgun bir sekilde cikabilmesi icin if gec son dugum ise once"|"Yazdir sonra 7 inci basamakta gec yazdir
        // sonra 8inci basamakta"|" yazdir

        os << "|" << setfill(' ') << setw(14) << gec->sonraki << "|" << endl
           << endl;

        gec = gec->sonraki;
    }

    os << endl;

    return os;
}
