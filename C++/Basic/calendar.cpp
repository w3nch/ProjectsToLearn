#include <iostream>

int main() {
  int number;
  std::cout << "Enter month (1-12): ";
  std::cin >> number;

  switch (number) {
    case 1:
      std::cout << "It is jan";
      break;
    case 2:
      std::cout << "It is feb";
      break;
    case 3:
      std::cout << "It is mar";
      break;
    case 4:
      std::cout << "It is apr";
      break;
    case 5:
      std::cout << "It is may";
      break;
    case 6:
      std::cout << "It is jun";
      break;
    case 7:
      std::cout << "It is jul";
      break;
    case 8:
      std::cout << "It is aug";
      break;
    case 9:
      std::cout << "It is sep";
      break;
    case 10:
      std::cout << "It is oct";
      break;
    case 11:
      std::cout << "It is nov";
      break;
    case 12:
      std::cout << "It is dec";
      break;
    default:
      std::cout << "Invalid month number";
      break;
  }

  return 0;
}
