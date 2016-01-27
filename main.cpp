#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "display.h"
#include "cpu.h"

int main(int argc, char** argv) {

  if (argc < 2) {
    std::cout << "no input file specified\n";
    return -1;
  }

  if(SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cout << "SDL_Init error: " << SDL_GetError() << '\n';
    return -1;
  }

  Display display;

  display.clear();

  Cpu chip8(display);
  chip8.loadProgram(std::string(argv[1]));
  chip8.run();
  SDL_Quit();
}
