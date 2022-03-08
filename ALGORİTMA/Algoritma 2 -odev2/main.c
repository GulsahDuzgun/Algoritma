#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

FILE *transpoze_file;
FILE *kaprekar_file;

void create_kaprekar_file() {
    kaprekar_file = fopen("kaprekar.txt", "a+");
}

void create_transpoze_file() {
    transpoze_file = fopen("transpoze.txt", "a+");
}

int random_number(int l, int r) {
    return (rand() % (r - l + 1)) + l;
}

// matrisi transpoze.txt dosyasýna yazar
void log_matris_to_file(int *matris, int satir, int sutun) {
    for (int i = 0; i < satir; ++i) {
        for (int j = 0; j < sutun; ++j) {
            fprintf(transpoze_file, "%d ", matris[i * satir + j]);
        }
        fprintf(transpoze_file, "\n");
    }
}

// verilen sayi kaprekar mi bulur
int kaprekar_sayi(int n) {
    if (n == 1) {
        return 1;
    }

    // kare sayýdaki toplam rakam sayýsý
    int rakam_sayisi = 0;

    // sayinin karesindeki rakam sayýsýný bul
    int karesi = n * n;

    while (karesi)
    {
        rakam_sayisi++;
        karesi /= 10;
    }

    // karesini tekrar hesapla çünkü while içinde deðiþti
    karesi = n * n;

    // kare sayiyi farklý noktalarda böl ve toplamlarý n'e eþit mi kontrol et
    for (int sag_rakamlar=1; sag_rakamlar < rakam_sayisi; sag_rakamlar++)
    {
        int parcalar = pow(10, sag_rakamlar);

        // 10, 100, 1000 gibi sayýlarý atla, bunlar kaprekar deðil
        if (parcalar == n) {
            continue;
        }

        // parçalarýn toplamý n sayýsýna eþit mi bak
        int toplam = karesi / parcalar + karesi % parcalar;
        if (toplam == n) {
            return 1;
        }
    }

    return 0;
}

// kaprekar sayi varsa kaprekar.txt'ye yazar
void log_kaprekar(int *matris, int satir, int sutun) {
    int kaprekar_found = 0;

    for (int i = 0; i < satir; ++i) {
        for (int j = 0; j < sutun; ++j) {
            if (kaprekar_sayi(matris[i * satir + j])) {
                kaprekar_found = 1;
                fprintf(kaprekar_file, "%d\n", matris[i * satir + j]);
            }
        }
    }

    if (kaprekar_found == 0) {
        printf("Kaprekar sayi yok!\n");
    } else {
        printf("Kaprekar sayilar dosyaya yazildi!\n");
    }
}

// matris bubble sort algoritmasýný kullanarak satýr bazýnda sort eder
void bubble_sort_matris(int *matris, int satir,int  sutun) {
    for (int k = 0; k < satir; k++) {
        for (int i = 0; i < sutun; i++) {
            for (int j = i + 1; j < sutun; j++) {

                if (matris[k * satir + i] > matris[k * satir + j]) {
                    int swap = matris[k * satir + i];
                    matris[k * satir + i] = matris[k * satir + j];
                    matris[k * satir + j] = swap;
                }
            }
        }
    }
}

// matrisi transpoze eder ve dosyalara loglar.
void transpose_matris() {
    int i, j, satir, sutun, *matris;

    printf("Matris satir sayisini girin:\t");
    scanf("%d", &satir);
    printf("Matris sutun sayisini girin:\t");
    scanf("%d", &sutun);

    matris = (int *) malloc(satir * sutun * sizeof(int));

    for (i = 0; i < satir; ++i) {
        for (j = 0; j < sutun; ++j) {
            matris[i * satir + j] = random_number(5, 40000);
        }
    }

    fprintf(transpoze_file, "Before tranpose: \n");
    log_matris_to_file(matris, satir, sutun);

    bubble_sort_matris(matris, satir, sutun);

    fprintf(transpoze_file, "After tranpose: \n");
    log_matris_to_file(matris, satir, sutun);

    log_kaprekar(matris, satir, sutun);
    printf("Yazdirma islemi tamam!");
}

int main() {
    create_transpoze_file();
    create_kaprekar_file();

    srand(time(NULL));

    transpose_matris();


    return 0;
}
