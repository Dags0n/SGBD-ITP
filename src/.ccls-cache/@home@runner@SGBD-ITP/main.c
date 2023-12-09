#include "sgbd.h"
#include <stdio.h>

// Made for Rômulo
//--||menssages||--
void msg_menu() {
  printf("\n"
         "|--What do you want to do?--|\n"
         "| 1 - Make a table          |\n"
         "| 2 - Show tables           |\n"
         "| 3 - Delete one table      |\n"
         "| 4 - Something in a table  |\n"
         "| 5 - Close the system      |\n\n");
}

void msg_table() {
  printf("\n"
         "|--What do you want to do?--|\n"
         "| 1 - Show                  |\n"
         "| 2 - Insert data           |\n"
         "| 3 - Remove data           |\n"
         "| 4 - Search something      |\n"
         "| 5 - Back                  |\n\n");
}

//--||screens||--
void openTable() {
  char *name = (char *)malloc(50 * sizeof(char));
  printf("Table name: ");
  scanf("%s", name);
  name = toLower(name);
  if (!tableExists(name)) {
    printf("Table not exists!\n");
    free(name);
    return;
  }

  int on = 1;
  int key;
  while (on) {
    msg_table();
    printf("Chose a option: ");
    scanf("%d", &key);
    switch (key) {
      case 1: showData(name); break;
      case 2: insertData(name); break;
      case 3: delData(); break;
      case 4: searchData(); break;
      case 5: on = 0; break;
      default: printf("Invalid option!\n\n");
    }
  }
}

//--||main||--
int main(void) {
  int key;

  serverOn();
  int on = 1;

  printf("Hello User!\n");
  while (on) {
    msg_menu();
    printf("Chose a option: ");
    scanf("%d", &key);
    switch (key) {
      case 1: makeTable(); break;
      case 2: showTables(); break;
      case 3: delTable(); break;
      case 4: openTable(); break;
      case 5: on = 0; break;
      default: printf("Invalid option!\n\n");
    }
  }
  printf("See you late!!!");
  return 0;
}