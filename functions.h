#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct {
	char name[8];
	int score;
}PLAYER;

typedef struct {
	char question[100];
	char correctOption[100];
	char wrongOption1[100];
	char wrongOption2[100];
	char wrongOption3[100];
	char corretAnswer;
}QUESTION;



int allocateQuestions();
int allocatePlayer();
void freeQuestions();
void freePlayer();


extern QUESTION* question;
extern PLAYER* player;


enum Opcije {
	Igraj = 1,
	DodajIgraca,
	IzbrisiIgraca,
	Izlaz
};


#endif 
