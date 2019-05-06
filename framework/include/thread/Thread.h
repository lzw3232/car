#ifndef __FRAMEWORK_THREAD_H__
#define __FRAMEWORK_THREAD_H__

#include "../../include/thread/Runnable.h"
#include <thread>

namespace lzw{
    class Thread
    {

    friend bool operator==(Thread my1, Thread my2);
    friend bool operator!=(Thread my1, Thread my2);
    
    private:
        /* data */
        Runnable *task;
        int threadId;
        std::thread thread;

    public:
        Thread(/* args */);
        ~Thread();
        void assign(Runnable *task);
        void start();
        void run();
        int getThreadId(){return this->threadId;};
    };
    

}

#endif //! __FRAMEWORK_THREAD_H__