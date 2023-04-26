#include <stdio.h>

#include <string.h>

struct marks {
  float mark;
  int id;
  char subject[30];
};

int main(void) {
  struct marks registers[30];
  float mark;
  int id = -1;
  char subject[30] = "";
  int count = 0;
  while ((id != 0 && strcmp(subject, "XXX")) && count < 30) {
    printf("Ingrese un registro con el siguiente formato\n Materia Legajo Nota \n");
    scanf("%s %d %f", subject, & id, & mark);
    strcpy(registers[count].subject, subject);
    registers[count].id = id;
    registers[count].mark = mark;
    count++;
  }
float avg_sub = 0;
float avg_id = 0;
int avg_sub_count = 0;
int marks_count_id = 0;
int prev_id = registers[0].id;
char prev_sub[30];
strcpy(prev_sub, registers[0].subject);

  for (int i = 0; i < count; i++) {
/*     if (registers[i].id == 1 && !(strcmp(registers[i].subject, "XXX"))){
        avg_sub -= registers[i].mark;
    } */
    if (strcmp(prev_sub, registers[i].subject)){
      avg_id = avg_id / marks_count_id;
      printf("Promedio del legajo %d = %.2f\n", prev_id, avg_id);
      avg_sub += avg_id;
      avg_sub_count++;
      avg_id = 0;
      marks_count_id = 0;
      prev_id = registers[i].id;
      avg_sub = avg_sub / avg_sub_count;
      printf("Promedio para %s = %.2f\n", prev_sub, avg_sub);
      avg_sub = 0;
      avg_sub_count = 0;
      strcpy(prev_sub, registers[i].subject);
      avg_id += registers[i].mark;
      marks_count_id++;
    } else if (prev_id != registers[i].id) {
      avg_id = avg_id / marks_count_id;
      printf("Promedio del legajo %d = %.2f\n", prev_id, avg_id);
      avg_sub += avg_id;
      avg_sub_count++;
      avg_id = 0;
      marks_count_id = 0;
      strcpy(prev_sub, registers[i].subject);
      prev_id = registers[i].id;
      avg_id += registers[i].mark;
      marks_count_id++;
    } 
    else{
    strcpy(prev_sub, registers[i].subject);
    prev_id = registers[i].id;
    avg_id += registers[i].mark;
    marks_count_id++;
    }
  }
}