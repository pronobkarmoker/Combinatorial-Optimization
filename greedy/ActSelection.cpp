#include <bits/stdc++.h>

int numOFjob;

struct job
{
    char jobID[20];
    int start, finish;
    int comp;
} jobs[100];

void readInput();
int compare(const void *a, const void *b);
void recurse_act(int i);

int main(int argc, char *argv[])
{
    freopen("actSelection.txt", "r", stdin);
    readInput();

    qsort(jobs, numOFjob, sizeof(struct job), compare);

    // for(int i=0;i<numOFjob;i++){
    //     for(int j=i+1;j<numOFjob;j++){
    //         if(jobs[j].start<=jobs[i].finish && jobs[i].comp==1) jobs[j].comp=0;
    //     }
    // }
    recurse_act(0);
    for (int i = 0; i < numOFjob; i++)
    {
        if (jobs[i].comp == 1)
            printf("%s  %d  %d\n", jobs[i].jobID, jobs[i].start, jobs[i].finish);
    }
    printf("\n");

    return 0;
}
void readInput()
{

    scanf("%d", &numOFjob);

    for (int i = 0; i < numOFjob; i++)
    {
        scanf("%s %d %d", jobs[i].jobID, &jobs[i].start, &jobs[i].finish);
        jobs[i].comp = 1;
    }
}
int compare(const void *a, const void *b)
{
    // Convert void pointers to job pointers
    const struct job *jobA = (const struct job *)a;
    const struct job *jobB = (const struct job *)b;

    // Compare based on finish times
    return jobA->finish - jobB->finish;
}
void recurse_act(int i)
{
    int m = i + 1;
    while (m <= numOFjob && jobs[m].start < jobs[i].finish)
    {
        jobs[m].comp = 0;
        m++;
    }
    if (m <= numOFjob)
        recurse_act(m);
}