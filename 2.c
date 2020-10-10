#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#define FILE_LENGTH 0x100

void main() {
  // FILE *input = NULL;
   int fd;
   char c;
   int *a = NULL, i = 0;
   int lines = 1;
   int any;
   void* file_memory;
  
  // input = fopen("F.txt", "rb");

   fd = open("F.txt", O_RDONLY, 0666);
   
  /* if (input == NULL) {
      printf("Ошибка открытия файла");
      exit(0);
   } */

       if( fd == -1){
        printf("Ошибка открытия файлаы\n");
        exit(1);
    }

    char str;

   file_memory = mmap (0, FILE_LENGTH, PROT_READ, MAP_SHARED, fd, 0);

       if (file_memory == MAP_FAILED)
    {
        close(fd);
        printf("Ошибка отображения файла");
        exit(1);
    }



    /*  do {
         any = fgetc(input);
         if (any == '\n') {
            a = (int*)realloc(a, (i + 1) * sizeof(int));
            a[i] = ftell(input);
            i++;
            lines++;
         }
         } while(any != EOF);*/

   int y;
   
 /*  while (1)
   {
    printf("Всего %d строк, выберите какую вывести(Для выхода выберите 0):\n",lines);
    scanf("%d", &y);

    if(y==0){break;}
    if(y>lines){printf("Такой строки нет\n\n"); continue;}
  
    fseek(input, a[y-2], SEEK_SET ); 
    
   while (fscanf(input, "%c", &c) == 1) {
      if(c=='\n') break;
      fprintf(stdout, "%c", c); 
   }
   printf("\n\n");}  */

   
}
