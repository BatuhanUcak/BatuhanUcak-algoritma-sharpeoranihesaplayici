#include <stdio.h>
#include <stdlib.h>
//Sharpe orani hesaplama
//Risk oran�
//Yapmaya de�er mi?


int main() {
    float getiri, risksiz_faiz, standart_sapma, sharpe_orani;  //Ondal�kl� say�.
    int kontrol; //Harf girilirse hata vermesini sa�layacak de�i�ken.

    while (1) {
        printf("Yatirim Getirisini Giriniz. (%% olarak): "); //yat�r�m getirisi giri�i.
        kontrol = scanf("%f", &getiri);
        if (kontrol != 1) {
            printf("\033[1;31mHatali giris! Lutfen sayi giriniz.\033[0m\n\n");
            while (getchar() != '\n'); 
            continue;
        }

        printf("Risksiz Faiz Oranini Giriniz. (%% olarak): ");//risksiz faiz oran� giri�i.
        kontrol = scanf("%f", &risksiz_faiz);
        if (kontrol != 1) {
            printf("\033[1;31mHatali giris! Lutfen sayi giriniz.\033[0m\n\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Portfoyun Standart Sapmasini Giriniz. (%% olarak): ");//portfoyun standart sapmas�n�n giri�i.
        kontrol = scanf("%f", &standart_sapma);
        if (kontrol != 1) {
            printf("\033[1;31mHatali giris! Lutfen sayi giriniz.\033[0m\n\n");
            while (getchar() != '\n');
            continue;
        }

        if (standart_sapma == 0) {
            printf("\033[1;31mStandart sapma sifir olamaz. Hesaplama yapilamadi.\033[0m\n\n"); //Standart sapman�n s�f�r olma olas�l��� yoktur. Girilirse hata verir.
            continue;
        }
        
        {
        //------Y�ZDEL�K DE�ERLER� ORANA �EV�R------//
        getiri /= 100;
        risksiz_faiz /= 100;
        standart_sapma /= 100;
        
        sharpe_orani = (getiri - risksiz_faiz) / standart_sapma; //Sharpe Oran� hesaplama.
        printf("\nSharpe Orani: %.3f\n", sharpe_orani);//Sharpe Oran� sonucu.

        if (sharpe_orani < 1)  //Sharpe oran�n�n sonucu
            printf("\033[1;31mBu oran dusuk olarak kabul edilir.\033[0m\n");//Sharpe oran� k�t� oldu�u anlam�na gelir.
        else if (sharpe_orani < 2)
            printf("\033[38;5;208mBu oran iyi olarak kabul edilir.\033[0m\n");//Sharpe oran� iyi oldu�u anlam�na gelir.
        else if (sharpe_orani < 3)
            printf("\033[0;32mBu oran cok iyi olarak kabul edilir.\033[0m\n");//Sharpe oran� �ok iyi oldu�u anlam�na gelir.
        else
            printf("\033[0;32mBu oran mukemmel olarak kabul edilir.\033[0m\n");//Sharpe oran� m�kemmel oldu�u anlam�na gelir.
    }

    return 0;}//Kodun sonu, ba�lang�ca d�n��.
}
