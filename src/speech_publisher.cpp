#include <speech_network/speech_publisher.h>

#include <voce.h>


namespace speech_network
{

SpeechPublisher::SpeechPublisher()
    : zmq_context_(1)
    , zmq_publisher_(zmq_context_, ZMQ_PUB)
{
    // voce
	voce::init("C:\\lib\\voce-0.9.1\\lib", true, true, "../grammar", "itomp_nlp_s2");

    // network
    zmq_publisher_.bind("tcp://*:54322");
}

SpeechPublisher::~SpeechPublisher()
{
	voce::destroy();

    // TODO: destroy sockets
}

void SpeechPublisher::run()
{
    while (true)
    {
		while (voce::getRecognizerQueueSize() > 0)
		{
            // speech recognition
            std::string string;
            string = voce::popRecognizedString();

            printf("You said: %s\n", string.c_str());
            voce::synthesize(string);

            // publish string
            zmq::message_t message(string.size());
            memcpy(message.data(), &string[0], string.size());
            zmq_publisher_.send(message);
        }
    }
}

}
