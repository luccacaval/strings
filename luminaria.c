#include <stdio.h>

void set_calles(int calles[5][15]){
    for (int i = 0; i < 5; i++){
        for(int j = 0;j < 15;j++){
            calles[i][j] = 0;
        }
    }
}

void set_max(int max_calles[5]){
    for (int i = 0; i < 5; i++){
        printf("Ingrese el numero maximo de luces encendidas para la calle %d\n", i+1);
        scanf("%d",&max_calles[i]);
    }
}

int check_max(int calles[5][15], int calle, int max_calle){
    int luces_encendidas = 0;
    for (int  i = 0; i < 15; i++){
        luces_encendidas += calles[calle][i];
    }
    if (luces_encendidas > max_calle){
        /* code */
    }
    
}

void flip_light(int calles[5][15]){
    int calle,luz;
    printf("Ingrese el numero de calle y la luz (En ese orden) para prender/apagar\n");
    scanf("%d %d",&calle,&luz);
    calles[calle][luz] = !calles[calle][luz];
}

int main(void){
    int calles[5][15];
    int max_calles[5];
    set_calles(calles);
    set_max(max_calles);
}