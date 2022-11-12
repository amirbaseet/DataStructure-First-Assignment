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
          if (sayfa_Adet - burayakadar_yazdir > 0) // Eger son sayfada degil ve birinci sayfada da degil ise burda gersin
          {
               cout << "bordayiim 24\n";
               burayakadar_yazdir--;
          }
          else if (sayfa_Adet - burayakadar_yazdir == 0)
          {
               cout << "bordayiim 29\n";

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
void YD_sil_sonra(float &Baslangic, float &burayakadar_yazdir, float &sayfa_Adet)
{
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
}
Y_Dugum *sonraki_Dugum_git(Y_Dugum *secilen_YDugum, int &secilen, float &burayakadar_yazdir, float &Baslangic)
{
     if (secilen_YDugum->sonraki != 0 && secilen < (burayakadar_yazdir * 8 - Baslangic - 1))
     {

          cout << "\n221(burayakadar_yazdir - Baslangic - 1) " << (burayakadar_yazdir * 8 - Baslangic - 1) << endl;
          cout << "secilen YD = " << secilen_YDugum << "\tBaslangic = " << Baslangic << "\tburayakadar_yazdir " << burayakadar_yazdir * 8 << endl;

          /* Eger Secilen Dugum son ise sonrasina gitmez*/

          secilen++;
          secilen_YDugum = secilen_YDugum->sonraki;
     }
     return secilen_YDugum;
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
     cout << sayac << endl;

     myfile.close();
     SatirListesi *okun_st = new SatirListesi[sayac];
     myfile.open("src/veriler.txt");
     int Kacinci_sati = 0;
     char sil_mi;
     YoneticiListesi *YTest = new YoneticiListesi;

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
     // delete[] okun_st;
     YTest->Y_Dugum_Siralama();

     float birblok = 21.3; // her bir iki dugumun arasinda uzaklasacak mesafe
     // int birblok = 21; // her bir iki dugumun arasinda uzaklasacak mesafe
     int secilen = 0;
     float sayfa_Adet = 0.000;
     float burayakadar_yazdir;
     float Baslangic = 0.00;

     int uzaklasacak_mesafe = birblok * secilen;
     Y_Dugum *secilen_YDugum = YTest->ilkGetir();
     Y_Dugum *Silinecek_YD;
     Y_Dugum *ilk;

     Dugum *silinecek_Dugum;
     int silinecekDugumun_indeksi;
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
          // system("cls");

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
               secilen = 0;
               break;
          case 'a': // 8tane sola git
               solaGit(sayfa_Adet, burayakadar_yazdir, Baslangic);
               secilen_YDugum = YTest->ilkGetir();

               for (int i = 0; i < Baslangic; i++)
               {
                    /* code */
                    secilen_YDugum = secilen_YDugum->sonraki; // bu yeni Sayfanin ilk dugumu olacak
               }
               secilen = 0;
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
               secilen_YDugum = sonraki_Dugum_git(secilen_YDugum, secilen, burayakadar_yazdir, Baslangic);
               break;
          case 'k':
               // secilen ydugmun rastgele secme
               silinecekDugumun_indeksi = secilen_YDugum->S_Liste->Dugum_Sil_rastgele();
               silinecek_Dugum = secilen_YDugum->S_Liste->get_D_byindeks(silinecekDugumun_indeksi);
               cin >> sil_mi;
               if (sil_mi == 'k')
               {
                    secilen_YDugum->S_Liste->Dugum_Sil(silinecek_Dugum);

                    if (secilen_YDugum->S_Liste->Dugum_Sayisi_Getir() != 0)
                    {
                         secilen_YDugum->Ort_Getir();

                         YTest->Y_Dugum_Siralama();
                    }
                    else
                    {
                         ilk = YTest->ilkGetir(); // ilk dugumu Degiri getirdim
                         if (ilk != 0)            // Eger Hic bir dugum kalmamis ise burada girmez
                         {
                              Silinecek_YD = secilen_YDugum;
                              if (secilen_YDugum->onceki == 0)
                              {
                                   cout << "\265\n";
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

                              cout << "\n\n\n\n280Baslangic = " << Baslangic << "\tburayakadar_yazdir= " << burayakadar_yazdir * 8 << endl;
                              YTest->Y_Dugumun_Silme(Silinecek_YD); // onu silindikten sonra Y_Dugumun_Silme() fonksiyonda bir kosul koymustum eger hic bir dugum kalmadi ise Yonerici Listesi sil
                              YD_Dugumsayisi = YTest->YDugumSayisi_Getir();
                              YD_sil_sonra(Baslangic, burayakadar_yazdir, sayfa_Adet);
                         }
                    }
               }

               break;

          case 'p':
               /*p bastiginda Yonetici Dugumu Cikaritilacaktir*/
               ilk = YTest->ilkGetir(); // ilk dugumu Degiri getirdim
               if (ilk != 0)            // Eger Hic bir dugum kalmamis ise burada girmez
               {
                    Silinecek_YD = secilen_YDugum;
                    if (secilen_YDugum->onceki == 0)
                    {
                         cout << "\n249\n";
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

                    cout << "\n\n\n\n254Baslangic = " << Baslangic << "\tburayakadar_yazdir= " << burayakadar_yazdir * 8 << endl;
                    YTest->Y_Dugumun_Silme(Silinecek_YD); // onu silindikten sonra Y_Dugumun_Silme() fonksiyonda bir kosul koymustum eger hic bir dugum kalmadi ise Yonerici Listesi sil
                    YD_Dugumsayisi = YTest->YDugumSayisi_Getir();
                    YD_sil_sonra(Baslangic, burayakadar_yazdir, sayfa_Adet);
               }
               break;

          case '8':
               // delete[] okun_st;
               delete YTest; // Tüm düğümleri sil
               break;
          default:
               break;
          }
     } while (in != '8');
}
