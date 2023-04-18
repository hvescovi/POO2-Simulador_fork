# COMPILADOR
CXX=g++

# FLAG DE INCLUSÃO
INCDIRS=-ISDL2\i686-w64-mingw32\include\SDL2 -LSDL2\i686-w64-mingw32\lib 

# FLAG DE BIBLIOTECA
LDFLAGS = -LSDL2\i686-w64-mingw32\lib -lmingw32 -lSDL2main -lSDL2

# FLAGS
CXXFLAGS=-g $(INCDIRS) -w

OBJECTS=App.o App_Implementation.o App_LoadFromArchive.o \
	AppUtils.o AppVar.o Body.o Particle.o Vect.o Simulador.o

BINARY=Simulador

all: $(BINARY)

bin:
	if not exist bin mkdir bin

$(BINARY): $(OBJECTS) bin
	$(CXX) $(LDFLAGS) -o bin/$(BINARY) $(OBJECTS)

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

Body.o: Body.cpp Body.hpp Vect.hpp
	$(CXX) $(CXXFLAGS) -c Body.cpp

Particle.o: Particle.cpp Particle.hpp Vect.hpp
	$(CXX) $(CXXFLAGS) -c Particle.cpp

Vect.o: Vect.cpp Vect.hpp
	$(CXX) $(CXXFLAGS) -c Vect.cpp

Simulador.o: Simulador.cpp # App.hpp AppVar.hpp Particle.hpp Vect.hpp
	$(CXX) $(CXXFLAGS) -c Simulador.cpp

clean:
	del /f /q $(BINARY).exe $(OBJECTS)