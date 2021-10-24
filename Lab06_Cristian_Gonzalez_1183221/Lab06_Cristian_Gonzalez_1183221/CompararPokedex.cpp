#include "pch.h"
#include "CompararPokedex.h"

int CompararPokedex::comparar(Pokemon a, Pokemon b)
{
    return a.getpokedex()-b.getpokedex();
}
