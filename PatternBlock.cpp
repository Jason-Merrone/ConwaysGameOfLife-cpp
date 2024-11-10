#include "PatternBlock.hpp"

PatternBlock::PatternBlock()
{
    this->width = 2;
    this->height = 2;
    grid.resize(this->height, std::vector<bool>(this->width, false));

    grid[0][0] = true;
    grid[1][0] = true;
    grid[0][1] = true;
    grid[1][1] = true;
}

std::uint8_t PatternBlock::getSizeX() const
{
    return width;
}

std::uint8_t PatternBlock::getSizeY() const
{
    return height;
}

bool PatternBlock::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x < width && y < height)
    {
        return grid[y][x];
    }
    return false;
}