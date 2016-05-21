#include <stdio.h>

struct Pepe {
	/* Struct fields */
	int x;
	int y;
	int z;
};

struct Juan {
	/* Struct fields */
	int a;
	Pepe &pp;

	/* Initialize struct objects */
	Juan(Pepe &pepeReference) : pp(pepeReference) {}
};

int main(void) {
	Pepe pepeObject;
	Juan *juanPointer = new Juan(pepeObject);

	printf("The size of the Pepe structure is: %d\n", sizeof(pepeObject));
	printf("The size of the Juan structure is: %d\n", sizeof(*juanPointer));

	return 0;
}

/*										PREGUNTA
¿Es válida la siguiente afirmación: “​sizeof(Juan) == sizeof(Pepe) + sizeof(int)”?
*/