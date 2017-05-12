#include <stdio.h>

#include <speech_network/speech_publisher.h>


int main()
{
    speech_network::SpeechPublisher publisher;
    publisher.run();

    return 0;
}
