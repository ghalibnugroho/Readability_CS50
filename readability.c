#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int get_index(string s);
int letters, words, sentences;

int main(){
    string text = get_string("Text : ");
    int index = get_index(text);
    printf("Letters : %d\n", letters);
    printf("Words : %d\n", words);
    printf("Sentences : %d\n", sentences);
    if(index<1){
        printf("Before Grade 1\n");
    }else if(index >= 16){
        printf("Grade 16+ \n");
    }else{
        printf("Grade %d\n", index);
    }
    
    return 0;
}

int get_index(string s){
    letters = 0, words = 0, sentences = 0;
    for(int i = 0; i < strlen(s); i++){
         char chr = s[i];
         if(isalpha(chr)){
             letters++;
         }
         //hello world
         if(isspace(chr)){
             words++;
         }
         if(chr == '.' || chr == '!' || chr == '?'){
             sentences++;
         }
    }
    // nambahin ini buat ngitung 2 kata kalo ada pemisahan dari spasi.
    words++; 
    float L = (letters * 100) / words  ;
    float S = (sentences * 100) / words ;
    return round(0.0588 * L - 0.296 * S - 15.8); 
}

// int main()
// {
//     int count_letter = 0;
//     int count_word = 0;
//     int count_sentence = 0;

//     string s = get_string("Text: ");

//     for (int i = 0, n = strlen(s); i < n; i++)
//     {
//         if (isalpha(s[i]))
//         {
//             count_letter += 1;
//         }
//     }
//     printf("%i letters \n", count_letter);

//     for (int j = 0, n = strlen(s); j < n; j++)
//     {
//         if (isspace(s[j])) //if(s[j] == 32) 32 = spasi
//         {
//             count_word++;
//         }
//     }
//     count_word++;
//     printf("%i words \n", count_word+1);

//     for (int k = 0, n = strlen(s); k < n; k++)
//     {
//         if (s[k] == 46 || s[k] == 33 || s[k] == 63)
//         {
//             count_sentence++;
//         }
//     }
//     printf("%i sentences \n", count_sentence);

//     //Count index number
//     float L = (100 * count_letter) / count_word;
//     float S = (100 * count_sentence) / count_word;

//    // printf("%f, %f \n", L, S);

//     int index = round(0.0588 * L - 0.296 * S - 15.8);

//     if (index > 16)
//     {
//         printf("Grade 16+ \n");
//     }

//     else if (index < 1)
//     {
//         printf("Before Grade 1 \n");
//     }

//     else   //There are more things in Heaven and Earth, Horatio, than are dreamt of in your philosophy. grade 9
//     {
//         printf("Grade: %d \n", index);
//         // return 0;
//     }
//     return 0;
// }