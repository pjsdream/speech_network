#include <speech_network/speech_subscriber.h>


namespace speech_network
{

SpeechSubscriber::SpeechSubscriber(const std::string& ip)
    : zmq_context_(1)
    , zmq_subscriber_(zmq_context_, ZMQ_SUB)
{
    std::string address = "tcp://" + ip + ":54322";
    zmq_subscriber_.connect(address.c_str());
    zmq_subscriber_.setsockopt(ZMQ_SUBSCRIBE, "", 0);
}

SpeechSubscriber::~SpeechSubscriber()
{
    // TODO: destroy sockets
}

std::string SpeechSubscriber::receive()
{
    zmq::message_t message;

    zmq_subscriber_.recv(&message);

    std::string string;
    char* p = (char*)message.data();
    for (int i=0; i<message.size(); i++)
        string.push_back(*p++);

    return string;
}

}
