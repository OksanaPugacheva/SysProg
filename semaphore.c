#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/fcntl.h>


long int fa(long int n)
{
    return n + 1;
}

int main() {
   FILE *input = NULL;

input = fopen("Lo.txt", "w");

   if (input == NULL) {
      printf("Ошибка открытия файла");
      exit(0);
   }
sem_t *s0;
sem_t *s1;
int i =0;
int err=0;
char lpsz_sem0[]="/000";
char lpsz_sem1[]="/111";

s0= sem_open(lpsz_sem0, O_CREAT, 0777,1);
s1= sem_open(lpsz_sem1, O_CREAT, 0777,0);

if(s0 == SEM_FAILED || s1 == SEM_FAILED){
   perror("Err");
   return(-1);
}

if(fork()){
   for(i=0;i<10;i++){
      sem_wait(s0);
      fputs("child\n", input);
      printf("child\n");
      sem_post(s1);
   }
}
else
{
     for(i=0;i<10;i++){
      sem_wait(s1);
      fputs("parent\n", input);
      printf("parent\n");
      sem_post(s0);
   }
}
sem_unlink(lpsz_sem0);
sem_unlink(lpsz_sem1);


   fclose(input);
   
}
