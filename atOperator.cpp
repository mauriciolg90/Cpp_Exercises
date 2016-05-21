#include <stdio.h>
#include <stdlib.h>

/* Macro */
#define declare_at(dataType, varName, destinationAddr) *(dataType *)destinationAddr = varName

int main(void) {
	unsigned short myVar = 0xffff;
	void *myAddr = malloc(sizeof(void *));
	//void *myAddr = (void *)0x97d8008;

	printf("Value %d in the address %p\n", *(unsigned short *)myAddr, myAddr);
	declare_at(unsigned short, myVar, myAddr);
	printf("Value %d in the address %p\n", *(unsigned short *)myAddr, myAddr);

	return 0;
}