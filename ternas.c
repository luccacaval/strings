#include <stdio.h>
#include <math.h>

int main(void)
{
    int count = 1;
/*     FILE *fp;
    fp = fopen("output.txt", "w"); */
    int hip= 1,co = 1,ca = 1;
    while (hip < 500 && co < 500 && ca < 500){
        if (pow(hip, 2) == pow(co, 2) + pow(ca, 2)){
            printf("Terna : hipotenusa = %d, cateto opuesto = %d, cateto opuesto = %d \n", hip,co,ca);
            hip++;
            ca++;
            co++;
            count = 0;
        } else if (pow(hip, 2) < pow(co, 2) + pow(ca, 2)) hip++;
        else if (pow(hip, 2) > pow(co, 2) + pow(ca, 2)){
            if (count % 2 == 0) co++;
            else ca++; 
            count++;
        }
    }
    

    return 0;
}
