#include <stdio.h>
#include <stdlib.h>
#include "file_io.h"
#include "player.h"

int score (){

}

int menu (){
    printf("===WELCOME===\n");
    printf("1. Start\n");
    printf("2. Score board\n");
    printf("3. Exit\n");
    printf("============\n");
    printf("Enter menu:");
    int select;
    scanf("%d", &select);
    return(select);
}

int main (){
    int men;
    men = menu();
    switch (men) {
        case 1:
            printf("Let's start");
        case 2:
            printf("Comparison is the thief of joy");
        case 3:
            printf("Come back later!");
            exit(0);
        default:
            printf("Wrong input!");
    }
    return 0;
}