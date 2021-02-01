#include <stdio.h>
#include <conio.h>

int main(){
    char c;
    do {
        c = getchar();
        printf("%d \n", c);
    }while (c != 27);
}
