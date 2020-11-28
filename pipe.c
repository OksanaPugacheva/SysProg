#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(){
    int fd[2];
    size_t size;
    char resstring[14]; 
    char ch; int j = 0;

    if(pipe(fd) < 0){
        printf("Не удалось создать канал\n");
        exit(-1); 
    } 

    if(fork() == -1){ 
        printf("Не удалось создать подпроцесс\n");
        exit(-1);

    } else if (fork() > 0) {
        close(fd[0]);
        size = write(fd[1], "Hello, world!", 14);
        if(size != 14){
            printf("Не удалось прочитать стоку\n"); 
            exit(-1); 
        } 
        close(fd[1]);
        printf("Родитель закончил\n");

    } else {
        close(fd[1]);
        size = read(fd[0], resstring, 14);
        if(size < 0){
            printf("Не удалось записать строку\n"); 
            exit(-1); 
        } 
        while (resstring[j]) {
            ch = resstring[j];
            putchar(toupper(ch));
            j++;
        }
        printf("\n");
        close(fd[0]);
    }    
    return 0; 
}
