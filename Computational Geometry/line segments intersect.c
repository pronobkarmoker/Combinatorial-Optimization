#include <stdio.h>

typedef struct
{
    double x, y;
} Point;

// Function to check if two line segments given by points p1, q1, and p2, q2 intersect
int doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Check bounding box intersection
    if (q1.x < p2.x || p1.x > q2.x || q1.y < p2.y || p1.y > q2.y)
        return 0; // Bounding boxes do not intersect, so segments cannot intersect

    // Calculate cross products
    double cross1 = (q2.x - p1.x) * (q1.y - p1.y) - (q1.x - p1.x) * (q2.y - p1.y);
    double cross2 = (p2.x - p1.x) * (q1.y - p1.y) - (q1.x - p1.x) * (p2.y - p1.y);
    double cross3 = (q1.x - p2.x) * (q2.y - p2.y) - (q2.x - p2.x) * (q1.y - p2.y);
    double cross4 = (p1.x - p2.x) * (q2.y - p2.y) - (q2.x - p2.x) * (p1.y - p2.y);

    // Check if cross products have different signs or are both zero
    if ((cross1 * cross2 < 0) && (cross3 * cross4 < 0))
        return 1; // Segments intersect

    return 0; // Segments do not intersect
}

int main()
{
    Point p1 = {1, 1};
    Point q1 = {4, 4};
    Point p2 = {2, 2};
    Point q2 = {5, 5};

    if (doIntersect(p1, q1, p2, q2))
    {
        printf("Segments intersect.\n");
    }
    else
    {
        printf("Segments do not intersect.\n");
    }

    return 0;
}
