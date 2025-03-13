/*
 * Problem: so the problem was something along the lines of a plane flying and youre given two sets of coordinates, x and y
 * You can only move horizontal or vertical no diagonal, find the max points you can hit
 * I wanna say that the pairs go side by side so if you're given a pair with only 1 coordinate its not valid
 */

//Header Files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/* only used in string related operations */
typedef struct String string;
struct String
{
    char *str;
};

char *input(FILE *fp, int size, int has_space)
{
    int actual_size = 0;
    char *str = (char *)malloc(sizeof(char)*(size+actual_size));
    char ch;
    if(has_space == 1)
    {
        while(EOF != (ch=fgetc(fp)) && ch != '\n')
        {
            str[actual_size] = ch;
            actual_size++;
            if(actual_size >= size)
            {
                str = realloc(str,sizeof(char)*actual_size);
            }
        }
    }
    else
    {
        while(EOF != (ch=fgetc(fp)) && ch != '\n' && ch != ' ')
        {
            str[actual_size] = ch;
            actual_size++;
            if(actual_size >= size)
            {
                str = realloc(str,sizeof(char)*actual_size);
            }
        }
    }
    actual_size++;
    str = realloc(str,sizeof(char)*actual_size);
    str[actual_size-1] = '\0';
    return str;
}
/* only used in string related operations */

typedef struct array_single_int array_single_int;
struct array_single_int
{
	int *data;
	int size;
};


#define MAX_POINTS 700  

typedef struct {
    int x, y;
} Coordinate;

typedef struct {
    Coordinate queue[MAX_POINTS];
    int front, rear;
} Queue;

void enqueue(Queue *q, int x, int y) {
    q->queue[q->rear++] = (Coordinate){x, y};
}
Coordinate dequeue(Queue *q) {
    return q->queue[q->front++];
}
bool isEmpty(Queue *q) {
    return q->front == q->rear;
}


bool visited[MAX_POINTS][MAX_POINTS]; 


int bfs(Coordinate start, Coordinate *points, int size, bool horizontal) {
    Queue q = {0};
    enqueue(&q, start.x, start.y);
    visited[start.x][start.y] = true;

    int count = 0;
    while (!isEmpty(&q)) {
        Coordinate current = dequeue(&q);
        count++;

        
        for (int i = 0; i < size; i++) {
            if (horizontal && points[i].x == current.x && !visited[points[i].x][points[i].y]) {
                enqueue(&q, points[i].x, points[i].y);
                visited[points[i].x][points[i].y] = true;
            }
            if (!horizontal && points[i].y == current.y && !visited[points[i].x][points[i].y]) {
                enqueue(&q, points[i].x, points[i].y);
                visited[points[i].x][points[i].y] = true;
            }
        }
    }
    return count;
}


void funcDrop(array_single_int xCoordinate, array_single_int yCoordinate) {
    if (xCoordinate.size == 0 || yCoordinate.size == 0) {
        printf("-1\n");
        return;
    }

   
    Coordinate points[MAX_POINTS];
    for (int i = 0; i < xCoordinate.size; i++) {
        points[i] = (Coordinate){xCoordinate.data[i], yCoordinate.data[i]};
    }

    int maxCount = 0;


    for (int i = 0; i < MAX_POINTS; i++)
        for (int j = 0; j < MAX_POINTS; j++)
            visited[i][j] = false;

   
    for (int i = 0; i < xCoordinate.size; i++) {
        if (!visited[points[i].x][points[i].y]) {
            int horizontalCount = bfs(points[i], points, xCoordinate.size, true);
            int verticalCount = bfs(points[i], points, xCoordinate.size, false);
            maxCount = (horizontalCount > maxCount) ? horizontalCount : maxCount;
            maxCount = (verticalCount > maxCount) ? verticalCount : maxCount;
        }
    }

    printf("%d\n", maxCount);
}

int main()
{
    array_single_int xCoordinate;
	array_single_int yCoordinate;
	
    //input for xCoordinate
	scanf("%d", &xCoordinate.size);
	xCoordinate.data = (int *)malloc(sizeof(int) * xCoordinate.size);
	for ( int idx = 0; idx < xCoordinate.size; idx++ )
	{
	    scanf("%d", &xCoordinate.data[idx]);
	}
	
	//input for yCoordinate
	scanf("%d", &yCoordinate.size);
	yCoordinate.data = (int *)malloc(sizeof(int) * yCoordinate.size);
	for ( int idx = 0; idx < yCoordinate.size; idx++ )
	{
	    scanf("%d", &yCoordinate.data[idx]);
	}
	
	
    
	funcDrop(xCoordinate, yCoordinate);
    return 0;
}
