#ifndef YoneticiListesi_hpp
#define YoneticiListesi_hpp
#include <YoneticiDugum.hpp>
#include <SatirListesi.hpp>
#include <iostream>

class YoneticiListesi
{
public:
    YoneticiListesi();
    // ~YoneticiListesi();
    // Bu fonksiyon SatirListesi nden bir nesnesi alip ve bir Yonetici dugum olarak Kadetme
    void Y_Dugum_Ekle(SatirListesi *Eklenecek_Satir);

    // bu fonksiyonda satir Listesindeki dugumleri silme islemi gerceklesecek
    void S_Dugumun_Silme(SatirListesi *SilSatirsayisi_Dugum);

    /*bu fonksiyonda YOneteci LIstesinden  dugumu silme islemi gerceklesecek
    ama bu SatirSayisinin Hic Bir Dugum kalmamissa Calisiyor*/
    void Y_Dugumun_Silme(Y_Dugum *Silinecek);
    void Y_Dugumun_Degistir(Y_Dugum *Degistirilecek);
    // Bu fonksiyon YoneticiListesindeki Dugumler Kucuken buguge Siralama Yapar
    void Y_Dugum_Siralama();
    int YDugumSayisi_Getir() const;
    void YL_Yazdir(SatirListesi *yazdirilacak); // YoneticiListesi ve secilen Ydugumun yazdiran bir fonksiyon
    friend ostream &operator<<(ostream &os, YoneticiListesi &YListesi);

private:
    Y_Dugum *ilk;
    int Y_Dugum_Sayisi;
};

#endif