#include <iostream>
#include <string>

#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"

using namespace std;
using namespace ftxui;

int main() {
  auto document = vbox({text("Some text")});
  // document |= underlined;
  // document |= bold;
  // document |= border;
  // document |= bgcolor(Color::Blue);

  auto screen =
      Screen::Create(Dimension::Fit(document), Dimension::Fit(document));
  Render(screen, document);
  screen.Print();
  std::cout << std::endl;
}
