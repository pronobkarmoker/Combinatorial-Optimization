#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    double x, y;
} Point;

// Function to calculate the square of the Euclidean distance between two points
double distanceSquare(Point p1, Point p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

// Function to compare points for sorting based on polar angle with a reference point
int comparePoints(const void *a, const void *b)
{
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    double angle1 = atan2(p1->y, p1->x);
    double angle2 = atan2(p2->y, p2->x);

    if (angle1 < angle2)
        return -1;
    if (angle1 > angle2)
        return 1;

    // If angles are the same, put the closest point first
    double dist1 = p1->x * p1->x + p1->y * p1->y;
    double dist2 = p2->x * p2->x + p2->y * p2->y;

    if (dist1 < dist2)
        return -1;
    if (dist1 > dist2)
        return 1;

    return 0;
}

// Function to compute the convex hull using the Graham Scan algorithm
void convexHull(Point *points, int n)
{
    if (n < 3)
    {
        printf("Convex hull not possible with less than 3 points.\n");
        return;
    }

    // Find the point with the lowest y-coordinate (and the leftmost if tied)
    int anchorIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (points[i].y < points[anchorIndex].y || (points[i].y == points[anchorIndex].y && points[i].x < points[anchorIndex].x))
        {
            anchorIndex = i;
        }
    }

    // Swap the anchor point with the first point
    Point temp = points[0];
    points[0] = points[anchorIndex];
    points[anchorIndex] = temp;

    // Sort the remaining points by polar angle with respect to the anchor point
    qsort(&points[1], n - 1, sizeof(Point), comparePoints);

    // Initialize the convex hull with the first two points
    Point *hull = (Point *)malloc(n * sizeof(Point));
    int hullSize = 0;
    hull[hullSize++] = points[0];
    hull[hullSize++] = points[1];

    // Process the remaining points to compute the convex hull
    for (int i = 2; i < n; i++)
    {
        while (hullSize > 1 && ((points[i].x - hull[hullSize - 1].x) * (hull[hullSize - 1].y - hull[hullSize - 2].y) -
                                (points[i].y - hull[hullSize - 1].y) * (hull[hullSize - 1].x - hull[hullSize - 2].x)) <= 0)
        {
            hullSize--;
        }
        hull[hullSize++] = points[i];
    }

    // Print the convex hull points
    printf("Convex Hull Points:\n");
    for (int i = 0; i < hullSize; i++)
    {
        printf("(%f, %f)\n", hull[i].x, hull[i].y);
    }

    free(hull);
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
