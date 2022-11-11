#include <YoneticiDugum.hpp>
#include <YoneticiListesi.hpp>
#include <SatirListesi.hpp>
#include <iostream>
#include <iomanip>
using namespace std;
YoneticiListesi::YoneticiListesi()
{
    ilk = 0;
    Y_Dugum_Sayisi = 0;
}
YoneticiListesi::~YoneticiListesi()
{
    cout << endl
         << this << "YoneticiListesi::~YoneticiListesi()\n";
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
void ::YoneticiListesi::YL_Sag_Yazdir(int Baslan, int bitis)
{
    Y_Dugum *secilen;
    if (this->ilk == 0)
    {
        cout << "Listesi Bos gosterilecek bir sey yok\n";
    }
    cout << "\n\n42BAslangic =" << Baslan << "Bitis = " << bitis;

    int isaretci_Uzunlugu = 21; // aslinda uzunlugu 13 ama 8 basamaktan sora gelebilemesi icin ona 8 ya ekliriz
    int son_on_Uzunlugu = 23;   // aslinda uzunlugu 13 ama || iki tane geldigi icin ona 2 ekliriz
    bitis -= Baslan;            // yazdirilacak sayisi getiriyorum bitis degerden  baslangec deger alarak
    if (bitis == 0)
        bitis++;
    cout << "\n\n47BAslangic =" << Baslan << "Bitis = " << bitis;
    ////
    Y_Dugum *gec;
    secilen = this->ilk;
    for (int i = 0; i < Baslan; i++)
    {
        /* code */
        secilen = secilen->sonraki; // bu yeni Sayfanin ilk dugumu olacak
    }

    gec = secilen;

    cout << endl
         << setw(14);
    for (int i = 0; i < bitis; i++)
    {
        if (gec->sonraki == 0)
        {
            cout << gec << endl;
        }
        else
        {

            cout << gec << setw(isaretci_Uzunlugu);
        }
        gec = gec->sonraki;
    }
    cout << endl;
    cout << setw(14);

    for (int i = 0; i < bitis; i++)
    {
        if (i == (bitis - 1))
        {

            cout << "-------------" << endl;
        }
        else
        {
            cout << "-------------" << setw(21);
        }
    }
    gec = secilen;

    for (int i = 0; i < bitis; i++)
    {
        if (gec->onceki == 0)
        {
            // os << "|" << setw(9) << gec->onceki << setw(4) << "|" << setw(8);
            cout << "|"
                 << "0000000000000"
                 << "|" << setw(7);
        }
        else
        {
            cout << "|" << gec->onceki << "|" << setw(7);
        }
        gec = gec->sonraki;
    }

    cout << endl;
    cout << setw(14);

    for (int i = 0; i < bitis; i++)
    {
        if (i == bitis - 1)
        {
            cout << "-------------" << endl;
        }
        else
        {
            cout << "-------------" << setw(21);
        }
    }
    gec = secilen;

    for (int i = 0; i < bitis; i++)
    {
        cout << setfill(' '); // Duzgun olusabilimesi icin kullanilan bir fonksiyon setw() kullaninca ' ' indeksi kadar dolduruyor
        if (gec->sonraki == 0)
        {

            cout << setw(7) << "|" << setw(13) << gec->ortalama << "|" << endl;
        }
        else if (gec == secilen)
        {
            cout << setw(1) << "|" << setw(13) << gec->ortalama << "|";
        }
        else
        {
            cout << setw(7) << "|" << setw(13) << gec->ortalama << "|" << setw(15);
        }
        gec = gec->sonraki;
    }
    cout << endl;
    cout << setw(14);

    for (int i = 0; i < bitis; i++)
    {
        if (i == bitis - 1)
        {
            cout << "-------------" << endl;
        }
        else
        {
            cout << "-------------" << setw(21);
        }
    }

    gec = secilen;

    for (int i = 0; i < bitis; i++)
    {
        if (gec->sonraki == 0)
        {
            // os << "|" << setfill(' ') << setw(13) << gec->sonraki
            //    << "|" << endl;
            cout << "|" << setw(3) << "0000000000000"
                 << "|" << endl;
        }
        else
        {

            cout << "|" << setw(3) << gec->sonraki << "|" << setw(7);
        }
        gec = gec->sonraki;
    }
    cout << endl;

    cout << setw(14);

    for (int i = 0; i < bitis; i++)
    {
        if (i == bitis - 1)
        {
            cout << "-------------" << endl;
        }
        else
        {
            cout << "-------------" << setw(21);
        }
    }
    cout << endl;
}

int ::YoneticiListesi::YDugumSayisi_Getir() const
{
    return Y_Dugum_Sayisi;
}
void ::YoneticiListesi::S_Dugumun_Silme(Y_Dugum *S_sildugum, Dugum *S_Dugumun_Silme)
{
    // bu fonksiyonda Y_Dugum Dugum sinifindan birer isaretci olusturdum
    // ilk once  silinecek SatirListesindeki dugume silme yap
    //  burda satirlistenin dugumlardan rastgele olarak birtane siliyorum
    S_sildugum->S_Liste->Dugum_Sil(S_Dugumun_Silme);
    /* onu sildikten sonra Satirlistesi kontrol ediyorum eger hic bir dugum yoksa
     Yoneticinin Dugumu silme yap*/
    if (this->YDugumSayisi_Getir() == 0)
    {
        Y_Dugumun_Silme(S_sildugum);
    }
    else
    {
        // Varsa YoneteciListesin Dugumundeku  SatirSayisinin Ortalamasi getirip
        // Yonetici Dugumlari sirala
        S_sildugum->Ort_Getir();
        this->Y_Dugum_Siralama();
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
    if (Dis_YDugumSayisi == 0)
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
Y_Dugum * ::YoneticiListesi::ilkGetir() const
{
    return this->ilk;
}
void ::YoneticiListesi::YL_Yazdir()
{
    Y_Dugum *gec = this->ilk;
    int sayac = 0;
    int isaretci_Uzunlugu = 21; // aslinda uzunlugu 13 ama 8 basamaktan sora gelebilemesi icin ona 8 ya ekliriz
    int son_on_Uzunlugu = 23;   // aslinda uzunlugu 13 ama || iki tane geldigi icin ona 2 ekliriz
    cout << setw(14);
    while (gec != 0)
    {
        // os << setw(15) << gec << setw(15) << gec->ortalama << setw(15) << gec->onceki << setw(15) << gec->sonraki << endl;
        if (gec->sonraki == 0)
        {
            cout << gec << endl;
        }
        else
        {
            cout << gec << setw(isaretci_Uzunlugu);
        }

        sayac++;
        gec = gec->sonraki;
    }
    cout << setw(14);

    for (int i = 0; i < sayac; i++)
    {
        if (i == sayac - 1)
        {
            cout << "-------------" << endl;
        }
        else
        {
            cout << "-------------" << setw(21);
        }
    }
    gec = this->ilk;

    while (gec != 0)
    {
        if (gec->onceki == 0)
        {
            // os << "|" << setw(9) << gec->onceki << setw(4) << "|" << setw(8);
            cout << "|"
                 << "0000000000000"
                 << "|" << setw(7);
        }
        else
        {
            cout << "|" << gec->onceki << "|" << setw(7);
        }
        gec = gec->sonraki;
    }
    cout << endl;
    cout << setw(14);

    for (int i = 0; i < sayac; i++)
    {
        if (i == sayac - 1)
        {
            cout << "-------------" << endl;
        }
        else
        {
            cout << "-------------" << setw(21);
        }
    }
    gec = this->ilk;

    while (gec != 0)
    {
        cout << setfill(' '); // Duzgun olusabilimesi icin kullanilan bir fonksiyon setw() kullaninca ' ' indeksi kadar dolduruyor
        if (gec->sonraki == 0)
        {

            cout << setw(7) << "|" << setw(13) << gec->ortalama << "|" << endl;
        }
        else if (gec == this->ilk)
        {
            cout << setw(1) << "|" << setw(13) << gec->ortalama << "|";
        }
        else
        {
            cout << setw(7) << "|" << setw(13) << gec->ortalama << "|" << setw(15);
        }
        gec = gec->sonraki;
    }
    cout << setw(14);

    for (int i = 0; i < sayac; i++)
    {
        if (i == sayac - 1)
        {
            cout << "-------------" << endl;
        }
        else
        {
            cout << "-------------" << setw(21);
        }
    }

    gec = this->ilk;

    while (gec != 0)
    {
        if (gec->sonraki == 0)
        {
            // os << "|" << setfill(' ') << setw(13) << gec->sonraki
            //    << "|" << endl;
            cout << "|" << setw(3) << "0000000000000"
                 << "|" << endl;
        }
        else
        {

            cout << "|" << setw(3) << gec->sonraki << "|" << setw(7);
        }
        gec = gec->sonraki;
    }
    cout << setw(14);

    for (int i = 0; i < sayac; i++)
    {
        if (i == sayac - 1)
        {
            cout << "-------------" << endl;
        }
        else
        {
            cout << "-------------" << setw(21);
        }
    }
    cout << endl;
}
ostream &
operator<<(ostream &os, YoneticiListesi &YListesi)
{

    Y_Dugum *gec = YListesi.ilk;
    int sayac = 0;
    int isaretci_Uzunlugu = 21; // aslinda uzunlugu 13 ama 8 basamaktan sora gelebilemesi icin ona 8 ya ekliriz
    int son_on_Uzunlugu = 23;   // aslinda uzunlugu 13 ama || iki tane geldigi icin ona 2 ekliriz
    os << setw(14);
    while (gec != 0)
    {
        // os << setw(15) << gec << setw(15) << gec->ortalama << setw(15) << gec->onceki << setw(15) << gec->sonraki << endl;
        if (gec->sonraki == 0)
        {
            os << gec << endl;
        }
        else
        {
            os << gec << setw(isaretci_Uzunlugu);
        }

        sayac++;
        gec = gec->sonraki;
    }
    os << setw(14);

    for (int i = 0; i < sayac; i++)
    {
        if (i == sayac - 1)
        {
            os << "-------------" << endl;
        }
        else
        {
            os << "-------------" << setw(21);
        }
    }
    gec = YListesi.ilk;

    while (gec != 0)
    {
        if (gec->onceki == 0)
        {
            // os << "|" << setw(9) << gec->onceki << setw(4) << "|" << setw(8);
            os << "|"
               << "0000000000000"
               << "|" << setw(7);
        }
        else
        {
            os << "|" << gec->onceki << "|" << setw(7);
        }
        gec = gec->sonraki;
    }
    os << endl;
    os << setw(14);

    for (int i = 0; i < sayac; i++)
    {
        if (i == sayac - 1)
        {
            os << "-------------" << endl;
        }
        else
        {
            os << "-------------" << setw(21);
        }
    }
    gec = YListesi.ilk;
    while (gec != 0)
    {
        cout << setfill(' '); // Duzgun olusabilimesi icin kullanilan bir fonksiyon setw() kullaninca ' ' indeksi kadar dolduruyor
        if (gec->sonraki == 0)
        {

            os << setw(7) << "|" << setw(13) << gec->ortalama << "|" << endl;
        }
        else if (gec == YListesi.ilk)
        {
            os << setw(1) << "|" << setw(13) << gec->ortalama << "|";
        }
        else
        {
            os << setw(7) << "|" << setw(13) << gec->ortalama << "|" << setw(15);
        }
        gec = gec->sonraki;
    }
    os << setw(14);

    for (int i = 0; i < sayac; i++)
    {
        if (i == sayac - 1)
        {
            os << "-------------" << endl;
        }
        else
        {
            os << "-------------" << setw(21);
        }
    }

    gec = YListesi.ilk;
    while (gec != 0)
    {
        if (gec->sonraki == 0)
        {
            // os << "|" << setfill(' ') << setw(13) << gec->sonraki
            //    << "|" << endl;
            os << "|" << setw(3) << "0000000000000"
               << "|" << endl;
        }
        else
        {

            os << "|" << setw(3) << gec->sonraki << "|" << setw(7);
        }
        gec = gec->sonraki;
    }
    os << setw(14);

    for (int i = 0; i < sayac; i++)
    {
        if (i == sayac - 1)
        {
            os << "-------------" << endl;
        }
        else
        {
            os << "-------------" << setw(21);
        }
    }
    return os;
}
