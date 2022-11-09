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
    int Dugum_Sil_rastgele(); // rastgele silinecek dugumun indeksi dondur
    void Dugum_Sil(Dugum *silinecek_Dugum);
    // void Dugum_Sil_byineks(int silinecek_indeks);
    friend ostream &
    operator<<(ostream &os, SatirListesi &Liste);
    bool ilk_D_varmi(); // burda ilk dugum var olup olmadigini kontrol ediyorum
    Dugum *get_D_byindeks(int indeks);
    void YD_Sat_Dugm_Yazdir(int mesafe);

private:
    Dugum *ilk;
    double Dugum_Ortalama;
    int Dugum_Sayisi;
};
#endif