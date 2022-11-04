#pragma once
#include <iostream>
#include"./Dugum.h"
using namespace std;
class SatirListesi
{
public:
    SatirListesi();

    ~SatirListesi();
    
    int Dugum_Sayisi_Getir();

    int Ortalama_getir();
    // Dugum Ekle fonksiyonu tanitiyorum disardan sabit int veri alip ekleme yapar
    void Dugum_Ekle(const int veri);
    void Ort_Hesapla();
    // Dugum silme fonksiyonu tanitiyorum disardan sabit int veri alip ekleme yapar
    void Dugum_Sil();

    friend ostream& operator<<(ostream& os, SatirListesi& Liste);
    SatirListesi* sonraki;
    SatirListesi* onceki;

private:
    Dugum* ilk;
    int Dugum_Ortalama;
    int Dugum_Sayisi;
};

