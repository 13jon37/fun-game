#include "include/renderwindow.hpp"

RenderWindow::RenderWindow(const char* p_window_name, int p_w, int p_h)
: window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(p_window_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    
    if (!window) 
        std::cout << "Failed to create window. Error: " << SDL_GetError() << "\n";
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
}

bool RenderWindow::event_processes()
{
    bool running = true;
    SDL_Event event;
    
    if (SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT: {
                running = false;
            } break;
        }
    }
    
    return running;
}

SDL_Texture* RenderWindow::load_texture(const char* p_filepath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filepath);
    
    if (!texture)
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << "\n";
    
    return texture;
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}
void  RenderWindow::render(Entity& p_entity)
{
    SDL_Rect src = { p_entity.get_current_frame().x, p_entity.get_current_frame().y, p_entity.get_current_frame().w, p_entity.get_current_frame().h };
    
    SDL_Rect dst = { (int)p_entity.get_pos().x, (int)p_entity.get_pos().y, p_entity.get_current_frame().w, p_entity.get_current_frame().h };
    
    SDL_RenderCopy(renderer, p_entity.get_texture(), &src, &dst);
}

void  RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}

RenderWindow::~RenderWindow()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}