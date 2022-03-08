#include <stdio.h>
#include <stdlib.h>
#include<time.h>

 void diziYazdir(int *tekPtr,int *ciftPtr,int a,int b)
{
    int i;
    printf("** TEK SAYILI DIZIMIZ**\n");

    for( i=0;i<a;i++)
    {
        printf("%d inci eleman %d\n",i+1,*(tekPtr+i));
    }

    printf("*CIFT SAYILI DIZIMIZ*\n");

    for(i=0;i<b;i++)
    {
        printf("%d inci elemaninimiz %d \n",i+1,*(ciftPtr+i));
    }

}



void  tekMiCiftMi(int *diziPtr)

{
    int i,m=0,n=0;

    int diziTek[10],diziCift[10];

      int *tekPtr=diziTek ,*ciftPtr=diziCift;


    for(i=0;i<10;i++)
    {

  /*EGER DÝZÝYLE YAPTIRMAK ÝSTESEYDÝK

        if(*(diziPtr+i)%2==0)
          {
               diziCift[m]= *(diziPtr+i) ;

               m++;
          }

          else
          {
              diziTek[n]= *(diziPtr+i);

              n++;


          }
    }

       */


       if(*(diziPtr+i)%2==0)
        {
             *ciftPtr = *(diziPtr+i);

              ciftPtr++;

               m++;
        }

        else
        {
            *tekPtr = *(diziPtr+i);

             tekPtr++;

            n++;
        }
   }

    diziYazdir(diziTek,diziCift,n,m);



}

   int main()
  {

    void  diziYazdir(int *tekPtr,int *ciftPtr,int a,int b);

    void  tekMiCiftMi(int *diziPtr);

    int dizi[10],i,*diziPtr;

    diziPtr=&dizi[0];

    srand(time(NULL));


    printf("*Random Dizimiz* \n");

    for(i=0;i<10;i++)
    {
        *(diziPtr+i)=1+rand()%100;

        printf("%d inci eleman %d\n ",i+1,*(diziPtr+i));

    }

     tekMiCiftMi( diziPtr);


        return 0;
  }
