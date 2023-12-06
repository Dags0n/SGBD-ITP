//--||Includes||--
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//--|||Functions|||--

// Made for Rômulo
char *toLower(char *string) {
  for (int i = 0; i < strlen(string); i++) {
    string[i] = tolower(string[i]);
  }
  return string;
}

void removeStructLine(char* name){
  char line[1000];
  FILE* output = fopen("temp.txt", "a");
  FILE* input = fopen("struct.txt", "r");
  char *nameTwo = (char *)malloc(51 * sizeof(char));
  strcpy(nameTwo, name);
  strcat(nameTwo, ":");
  while(fgets(line, sizeof(line), input)){
    if(strstr(line, nameTwo) == NULL){
      printf("%s\n",line);
      fprintf(output, "%s", line);
    }
  }
  fclose(input);
  remove("struct.txt");
  rename("temp.txt", "struct.txt"); 
  fclose(output);
  free(nameTwo);
}

void serverOn() {
  FILE *server;
  server = fopen("struct.txt", "a");
  fclose(server);
}

char *path(char *name) {
  char *path = (char *)malloc(sizeof(char) * 60);
  strcpy(path, "Tables/");
  strcat(path, name);
  strcat(path, ".txt");
  return path;
}

int tableExists(char *name) {
  FILE *table = fopen(path(name), "r");
  if (table == NULL) {
    return 0;
  }
  fclose(table);
  return 1;
}

void makeTable() {
  char *name = (char *)malloc(50 * sizeof(char));
  char trash;
  FILE *table;

  printf("Table name: ");
  scanf("%s%c", name, &trash);
  name = toLower(name);
  if (tableExists(name)) {
    printf("Invalid table!\n");
    return;
  }
  table = fopen(path(name), "a");
  fclose(table);

  table = fopen("struct.txt", "a");
  fprintf(table, "%s: ", name);

  printf("Primary Key name: ");
  scanf("%s%c", name, &trash);
  fprintf(table, "(%s, pk) ", name);

  char type, option;
  printf("\nChose i for int, c for char, s for string or d for double\n\n");

  while (1) {

    printf("Colum name: ");
    scanf("%s%c", name, &trash);
    printf("Type: ");
    scanf("%c%c", &type, &trash);
    fprintf(table, "(%s, %c) ", name, type);

    printf("New colum [Y/N]: ");
    scanf("%s%c", &option, &trash);
    if (option == 'N') {
      fprintf(table, "\n");
      break;
    }
  }

  fclose(table);
}

void showTables() {
  char arqName[] = "struct.txt";
  FILE *arq = fopen(arqName, "r");
  char line[1000];
  int cont = 1;
  printf("\nAll tables:\n");
  while (fgets(line, sizeof(line), arq) != NULL) {
    printf("%d - %s", cont, line);
    cont++;
  }
}

void delTable() {
  char *name = (char *)malloc(50 * sizeof(char));
  char trash;
  FILE *table;
  printf("Table name: ");
  scanf("%s", name);
  name = toLower(name);
  if(tableExists(name)){
    remove(path(name));
    removeStructLine(name);
  } else {
    printf("Invalid table!\n");
  }
}

// Made for Dagson
void insertData() {
  // To make
}

void showData() {
  // To make
}

void searchData() {
  // To make
}

void delData() {
  // To make
}