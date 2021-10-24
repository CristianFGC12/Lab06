#include "pch.h"
#include"List.h"
#include "Pokemon.h"
#include <string>
#include"CompararPokedex.h"
#include"CompararGeneracion.h"
#include"Orden.h"

using namespace System;
using std::string;

void MarshalString(String^ s, string& os) {
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
}

List<Pokemon>*LeerPokemon(String^ filepath)
{
    List<Pokemon>* pokemons = new List<Pokemon>();

    array<String^>^ lines = System::IO::File::ReadAllLines(filepath);

    for (int i = 0; i < lines->Length; i++)
    {
        array<String^>^ line = lines[i]->Split(',');
        int pokedex = Convert::ToInt32(line[0]);
        string nombre;
        MarshalString(line[1], nombre);
        int generacion = Convert::ToInt32(line[2]);

        Pokemon* pokemon = new Pokemon(pokedex, nombre, generacion);

        pokemons->add(pokemon);
    }

    return pokemons;
}

void Mostrar(List<Pokemon>* pokemons)
{
    Console::WriteLine("No\tNombre\tGeneracion");

    for (int i = 0; i < pokemons->getSize(); i++)
    {
        Pokemon* pokemon = pokemons->get(i);

        String^ nombre = gcnew String(pokemon->getnombre().c_str());

        Console::WriteLine("{0}\t{1}\t{2}", pokemon->getpokedex(), nombre, pokemon->getgeneracion());
    }
}

int main(array<System::String ^> ^args)
{
    List<Pokemon>* pokemons = LeerPokemon("Pokedex.cvs");
    int m;
    Console::WriteLine("Desea ordenar por medio de: ");
    Console::WriteLine("1. Numero de Pokedex");
    Console::WriteLine("2. Generacion de origen");
    m = Convert::ToInt32(Console::ReadLine());
    switch (m)
    {
    case 01: 
        pokemons = pokemons->BubbleSort(new CompararPokedex(), new CompararNombre());
        Mostrar(pokemons);
        break;
    case 02:
        pokemons = pokemons->selectionSort(new CompararGeneracion(),new CompararNombre());
        Mostrar(pokemons);
        break;
    default:
        break;
    }

    system("PAUSE");
}
