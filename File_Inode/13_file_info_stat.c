#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){


    struct stat fileStat;

    if(stat("/home/hawk/Desktop/UOS",&fileStat) < 0){
        printf("Failed to retrieve information");
        return 1;
    }

    printf("----------------------------\n");
    printf("File Size is: %ld bytes\n",(long)fileStat.st_size);
    printf("Number of Links: %ld bytes\n",(long)fileStat.st_nlink);
    printf("File Inode: %ld bytes\n",(long)fileStat.st_ino);

    

    printf("File Access Permissions:\n");
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf((fileStat.st_mode & S_IRUSR)? "r": "-");
    printf((fileStat.st_mode & S_IWUSR)? "w": "-");
    printf((fileStat.st_mode & S_IXUSR)? "x": "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");

    printf("File UID: \t\t%d\n", (int)fileStat.st_uid);
    printf("File GID: \t\t%d\n", (int)fileStat.st_gid);
    printf("Time of last modification: %ld\n", (long)fileStat.st_mtime);
    printf("Time of last status change: %ld\n", (long)fileStat.st_ctime);
    printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
    return 0;

}