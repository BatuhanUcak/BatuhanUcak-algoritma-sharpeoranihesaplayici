#include <stdio.h>
#include <stdlib.h>
//Sharpe orani hesaplama
//Risk oraný
//Yapmaya deðer mi?


int main() {
    float getiri, risksiz_faiz, standart_sapma, sharpe_orani;  //Ondalýklý sayý.
    int kontrol; //Harf girilirse hata vermesini saðlayacak deðiþken.

    while (1) {
        printf("Yatirim Getirisini Giriniz. (%% olarak): "); //yatýrým getirisi giriþi.
        kontrol = scanf("%f", &getiri);
        if (kontrol != 1) {
            printf("\033[1;31mHatali giris! Lutfen sayi giriniz.\033[0m\n\n");
            while (getchar() != '\n'); 
            continue;
        }

        printf("Risksiz Faiz Oranini Giriniz. (%% olarak): ");//risksiz faiz oraný giriþi.
        kontrol = scanf("%f", &risksiz_faiz);
        if (kontrol != 1) {
            printf("\033[1;31mHatali giris! Lutfen sayi giriniz.\033[0m\n\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Portfoyun Standart Sapmasini Giriniz. (%% olarak): ");//portfoyun standart sapmasýnýn giriþi.
        kontrol = scanf("%f", &standart_sapma);
        if (kontrol != 1) {
            printf("\033[1;31mHatali giris! Lutfen sayi giriniz.\033[0m\n\n");
            while (getchar() != '\n');
            continue;
        }

        if (standart_sapma == 0) {
            printf("\033[1;31mStandart sapma sifir olamaz. Hesaplama yapilamadi.\033[0m\n\n"); //Standart sapmanýn sýfýr olma olasýlýðý yoktur. Girilirse hata verir.
            continue;
        }
        
        {
        //------YÜZDELÝK DEÐERLERÝ ORANA ÇEVÝR------//
        getiri /= 100;
        risksiz_faiz /= 100;
        standart_sapma /= 100;
        
        sharpe_orani = (getiri - risksiz_faiz) / standart_sapma; //Sharpe Oraný hesaplama.
        printf("\nSharpe Orani: %.3f\n", sharpe_orani);//Sharpe Oraný sonucu.

        if (sharpe_orani < 1)  //Sharpe oranýnýn sonucu
            printf("\033[1;31mBu oran dusuk olarak kabul edilir.\033[0m\n");//Sharpe oraný kötü olduðu anlamýna gelir.
        else if (sharpe_orani < 2)
            printf("\033[38;5;208mBu oran iyi olarak kabul edilir.\033[0m\n");//Sharpe oraný iyi olduðu anlamýna gelir.
        else if (sharpe_orani < 3)
            printf("\033[0;32mBu oran cok iyi olarak kabul edilir.\033[0m\n");//Sharpe oraný çok iyi olduðu anlamýna gelir.
        else
            printf("\033[0;32mBu oran mukemmel olarak kabul edilir.\033[0m\n");//Sharpe oraný mükemmel olduðu anlamýna gelir.
    }

    return 0;}//Kodun sonu, baþlangýca dönüþ.
}
