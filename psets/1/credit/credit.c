#include <cs50.h>
#include <stdio.h>

int main(void) {
  long card;
  int digitn;
  int digit;
  int brand;

  card = get_long("Number: ");

  if (card <= 3000000000000 || card > 6000000000000000)
  {
    printf("INVALID\n");
    return 1;
  }

  while (card > 0)
  {
    if (card / 10 < 9 && card / 10 > 0)
    {
      brand += card;
    }

    digit += card % 10;
    card = card / 10;

    if (card / 10 < 9 && card / 10 > 0)
    {
      brand += card;
    }

    int expr = (card % 10) * 2;
    digitn += expr > 9 ? expr - 9 : expr;

    card = card / 10;
  }

  // for VISA cards
  if (brand / 10 == 4)
  {
    brand = brand / 10;
  }

  if ((digitn + digit) % 10 == 0)
  {
    switch (brand)
    {
    case 34:
    case 37:
      printf("AMEX\n");
      break;
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
      printf("MASTERCARD\n");
      break;
    case 4:
      printf("VISA\n");
      break;
    default:
      printf("INVALID\n");
      break;
    }
  }
  else
  {
    printf("INVALID\n");
  }
}
