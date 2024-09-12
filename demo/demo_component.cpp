#include <iostream>
#include <string>

#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"

using namespace std;
using namespace ftxui;

int main() {
  auto screen = ScreenInteractive::Fullscreen();

  auto document = text("");
  document |= center;
  document |= bgcolor(LinearGradient()
                          .Angle(45)
                          .Stop(Color::DeepPink1)
                          .Stop(Color::DeepSkyBlue1));
  auto background{Renderer([&]() { return document; })};

  auto window1 = Window({});
  auto window2 = Window({});

  auto container = Container::Stacked({background, window1, window2});

  screen.Loop(container);
}
