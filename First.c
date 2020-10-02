#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>

void main() {
   FILE *input = NULL;
   char c;
   int *a = NULL, i = 0;
   int lines = 0;
   int any;
  
   input = fopen("F.txt", "rt");
   
   if (input == NULL) {
      printf("Ошибка открытия файла");
      exit(0);
   }

      do {
         any = fgetc(input);
         if (any == '\n') {
            a = (int*)realloc(a, (i + 1) * sizeof(int));
            a[i] = ftell(input);
            i++;
            lines++;
         }
         } while(any != EOF);

   int y;
    printf("Всего %d строк, выберите какую вывести:\n",lines);
    scanf("%d", &y);
  
    fseek(input, a[y-2], SEEK_SET ); 
    
   while (fscanf(input, "%c", &c) == 1) {
      if(c=='\n') break;
      fprintf(stdout, "%c", c); 
   }
   printf("\n");
   fclose(input);
   
}
