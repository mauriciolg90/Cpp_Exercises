#include <stdio.h>

/* Function prototype */
void increment(int &);

int main(void) {
	int i = 2;

	increment(i);
	printf("%d\n", i);

	return 0;
}

/** @brief Receives an integer and increments it on the same parameter.
 *
 *  @param varToIncrement Reference to the variable that wants to increase.
 *  @return void Does not return any value.
 */
void increment(int &varToIncrement) {
	++varToIncrement;
}