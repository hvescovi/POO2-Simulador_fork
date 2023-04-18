#include "AppVar.hpp"

AppVar::AppVar():
	fps{},
	ticks{},
	dDT{},
	dT{},
	width{},
	height{},
	vectorParticle{},
	particleVertexQuantity{},
	rDT{}
{}

AppVar::AppVar(int pFps, int pWidth, int pHeigth, int particleVertexQuantity, std::vector<Particle> vectorParticle):
	fps{ pFps },
	ticks{ 0 },
	dDT{ 1000.0 / pFps },
	dT{ 0 },
	width{ pWidth },
	height{ pHeigth },
	vectorParticle{ vectorParticle },
	particleVertexQuantity{ particleVertexQuantity },
	rDT{ 0 }
	//gravity{ Vect(0, 9.80665) }
{}

int AppVar::get_fps() { return fps; }

int AppVar::get_ticks() { return ticks; }
void AppVar::set_ticks(int ticks) { this->ticks = ticks; }

double AppVar::get_dDT() { return dDT; }

int AppVar::get_dT() { return dT; }
void AppVar::set_dT(int dT) { this->dT = dT; }

double AppVar::get_rDT() { return rDT; }
void AppVar::set_rDT(double rDT) { this->rDT = rDT; }

int AppVar::get_width() { return width; }
int AppVar::get_heigth() { return height; }

int AppVar::get_particleVertexQuantity() { return particleVertexQuantity; }