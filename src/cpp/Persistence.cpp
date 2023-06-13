#include "../hpp/Persistence.hpp"
#include "../hpp/App.hpp"
#include <fstream>  // para usar file streams (ifstream, ofstream)
#include <iostream>
#include <string>
using namespace std;

bool Persistence::LoadSimulation(AppVar& global)
{
    // FORMATO DOS DADOS DOS CÍRCULOS
    // pos.x pos.y raio vel_max
    ifstream file;
    vector<CircumBody> v;

    // Abre arquivo
    file.open("simu_" + to_string(global.simulationFileIndex) + ".txt", ios::in);

    if (!file.is_open())
    {
        cout << "O arquivo simu_" + to_string(global.simulationFileIndex) + ".txt não pôde ser aberto" << endl;
        return false;
    }

    file >> global.simulationRectTemplate;
    cout << to_string(global.simulationRectTemplate) << endl;

    do
    {
        int px, py, rad, mvel;
        file >> px >> py >> rad >> mvel;

        if (file.fail())
        {
            cout << "Erro ao ler o arquivo simu_" + to_string(global.simulationFileIndex) + ".txt" << endl;
            return false;
        }

        v.push_back(CircumBody(Vect(px, py), Vect(0, 0), Vect(0, 0), rad, mvel));
    }
    while (!file.eof());

    file.close();

    cout << "Fim da leitura do arquivo simu_" + to_string(global.simulationFileIndex) + ".txt" << endl;

    global.circumBodies = v;

    global.simulationFileIndex += 1;

    return true;
}

bool Persistence::SaveResults(AppVar& global)
{
    ofstream file;
    file.open("res_sim.txt", fstream::app);

    if (!file.is_open())
    {
        cout << "O arquivo res_sim.txt não pôde ser aberto" << endl;
        return false;
    }

    // Template, Quantidade de círculos no começo, Quantidade de círculos terminados, Tempo gasto na simulação
    file << to_string(global.simulationRectTemplate) << ";"
         << to_string(global.circumQty)              << ";"
         << to_string(global.terminatedCircumQty)    << ";"
         << to_string((SDL_GetTicks() - global.ticksBeforeSimulation) / 1000)
         << "\n";

    file.close();

    return true;
}