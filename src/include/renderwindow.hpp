#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "entity.hpp"

class RenderWindow {
    public:
    RenderWindow(const char* p_window_name, int p_w, int p_h);
    bool event_processes();
    SDL_Texture* load_texture(const char* p_filepath);
    void clear();
    void render(Entity& p_entity);
    void display();
    ~RenderWindow();
    
    
    private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};