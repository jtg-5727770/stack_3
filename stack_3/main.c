#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;
typedef struct {
    element* data; // data�� �����ͷ� ���ǵȴ�. 
    int capacity; // ���� ũ��
    int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s) {
    s->top = -1;
    s->capacity = 1;
    s->data = (element*)malloc(s->capacity * sizeof(element));
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s) {
    return (s->top == -1);
}

// ��ȭ ���� ���� �Լ�
int is_full(StackType* s) {
    return (s->top == (s->capacity - 1));
}

// ���� �Լ�
void push(StackType* s, element item)
{
    if (is_full(s)) {
        s->capacity *= 2;
        element* temp = (element*)realloc(s->data, s->capacity * sizeof(element));
        if (temp == NULL) {
            fprintf(stderr, "�޸� �Ҵ� ����");
            return;
        }
        s->data = temp;
    }
    s->data[++(s->top)] = item;
}

// ���� �Լ�
element pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "���� ���� ����");
        return 0;
    }
    else return s->data[(s->top)--];
}
element peek(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
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
