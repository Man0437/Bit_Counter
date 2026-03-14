#include <stdint.h>
#include <stdio.h>

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long long u64;


int unsigned count_bits_noway(u8 x){
    int count = 0;
    while (x){
        x += x&1;
        x >>= 1;
    }
    return count;
}

int unsigned count_bits_1(u8 x){
    int count = 0;
    while (x){
        x &= (x-1);
        count++;
    }
    return count;
}

u8 count_bits_2(u8 x){
    if(x == 0) return 0;
    if(x == 0xFF) return 8;
    x = (0x010101*x & 0x249249) % 7;
    if (x == 0) return 7;
    return x;
}

u8 count_bits_3(u16 x){
    u8 leastbit = x&1;
    x >>= 1;
    if(x == 0) return leastbit;
    if(x == 0x7FFF) return leastbit + 15;
    return leastbit + (x*0x200040008001llu & 0x111111111111111llu) % 15;
}

int unsigned count_bits_4(u16 x){
    u8 leastbit = x&1;
    x >>= 1;
    if(x == 0) return leastbit + (((x*0x200040008001llu & 0x111111111111111llu)*0x111111111111111llu >> 56) & 0xF);
}

/*int unsigned count_bits_4_m(u8 x){
    if (x == 0xFF) return 8;
    return ((u64(0x010101*x & 0x249249)*0x249249) >> 21) & 0x7;
}*/


long read_file(char* file_name){
    FILE *f = fopen(file_name, "rb");

    if (f == NULL) {
        printf("Нельзя открыть файл\n");
        return 1;
    }
    
    u64 buffer[1024];
    size_t n;
    long total = 0;
    while((n = fread(buffer, 1, 1024, f)) > 0){
        for(size_t i = 0; i < n; i++){
            total += count_bits_3(buffer[i]);
        }
    }
    fclose(f);
    printf("Общее число 1 бит: %ld\n", total);
    return total;
}

int main(int argc, char *argv[]){
    
    if (argc < 2) {
        printf("Использовать: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "rb");

    if (f == NULL) {
        printf("Нельзя открыть файл\n");
        return 1;
    }

    u8 buffer[1024];
    size_t n;
    long total = 0;
    while((n = fread(buffer, 1, 1024, f)) > 0){
        for(size_t i = 0; i < n; i++){
            total += count_bits_2(buffer[i]);
        }
    }
    fclose(f);

    printf("%ld\n", total);
    return 0;
}