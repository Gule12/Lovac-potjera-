#include "functions.h"
#include <stdlib.h>

QUESTION* question;
PLAYER* player;

int allocateQuestions() {
	question = (QUESTION*)calloc(10, sizeof(QUESTION)); 

	if (question == NULL) {
		perror("allocateQuestion");
		return 1;
	}
	return 0;
}

int allocatePlayer() {
	 player = (PLAYER*)calloc(1, sizeof(PLAYER));

	if (player == NULL) {
		perror("allocatePlayer");
		return 1;
	}
	return 0;
}

void freeQuestions() {

	free(question);
}

void freePlayer() {
	free(player);
}
