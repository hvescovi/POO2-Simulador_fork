#include "Button.hpp"

Button::Button() :
    position{ Vect() },
    width{ 0 },
    height{ 0 },
    isPressed{ false }
{}

Button::Button(Vect position, int width, int height):
    position{ position },
    width{ width },
    height{ height },
    isPressed{ false }
{}

Vect Button::get_pos() { return position; }
int Button::get_w() { return width; }
int Button::get_h() { return height; }

bool Button::get_isPressed() { return isPressed; }
void Button::not_isPressed() { isPressed = !isPressed; }