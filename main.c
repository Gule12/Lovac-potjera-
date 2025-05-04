#define _CRT_SECURE_NO_WARNINGS

#include "functions.h"
#include <stdio.h>
int main() {
	printf("1. IGRAJ\n");
	printf("2. DODAJ IGRACA\n");
	printf("3. IZBRISI IGRACA\n");
	printf("4. IZLAZ\n");

	int choice;
	scanf("%d", &choice);


	switch (choice)
	{
	case Igraj:
		printf("Igram");
	case DodajIgraca:
		printf("Dodajem");
	case IzbrisiIgraca:
		printf("Brisem");
	case Izlaz:
		printf("Izlazim");
	default:
		printf("Nista od navedenog");
		break;
	}




	return 0;
	
}
