#ifndef WIDGET_SERVO_H_
#define WIDGET_SERVO_H_

#include "application.h"




class WidgetServo : public WidgetBaseClass
{

public:
    WidgetServo(uint8_t ucItem = 0);
    ~WidgetServo();
    void begin(void (*UserCallBack)(void) = NULL);
    char getServoAngle(void);
    
private:
    char pCmdAngleTopic[64];
    char pDataStatusTopic[64];
    uint8_t _Item = 0;         
    int _angle;
    void (*_EventCb)(void);
    void widgetBaseCallBack(uint8_t *payload, uint32_t len);

};

#endif
