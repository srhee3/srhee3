#include <stdio.h>
#include <string.h>
// inputs 

void words_anagram
(char first_word[], char second_word[]) {
    
printf("Please enter the first word: ");
scanf("%s", first_word);

printf("Please enter the second word: ");
scanf("%s", second_word);
}

// functions
char letter;
int anagram(char first_word[], char second_word[]) {
int letter_count1[26];  // array size is 26 letters in alphabet 
int letter_count2[26]; 
int a;  // variable a

for(a = 0; a < 26; ++a) {

letter_count1[a] = 0;
letter_count2[a] = 0;
}

// for first word 
a = 0;

while(first_word[a] != 0) {

letter = first_word[a];

if(letter >= 'A' && letter <= 'Z') {
letter += 32;
}

letter_count1[letter- 'a']++;

a++;

}
// for second word
a = 0;

while(second_word[a] != 0) {

letter = second_word[a];

if(letter >= 'A' && letter <= 'Z') {
letter += 32;  //output
}

letter_count2[letter - 'a']++;
a++;

}

for (a = 0; a < 26; ++a) {

if (letter_count1[a] != letter_count2[a]) {
return 0;  
}
}

return 1;  
}

void print_if_anagram(char first_word[], char second_word[]) {
if(anagram (first_word, second_word) == 1) {
printf("%s is an anagram of %s", first_word, second_word);
} 
else {
printf("%s is NOT an anagram of %s", first_word, second_word);
}
}

// main function
int main() {

char first_word[100], second_word[100];
words_anagram (first_word, second_word);
print_if_anagram (first_word, second_word);

return 0;
}