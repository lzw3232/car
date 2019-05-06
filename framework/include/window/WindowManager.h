#ifndef __FRAMEWORK_WINDOW_MANAGER_H__
#define __FRAMEWORK_WINDOW_MANAGER_H__

#include "../../include/window/Window.h"
#include <vector>

namespace lzw{
    class WindowManager
    {
    private:
        /* data */
        static WindowManager windowManagerInstance;
        std::vector<Window*> windows;
        int windowNum=0;
    public:
        WindowManager(/* args */);

        static WindowManager *GetWindowManagerInstance();

        int getWindowNum(){return this->windowNum;};

        int createWindow(Window *window);

        int renderWindow();

        ~WindowManager();
    };

    
}

#endif //! __FRAMEWORK_WINDOW_MANAGER_H__
