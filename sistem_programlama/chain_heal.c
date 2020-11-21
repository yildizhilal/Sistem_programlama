

    #include<stdlib.h>
    #include<stdio.h>
    #include <unistd.h>
    #include<string.h>
    #include<math.h>

    struct dugum{
            int X, Y;
            int mevcut_PP, max_PP;
            char *ad;
            int boyut;
            int iyilesme;
            int visit;

            struct dugum **liste_1;
            struct dugum *sonraki;

        };

    int initial_range, jump_range, num_jumps, initial_power = 0;
    float power_reduction;

    struct dugum *ilk;
    struct dugum *simdiki;
    struct dugum *gecici;
    struct dugum **yol;
    struct dugum **gecici_yol;
    struct dugum *kontrol;
    struct dugum *kontrol1;

    int saglik;
    int **iyilesme;
    int **mevcut_iyilesme;





    void chain_heal(struct dugum* dugum, int sicrama1, int sicrama2, int toplam_iyilesme, struct dugum* from,int index){

        int gerekli_iyilesme;
        int reset_power = initial_power;
        int sayi;
        gecici_yol[index] = dugum;

        if(dugum->visit == 1 || sicrama1>sicrama2){
            dugum->visit = 0;
            return;
        }


        if(index == sicrama2-1){

                     for(int i= 0; i<sicrama2;i++){


                       printf("ad: %s", gecici_yol[i]->ad); //??????????????????????????????????????????
                        gerekli_iyilesme = gecici_yol[i]->max_PP - gecici_yol[i]->mevcut_PP;
                        if(gerekli_iyilesme<initial_power)
                            gecici_yol[i]->iyilesme = gerekli_iyilesme;
                        else
                            gecici_yol[i]->iyilesme = rint(initial_power);

                        initial_power = initial_power * (1-power_reduction);
                        toplam_iyilesme = toplam_iyilesme + gecici_yol[i]->iyilesme;
                        mevcut_iyilesme[i] = gecici_yol[i]->iyilesme;

                        printf("[%d]: %d ", i, mevcut_iyilesme[i]);
                        printf("\n");


                        }
                        int yedek=0 ,yedek1;

                        while(yedek<sicrama2-1){
                                for(yedek1=yedek+1;yedek1<sicrama2;yedek1++){
                                    kontrol = gecici_yol[yedek];
                                    kontrol1 = gecici_yol[yedek1];
                                    //printf("\n\nTemp Path: %s\n",gecici_yol[yedek]->ad);
                                    if(kontrol == kontrol1)
                                        toplam_iyilesme = 0;
                                        }
                                yedek++;
                     }



                     initial_power = reset_power;


                    if(toplam_iyilesme>saglik){

                    saglik = toplam_iyilesme;
                    for(int x=0;x<sicrama2;x++){
                        yol[x]=gecici_yol[x];
                        iyilesme[x]=mevcut_iyilesme[x];
                    }
                }
        }


        for(sayi = 0; sayi<dugum->boyut; sayi++){
            dugum->visit = 1;

            chain_heal(dugum->liste_1[sayi], sicrama1+1, sicrama2,toplam_iyilesme,dugum->sonraki,index+1);
        }


    }




    int main(int argc, char ** argv){

        ilk = (struct dugum*) malloc(sizeof(struct dugum));
        simdiki = (struct dugum*) malloc(sizeof(struct dugum));
        ilk = NULL;

        int x, y, mevcut_PP, max_PP;
        char *ad = malloc(sizeof(char) * 100);

        initial_range=atoi(argv[1]);
        jump_range=atoi(argv[2]);
        num_jumps=atoi(argv[3]);
        initial_power =atoi(argv[4]);
        power_reduction=atof(argv[5]);



        FILE *f=stdin;




        int dugum_sayisi = 0;


            while (fscanf(f, "%d %d %d %d %s", &x, &y, &mevcut_PP, &max_PP, ad) != EOF){

            gecici = (struct dugum*) malloc(sizeof(struct dugum));
            gecici->X = x;
            gecici->Y = y;
            gecici->mevcut_PP = mevcut_PP;
            gecici->max_PP = max_PP;
            gecici->ad = malloc(sizeof(char) * 100);
            strcpy(gecici->ad, ad);

            if(dugum_sayisi <= 0){
                ilk = gecici;
                ilk->sonraki = NULL;
                simdiki = ilk;
            }else{
                simdiki->sonraki = gecici;
                simdiki = gecici;
                simdiki->sonraki = NULL;
            }

            dugum_sayisi++;
        }

            fclose(f);


        for(simdiki = ilk;simdiki<0;simdiki--){

            simdiki = simdiki->sonraki;
        }

        struct dugum *cikis = (struct dugum*) malloc(sizeof(struct dugum));
        struct dugum *giris = (struct dugum*) malloc(sizeof(struct dugum));

        cikis = ilk;

        do {
          int sayac = 0;
          giris = ilk;


          while(giris ){




              if( cikis != giris){
              if(sqrt(((cikis->X - giris->X)*(cikis->X - giris->X)) + ((cikis->Y - giris->Y)*(cikis->Y
                  - giris->Y))) <= jump_range){
                  sayac++;
              }
          }

              giris = giris->sonraki;
          }

          cikis->boyut = sayac;
          cikis = cikis->sonraki;
        } while(cikis);


        for(simdiki = ilk;simdiki<0;simdiki--){

            simdiki = simdiki->sonraki;
        }

        cikis = ilk;
        do {
          cikis->liste_1 = (struct dugum**)malloc(sizeof(struct dugum*) * cikis->boyut);
          int index_sayaci = 0;
          giris = ilk;


          while(giris){

                  if(cikis == ilk){

                  }

              if( cikis != giris){
                  if(sqrt(((cikis->X - giris->X)*(cikis->X - giris->X)) + ((cikis->Y -
                  giris->Y)*(cikis->Y - giris->Y))) <= jump_range){
                      cikis->liste_1[index_sayaci++]=giris;
                  }
              }

              giris = giris->sonraki;
          }
          cikis = cikis->sonraki;
        } while( cikis);



        for(simdiki=ilk;simdiki<0;simdiki--){

            for(int liste = 0; liste < simdiki->boyut; liste++)

            printf("\n");
            simdiki = simdiki->sonraki;
        }


        //

        yol = (struct dugum**)malloc(sizeof(struct dugum*) * num_jumps);
        gecici_yol = (struct dugum**)malloc(sizeof(struct dugum*) * num_jumps);
        iyilesme =   (int**)malloc(sizeof(int*)*num_jumps);
        mevcut_iyilesme =  (int**)malloc(sizeof(int*) * num_jumps);
        kontrol = (struct dugum*) malloc(sizeof(struct dugum));
        kontrol1 = (struct dugum*) malloc(sizeof(struct dugum));

        saglik = 0;
        int deger=0;
        simdiki = ilk;

        while( deger<dugum_sayisi){
                if(sqrt(((ilk->X - simdiki->X)*(ilk->X - simdiki->X)) +
                        ((ilk->Y - simdiki->Y)*(ilk->Y - simdiki->Y))) <= initial_range){

                            chain_heal(simdiki, 1, num_jumps,0, NULL,0);
                            simdiki = simdiki->sonraki;


            }
              deger++;
        }



        printf("\nToplam iyilesme: %d", saglik);


    printf("\nProgram End!\n");
    return 0;
    }
