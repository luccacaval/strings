#include <stdio.h>

#include <string.h>


// Struct para guardar los registros
struct marks {
  float mark;
  int id;
  char subject[30];
};

int main(void) {
  // Inicialisar las variables
  struct marks registers[30];
  float mark;
  int id = -1;
  char subject[30] = "";
  int count = 0;
  // Tomar los registros via entrada estandar y guardarlos en el array de structs
  while ((id != 0 && strcmp(subject, "XXX")) && count < 30) {
    printf("Ingrese un registro con el siguiente formato\n Materia Legajo Nota \n");
    scanf("%s %d %f", subject, & id, & mark);
    strcpy(registers[count].subject, subject);
    registers[count].id = id;
    registers[count].mark = mark;
    count++;
  }

// Inicializar las variables para calcular los promedios y controlar los cambios de matria y legajo
float avg_sub = 0;
float avg_id = 0;
int avg_sub_count = 0;
int marks_count_id = 0;
int prev_id = registers[0].id;
char prev_sub[30];
strcpy(prev_sub, registers[0].subject);
// Ciclo for que recorre todos los registros
  for (int i = 0; i < count; i++) {
    // Cambio de materia 
    if (strcmp(prev_sub, registers[i].subject)){
      // Calcular el ultimo promedio por legajo de la materia y reiniciar las variables pertinentes
      avg_id = avg_id / marks_count_id;
      printf("Promedio del legajo %d = %.2f\n", prev_id, avg_id);
      avg_sub += avg_id;
      avg_sub_count++;
      avg_id = 0;
      marks_count_id = 0;
      prev_id = registers[i].id;
      // Calcular el promedio de la materia y reiniciar las variables pertinentes
      avg_sub = avg_sub / avg_sub_count;
      printf("Promedio para %s = %.2f\n", prev_sub, avg_sub);
      avg_sub = 0;
      avg_sub_count = 0;
      strcpy(prev_sub, registers[i].subject);
      avg_id += registers[i].mark;
      marks_count_id++;
      // Cambio de alumno
    } else if (prev_id != registers[i].id) {
      // Calcular el promedio del alumno
      avg_id = avg_id / marks_count_id;
      printf("Promedio del legajo %d = %.2f\n", prev_id, avg_id);
      // Sumar el promedio del alumno para el calculo del promedio de toda la materaq 
      avg_sub += avg_id;
      avg_sub_count++;
      // Reiniciar las variables para el calculo del promedio por alumno
      avg_id = 0;
      marks_count_id = 0;
      // Comenzar el calculo del proximo promedio por legajo y actualizar las variables de control
      strcpy(prev_sub, registers[i].subject);
      prev_id = registers[i].id;
      avg_id += registers[i].mark;
      marks_count_id++;
    } 
    else{
    // Sumar la calificacion para el calculo del promedio y actualizar las variables de control 
    strcpy(prev_sub, registers[i].subject);
    prev_id = registers[i].id;
    avg_id += registers[i].mark;
    marks_count_id++;
    }
  }
}