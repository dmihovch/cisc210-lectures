#include <stddef.h>
#include <stdio.h>

typedef struct grade_t { 
	int score; 
	char letter; 
} grade_t;

int main(void) {
	grade_t grades[] = {{94, 'A'}, {83, 'B'}, {62, 'D'}};
	grade_t *grade_pointer = grades;
	grade_t *grade_pointers[] = {&grades[2], &grades[0], &grades[1]};

	printf("sizeof(grade_t) = %zu bytes\n", sizeof(grade_t));
	printf("sizeof(grade_t *) = %zu bytes\n", sizeof(grade_t *));
	printf("grades = %p\n", (void *)grades);
	printf("grades+1: %p (%zu bytes)\n", (void *)(grades + 1), sizeof grades[0]);

	for (size_t i = 0; i < sizeof grades / sizeof grades[0]; i++) {
		printf("[%zu] score=%d letter=%c\n", i, grades[i].score, grades[i].letter);
		printf("(p + %zu)->score = %d\n", i, (grade_pointer + i)->score);
		printf("(*(p + %zu)).letter = %c\n", i, (*(grade_pointer + i)).letter);
	}

	grade_t *first_grade = grades;
	grade_t *third_grade = grades + 2;
	ptrdiff_t elements_apart = third_grade - first_grade;
	size_t bytes_apart = (size_t)elements_apart * sizeof *first_grade;
	printf("first=%p third=%p\n", (void *)first_grade, (void *)third_grade);
	printf("%td elements; %zu bytes apart\n", elements_apart, bytes_apart);

	printf("grade_pointers=%p\n", (void *)grade_pointers);
	printf("grade_pointers + 1 = %p\n", (void *)(grade_pointers + 1));
	for (size_t i = 0; i < sizeof grade_pointers / sizeof grade_pointers[0]; i++) {
		printf("%zu:%p %d\n", i, (void *)grade_pointers[i], grade_pointers[i]->score);
		printf("(*(ptr + %zu))->letter = %c\n", i, (*(grade_pointers + i))->letter);
	}

	return 0;
}
