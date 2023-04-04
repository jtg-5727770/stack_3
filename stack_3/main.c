#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;
typedef struct {
    element* data; // data은 포인터로 정의된다. 
    int capacity; // 현재 크기
    int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s) {
    s->top = -1;
    s->capacity = 1;
    s->data = (element*)malloc(s->capacity * sizeof(element));
}

// 공백 상태 검출 함수
int is_empty(StackType* s) {
    return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType* s) {
    return (s->top == (s->capacity - 1));
}

// 삽입 함수
void push(StackType* s, element item)
{
    if (is_full(s)) {
        s->capacity *= 2;
        element* temp = (element*)realloc(s->data, s->capacity * sizeof(element));
        if (temp == NULL) {
            fprintf(stderr, "메모리 할당 에러");
            return;
        }
        s->data = temp;
    }
    s->data[++(s->top)] = item;
}

// 삭제 함수
element pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러");
        return 0;
    }
    else return s->data[(s->top)--];
}
element peek(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        return 0;
    }
    else return s->data[(s->top)];
}

int main(void)
{
    StackType s;
    srand((unsigned int)time(NULL));
    init_stack(&s);
    for (int i = 1; i <= 30; i++) {
        int rand_num = rand() % 100 + 1;

        if (rand_num % 2 == 0) {
            push(&s, rand_num);
            printf("push %d\n", rand_num);
        }
        else
            printf("pop %d\n", pop(&s));
    }
    free(s.data);
    system("pause");
    return 0;
}
