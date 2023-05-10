#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr_includes_char(char Jugadores_i[], char initial, int initials_count){
    // Recorrer todas las iniciales definidas hasta el momento
    for (int i = 0; i < initials_count; i++){
        // La la inicial por definir ya esta en el array devolver 1
        if (Jugadores_i[i] == initial){
            return 1;
        }
    }
    // Si la inical por definir no esta en el array devolver 1
    return 0;
}

void get_initials (char Jugadores[9][20], char Jugadores_i[9]){
    // Recorrer todos los nombres
    for (int i = 0; i < 9; i++){
        // Recorrer todas las letras de todos los nombres
        for (int j = 0; j < 20; j++){
            // Buscar la primer letra en el nombre que no aparesca en el array y asignarla en el array
            if(!(arr_includes_char(Jugadores_i, Jugadores[i][j],i))){
                Jugadores_i[i] = Jugadores[i][j];
                break;
            } 
        }  
    }
    
}
void show_res(char Jugadores_i[9], int Edades[9], int Puntajes[9], int centros, int turnos){
    // Definir variables para la cantidad de jugadores y para el puntaje maximo 
    int max_score = 0;
    int menores = 0;
    // Recorrer todos los puntajes
    for (int i = 0; i < 9; i++){
        // Imprimir el resultado final de este jugador
        printf("%s, %d puntos", Jugadores_i[i], Puntajes[i]);
        // Verificar si este punaje es mas grande que el maximo y si  fuera el caso asignarlo a la variable correspondiente
        if (Puntajes[i] > Puntajes[max_score]){
            max_score = i;
        }
        // Verificar si el jugador es menor y si fuera el caso sumarle 1 a la variable correspondiente
        if (Edades[i] <= 18){
            menores++;
        }
    }
    // Calcular el porcentaje de centros y de menores
    float ratio_centros = ((centros + 0.0) / (turnos + 0.0)) * 100.00;
    float ratio_menores = (menores / 9.0) * 100.00;
    // Imprimir los resultados
    printf("Maximo anotador %s, porcentaje de menores %0.2f, porcentaje de centros %0.2f", Jugadores_i[max_score], ratio_menores, ratio_centros);
    exit(0);
}

int main(){
    // Definir las variables para los jugadores, las iniciales, las edades y los puntajes
    char Jugadores[9][20];
    char Jugadores_i[9];
    int Edades[9];
    int Puntajes[9] = {0,0,0,0,0,0,0,0,0};
    // Cargar 9 nombres y edades
    for (int i = 0; i < 9; i++){
    // Almacenar el nombre del jugador 
    char nombre[20];
    printf("Ingrese el nombre del jugador %d\n",i+1);
    fgets(nombre, 20, stdin);
    strcpy(Jugadores[i], nombre);
    // Almacenar la edad del jugador
    printf("Ingrese la edad del jugador %d\n", i+1);
    scanf("%d", &Edades[i]);
    // Sacar el '\n' del buffer
    getchar();
    }
    // Obtener las inciales
    get_initials(Jugadores, Jugadores_i);   
    // Definir variables para el nro de turno, la cantidad de centros y para donde impacto el tiro
    int turno = 0;
    char pos;
    int centros = 0;
    // Almacenar tiros
    while (1){
        printf("Le toca a %s, donde dio? \n C) Centro, M) Medio, B) Blanco, F) Fallo \n", Jugadores[turno % 9]);
        // Si todos los jugadores ya tirararon al menos 1 vez habiliar la opcion de salir
        if (turno > 8){
            printf("Para salir ingrese S\n");
        }
        scanf("%c", &pos);
        // Verificar donde impacto el tiro
        switch (pos)
        {
        case 'C':
            Puntajes[turno] += 100;
            // Si el tiro impacto en el centro sumarle 1 a la variable correspondiente
            centros++;
            break;
        case 'M' :
            Puntajes[turno] += 50;
            break;
        case 'B' :
            Puntajes[turno] += 10;
            break;
        case 'F' :
           Puntajes[turno] -= 10;
           break;
        case 'S' :
        // Si todos los jugadores ya tirararon al menos 1 vez habiliar la opcion de salir
            if (turno >= 8){
                show_res(Jugadores_i,Edades,Puntajes, centros, turno);
        // Sino imprimir un mensaje de error
            } else {
                printf("Opcion invalida\n");
            }
            break;
        default:
        // Si el usuario ingreso un caracter que no reprecenta ninguna posiscion restarle 1 a la variables turnos para repetir el turno
            printf("Opcion invalida\n");
            turno--;
            break;
        }
        // Sacar el '\n' del buffer
        getchar();
        turno++;
    }
    return 0;
}
