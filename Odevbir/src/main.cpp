#include <Dugum.hpp>
#include <SatirListesi.hpp>
#include <YoneticiDugum.hpp>
#include <YoneticiListesi.hpp>
#include <iostream>
using namespace std;
int main()
{
  // SatirListesi *test = new SatirListesi;
  // test->Dugum_Ekle(1);

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
  YTest.Y_Dugum_Ekle(test);
  YTest.Y_Dugum_Ekle(test1);
  YTest.Y_Dugum_Ekle(test);
  YTest.Y_Dugum_Ekle(test1);
  YTest.Y_Dugum_Ekle(test4);
  YTest.Y_Dugum_Ekle(test);
  YTest.Y_Dugum_Ekle(test1);
  YTest.Y_Dugum_Ekle(test);
  YTest.Y_Dugum_Ekle(test1);
  YTest.Y_Dugum_Ekle(test1);
  YTest.Y_Dugum_Ekle(test);
  cout << YTest;
  // cout << YTest;
  YTest.Y_Dugum_Siralama();
  cout << YTest;

  // YTest.S_Dugumun_Silme(test);

  // cout << YTest;

  // // cout << *test << endl;
  // YTest.Y_Dugum_Ekle(test);
  // YTest.Y_Dugum_Ekle(test1);
  // cout << YTest;
  // // cout << *test;

  // cout << YTest;
}
