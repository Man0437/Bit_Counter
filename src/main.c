#include <stdint.h>
#include <stdio.h>

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;


u8 CountOnes3_x64_m ( u32 n ) {    
    if (n+1 == 0)  return 32;
    u64 res = (n&0xFFF)*0x1001001001001llu & 0x84210842108421llu;
    res += ((n&0xFFF000)>>12)*0x1001001001001llu & 0x84210842108421llu;
    res += (n>>24)*0x1001001001001llu & 0x84210842108421llu;
    return (res*0x84210842108421llu >> 55) & 0x1F;
}

long read_file(char* file_name){
    FILE *file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Нельзя открыть файл\n");
        return 1;
    }
    
    
    u8 buffer[65536];
    long total = 0;
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (size_t i = 0; i < n; i++)
            total += CountOnes3_x64_m(buffer[i]);
    } 
    fclose(file);
    printf("Всего единичных бит: %ld\n", total);
    return total;
}

int main(int argc, char *argv[]){
    read_file(argv[1]);
    return 0;
}