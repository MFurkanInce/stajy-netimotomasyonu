#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int ogrencinumara;
    char ogrenciad[30];
    char ogrencisoyad[30];
}ogrenci;
typedef struct
{
    int FirmaVergiNo;
    char FirmaAd[30];
    char FirmaFaaliyet[30];
}firma;
typedef struct
{
    int stajTur;
    int stajYVergiNo;
    int stajYOgrenciNo;
    int stajYBaslangicGun;
    int stajYBaslangicAy;
    int stajYBaslangicYil;
    int stajYBitisGun;
    int stajYBitisAy;
    int stajYBitisYil;
    int stajYToplamHafta;
    int stajDVergiNo;
    int stajDOgrenciNo;
    int stajDBaslangicGun;
    int stajDBaslangicAy;
    int stajDBaslangicYil;
    int stajDBitisGun;
    int stajDBitisAy;
    int stajDBitisYil;
    int stajDToplamHafta;
    int stajToplamHafta;
}staj;
int i=0,arananNo=0,arananNo2=0,m,f;
int NoSearch=0,NoSearch2=0,NoSearch3=0,NoSearch4=0;
int main()
{
    FILE *ogrencibilgi;
    FILE *firmabilgi;
    FILE *stajbilgi;
    ogrenci ogr[30];
    firma fir[30];
    staj sta[30];
   int menu;
   int i=0;
   int k,s,stajSayac,stajm,staji,p;
   int arananNo;
 int menuInput;
 basla:
    printf("\n\n\t\t OGRENCI MENUSU\n");
    printf("\t__________________________________ \n\n");
    printf("\t   1.Ogrenci Ekleme Menusu\n");
    printf("\t   2.Ogrenci Duzenleme Menusu\n");
    printf("\t   3.Ogrenci Silme Menusu\n");
    printf("\t   4.Ogrenci Listeleme Menusu\n\n");
    printf("\t\t FIRMA MENUSU\n");
    printf("\t__________________________________ \n\n");
    printf("\t   5.Firma Ekleme Menusu\n");
    printf("\t   6.Firma Duzenleme Menusu\n");
    printf("\t   7.Firma Silme Menusu\n");
    printf("\t   8.Firma Listeleme Menusu\n\n");
    printf("\t\t STAJ MENUSU\n");
    printf("\t__________________________________ \n\n");
    printf("\t   9.Staj Ekleme Menusu\n");
    printf("\t   10.Tamamlanmis Staj Menusu\n");
    printf("\t   11.Tamamlanmamis Staj Menusu\n\n");
    printf("\t__________________________________ \n\n");
    printf("Gitmek istediginiz menuyu tuslayin:");
    scanf("%d",&menuInput);
if(menuInput==1)
{
          printf("\n YENI OGRENCININ ISMI:");
          scanf("%s",&ogr[i].ogrenciad);
          printf(" YENI OGRENCININ SOYADI:");
          scanf("%s",&ogr[i].ogrencisoyad);
        ogr[i].ogrencinumara=i+1;
        ogrencibilgi=fopen("ogrencibilgiler.txt","a");
        fprintf(ogrencibilgi,"%d",ogr[i].ogrencinumara);
        fprintf(ogrencibilgi,"%s",ogr[i].ogrenciad);
        fprintf(ogrencibilgi,"%s \n",ogr[i].ogrencisoyad);
        fclose(ogrencibilgi);
        i++;
       goto basla;
}
if(menuInput==2)
{
    NoSearch=0;
  printf("\n DUZENLEME YAPMAK ISTEDIGINIZ OGRENCININ NUMARASINI GIRINIZ: ");
  scanf("%d",&arananNo);
  ogrencibilgi=fopen("ogrencibilgiler.txt","r+");
 for(k=0;k<i+1;k++)
 {
            if(ogr[k].ogrencinumara==arananNo)
            {
            printf("\n OGRENCININ YENI ADI: ");
            scanf("%s",&ogr[k].ogrenciad);
            printf("\n OGRENCININ YENI SOYADI: ");
            scanf("%s",&ogr[k].ogrencisoyad);
            NoSearch=1;
            }
    fprintf(ogrencibilgi,"%d",ogr[k].ogrencinumara);
    fprintf(ogrencibilgi,"%s",ogr[k].ogrenciad);
    fprintf(ogrencibilgi,"%s",ogr[k].ogrencisoyad);
}
if (NoSearch==0)
        {
            printf(" !!! BOYLE BIR NUMARAYA SAHIP OGRENCI BULUNMAMAKTADIR !!! \n");
        }
        fclose(ogrencibilgi);

    goto basla;
}
if(menuInput==3)
{
     NoSearch2=0;
    printf("\n SILMEK ISTEDIGINIZ OGRENCININ NUMARASI: ");
    scanf("%d",&arananNo);
    ogrencibilgi=fopen("ogrencibilgiler.txt","r+");
    for(k=0;k<i+1;k++)
    {
         if(ogr[k].ogrencinumara== arananNo)
         {
                strcpy(ogr[k].ogrenciad,"Silinmistir");
                strcpy(ogr[k].ogrencisoyad,"Silinmistir");
                NoSearch2=1;
                printf("\n SILME ISLEMI BASARI ILE GERCEKLESMISTIR \n");
         }
    fprintf(ogrencibilgi,"%d",ogr[k].ogrencinumara);
    fprintf(ogrencibilgi,"%s",ogr[k].ogrenciad);
    fprintf(ogrencibilgi,"%s",ogr[k].ogrencisoyad);
    }
    if (NoSearch2==0)
        {
             printf(" !!! BOYLE BIR NUMARAYA SAHIP OGRENCI BULUNMAMAKTADIR !!! \n");
        }
        fclose(ogrencibilgi);
        goto basla;
}
if(menuInput==4)
{
        printf("\n \t\t OGRENCI LISTESI \n");
        printf("\t______________________________\n");
        printf("\n\tOGRENCI NO \t OGRENCI AD \t\t\t     OGRENCI SOYAD\n");

        for(k=0;k<i;k++)
        {
            printf("\t    %d\t\t   %s\t\t          \t%s \n",ogr[k].ogrencinumara,ogr[k].ogrenciad,ogr[k].ogrencisoyad);
        }
    goto basla;
}
if(menuInput==5)
{
          printf("\nYENI FIRMANIN ISMI:");
          scanf("%s",&fir[m].FirmaAd);
          printf("YENI FIRMANIN FAALIYET ALANI:");
          scanf("%s",&fir[m].FirmaFaaliyet);
        fir[m].FirmaVergiNo=m+1;
        firmabilgi=fopen("firmabilgiler.txt","a");
        fprintf(firmabilgi,"%d",fir[m].FirmaVergiNo);
        fprintf(firmabilgi,"%s",fir[m].FirmaAd);
        fprintf(firmabilgi,"%s \n",fir[m].FirmaFaaliyet);
        fclose(firmabilgi);
        m++;
       goto basla;
}
if(menuInput==6)
{
    NoSearch3=0;
  printf("\nDUZENLEMEK ISTEDIGINIZ FIRMANIN VERGI NUMARASINI GIRINIZ: ");
  scanf("%d",&arananNo);
  firmabilgi=fopen("firmabilgiler.txt","r+");
 for(k=0;k<m+1;k++)
 {
            if(fir[k].FirmaVergiNo==arananNo)
            {
            printf("FIRMANIN YENI ADI: ");
            scanf("%s",&fir[k].FirmaAd);
            printf("FIRMANIN YENI FAALIYET ALANI: ");
            scanf("%s",&fir[k].FirmaFaaliyet);
            NoSearch3=1;
            }
    fprintf(firmabilgi,"%d ",fir[k].FirmaVergiNo);
    fprintf(firmabilgi,"%s ",fir[k].FirmaAd);
    fprintf(firmabilgi,"%s \n",fir[k].FirmaFaaliyet);
}
        if (NoSearch3==0)
        {
            printf(" !!! BOYLE BIR NUMARAYA SAHIP FIRMA BULUNMAMAKTADIR !!! \n");
        }
        fclose(firmabilgi);
    goto basla;
}
if(menuInput==7)
{
 NoSearch4=0;
    printf("\nSILMEK ISTEDIGINIZ FIRMANIN VERGI NUMARASI: ");
    scanf("%d",&arananNo);
    ogrencibilgi=fopen("firmabilgiler.txt","r+");
    for(k=0;k<m+1;k++)
    {
         if(fir[k].FirmaVergiNo == arananNo)
         {
                strcpy(fir[k].FirmaAd,"Silinmistir");
                strcpy(fir[k].FirmaFaaliyet,"Silinmistir");
                printf("\n SILME ISLEMI BASARI ILE GERCEKLESMISTIR \n");
                NoSearch4=1;
         }
    fprintf(ogrencibilgi,"%d ",fir[k].FirmaVergiNo);
    fprintf(ogrencibilgi,"%s ",fir[k].FirmaAd);
    fprintf(ogrencibilgi,"%s \n",fir[k].FirmaFaaliyet);
    }
    if (NoSearch4==0)
        {
             printf(" !!! BOYLE BIR NUMARAYA SAHIP FIRMA BULUNMAMAKTADIR !!! \n");
        }
        fclose(ogrencibilgi);
        goto basla;
}
if(menuInput==8)
{
        printf("\n \t\t FIRMA LISTESI \n");
        printf("\t______________________________\n");
        printf("\n\tVERGI NO \t  FIRMA AD \t\t\t     FIRMA FAALIYET ALANI\n");
        for(k=0;k<m;k++)
        {
            printf("\t    %d\t\t   %s\t\t          \t%s \n",fir[k].FirmaVergiNo,fir[k].FirmaAd,fir[k].FirmaFaaliyet);
        }
    goto basla;
}
if(menuInput==9)
{
    stajbilgi=fopen("stajbilgiler.txt","a");
                      printf("\nSTAJ EKLEMESI YAPMAK ISTEDIGINIZ OGRENCI NUMARASINI GIRINIZ: ");
                      scanf("%d",&sta[stajSayac].stajYOgrenciNo);
                      for (staji=0;staji<i+1;staji++)
                      {
                      if (sta[stajSayac].stajYOgrenciNo==ogr[staji].ogrencinumara)
                      {
                            sta[stajSayac].stajYOgrenciNo=ogr[staji].ogrencinumara;
                            printf("OGRENCININ YAZILIM STAJINI YAPTIGI FIRMA VERGI NUMARASINI GIRINIZ: ");
                            scanf("%d",&sta[stajSayac].stajYVergiNo);
                                for (stajm=0;stajm<m+1;stajm++)
                                {
                                    if (sta[stajSayac].stajYVergiNo==fir[stajm].FirmaVergiNo)
                                {
                                  staj:
                               printf("OGRENCININ YAZILIM STAJINA BASLADIGI GUN : ");
                               scanf("%d",&sta[stajSayac].stajYBaslangicGun);
                                 while ( sta[stajSayac].stajYBaslangicGun<0 || sta[stajSayac].stajYBaslangicGun>30 )
                               {
                                   printf("!!! GECERSIZ ARALIK GIRDINIZ TEKRAR GIRINIZ\n");
                                   printf("OGRENCININ YAZILIM STAJINA BASLADIGI GUN : ");
                               scanf("%d",&sta[stajSayac].stajYBaslangicGun);
                               }
                               printf("OGRENCININ YAZILIM STAJINA BASLADIGI AY : ");
                               scanf("%d",&sta[stajSayac].stajYBaslangicAy);
                                  while ( sta[stajSayac].stajYBaslangicAy<0 || sta[stajSayac].stajYBaslangicAy>12 )
                               {
                                   printf("!!! GECERSIZ ARALIK GIRDINIZ TEKRAR GIRINIZ\n");
                                   printf("OGRENCININ YAZILIM STAJINA BASLADIGI GUN : ");
                               scanf("%d",&sta[stajSayac].stajYBaslangicAy);
                               }
                               printf("OGRENCININ YAZILIM STAJINA BASLADIGI YIL : ");
                               scanf("%d",&sta[stajSayac].stajYBaslangicYil);
                               printf("OGRENCININ YAZILIM STAJINI BITIRDIGI GUN : ");
                               scanf("%d",&sta[stajSayac].stajYBitisGun);
                               while ( sta[stajSayac].stajYBitisGun<0 || sta[stajSayac].stajYBitisGun>30 )
                               {
                                   printf("!!! GECERSIZ ARALIK GIRDINIZ TEKRAR GIRINIZ\n");
                                   printf("OGRENCININ YAZILIM STAJINI BITIRDIGI GUN : ");
                               scanf("%d",&sta[stajSayac].stajYBitisGun);
                               }
                               printf("OGRENCININ YAZILIM STAJINI BITIRDIGI AY : ");
                               scanf("%d",&sta[stajSayac].stajYBitisAy);
                               while ( sta[stajSayac].stajYBitisAy<0 || sta[stajSayac].stajYBitisAy>12 )
                               {
                                   printf("!!! GECERSIZ ARALIK GIRDINIZ TEKRAR GIRINIZ\n");
                                   printf("OGRENCININ YAZILIM STAJINI BITIRDIGI GUN : ");
                               scanf("%d",&sta[stajSayac].stajYBitisAy);
                               }
                               printf("OGRENCININ YAZILIM STAJINI BITIRDIGI  YIL : ");
                               scanf("%d",&sta[stajSayac].stajYBitisYil);
                                if (sta[stajSayac].stajYBitisAy<sta[stajSayac].stajYBaslangicAy)
                                {
                                sta[stajSayac].stajYToplamHafta = sta[stajSayac].stajYToplamHafta + (sta[stajSayac].stajYBitisGun-sta[stajSayac].stajYBaslangicGun)+((12-(sta[stajSayac].stajYBaslangicAy-sta[stajSayac].stajYBitisAy))*30)/7;
                                }

                                if (sta[stajSayac].stajYBitisAy>sta[stajSayac].stajYBaslangicAy)
                                {
                                sta[stajSayac].stajYToplamHafta = sta[stajSayac].stajYToplamHafta + ((sta[stajSayac].stajYBitisGun-sta[stajSayac].stajYBaslangicGun)+((sta[stajSayac].stajYBitisAy-sta[stajSayac].stajYBaslangicAy)*30))/7;
                                }
                                printf("OGRENCININ YAZILIM STAJI YAPTIGI HAFTA SAYISI=%d\n\n",sta[stajSayac].stajYToplamHafta);
                                        if (sta[stajSayac].stajYToplamHafta<4)
                                {
                                    printf("!!! FAZLA VEYA EKSIK HAFTA GIRDINIZ LUTFEN TEKRAR DENEYIN !!! \n\n");
                                    sta[stajSayac].stajYToplamHafta=0;
                                    goto staj;
                                }
                                if (sta[stajSayac].stajYToplamHafta>10)
                                {
                                    printf("!!! FAZLA VEYA EKSIK HAFTA GIRDINIZ LUTFEN TEKRAR DENEYIN !!! \n\n");
                                    sta[stajSayac].stajYToplamHafta=0;
                                    goto staj;
                                }

                                fprintf(stajbilgi,"%d \t",sta[stajSayac].stajYOgrenciNo);
                                fprintf(stajbilgi,"%d ",sta[stajSayac].stajYBaslangicGun);
                                fprintf(stajbilgi,"%d ",sta[stajSayac].stajYBaslangicAy);
                                fprintf(stajbilgi,"%d \t",sta[stajSayac].stajYBaslangicYil);
                                fprintf(stajbilgi,"%d ",sta[stajSayac].stajYBitisGun);
                                fprintf(stajbilgi,"%d ",sta[stajSayac].stajYBitisAy);
                                fprintf(stajbilgi,"%d ",sta[stajSayac].stajYBitisYil);
                                fprintf(stajbilgi,"  %d\n",sta[stajSayac].stajYToplamHafta);
                                }
                      }
                            printf("OGRENCININ DONANIM STAJININ YAPILDIGI FIRMA VERGI NO GIRINIZ: ");
                            scanf("%d",&sta[stajSayac].stajDVergiNo);
                                for (stajm=0;stajm<m+1;stajm++)
                                {
                                    if (sta[stajSayac].stajDVergiNo==fir[stajm].FirmaVergiNo)
                                {
                                staj2:
                               printf("OGRENCININ DONANIM STAJINA BASLADIGI GUN : ");
                               scanf("%d",&sta[stajSayac].stajDBaslangicGun);
                               while ( sta[stajSayac].stajDBaslangicGun<0 || sta[stajSayac].stajDBaslangicGun>30 )
                               {
                                   printf("!!! GECERSIZ ARALIK GIRDINIZ TEKRAR GIRINIZ\n");
                                   printf("OGRENCININ DONANIM STAJINA BASLADIGI GUN : ");
                               scanf("%d",&sta[stajSayac].stajDBaslangicGun);
                               }
                               printf("OGRENCININ DONANIM STAJINA BASLADIGI AY : ");
                               scanf("%d",&sta[stajSayac].stajDBaslangicAy);
                                while ( sta[stajSayac].stajDBaslangicAy<0 || sta[stajSayac].stajDBaslangicAy>12 )
                               {
                                   printf("!!! GECERSIZ ARALIK GIRDINIZ TEKRAR GIRINIZ\n");
                                   printf("OGRENCININ DONANIM STAJINA BASLADIGI AY : ");
                               scanf("%d",&sta[stajSayac].stajDBaslangicAy);
                               }
                               printf("OGRENCININ DONANIM STAJINA BASLADIGI YIL : ");
                               scanf("%d",&sta[stajSayac].stajDBaslangicYil);

                               printf("OGRENCININ DONANIM STAJINI BITIRDIGI GUN : ");
                               scanf("%d",&sta[stajSayac].stajDBitisGun);
                                while ( sta[stajSayac].stajDBitisGun<0 || sta[stajSayac].stajDBitisGun>30 )
                               {
                                   printf("!!! GECERSIZ ARALIK GIRDINIZ TEKRAR GIRINIZ\n");
                                   printf("OGRENCININ DONANIM STAJINI BITIRDIGI GUN : ");
                               scanf("%d",&sta[stajSayac].stajDBitisGun);
                               }
                               printf("OGRENCININ DONANIM STAJINI BITIRDIGI AY : ");
                               scanf("%d",&sta[stajSayac].stajDBitisAy);
                                while ( sta[stajSayac].stajDBitisAy<0 || sta[stajSayac].stajDBitisAy>12 )
                               {
                                   printf("!!! GECERSIZ ARALIK GIRDINIZ TEKRAR GIRINIZ\n");
                                   printf("OGRENCININ DONANIM STAJINI BITIRDIGI AY : ");
                               scanf("%d",&sta[stajSayac].stajDBitisAy);
                               }
                               printf("OGRENCININ DONANIM STAJINI BITIRDIGI  YIL : ");
                               scanf("%d",&sta[stajSayac].stajDBitisYil);
                               if (sta[stajSayac].stajDBaslangicGun==0 && sta[stajSayac].stajDBaslangicAy==0 && sta[stajSayac].stajDBaslangicYil==0 &&
                                   sta[stajSayac].stajDBitisGun==0 && sta[stajSayac].stajDBitisAy==0 && sta[stajSayac].stajDBitisYil==0)
                               {
                                   sta[stajSayac].stajDToplamHafta=0;
                                   goto donanimbilgi;
                               }
                                 if (sta[stajSayac].stajDBitisAy<sta[stajSayac].stajDBaslangicAy)
                                {
                                sta[stajSayac].stajDToplamHafta = sta[stajSayac].stajDToplamHafta + ((sta[stajSayac].stajDBitisGun-sta[stajSayac].stajDBaslangicGun)+((12-(sta[stajSayac].stajDBaslangicAy-sta[stajSayac].stajDBitisAy))*30))/7;
                                }
                                if (sta[stajSayac].stajDBitisAy>sta[stajSayac].stajDBaslangicAy)
                                {
                                sta[stajSayac].stajDToplamHafta = sta[stajSayac].stajDToplamHafta + ((sta[stajSayac].stajDBitisGun-sta[stajSayac].stajDBaslangicGun)+((sta[stajSayac].stajDBitisAy-sta[stajSayac].stajDBaslangicAy)*30))/7;
                                }
                               if (sta[stajSayac].stajDToplamHafta<2)
                                {
                                    printf("!!! FAZLA VEYA EKSIK HAFTA GIRDINIZ LUTFEN TEKRAR DENEYIN !!! \n\n");
                                    sta[stajSayac].stajDToplamHafta=0;
                                    goto staj2;
                                }
                                if (sta[stajSayac].stajDToplamHafta>8)
                                    {
                                    printf("!!! FAZLA VEYA EKSIK HAFTA GIRDINIZ LUTFEN TEKRAR DENEYIN !!! \n\n");
                                    sta[stajSayac].stajDToplamHafta=0;
                                    goto staj2;
                                }
                                sta[stajSayac].stajDOgrenciNo=sta[stajSayac].stajYOgrenciNo;
                                printf("OGRENCININ DONANIM STAJINI YAPTIGI HAFTA SAYISI=%d\n\n",sta[stajSayac].stajDToplamHafta);

donanimbilgi:

                                fprintf(stajbilgi,"%d ",sta[stajSayac].stajDOgrenciNo);
                                fprintf(stajbilgi,"%d ",sta[stajSayac].stajDBaslangicGun);
                                fprintf(stajbilgi,"%d ",sta[stajSayac].stajDBaslangicAy);
                                fprintf(stajbilgi,"%d \t",sta[stajSayac].stajDBaslangicYil);
                                fprintf(stajbilgi,"%d ",sta[stajSayac].stajDBitisGun);
                                fprintf(stajbilgi,"%d ",sta[stajSayac].stajDBitisAy);
                                fprintf(stajbilgi,"%d ",sta[stajSayac].stajDBitisYil);
                                fprintf(stajbilgi," %d \n",sta[stajSayac].stajDToplamHafta);
                                fclose(stajbilgi);
                                stajSayac++;
                                goto basla;
                                }
                                }
                                }

}
}
if(menuInput==10)
{

   for(stajSayac=0;stajSayac<i;stajSayac++)
        {

           sta[stajSayac].stajToplamHafta=sta[stajSayac].stajDToplamHafta+sta[stajSayac].stajYToplamHafta;
            if (sta[stajSayac].stajDToplamHafta >= 2 && sta[stajSayac].stajYToplamHafta >=4 && sta[stajSayac].stajToplamHafta==12)
            {
                for (f=0;f<i;f++)
                {
                    if (sta[stajSayac].stajDOgrenciNo == ogr[f].ogrencinumara)
                    {
                        ogr[f].ogrencinumara= sta[stajSayac].stajDOgrenciNo ;
                        printf("\nOGRENCININ ADI =%s\n",ogr[f].ogrenciad);
                            printf("OGRENCININ SOYADI =%s\n",ogr[f].ogrencisoyad);
                    }
                }
                printf("OGRENCININ NUMARASI =%d\n",sta[stajSayac].stajDOgrenciNo);
                printf("OGRENCININ YAZILIM STAJI YAPTIGI HAFTA SAYISI =%d\n",sta[stajSayac].stajYToplamHafta);
                printf("OGRENCININ DONANIM STAJI YAPTIGI HAFTA SAYISI =%d\n",sta[stajSayac].stajDToplamHafta);
                printf("OGRENCININ STAJ YAPTIGI TOPLAM HAFTA SAYISI =%d\n",sta[stajSayac].stajToplamHafta);
            }
        }
    goto basla;
}
if(menuInput==11)
{
     for(stajSayac=0;stajSayac<i+1;stajSayac++)
        {
           sta[stajSayac].stajToplamHafta=sta[stajSayac].stajDToplamHafta+sta[stajSayac].stajYToplamHafta;
            if (sta[stajSayac].stajDToplamHafta < 2 || sta[stajSayac].stajYToplamHafta <4 || sta[stajSayac].stajToplamHafta<12 )
            {
                        for (f=0;f<i; f++)
                        {
                    if (sta[stajSayac].stajDOgrenciNo == ogr[f].ogrencinumara)
                            {
                        ogr[f].ogrencinumara= sta[stajSayac].stajDOgrenciNo ;
                        printf("\n\nOGRENCININ ADI =%s\n",ogr[f].ogrenciad);
                            printf("OGRENCININ SOYADI =%s\n",ogr[f].ogrencisoyad);
                             printf("OGRENCININ NUMARASI =%d\n",sta[stajSayac].stajDOgrenciNo);
                printf("OGRENCININ YAZILIM STAJI YAPTIGI HAFTA SAYISI =%d\n",sta[stajSayac].stajYToplamHafta);
                printf("OGRENCININ DONANIM STAJI YAPTIGI HAFTA SAYISI =%d\n",sta[stajSayac].stajDToplamHafta);
                printf("OGRENCININ STAJ YAPTIGI TOPLAM HAFTA SAYISI =%d\n",sta[stajSayac].stajToplamHafta);

                            }
                        }

            }
        }
    goto basla;
}
}
