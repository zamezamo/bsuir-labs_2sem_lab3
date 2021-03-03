/* 
* 03/03/21
* Artyom Zamoyskiy
*
* Task:
* RU: 2. В некоторых видах спортивных состязаний (например, в фигурном катании) выступление каждого спортсмена
* независимо оценивается несколькими судьями, затем из всей совокупности оценок удаляются наиболее высокая
* и наиболее низкая, а для оставшихся оценок вычисляется среднее арифметическое, которое и идет в зачет
* спортсмену. Если наиболее высокую оценку выставило несколько судей, то из совокупности оценок удаляется
* только одна такая оценка; аналогично поступают и с наиболее низкими оценками. Известны оценки одного из
* участников соревнований. Определить балл спортсмена.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int number[10];
    FILE *file_input = fopen("task2.bin", "rb");
    for (int i = 0; i < 10; i++)
    {
        fwrite(&number[i], sizeof(int), 1, file_input);
    }
    rewind(file_input);
    for (int i = 0; i < 10; i++)
    {
        fread(&number[i], sizeof(int), 1, file_input);
        printf("%dth score is %d\n", i + 1, number[i]);
    }
    printf("\n--------------\n");
    int max = number[0], min = number[0];
    for (int i = 1; i < 10; i++)
    {
        if (number[i] > max)
            max = number[i];
        if (number[i] < min)
            min = number[i];
    }
    int countermax=0, countermin=0, k=0, size=10;
    while (k<size)
    {
        if (number[k] == max && countermax==0) {
            for (int c=k; c<9; c++) number[c]=number[c+1];
            size--;
            countermax++;
        }
        if (number[k] == min && countermin == 0){
           for (int c=k; c<9; c++) number[c]=number[c+1];
            size--;
            countermin++;
        } else k++;
    }
    float sum = 0;
    for(int i=0; i<size; i++){
        sum=sum+number[i];
    }
    printf("average: %.2f", sum/size);
    fclose(file_input);
}