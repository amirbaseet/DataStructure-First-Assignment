#include <Dugum.hpp>
#include <SatirListesi.hpp>
#include <YoneticiDugum.hpp>
#include <YoneticiListesi.hpp>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

int main()
{

  SatirListesi *test = new SatirListesi;
  test->Dugum_Ekle(1);
  test->Dugum_Ekle(2);
  test->Dugum_Ekle(3);

  SatirListesi *test1 = new SatirListesi;
  test1->Dugum_Ekle(1);
  test1->Dugum_Ekle(2);
  test1->Dugum_Ekle(99);

  SatirListesi *test3 = new SatirListesi;
  test3->Dugum_Ekle(1);
  test3->Dugum_Ekle(2);
  test3->Dugum_Ekle(8);
  SatirListesi *test4 = new SatirListesi;
  test4->Dugum_Ekle(1);
  test4->Dugum_Ekle(2);
  test4->Dugum_Ekle(999);
  YoneticiListesi YTest;
  YTest.Y_Dugum_Ekle(test1);
  YTest.Y_Dugum_Ekle(test4);
  YTest.YL_Yazdir(test1);
  // cout << *test1;
  // cout << YTest;
  // cout << *test << endl;
  // cout << *test3 << endl;
  // cout << YTest;
  // YTest.Y_Dugum_Siralama();
  // cout << YTest;
}
