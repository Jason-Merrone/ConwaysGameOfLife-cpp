#include "PatternAcorn.hpp"

PatternAcorn::PatternAcorn()
{
    this->width = 7;
    this->height = 3;
    grid.resize(this->height, std::vector<bool>(this->width, false));

    grid[2][0] = true;
    grid[0][1] = true;
    grid[2][1] = true;
    grid[1][3] = true;
    grid[2][4] = true;
    grid[2][5] = true;
    grid[2][6] = true;
}

std::uint8_t PatternAcorn::getSizeX() const
{
    return width;
}

std::uint8_t PatternAcorn::getSizeY() const
{
    return height;
}

bool PatternAcorn::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x < width && y < height)
    {
        return grid[y][x];
    }
    return false;
}