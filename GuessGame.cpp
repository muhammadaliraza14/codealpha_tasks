#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const int MAX_WORDS = 10;
const int MAX_WORD_LENGTH = 10;

// Function to choose a random word from an array of words
char* chooseWord(const char* words[], int numWords) {
    srand(time(0));
    return const_cast<char*>(words[rand() % numWords]);
}

// Function to check if the guessed letter exists in the chosen word
bool checkGuess(char guess, const char* word) {
    int len = strlen(word);
    for (int i = 0; i < len; ++i) {
        if (word[i] == guess) {
            return true;
        }
    }
    return false;
}

// Function to update the guessed word with correctly guessed letters
void updateGuessedWord(char guess, const char* word, char* guessedWord) {
    int len = strlen(word);
    for (int i = 0; i < len; ++i) {
        if (word[i] == guess) {
            guessedWord[i] = guess;
        }
    }
}

int main() {
    const char* words[MAX_WORDS] = {"apple", "banana", "orange", "grape", "melon",
                                     "peach", "strawberry", "codealpha", "mango", "pineapple"};
    char* chosenWord = chooseWord(words, MAX_WORDS);

    int wordLength = strlen(chosenWord);

    char guessedWord[MAX_WORD_LENGTH];
    for (int i = 0; i < wordLength; ++i) {
        guessedWord[i] = '_';
    }
    guessedWord[wordLength] = '\0';

    int attempts = 0;
    bool guessed = false;

    cout << "Welcome to the Guess the Word game!" << endl;
    cout << "Guess the word by entering one letter at a time." << endl;

    while (!guessed && attempts < 10) {
        cout << "Word: " << guessedWord << endl;
        cout << "Enter your guess: ";
        char guess;
        cin >> guess;
        cin.ignore(); // Clear input buffer

        if (checkGuess(guess, chosenWord)) {
            updateGuessedWord(guess, chosenWord, guessedWord);
            cout << "Correct guess!" << endl;
            if (strcmp(guessedWord, chosenWord) == 0) {
                guessed = true;
            }
        } else {
            cout << "Incorrect guess!" << endl;
            attempts++;
        }
    }

    if (guessed) {
        cout << "Congratulations! You guessed the word: " << chosenWord << endl;
    } else {
        cout << "Sorry, you've run out of attempts. The word was: " << chosenWord << endl;
    }

    return 0;
}
