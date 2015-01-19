#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORD 16
#define LEN 50

void tokenize(char *sentence);
void addDictionary(char *word);
int indexDictionary(char *word);
void shiftDictionary(int index, int places);
void printDictionary();
char *stringToLwr(char *str);

struct {
    char string[WORD];
    int counter;
} dictionary[LEN];

int main() {
    int sentenceNum, i;
    char sentence[LEN + 1];

    //initialization
    for (i = 0; i < LEN; i++) {
        dictionary[i].counter = 0;
    }

    //input
    printf("How many sentences you want to enter [1-5]?\n");
    scanf("%d", &sentenceNum);
    if (sentenceNum > 5 || sentenceNum < 1) {
        printf("ERROR: can read 1 to 5 sentences\n");
        exit(1);
    }

    gets(sentence);
    for (i = 0; i < sentenceNum; ++i) {
        printf("Sentence %d:\n", i + 1);
        gets(sentence);
        tokenize(sentence);
    }

    //output
    printf("Vocabulary:\n");
    printDictionary();

    return 0;
}

/**
* breaks sentence into words and add each one to the dictionary
*/
void tokenize(char *sentence) {
    char *word;

    word = stringToLwr(strtok(sentence, " 0123456789"));
    while (word) { //while word != NULL
        addDictionary(word);
        word = stringToLwr(strtok(NULL, " 0123456789"));
    }
}

/**
* handles adding words to dictionary
* if word is already in dictionary - adding 1 to its counter
* if word is not in dictionary - add it to dictionary and set counter to 1 (shifting other entries as needed)
*/
void addDictionary(char *word) {
    if (word == NULL) {
        return;
    }

    int i;

    if ((i = indexDictionary(word)) != -1) {
        dictionary[i].counter++;
        return;
    }

    for (i = 0; i < LEN; i++) {
        if (dictionary[i].counter == 0) { //if cell is empty
            strcpy(dictionary[i].string, word);
            dictionary[i].counter++;
            return;
        }
        if (strcmp(word, dictionary[i].string) < 0) {
            shiftDictionary(i, 1);
            strcpy(dictionary[i].string, word);
            dictionary[i].counter = 1;
            return;
        }
    }
    printf("ERROR: Full dictionary\n");
    exit(1);
}

/**
* returns index of word in dictionary.
* if word isn't in dictionary - returns -1
*/
int indexDictionary(char *word) {
    int i;
    for (i = 0; i < LEN; i++) {
        if (strcmp(word, dictionary[i].string) == 0) {
            return i;
        }
    }
    return -1;
}

/**
* shift dictionary down from index a given number of places
*/
void shiftDictionary(int index, int places) {
    if (dictionary[LEN - places].counter) {
        printf("ERROR: Full dictionary - can't shift");
        exit(1);
    }

    int i;
    for (i = LEN - places - 1; i >= index; i--) {
        strcpy(dictionary[i + places].string, dictionary[i].string);
        dictionary[i + places].counter = dictionary[i].counter;
    }
}

/**
* print dictionary - words and counters
*/
void printDictionary() {
    int i;
    for (i = 0; i < LEN && dictionary[i].counter; i++) {
        printf("%s %d\n", dictionary[i].string, dictionary[i].counter);
    }
}

char *stringToLwr(char *str) {
    if (str == NULL)
        return str;
    int i, len = strlen(str);
    for (i = 0; i < len; i++) {
        str[i] += (str[i] > 64 && str[i] < 91) ? 32 : 0;
    }

    return str;
}