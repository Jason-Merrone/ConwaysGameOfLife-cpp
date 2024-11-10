#include "PatternGlider.hpp"

PatternGlider::PatternGlider()
{
    this->width = 3;
    this->height = 3;
    grid.resize(this->height, std::vector<bool>(this->width, false));

    grid[1][0] = true;
    grid[2][1] = true;
    grid[0][2] = true;
    grid[1][2] = true;
    grid[2][2] = true;
}

std::uint8_t PatternGlider::getSizeX() const
{
    return width;
}

std::uint8_t PatternGlider::getSizeY() const
{
    return height;
}

bool PatternGlider::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x < width && y < height)
    {
        return grid[y][x];
    }
    return false;
}