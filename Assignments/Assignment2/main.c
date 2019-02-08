/* Assignment 2 - Morse Code:
 * The task of Assignment 2 is to develop a console application that will allow the user to enter in one or more words
 * separated by a space. The program must convert each letter to the corresponding Morse Code equivalent.
 * The program only needs to convert the upper-case alphabet; lower-case letters, digits, punctuation and other
 * characters don't need to be converted and you can assume they won't be typed in.
 * Created by: Andrew Parisee
 */

// Include and Define Statements
#include <stdio.h>
#include <string.h>
#include <ctype.h>


// change to all caps and underscores
#define sentenceCharacterLength 1000

int main() {

    // Morse Code Symbols in order and letters arranged in same order
    char *morse[] = {".-", "-...","-.-.","-..",".","..-.","--.","....","..",".---",
                     "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-",
                     "...-",".--","-..-","-.--","--.."};

    char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                      'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'};

    int morseCodeLetterLength[sentenceCharacterLength];

    int isValidInput = 0;

    // Define string variable
    char sentence[sentenceCharacterLength];

    printf("Assignment 2 - Morse Code\n");
    printf("-------------------------\n");
    printf("\nEnter the message: ");
    fgets (sentence, sentenceCharacterLength-1, stdin);

    printf("\nSend the dots and dashes over the telegraph.\n");

    // Begin for loop to loop through letters
    for (int i = 0; i < strlen(sentence); i++) {
        // If statement to detect space within the input
        if(sentence[i] == ' ') {
            printf(" ");
            // Else to set validation to zero
        } else {
            isValidInput = 0;
            // For loop to loop through and print the letters underneath the morse code
            for (int x = 0; x < strlen(letters); x++) {
                // If statement to compare the sentence array to the letters array and print the morse code
                if (toupper(sentence[i]) == letters[x]) {
                    printf("%s ", morse[x]);
                    morseCodeLetterLength[i] = strlen(morse[x]);
                    isValidInput = 1;
                }
            }

            // If statement to correct error caused by new line
            if(sentence[i] == '\n'){
                isValidInput = 1;
            }

            // Else if to set validation to zero so code does not continue
            else if(isValidInput == 0){
                break;
            }
        }
    }

    // If statement that checks if the validation is one
    if (isValidInput == 1){
        printf("\n");
        // For loop to print the letters in uppercase
        for(int y = 0; y < strlen(sentence); y++){
            printf("%c", toupper(sentence[y]));
            // For loop to print the space in the morse code
            for (int z = 0; z < morseCodeLetterLength[y]; z++) {
                printf(" ");
            }
        }
    }

    // Else statement to print invalid input line (VALIDATION)
    else{
        printf("Not a valid input! (Must Be A LETTER)");
    }

    return 0;
}