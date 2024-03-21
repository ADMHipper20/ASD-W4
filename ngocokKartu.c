#include <stdio.h>
#include <string.h>

int cardValueByINT(char *value1){
    if (strcmp(value1, "J") == 0) return 11;
    if (strcmp(value1, "Q") == 0) return 12;
    if (strcmp(value1, "K") == 0) return 13;
    if (strcmp(value1, "10") == 0) return 10;
    return (*value1 - '0'); // Mengubah karakter menjadi bilangan bulat
}

void tukarKartu(char *kartu1, char *kartu2) {
    char temp[3];
    strcpy(temp, kartu1);
    strcpy(kartu1, kartu2);
    strcpy(kartu2, temp);
}

void sortKartu(int jumlahKartu, char *ptr[]){
    int count = 0, min;
    for (int i = 0; i < jumlahKartu - 1; i++){
        // Inisialisasi value min = i
        min = i;
        for (int j = i + 1; j < jumlahKartu; j++){
            // Mengecek kondisi bahwa ptr[j] < ptr[min] atau ptr[min] == "K"
            // Akan mengubah nilai min = j karena ptr[min] lebih besar atau sama dengan "K"
            if (cardValueByINT(ptr[j]) < cardValueByINT(ptr[min]) || ptr[min] == "K") {
                min = j;
            }
        }
        if (min != i){
            //Perubahan tempat
            tukarKartu(ptr[min], ptr[i]);
            count++;

            // Menampilkan hasil kartu tiap pertukaran
            printf("Pertukaran %d: ", count);
            for (int k = 0; k < jumlahKartu; k++){
                printf("%s ", ptr[k]);
            }
            printf("\n");
        }
    }
    printf("%d\n", count);
}

int main(){
    int jumlahKartu;

    printf("Jumlah Kartu yang ada ditangan: ");
    scanf("%d", &jumlahKartu);

    char nilaiKartu[jumlahKartu][3];

    // Memasukkan input per array dari nilaiKartu
    printf("Cards on Deck: ");
    for (int i = 0; i < jumlahKartu; i++){
        scanf(" %s", nilaiKartu[i]);
    }
    printf("\n");

    // Memberikan tampilan Jumlah kartu dan Kartu apa saja yang di input
    printf("Jumlah Kartu: %d\n", jumlahKartu);
    for (int i = 0; i < jumlahKartu; i++) {
        printf("%s ", nilaiKartu[i]);
    }
    printf("\n");

    // Konversi array nilaiKartu[][] menjadi array nilaiKartu[].
    char *ptr[jumlahKartu];
    for (int i = 0; i < jumlahKartu; i++) {
        ptr[i] = nilaiKartu[i];
    }

    sortKartu(jumlahKartu, ptr);
}