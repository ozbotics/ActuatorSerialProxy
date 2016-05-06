#ifndef _ACTUATOR_SERIAL_PROXY_H
  #define _ACTUATOR_SERIAL_PROXY_H
  
#include <Arduino.h>
#include <Actuator.h>
#include <SerialMessageStream.h>

class ActuatorSerialProxy : public Actuator {
  protected:
    SerialMessageStream* _messageStream;

  public:

    ActuatorSerialProxy(SerialMessageStream* messageStream) : _messageStream(messageStream), Actuator() {}
        
    virtual void start()=0;
    virtual void stop()=0;
};
  
#endif //_ACTUATOR_SERIAL_PROXY_H
