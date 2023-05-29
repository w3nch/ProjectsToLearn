#include <iostream>
#include <string>
#include <sstream>
#include <vector>

double evaluateExpression(const std::string& expression) {
  std::istringstream iss(expression);
  std::vector<double> numbers;
  std::vector<char> operators;
  
  double num;
  char op;
  while (iss >> num) {
    numbers.push_back(num);
    
    if (iss >> op) {
      operators.push_back(op);
    }
  }
  
  double result = numbers[0];
  for (size_t i = 0; i < operators.size(); ++i) {
    switch (operators[i]) {
      case '+':
        result += numbers[i + 1];
        break;
      case '-':
        result -= numbers[i + 1];
        break;
      case '*':
        result *= numbers[i + 1];
        break;
      case '/':
        if (numbers[i + 1] != 0) {
          result /= numbers[i + 1];
        } else {
          std::cout << "Error: Division by zero is not allowed.\n";
          return 0.0;
        }
        break;
      default:
        std::cout << "Error: Invalid operator.\n";
        return 0.0;
    }
  }
  
  return result;
}

int main() {
  std::string expression;
  
  std::cout << "****************** CALCULATOR ***************** \n";
  std::cout << "Enter an arithmetic expression: ";
  std::getline(std::cin, expression);
  
  double result = evaluateExpression(expression);
  std::cout << "Result: " << result << '\n';
  
  std::cout << "******************  ***************** \n";
  return 0;
}
