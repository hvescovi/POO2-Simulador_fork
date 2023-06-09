# COMPILADOR
CXX=g++

# FLAG DE INCLUSÃO
# INCDIRS=-ISDL2\i686-w64-mingw32\include\SDL2 -LSDL2\i686-w64-mingw32\lib 
INCDIRS=-I..\lib\SDL2win_i686-w64-mingw32\include\SDL2

# FLAG DE BIBLIOTECA
LDFLAGS = -L..\lib\SDL2win_i686-w64-mingw32\lib -lmingw32 -lSDL2main -lSDL2

# FLAGS
CXXFLAGS=-g $(INCDIRS)

OBJECTS=App.o App_Implementation.o AppVar.o Body.o CircumBody.o RectBody.o \
	Exhibition.o Mechanics.o Vect.o SimulationTime.o Persistence.o Simulador.o

BINARY=Simulador

all: $(BINARY)

bin:
	if not exist bin mkdir bin

$(BINARY): $(OBJECTS) bin
	$(CXX) $(OBJECTS) -o bin/$(BINARY) $(LDFLAGS)

App.o: cpp/App.cpp hpp/App.hpp \
	cpp/AppVar.cpp hpp/AppVar.hpp \
	hpp/Vect.hpp
	$(CXX) $(CXXFLAGS) -c cpp/App.cpp

App_Implementation.o: cpp/App_Implementation.cpp hpp/App.hpp
	$(CXX) $(CXXFLAGS) -c cpp/App_Implementation.cpp

AppVar.o: cpp/AppVar.cpp hpp/AppVar.hpp hpp/Vect.hpp
	$(CXX) $(CXXFLAGS) -c cpp/AppVar.cpp

Body.o: cpp/Body.cpp hpp/Body.hpp hpp/Vect.hpp
	$(CXX) $(CXXFLAGS) -c cpp/Body.cpp

CircumBody.o: cpp/CircumBody.cpp hpp/CircumBody.hpp hpp/Body.hpp hpp/Vect.hpp
	$(CXX) $(CXXFLAGS) -c cpp/CircumBody.cpp

RectBody.o: cpp/RectBody.cpp hpp/RectBody.hpp hpp/Body.hpp hpp/Vect.hpp
	$(CXX) $(CXXFLAGS) -c cpp/RectBody.cpp

Exhibition.o: cpp/Exhibition.cpp hpp/Exhibition.hpp hpp/Vect.hpp
	$(CXX) $(CXXFLAGS) -c cpp/Exhibition.cpp

Mechanics.o: cpp/Mechanics.cpp hpp/Mechanics.hpp hpp/Vect.hpp
	$(CXX) $(CXXFLAGS) -c cpp/Mechanics.cpp

SimulationTime.o: cpp/SimulationTime.cpp hpp/SimulationTime.hpp
	$(CXX) $(CXXFLAGS) -c cpp/SimulationTime.cpp

Persistence.o: cpp/Persistence.cpp hpp/Persistence.hpp
	$(CXX) $(CXXFLAGS) -c cpp/Persistence.cpp

Vect.o: cpp/Vect.cpp hpp/Vect.hpp
	$(CXX) $(CXXFLAGS) -c cpp/Vect.cpp

Simulador.o: Simulador.cpp # App.hpp AppVar.hpp Particle.hpp Vect.hpp
	$(CXX) $(CXXFLAGS) -c Simulador.cpp

clean:
	del /f /q bin\$(BINARY).exe $(OBJECTS)