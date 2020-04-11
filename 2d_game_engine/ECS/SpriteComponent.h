#pragma once

#include "Components.h"
#include <SDL2/SDL.h>
#include "../TextureManager.h"

class SpriteComponent : public Component
{
    private:
        TransformComponent *transform;
        SDL_Texture *texture;
        SDL_Rect srcRect, destRect;
    
    public:
        SpriteComponent() = default;
        SpriteComponent(const char* path)
        {
            texture = TextureManager::loadTexture(path);
        }


        ~SpriteComponent()
        {
            SDL_DestroyTexture(texture);
        }
        void setTex(const char* path)
        {
            texture = TextureManager::loadTexture(path);
        }

        void init() override
        {
            transform = &entity->getComponent<TransformComponent>();

            srcRect.x = srcRect.y = 0;
            srcRect.w = transform->wigth;
            srcRect.h = transform->height;
            destRect.w = destRect.h = 64;
        }

        void update() override
        {
            destRect.x = (int)transform->position.x;
            destRect.y = (int)transform->position.y;
            destRect.w = transform->wigth * transform->scale;
            destRect.h = transform->height * transform->scale;

        }

        void draw() override
        {
            TextureManager::Draw(texture, srcRect, destRect);
        }


};