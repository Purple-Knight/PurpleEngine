#include <iostream>
#include <PSDL.h>
#include <PWindow.h>
#include <PRenderer.h>
#include <ResourceManager.h>
#include <InputManager.h>
#include <Sprite.h>
#include <PTexture.h>
#include <Vector2.h>
#include <Transform.h>
#include <Model.h>
#include <imgui.h>
#include <imgui_impl_sdl.h>
#include <imgui_impl_sdlrenderer.h>
#include <entt/entt.hpp>

int main(int argc, char** argv)
{

    PSDL psdl;
    PWindow window("PurpleEngine", 1280, 720);
    PRenderer renderer(window);

    ResourceManager& resourceManager = ResourceManager::Instance();
    InputManager& inputManager = InputManager::Instance();

    //entt
    entt::registry registry;
    entt::entity entity = registry.create();

    //Model
    Model house("PurpleGame/assets/House.model");

    //Srite
    std::shared_ptr<PTexture> runner = resourceManager.GetTexture(renderer, "PurpleGame/assets/runner.png");
    Sprite sprite(runner);

    sprite.Resize(256, 256);
    sprite.SetRect(SDL_Rect{ 0, 0, 32, 32 });
    Transform spriteT;
    spriteT.SetPosition(120, 300);

    //Input 
    inputManager.BindKeyPressed(SDLK_RIGHT, "Right");
    inputManager.BindKeyPressed(SDLK_LEFT, "Left");

    inputManager.OnAction("Right", [&spriteT]() {spriteT.position.x += 5; });
    inputManager.OnAction("Left", [&spriteT]() {spriteT.position.x -= 5; });

    Uint64 lastUpdate = SDL_GetPerformanceCounter();

    bool isOpen = true;
    while (isOpen)
    {
        //Time 
        Uint64 now = SDL_GetPerformanceCounter();
        float deltaTime = (float)(now - lastUpdate) / SDL_GetPerformanceFrequency();
        lastUpdate = now;

        //Event Poll
        SDL_Event event;
        while (PSDL::PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                isOpen = false;

            //if (event.type == SDL_KEYDOWN)
                //inputManager.CheckInput(event.key.keysym.sym);
        }

        //Render a frame
        renderer.SetDrawColor(186, 72, 247, 255); //Purple : (127, 0, 127, 255)
        renderer.Clear();

        sprite.Draw(renderer, spriteT.position.x, spriteT.position.y);
        renderer.Present();
    }

    return 0;
}
