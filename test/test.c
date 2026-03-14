#include <stdio.h>
#include <assert.h>
#include "../src/main.c"

int main(int argc, char *argv[]){
    assert(read_file("../files/test.txt") == 50);
    assert(read_file("../files/test.bk2") == 1112350558);
    assert(read_file("../files/test.jpg") == 1112350558);
    assert(read_file("../files/test.pdf") == 1112350558);


    printf("Все тесты пройдены");
    return 0;
}
