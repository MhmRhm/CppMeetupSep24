#include <iostream>
#include <string>

#include "ftxui/screen/screen.hpp"

using namespace std;
using namespace ftxui;

int main() {
  std::string reset_position;
  Screen screen{10, 10};

  screen.at(0, 0) = "Hello ftxui!";

  std::cout << reset_position;
  screen.Print();
  reset_position = screen.ResetPosition();

  // screen.Clear();

  Pixel p{};
  p.character = "❤️";
  p.foreground_color = Color::Red;
  screen.PixelAt(9, 9) = p;

  std::cout << reset_position;
  screen.Print();
  reset_position = screen.ResetPosition();
}
