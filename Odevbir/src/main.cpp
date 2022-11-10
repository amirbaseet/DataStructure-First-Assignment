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
     SatirListesi *test5 = new SatirListesi;
     test5->Dugum_Ekle(177);
     test5->Dugum_Ekle(882);
     test5->Dugum_Ekle(844);
     test5->Dugum_Ekle(904);
     test5->Dugum_Ekle(841);
     test5->Dugum_Ekle(759);
     test5->Dugum_Ekle(844);
     SatirListesi *test6 = new SatirListesi;
     test6->Dugum_Ekle(177);
     test6->Dugum_Ekle(882);
     test6->Dugum_Ekle(844);
     test6->Dugum_Ekle(904);
     test6->Dugum_Ekle(841);
     test6->Dugum_Ekle(759);
     test6->Dugum_Ekle(844);
     SatirListesi *test7 = new SatirListesi;
     test7->Dugum_Ekle(177);
     test7->Dugum_Ekle(882);
     test7->Dugum_Ekle(844);
     test7->Dugum_Ekle(904);
     test7->Dugum_Ekle(841);
     test7->Dugum_Ekle(759);
     test7->Dugum_Ekle(844);
     SatirListesi *test8 = new SatirListesi;
     test8->Dugum_Ekle(177);
     test8->Dugum_Ekle(882);
     test8->Dugum_Ekle(844);
     test8->Dugum_Ekle(904);
     test8->Dugum_Ekle(841);
     test8->Dugum_Ekle(759);
     test8->Dugum_Ekle(844);

     SatirListesi *test4 = new SatirListesi;
     test4->Dugum_Ekle(1);
     test4->Dugum_Ekle(2);

     YoneticiListesi *YTest = new YoneticiListesi;
     YTest->Y_Dugum_Ekle(test);
     YTest->Y_Dugum_Ekle(test1);
     YTest->Y_Dugum_Ekle(test3);
     YTest->Y_Dugum_Ekle(test4);
     YTest->Y_Dugum_Ekle(test5);
     YTest->Y_Dugum_Ekle(test6);
     YTest->Y_Dugum_Ekle(test7);
     YTest->Y_Dugum_Ekle(test8);
     YTest->Y_Dugum_Ekle(test8);
     YTest->Y_Dugum_Siralama();
     // cout << *YTest;
     // cout << "-------------" << endl;
     // Y_Dugum *ben = YTest->YL_Sag_Yazdir(2, 3, YTest->ilkGetir());
     // cout << ben;
     // YTest.YL_Yazdir();
     int birblok = 22; // her bir iki dugumun arasinda uzaklasacak mesafe
     int secilen = 0;
     float sayfa_Adet = 0.000;
     float burayakadar_yazdir;
     float Baslangic = 0.00;

     int uzaklasacak_mesafe = birblok * secilen;
     Y_Dugum *secilen_YDugum = YTest->ilkGetir();
     Y_Dugum *Silinecek_YD;
     Y_Dugum *ilk;
     char in;
     float YD_Dugumsayisi = YTest->YDugumSayisi_Getir();
     sayfa_Adet = YD_Dugumsayisi / 8;
     if (YD_Dugumsayisi / 8 >= 1)
     {
          burayakadar_yazdir = 1;
     }
     else
          burayakadar_yazdir = YD_Dugumsayisi / 8;

     // secilen_YDugum = YTest->YL_Sag_Yazdir((burayakadar_yazdirilan - 1) * 8, (burayakadar_yazdirilan)*8, secilen_YDugum);

     do
     {
          system("cls");

          YD_Dugumsayisi = YTest->YDugumSayisi_Getir();
          if (YD_Dugumsayisi / 8 >= 1)
          {
               burayakadar_yazdir = 1;
          }
          else
               burayakadar_yazdir = YD_Dugumsayisi / 8;
          uzaklasacak_mesafe = birblok * secilen;

          YTest->YL_Sag_Yazdir(Baslangic, burayakadar_yazdir * 8, secilen_YDugum);
          secilen_YDugum->S_Liste->YD_Sat_Dugm_Yazdir(uzaklasacak_mesafe);

          cout << "\nsecilen =" << secilen << "\n uzaklasacak_mesafe =" << uzaklasacak_mesafe << endl;

          cout << "secilen YD = " << secilen_YDugum << "\tBaslangic = " << Baslangic << "\tburayakadar_yazdir " << burayakadar_yazdir * 8 << endl;

          cin >> in;
          switch (in)
          {
          case 'd': // 8tane sag git
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
                    secilen = 0;
                    if (YD_Dugumsayisi != 0)
                    {
                         secilen_YDugum = YTest->YL_Sag_Yazdir(Baslangic, burayakadar_yazdir * 8, secilen_YDugum);
                    }
                    else
                         secilen_YDugum = 0;

                    system("cls");
               }

               break;
          case 'a': // 8tane sola git
               // 16-8=8
               ///
               if (sayfa_Adet - burayakadar_yazdir != 0)
               {

                    if (sayfa_Adet - burayakadar_yazdir >= 1)
                    {
                         burayakadar_yazdir--;
                    }
                    else if (sayfa_Adet - burayakadar_yazdir > 0 && sayfa_Adet - burayakadar_yazdir < 1)
                    {
                         burayakadar_yazdir -= (sayfa_Adet - burayakadar_yazdir);
                    }
                    secilen = 0;
                    if (burayakadar_yazdir > 1) // Eger burayakadar_yazdir 8 taneden buyuk ise baslangic =burayakadar_yazdir -8
                         Baslangic = burayakadar_yazdir - 1;
                    else
                         Baslangic = 0;
                    Baslangic *= 8;
                    if (YD_Dugumsayisi != 0)
                    {
                         secilen_YDugum = YTest->YL_Sag_Yazdir(Baslangic, burayakadar_yazdir * 8, secilen_YDugum);
                    }
                    else
                         secilen_YDugum = 0;
                    system("cls");
               }
               break;

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
                    YTest->Y_Dugumun_Silme(Silinecek_YD); // onu silindikten sonra Y_Dugumun_Silme() fonksiyonda bir kosul koymustum eger hic bir dugum kalmadi ise Yonerici Listesi sil
                    YD_Dugumsayisi = YTest->YDugumSayisi_Getir();

                    /* code */
               }
               break;

          case '8':
               delete YTest; // Tüm düğümleri sil
               break;
          default:
               break;
          }
          /* code */
     } while (secilen_YDugum != 0);
     // } while (in != '8');

     // cout << setw(37) << *test1;
     // test1->YD_Sat_Dugm_Yazdir(UzaklasacakMesafe);
}
