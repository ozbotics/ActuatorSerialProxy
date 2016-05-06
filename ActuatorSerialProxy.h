#ifndef _ACTUATOR_SERIAL_PROXY_H
  #define _ACTUATOR_SERIAL_PROXY_H
  
#include <Arduino.h>
#include <Actuator.h>
#include <SerialMessageStream.h>

class ActuatorSerialProxy : public Actuator {
  protected:
    SerialMessageStream* _stream;

  public:

    ActuatorSerialProxy(HardwareSerial& stream) : Actuator() {
      this->_stream = new SerialMessageStream(stream);
    }
    
    ~ActuatorSerialProxy()  {
      delete _stream;
    }
    
    virtual void start()=0;
    virtual void stop()=0;
};
  
#endif //_ACTUATOR_SERIAL_PROXY_H
