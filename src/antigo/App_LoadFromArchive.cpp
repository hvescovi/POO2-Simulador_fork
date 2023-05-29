// #include "App.hpp"
// #include <fstream>	// para usar file streams (ifstream,ofstream)
// #include <iostream>	// para usar cin,cout
// #include <string>	// para usar string
// #include <iomanip>	// para usar manipuladores (setw, right, ...)
// using namespace std;

// std::vector<Particle> App::LoadFromArchive(std::string filename)
// {
//     ifstream archive;
//     std::vector<Particle> v;

//     try
//     {
//         // Abre arquivo
//         archive.open(filename, ios::in);

//         if (!archive.is_open())
//         {
//             const char* msg = "O arquivo não pôde ser aberto.";
//             throw string(msg);
//         }

//     }
//     catch (const char* s)
//     {
//         std::cout << s << std::endl;
//     }

//     //DADOS:
//     //Posição Velocidade Raio
//     //FORMATO:
//     //PX PY VX VY RAD -> por linha, espaço entre eles

//     try
//     {
//         do
//         {
//             double px, py, vx, vy, rad;
//             archive >> px >> py >> vx >> vy >> rad;

//             if (archive.fail())
//             {
//                 const char* msg = "Erro ao ler o conteúdo.";
//                 throw(msg);
//             }

//             v.push_back(Particle(Vect(px, py), Vect(vx, vy), rad));

//         } while (archive.good());

//         if (archive.bad() || !archive.eof()) 
//         {
//             const char* msg = "Erro fatal.";
//         }
//     }
//     catch (const char* s)
//     {
//         std::cout << s << std::endl;
//         archive.close();
//     }

//     archive.close();

//     return v;
// }