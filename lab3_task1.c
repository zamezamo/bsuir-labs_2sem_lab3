/* 
* 01/03/21
* Artyom Zamoyskiy
*
* Task:
* RU: 1. С клавиатуры заполнить файл целыми числами.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int number[10];
    FILE *file = NULL;
    char filename[10];
    printf("enter file name without extension - ");
    scanf("%s", filename);
    printf("------------------------------------\n  file name is %s.bin\n\n", filename);
    file = fopen(strcat(filename, ".bin"), "wb+");
    int temp = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter %dth number - ", i + 1);
        while (1)
        {
            temp = scanf("%d", &number[i]);
            if (temp != 1)
            {
                printf("Enter only numbers! - ");
            }
            else
                break;
        }
        fwrite(&number[i], sizeof(int), 1, file);
    }
    rewind(file);
    for (int i = 0; i < 5; i++)
    {
        fread(&number[i], sizeof(int), 1, file);
        printf("%dth number is %d\n", i + 1, number[i]);
    }
    fclose(file);
}
