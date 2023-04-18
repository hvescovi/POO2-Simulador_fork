# author: Éder Augusto Penharbel
# date: November 07, 2022.
# version: November 07, 2022.
#
# author: Marcos Viana Sena
# date: November 28, 2022.
# version: November 28, 2022.

.PHONY: all clean

CXX = g++
RM = rm -f
CXXFLAGS = -I/usr/include/SDL2 -D_REENTRANT
LDFLAGS = -lSDL2 
MKDIR = mkdir

all: App.o App_OnCleanup.o App_OnEvent.o App_OnInit.o App_OnBeforeLoop.o \
	AppUtils.o AppVar.o Particle.o App_OnRenderPresent.o App_OnTimeDelay.o\
	App_OnRenderParticle.o App_OnParticleBorderCollision.o App_OnParticleMove.o \
	App_OnRenderClear.o App_OnParticleCollision.o App_OnLoopThroughParticles.o \
	Simulador.o Vect.o

bin:
	$(MKDIR) ./bin

Simulador: App.o App_OnCleanup.o App_OnEvent.o App_OnInit.o App_OnBeforeLoop.o \
	AppUtils.o AppVar.o Particle.o App_OnRenderPresent.o App_OnTimeDelay.o\
	App_OnRenderParticle.o App_OnParticleBorderCollision.o App_OnParticleMove.o \
	App_OnRenderClear.o App_OnParticleCollision.o App_OnLoopThroughParticles.o \
	Simulador.o Vect.o bin	
	$(CXX) *.o -o ./bin/Simulador $(LDFLAGS) 

App.o: App.cpp App.h AppVar.h App_OnRenderParticle.cpp Particle.h Vect.h

App_OnCleanup.o: App_OnCleanup.cpp App.h AppVar.h App_OnRenderParticle.cpp Particle.h Vect.h

App_OnEvent.o: App_OnEvent.cpp App.h AppVar.h App_OnRenderParticle.cpp Particle.h Vect.h

App_OnInit.o: App_OnInit.cpp App.h AppVar.h App_OnRenderParticle.cpp Particle.h Vect.h

App_OnBeforeLoop.o: App_OnBeforeLoop.cpp App.h AppVar.h App_OnRenderParticle.cpp Particle.h Vect.h

AppUtils.o: AppUtils.cpp AppUtils.h Vect.h

AppVar.o: AppVar.cpp AppVar.h App_OnRenderParticle.cpp Particle.h Vect.h
 Particle.o: Particle.cpp Particle.h Vect.h

App_OnRenderParticle.o: App_OnRenderParticle.cpp Particle.h Vect.h

App_OnParticleMove.o: App_OnParticleMove.cpp Particle.cpp Particle.h App_OnRenderParticle.cpp

App_OnRenderPresent.o: App_OnRenderPresent.cpp App.h

App_OnTimeDelay.o: App_OnTimeDelay.cpp App.h

App_OnRenderClear.o: App_OnRenderClear.cpp App.h

App_OnParticleBorderCollision.o: App_OnParticleBorderCollision.cpp App.h

App_OnParticleCollision.o: App_OnParticleCollision.cpp App.h AppUtils.h

App_OnLoopThroughParticles.o: App_OnLoopThroughParticles.cpp App.h

Simulador.o: Simulador.cpp App.h AppVar.h App_OnRenderParticle.cpp Particle.h Vect.h

Vect.o: Vect.cpp Vect.h

clean: App.o App_OnCleanup.o
	$(RM) App.o
	$(RM) App_OnCleanup.o
	$(RM) App_OnEvent.o
	$(RM) App_OnInit.o
	$(RM) App_OnBeforeLoop.o
	$(RM) AppUtils.o
	$(RM) AppVar.o
	$(RM) Particle.o
	$(RM) App_OnRenderParticle.o
	$(RM) App_OnParticleMove.o
	$(RM) App_OnRenderPresent.o
	$(RM) App_OnTimeDelay.o
	$(RM) App_OnRenderClear.o
	$(RM) App_OnParticleBorderCollision.o
	$(RM) App_OnParticleCollision.o
	$(RM) App_OnLoopThroughParticles.o
	$(RM) Simulador.o
	$(RM) Vect.o
	$(RM) ./bin/Simulador