#include "include/entity.hpp"

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex)
:pos(p_pos), tex(p_tex)
{
    current_frame = { 0, 0, 32, 32 };
}

SDL_Texture* Entity::get_texture()
{
    return tex;
}
SDL_Rect Entity::get_current_frame()
{
    return current_frame;
}