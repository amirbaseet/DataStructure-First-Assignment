#ifndef YoneticiDugum_hpp
#define YoneticiDugum_hpp
#include <SatirListesi.hpp>
using namespace std;
// bu sinifta yeni bir Dugum yapisi olusturuyorum,Yonetici Dugum Adi
class Y_Dugum
{
public:
    Y_Dugum(SatirListesi *S_Liste); // Kurucu SatirListesinden bir nesne alir
    ~Y_Dugum();
    double ortalama; /* burda Satir Listesinindeki
                        Tum Dumlarin Ortalamasi gosteren biri*/

    void Ort_Getir(); /* Burada Ortalama getiren bir fonksiyon tanitim bu fonksiyon
                       Satirlistesine gidip Ortalamasini Hesaplanip getiren bir fonksiyon*/

    SatirListesi *S_Liste; // Burada SatirListesinden bir Isaretici olusturdum

    // burda SatirListesinden iki tane isaretci olusturdum
    Y_Dugum *sonraki;
    Y_Dugum *onceki;
};

#endif