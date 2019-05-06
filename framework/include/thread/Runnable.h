#ifndef __FRAMEWORK_RUNNABLE_H__
#define __FRAMEWORK_RUNNABLE_H__


namespace lzw{
    class Runnable
    {
    
    private:
        /* data */

    public:
        Runnable(/* args */);
        ~Runnable();
        virtual void Run()=0;
    };

}

#endif //! __FRAMEWORK_RUNNABLE_H__