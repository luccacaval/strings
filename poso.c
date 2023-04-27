#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_arr(int a[10][10]){
    printf("Poninendo los 1\n");
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            a[i][j] = 0;
        }   
    }
}

void add_holes(int a[10][10], int holes){
    printf("Agregando %d agujeros\n", holes);
    srand(time(NULL));
    int x,y;
    for (int i = 0; i <= holes; i++){
        printf("En el for");
        x = rand() % 10;
        y = rand() % 10;
        while ((x == 0 && y == 0) || (x == 9 && y == 9)){
        printf("While sospechoso\n");
        x = rand() % 10;
        y = rand() % 10;
        }
        a[y][x] = 1;
    }
    printf("Sali del for");
}

void print_board (int pos_x, int pos_y){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
        if (i == pos_y && j == pos_x){
            printf("2 ");
        } else{
            printf("0 ");
        }
    }
    printf("\n");
    }
}

int check_hole(int a[10][10], int pos_x, int pos_y){
    if(a[pos_y][pos_x] == 1) return 1;
    else return 0;
}

int check_goal(int pos_x, int pos_y){
    if(pos_x == 9 && pos_y == 9) return 1;
    else return 0;
}

int check_bounds(int pos_x, int pos_y,int move){
    switch (move)
    {
    case 1:
        if(pos_y - 1 < 0) return 0;
        else return 1;
    case 2:
        if(pos_y + 1 > 9) return 0;
        else return 1;
    case 3:
        if(pos_x - 1 < 0) return 0;
        else return 1;
    case 4:
        if(pos_x + 1 > 9) return 0;
        else return 1;
    default:
        return 0;
    }
}

int main(void){
    int board[10][10];
    clear_arr(board);
    add_holes(board, 3);
    printf("asd\n");
    int pos_x = 0;
    int pos_y = 0;
    int move;
    print_board(pos_x, pos_y);
    while (1){
        printf("Hacia donde te quieres mover:\n 1) Arriba 2) Abajo 3) Izquierda 4) Derecha\n");
        scanf("%d", &move);
        if (check_bounds(pos_x, pos_y,move)){
        switch (move)
        {
        case 1:
            pos_y--;
            break;
        case 2:
            pos_y++;
            break;
        case 3:
            pos_x--;
            break;
        case 4:
            pos_x++;
        default:
            break;
        }
    } else{
        printf("Eso es fuera del tablero\n");
    }
    if (check_hole(board, pos_x, pos_y)){
        printf("Caiste en un agujero, perdiste\n");
        return 0;
    } else if (check_goal(pos_x, pos_y)){
        printf("Llegaste al objetivo, ganaste\n");
        return 0;
    }
    print_board(pos_x, pos_y);
    }
    return 0;
}
