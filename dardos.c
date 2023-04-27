#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * sacar_salto(char str[]){
    int len = strlen(str);
    int i = 0;
    while (i < len){
        if (str[i] == '\n'){
            str[i] = '\0';
        }
    }
    return str;
}

void show_res(char Jugadores[9][20], int Edades[9], int Puntajes[9], int centros, int turnos){
    int max_score = 0;
    int menores = 0;
    for (int i = 0; i < 9; i++){
        printf("%s, %d puntos", Jugadores[i], Puntajes[i]);
        if (Puntajes[i] > Puntajes[max_score]){
            max_score = i;
        }
        if (Edades[i] <= 18){
            menores++;
        }
    }
    float ratio_centros = ((centros + 0.0) / (turnos + 0.0)) * 100.00;
    float ratio_menores = (menores / 9.0) * 100.00;
    printf("Maximo anotador %s, porcentaje de menores %0.2f, porcentaje de centros %0.2f", Jugadores[max_score], ratio_menores, ratio_centros);
    exit(0);
}

int main()
{
    char Jugadores[9][20];
    int Edades[9];
    int Puntajes[9] = {0,0,0,0,0,0,0,0,0};

    for (int i = 0; i < 9; i++){
    char nombre[20];
    printf("Ingrese el nombre del jugador %d\n",i+1);
    fgets(nombre, 20, stdin);
    int nombre_len = strlen(nombre);
    nombre[nombre_len] = '\0';
    strcpy(Jugadores[i], nombre);
    printf("Ingrese la edad del jugador %d\n", i+1);
    scanf("%d", &Edades[i]);
    getchar();
    }   
    for (int i = 0; i < 9; i++){
        printf("%s %d\n", Jugadores[i], Edades[i]);
    }
    
    int turno = 0;
    char pos;
    int centros = 0;
    while (1){
        printf("Le toca a %s, donde dio? \n C) Centro, M) Medio, B) Blanco, F) Fallo \n", Jugadores[turno % 9]);
        if (turno > 8){
            printf("Para salir ingrese S\n");
        }
        scanf("%c", &pos);
        switch (pos)
        {
        case 'C':
            Puntajes[turno] += 100;
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
            if (turno >= 8){
                show_res(Jugadores,Edades,Puntajes, centros, turno);
            } else {
                printf("Opcion invalida\n");
            }
            break;
        default:
            printf("Opcion invalida\n");
            turno--;
            break;
        }
        getchar();
        turno++;
    }
    return 0;
}
