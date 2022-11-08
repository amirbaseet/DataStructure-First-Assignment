#ifndef SatirListesi_hpp
#define SatirListesi_hpp
#include <iostream>
#include <Dugum.hpp>
using namespace std;
class SatirListesi
{
public:
    SatirListesi();

    ~SatirListesi();

    int Dugum_Sayisi_Getir() const; // fonksiyonun const yapiyiorum degere degisiklik yapmamasini icin

    double Ortalama_getir() const;
    // Dugum Ekle fonksiyonu tanitiyorum disardan sabit int veri alip ekleme yapar
    void Dugum_Ekle(const int veri);
    void Ort_Hesapla();
    // Dugum silme fonksiyonu tanitiyorum disardan sabit int veri alip ekleme yapar
    void Dugum_Sil();
    friend ostream &operator<<(ostream &os, SatirListesi &Liste);
    bool ilk_D_varmi(); // burda ilk dugum var olup olmadigini kontrol ediyorum
    Dugum *S_ilkDugum();

private:
    Dugum *ilk;
    double Dugum_Ortalama;
    int Dugum_Sayisi;
};
#endif