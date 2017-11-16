/*
************************************************************************
* 作者:  IntoRobot Team 
* 版本:  V1.0.0
* 日期:  03-30-15
************************************************************************
功能描述：
舵机控制：控制舵机的运动

所需器件:
1.舵机（舵机电流过大需单独供电）

接线说明:
SG90 9G舵机                  Atom
1.红线                       +5V
2.暗灰线                     GND
3.橙黄线                     A0
*/

#include <WidgetServo.h>

#define SERVO_CONTROL_PIN    A0 //定义舵机控制引脚

Servo myservo;
WidgetServo servo = WidgetServo();

void servoAngleControlCb(void)
{
	if((servo.getServoAngle()>=0) && (servo.getServoAngle()<=180))
	{
		myservo.write(servo.getServoAngle());
	}
}

void setup()
{
	//初始化
	myservo.attach(SERVO_CONTROL_PIN);
	//接收舵机控制
	servo.begin(servoAngleControlCb);
}

void loop()
{
}
