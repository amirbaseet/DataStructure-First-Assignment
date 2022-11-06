#include <YoneticiDugum.hpp>
#include <YoneticiListesi.hpp>
#include <iostream>
#include <iomanip>
using namespace std;
YoneticiListesi::YoneticiListesi()
{
    ilk = 0;
    Y_Dugum_Sayisi = 0;
}
void ::YoneticiListesi::Y_Dugum_Ekle(SatirListesi *Eklenecek_Satir)
{
    Y_Dugum *yeni = new Y_Dugum(Eklenecek_Satir);

    if (ilk == 0)
    {
        /* code */
        ilk = yeni;
    }
    else
    {
        Y_Dugum *gec = ilk;
        // burda bir while dongu olusturdum SatirListesi nin son Y_dugume gitmemize saglar
        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }

        gec->sonraki = yeni;
        yeni->onceki = gec;
    }
    Y_Dugum_Sayisi++;
}
int ::YoneticiListesi::YDugumSayisi_Getir() const
{
    return Y_Dugum_Sayisi;
}
void ::YoneticiListesi::S_Dugumun_Silme(SatirListesi *S_Dugumun_Silme)
{

    // S_Dugumun_Silme->Dugum_Sil();
    // int Dis_YDugumSayisi = YDugumSayisi_Getir();
    // Y_Dugum *gec = ilk;
    // for (int i = 0; i < Dis_YDugumSayisi; i++)
    // {
    //     gec->Ort_Getir();
    //     gec = gec->sonraki;
    // }

    /*burda Yonetici listesinde satirlistesindeki silinecek dugumun ariyorum*/
    Y_Dugum *gec = ilk;
    bool buldum = false;
    while (buldum == true)
    {
        if (&gec->S_Liste == &S_Dugumun_Silme)
        {
            buldum = true;
        }
        gec = gec->sonraki;
    }
    // burda satirlistenin dugumlardan rastgele olarak birtane siliyorum
    gec->S_Liste->Dugum_Sil();
    /* onu sildikten sonra Satirlistesi kontrol ediyorum eger hic bir dugum yoksa
     Yoneticinin Dugumu silme yap*/
    if (S_Dugumun_Silme->ilk_D_varmi() == false)
    {
        // Yoneticinin Dugumu silme yap
        Y_Dugumun_Silme(gec);
    }
    else
    {
        // Varsa YoneteciListesin Dugumundeku  SatirSayisinin Ortalamasi getir
        gec->Ort_Getir();
    }
}
void ::YoneticiListesi::Y_Dugumun_Silme(Y_Dugum *silinecek_Dugum)
{
    if (ilk == 0)
    {
        /*burda  Yonetici nin dugum sayisi kontrol ediyiorum
        eger hic bir dugum yoksa silme yapmaz*/
        return;
    }
    // Yonetici listesinin dugum sayisi sifir degilse silme yapar

    int Dis_YDugumSayisi = YDugumSayisi_Getir();
    if (Dis_YDugumSayisi == 1)
    {
        /* Eger Tek Dugum varsa
         ilk Dugum silinip ilk e 0 atma yapar*/
        delete ilk;
        ilk = 0;
    }
    else
    {
        /*Birden Fazla Yoneticinin Dugum varsa Verilen YDugumu silme yapar */
        Y_Dugum *silinecekOnceki = silinecek_Dugum->onceki;
        Y_Dugum *silinecekSonraki = silinecek_Dugum->sonraki;
        /*eger silinecek dugumun sonraki nin varsa
       o zaman silineceksonraki dugum oncekinin degeri
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

        delete silinecek_Dugum; // silinecek dugum siliyorum
    }

    Y_Dugum_Sayisi--; // Yoneticinin Dugum sayisi bir azaltik
}
void ::YoneticiListesi::Y_Dugumun_Degistir(Y_Dugum *Degis_Dugum) // Degisecek Dugumun Adresi Disardan aliyorum
{
    Y_Dugum *Degis_Dugum_Sonraki = Degis_Dugum->sonraki;
    Y_Dugum *Degis_Dugum_Onceki = Degis_Dugum->onceki;
    Y_Dugum *Degis_Dugum_Sonraki_Sonraki = Degis_Dugum_Sonraki->sonraki;
    /*******************/

    if (Degis_Dugum->sonraki == 0 || Degis_Dugum == 0) // Eger Degisecek dugumun sonraki bos ise Yada Degisecek bos ise bir sey yapmaz
    {
        return;
    }

    if (Degis_Dugum_Sonraki_Sonraki) // Eger Degisecek Dugumun Sonrakinin sonraki var ise kosula girer
    {
        Degis_Dugum_Sonraki_Sonraki->onceki = Degis_Dugum;
    }

    Degis_Dugum->sonraki = Degis_Dugum_Sonraki->sonraki;

    Degis_Dugum_Sonraki->sonraki = Degis_Dugum;

    Degis_Dugum_Sonraki->onceki = Degis_Dugum_Onceki;
    if (Degis_Dugum == ilk) // birinci dugum yere Degistirilecekse Onceki olmadigi icin burda girmemesi gerek
    {
        Degis_Dugum->onceki = Degis_Dugum_Sonraki;
    }

    else
    {
        Degis_Dugum_Onceki->sonraki = Degis_Dugum_Sonraki;

        Degis_Dugum->onceki = Degis_Dugum_Sonraki;
    }
    if (Degis_Dugum_Onceki == 0) // Eger Degisecek dugum ilk olan ise ilk YDugum sonraki olsun
    {
        this->ilk = Degis_Dugum_Sonraki;
    }
}
void ::YoneticiListesi::Y_Dugum_Siralama()
{

    int YD_Say = this->YDugumSayisi_Getir(); // YoneticiListesindeki Dugum Sayisi getiriyorum
    Y_Dugum *gec = this->ilk;
    if (YD_Say == 1) // eger Dugum Sayisi Bir ise Degistirme Yapmayacaktir
    {
        return;
    }
    // burda YoneticiListesin Dugumlerin Siralama islemi yapiyorum

    for (int k = YD_Say; k > 0; k--)
    {
        for (int j = YD_Say; j > 0; j--)
        {
            for (int i = YD_Say; i > 0; i--)
            {
                if (gec->sonraki == 0) // eger Degistirilecegin sonraki bos ise tekrardan gec = ilk dugumdur
                {
                    gec = ilk;
                }
                // Eger Gecin adresi gecin sonraki adresi buguk
                // ise YoneticiListesin Dugumleri  Yerleri degistir
                if (gec->ortalama > gec->sonraki->ortalama)
                {
                    Y_Dugumun_Degistir(gec);
                }
            }
            gec = gec->sonraki;
        }
    }
}

ostream &operator<<(ostream &os, YoneticiListesi &YListesi)
{
    // os << setw(15) << "dugum adresi " << endl
    //    << setw(15) << "ortalama" << endl
    //    << setw(15) << "onceki" << endl
    //    << setw(15) << "sonraki" << endl;

    Y_Dugum *gec = YListesi.ilk;
    int sayac = 0;
    while (gec != 0)
    {
        os << setw(15) << gec << setw(15);

        gec = gec->sonraki;
        sayac++;
    }
    gec = YListesi.ilk;
    for (int i = 0; i < sayac; i++)
    {
        /* code */
    }

    os << "-------------------------------------" << endl;

    return os;
}
// ostream &operator<<(ostream &os, YoneticiListesi &YListesi)
// {
//     os << setw(15) << "dugum adresi " << setw(15) << "ortalama" << setw(15) << "onceki" << setw(15) << "sonraki" << endl;

//     Y_Dugum *gec = YListesi.ilk;

//     while (gec != 0)
//     {
//         os << setw(15) << gec << setw(15) << gec->ortalama << setw(15) << gec->onceki << setw(15) << gec->sonraki << endl;
//         gec = gec->sonraki;
//     }

//     os << "-------------------------------------" << endl;

//     return os;
// }
