#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>

int main (int argc, char *argv[], char *envp[]) {

    int pid = fork(); // The 'pid' identifies the process that is running.
    char comma[100], save_pid[100];

    // Check if the fork failed
    if (pid < 0) {
        perror ("Error: ");
        exit(-1); // End the process with an error code (-1)
    
    } else if (pid == 0) { // I'm the child process

        if(strcmp(argv[1], "ucp") == 0) { // Check if argv[1] is "ucp" to monitor cpu usage
            for (;;) {}                  // Infinite loop that is cpu intensive
        } else if(strcmp(argv[1], "ucp-mem") == 0) { // Check if argv[1] is "ucp-mem" to monitor cpu and memory usage
            for (;;) {                  // Infinite loop that is cpu and memory intensive
                malloc(sizeof(char));   // Memory allocation
            } 
        }
    
    } else {  // I'm the parent process
        sprintf(save_pid, "%d", pid); // Save the current process identifier
        
        if (strcmp (argv[1], "ucp") == 0) { 
            
            printf ("# CPU USAGE #\n");
            strcpy(comma, "ps -e -o pid,pcpu | grep "); // Save in 'comma' the bash command
            strcat(comma, save_pid); // Concatenate the bash command and the saved pid
        
        } else if (strcmp (argv[1], "ucp-mem") == 0) {

            printf ("# CPU AND MEMORY USAGE #\n");
            strcpy(comma, "ps -e -o pid,pcpu | grep ");
            strcat(comma, save_pid);
            strcat(comma, ";pmap "); // Show the memory consumption
            strcat(comma, save_pid); 
            strcat(comma, " | grep -i total");
        }
    
        for (int cont = 0; cont < 3; cont++) {
            system(comma);
            usleep(500000);
        }
        strcpy(comma, "kill "); // Kill the child process
        strcat(comma, save_pid);
        system(comma);
    }

    perror("Error: "); 

    exit(0); // Terminate the process with success
    return 0;
}