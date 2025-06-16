#define _CRT_SECURE_NO_WARNINGS

#include "funkcije.h"
#include <stdio.h>
#include <string.h>

int main() {
    printf("%s", pocetniTekst);
    static int izbor;
    char imeIgraca[100];
    int rezultat = 0;

    if (zauzmiMemorijuPitanja() != 0 || zauzmiMemorijuIgraca() != 0) {
        printf("Neuspjesno zauzimanje memorije\n");
        return 1;
    }

    while (1) {
    a:
        printf("\n-----LOVAC-----\n");
        printf("1. IGRAJ\n");
        printf("2. DODAJ IGRACA\n");
        printf("3. IZBRISI IGRACA\n");
        printf("4. ISPIS IGRACA\n");
        printf("5. IZLAZ\n");
        printf("Unesi svoj izbor: ");
        //14
        do {
            scanf("%d", &izbor);
           
            printf("%d\n", izbor);
            if (izbor < 1 || izbor >  5) {
                printf("Neispravan unos. Ponovno unesite izbor: ");
                isprazniOdabir();
                while (getchar() != '\n');
            }
        } while (izbor < 1 || izbor > 5);

        switch (izbor) {
        case Igraj:
            printf("Unesi ime igraca: ");
            scanf("%s", imeIgraca);
            if (!pronadiIgraca(imeIgraca, &rezultat)) {
                printf("Igrac ne postoji. Zelis li ga kreirati? (da/ne): ");
                char response[10];
                scanf("%9s", response);
                if (strcmp(response, "da") == 0) {
                    dodajIgraca(imeIgraca);
                }
                else {
                    break;
                }
            }
            pokreniIgru(&rezultat);
            azurirajRezultat(imeIgraca, rezultat);
            break;
        case DodajIgraca:
            printf("Unesi ime igraca: ");
            scanf("%s", imeIgraca);
            dodajIgraca(imeIgraca);
            break;
        case IzbrisiIgraca:
            printf("Unesi ime igraca za obrisati: ");
            scanf("%s", imeIgraca);
            izbrisiIgraca(imeIgraca);
            break;
        case IspisIgraca:
            PRINT();
            citajIgrace();
            sortirajIgrace();
            ispisSortiranihIgraca();
            break;;
        case Izlaz:
            printf("Izlazenje iz programa.\n");
            izlazIzPrograma();
            goto a;
        default:
            printf("Neispravan unos. Pokusaj ponovno.\n");
        }
        isprazniOdabir();
    }

    return 0;
}

