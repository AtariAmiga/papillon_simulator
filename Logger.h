#ifndef LOGGER_H
#define LOGGER_H

#include <ctime>
#include <iostream>
#include <sstream>
#include <string>

class Logger: public std::ostream {
    // Source: https://stackoverflow.com/questions/2212776/overload-handling-of-stdendl

    class StreamBuf: public std::stringbuf {
    private:
        std::ostream& _output;
        time_t& _currentTime;
        time_t& _lastTimeLogged;

    public:
        StreamBuf(std::ostream& output, time_t& currentTime, time_t& lastTimeLogged ):
            _output(output), _currentTime(currentTime), _lastTimeLogged(lastTimeLogged)

        {}
        ~StreamBuf() override {
            if( pbase() != pptr() ) {
                putOutput();
            }
        }

        // When we sync the stream with the _output.
        // 1) Output Plop then the buffer
        // 2) Reset the buffer
        // 3) flush the actual _output stream we are using.
        int sync() override {
            putOutput();
            return 0;
        }

        void putOutput() {
            // Called by destructor.
            // destructor can not call virtual methods.
            if( _lastTimeLogged < _currentTime ) {
                _lastTimeLogged = _currentTime;
                _output << _currentTime;
            }

            _output << '\t' <<  str();
            str("");
            _output.flush();
        }
    };

    // My Stream just uses a version of my special buffer
    StreamBuf buffer;

public:
    explicit Logger(std::ostream& str);

    void updateTime(time_t t);

private:
    time_t _currentTime;
    time_t _lastTimeLogged;
};


#endif // LOGGER_H
