#include <stdio.h>
#include <time.h>

void lotto_writefile(int number[], int n){
    FILE*fp=fopen("lotto.txt", "wb+");
    for(int i=0;i<n;i++){
        fwrite(&num[i], sizeof(int), 1, fp);
    }
    fclose(fp);
    return;
}

void lotto_readfile(int number[]){

    FILE*fp=fopen("lotto.txt", "rb");
    int i=0;
    while(fread(&emp[i], sizeof(int), 1, fp)){
        printf("[%d] %d %s\n", i, emp[i].id, emp[i].name);
        i++;
    }
    fclose(fp);
    return;
}

int main()
{
    int num[5][7];
    int n;
    srand((unsigned) time(NULL));
    
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩:");
    scanf("%d", &n);
    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt", n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<7;j++){
            num[i][j]=(rand()%69)+1;
        }
    }
    
    lotto_writefile(num, n);
    lotto_readfile(num);

    return 0;
}
