#include <stdio.h>
#include <stdlib.h>

 typedef struct
{
    char plaka[7];
    char model[50];
    char renk[50];


}AracBilgi;

typedef struct
{
    float girisSaati;
    AracBilgi genel;

}Arac;

  void AraclariListele() ;

  void   AracEkle();

   Arac otoArac[1000];

int main()
{
    int secim,aracSayisi;



    printf("-----HOSGELDINIZ-----\n");


    printf("Kac  tane arac bilgisi girlecektir ? ");

    scanf("%d",&aracSayisi);

    printf("Isleminizi seciniz \n1-Arac Ekle\n2-Arac Listele\n");

    scanf("%d",&secim);

    if (secim==1)
      {

        AracEkle(aracSayisi);
      }


    else if(secim==2)

      {

         AraclariListele(aracSayisi) ;

      }


    else
        printf("Hatali secim\n");

}


void AracEkle(int a)//arascsayisiný a degerine aktardim

{
    int i;

    printf("Arac bilgilerinizi giriniz \n");

    for(i=0;i<a;i++)
    {
        printf("Aracinizin plakasini griniz-bosluk birakmayiniz-\n");

        scanf("%s",otoArac[i].genel.plaka);

        printf("Aracinizin rengini girniz\n");

        scanf("%s",otoArac[i].genel.renk);

        printf("Aracinizin modelini giriniz\n");

        scanf("%s",otoArac[i].genel.model);

        printf("Aracinizin otoparka giris saatiniz giriniz ");

        scanf("%f",&otoArac[i].girisSaati);

    }

    AraclariListele(a);

}

void AraclariListele(int a)

{
    int i;

    for(i=0;i<a;i++)

    {
        printf("%d numarali aracin\n plakasi %s\n rengi %s\n moldeli %s\n otoparka giris saati %2.2f \n",
               i+1,otoArac[i].genel.plaka,otoArac[i].genel.renk,otoArac[i].genel.model,otoArac[i].girisSaati);



    }



}
