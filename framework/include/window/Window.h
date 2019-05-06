#ifndef __FRAMEWORK_WINDOW_H__
#define __FRAMEWORK_WINDOW_H__

#include <SDL2/SDL.h>
#include "../../include/image/PixelMtrix.h"
#include "../../include/thread/Runnable.h"

namespace lzw{
    class Window:public Runnable{
        private:
            bool running = true;

            SDL_Window* window = NULL;
            SDL_Renderer* renderer = NULL;
            SDL_Surface* primarySurface = NULL;

            int windowWidth = 256;
            int windowHeight = 240;

            char *windowName = "lzw Window";

            PixelMtrix *pixelMtrix=NULL;
            
        private:

            // Capture SDL Events
            void OnEvent(SDL_Event* Event);
        
            // Initialize our SDL game / app
            bool Init();
        
            // Logic loop
            void Loop();
        
            // Render loop (draw)
            void Render();
        
            // Free up resources
            void Cleanup();

            void Run();
        public:
            
            int Execute();
            
            Window();
            Window(int windowWidth,int windowHeight,const char *windowName);

            int GetWindowWidth();
            int GetWindowHeight();

            void SetWindowWidth(int width){this->windowWidth=width;};
            void SetWindowHeight(int height){this->windowHeight=height;};
            void SetWindowName(char *name){this->windowName=name;};
            void SetPixelMtrix(PixelMtrix *pixels){this->pixelMtrix=pixels;};

    };

}

#endif //! __FRAMEWORK_WINDOW_H__