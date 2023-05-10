#include <stdio.h>
#include <stdbool.h>

void set_board(char board[3][3]){
    // Rellenar el tablero con el caracter |
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board[i][j] = '|';
        }
    }  
}

int has_won(char board[3][3]){
    for (int i = 0; i < 3; i++){
    // Verificar si los caracteres en una fila o en una columna son todos iguales
    bool horizontal = board[i][0] ==  board[i][1] && board[i][1] == board[i][2];
    bool vertical = board[0][i] ==  board[1][i] && board[1][i] == board[2][i];
    // Verificar si algunos de los caracteres en la fila o en la columna son un plase holder
    bool ph_horizontal = (board[i][0] ==  '|' && board[i][1] == '|') && board[i][2] == '|';
    bool ph_vertical = (board[0][i] ==  '|' && board[1][i] == '|') && board[2][i] == '|';
    // Si estas condiciones se cumplen devolver 1
    if(horizontal && !(ph_horizontal)){
        return 1;
    } else if (vertical && !(ph_vertical)){
        return 1;
    } 
    }
    // Realizar las mismas verficaciones sobre las diagonales
    bool diagonal_1 = board[0][0] == board[1][1] && board[1][1] == board[2][2];
    bool diagonal_2 = board[0][2] == board[1][1] && board[1][1] == board[2][0];
    bool diagonal_1_ph = (board[0][0] != '|' && board[1][1] != '|') && board[2][2] != '|';
    bool diagonal_2_ph = (board[0][2] != '|' && board[1][1] != '|' )&& board[2][0] != '|';
    if (diagonal_1 && !(diagonal_1_ph)){
        return 1;
    } else if (diagonal_2 && !(diagonal_2_ph)){
        return 1;
    }
    return 0;
}

void print_board(char board[3][3]){
    // Recorrer todo el tablero
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3; j++){
            // Imprimir el caracter que se encuentra en esta posicion
            printf("%c ", board[i][j]);
        }
        // Antes de cambiar de fila imprimir un salto de linea
        printf("\n");
    }
}

int main(void){
    // Inicializar el tablero y rellenarlo
    char board[3][3];
    set_board(board);
    // Comenzar el conteo de turnos
    int player_turn = 1;
    int x_pos,y_pos;
    printf("Bienvenido a tres en raya, el objeitvo es alinear 3 simbolos mitras evita que el contrario hago lo mismo\n");
    print_board(board);
    while (player_turn != 10){
        printf("Jugador %d ingrese las cordenadas X e Y donde quere poner su ficha\n", player_turn % 2  == 0 ? 2 : 1);
        // Leer dos numeros via entrada estandar para ubicar una ficha
        scanf("%d %d", &x_pos, &y_pos);
        // Verificar que el casillero este vacio
        if (board[y_pos - 1][x_pos - 1] == '|'){
        // Asignar el caracter correspondiente en el tablero
        board[y_pos - 1][x_pos - 1] = player_turn % 2  == 0 ? 'X' : 'O';
        print_board(board);
        // Comprobar si el jugador que puso una ficha gano
        if (has_won(board) && player_turn > 3){
            printf("El jugador %d ha ganado", player_turn % 2  == 0 ? 2 : 1);
            return 0;
        }
        player_turn++;
        } else{
            // SI e espacio ya tenia una ficha imprimir un mensaje de error
            printf("Ese espacio ya esta ocupado, elija otra posicion\n");
        }
    }
    // En caso de que se juegon los 9 turnos imprimir un mensaje de empate y cerrar el programa
    printf("Empate\n");
}