#include "../../include/thread/Thread.h"

using namespace lzw;
    
Thread::Thread(/* args */)
{
}

Thread::~Thread()
{
}

void Thread::assign(Runnable *task){
    this->task=task;
}

void Thread::start(){
    this->thread = std::thread(&Thread::run,this);
    this->thread.join();
}

void Thread::run(){
    this->task->Run();
}