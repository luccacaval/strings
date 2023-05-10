#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_arr(int a[10][10]){
    // Llenar el tablero con 0s
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            a[i][j] = 0;
        }   
    }
}

void add_holes(int a[10][10], int holes){
    // Agregar los agujeros
    srand(time(NULL));
    int x,y;
    for (int i = 0; i <= holes; i++){
        // Generar dos numeros aleatorios
        x = rand() % 10;
        y = rand() % 10;
        // En caso de que las coordenas genradas coinsidan con el inicio o el final volverlas a generar
        while ((x == 0 && y == 0) || (x == 9 && y == 9)){
        x = rand() % 10;
        y = rand() % 10;
        }
        // Poner el agujero en el tablero
        a[y][x] = 1;
    }
}

void print_board (int pos_x, int pos_y){
    // Recorrer todo el tablero
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
        // Imprimir un caracter diferente para reprecentar al jugador
        if (i == pos_y && j == pos_x){
            printf("2 ");
        } else{
            printf("0 ");
        }
    }
    // Al cambiar de fila imprimir un cambio de linea
    printf("\n");
    }
}

int check_hole(int a[10][10], int pos_x, int pos_y){
    // Si en la posicion a la que el usuario se movio hay in agujero devolver 1 
    if(a[pos_y][pos_x] == 1) return 1;
    else return 0;
}

int check_goal(int pos_x, int pos_y){
    if(pos_x == 9 && pos_y == 9) return 1;
    else return 0;
}

int check_bounds(int pos_x, int pos_y,int move){
    // Verficar si la casilla a la que se quiere mover el usuario esta dentro del tablero
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
    // Inicialisar el tablero
    int board[10][10];
    clear_arr(board);
    add_holes(board, 3);
    int pos_x = 0;
    int pos_y = 0;
    int move;
    print_board(pos_x, pos_y);
    while (1){
        printf("Hacia donde te quieres mover:\n 1) Arriba 2) Abajo 3) Izquierda 4) Derecha\n");
        // Leer un numero por entrada estandar para mover al jugador
        scanf("%d", &move);
        // Si el movimiento es valido realizarlo
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
        // Caso contrario imprimir un mensaje de error
    } else{
        printf("Eso es fuera del tablero\n");
    }
    // Verficiar si el usuario gano o perdio
    if (check_hole(board, pos_x, pos_y)){
        printf("Caiste en un agujero, perdiste\n");
        return 0;
    } else if (check_goal(pos_x, pos_y)){
        printf("Llegaste al objetivo, ganaste\n");
        return 0;
    }
    // Reimprimir el tablero
    print_board(pos_x, pos_y);
    }
    return 0;
}
