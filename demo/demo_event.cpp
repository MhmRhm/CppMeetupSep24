#include <iostream>
#include <string>

#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"

using namespace std;
using namespace ftxui;

int main() {
  auto screen = ScreenInteractive::Fullscreen();

  bool clicked{};

  auto component{Renderer([&]() {
    auto document{text("Squid Game")};
    document |= center;
    document |= clicked ? bgcolor(Color::Green) : bgcolor(Color::Red);
    return document;
  })};

  component |= CatchEvent([&](Event event) -> bool {
    clicked = event.is_mouse() && event.mouse().button == Mouse::Left;
    return true;
  });

  screen.Loop(component);
}
