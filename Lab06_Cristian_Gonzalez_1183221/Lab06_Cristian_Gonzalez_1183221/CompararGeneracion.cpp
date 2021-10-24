#include "pch.h"
#include "CompararGeneracion.h"

int CompararGeneracion::comparar(Pokemon a, Pokemon b)
{
    return a.getgeneracion()-b.getgeneracion();
}
