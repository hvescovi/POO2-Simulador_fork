CXX=g++                     # COMPILADOR
INCDIRS=-Isdl2/include      # FLAG DE INCLUSÃO DE DIRETÓRIOS
OPT=-O0                     # FLAG DE OTIMIZAÇÕES
# CXXFLAGS = -I/usr/include/SDL2 -D_REENTRANT
# LDFLAGS = -lSDL2
# CXXFLAGS=-Wall -Wextra -Werror -g $(INCDIRS) $(OPT) # FLAGS
CXXFLAGS=-g $(INCDIRS) $(OPT) # FLAGS

OBJECTS=App.o App_Implementation.o App_LoadFromArchive.o \
	AppUtils.o AppVar.o Particle.o Simulador.o Vect.o

BINARY=Simulador

all: $(BINARY)

bin:
	if not exist bin mkdir bin

$(BINARY): $(OBJECTS) bin
	$(CXX) $(CXXFLAGS) -o bin/$(BINARY) $(OBJECTS)

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

Particle.o: Particle.cpp Particle.hpp Vect.hpp
	$(CXX) $(CXXFLAGS) -c Particle.cpp

Vect.o: Vect.cpp Vect.hpp
	$(CXX) $(CXXFLAGS) -c Vect.cpp

Simulador.o: Simulador.cpp # App.hpp AppVar.hpp Particle.hpp Vect.hpp
	$(CXX) $(CXXFLAGS) -c Simulador.cpp

clean:
	del /f /q $(BINARY).exe $(OBJECTS)