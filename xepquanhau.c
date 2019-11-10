#include <stdio.h>

#define MAXM 8
#define MAXN 8
#define SOQUANHAU 8

int map[MAXM][MAXN];

FILE *fout;


void init_map() { // khởi tạo tất cả giá trị của map bằng 0
    for(int m = 0; m < MAXM; m++) {
        for(int n = 0; n < MAXN; n++) {
            map[m][n] = 0;
        }
    }
}

void print_map() {
    for(int m = 0; m < MAXM; m++) {
        for(int n = 0; n < MAXN; n++) {
            fprintf(fout, "%d ", map[m][n]);
        }
        fprintf(fout, "\n");
    }
    fprintf(fout, "\n");
}

int check_duong_di_quan_hau(int m, int n) { //trả về giá trị 1 nếu có quân hậu khác trên đường di chuyển
    int x, y;
    //check đường ngang 
    for (int x = 0; x < MAXN; x++) {
        if (x == n) continue;
        if (map[m][x] == 1) return 1;
    }
    //check đường dọc
    for (int y = 0; y < MAXM; y++) {
        if (y == m) continue;
        if (map[y][n] == 1) return 1;
    }
    //check đường chéo phải

    for (y = m, x = n; (y < MAXM) && (x >= 0); y++, x--) {
        if (y == m || x == n) continue;
        if (map[y][x] == 1) return 1;
    }
    for (y = m, x = n; (x < MAXN) && (y >= 0); y--, x++) {
        if (y == m || x == n) continue;
        if (map[y][x] == 1) return 1;
    }

    //check duong cheo trai

    for (y = m, x = n; (y < MAXM) && (x < MAXN); y++, x++) {
        if (y == m || x == n) continue;
        if (map[y][x] == 1) return 1;
    }
    for (y = m, x = n; (x >= 0) && (y >= 0); y--, x--) {
        if (y == m || x == n) continue;
        if (map[y][x] == 1) return 1;
    }
    return 0; // neu khong co quan hau nao tren duong di
}

void danhdau(int m, int n) {
    map[m][n] = 1;
}

int la_quan_Hau(int m, int n) {
    if (map[m][n] == 1) return 1;
    return 0;
}

void quay_lui(int k) {
    for(int m = 0; m < MAXM; m++) {
        for(int n = 0; n < MAXN; n++) {
            if (!la_quan_Hau(m, n) && !check_duong_di_quan_hau(m, n)) {
                map[m][n] = 1;
                if (k == SOQUANHAU) {
                    print_map();
                }
                else {
                    quay_lui(k+1);
                }
                map[m][n] = 0;
            }
        }
    }
}

int main() {
    fout = fopen("output.txt", "w");
    init_map();
    quay_lui(1);
    fclose(fout);
    return 0;
}