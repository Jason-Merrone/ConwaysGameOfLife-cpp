#pragma once
#include "Pattern.hpp"

class PatternAcorn : public Pattern
{
  public:
    PatternAcorn();
    std::uint8_t getSizeX() const override;

    std::uint8_t getSizeY() const override;

    bool getCell(std::uint8_t x, std::uint8_t y) const override;

  private:
    std::vector<std::vector<bool>> grid;
    std::uint8_t width;
    std::uint8_t height;
};
