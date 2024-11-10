#include "PatternBlinker.hpp"

PatternBlinker::PatternBlinker()
{
    this->width = 1;
    this->height = 3;
    grid.resize(this->height, std::vector<bool>(this->width, false));

    grid[0][0] = true;
    grid[1][0] = true;
    grid[2][0] = true;
}

std::uint8_t PatternBlinker::getSizeX() const
{
    return width;
}

std::uint8_t PatternBlinker::getSizeY() const
{
    return height;
}

bool PatternBlinker::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x < width && y < height)
    {
        return grid[y][x];
    }
    return false;
}