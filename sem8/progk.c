#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

// Функция поиска элемента в двумерном массиве
void find_element(int arr[][COLS], int element) {
	int row, col;
	for (row = 0; row < ROWS; row++) {
		for (col = 0; col < COLS; col++) {
			if (arr[row][col] == element) {
				printf("Элемент %d найден в строке %d, столбце %d.\n", element, row + 1, col + 1);
				return;
			}
		}
	}
	printf("Элемент %d не найден в массиве.\n", element);
}

int main(void) {
	int arr[ROWS][COLS];
	int element;
	int row, col;
	srand(time(NULL));

	// Заполнение массива случайными числами
	printf("Исходный массив:\n");
	for (row = 0; row < ROWS; row++) {
		for (col = 0; col < COLS; col++) {
			arr[row][col] = rand() % 10;
			printf("%d ", arr[row][col]);
		}
		printf("\n");
	}

	// Получение элемента для поиска от пользователя
	printf("Введите элемент для поиска: ");
	scanf("%d", &element);

	// Вызов функции поиска элемента
	find_element(arr, element);

	return 0;
}