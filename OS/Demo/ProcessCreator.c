#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>

#include <sys/stat.h>

#include <string.h>



int main(int argc, char *argv[])

{

    int flag,i;



    for (i = 1; i < argc; i++)

    {

        char pipePath[] = "/home/humayun/Desktop/Class_work/Exam_code/Exam2"; // filePath or location

        

        strcat(pipePath, argv[i]);



        

        if (access(pipePath, F_OK) == 0) // Check if pipe already exists

        {

            printf("%s pipe is already created!\n. ", argv[i]);

            exit(-1);

        }



        // Creating namedPipe

        flag = mkfifo(pipePath, 0666); // here the number is a permission

        if (flag == -1)

        {

            printf("Some error has been occured here.\n");

        }

        else

        {

            printf("Pipe creation is successful.\n");

        }

    }



    return 0;

}