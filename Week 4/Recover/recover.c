#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check if user input two argc or not
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    //declare variables
    int counter = 0;
    char *newFileName = malloc(sizeof(char) * 8);
    BYTE *buffer = malloc(512 * sizeof(BYTE));
    FILE *file = fopen(argv[1], "r");
    FILE *newFile = NULL;

    while (fread(buffer, sizeof(BYTE), 512, file) == 512)
    {
        //check if the following 512 bytes are jpeg or not
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter != 0)
            {
                fclose(newFile);
            }
            //assign new file number to the up comming file
            sprintf(newFileName, "%03i.jpg", counter++);
            newFile = fopen(newFileName, "w");
        }
        if (newFile != NULL)
        {
            fwrite(buffer, 512, 1, newFile);
        }
    }

    //close all unused data to prevent data lost
    fclose(newFile);
    fclose(file);
    free(newFileName);
    free(buffer);

    return 0;
}