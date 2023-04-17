#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 10
int return_count = 0;



typedef struct {
    short r;
    short c;
} element;

typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;

void init(StackType* s) {
    s->top = -1;
}

int is_empty(StackType* s) {
    return s->top == -1;
}

int is_full(StackType* s) {
    return s->top == MAX_STACK_SIZE - 1;
}

void push(StackType* s, element item) {
    if (is_full(s)) {
        exit(1);
    }
    s->stack[++(s->top)] = item;
}

element pop(StackType* s) {
    if (is_empty(s)) {
        exit(1);
    }
    return s->stack[(s->top)--];
}

element peek(StackType* s) {
    if (is_empty(s)) {
        exit(1);
    }
    return s->stack[s->top];
}

element here = { 1,0 };
element entry = { 1,0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {

        {'1','1','1','1','1','1','1','1','1','1'},
        {'e','1','0','1','0','0','0','1','0','1'},
        {'0','0','0','1','0','0','0','1','0','1'},
        {'0','1','0','0','0','1','1','0','0','1'},
        {'1','0','0','0','1','0','0','0','0','1'},
        {'1','0','0','0','1','0','0','0','0','1'},
        {'1','0','0','0','0','0','1','0','1','1'},
        {'1','0','1','1','1','0','1','1','0','1'},
        {'1','1','0','0','0','0','0','0','0','x'},
        {'1','1','1','1','1','1','1','1','1','1'}

};

void push_loc(StackType* s, int r, int c) {
    
    if (r < 0 || c < 0 || r > MAZE_SIZE || c > MAZE_SIZE) return;
   
    if (maze[r][c] != '1' && maze[r][c] != '.') {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
    if (maze[r][c] =='1') {
            return_count++;

        }
    
}

void print() {
    int i, j;
    for (i = 0; i < MAZE_SIZE; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int r, c;
    StackType s;
    
    init(&s);
    here = entry; 
    while (maze[here.r][here.c] != 'x') {
        r = here.r;
        c = here.c;
        
        maze[r][c] = '.';
         
        print();
        
        
        printf("------------\n");
        

        
        push_loc(&s, r - 1, c); // north
        push_loc(&s, r + 1, c); // south
        push_loc(&s, r, c - 1); // west
        push_loc(&s, r, c + 1); // east
        
        
        
        if (is_empty(&s)) {
            printf("½ÇÆÐ\n");
            exit(1);
        }
        else {
            here = pop(&s);
        }
        
    }
    printf("Success!\n");
    printf("Back count: %d", return_count);
    return 0;
}
