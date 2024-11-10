#include "PatternGosperGliderGun.hpp"

PatternGosperGliderGun::PatternGosperGliderGun()
{
    this->width = 36;
    this->height = 9;
    grid.resize(this->height, std::vector<bool>(this->width, false));

    // Define the pattern by marking cells as `true`
    grid[4][0] = true;
    grid[5][0] = true;
    grid[4][1] = true;
    grid[5][1] = true;

    grid[4][10] = true;
    grid[5][10] = true;
    grid[6][10] = true;
    grid[3][11] = true;
    grid[7][11] = true;
    grid[2][12] = true;
    grid[8][12] = true;
    grid[2][13] = true;
    grid[8][13] = true;
    grid[5][14] = true;
    grid[3][15] = true;
    grid[8][15] = true;
    grid[4][16] = true;
    grid[5][16] = true;
    grid[6][16] = true;
    grid[5][17] = true;

    grid[2][20] = true;
    grid[3][20] = true;
    grid[4][20] = true;
    grid[2][21] = true;
    grid[3][21] = true;
    grid[4][21] = true;
    grid[1][22] = true;
    grid[5][22] = true;
    grid[0][24] = true;
    grid[1][24] = true;
    grid[5][24] = true;
    grid[6][24] = true;

    grid[2][34] = true;
    grid[3][34] = true;
    grid[2][35] = true;
    grid[3][35] = true;
}

std::uint8_t PatternGosperGliderGun::getSizeX() const
{
    return width;
}

std::uint8_t PatternGosperGliderGun::getSizeY() const
{
    return height;
}

bool PatternGosperGliderGun::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x < width && y < height)
    {
        return grid[y][x];
    }
    return false;
}

// bool PatternGosperGliderGun::getCell(std::uint8_t x, std::uint8_t y) const
// {
//     // Extra bounds check for uint8_t
//     if (x >= 0 && x < width && y >= 0 && y < height)
//     {
//         return grid[y][x];
//     }
//     return false;
// }