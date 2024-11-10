#include "LifeSimulator.hpp"

LifeSimulator::LifeSimulator(std::uint8_t width, std::uint8_t height)
{
    this->width = width;
    this->height = height;
    grid.resize(this->height, std::vector<bool>(this->width, false));
}

std::uint8_t LifeSimulator::getSizeX() const
{
    return width;
}

std::uint8_t LifeSimulator::getSizeY() const
{
    return height;
}

bool LifeSimulator::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x >= width || y >= height)
    {
        return false;
    }
    return grid[y][x];
}

void LifeSimulator::insertPattern(const Pattern& pattern, std::uint8_t x, std::uint8_t y)
{
    for (std::uint8_t i = 0; i < pattern.getSizeX(); i++)
    {
        for (std::uint8_t j = 0; j < pattern.getSizeY(); j++)
        {
            std::uint8_t xPos = x + i;
            std::uint8_t yPos = y + j;

            if (xPos < width && yPos < height)
            {
                grid[yPos][xPos] = pattern.getCell(i, j);
            }
        }
    }
}

std::uint8_t LifeSimulator::numLiveNeighbors(std::uint8_t x, std::uint8_t y)
{
    std::uint8_t numAlive = 0;
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if (i == 1 && j == 1)
            {
                continue; // Skip the current cell
            }

            int nx = static_cast<int>(x) + (i - 1);
            int ny = static_cast<int>(y) + (j - 1);

            if (nx >= 0 && nx < static_cast<int>(width) && ny >= 0 && ny < static_cast<int>(height))
            {
                if (getCell(static_cast<std::uint8_t>(nx), static_cast<std::uint8_t>(ny)))
                {
                    numAlive++;
                }
            }
        }
    }
    return numAlive;
}

bool LifeSimulator::cellLives(std::uint8_t x, std::uint8_t y, std::uint8_t numNeighborsAlive)
{
    if (!getCell(x, y) && numNeighborsAlive == 3)
    {
        // Dead cell with exactly three live neighbors becomes alive
        return true;
    }
    else if (getCell(x, y) && (numNeighborsAlive == 2 || numNeighborsAlive == 3))
    {
        // Live cell with two or three live neighbors stays alive
        return true;
    }
    return false; // Cell dies or remains dead
}

void LifeSimulator::update()
{
    std::vector<std::vector<bool>> newGrid = grid;

    for (std::uint8_t y = 0; y < height; y++)
    {
        for (std::uint8_t x = 0; x < width; x++)
        {
            std::uint8_t numNeighborsAlive = numLiveNeighbors(x, y);
            if (cellLives(x, y, numNeighborsAlive))
            {
                newGrid[y][x] = true;
            }
            else
            {
                newGrid[y][x] = false;
            }
        }
    }

    grid = newGrid;
}
