#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    pid_t filho_1, filho_2, wpid;
    int status = 0;

    (filho_1 = fork()) && (filho_2 = fork());

    if (filho_1 == 0) {
        
        printf("Processo %d, filho de %d\n", getpid(), getppid());
        fflush(stdout);
        
        pid_t neto_1_1, neto_1_2, neto_1_3, wpid_f1;
        int status_f1 = 0;
        
        (neto_1_1 = fork()) && (neto_1_2 = fork()) && (neto_1_3 = fork());
        
        if (neto_1_1 == 0) {
            printf("Processo %d, filho de %d\n", getpid(), getppid());
            sleep(5);
            printf("Processo %d finalizado\n", getpid());
            exit(0);
        } else if (neto_1_2 == 0) {
            printf("Processo %d, filho de %d\n", getpid(), getppid());
            sleep(5);
            printf("Processo %d finalizado\n", getpid());
            exit(0);
        } else if (neto_1_3 == 0) {
            printf("Processo %d, filho de %d\n", getpid(), getppid());
            sleep(5);
            printf("Processo %d finalizado\n", getpid());
            exit(0);
        } else {
            while ((wpid_f1 = wait(&status_f1)) > 0);
            printf("Processo %d finalizado\n", getpid());
            exit(0);
        }
        
    } else if (filho_2 == 0) {
        
        printf("Processo %d, filho de %d\n", getpid(), getppid());
        fflush(stdout);
        
        pid_t neto_2_1, neto_2_2, neto_2_3, wpid_f2;
        int status_f2 = 0;
        
        (neto_2_1 = fork()) && (neto_2_2 = fork()) && (neto_2_3 = fork());
        
        if (neto_2_1 == 0) {
            printf("Processo %d, filho de %d\n", getpid(), getppid());
            sleep(5);
            printf("Processo %d finalizado\n", getpid());
            exit(0);
        } else if (neto_2_2 == 0) {
            printf("Processo %d, filho de %d\n", getpid(), getppid());
            sleep(5);
            printf("Processo %d finalizado\n", getpid());
            exit(0);
        } else if (neto_2_3 == 0) {
            printf("Processo %d, filho de %d\n", getpid(), getppid());
            sleep(5);
            printf("Processo %d finalizado\n", getpid());
            exit(0);
        } else {
            while ((wpid_f2 = wait(&status_f2)) > 0);
            printf("Processo %d finalizado\n", getpid());
            exit(0);
        }
        
    } else {
        while ((wpid = wait(&status)) > 0);
        printf("Processo principal %d finalizado\n", getpid());
    }
    
    return 0;
}