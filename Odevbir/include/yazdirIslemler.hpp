/**
 * @file yazdirIslemler.hpp
 * @description Programınızın açıklaması ne yaptığına dair.
 * @course 2C
 * @assignment birinci ödev
 * @date 1/12/2022
 * @author AMRO MOUSA ISMAIL BASEET
 */
#ifndef yazdirIslemler_hpp
#define yazdirIslemler_hpp
#include <iostream>
#include <YoneticiDugum.hpp>
using namespace std;
void solaGit(float &sayfa_Adet, float &burayakadar_yazdir, float &Baslangic) // sol sayfa varsa giden bir fonksiyon
{

    if (sayfa_Adet - burayakadar_yazdir != sayfa_Adet - 1) // Eger ilk sayfada bulunmuyorsa onceki sayfa Yazdir
    {
        if (sayfa_Adet - burayakadar_yazdir > 0) // Eger son sayfada degil ve birinci sayfada da degil ise burda gersin
        {
            burayakadar_yazdir--;
        }
        else if (sayfa_Adet - burayakadar_yazdir == 0)
        {

            // eger tum elemanlari yazdirildi ise .000 kurtalmak icin
            burayakadar_yazdir = Baslangic / 8;
        }

        if (burayakadar_yazdir >= 1)
        { // Eger burayakadar_yazdir 8 taneden buyuk ise baslangic =burayakadar_yazdir -8
            Baslangic = burayakadar_yazdir - 1;
        }
        else
        {
            Baslangic = 0;
        }
        Baslangic *= 8;
    }
}
void SagGit(float &sayfa_Adet, float &burayakadar_yazdir, const int &YD_Dugumsayisi, float &Baslangic)
{ // sag sayfa varsa giden bir fonksiyon
    if (burayakadar_yazdir * 8 != YD_Dugumsayisi)
    {
        Baslangic = burayakadar_yazdir * 8;

        if (sayfa_Adet - burayakadar_yazdir >= 1)
        {
            burayakadar_yazdir++;
        }
        else if (sayfa_Adet - burayakadar_yazdir > 0 && sayfa_Adet - burayakadar_yazdir < 1)
        {

            burayakadar_yazdir += (sayfa_Adet - burayakadar_yazdir);
        }
    }
}
void YD_sil_sonra(float &Baslangic, float &burayakadar_yazdir, float &sayfa_Adet)
{
    if (Baslangic == ((burayakadar_yazdir * 8) - 1)) // Eger Sayfada Tek Dugum Varsa silindikten sonra Sayfada Hic Bir dugum kalmadiginden  onceki Sayfa ya Yazdirilacak
    {
        solaGit(sayfa_Adet, burayakadar_yazdir, Baslangic);
    }
    else if (burayakadar_yazdir == sayfa_Adet)
    {
        burayakadar_yazdir *= 8;
        burayakadar_yazdir--;
        burayakadar_yazdir /= 8;
    }
}

Y_Dugum *sonraki_sayfa_birinciD_sec(const float &Baslangic, Y_Dugum *secilen_YDugum, int &secilen)
{ // sag yada sol sayfa giderken yeni sayfada ilk Ydugum secen bir fonksiyon
    for (int i = 0; i < Baslangic; i++)
    {
        /* code */
        secilen_YDugum = secilen_YDugum->sonraki; // bu yeni Sayfanin ilk dugumu olacak
    }
    secilen = 0;
    return secilen_YDugum;
}
Y_Dugum *Onceki_sayfa_SonD_sec(const float &Baslangic, const float &bitis, Y_Dugum *secilen_YDugum, int &secilen)
{                                             // sag yada sol sayfa giderken yeni sayfada ilk Ydugum secen bir fonksiyon
    for (int i = 0; i < (bitis * 8) - 1; i++) // bitis*8 -1 cunku bitis son yazdirilanin sonraki issetir 8
    {
        /* code */
        secilen_YDugum = secilen_YDugum->sonraki; // bu yeni Sayfanin ilk dugumu olacak
    }
    secilen = (bitis * 8 - 1) - Baslangic;
    return secilen_YDugum;
}
Y_Dugum *Siralama_sonra_YDsec(Y_Dugum *secilen_YDugum, Y_Dugum *ilk, const int &secilen, const float &Baslangic)
{
    int dugum_indeksi = secilen + Baslangic;
    secilen_YDugum = ilk;
    for (int i = 0; i < dugum_indeksi; i++)
    {
        /* code */
        secilen_YDugum = secilen_YDugum->sonraki; // bu yeni Sayfanin ilk dugumu olacak
    }
    return secilen_YDugum;
}
Y_Dugum *sonraki_Dugum_git(Y_Dugum *secilen_YDugum, float &sayfa_Ade, const int &YD_Dugumsayisi, Y_Dugum *ilk, int &secilen, float &burayakadar_yazdir, float &Baslangic)
{
    if (secilen_YDugum->sonraki != 0 && secilen < (burayakadar_yazdir * 8 - Baslangic - 1))
    {
        /* Eger Secilen Dugum son ve sayfada son dugum ise sonrasina gitmez*/
        cout << "\n104\n";
        secilen++;
        secilen_YDugum = secilen_YDugum->sonraki;
    }
    else if (secilen_YDugum->sonraki != 0 && secilen == (burayakadar_yazdir * 8 - Baslangic - 1))
    {
        cout << "\n110\n";
        SagGit(sayfa_Ade, burayakadar_yazdir, YD_Dugumsayisi, Baslangic);
        secilen_YDugum = ilk;
        secilen_YDugum = sonraki_sayfa_birinciD_sec(Baslangic, secilen_YDugum, secilen);
    }

    return secilen_YDugum;
}
Y_Dugum *Onceki_Dugum_git(Y_Dugum *secilen_YDugum, float &sayfa_Ade, const int &YD_Dugumsayisi, Y_Dugum *ilk, int &secilen, float &burayakadar_yazdir, float &Baslangic)
{
    if (secilen_YDugum != ilk)
    {
        if (secilen != 0)
        {
            /*Eger Secilen Dugumun Onceki Dugumun adresi 0 degil ise onceki gitmez */
            secilen--;
            secilen_YDugum = secilen_YDugum->onceki;
        }
        else if (secilen == 0 && secilen_YDugum->onceki != 0)
        {

            solaGit(sayfa_Ade, burayakadar_yazdir, Baslangic);
            secilen_YDugum = ilk;
            secilen_YDugum = Onceki_sayfa_SonD_sec(Baslangic, burayakadar_yazdir, secilen_YDugum, secilen);
        }
    }
    return secilen_YDugum;
}
#endif
