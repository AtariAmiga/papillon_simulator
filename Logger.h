#ifndef LOGGER_H
#define LOGGER_H

#include <ctime>
#include <iostream>
#include <sstream>

class Logger: public std::ostream
{
    // Write a stream buffer that prefixes each line with Plop
    class MyStreamBuf: public std::stringbuf
    {
        std::ostream&   output;
    public:
        explicit MyStreamBuf(std::ostream& str)
                :output(str)
        {}
        ~MyStreamBuf() override {
            if (pbase() != pptr()) {
                putOutput();
            }
        }

        // When we sync the stream with the output.
        // 1) Output Plop then the buffer
        // 2) Reset the buffer
        // 3) flush the actual output stream we are using.
        int sync() override {
            putOutput();
            return 0;
        }
        void putOutput() {
            // Called by destructor.
            // destructor can not call virtual methods.
            output << "[blah]" << str();
            str("");
            output.flush();
        }
    };

    // My Stream just uses a version of my special buffer
    MyStreamBuf buffer;
public:
    Logger(std::ostream& str)
            :std::ostream(&buffer)
            ,buffer(str)
    {
    }

private:
    time_t _currentTime;
    time_t _lastTimeLogged;
};


#endif // LOGGER_H
