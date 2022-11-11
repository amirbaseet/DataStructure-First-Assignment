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
void solaGit(float &sayfa_Adet, float &burayakadar_yazdir, float &Baslangic)
{
     cout << "\n\n\n\n17Baslangic = " << Baslangic << "\tburayakadar_yazdir= " << burayakadar_yazdir << "sayfa_Adet = " << sayfa_Adet << endl;

     cout << "\n\n\n\n17Baslangic = " << Baslangic << "\tburayakadar_yazdir - sayfa_Adet= " << burayakadar_yazdir - sayfa_Adet << "sayfa_Adet = " << sayfa_Adet << endl;

     if (sayfa_Adet - burayakadar_yazdir != sayfa_Adet - 1) // Eger ilk sayfada bulunmuyorsa onceki sayfa Yazdir
     {
          if (sayfa_Adet - burayakadar_yazdir >= 1)
          // if (sayfa_Adet - burayakadar_yazdir >= 1 || sayfa_Adet - burayakadar_yazdir == 0)
          {

               burayakadar_yazdir--;
          }
          else if (sayfa_Adet - burayakadar_yazdir == 0)
          {
               // eger tum elemanlari yazdirildi ise .000 kurtalmak icin
               burayakadar_yazdir = Baslangic / 8;
          }

          if (burayakadar_yazdir >= 1)
          { // Eger burayakadar_yazdir 8 taneden buyuk ise baslangic =burayakadar_yazdir -8
               Baslangic = burayakadar_yazdir - 1;
               cout << "\n\n\n\n39Baslangic = " << Baslangic * 8 << "\tburayakadar_yazdir= " << burayakadar_yazdir << endl;
          }
          else
          {
               Baslangic = 0;
               cout << "\n\n\n\n43Baslangic = " << Baslangic * 8 << "\tburayakadar_yazdir= " << burayakadar_yazdir << endl;
          }
          Baslangic *= 8;
     }
     // system("cls");
}
void SagGit(float &sayfa_Adet, float &burayakadar_yazdir, const int &YD_Dugumsayisi, float &Baslangic)
{
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
     }
}
int main()
{

     ifstream myfile("src/veriler.txt");
     // read line
     int sayac = 0;
     string satir;
     string bosluk = " ";
     /* code */
     if (!myfile)
          cout << "Erororororororoorororororororooror\n";
     while (getline(myfile, satir))
     {
          sayac++;
     }
     cout << "asdfsfd" << endl;
     cout << sayac << endl;

     myfile.close();
     SatirListesi *okun_st = new SatirListesi[sayac];
     myfile.open("src/veriler.txt");
     int satirdaki_sayilar = 0;
     size_t pos = 0;
     string stringnumber;
     int satirdakisayilar = 0;
     int *maxSayi = &satirdakisayilar;
     int Kacinci_sati = 0;
     // YoneticiListesi *YT_Liste;
     YoneticiListesi *YTest = new YoneticiListesi;

     int x[1000];
     string str;
     string token;
     while (std::getline(myfile, token))
     {
          istringstream ss(token);
          while (getline(ss, str, ' '))
          {
               okun_st[Kacinci_sati].Dugum_Ekle(stoi(str));
          }
          YTest->Y_Dugum_Ekle(&okun_st[Kacinci_sati]);
          Kacinci_sati++;
     }
     myfile.close();

     YTest->Y_Dugum_Siralama();

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
     char intest;
     do
     {

          YD_Dugumsayisi = YTest->YDugumSayisi_Getir();
          sayfa_Adet = YD_Dugumsayisi / 8;

          uzaklasacak_mesafe = birblok * secilen;
          if (YTest->ilkGetir())
          {
               YTest->YL_Sag_Yazdir(Baslangic, burayakadar_yazdir * 8);
               secilen_YDugum->S_Liste->YD_Sat_Dugm_Yazdir(uzaklasacak_mesafe);
               cout << "\nsecilen =" << secilen << "\n uzaklasacak_mesafe =" << uzaklasacak_mesafe << endl;

               cout << "secilen YD = " << secilen_YDugum << "\tBaslangic = " << Baslangic << "\tburayakadar_yazdir " << burayakadar_yazdir * 8 << endl;
               cout << "\n\n\n\n17Baslangic = " << Baslangic << "\tburayakadar_yazdir= " << burayakadar_yazdir << "sayfa_Adet = " << sayfa_Adet << endl;

               cin >> in;
          }
          else
          {
               YTest->YL_Yazdir();
               cout << "/nYonetici Listesi Bos oldugundan Bir sey Yazdirilmeyecktir lutfen 8 basin program kapatsin/n";
               cin >> intest;
               if (intest == '8')
               {
                    in = '8';
               }
          }

          switch (in)
          {
          case 'd': // 8tane sag git
               secilen_YDugum = YTest->ilkGetir();
               // if (YD_Dugumsayisi != 0)
               // {
               SagGit(sayfa_Adet, burayakadar_yazdir, YD_Dugumsayisi, Baslangic);

               for (int i = 0; i < Baslangic; i++)
               {
                    /* code */
                    secilen_YDugum = secilen_YDugum->sonraki; // bu yeni Sayfanin ilk dugumu olacak
               }
               cout << "\n\n\n181 secD = " << secilen_YDugum;
               // }
               // else
               // secilen_YDugum = 0;
               break;
          case 'a': // 8tane sola git
               solaGit(sayfa_Adet, burayakadar_yazdir, Baslangic);
               secilen_YDugum = YTest->ilkGetir();

               for (int i = 0; i < Baslangic; i++)
               {
                    /* code */
                    secilen_YDugum = secilen_YDugum->sonraki; // bu yeni Sayfanin ilk dugumu olacak
               }
               break;

               /*sonraki/onceki YDugum sec case z & c*/
          case 'z': /*Kullanıcı ‘z’ tuşuna bastığında seçili düğüm bir öncekine*/

               if (secilen_YDugum != YTest->ilkGetir() && secilen != 0)
               {
                    /*Eger Secilen Dugumun Onceki Dugumun adresi 0 degil ise onceki gitmez */

                    secilen--;
                    secilen_YDugum = secilen_YDugum->onceki;
               }

               break;
          case 'c': /*‘c’ tuşuna bastığında bir sonraki düğüme secer*/
               if (secilen_YDugum->sonraki != 0 && secilen < (burayakadar_yazdir * 8 - Baslangic - 1))
               {

                    cout << "\n221(burayakadar_yazdir - Baslangic - 1) " << (burayakadar_yazdir * 8 - Baslangic - 1) << endl;
                    cout << "secilen YD = " << secilen_YDugum << "\tBaslangic = " << Baslangic << "\tburayakadar_yazdir " << burayakadar_yazdir * 8 << endl;

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
                    if (secilen_YDugum->onceki == 0)
                    {
                         secilen_YDugum = secilen_YDugum->sonraki;
                    }
                    else
                    {
                         secilen_YDugum = secilen_YDugum->onceki;
                    }
                    if (secilen != 0) // Eger silinecek Dugum ilk Dugume isset ise secilenden azaltmaz
                    {

                         /* code */
                         secilen--;
                    }
                    cout << "\n254Ssecilen_YDugum = " << secilen_YDugum << endl;

                    cout << "\n\n\n\n254Baslangic = " << Baslangic << "\tburayakadar_yazdir= " << burayakadar_yazdir * 8 << endl;
                    YTest->Y_Dugumun_Silme(Silinecek_YD); // onu silindikten sonra Y_Dugumun_Silme() fonksiyonda bir kosul koymustum eger hic bir dugum kalmadi ise Yonerici Listesi sil
                    YD_Dugumsayisi = YTest->YDugumSayisi_Getir();
                    if (Baslangic == ((burayakadar_yazdir * 8) - 1)) // Eger Sayfada Tek Dugum Varsa silindikten sonra Sayfada Hic Bir dugum kalmadiginden  onceki Sayfa ya Yazdirilacak
                    {
                         cout << "\n\n\n\nsolaGit(sayfa_Adet, burayakadar_yazdir, Baslangic);\n";
                         solaGit(sayfa_Adet, burayakadar_yazdir, Baslangic);
                    }
                    else if (burayakadar_yazdir == sayfa_Adet)
                    {
                         burayakadar_yazdir *= 8;
                         burayakadar_yazdir--;
                         burayakadar_yazdir /= 8;
                    }
                    else
                    {
                         cout << "\n\n\n\n!!!!!!!!solaGit(sayfa_Adet, burayakadar_yazdir, Baslangic);\n";
                    }

                    //المشكلة انه ما بنقص من البداية والنهاية
                    /* code */
               }
               break;

          case '8':
               delete YTest; // Tüm düğümleri sil
               break;
          default:
               break;
          }
     } while (in != '8');
}
