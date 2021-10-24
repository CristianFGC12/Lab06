#pragma once
#include "Comparador.h"
#include "Pokemon.h"
class CompararPokedex :
    public Comparador<Pokemon>
{
    // Heredado vía Comparador
    virtual int comparar(Pokemon a, Pokemon b) override;
};

