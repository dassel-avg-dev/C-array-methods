#include <stdio.h>
#include <math.h>

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Line {
    Point beg;
    Point end;
} Line;

// Function to create a default point (0, 0)
Point createPoint() {
    Point p;
    p.x = 0;
    p.y = 0;
    return p;
}

// Function to create a point with given x and y
Point initPoint(int x, int y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

// Function to create a default line from (0,0) to (0,0)
Line createLine() {
    Line line;
    line.beg = createPoint();
    line.end = createPoint();
    return line;
}

// Function to create a line from two points
Line initLine(Point p1, Point p2) {
    Line line;
    line.beg = p1;
    line.end= p2;
    return line;
}

// Display a point
void displayPoint(Point p) {
    printf("(%d, %d) ", p.x, p.y);
}

// Display a line as two points
void displayLine(Line line1) {
    printf("[ ");
    displayPoint(line1.beg);
    displayPoint(line1.end);
    printf("]");
}

// Determine the type of line
int lineType(Line line) {
    int type;
    if(line.beg.x == line.end.x)
        type = 1;
    else if(line.beg.y == line.end.y)
        type=2;
    else
        type=3;
    return type;
}

int main() {
    Point a = initPoint(0, 0);
    Point b = initPoint(3, 3);
    Line l = initLine(a, b);

    displayLine(l);
    
    int type = lineType(l);
    switch(type) {
        case 1: printf("Line is vertical\n"); break;
        case 2: printf("Line is horizontal\n"); break;
        case 3: printf("Line is diagonal\n"); break;
        case 4: printf("Line is oblique\n"); break;
    }

    return 0;
}
