#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5
char matrix[N][N];
void findPos(char ch, int* row, int* col) {
    int i, j;
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            if(matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void decrypt(char* msg) {
    int len = strlen(msg), i, row1, row2, col1, col2;
    for(i = 0; i < len; ++i) {
        if(msg[i] == ' ') {
            for(int j = i; j < len; ++j) {
                msg[j] = msg[j+1];
            }
            len--;
        }
    }
    char* keyword = "CIPHER";
    int klen = strlen(keyword), pos = 0;
    int freq[26] = {0};
    for(i = 0; i < klen; ++i) {
        if(keyword[i] >= 'A' && keyword[i] <= 'Z') {
            if(!freq[keyword[i] - 'A']) {
                matrix[pos / N][pos % N] = keyword[i];
                freq[keyword[i] - 'A'] = 1;
                pos++;
            }
        }
    }
    for(i = 0; i < 26; ++i) {
        if(!freq[i]) {
            matrix[pos / N][pos % N] = 'A' + i;
            pos++;
        }
    }
    for(i = 0; i < len-1; i += 2) {
        findPos(msg[i], &row1, &col1);
        findPos(msg[i+1], &row2, &col2);
        if(row1 == row2) {
            msg[i] = matrix[row1][(col1+N-1)%N];
            msg[i+1] = matrix[row2][(col2+N-1)%N];
        }
        else if(col1 == col2) {
            msg[i] = matrix[(row1+N-1)%N][col1];
            msg[i+1] = matrix[(row2+N-1)%N][col2];
        }
        else {
            msg[i] = matrix[row1][col2];
            msg[i+1] = matrix[row2][col1];
        }
    }
}

int main() {
    char msg[] = "KXJEY UREBE ZWEHE WRYTU HEYFS KREHE GOYFI WTTTU OLKSY CAJPO BOTEI ZONTX BYBNT GONEY CUZWR GDSON SXBOU YWRHE BAAHY USEDQ";
    decrypt(msg);
    printf("Decrypted message: %s\n", msg);
    return 0;
}
