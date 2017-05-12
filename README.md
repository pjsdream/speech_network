# speech_network
speech recognition string communication using voce and zmq

## Dependencies
* jdk Windows x86 1.8.0
* jre Windows x86 1.8.0
* voce 0.9.1
* libzmq 4.2.1, c++ binding

## Build
1. Install jdk and jre for Windows x86, add the followings to the PATH environment variable:
 * `<jre_dir>/bin/client`
 * `<jdk_dir>/bin`
2. Download `voce`
3. Download and build `libzmq`, copy `zmq.h`, `zmq.hpp`, `libzmq.lib` to `/lib`, `libzmq.dll` to `/bin`.