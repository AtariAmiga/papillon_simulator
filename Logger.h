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
        int& _indent;
        time_t& _currentTime;
        time_t& _lastTimeLogged;

    public:
        StreamBuf(std::ostream& output, time_t& currentTime, time_t& lastTimeLogged, int& _indent ):
            _output(output), _currentTime(currentTime), _lastTimeLogged(lastTimeLogged), _indent(_indent)
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
                _output << '\n';
                _output << _currentTime;
            }

            _output << std::string(_indent, '\t') <<  str();
            str("");
            _output.flush();
        }
    };

    StreamBuf buffer;

public:
    explicit Logger(std::ostream& str);

    void updateTime(time_t t);

    void stepIn();
    void stepOut();

private:
    int _indent;
    time_t _currentTime;
    time_t _lastTimeLogged;
};


extern Logger logger;

#endif // LOGGER_H
