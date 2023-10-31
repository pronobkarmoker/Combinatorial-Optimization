#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    double x, y;
} Point;

// Helper function to calculate the polar angle of a point with respect to the reference point
double polarAngle(Point reference, Point p)
{
    return atan2(p.y - reference.y, p.x - reference.x);
}

// Helper function to compare points by their polar angles
int comparePoints(const void *a, const void *b)
{
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    double angle1 = polarAngle(p1[0], *p1);
    double angle2 = polarAngle(p1[0], *p2);
    if (angle1 < angle2)
        return -1;
    if (angle1 > angle2)
        return 1;
    // If two points have the same angle, the one closer to the reference point comes first
    double dist1 = (p1[0].x - p1->x) * (p1[0].x - p1->x) + (p1[0].y - p1->y) * (p1[0].y - p1->y);
    double dist2 = (p1[0].x - p2->x) * (p1[0].x - p2->x) + (p1[0].y - p2->y) * (p1[0].y - p2->y);
    if (dist1 < dist2)
        return -1;
    if (dist1 > dist2)
        return 1;
    return 0;
}

// Function to compute the convex hull using Graham's Scan algorithm
void convexHull(Point *points, int n)
{
    if (n < 3)
    {
        printf("Convex hull not possible with less than 3 points.\n");
        return;
    }

    // Find the reference point (lowest y, leftmost if tied)
    int refIdx = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].y < points[refIdx].y || (points[i].y == points[refIdx].y && points[i].x < points[refIdx].x))
        {
            refIdx = i;
        }
    }

    // Swap the reference point with the first point
    Point temp = points[0];
    points[0] = points[refIdx];
    points[refIdx] = temp;

    // Sort the remaining points by polar angle
    qsort(&points[1], n - 1, sizeof(Point), comparePoints);

    // Initialize the convex hull with the first two points
    Point hull[n];
    int hullSize = 2;
    hull[0] = points[0];
    hull[1] = points[1];

    // Compute the convex hull
    for (int i = 2; i < n; i++)
    {
        while (hullSize > 1 && polarAngle(hull[hullSize - 2], hull[hullSize - 1]) >= polarAngle(hull[hullSize - 2], points[i]))
        {
            hullSize--;
        }
        hull[hullSize++] = points[i];
    }

    // Print the convex hull
    printf("Convex Hull Points:\n");
    for (int i = 0; i < hullSize; i++)
    {
        printf("(%f, %f)\n", hull[i].x, hull[i].y);
    }
}

int main()
{
    Point points[] = {
        {0, 3},
        {1, 1},
        {2, 2},
        {4, 4},
        {0, 0},
        {1, 2},
        {3, 1},
        {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);

    convexHull(points, n);

    return 0;
}
