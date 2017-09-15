/** @file ActuatorSerialProxy.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _ACTUATOR_SERIAL_PROXY_H
  #define _ACTUATOR_SERIAL_PROXY_H
  
#include <Arduino.h>
#include <Actuator.h>
#include <MessageStream.h>

/**
 *  Base of all ActuatorSerialProxies
 *  Provides drop in replacement for Local Actuators, proxying a remote Actuator, communicating over a MessageStream
*/
class ActuatorSerialProxy : public Actuator {
  protected:
    MessageStream* _messageStream; /**< protected variable _messageStream  Shared MessageStream object */ 

  public:
  
   /**
    * Constructor
    *
    * @param messageStream The shared MessageStream object. 
    */
    ActuatorSerialProxy(MessageStream* messageStream) : _messageStream(messageStream), Actuator() {}

   /**
    * start the actuator
    */  
    virtual void start()=0;
    
   /**
    * stop the actuator
    */ 
    virtual void stop()=0;
};
  
#endif //_ACTUATOR_SERIAL_PROXY_H
