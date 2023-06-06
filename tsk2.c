#include <stdio.h>

int main() {
    FILE *f1, *f2, *fout;
    int i, j, k, n, m, p, q;
    double mat1[100][100], mat2[100][100], res[100][100];

    f1 = fopen("matrix1.txt", "r");
    f2 = fopen("matrix2.txt", "r");
    fout = fopen("result.txt", "w");

    // чтение размеров матриц
    fscanf(f1, "%d %d", &n, &m);
    fscanf(f2, "%d %d", &p, &q);

    // проверка возможности умножения
    if (m != p) {
        printf("Error: incorrect matrices sizes\n");
        return 1;
    }

    // чтение матриц
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            fscanf(f1, "%lf", &mat1[i][j]);
        }
    }

    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            fscanf(f2, "%lf", &mat2[i][j]);
        }
    }

    // вычисление произведения матриц
    for (i = 0; i < n; i++) {
        for (j = 0; j < q; j++) {
            res[i][j] = 0;
            for (k = 0; k < m; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // запись результата в файл
    fprintf(fout, "%d %d\n", n, q);
    for (i = 0; i < n; i++) {
        for (j = 0; j < q; j++) {
            fprintf(fout, "%.2f ", res[i][j]);
        }
        fprintf(fout, "\n");
    }

    // закрытие файлов
    fclose(f1);
    fclose(f2);
    fclose(fout);

    return 0;
}

