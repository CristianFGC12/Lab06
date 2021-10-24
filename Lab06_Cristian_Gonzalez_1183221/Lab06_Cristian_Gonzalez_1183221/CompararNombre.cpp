#include "pch.h"
#include "CompararNombre.h"

int CompararNombre::comparar(Pokemon a, Pokemon b)
{
    return a.getnombre().compare(b.getnombre());
}
