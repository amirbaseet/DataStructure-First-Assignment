#include <Dugum.hpp>
#include <SatirListesi.hpp>
#include <YoneticiDugum.hpp>
#include <YoneticiListesi.hpp>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
     SatirListesi *test = new SatirListesi;
     test->Dugum_Ekle(1);
     test->Dugum_Ekle(2);
     test->Dugum_Ekle(3);

     SatirListesi *test1 = new SatirListesi;
     test1->Dugum_Ekle(1);
     test1->Dugum_Ekle(240);
     test1->Dugum_Ekle(99);

     SatirListesi *test3 = new SatirListesi;
     test3->Dugum_Ekle(177);
     test3->Dugum_Ekle(882);
     test3->Dugum_Ekle(844);
     test3->Dugum_Ekle(904);
     test3->Dugum_Ekle(841);
     test3->Dugum_Ekle(759);
     test3->Dugum_Ekle(844);

     SatirListesi *test4 = new SatirListesi;
     test4->Dugum_Ekle(1);
     test4->Dugum_Ekle(2);

     YoneticiListesi *YTest = new YoneticiListesi;
     YTest->Y_Dugum_Ekle(test1);
     YTest->Y_Dugum_Ekle(test);
     YTest->Y_Dugum_Ekle(test3);
     YTest->Y_Dugum_Ekle(test4);
     YTest->Y_Dugum_Siralama();
     // YTest.YL_Yazdir();
     int birblok = 22; // her bir iki dugumun arasinda uzaklasacak mesafe
     int secilen = 0;
     int uzaklasacak_mesafe = birblok * secilen;
     Y_Dugum *secilen_YDugum = YTest->ilkGetir();
     Y_Dugum *Silinecek_YD;
     Y_Dugum *ilk;
     char in;

     secilen_YDugum->S_Liste->YD_Sat_Dugm_Yazdir(uzaklasacak_mesafe);
     do
     {
          system("cls");
          cout << *YTest;
          uzaklasacak_mesafe = birblok * secilen;
          secilen_YDugum->S_Liste->YD_Sat_Dugm_Yazdir(uzaklasacak_mesafe);
          cout << "\nSecilen = " << secilen << "\tILK DUGUM = " << YTest->ilkGetir() << endl;
          cin >> in;
          switch (in)
          {
               /*sonraki/onceki YDugum sec case z &c*/
          case 'z': /*Kullanıcı ‘z’ tuşuna bastığında seçili düğüm bir öncekine*/

               if (secilen_YDugum != YTest->ilkGetir())
               {
                    /*Eger Secilen Dugumun Onceki Dugumun adresi 0 degil ise onceki gitmez */

                    secilen--;
                    secilen_YDugum = secilen_YDugum->onceki;
               }

               cout << *YTest;

               // uzaklasacak_mesafe = birblok * secilen;
               // secilen_YDugum->S_Liste->YD_Sat_Dugm_Yazdir(uzaklasacak_mesafe);

               break;
          case 'c': /*‘c’ tuşuna bastığında bir sonraki düğüme secer*/
               if (secilen_YDugum->sonraki != 0)
               {
                    /* Eger Secilen Dugum son ise sonrasina gitmez*/
                    secilen++;
                    secilen_YDugum = secilen_YDugum->sonraki;
               }

               // secilen_YDugum->S_Liste->YD_Sat_Dugm_Yazdir(uzaklasacak_mesafe);

               break;
          case 'p':
               /*p bastiginda Yonetici Dugumu Cikaritilacaktir*/
               ilk = YTest->ilkGetir(); // ilk dugumu Degiri getirdim
               if (ilk != 0)            // Eger Hic bir dugum kalmamis ise burada girmez
               {
                    Silinecek_YD = secilen_YDugum;
                    if (secilen_YDugum->onceki != 0)
                    {
                         secilen_YDugum = secilen_YDugum->onceki;
                         secilen--;
                    }
                    else
                    {
                         secilen_YDugum = secilen_YDugum->sonraki;
                         if (Silinecek_YD != ilk) // Eger silinecek Dugum ilk Dugume isset ise secilenden azaltmaz
                         {
                              /* code */
                              secilen--;
                         }
                    }

                    if (YTest->YDugumSayisi_Getir() == 1)
                    {
                         YTest->Y_Dugumun_Silme(Silinecek_YD); // onu silindikten sonra Y_Dugumun_Silme() fonksiyonda bir kosul koymustum eger hic bir dugum kalmadi ise Yonerici Listesi sil
                         cout << "Hic bir Dugum kalmadigi icin Yonetici listesi silinicek program sonlandirilacak\n";
                         in = '8';
                    }
                    else
                         YTest->Y_Dugumun_Silme(Silinecek_YD); // onu silindikten sonra Y_Dugumun_Silme() fonksiyonda bir kosul koymustum eger hic bir dugum kalmadi ise Yonerici Listesi sil

                    /* code */
               }

               break;
          default:
               break;
          }
          /* code */
     } while (in != '8');

     // cout << setw(37) << *test1;
     // test1->YD_Sat_Dugm_Yazdir(UzaklasacakMesafe);
}
