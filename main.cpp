#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <spdlog/spdlog.h>

enum TokenType
{
  tok_eof        = -1,
  tok_def        = -2,
  tok_extern     = -3,
  tok_identifier = -4,
  tok_number     = -5,
};

static std::string identifier_str;
static double      num_val;
static auto        Gettok() -> int
{
  static int last_char = ' ';
  while (isspace(last_char) != 0) {
    last_char = getchar();
  }

  if (isalpha(last_char) != 0) {
    identifier_str = std::to_string(last_char);
    while (isalnum(last_char = getchar()) != 0) {
      identifier_str += std::to_string(last_char);
    }
    if (identifier_str == "def") {
      return tok_def;
    }
    if (identifier_str == "extern") {
      return tok_extern;
    }
    return tok_identifier;
  }
  if ((isdigit(last_char) != 0) || last_char == '.') {   // Number: [0-9.]+
    std::string num_str;
    do {
      num_str += std::to_string(last_char);
      last_char = getchar();
    } while ((isdigit(last_char) != 0) || last_char == '.');

    num_val = strtod(num_str.c_str(), nullptr);
    return tok_number;
  }

  if (last_char == '#') {
    // Comment until end of line.
    do {
      last_char = getchar();
    } while (last_char != EOF && last_char != '\n' && last_char != '\r');

    if (last_char != EOF) {
      return Gettok();
    }
  }
  if (last_char == EOF) {
    return tok_eof;
  }

  // Otherwise, just return the character as its ascii value.
  int this_char = last_char;
  last_char     = getchar();
  return this_char;
}



auto main(int argc, const char** argv) -> int
{

  return 0;
}