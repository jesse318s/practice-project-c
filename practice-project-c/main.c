#include <stdio.h>
#include <stdlib.h>
#include "c-review.h"

int main(void) {
	// Test the factorial function
	uint32_t result;

	if (factorial(5, &result) == RET_SUCCESS) {
		printf("5! = %u\n", result);
	}
	else {
		printf("Factorial calculation failed.\n");
	}

	// Test the vec3_init function
	vec3_t myVec;

	if (vec3_init(&myVec, 1.0f, 2.0f, 3.0f) == RET_SUCCESS) {
		printf("Vector initialized: (%f, %f, %f)\n", myVec.x, myVec.y, myVec.z);
	}
	else {
		printf("Vector initialization failed.\n");
	}

	// Test the vec3_dot function
	vec3_t v1 = { 1.0f, 2.0f, 3.0f };
	vec3_t v2 = { 4.0f, 5.0f, 6.0f };
	float dotProduct;

	if (vec3_dot(v1, v2, &dotProduct) == RET_SUCCESS) {
		printf("Dot product: %f\n", dotProduct);
	}
	else {
		printf("Dot product calculation failed.\n");
	}

	// Test the bit_set function
	uint16_t bitVectorSet = 0b1010;

	if (bit_set(&bitVectorSet, 1) == RET_SUCCESS) {
		printf("Bit set: %u\n", bitVectorSet);
	}
	else {
		printf("Bit set operation failed.\n");
	}

	// Test the bit_clear function
	uint16_t bitVectorClear = 0b1011;

	if (bit_clear(&bitVectorClear, 0) == RET_SUCCESS) {
		printf("Bit cleared: %u\n", bitVectorClear);
	}
	else {
		printf("Bit clear operation failed.\n");
	}

	// Test the bit_toggle function
	uint16_t bitVectorToggle = 0b1010;

	if (bit_toggle(&bitVectorToggle, 2) == RET_SUCCESS) {
		printf("Bit toggled: %u\n", bitVectorToggle);
	}
	else {
		printf("Bit toggle operation failed.\n");
	}

	// Test the counter_init function
	if (counter_init(10) == RET_SUCCESS) {
		printf("Counter initialized to 10.\n");
	}
	else {
		printf("Counter initialization failed.\n");
	}

	// Test the counter_set function
	if (counter_set(20) == RET_SUCCESS) {
		printf("Counter set to 20.\n");
	}
	else {
		printf("Counter set operation failed.\n");
	}

	// Test the counter_dec function
	if (counter_dec() == RET_SUCCESS) {
		printf("Counter decremented.\n");
	}
	else {
		printf("Counter decrement operation failed.\n");
	}

	// Test the counter_get function
	uint32_t counterValue;

	if (counter_get(&counterValue) == RET_SUCCESS) {
		printf("Counter value: %u\n", counterValue);
	}
	else {
		printf("Counter get operation failed.\n");
	}

	return 0;
}
