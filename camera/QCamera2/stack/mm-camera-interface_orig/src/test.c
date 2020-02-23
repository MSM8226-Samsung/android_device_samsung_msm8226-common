#include <stdio.h>
#include <stdint.h>

typedef struct {
	int h;
	int w;
	int y;
	int x;
} test;

typedef struct {
	int something;
	uint8_t something_smaller;
	char a;
} test_one;

typedef struct {
	uint32_t test;
	union {
		test my_test;
		test_one one;
	};
} my_struct;

int main() {
	printf("sizeof is %lu ", sizeof(my_struct));
}
