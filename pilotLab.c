#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <locale.h>

int main()
{
    char *arg[]={"./pilotChild", NULL};
    pid_t idProc;
    int status; 
    
    //Устанавиваем русский язык в консоли
    //setLocale(LC_ALL, "Rus");

    switch (idProc = fork())
    {
    case -1:
        printf("ERR: Процесс не создан!\n");
        exit(-1);

    case 0:
        execvp(arg[0], arg);    
    
    default:
        printf("Родительский процесс [%d] запущен\n", getpid());
        wait(&status);
        printf("Процесс завершен с кодом: [%d]\n", WEXITSTATUS(status));
    }
    return 0;
}