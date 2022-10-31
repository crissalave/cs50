#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int checkinvalid(string key);

int main(int argc, string argv[]) {
  // string key = "YUKFRNLBAVMWZteogxhcipjsqd";
  // string plaintext = "This is CS50";

  if (argc != 2) {
    printf("Usage: ./substitution key\n");
    return 1;
  }

  string key = argv[1];
  int errorCode = checkinvalid(key);

  // handle error code
  if (errorCode == 2) {
    printf("Key must contain 26 characters.\n");
    return 1;
  } else if (errorCode == 3) {
    printf("Key must contain only valid characters\n");
    return 1;
  } else if (errorCode == 4) {
    printf("Key must contain no repeat characters\n");
    return 1;
  }

  string plaintext = get_string("plaintext: ");

  printf("ciphertext: ");
  for (int i = 0; i < strlen(plaintext); i++) {

    int pos;
    int n = plaintext[i];
    char cipherchar;

    if (isupper(plaintext[i])) {
      pos = n - 65;
      cipherchar = key[pos];
      printf("%c", toupper(cipherchar));

    } else if (islower(plaintext[i])) {
      pos = n - 97;
      cipherchar = key[pos];
      printf("%c", tolower(cipherchar));

    } else {
      printf("%c", plaintext[i]);
    }
  }
  printf("\n");

  return 0;
}

int checkinvalid(string key) {
  int error = 0;
  char character;
  char character2;

  // check if ket not contain 26 characters
  if (strlen(key) != 26) {
    error = 2;
    return error;
  }

  for (int i = 0; i < strlen(key); i++) {
    character = key[i];

    // check if the key containe any character that is not an alphabetic
    // character
    if (!isalpha(character)) {
      error = 3;
      break;
    }

    // check if key contain a letter exactly one
    for (int j = i + 1; j < strlen(key); j++) {
      character2 = key[j];
      if (character == character2) {
        error = 4;
        break;
      }
    }
  }

  return error;
}
