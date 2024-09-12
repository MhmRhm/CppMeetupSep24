#include <chrono>
#include <iostream>
#include <string>

#include "ftxui/component/component.hpp"
#include "ftxui/component/loop.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"

using namespace std;
using namespace chrono;
using namespace ftxui;

int main() {
  auto screen = ScreenInteractive::Fullscreen();

  bool clicked{};
  steady_clock::time_point start{};

  auto component{Renderer([&]() {
    auto document{text("Squid Game")};
    document |= center;
    document |= clicked ? bgcolor(Color::Green) : bgcolor(Color::Red);
    return document;
  })};

  component |= CatchEvent([&](Event event) -> bool {
    if (event.is_mouse() && event.mouse().button == Mouse::Left) {
      clicked = true;
      start = steady_clock::now();
    }
    if (event == Event::Character('q'))
      screen.Exit();
    return true;
  });

  Loop loop(&screen, component);
  while (!loop.HasQuitted()) {
    loop.RunOnce();

    if ((steady_clock::now() - start) > 2s) {
      clicked = false;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(2));
  }
}
