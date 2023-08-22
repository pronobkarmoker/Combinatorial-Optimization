#include <stdio.h>
#include <stdlib.h>

int num_job;

struct job
{
    char jobId[20];
    int starttime;
    int finishtime;
    int compatibility;
} job[100];

void readInput()
{
    scanf("%d", num_job);
    for (size_t i = 0; i < num_job; i++)
    {
        scanf("%d", job[i].starttime);
        scanf("%d", job[i].finishtime);
        scanf("%d", job[i].jobId);
        // scanf("%d",job[i].compatibility);
        job[i].compatibility = 1;
    }

    for (size_t i = 0; i < num_job; i++)
    {
        printf("%d ", job[i].starttime);
        printf("%d ", job[i].finishtime);
        printf("%d ", job[i].jobId);
        printf("%d ", job[i].compatibility);
        printf("\n");
    }
}

void sort()
{
    for (int i = 0; i < num_job; i++)
    {
        for (int j = 0; i < num_job; i++)
        {
            if (job[i].finishtime > job[j].finishtime)
            {
                struct temp = job[i];
                job[i] = temp;
                job[j] = temp;
            }
        }
    }
}

void iterative()
{
    int k = 0;
    for (int i = 0; i < num_job; i++)
    {
        if (job[i].compatibility != 0)
        {
            for (int j = i+1; i < num_job; j++)
            {
                if (job[j].starttime < job[i].finishtime)
                {
                    job[j].compatibility= 0;
                }
                
            }
            
            
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    readInput();

    for (int i = 0; i < count; i++)
    {
        /* code */
    }
    
    return 0;
}