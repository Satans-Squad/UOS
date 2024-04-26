#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int main(){
    char pathname[255];

    printf("Enter pathname:");
    scanf("%s",&pathname);

    struct stat fileStat;

    if(stat(pathname,&fileStat) < 0){
        perror("Error in converting...");
        return 1;
    }

    printf("Inode Number %s is \t %ld \t",pathname,(long)fileStat.st_ino);
    return 0;
}