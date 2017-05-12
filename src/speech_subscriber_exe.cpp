#include <stdio.h>

#include <speech_network/speech_subscriber.h>


int main()
{
    speech_network::SpeechSubscriber subscriber("localhost");

    while (true)
    {
        std::string string = subscriber.receive();

        if (string != "")
            printf("You said: %s\n", string.c_str());
    }

    return 0;
}
