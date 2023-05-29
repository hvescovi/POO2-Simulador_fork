#pragma once

class SimulationTime
{
    public:
        // Frames por segundo da janela SDL.
        int fps;
        
        // Ticks atuais do SDL.
        int ticks;

        // Delta desejado.
        double dDT;

        // Delta do loop.
        int dT;

        // Delta real.
        double rDT;

        SimulationTime();

        SimulationTime(int fps);

        void Delay();
};