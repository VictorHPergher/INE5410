#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

//       (pai)      
//         |        
//    +----+----+
//    |         |   
// filho_1   filho_2


// ~~~ printfs  ~~~
// pai (ao criar filho): "Processo pai criou %d\n"
//    pai (ao terminar): "Processo pai finalizado!\n"
//  filhos (ao iniciar): "Processo filho %d criado\n"

// Obs:
// - pai deve esperar pelos filhos antes de terminar!


int main(int argc, char** argv) {

    pid_t filho_1, filho_2, wpid;
    int status = 0;

    (filho_1 = fork()) && (filho_2 = fork());
    
    if (filho_1 > 0 && filho_2 > 0) {
        printf("Processo pai criou %d\n", filho_1);
        printf("Processo pai criou %d\n", filho_2);
    }

    if (filho_1 == 0) {
        printf("Processo filho %d criado\n", getpid());
        exit(0);
    } else if (filho_2 == 0) {
        printf("Processo filho %d criado\n", getpid());
        exit(0);
    } else {
        while ((wpid = wait(&status)) > 0);
        printf("Processo pai finalizado!\n");
    }
    
    return 0;
}
