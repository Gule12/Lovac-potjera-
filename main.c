#include "functions.h"
#include <stdlib.h>

typedef struct person{
	char name[8];
	int age;
}PERSON;

int main(){

	PERSON* osoba = (PERSON*)malloc(sizeof(PERSON)*1);
	osoba->age = 20;
	printf("osoba ima godina : %d", osoba->age);
	


	return 0;
}