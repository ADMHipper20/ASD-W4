#include <stdio.h>

void koboImaginaryChess(int (*bidakCatur)[8], int kudaX, int kudaY, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            // Mengatur bidak kuda pada posisi yang di input
            if (i == kudaX && j == kudaY){
                bidakCatur[i][j] = 0;
            }
            
            // Menandai sel yang dapat dijangkau oleh kuda
            // Misal angka kudaX dan kudaY adalah 2 & 2, dan saat index i dan j adalah 2
            // Maka ia akan meng-inisialisasi algoritma perhitungan kemungkinan perpindahan
            else if ((i == kudaX - 2 || i == kudaX + 2)) {
                if (j == kudaY - 1 || j == kudaY + 1)
                    bidakCatur[i][j] = 1;
            }
            else if ((i == kudaX - 1 || i == kudaX + 1)) {
                if (j == kudaY - 2 || j == kudaY + 2)
                    bidakCatur[i][j] = 1;
            }
            // Jika tidak dijangkau, maka tetap 0
            else bidakCatur[i][j] = 0;

            // Mencetak nilai 0 atau 1
            printf("%d ", bidakCatur[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int Catur[8][8] = { {0} }, kudaX, kudaY;
    int sizeBidak = sizeof(Catur) / sizeof(Catur[0]);

    printf("%d", sizeof(Catur[0]));
    printf("Masukkan letak bidak Kuda: ");
    scanf("%d %d", &kudaX, &kudaY);
    printf("Bidak X dan Y: %d & %d\n", kudaX, kudaY);

    koboImaginaryChess(Catur, kudaX, kudaY, sizeBidak);
}