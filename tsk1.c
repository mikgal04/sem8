#include <stdio.h>
#include <math.h>

int main() {
    const double er = 6.371e+6; // Радиус Земли (м)
    const double mu = 3.986e+14; // Гравитационный параметр Земли (м^3/c^2)
    const double omega = 7.292e-5; // Угловая скорость вращения Земли (рад/с)

    double ra, rp, va, vomega, point_ra, point_rp;
    FILE* fp;
    fp = fopen("data.txt", "w"); // Открыть файл для записи данных
    fprintf(fp, "ra\t rp\t va\t vomega\n"); // Записать заголовок таблицы

    for (ra = 0; ra <= 60000; ra += 10) {
        for (rp = 0; rp <= ra; rp += 10) {
            va = sqrt(2 * mu * rp / (ra * (ra + rp))); // Подсчет va
            point_ra = cos(omega * sqrt(ra * ra * ra / mu)); // Подсчет vomega для текущей точки ra
            point_rp = cos(omega * sqrt(rp * rp * rp / mu)); // Подсчет vomega для текущей точки rp
            if (point_ra <= va && point_rp <= va) {
                vomega = omega * er * sqrt((ra + rp) / (2 * ra * rp)); // Подсчет итогового vomega
                fprintf(fp, "%.1f\t %.1f\t %.6f\t %.6f\n", ra, rp, va, vomega); // Записать данные в файл
                break; // Прервать цикл rp, перейти к следующей точке ra
            }
        }
    }

    fclose(fp); // Закрыть файл
    return 0;
}