#ifndef SPEECH_NETWORK_SPEECH_PUBLISHER_H
#define SPEECH_NETWORK_SPEECH_PUBLISHER_H


#include <zmq.hpp>


namespace speech_network
{

class SpeechPublisher
{
public:

    SpeechPublisher();
    ~SpeechPublisher();

    // infinite loop publishing recognized strings
    void run();

private:

    zmq::context_t zmq_context_;
    zmq::socket_t zmq_publisher_;
};

}


#endif // SPEECH_NETWORK_SPEECH_PUBLISHER_H