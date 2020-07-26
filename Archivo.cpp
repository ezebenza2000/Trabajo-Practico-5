#include "Archivo.h"
#include <fstream>

using namespace std;

bool Archivo :: existe_archivo(ifstream archivo)
{
    if (!archivo.fail())
    {
        return true;
    }
    else
        return false;
}
