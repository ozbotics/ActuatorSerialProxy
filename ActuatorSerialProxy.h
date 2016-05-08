/** @file ActuatorSerialProxy.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _ACTUATOR_SERIAL_PROXY_H
  #define _ACTUATOR_SERIAL_PROXY_H
  
#include <Arduino.h>
#include <Actuator.h>
#include <SerialMessageStream.h>

/**
 *  Base of all ActuatorSerialProxies
 *  Provides drop in replacement for Local Actuators, proxying a remote Actuator, communicating over a SerialMessageStream
*/
class ActuatorSerialProxy : public Actuator {
  protected:
    SerialMessageStream* _messageStream; /**< protected variable _messageStream  Shared SerialMessageStream object */ 

  public:
  
   /**
    * Constructor
    *
    * @param messageStream The shared SerialMessageStream object. 
   */
    ActuatorSerialProxy(SerialMessageStream* messageStream) : _messageStream(messageStream), Actuator() {}

   /**
    * start the actuator
    * @return nothing
    */  
    virtual void start()=0;
    
   /**
    * stop the actuator
    * @return nothing
    */ 
    virtual void stop()=0;
};
  
#endif //_ACTUATOR_SERIAL_PROXY_H
