#ifndef SPEECH_NETWORK_SPEECH_SUBSCRIBER_H
#define SPEECH_NETWORK_SPEECH_SUBSCRIBER_H


#include <zmq.hpp>

#include <string>


namespace speech_network
{

class SpeechSubscriber
{
public:

    SpeechSubscriber(const std::string& ip);
    ~SpeechSubscriber();

    std::string receive();

private:

    zmq::context_t zmq_context_;
    zmq::socket_t zmq_subscriber_;
};

}


#endif // SPEECH_NETWORK_SPEECH_SUBSCRIBER_H