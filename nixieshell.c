#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

char shell[50] = "[nixie~]$";
char userinput[100];

int main(int argc, char *argv[]){

  char *pid_ls[] = {"ls", NULL};
  char *pid_ff[] = {"fastfetch", NULL};
  char *pid_nf[] = {"neofetch", NULL};
 
  printf("\nNIXIE SHELL V1\n");
  printf("NixolaTesla on GitHub\n\n");

while(1){
  printf("%s ", shell);
  fgets(userinput, sizeof(userinput), stdin);
  userinput[strcspn(userinput, "\n")] = '\0';
  printf("\nyou typed: %s\n\n", userinput);

  // USER INPUT TO SHELL (EXECVP)
  
  // ls

  if(strcmp(userinput, "ls") == 0){
    pid_t pid = fork();

    if(pid == 0){
    execvp(pid_ls[0], pid_ls);
    perror("EXECVP FAILED");
   }

    else{
     waitpid(pid, NULL, 0);
   }
  }

  // fastfetch

    if(strcmp(userinput, "fastfetch") == 0){
    pid_t pid = fork();

    if(pid == 0){
    execvp(pid_ff[0], pid_ff);
    perror("EXECVP FAILED");
   }

    else{
      waitpid(pid, NULL, 0);
    }
  }

    // neofetch

    if(strcmp(userinput, "neofetch") == 0){
    pid_t pid = fork();

    if(pid == 0){
    execvp(pid_nf[0], pid_nf);
    perror("EXECVP FAILED");
   }

    else{
     waitpid(pid, NULL, 0);
   }
  }

  // cd
   
    if(strcmp(userinput, "cd") == 0){
      pid_t pid = fork();

  }


    // EXIT SHELL

  if(strcmp(userinput, "exit") == 0){
    break;
  }
}
  
  
  return 0;
}
