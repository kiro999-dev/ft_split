#include <stdio.h>
#include <stdlib.h>

// Function to check if a character is in a given character set (charset)
int cheak_charset(char c, char *charset) {
    int i = 0;
    while (charset[i]) {
        if (charset[i] == c) {
            return 1; // Character found in the charset
        }
        i++;
    }
    return 0; // Character not found in the charset
}

// Function to calculate the length of a word in a string, delimited by a charset
int len_word(int i, char *str, char *charset) {
    int len = 0;
    while (str[i] && !cheak_charset(str[i], charset)) {
        len++;
        i++;
    }
    return len;
}

// Function to count the number of words in a string, delimited by a charset
int word_count(char *str, char *charset) {
    int i = 0;
    int count = 0;
    while (str[i]) {
        while (str[i] && cheak_charset(str[i], charset)) {
            i++;
        }
        if (str[i]) {
            count++;
        }
        while (str[i] && !cheak_charset(str[i], charset)) {
            i++;
        }
    }
    return count;
}

// Function to split a string into an array of words, delimited by a charset
char **ft_split(char *str, char *charset) {
    char **result = malloc(word_count(str, charset) * sizeof(char *) + 1);
    char *word = NULL;
    int i = 0, len = 0, j = 0, k = 0;

    if (!result) {
        return NULL;
    }

    while (str[i]) {
        while (str[i] && cheak_charset(str[i], charset)) {
            i++;
        }

        j = 0;
        len = len_word(i, str, charset);
        word = malloc(len + 1);

        while (str[i] && !cheak_charset(str[i], charset)) {
            word[j] = str[i];
            i++;
            j++;
        }

        word[j] = '\0';
        result[k] = word;
        k++;
    }

    result[k] = 0; // Null-terminate the array
    return result;
}

int main() {
    // Test case: Split a string into words using a space as the delimiter
    char **result = ft_split("hello man what are u doing", " ");
    int i = 0;

    // Print the resulting array of words
    while (result[i]) {
        printf("%s\n", result[i]);
        i++;
    }

    // Free allocated memory
    free(result);

    return 0;
}

