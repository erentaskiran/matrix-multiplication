#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int matris1BuyukluguSatir, matris1BuyukluguSutun, matris2BuyukluguSatir, matris2BuyukluguSutun;

    do {
        printf("Matris 1'in satır sayısı: ");
        scanf("%d", &matris1BuyukluguSatir);
        printf("Matris 1'in sütun sayısı: ");
        scanf("%d", &matris1BuyukluguSutun);
        printf("Matris 2'nin satır sayısı: ");
        scanf("%d", &matris2BuyukluguSatir);
        printf("Matris 2'nin sütun sayısı: ");
        scanf("%d", &matris2BuyukluguSutun);
    } while (matris1BuyukluguSutun != matris2BuyukluguSatir);

    int** matris1 = (int**)malloc(matris1BuyukluguSatir * sizeof(int*));
    for (int i = 0; i < matris1BuyukluguSatir; i++) {
        matris1[i] = (int*)malloc(matris1BuyukluguSutun * sizeof(int));
    }

    int** matris2 = (int**)malloc(matris2BuyukluguSatir * sizeof(int*));
    for (int i = 0; i < matris2BuyukluguSatir; i++) {
        matris2[i] = (int*)malloc(matris2BuyukluguSutun * sizeof(int));
    }

    printf("Matris 1 elemanlarını giriniz:\n");
    for (int i = 0; i < matris1BuyukluguSatir; i++) {
        for (int j = 0; j < matris1BuyukluguSutun; j++) {
            printf("Matris 1 [%d][%d]: ", i+1, j+1);
            scanf("%d", &matris1[i][j]);
        }
    }

    printf("Matris 2 elemanlarını giriniz:\n");
    for (int i = 0; i < matris2BuyukluguSatir; i++) {
        for (int j = 0; j < matris2BuyukluguSutun; j++) {
            printf("Matris 2 [%d][%d]: ", i+1, j+1);
            scanf("%d", &matris2[i][j]);
        }
    }

    int** sonuc = (int**)malloc(matris1BuyukluguSatir * sizeof(int*));
    for (int i = 0; i < matris1BuyukluguSatir; i++) {
        sonuc[i] = (int*)malloc(matris2BuyukluguSutun * sizeof(int));
    }

    for (int i = 0; i < matris1BuyukluguSatir; i++) {
        for (int j = 0; j < matris2BuyukluguSutun; j++) {
            int toplam = 0;
            for (int k = 0; k < matris1BuyukluguSutun; k++) {
                toplam += matris1[i][k] * matris2[k][j];
            }
            sonuc[i][j] = toplam;
        }
    }

    printf("Matrislerin çarpımı:\n");
    for (int i = 0; i < matris1BuyukluguSatir; i++) {
        for (int j = 0; j < matris2BuyukluguSutun; j++) {
            printf("%d ", sonuc[i][j]);
        }
        printf("\n");
    }

    // Belleği serbest bırak
    for (int i = 0; i < matris1BuyukluguSatir; i++) {
        free(matris1[i]);
    }
    free(matris1);
    for (int i = 0; i < matris2BuyukluguSatir; i++) {
        free(matris2[i]);
    }
    free(matris2);
    for (int i = 0; i < matris1BuyukluguSatir; i++) {
        free(sonuc[i]);
    }
    free(sonuc);

    return 0;
}
