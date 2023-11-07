#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


//PROGRAM ALGORITMA PRIM dengan BAHASA C

void main() {
    
    int vertex, i, j, awal, v=0; 

    printf("Program Algoritma Prim || Modify by - Irwan Nawawi");
    printf("\n================================================");
    printf("\n================================================");
    printf("\n================================================\n");
    printf("\nMasukkan jumlah vertex : ");
    scanf("%d", &vertex);

    int titik[vertex][vertex];
    int uji[vertex];
    
    for(i=1;i<=vertex;i++){
    
        for(j=i;j<=vertex;j++){
            if(i==j)
            {
                titik[i][j]=0;
            }
            else
            {
                printf("\n Bobot [%d-%d] : ", i, j);
                scanf("%d", &titik[i][j]);
                titik[j][i] = titik[i][j];
            }
        }
    }
    
    printf("\nBentuk dalam Matriks : \n");
        for (i=1;i<=vertex;i++)
        {
            printf("\n");
            for (j=1;j<=vertex;j++)
                printf("%d\t",titik[i][j]);
        }
    
    printf("\nMasukkan vertex awal yang dipilih : ");
    scanf("%d", &awal);
    
    int batas=0, min, a, b, bobot=0;

    for(i=1;i<=vertex;i++)
    {
        uji[i]=999;
    }
    
    uji[awal]=awal;

    while(1){

        min=999;
        for(i=1;i<=vertex;i++)
        {
            if(uji[i]==i)
            {
                for(j=1;j<=vertex;j++)
                {
                    if(titik[i][j]<min&&titik[i][j]!=0)
                    {
                        min = titik[i][j];
                        a=i;
                        b=j;
                    }
                } 
            }
        }
        titik[a][b]=0;
        titik[b][a]=0;
        
        int sama=0;

        for(i=1;i<=vertex;i++)
        {
            if(uji[i]==b)
            {
                sama++;
            }

        }
        
        if (sama==0)
        {
            printf("%d - %d : %d\n",a,b,min);
            bobot+=min;
            uji[b]=b;
            v++;
        
        }
        if(v == vertex-1)
        {
            break;
        }

        batas++;
    }
    
    printf("\nTotal : %d",bobot);

}