#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    
    char choice[10];  
    char input;
    
    char options[][10] = {"Luffy", "Saitama", "Zorro", "Naruto", "Ace"};

    printf("Hello, welcome to this Hangman game.\n");
    printf("Would you like to know the rules? (Yes/No): ");
    scanf("%9s", choice);  

    if (strcmp(choice, "Yes") == 0 || strcmp(choice, "yes") == 0) {
        printf("Rules:\n");
        printf("1. A word is chosen randomly and some characters are omitted.\n");
        printf("2. Guess the characters to win the game. If you guess all correctly, the man lives; otherwise, he dies.\n");
    }
    
    int size = sizeof(options) / sizeof(options[0]);  
    srand(time(0));
    int random_index = rand() % size;
    
    int word_length = strlen(options[random_index]);
    char guessed[word_length + 1];
    for (int i = 0; i < word_length; i++) {
        guessed[i] = '_';
    }
    guessed[word_length] = '\0';
    
    int attempts = 0;
   
    while (attempts < word_length) {
        printf("\nCurrent word: %s\n", guessed);
        printf("Enter a letter: ");
        
        scanf(" %c", &input);
        
        int found = 0;
      
        for (int i = 0; i < word_length; i++) {
            if (options[random_index][i] == input) {
                guessed[i] = input;  
                found = 1;
            }
        }
        
        if (found) {
            printf("You guessed right!\n");
        } else {
            printf("Oops! You guessed wrong.\n");
        }
        
        attempts++;
    }
    
    printf("\nThe random word was: %s\n", options[random_index]);
    return 0;
}
