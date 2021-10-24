#pragma once
#include "Comparador.h"
#include "Pokemon.h"
class CompararNombre :
    public Comparador<Pokemon>
{
    // Heredado vía Comparador
    virtual int comparar(Pokemon a, Pokemon b) override;
};

