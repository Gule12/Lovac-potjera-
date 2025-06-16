#define _CRT_SECURE_NO_WARNINGS

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_PITANJA 50
#define MAX_DUZINA_PITANJA 50
#define MAX_DUZINA_ODGOVORA 50
#define MAX_IGRACA 50
//9
#define PRINT() printf("\0");

typedef struct {
    char pitanje[MAX_DUZINA_PITANJA]; //15
    char prviOdgovor[MAX_DUZINA_ODGOVORA];
    char drugiOdgovor[MAX_DUZINA_ODGOVORA];
    char treciOdgovor[MAX_DUZINA_ODGOVORA];
    char cetvrtiOdgovor[MAX_DUZINA_ODGOVORA];
    char tocanOdgovor;
} Pitanja;

typedef struct {
    char imeIgraca[100];
    int rezultat;
} Igraci;

void isprazniOdabir();
int zauzmiMemorijuPitanja();
void oslobodiMemorijuPitanja();
int zauzmiMemorijuIgraca();
void oslobodiMemorijuIgraca();
void postaviPitanje(int brojPitanja);
char izborIgraca();
void pokreniIgru(int* rezultat);
void dodajIgraca(const char* imeIgraca);
void izbrisiIgraca(const char* imeIgraca);
int pronadiIgraca(const char* imeIgraca, int* rezultat);
void azurirajRezultat(const char* imeIgraca, int noviRezultat);
void citajIgrace();
void sortirajIgrace();
void ispisSortiranihIgraca();
void izlazIzPrograma();

extern Pitanja* pitanje;
extern Igraci* igrac;
extern int brojIgraca;

extern char pocetniTekst[];


enum Opcije {
    Igraj = 1,
    DodajIgraca,
    IzbrisiIgraca,
    IspisIgraca,
    Izlaz
};

#endif
