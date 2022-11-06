#include "SatirListesi.h"
#include <iostream>
#include <iomanip>

using namespace std;
SatirListesi::SatirListesi()
{
    ilk = 0;
    Dugum_Ortalama = 0;
    Dugum_Sayisi = 0;
    sonraki = onceki = 0;
}
SatirListesi::~SatirListesi()
{
    cout << this << "\t~SatirListesi()" << endl;
}
int SatirListesi::Dugum_Sayisi_Getir()
{
    return Dugum_Sayisi;
}
int SatirListesi::Ortalama_getir()
{
    return Dugum_Ortalama;
}
void SatirListesi::Ort_Hesapla()
{
    Dugum* gec = ilk;
    int ortalama = 0;
    int Dugum_Sayisi = Dugum_Sayisi_Getir();
    for (int i = 0; i < Dugum_Sayisi; i++)
    {
        ortalama += gec->veri;
        gec = gec->sonraki;
    }
    ortalama /= Dugum_Sayisi;
    Dugum_Ortalama = ortalama;
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
    Dugum* yeni = new Dugum(veri);
    if (ilk == 0)
    {
        ilk = yeni;
    }
    else
    {
        Dugum* gec = ilk;
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
void SatirListesi::Dugum_Sil()
{
    if (ilk == 0)
    {
        /*burda  SatirListesi nin dugum sayisi kontrol ediyiorum
        eger hic bir dugum yoksa silme yapmaz*/
        return;
    }
    if (Dugum_Sayisi_Getir() == 1)
    {
        /* Eger Tek Dugum varsa
        ilk Dugum silinip ilk e 0 atma*/
        delete ilk;
        ilk = 0;
    }
    else
    {
        // burda silinecek dugumun indeksi rastgele olarak getiriyorum
        int Silinecek_index_rastgele = rand() % Dugum_Sayisi_Getir() + 1;
        Dugum* gec = ilk;
        for (int i = 0; i < Silinecek_index_rastgele; i++)
        {
            gec = gec->sonraki;
        }
        Dugum* silinecek_Dugum = gec;
        Dugum* silinecekOnceki = silinecek_Dugum->onceki;
        Dugum* silinecekSonraki = silinecek_Dugum->sonraki;

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
    }
    Dugum_Sayisi--;
    if (Dugum_Sayisi_Getir() == 0)
    {
        /* Eger hic bir dugum kalmamis isa satirsayisinin listesi silinecek  */
         //delete this;
      this->~SatirListesi();
        
    }
    else
    {
        Ort_Hesapla();
    }
}
ostream& operator<<(ostream& os, SatirListesi& Liste)
{

    os << setw(15) << "dugum adresi \t" /*<< setw(15)*/ << "\tveri\t" << setw(15) << "onceki\t" << setw(15) << "sonraki" << endl;

    Dugum* gec = Liste.ilk;

    while (gec != 0)
    {
        os << setw(15) << gec << "\t" << gec->veri << "\t" << gec->onceki << "\t" << gec->sonraki << endl;
        gec = gec->sonraki;
    }

    os << "-------------------------------------" << endl;

    return os;
}

