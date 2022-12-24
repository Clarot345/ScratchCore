#include <iostream>
#include <vector>

// Represents a node in the intermediate language AST
struct ILExpression {
  virtual ~ILExpression() {}
};

// Represents a constant value in the intermediate language
struct ILConstant : ILExpression {
  int value;
  ILConstant(int value) : value(value) {}
};

// Represents a binary operation in the intermediate language
struct ILBinaryOperation : ILExpression {
  char op;
  std::unique_ptr<ILExpression> lhs, rhs;
  ILBinaryOperation(char op, std::unique_ptr<ILExpression> lhs,
                    std::unique_ptr<ILExpression> rhs)
      : op(op), lhs(std::move(lhs)), rhs(std::move(rhs)) {}
};

// Parses an expression in infix notation and returns an AST
std::unique_ptr<ILExpression> parseExpression(const std::string &input) {
  // TODO: Implement me!
}

// Generates machine code for the given AST
std::vector<uint8_t> generateCode(const ILExpression &expr) {
  // TODO: Implement me!
}

// Executes the given machine code
int executeCode(const std::vector<uint8_t> &code) {
  // TODO: Implement me!
}

int main() {
  std::string input;
  std::cout << "Enter an expression: ";
  std::cin >> input;

  // Parse the input into an AST
  auto expr = parseExpression(input);

  // Generate machine code from the AST
  auto code = generateCode(*expr);

  // Execute the machine code
  int result = executeCode(code);

  std::cout << "Result: " << result << std::endl;
}
