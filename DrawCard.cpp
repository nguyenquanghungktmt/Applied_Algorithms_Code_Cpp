#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char suitRequest[3], rankRequest[3];
char suitDraw[3], rankDraw[3];
char suits[5][2] = {"D", "H", "C", "S"};
char ranks[14][3] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

int main(){
    printf("Card Draw\n");
    printf("=========\n");
    printf("Suit: "); scanf("%s", &suitRequest);
    fflush(stdin);
    printf("Rank: "); scanf("%s", &rankRequest);

    int index = 0;
    do{
        index++;
        srand((int)time(0) + index*10);
        short s = rand() % 4;
        short r = rand() % 13;
        strcpy(suitDraw, suits[s]);
        strcpy(rankDraw, ranks[r]);
        printf("Result of draw %d : %s%s \n", index, rankDraw, suitDraw);
    }
    while (strcmp(suitDraw,suitRequest)!=0 || strcmp(rankDraw,rankRequest)!=0 );

    printf("you got your result in %d draws!", index);

}

