#include "PatternPulsar.hpp"

PatternPulsar::PatternPulsar()
{
    this->width = 13;
    this->height = 13;
    grid.resize(this->height, std::vector<bool>(this->width, false));

    grid[2][0] = true;
    grid[3][0] = true;
    grid[4][0] = true;
    grid[8][0] = true;
    grid[9][0] = true;
    grid[10][0] = true;

    grid[2][5] = true;
    grid[3][5] = true;
    grid[4][5] = true;
    grid[8][5] = true;
    grid[9][5] = true;
    grid[10][5] = true;

    grid[2][7] = true;
    grid[3][7] = true;
    grid[4][7] = true;
    grid[8][7] = true;
    grid[9][7] = true;
    grid[10][7] = true;

    grid[2][12] = true;
    grid[3][12] = true;
    grid[4][12] = true;
    grid[8][12] = true;
    grid[9][12] = true;
    grid[10][12] = true;

    grid[0][2] = true;
    grid[5][2] = true;
    grid[7][2] = true;
    grid[12][2] = true;

    grid[0][3] = true;
    grid[5][3] = true;
    grid[7][3] = true;
    grid[12][3] = true;

    grid[0][4] = true;
    grid[5][4] = true;
    grid[7][4] = true;
    grid[12][4] = true;

    grid[0][8] = true;
    grid[5][8] = true;
    grid[7][8] = true;
    grid[12][8] = true;

    grid[0][9] = true;
    grid[5][9] = true;
    grid[7][9] = true;
    grid[12][9] = true;

    grid[0][10] = true;
    grid[5][10] = true;
    grid[7][10] = true;
    grid[12][10] = true;
}

std::uint8_t PatternPulsar::getSizeX() const
{
    return width;
}

std::uint8_t PatternPulsar::getSizeY() const
{
    return height;
}

bool PatternPulsar::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x < width && y < height)
    {
        return grid[y][x];
    }
    return false;
}