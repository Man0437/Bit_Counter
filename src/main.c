#include <stdint.h>
#include <stdio.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Алгоритм для подсчета битов

// Метод при котором получается 8853ms при подсчете 2,4G на компиляторе gcc
// Паралельный метод
u8 CountOnes(u8 n) {
  n = ((n>>1) & 0x55) + (n & 0x55);
  n = ((n>>2) & 0x33) + (n & 0x33);
  n = ((n>>4) & 0x0F) + (n & 0x0F);
  return n;
}

long read_file(char* file_name){
    FILE *file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Нельзя открыть файл\n");
        return 1;
    }
    
    
    u8 buffer[65536];

    long total = 0;
    size_t count_buf;
    while ((count_buf = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (size_t i = 0; i < count_buf; i++)
            total += CountOnes(buffer[i]);
    } 
    fclose(file);

    // Вывод числа битов в файле
    printf("%ld\n", total);
    return total;
}

int main(int argc, char *argv[]){
    read_file(argv[1]);
    return 0;
}