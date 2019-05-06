#ifndef __FRAMEWORK_IOMANAGER_H__
#define __FRAMEWORK_IOMANAGER_H__
namespace lzw{
    class IOManager
    {
    private:
        /* data */
        char *buffer;
        int bufferSize;

    public:
        IOManager(/* args */);
        void loadFile(const char *filePath);
        int getBufferSize(){return this->bufferSize;};
        char *getBuffer(){return this->buffer;};
        ~IOManager();
    };

    
}

#endif //! __FRAMEWORK_IOMANAGER_H__
