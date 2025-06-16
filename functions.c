#define _CRT_SECURE_NO_WARNINGS

#include "funkcije.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char pocetniTekst[] = "Ulaz u program.";

Pitanja* pitanje;
Igraci* igrac;
int brojIgraca = 0;

void isprazniOdabir() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
//16,17
int zauzmiMemorijuPitanja() {
    pitanje = (Pitanja*)calloc(MAX_PITANJA, sizeof(Pitanja));
    if (pitanje == NULL) {
        perror("memorija pitanja"); //22
        return 1;
    }
    return 0;
}
//18
void oslobodiMemorijuPitanja() {
    free(pitanje);
}

int zauzmiMemorijuIgraca() {
    igrac = (Igraci*)calloc(MAX_IGRACA, sizeof(Igraci));
    if (igrac == NULL) {
        perror("memorija igraca");
        return 1;
    }
    return 0;
}

void oslobodiMemorijuIgraca() {
    free(igrac);
}

void dodajIgraca(const char* imeIgraca) {
    FILE* file = fopen("igraci.txt", "a");
    if (file == NULL) {
        perror("dodajIgraca");
        return;
    }

    fprintf(file, "%s 0\n", imeIgraca); // Initialize with a score of 0
    fclose(file);
    printf("Igrac uspjesno dodan.\n");
}

void izbrisiIgraca(const char* imeIgraca) {
    FILE* tempfile = fopen("temp.txt", "w");
    FILE* file = fopen("igraci.txt", "r");
    if (file == NULL || tempfile == NULL) {
        perror("izbrisiIgraca");
        return;
    }

    char linija[100];
    int pronaden = 0;

    while (fgets(linija, sizeof(linija), file)) {
        linija[strcspn(linija, "\n")] = '\0';
        char postojeciIgrac[100];
        int rezultat;
        sscanf(linija, "%s %d", postojeciIgrac, &rezultat);

        if (strcmp(postojeciIgrac, imeIgraca) == 0) {
            pronaden = 1;
        }
        else {
            fprintf(tempfile, "%s %d\n", postojeciIgrac, rezultat);
        }
    }
    fclose(file);
    fclose(tempfile);

    if (!pronaden) {
        printf("Igrac nije pronaden.\n");
        remove("temp.txt");
    }
    else {
        remove("players.txt");
        rename("temp.txt", "players.txt");
        printf("Igrac uspjesno izbrisan.\n");
    }
}

void inicijalizacijaPitanja() {

    strcpy(pitanje[0].pitanje, "Koji je glavni grad Francuske?");
    strcpy(pitanje[0].prviOdgovor, "London");
    strcpy(pitanje[0].drugiOdgovor, "Pariz");
    strcpy(pitanje[0].treciOdgovor, "Berlin");
    strcpy(pitanje[0].cetvrtiOdgovor, "Rim");
    pitanje[0].tocanOdgovor = 'B';

    strcpy(pitanje[1].pitanje, "Koji je najveci ocean na svijetu?");
    strcpy(pitanje[1].prviOdgovor, "Pacifik");
    strcpy(pitanje[1].drugiOdgovor, "Atlantski");
    strcpy(pitanje[1].treciOdgovor, "Indijski");
    strcpy(pitanje[1].cetvrtiOdgovor, "Juzni");
    pitanje[1].tocanOdgovor = 'A';

    // Add more questions as needed
    strcpy(pitanje[2].pitanje, "Koliko kontinenata postoji na Zemlji?");
    strcpy(pitanje[2].prviOdgovor, "6");
    strcpy(pitanje[2].drugiOdgovor, "5");
    strcpy(pitanje[2].treciOdgovor, "7");
    strcpy(pitanje[2].cetvrtiOdgovor, "8");
    pitanje[2].tocanOdgovor = 'C';

    strcpy(pitanje[3].pitanje, "Koja je najmanja država na svijetu?");
    strcpy(pitanje[3].prviOdgovor, "Vatikan");
    strcpy(pitanje[3].drugiOdgovor, "Monako");
    strcpy(pitanje[3].treciOdgovor, "San Marino");
    strcpy(pitanje[3].cetvrtiOdgovor, "Lihtenštajn");
    pitanje[3].tocanOdgovor = 'A';

    strcpy(pitanje[4].pitanje, "Koji je najduži riječni sistem na svijetu?");
    strcpy(pitanje[4].prviOdgovor, "Misisipi");
    strcpy(pitanje[4].drugiOdgovor, "Amazon");
    strcpy(pitanje[4].treciOdgovor, "Jangce");
    strcpy(pitanje[4].cetvrtiOdgovor, "Nil");
    pitanje[4].tocanOdgovor = 'D';

    strcpy(pitanje[5].pitanje, "Koji je najveći planet u našem Sunčevom sustavu?");
    strcpy(pitanje[5].prviOdgovor, "Mars");
    strcpy(pitanje[5].drugiOdgovor, "Saturn");
    strcpy(pitanje[5].treciOdgovor, "Zemlja");
    strcpy(pitanje[5].cetvrtiOdgovor, "Jupiter");
    pitanje[5].tocanOdgovor = 'D';

    strcpy(pitanje[6].pitanje, "Koji je najviše planinski vrh na svijetu?");
    strcpy(pitanje[6].prviOdgovor, "Mount Everest");
    strcpy(pitanje[6].drugiOdgovor, "K2");
    strcpy(pitanje[6].treciOdgovor, "Kangchenjunga");
    strcpy(pitanje[6].cetvrtiOdgovor, "Lhotse");
    pitanje[6].tocanOdgovor = 'A';

    strcpy(pitanje[7].pitanje, "Koja je najduža rijeka u Europi?");
    strcpy(pitanje[7].prviOdgovor, "Dunav");
    strcpy(pitanje[7].drugiOdgovor, "Volga");
    strcpy(pitanje[7].treciOdgovor, "Rajna");
    strcpy(pitanje[7].cetvrtiOdgovor, "Seine");
    pitanje[7].tocanOdgovor = 'B';

    strcpy(pitanje[8].pitanje, "Koji je najveći otok na svijetu?");
    strcpy(pitanje[8].prviOdgovor, "Grenland");
    strcpy(pitanje[8].drugiOdgovor, "Novi Zeland");
    strcpy(pitanje[8].treciOdgovor, "Borneo");
    strcpy(pitanje[8].cetvrtiOdgovor, "Madagaskar");
    pitanje[8].tocanOdgovor = 'A';

    strcpy(pitanje[9].pitanje, "Koji je najviši vodopad na svijetu?");
    strcpy(pitanje[9].prviOdgovor, "Angelov vodopad");
    strcpy(pitanje[9].drugiOdgovor, "Niagara");
    strcpy(pitanje[9].treciOdgovor, "Victoria Falls");
    strcpy(pitanje[9].cetvrtiOdgovor, "Tugela Falls");
    pitanje[9].tocanOdgovor = 'A';

}

void postaviPitanje(int brojPitanja) {
    printf("\nPitanje %d: %s\n", brojPitanja + 1, pitanje[brojPitanja].pitanje);
    printf("A. %s\n", pitanje[brojPitanja].prviOdgovor);
    printf("B. %s\n", pitanje[brojPitanja].drugiOdgovor);
    printf("C. %s\n", pitanje[brojPitanja].treciOdgovor);
    printf("D. %s\n", pitanje[brojPitanja].cetvrtiOdgovor);
}

char izborIgraca() {
    char izbor;
    printf("Unesite odgovor (A/B/C/D): ");
    scanf(" %c", &izbor);
    return izbor;
}
//12
void pokreniIgru(int* rezultat) {
    inicijalizacijaPitanja();
    int trenutnoPitanje = 0;
    int osvojeno = 0;

    while (trenutnoPitanje < MAX_PITANJA) {
        postaviPitanje(trenutnoPitanje);
        char izbor = izborIgraca();

        if (izbor == pitanje[trenutnoPitanje].tocanOdgovor) {
            printf("Tocan odgovor!\n");
            osvojeno += 1000;
        }
        else {
            printf("Krivi odgovor!\n");
            printf("Osvojili ste %d eura!\n", osvojeno);
            break;
        }

        trenutnoPitanje++;
        if (trenutnoPitanje == 10) {
            printf("Pobjedio si.");
            break;
        }
    }

    *rezultat = osvojeno;
}
//24
int pronadiIgraca(const char* imeIgraca, int* rezultat) {
    FILE* file = fopen("igraci.txt", "r");
    if (file == NULL) {
        perror("pronadiIgraca");
        return 0;
    }

    char linija[100];
    while (fgets(linija, sizeof(linija), file)) {
        linija[strcspn(linija, "\n")] = '\0';
        char postojeciIgrac[100];
        int postojeciRezultat;
        sscanf(linija, "%s %d", postojeciIgrac, &postojeciRezultat);

        if (strcmp(postojeciIgrac, imeIgraca) == 0) {
            *rezultat = postojeciRezultat;
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void azurirajRezultat(const char* imeIgraca, int noviRezultat) {
    FILE* tempfile = fopen("temp.txt", "w");
    FILE* file = fopen("igraci.txt", "r");
    if (tempfile == NULL || file == NULL) {
        perror("azurirajRezultat");
        return;
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        char postojeciIgrac[100];
        int postojeciRezultat;
        sscanf(buffer, "%s %d", postojeciIgrac, &postojeciRezultat);

        if (strcmp(postojeciIgrac, imeIgraca) == 0) {
            fprintf(tempfile, "%s %d\n", imeIgraca, noviRezultat);
        }
        else {
            fprintf(tempfile, "%s %d\n", postojeciIgrac, postojeciRezultat);
        }
    }
    //21
    fclose(file);
    fclose(tempfile);
    remove("igraci.txt");
    rename("temp.txt", "igraci.txt");
}

void citajIgrace() {
    brojIgraca = 0; // Reset player count before reading
    FILE* file = fopen("igraci.txt", "r");
    if (file == NULL) {
        perror("citajIgrace");
        return;
    }

    while (fscanf(file, "%s %d", igrac[brojIgraca].imeIgraca, &igrac[brojIgraca].rezultat) != EOF) {
        brojIgraca++;
    }

    fclose(file);
}
//23
void sortirajIgrace() {
    for (int i = 0; i < brojIgraca - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < brojIgraca; j++) {
            if (igrac[j].rezultat > igrac[maxIndex].rezultat) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            Igraci temp = igrac[i];
            igrac[i] = igrac[maxIndex];
            igrac[maxIndex] = temp;
        }
    }
}


void ispisSortiranihIgraca() {
    printf("Igraci sortirani po rezultatu:\n");
    for (int i = 0; i < brojIgraca; i++) {
        printf("%s: %d\n", igrac[i].imeIgraca, igrac[i].rezultat);
    }
}

void izlazIzPrograma() {
    printf("Zelite li sigurno izaci(da/ne): ");
    char odabir[3];

    if (scanf("%2s", odabir) != 1) {
        printf("Neispravan unos!\n");
        return;
    }

    while (getchar() != '\n');

    if (strcmp(odabir, "da") == 0) {
        oslobodiMemorijuPitanja();
        oslobodiMemorijuIgraca();
        exit(0);
    }
    else if (strcmp(odabir, "ne") == 0) {
        return;
    }
    else {
        printf("Neispravan odgovor\n");
        izlazIzPrograma(); //25
    }
}
