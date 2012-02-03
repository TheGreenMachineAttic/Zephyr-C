/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "GamePadL.h"
#include "DriverStation.h"
#include "Utility.h"
// #include "WPIStatus.h"
#include <math.h>

static GamepadL *gamepads[DriverStation::kJoystickPorts];
static bool gamePadsInitialized = false;

/**
 * Construct an instance of a gamepad.
 * 
 * @param port The USB port on the driver station to which the gamepad is attached.
 */
GamepadL::GamepadL(unsigned port)
	: m_ds (NULL)
	, m_port (port)
	, m_axes (NULL)
	, m_buttons (NULL)
{
	InitGamepadL(kNumAxisTypes, kNumButtonTypes);

	m_axes[kLeftXAxis] = kDefaultLeftXAxis;
	m_axes[kLeftYAxis] = kDefaultLeftYAxis;
	m_axes[kRightXAxis] = kDefaultRightXAxis;
	m_axes[kRightYAxis] = kDefaultRightYAxis;
	m_axes[kDpadXAxis] = kDefaultDpadXAxis;
	m_axes[kDpadYAxis] = kDefaultDpadYAxis;
	
	m_buttons[kButton01] = kDefaultButton01;
	m_buttons[kButton02] = kDefaultButton02;
	m_buttons[kButton03] = kDefaultButton03;
	m_buttons[kButton04] = kDefaultButton04;
	m_buttons[kButton05] = kDefaultButton05;
	m_buttons[kButton06] = kDefaultButton06;
	m_buttons[kButton07] = kDefaultButton07;
	m_buttons[kButton08] = kDefaultButton08;
	m_buttons[kButton09] = kDefaultButton09;
	m_buttons[kButton10] = kDefaultButton10;
	m_buttons[kButton11] = kDefaultButton11;
	m_buttons[kButton12] = kDefaultButton12;
}
/**
 * Version of the constructor to be called by sub-classes.
 * 
 * This constructor allows the subclass to configure the number of constants
 * for axes and buttons.
 * 
 * @param port The port on the driver station that the gamepad is plugged into.
 * @param numAxisTypes The number of axis types in the enum.
 * @param numButtonTypes The number of button types in the enum.
 */
GamepadL::GamepadL(unsigned port, unsigned numAxisTypes, unsigned numButtonTypes)
	: m_ds (NULL)
	, m_port (port)
	, m_axes (NULL)
	, m_buttons (NULL)
{
	InitGamepadL(numAxisTypes, numButtonTypes);
}

void GamepadL::InitGamepadL(unsigned numAxisTypes, unsigned numButtonTypes)
{
	if ( !gamePadsInitialized )
	{
		for (unsigned i = 0; i < DriverStation::kJoystickPorts; i++)
			gamepads[i] = NULL;
		gamePadsInitialized = true;
	}
	gamepads[m_port - 1] = this;
	
	m_ds = DriverStation::GetInstance();
	m_axes = new unsigned[numAxisTypes];
	m_buttons = new unsigned[numButtonTypes];
}

GamepadL * GamepadL::GetStickForPort(unsigned port)
{
	GamepadL *stick = gamepads[port - 1];
	if (stick == NULL)
	{
		stick = new GamepadL(port);
		gamepads[port - 1] = stick;
	}
	return stick;
}

GamepadL::~GamepadL()
{
	delete [] m_buttons;
	delete [] m_axes;
}
/**
 * Get the left joystick X-value.
 *
 * @return The left joystick X-value of the gamepad.
 */
float GamepadL::GetLeftX(void)
{
	return GetRawAxis(m_axes[kLeftXAxis]);
}
/**
 * Get the left joystick Y-value.
 *
 * @return The left joystick Y-value of the gamepad.
 */
float GamepadL::GetLeftY(void)
{
	return -GetRawAxis(m_axes[kLeftYAxis]);
}
/**
 * Get the right joystick X-value.
 *
 * @return The right joystick X-value of the gamepad.
 */
float GamepadL::GetRightX(void)
{
	return GetRawAxis(m_axes[kRightXAxis]);
}
/**
 * Get the right joystick Y-value.
 *
 * @return The right joystick Y-value of the gamepad.
 */
float GamepadL::GetRightY(void)
{
	return -GetRawAxis(m_axes[kRightYAxis]);
}
/**
 * Get the dpad X-value.
 *
 * @return The dpad X-value of the gamepad.
 */
float GamepadL::GetDpadX(void)
{
	return GetRawAxis(m_axes[kDpadXAxis]);
}
/**
 * Get the dpad Y-value.
 *
 * @return The dpad Y-value of the gamepad.
 */
float GamepadL::GetDpadY(void)
{
	return GetRawAxis(m_axes[kDpadYAxis]);
}
/**
 * Get the axis value for axes 1 through 6.
 *
 * @param axis The axis to read (1-6)
 * @return The value of the axis
 */
float GamepadL::GetRawAxis(unsigned axis)
{
	return m_ds->GetStickAxis(m_port, axis);
}
/**
 * Return the axis value determined by the argument.
 *
 * This is for cases where the gamepad axis is returned programatically,
 * otherwise one of the previous functions would be preferable
 * (for example GetLeftX()).
 *
 * @param axis The axis to read
 * @return The value of the axis
 * @todo check signs of gamepad axes
 */
float GamepadL::GetAxis(AxisType axis)
{
	switch(axis)
	{
		case kLeftXAxis: return this->GetLeftX();
		case kLeftYAxis: return -this->GetLeftY();
		case kRightXAxis: return this->GetRightX();
		case kRightYAxis: return -this->GetRightY();
		case kDpadXAxis: return this->GetDpadX();
		case kDpadYAxis: return this->GetDpadY();
		default:
		//	wpi_fatal(BadJoystickAxis);
			return 0.0;
	}
}
/**
 * Read the state of button 1 on the gamepad.
 * 
 * @return The state of the button.
 */
bool GamepadL::GetButton01(void)
{
	return GetRawButton(m_buttons[kButton01]);
}
/**
 * Read the state of button 2 on the gamepad.
 * 
 * @return The state of the button.
 */
bool GamepadL::GetButton02(void)
{
	return GetRawButton(m_buttons[kButton02]);
}
/**
 * Read the state of button 3 on the gamepad.
 * 
 * @return The state of the button.
 */
bool GamepadL::GetButton03(void)
{
	return GetRawButton(m_buttons[kButton03]);
}
/**
 * Read the state of button 4 on the gamepad.
 * 
 * @return The state of the button.
 */
bool GamepadL::GetButton04(void)
{
	return GetRawButton(m_buttons[kButton04]);
}
/**
 * Read the state of button 5 on the gamepad.
 * 
 * @return The state of the button.
 */
bool GamepadL::GetButton05(void)
{
	return GetRawButton(m_buttons[kButton05]);
}
/**
 * Read the state of button 6 on the gamepad.
 * 
 * @return The state of the button.
 */
bool GamepadL::GetButton06(void)
{
	return GetRawButton(m_buttons[kButton06]);
}
/**
 * Read the state of button 7 on the gamepad.
 * 
 * @return The state of the button.
 */
bool GamepadL::GetButton07(void)
{
	return GetRawButton(m_buttons[kButton07]);
}
/**
 * Read the state of button 8 on the gamepad.
 * 
 * @return The state of the button.
 */
bool GamepadL::GetButton08(void)
{
	return GetRawButton(m_buttons[kButton08]);
}
/**
 * Read the state of button 9 on the gamepad.
 * 
 * @return The state of the button.
 */
bool GamepadL::GetButton09(void)
{
	return GetRawButton(m_buttons[kButton09]);
}
/**
 * Read the state of button 10 on the gamepad.
 * 
 * @return The state of the button.
 */
bool GamepadL::GetButton10(void)
{
	return GetRawButton(m_buttons[kButton10]);
}
/**
 * Read the state of button 11 on the gamepad.
 * 
 * @return The state of the button.
 */
bool GamepadL::GetButton11(void)
{
	return GetRawButton(m_buttons[kButton11]);
}
/**
 * Read the state of button 12 on the gamepad.
 * 
 * @return The state of the button.
 */
bool GamepadL::GetButton12(void)
{
	return GetRawButton(m_buttons[kButton12]);
}
/**
 * Get the button value for buttons 1 through 12.
 *
 * @param button The button number to read (1-12)
 * @return The state of the button
 */
bool GamepadL::GetRawButton(unsigned button)
{
	return ((0x1 << (button-1)) & m_ds->GetStickButtons(m_port)) != 0;
}
/**
 * Get buttons based on an enumerated type.
 * 
 * The button type will be looked up in the list of buttons and then read.
 * 
 * @param button The type of button to read.
 * @return The state of the button.
 */
bool GamepadL::GetButton(ButtonType button)
{
	switch (button)
	{
	case kButton01: return GetRawButton( 1 );
	case kButton02: return GetRawButton( 2 );
	case kButton03: return GetRawButton( 3 );
	case kButton04: return GetRawButton( 4 );
	case kButton05: return GetRawButton( 5 );
	case kButton06: return GetRawButton( 6 );
	case kButton07: return GetRawButton( 7 );
	case kButton08: return GetRawButton( 8 );
	case kButton09: return GetRawButton( 9 );
	case kButton10: return GetRawButton( 10 );
	case kButton11: return GetRawButton( 11 );
	case kButton12: return GetRawButton( 12 );
	default:
		wpi_assert(false);
		return false;
	}
}
/**
 * Get the channel currently associated with the specified axis.
 * 
 * @param axis The axis to look up the channel for.
 * @return The channel fr the axis.
 */
unsigned GamepadL::GetAxisChannel(AxisType axis)
{
	return m_axes[axis];
}

/**
 * Set the channel associated with a specified axis.
 * 
 * @param axis The axis to set the channel for.
 * @param channel The channel to set the axis to.
 */
void GamepadL::SetAxisChannel(AxisType axis, unsigned channel)
{
	m_axes[axis] = channel;
}

/**
 * Get the magnitude of the direction vector formed by the joystick's
 * current position relative to its origin
 * 
 * @return The magnitude of the direction vector
 */
float GamepadL::GetLeftMagnitude(){
	return sqrt(pow(GetLeftX(),2) + pow(GetLeftY(),2) );
}
/**
 * Get the magnitude of the direction vector formed by the joystick's
 * current position relative to its origin
 * 
 * @return The magnitude of the direction vector
 */
float GamepadL::GetRightMagnitude(){
	return sqrt(pow(GetRightX(),2) + pow(GetRightY(),2) );
}
/**
 * Get the magnitude of the direction vector formed by the joystick's
 * current position relative to its origin
 * 
 * @return The magnitude of the direction vector
 */
float GamepadL::GetDpadMagnitude(){
	return sqrt(pow(GetDpadX(),2) + pow(GetDpadY(),2) );
}
/**
 * Get the direction of the vector formed by the joystick and its origin
 * in radians
 * 
 * @return The direction of the vector in radians
 */
float GamepadL::GetLeftDirectionRadians(){
	return atan2(GetLeftX(), -GetLeftY());
}
/**
 * Get the direction of the vector formed by the joystick and its origin
 * in radians
 * 
 * @return The direction of the vector in radians
 */
float GamepadL::GetRightDirectionRadians(){
	return atan2(GetRightX(), -GetRightY());
}
/**
 * Get the direction of the vector formed by the joystick and its origin
 * in radians
 * 
 * @return The direction of the vector in radians
 */
float GamepadL::GetDpadDirectionRadians(){
	return atan2(GetDpadX(), -GetDpadY());
}
/**
 * Get the direction of the vector formed by the joystick and its origin
 * in degrees
 * 
 * uses acos(-1) to represent Pi due to absence of readily accessable Pi 
 * constant in C++
 * 
 * @return The direction of the vector in degrees
 */
float GamepadL::GetLeftDirectionDegrees(){
	return (180/acos(-1))*GetLeftDirectionRadians();
}
/**
 * Get the direction of the vector formed by the joystick and its origin
 * in degrees
 * 
 * uses acos(-1) to represent Pi due to absence of readily accessable Pi 
 * constant in C++
 * 
 * @return The direction of the vector in degrees
 */
float GamepadL::GetRightDirectionDegrees(){
	return (180/acos(-1))*GetRightDirectionRadians();
}
/**
 * Get the direction of the vector formed by the joystick and its origin
 * in degrees
 * 
 * uses acos(-1) to represent Pi due to absence of readily accessable Pi 
 * constant in C++
 * 
 * @return The direction of the vector in degrees
 */
float GamepadL::GetDpadDirectionDegrees(){
	return (180/acos(-1))*GetDpadDirectionRadians();
}
