
#include "WidgetServo.h"


WidgetServo::WidgetServo(uint8_t ucItem)
{
    _Item=ucItem;
    memset(pCmdAngleTopic,0,sizeof(pCmdAngleTopic));
    memset(pDataStatusTopic,0,sizeof(pDataStatusTopic));  
    sprintf(pCmdAngleTopic,"channel/servo_%d/cmd/angle",_Item);   
    sprintf(pDataStatusTopic,"channel/servo_%d/data/status",_Item);  
}

WidgetServo::~WidgetServo()
{
    
}

void WidgetServo::begin(void (*UserCallBack)(void))
{
    _EventCb=UserCallBack;
    IntoRobot.subscribe(pCmdAngleTopic, NULL, this);
}

char WidgetServo::getServoAngle(void)
{
    return _angle;
}

void WidgetServo::widgetBaseCallBack(uint8_t *payload, uint32_t len)
{
   _angle = atoi((char *)payload);
   _EventCb();
   IntoRobot.publish(pDataStatusTopic,1);
}

