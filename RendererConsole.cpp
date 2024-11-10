#include "RendererConsole.hpp"

#include "rlutil.h"

#include <iostream>

RendererConsole::RendererConsole()
{
    // Constructor
}

void RendererConsole::render(const LifeSimulator& simulation)
{
    std::uint8_t sizeX = simulation.getSizeX();
    std::uint8_t sizeY = simulation.getSizeY();

    if (previousState.empty())
    {
        // First-time rendering
        rlutil::cls();
        previousState.resize(sizeY, std::vector<bool>(sizeX, false));

        rlutil::hidecursor();

        for (std::uint8_t y = 0; y < sizeY; ++y)
        {
            for (std::uint8_t x = 0; x < sizeX; ++x)
            {
                bool alive = simulation.getCell(x, y);
                previousState[y][x] = alive;
                rlutil::locate(x + 1, y + 1); // rlutil positions start at (1,1)
                if (alive)
                {
                    std::cout << 'O';
                }
                else
                {
                    std::cout << ' ';
                }
            }
        }

        rlutil::showcursor();
        std::cout << std::flush;
    }
    else
    {
        // Update only cells that have changed state
        rlutil::hidecursor();

        for (std::uint8_t y = 0; y < sizeY; ++y)
        {
            for (std::uint8_t x = 0; x < sizeX; ++x)
            {
                bool alive = simulation.getCell(x, y);
                if (alive != previousState[y][x])
                {
                    rlutil::locate(x + 1, y + 1);
                    if (alive)
                    {
                        std::cout << 'O';
                    }
                    else
                    {
                        std::cout << ' ';
                    }
                    previousState[y][x] = alive;
                }
            }
        }

        rlutil::showcursor();
        std::cout << std::flush;
    }
}
