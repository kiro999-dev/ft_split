# ft_split
This C program provides functions to split a string into an array of words based on a specified character set (charset) as the delimiter. The main function demonstrates how to use the ft_split function to split a sample string into words using a space as the delimiter and prints the resulting array of words. The program includes functions to check for characters in a charset, calculate the length of a word, count the number of words, and perform the actual string splitting.
# subject
• Create a function that splits a string of character depending on another string of
characters.
• You’ll have to use each character from the string charset as a separator.
• The function returns an array where each element of the array contains the address
of a string wrapped between two separators. The last element of that array should
equal to 0 to indicate the end of the array.
• There cannot be any empty strings in your array. Get your own conclusions ac-
cordingly.
• The string given as argument won’t be modifiable.
• Here’s how it should be prototyped :
char **ft_split(char *str, char *charset);
