#pragma once
#include "Food.h"


class BigFood :
    public Food
{
private:
    COORD Bfposition;
public:
    BigFood();
    void GenerateBigFood();
    COORD RealPosition();
};

