/** @file LedActuatorSerialProxy.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _LED_ACTUATOR_SERIAL_PROXY_H
  #define _LED_ACTUATOR_SERIAL_PROXY_H
  
#include <Arduino.h>
#include <ActuatorSerialProxy.h>
#include <SerialMessageStream.h>

#define PROXY_BUFF_SIZE 8  /**< const  PROXY_BUFF_SIZE size of the request buffer */ 

/**
 *  SerialProxy for LedActuator
 *  Provides drop in replacement for Local LedActuator(s), proxying a remote LedActuator, communicating over a SerialMessageStream
 */
class LedActuatorSerialProxy : public ActuatorSerialProxy {
  protected:
    byte _id; /**< protected variable _id  The remote actuator_id */ 

   /**
    * start the timer, completing in dur milliseconds
    *
    * @param enabled Turn Off/On LedActuator
    */  
    inline void _setEnabled(bool enabled) {
      char _request[PROXY_BUFF_SIZE];
      
      sprintf(_request, "L,%d,%d", _id, enabled);
      _messageStream->writeRequest(_request);
    }
    
  public:

   /**
    * Constructor
    *
    * @param messageStream Pointer to the SerialMessageStream
    * @param id The remote actuator_id 
    */
    LedActuatorSerialProxy(SerialMessageStream* messageStream, byte id) : _id(id), ActuatorSerialProxy(messageStream) {}
    
   /**
    * start the actuator
    */  
    virtual void start() {
      _setEnabled(true);
    }
    
   /**
    * stop the actuator
    */ 
    virtual void stop() {
      _setEnabled(false);
    }
};


#endif //_LED_ACTUATOR_SERIAL_PROXY_H
