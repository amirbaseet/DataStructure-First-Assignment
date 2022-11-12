/**
 * @file Dugum.hpp
 * @description Programınızın açıklaması ne yaptığına dair.
 * @course 2C
 * @assignment birinci ödev
 * @date 1/12/2022
 * @author AMRO MOUSA ISMAIL BASEET
 */
#ifndef Dugum_hpp
#define Dugum_hpp
using namespace std;
// bu sinifta yeni bir Dugum yapisi olusturuyorum,SatirSayisinin Dugumu
class Dugum
{
public:
    Dugum(int veri);
    // ~Dugum();

    int veri;
    Dugum *sonraki;
    Dugum *onceki;
};

#endif