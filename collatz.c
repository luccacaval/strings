#include <stdio.h>
#include <conio.h>

int main(void){
    long x;
    // Pedirle al usuario que ingrese un numero
    printf("Ingrese el numero con el que quiera comenzar\n");
    scanf("%ld",&x);
    while (x != 1){
    if (x % 2 == 0){
        // Si es par dividir por 2
        // Al sacarle el ultimo bit a un numero en binario se divide por 2, sin tener en cuenta el resto (si lo hubiera)
        x = x >> 1;
        printf("%ld\n", x);
    } else {
        // Si es impar multiplicarlo por 3 y sumarle 1
        x = (x * 3) + 1;
        printf("%ld\n", x);
    }
    }       
}