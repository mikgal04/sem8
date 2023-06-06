#include <stdio.h>

int main() {
    FILE *source_file, *destination_file;
    char file_name[100];

    printf("Введите имя копируемого файла: ");
    scanf("%s", file_name);
    
    source_file = fopen(file_name, "rb");
    if (source_file == NULL) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }

    destination_file = fopen("copy.txt", "wb");
    if (destination_file == NULL) {
        fclose(source_file);
        printf("Ошибка создания файла копии!\n");
        return 1;
    }
    
    fclose(destination_file);
    fclose(source_file);
    return 0;
}



