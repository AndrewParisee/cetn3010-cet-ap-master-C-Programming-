/* Assignment 3 - Morse Code [Deja Vu]:
 * Morse code to text added to assignment 2 program
 * Created by: Andrew Parisee
 */


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SENTENCE_CHARACTER_LENGTH 4000
#define CHOICE_LENGTH 100

// Morse Code Symbols
char morse[27][5] = {".-", "-...","-.-.","-..",".","..-.","--.\0","....\0","..\0",".---\0",
                 "-.-\0",".-..\0","--\0","-.\0","---\0",".--.\0","--.-\0",".-.\0","...\0","-\0","..-\0",
                 "...-\0",".--\0","-..-\0","-.--\0","--..\0"};
// Letters in order with morse code
char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'};
int morseCodeLetterLength[SENTENCE_CHARACTER_LENGTH];
int isValidInput = 0;

// Letters to morse code function
void letters_to_morse_code(char sentence[]) {
    // Loop through each letter in the user input
    for (int i = 0; i < strlen(sentence); i++) {
        // If there is a space print a space
        if(sentence[i] == ' ') {
            printf(" ");
        } else {
            isValidInput = 0;
            // Loop through each letter in the letters array
            for (int x = 0; x < strlen(letters); x++) {
                // Compare the sentence array to the letters array
                if (toupper(sentence[i]) == letters[x]) {
                    // Print morse code as the user entered
                    printf("%s ", morse[x]);
                    // Assign length of morse code to a variable
                    morseCodeLetterLength[i] = strlen(morse[x]);
                    isValidInput = 1;
                }
            }

            // Correct new line error in coding
            if(sentence[i] == '\n'){
                isValidInput = 1;
            }

            // Break out of loop when 0
            else if(isValidInput == 0){
                break;
            }
        }
    }

    if (isValidInput == 1){
        printf("\n");

        // Loop through each letter in the user input
        for(int y = 0; y < strlen(sentence); y++){
            // Print uppercase letters of user input letters
            printf("%c", toupper(sentence[y]));
            // For loop to arrange the letters in the correct manner for morse code
            for (int z = 0; z < morseCodeLetterLength[y]; z++) {
                printf(" ");
            }
        }
    }

    else{
        printf("Not a valid input! (Must Be A LETTER)");
    }
}

// Morse code to letters function
void morse_code_to_letters(char sentence[]) {
    char *currentCode;
    char modifiedSentence[SENTENCE_CHARACTER_LENGTH];
    // Copy sentence array into modified sentence array (dest, src)
    strcpy(modifiedSentence, sentence);
    // Break the sentence into a series of tokens and set into variable
    currentCode = strtok(modifiedSentence, " \n");
    int count = 0;
    // Loop as long as the pointer is not empty
    while (currentCode != NULL) {
        isValidInput = 0;
        size_t x = 0;
        // Loop through the morse code array
        for( x = 0; x < sizeof(morse) / sizeof(morse[x]); x++) {
            if(strcmp(currentCode, morse[x]) == 0) {
                printf("%c ", letters[x]);
                morseCodeLetterLength[count] = strlen(morse[x]) - 1;
                // Loop through the user input morse code
                for (int z = 0; z < morseCodeLetterLength[count]; z++) {
                    printf(" ");
                }
                isValidInput = 1;
                count ++;
            }
        }
        currentCode = strtok(NULL, " \n");
    }

    if (isValidInput == 1){
        printf("\n%s", sentence);
    } else{
        printf("Not a valid input! (Must Be Morse Code)");
    }
}

// Main function
int main() {
    // Variables
    char sentence[SENTENCE_CHARACTER_LENGTH];
    char choice[CHOICE_LENGTH];

    printf("Assignment 3 - Morse Code(Deja vu)\n");
    printf("-------------------------\n");
    printf("\nEnter 1 to type a message or 2 to type a coded stream: ");
    fgets(choice, CHOICE_LENGTH - 1, stdin);

    // Call letters to morse function when 1 is selected
    if(strcmp(choice, "1\n") == 0) {
        printf("\nSend the dots and dashes over the telegraph.\n");
        printf("\nEnter the message: ");
        fgets(sentence, SENTENCE_CHARACTER_LENGTH - 1, stdin);
        letters_to_morse_code(sentence); // calling method
    }

    // Call morse code to letters function when 2 is selected
    else if(strcmp(choice, "2\n") == 0) {
        printf("\nReceive the dots and dashes from the telegraph.\n");
        printf("\nEnter the coded stream: ");
        fgets(sentence, SENTENCE_CHARACTER_LENGTH - 1, stdin);
        morse_code_to_letters(sentence); // calling method
    }
    // Anything other than 1 or 2 is entered
    else {
        printf("Incorrect Input.");
    }
    return 0;
}