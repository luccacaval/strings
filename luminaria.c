#include <stdio.h>

void print_calles(int calles[5][15]){
    // Recorrer todas las calles e imprimir el estado de todas las luces
    for (int calle = 0; calle < 5; calle++){
        for (int luz = 0; luz < 15; luz++){
            printf("%d ", calles[calle][luz]);
        }
        printf("\n");
    }
    
}

void set_calles(int calles[5][15]){
    // Rellenar todo el array con 0s
    for (int i = 0; i < 5; i++){
        for(int j = 0;j < 15;j++){
            calles[i][j] = 0;
        }
    }
}

void set_max(int max_calles[5]){
    // Recorrer todas las calles
    for (int i = 0; i < 5; i++){
        // Pedirle al usuario que ingrese el numero maximo de luces encendidas para esta calle
        int num;
        printf("Ingrese el numero maximo de luces encendidas para la calle %d\n", i+1);
        scanf("%d",&num);
        // Si el numero es menor a 15 cargarlo en el array 
        if (num <= 15){
            max_calles[i] = num;
        } else { // Si no volver a pedir un numero maximo de luces
            printf("La cantidad maxmia de luces encendidas por calle no puede ser mayor a 15\n");
            i--;
        }
    }
}

int check_max(int calles[5][15], int calle, int max_calle){
    int luces_encendidas = 0;
    // Sumar todos los numeros en una calle 
    for (int luz = 0; luz < 15; luz++){
        luces_encendidas += calles[calle][luz];
    }
    // Si ese numero es igual al maximo de luces encendidas para esa calle devolver 1
    if (luces_encendidas == max_calle + 1){
        return 1;
    } else { // Sino devolver 0
        return 0;
    }
}

void check_state(int calles[5][15], int max_calle[5]){
    int luces_encendidas = 0;
        // Recorrer todas las calles 
    for (int calle = 0; calle < 5; calle++){
        // Sumar todos los numeros en una calle 
        for (int luz = 0; luz < 15; luz++){
            luces_encendidas += calles[calle][luz];
        }
        // Segun las condicines que se cumplan imprimir un estado u otro
        if (luces_encendidas == max_calle[calle] && 15 / luces_encendidas > 15 / 2){
            printf("Calle %d muy luminosa\n", calle);
        } else if (luces_encendidas == max_calle[calle] && 15 / luces_encendidas < 15 / 2){
            printf("Calle %d luminosa\n", calle);
        } else if (luces_encendidas == 0){
            printf("Calle %d a oscuras\n", calle);
        } else {
            printf("Calle %d tenebrosa\n", calle);
        }
    }
}

void flip_light(int calles[5][15], int max_calles[5]){
    // Peidrle al usuario que ingrese el numero de calle y luz que quiere prender o apagar 
    int calle,luz;
    printf("Ingrese el numero de calle y la luz (En ese orden) para prender/apagar\n");
    scanf("%d %d",&calle,&luz);
     calles[calle - 1][luz - 1] = !calles[calle - 1][luz - 1];
    // Si la calle no tiene el numero maximo de luces encendidas 
    if (check_max(calles, calle - 1, max_calles[calle - 1])){
        printf("Esa calle ya tiene el maximo de luces\n");
        calles[calle - 1][luz - 1] = !calles[calle - 1][luz - 1];
    }
}

int main(void){
    // Inicializar los arrays para las calles y para los maximos de luces 
    int calles[5][15];
    int max_calles[5];
    // Llamar a las funciones para preparar los arrays 
    set_calles(calles);
    set_max(max_calles);
    // Inicializar la variable para alamcenar 
    int choise;
    while (1){
        // Imprimir el estado actual de las luses y pedirle al usuario que selecione una opcion
        print_calles(calles);
        printf("¿Que desea hacer?\n 1) Encender / apagar una luz\n 2) Verificar el estado de las calles \n 3) Salir \n");
        scanf("%d",&choise);
        getchar(); // Para limpiar el buffer
        // Segun la opcion seleciconada por el usuario llamar a la funcion correspondiente o salir del programa
        switch (choise){
        case 1:
            flip_light(calles, max_calles);
            break;
        case 2:
            check_state(calles, max_calles);
            break;
        case 3:
            return 0;
        default:
            printf("Ingrese una opcion valida");
            break;
        }
    }
    
}