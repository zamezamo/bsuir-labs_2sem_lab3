/* 
* 03/03/21
* Artyom Zamoyskiy
*
* Task:
* RU: 3. Поменять значения минимальных элементов на максимальные, а максимальных - на минимальные.
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
    for (int i = 0; i < 10; i++)
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
    int max = number[0], min = number[0];
    for (int i = 1; i < 10; i++)
    {
        if (number[i] > max)
            max = number[i];
        if (number[i] < min)
            min = number[i];
    }
    for (int i = 0; i < 10; i++)
    {
        if (number[i] == max)
        {
            number[i] = min;
            fwrite(&number[i], sizeof(int), 1, file);
            
        }
        else if (number[i] == min)
        {
            number[i] = max;
            fwrite(&number[i], sizeof(int), 1, file);
        }
    }
    printf("\n--------- Replace ---------\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%dth element is %d\n", i + 1, number[i]);
    }
    fclose(file);
}
