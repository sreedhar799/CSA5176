#include<stdio.h>
#include<ctype.h>
int main()
{
  char text[500], ch;
  int key;
  // taking user input
  printf("Enter a message to encrypt: ");
  scanf("%s", text);
  printf("Enter the key: ");
  scanf("%d", & key);
  // visiting character by character
  for (int i = 0; text[i] != '\0'; ++i) {
    ch = text[i];
    // check for valid character
    if (isalnum(ch)) {
      // lower case characters
      if (islower(ch)) {
        ch = (ch - 'a' + key) % 26 + 'a';
      }
      // uppercase characters
      if (isupper(ch)) {
        ch = (ch - 'A' + key) % 26 + 'A';
      }
      // numbers
      if (isdigit(ch)) {
        ch = (ch - '0' + key) % 10 + '0';
      }
    }
    // invalid character
    else {
      printf("Invalid Message");
    }
    // adding encoded answer 
    text[i] = ch;
  }
  printf("Encrypted message: %s", text);
  return 0;
}
