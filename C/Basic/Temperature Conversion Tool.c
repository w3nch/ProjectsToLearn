#include <ctype.h>
#include <stdio.h>

int main() {
  char unit;
  double temp;

  printf("\nIs the temperature in (F) or (C): ");
  scanf("%c", &unit);
  unit = toupper(unit);

  if (unit == 'C') {
    printf("\nEnter the temperature in C: ");
    scanf("%lf", &temp);
    temp = (temp * 9.0 / 5.0) + 32.0;
    printf("\nThe temperature in F: %.2lf", temp);
  } else if (unit == 'F') {
    printf("\nEnter the temperature in F: ");
    scanf("%lf", &temp);
    temp = (temp - 32.0) * 5.0 / 9.0;
    printf("\nThe temperature in C: %.2lf", temp);
  } else {
    printf("\nInvalid temperature unit.");
  }

  return 0;
}
