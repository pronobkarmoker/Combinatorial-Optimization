#include <stdio.h>

void sort(int *start, int *finish, int n);
void findOptimalActivities(int *act, int *start, int *finish, int n, int currentIndex, int *selected, int selectedCount, int *maxCount);

int main()
{
    int n;
    printf("Enter total activity:");
    scanf("%d", &n);

    int act[n], start[n], finish[n];

    FILE *fp;
    fp = fopen("activitySelection.txt", "r");

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d %d", &start[i], &finish[i]);
    }
    fclose(fp);

    sort(start, finish, n);

    int selected[n];
    for (int i = 0; i < n; i++)
        selected[i] = 0;

    int maxCount = 0;

    printf("All possible optimal solutions for activity selection:\n");
    findOptimalActivities(act, start, finish, n, 0, selected, 0, &maxCount);

    return 0;
}

void sort(int *start, int *finish, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (finish[i] > finish[j])
            {
                temp = finish[i];
                finish[i] = finish[j];
                finish[j] = temp;

                temp = start[i];
                start[i] = start[j];
                start[j] = temp;
            }
        }
    }
}

void printActivities(int *act, int n)
{
    printf("Optimal activity number: %d\n", n);
    printf("Activity number: ");
    for (int i = 0; i < n; i++)
    {
        if (act[i] == 1)
        {
            printf("%d ", i + 1);
        }
    }
    printf("\n\n");
}

void findOptimalActivities(int *act, int *start, int *finish, int n, int currentIndex, int *selected, int selectedCount, int *maxCount)
{
    if (currentIndex == n)
    {
        // Base case: All activities have been considered
        if (selectedCount > *maxCount)
        {
            // If we find a new maximum, reset the result and update the maxCount
            *maxCount = selectedCount;
            for (int i = 0; i < n; i++)
            {
                act[i] = selected[i];
            }
        }
        else if (selectedCount == *maxCount)
        {
            // If we find another optimal solution with the same count, print it
            printActivities(selected, selectedCount);
        }
        return;
    }

    // Include the current activity and recursively find the next activities
    selected[currentIndex] = 1;
    findOptimalActivities(act, start, finish, n, currentIndex + 1, selected, selectedCount + 1, maxCount);

    // Exclude the current activity and recursively find the next activities
    selected[currentIndex] = 0;
    findOptimalActivities(act, start, finish, n, currentIndex + 1, selected, selectedCount, maxCount);
}