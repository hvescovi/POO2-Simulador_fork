# COMPILADOR
CXX=g++

# FLAG DE INCLUSÃO
# INCDIRS=-ISDL2\i686-w64-mingw32\include\SDL2 -LSDL2\i686-w64-mingw32\lib 
INCDIRS=-ISDL2\i686-w64-mingw32\include\SDL2

# FLAG DE BIBLIOTECA
LDFLAGS = -LSDL2\i686-w64-mingw32\lib -lmingw32 -lSDL2main -lSDL2

# FLAGS
CXXFLAGS=-g $(INCDIRS)

OBJECTS=App.o App_Implementation.o App_LoadFromArchive.o \
	AppUtils.o AppVar.o Body.o Particle.o Vect.o SimulationTime.o \
	Simulador.o

BINARY=Simulador

all: $(BINARY)

bin:
	if not exist bin mkdir bin

$(BINARY): $(OBJECTS) bin
	$(CXX) $(OBJECTS) -o bin/$(BINARY) $(LDFLAGS)

App.o: App.cpp App.hpp \
	AppVar.cpp AppVar.hpp \
	Particle.cpp Particle.hpp \
	Vect.cpp Vect.hpp
	$(CXX) $(CXXFLAGS) -c App.cpp

App_Implementation.o: App_Implementation.cpp App.hpp
	$(CXX) $(CXXFLAGS) -c App_Implementation.cpp

App_LoadFromArchive.o: App_LoadFromArchive.cpp App.hpp
	$(CXX) $(CXXFLAGS) -c App_LoadFromArchive.cpp

AppUtils.o: AppUtils.cpp AppUtils.hpp Vect.hpp
	$(CXX) $(CXXFLAGS) -c AppUtils.cpp

AppVar.o: AppVar.cpp AppVar.hpp Particle.hpp Vect.hpp
	$(CXX) $(CXXFLAGS) -c AppVar.cpp

Body.o: Body.cpp Body.hpp Vect.hpp Shape.hpp
	$(CXX) $(CXXFLAGS) -c Body.cpp

Shape.o: Shape.cpp Shape.hpp Vect.hpp
	$(CXX) $(CXXFLAGS) -c Shape.cpp

Circle.o: Circle.cpp Circle.hpp Vect.hpp
	$(CXX) $(CXXFLAGS) -c Circle.cpp

Rectangle.o: Rectangle.cpp Rectangle.hpp Vect.hpp
	$(CXX) $(CXXFLAGS) -c Rectangle.cpp

Vect.o: Vect.cpp Vect.hpp
	$(CXX) $(CXXFLAGS) -c Vect.cpp

SimulationTime.o: SimulationTime.cpp SimulationTime.hpp
	$(CXX) $(CXXFLAGS) -c SimulationTime.cpp

Simulador.o: Simulador.cpp # App.hpp AppVar.hpp Particle.hpp Vect.hpp
	$(CXX) $(CXXFLAGS) -c Simulador.cpp

clean:
	del /f /q $(BINARY).exe $(OBJECTS)