#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int treasure_pos_x,treasure_pos_y;

void print_board(int len ,int(*board)[len]){
    // Recorrer todo el tablero imprimiendo sus valores
    for (int i = 0; i < len; i++){
        for(int j = 0; j < len;j++){
            // EN caso de llegar a la ubicacion del tesoro imprimir 1 para reprecentar tierra
            if (board[i][j] == 2){
                printf("1 ");
            } else printf ("%d ",board[i][j]);
        }
        printf("\n");
    }
}

int check_trasure(int pos_x, int pos_y, int len, int(*board)[len]){
    if (board[pos_y][pos_x] == 2) return 1;
    else return 0;
    return !(board[pos_y][pos_x] == 2);
}

void set_board(int len ,int(*board)[len]){
    // Recorrer todo el tablero, rellenar los bordes con 1 para reprecentar agua y 0 para reprecentar tierra
    for (int i = 0; i < len; i++){
        for(int j = 0; j < len;j++){
            printf("%d:%d\n",j,i);
            if ((((i == 0 || i == len -1 )|| j == 0) || j == len -1)){
                board[i][j] = 0;
            } else board[i][j] = 1;
        }
    }
    // Establecer una semilla para los numueros aleatorios
    srand(time(NULL));
    // Generar dos numeros aleatorios para la ubicacion del tesoro
    treasure_pos_x = rand() % len;
    treasure_pos_y = rand() % len;
    // Comprobar si el tesoro esta ubicado en agua y si es el caso volver a generar los numeros
    while (board[treasure_pos_y][treasure_pos_x] == 0){
            treasure_pos_x = rand() % len; 
            treasure_pos_y = rand() % len;
    }
    // Establecer un valor de dos en la ubicacion previamente definida para reprecentar el tesoro
    board[treasure_pos_y][treasure_pos_x] = 2;
}

int check_bounds(int pos_x, int pos_y,int move,int len){
    // Verficar si la casilla a la que se quiere mover el usuario esta dentro del tablero
    switch (move)
    {
    case 1:
        if(pos_y - 1 < 0) return 0;
        else return 1;
    case 2:
        if(pos_y + 1 > len) return 0;
        else return 1;
    case 3:
        if(pos_x - 1 < 0) return 0;
        else return 1;
    case 4:
        if(pos_x + 1 > len) return 0;
        else return 1;
    default:
        return 0;
    }
}

int main(void){
    srand(time(NULL));
    // Definir la variable correspondiente y pedirle al usuario que ingrese el tamaño del tablero
    int len;
    printf("Ingrse el tamanio del tablero\n");
    scanf("%d", &len);
    // Inicialisar el tablero y llamar a la funcion que alamacena en el los valores correspondientes
    int board[len][len];
    set_board(len,board);
    // Variable para contar los turnos jugados
    int turns = 0;
    // Variables para alamacenar la posicion del jugador
    int pos_x = rand() % len;
    int pos_y = rand() % len;
    // Variables para almacenar la posicion anterior del jugador
    int prev_x = pos_x;
    int prev_y = pos_y;
    // Variable para almacenar que habia en la posicion anterior del jugador
    int prev_land = board[pos_y][pos_x];
    // Alamacenar un 3 en la posicion del jugador para reprecentarlo
    board[pos_y][pos_x] = 3;
    // Variable para almacenar la eleccion del juagdor
    int move;
    print_board(len,board);
        while (turns < 50){
        printf("Hacia donde te quieres mover:\n 1) arriba 2) Abajo 3) Izquierda 4) Derecha\n");
        printf("Te quedan %d turnos", 50-turns);
        // Leer un numero por entrada estandar para mover al jugador
        scanf("%d", &move);
        // Si el movimiento es valido realizarlo
        if (check_bounds(pos_x, pos_y,move,len)){
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
        // Veficar si el jugador gano, si es el caso imprimir un mensaje y salir del programa
        if (check_trasure(pos_x,pos_y,len,board)){
            printf("Ganaste el juego, felisitaciones\n");
            exit(0);
        }
        // Reubicar el 3 que reprecenta al jugador
        board[pos_y][pos_x] = 3;
        // Volver a poner el numero que reprecentaba el tipo de terreno en el que estaba el juagador
        board[prev_y][prev_x] = prev_land;
        // Actualizar las variables de posicion anterior
        prev_x = pos_x;
        prev_y = pos_y;
        // Caso contrario imprimir un mensaje de error
    } else{
        printf("Eso es fuera del tablero\n");
    }
    // Suamar 1 la la variable turns y volver a imprimir el tablero con los ultimos cambios
    turns++;
    print_board(len,board);
}
}