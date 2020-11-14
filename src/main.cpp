#include <iostream>
#include <vector>

#include "include/renderwindow.hpp"

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Failed to init SDL video. Error: " << SDL_GetError() << "\n";
        exit(1);
    }
    if (!IMG_Init(IMG_INIT_PNG)) {
        std::cout << "Failed to init IMG. Error: " << SDL_GetError() << "\n";
        exit(1);
    }
    
    RenderWindow window("Fun Game", 800, 600);
    
    SDL_Texture* block = window.load_texture("imgs/block.png");
    
    std::vector<Entity> entities = {
        Entity(Vector2f(0, 0), block),
        Entity(Vector2f(32, 0), block), 
        Entity(Vector2f(64, 0), block)
    };
    
    bool running = true;
    
    while (running) 
    {
        running = window.event_processes();
        
        window.clear();
        
        for (Entity& e : entities)
            window.render(e);
        
        window.display();
    }
    
    return 0;
}