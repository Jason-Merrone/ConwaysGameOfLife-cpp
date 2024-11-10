#include "LifeSimulator.hpp"
#include "PatternAcorn.hpp"
#include "PatternBlinker.hpp"
#include "PatternBlock.hpp"
#include "PatternGlider.hpp"
#include "PatternGosperGliderGun.hpp"
#include "PatternPulsar.hpp"
#include "RendererConsole.hpp"
#include "rlutil.h"

#include <algorithm> // For std::min
#include <chrono>
#include <iostream>
#include <thread>

int main()
{
    // Window size
    int consoleWidth = rlutil::tcols();
    int consoleHeight = rlutil::trows();
    std::uint8_t sizeX = static_cast<std::uint8_t>(std::min(consoleWidth, 255));
    std::uint8_t sizeY = static_cast<std::uint8_t>(std::min(consoleHeight, 255));

    LifeSimulator simulator(sizeX, sizeY);

    // patern instances
    PatternAcorn acorn;
    PatternBlinker blinker;
    PatternBlock block;
    PatternGlider glider;
    PatternPulsar pulsar;
    PatternGosperGliderGun gosper;

    std::uint8_t acornX = sizeX / 2;
    std::uint8_t acornY = sizeY / 2;

    std::uint8_t blinkerX = sizeX / 4;
    std::uint8_t blinkerY = sizeY / 4;

    std::uint8_t blockX = sizeX / 3;
    std::uint8_t blockY = sizeY / 3;

    std::uint8_t gliderX = (sizeX / 3) * 2;
    std::uint8_t gliderY = (sizeY / 3) * 2;

    std::uint8_t pulsarX = sizeX / 5;
    std::uint8_t pulsarY = sizeY / 2;

    std::uint8_t gosperX = 5;
    std::uint8_t gosperY = 5;

    // Ensure patterns fit in window size
    if (acornX + acorn.getSizeX() < sizeX && acornY + acorn.getSizeY() < sizeY)
        simulator.insertPattern(acorn, acornX, acornY);

    if (blinkerX + blinker.getSizeX() < sizeX && blinkerY + blinker.getSizeY() < sizeY)
        simulator.insertPattern(blinker, blinkerX, blinkerY);

    if (blockX + block.getSizeX() < sizeX && blockY + block.getSizeY() < sizeY)
        simulator.insertPattern(block, blockX, blockY);

    if (gliderX + glider.getSizeX() < sizeX && gliderY + glider.getSizeY() < sizeY)
        simulator.insertPattern(glider, gliderX, gliderY);

    if (pulsarX + pulsar.getSizeX() < sizeX && pulsarY + pulsar.getSizeY() < sizeY)
        simulator.insertPattern(pulsar, pulsarX, pulsarY);

    if (gosperX + gosper.getSizeX() < sizeX && gosperY + gosper.getSizeY() < sizeY)
        simulator.insertPattern(gosper, gosperX, gosperY);

    RendererConsole renderer;

    // Animation loop
    int steps = 100000;
    for (int i = 0; i < steps; ++i)
    {
        simulator.update();
        renderer.render(simulator);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    return 0;
}
