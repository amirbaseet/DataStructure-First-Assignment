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

     SatirListesi *test4 = new SatirListesi;
     test4->Dugum_Ekle(1);
     test4->Dugum_Ekle(2);

     YoneticiListesi *YTest = new YoneticiListesi;
     YTest->Y_Dugum_Ekle(test1);
     // YTest->Y_Dugum_Ekle(test);
     // YTest->Y_Dugum_Ekle(test3);
     // YTest->Y_Dugum_Ekle(test4);
     cout << "\n/**********************/\nSiralama yaptim\n";
     YTest->Y_Dugum_Siralama();
     // YTest.YL_Yazdir();
     int birblok = 22; // her bir iki dugumun arasinda uzaklasacak mesafe
     int secilen = 0;
     int uzaklasacak_mesafe = birblok * secilen;
     Y_Dugum *secilen_YDugum = YTest->ilkGetir();
     Y_Dugum *Silinecek_YD;
     char in;
     system("cls");

     cout << *YTest;

     secilen_YDugum->S_Liste->YD_Sat_Dugm_Yazdir(uzaklasacak_mesafe);
     do
     {
          cin >> in;
          system("cls");
          // cout << *YTest;
          // uzaklasacak_mesafe = birblok * secilen;
          // secilen_YDugum->S_Liste->YD_Sat_Dugm_Yazdir(uzaklasacak_mesafe);
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

                    secilen_YDugum = secilen_YDugum->sonraki;
                    secilen++;
                    cout << secilen;
               }

               // secilen_YDugum->S_Liste->YD_Sat_Dugm_Yazdir(uzaklasacak_mesafe);

               break;
          case 'p':
               cout << "\5\n";
               /*p bastiginda Yonetici Dugumu Cikaritilacaktir*/
               if (YTest->ilkGetir() != 0) // Eger Hic bir dugum kalmamis ise burada girmez
               {
                    cout << "\n100\n";
                    Silinecek_YD = secilen_YDugum;
                    if (secilen_YDugum->onceki != 0)
                    {
                         secilen_YDugum = secilen_YDugum->onceki;
                    }
                    else
                    {
                         secilen_YDugum = secilen_YDugum->sonraki;
                    }
                    secilen--;

                    if (secilen < 0)
                         secilen = 0;

                    cout << "||" << YTest->YDugumSayisi_Getir() << endl;

                    YTest->Y_Dugumun_Silme(Silinecek_YD); // onu silindikten sonra Y_Dugumun_Silme() fonksiyonda bir kosul koymustum eger hic bir dugum kalmadi ise Yonerici Listesi sil
                    cout << YTest->YDugumSayisi_Getir() << endl;

                    /* code */
                    cout << "\n\n121\n";
                    cout << "\n\n123\n";
               }
               else
               {
                    cout << "Hic bir Dugum kalmadigi icin Yonetici listesi silinicek program sonlandirilacak\n";
                    // exit(1);
                    in = '8';
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
