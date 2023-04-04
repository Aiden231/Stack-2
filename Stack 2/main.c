#include <stdio.h>
#include <time.h>
#define MAX_STACK_SIZE 10

// 구조체 배열 사용
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

// 스택 초기화
void init_stack(StackType *s)
{
	s->top = -1;
}

// 공백 상태 검사
int is_empty(StackType *s)
{
	return (s->top == -1);
}

// 포화 상태 검사
int is_full(StackType* s)
{
	return(s->top == (MAX_STACK_SIZE - 1));
}

// 삽입함수
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		s->top++;
		s->data[s->top] = item;
		return;
	}
}

//삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		return;
	}
	else return s->data[(s->top--)];
}

int main()
{
	srand(time(NULL));

	StackType s;
	init_stack(&s);

	printf("구조체 배열\n");

	for (int i = 1; i <= 30; i++)
	{
		int rand_num = rand() % 100 + 1;

		if (rand_num % 2 == 0) {
			push(&s, rand_num);
			printf("[%d] Push %d\n", i , rand_num);
		}

		else if (rand_num % 2 == 1)
		{
			pop(&s);
			printf("[%d] Pop %d\n", i, rand_num);
		}
	}

	return 0;
}