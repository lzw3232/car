#include "../../include/window/WindowManager.h"
#include "../../include/log/Log.h"
#include "../../include/thread/Thread.h"

using namespace lzw;

WindowManager WindowManager::windowManagerInstance;
   
WindowManager::WindowManager(/* args */){
}

WindowManager::~WindowManager(){
}

WindowManager* WindowManager::GetWindowManagerInstance(){
    return &WindowManager::windowManagerInstance;
};

int WindowManager::createWindow(Window *window){
    if(windowNum==0){
        windowNum=1;
    }
    else{
        windowNum++;
    }

    //add new window
    this->windows.push_back(window);

    return 1;
};

int WindowManager::renderWindow(){
    for(int i=0;i<this->windows.size();i++){
        Thread *thread=new Thread();
        thread->assign(this->windows.at(i));
        thread->start();
    }
}