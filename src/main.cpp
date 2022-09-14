#include <iostream>
#include <sdl.h>
#include <PSDL.h>
#include <PWindow.h>
#include <PRenderer.h>

int main(int argc, char** argv)
{
    std::cout << "       _____                 _       _____            _" << std::endl;
    std::cout << "      |  _  | _ _  ___  ___ | | ___ |   __| ___  ___ |_| ___  ___" << std::endl;
    std::cout << "      |   __|| | ||  _|| . || || -_||   __||   || . || ||   || -_|" << std::endl;
    std::cout << "      |__|   |___||_|  |  _||_||___||_____||_|_||_  ||_||_|_||___|" << std::endl;
    std::cout << "                       |_|                      |___|" << std::endl;

    PSDL psdl;
    PWindow window("PurpleEngine", 1280, 720);
    PRenderer renderer(window);

    bool isOpen = true;
    while (isOpen)
    {
        //Event Poll
        SDL_Event event;
        while (PSDL::PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                isOpen = false;
        }

        //Render a frame
        renderer.SetDrawColor(186, 72, 247, 255); //Purple : (127, 0, 127, 255)
        renderer.Clear();

        renderer.Present();
    }

    return 0;
}
