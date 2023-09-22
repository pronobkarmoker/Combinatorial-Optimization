#include <stdio.h>

void knapsack(float *weight, float *benefit, float *valuePerUnit, int item, int capacity);
void sort(float *weight, float *benefit, float *valuePerUnit, int item);

int main(int argc, char *argv[])
{

    int capacity, item;

    freopen("knapsackinput.txt", "r", stdin);

    // printf("Enter number of items:");
    scanf("%d", &item);
    // printf("Enter capacity of knapsack:");
    scanf("%d", &capacity);
    float weight[item], benefit[item], valuePerUnit[item];

    // printf("Enter weights and benefits:\n");
    for (int i = 0; i < item; i++)
    {
        scanf("%f %f", &weight[i], &benefit[i]);
    }

    for (int i = 0; i < item; i++)
    {
        valuePerUnit[i] = benefit[i] / weight[i];
    }
    printf("\n");
    sort(weight, benefit, valuePerUnit, item);
    knapsack(weight, benefit, valuePerUnit, item, capacity);

    return 0;
}
void sort(float *weight, float *benefit, float *valuePerUnit, int item)
{
    float temp;
    for (int i = 0; i < item; i++)
    {
        for (int j = i + 1; j < item; j++)
        {
            if (valuePerUnit[i] < valuePerUnit[j])
            {
                temp = valuePerUnit[i];
                valuePerUnit[i] = valuePerUnit[j];
                valuePerUnit[j] = temp;

                temp = benefit[i];
                benefit[i] = benefit[j];
                benefit[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
            }
        }
    }
}
void knapsack(float *weight, float *benefit, float *valuePerUnit, int item, int capacity)
{
    float x[item], total_benefit = 0;
    int i;
    for (int i = 0; i < item; i++)
    {
        x[i] = 0.0;
    }
    for (i = 0; i < item; i++)
    {
        if (weight[i] > capacity)
        {
            break;
        }
        else
        {
            x[i] = 1.0;
            // total_benefit+=benefit[i];
            capacity -= weight[i];
        }
    }
    if (i < item)
    {
        x[i] = capacity / weight[i];
        // total_benefit+=x[i]*benefit[i];
    }

    for (int i = 0; i < item; i++)
    {
        total_benefit += x[i] * benefit[i];
    }

    printf("Item taken:\n");
    for (int i = 0; i < item; i++)
    {
        printf("%.0f ml from %.0f ml item\n", x[i] * weight[i], weight[i]);
    }

    printf("\n");
    printf("Maximum benefit: $%.2f\n", total_benefit);
}