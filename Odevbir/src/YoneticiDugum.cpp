/**
 * @file YoneticiDugum.cpp
 * @description Programınızın açıklaması ne yaptığına dair.
 * @course 2C
 * @assignment birinci ödev
 * @date 1/12/2022
 * @author AMRO MOUSA ISMAIL BASEET
 */
#include <YoneticiDugum.hpp>
Y_Dugum::Y_Dugum(SatirListesi *S_Liste)
{
    this->S_Liste = S_Liste;

    // ilk Eklenecek Satir saiyisinin ortalamasi Hesaplanip Dugume atanir
    S_Liste->Ort_Hesapla();
    this->ortalama = S_Liste->Ortalama_getir();
    sonraki = onceki = 0;
}
Y_Dugum::~Y_Dugum()
{
    cout << this << "Y_Dugum::~Y_Dugum()" << endl;
};
void ::Y_Dugum::Ort_Getir()
{
    // Sayi listesinin sayilari ortalmasini hesaplanip degeri verir
    S_Liste->Ort_Hesapla();
    this->ortalama = S_Liste->Ortalama_getir();
}
