/**
 * @file SatirListesi.hpp
 * @description Satir listesi icin iki yonlu bagli list olusturdum
 * @course 2C
 * @assignment birinci ödev
 * @date 1/12/2022
 * @author AMRO MOUSA ISMAIL BASEET
 */
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
    Dugum *get_D_byindeks(int indeks);
    void YD_Sat_Dugm_Yazdir(int mesafe);
    void YD_silinecek_Sat_Dugm_Yazdir_(Dugum *silinecek, int mesafe);

private:
    Dugum *ilk;
    double Dugum_Ortalama;
    int Dugum_Sayisi;
};
#endif