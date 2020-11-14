#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "math.hpp"

class Entity {
    public:
    Entity(Vector2f p_pos, SDL_Texture* p_tex);
    Vector2f& get_pos()
    {
        return pos;
    }
    SDL_Texture* get_texture();
    SDL_Rect get_current_frame();
    
    private:
    Vector2f pos;
    SDL_Rect current_frame;
    SDL_Texture* tex;
};