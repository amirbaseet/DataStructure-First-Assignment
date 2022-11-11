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