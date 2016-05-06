#ifndef _LED_ACTUATOR_SERIAL_PROXY_H
  #define _LED_ACTUATOR_SERIAL_PROXY_H
  
#include <Arduino.h>
#include <ActuatorSerialProxy.h>
#include <SerialMessageStream.h>

#define PROXY_BUFF_SIZE 8

class LedActuatorSerialProxy : public ActuatorSerialProxy {
  protected:
    byte _id;
    
    inline void _setEnabled(bool enabled) {
      char _request[PROXY_BUFF_SIZE];
      
      sprintf(_request, "L,%d,%d", _id, enabled);
      _messageStream->writeRequest(_request);
    }
    
  public:
    LedActuatorSerialProxy(SerialMessageStream* messageStream, byte id) : _id(id), ActuatorSerialProxy(messageStream) {}
    
    virtual void start() {
      _setEnabled(true);
    }
    
    virtual void stop() {
      _setEnabled(false);
    }
};


#endif //_LED_ACTUATOR_SERIAL_PROXY_H
