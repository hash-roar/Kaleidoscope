#include <fmt/core.h>
#include <fmt/format.h>

#include <vector>

int main(int argc, const char** argv) {
  std::vector<int> vec{1, 43, 645};
  fmt::print("{}", vec);
  return 0;
}