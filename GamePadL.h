/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef GAME_PAD_H_
#define GAME_PAD_H_

#include "Base.h"

class DriverStation;

/**
 * Handle input from standard Gamepads connected to the Driver Station.
 * For Gamepads such as the Logitech Dual Action or RumblePads.
 * This class handles standard input that comes from the Driver Station. Each
 * time a value is requested the most recent value is returned. There is a
 * single class instance for each gamepad and the mapping of ports to hardware
 * buttons depends on the code in the driver station.
 * @author DWD
 */
class GamepadL
{
public:
	static const unsigned kDefaultLeftXAxis = 1;
	static const unsigned kDefaultLeftYAxis = 2;
	static const unsigned kDefaultRightXAxis = 3;
	static const unsigned kDefaultRightYAxis = 4;
	static const unsigned kDefaultDpadXAxis = 5;
	static const unsigned kDefaultDpadYAxis = 6;
	typedef enum
	{
		kLeftXAxis, kLeftYAxis, kRightXAxis, kRightYAxis, kDpadXAxis,
		kDpadYAxis, kNumAxisTypes
	} AxisType;
	static const unsigned kDefaultButton01 = 1;
	static const unsigned kDefaultButton02 = 2;
	static const unsigned kDefaultButton03 = 3;
	static const unsigned kDefaultButton04 = 4;
	static const unsigned kDefaultButton05 = 5;
	static const unsigned kDefaultButton06 = 6;
	static const unsigned kDefaultButton07 = 7;
	static const unsigned kDefaultButton08 = 8;
	static const unsigned kDefaultButton09 = 9;
	static const unsigned kDefaultButton10 = 10;
	static const unsigned kDefaultButton11 = 11;
	static const unsigned kDefaultButton12 = 12;
	typedef enum
	{
		kButton01, kButton02, kButton03, kButton04, kButton05, kButton06, kButton07,
		 kButton08, kButton09, kButton10, kButton11, kButton12, kNumButtonTypes
	} ButtonType;

	explicit GamepadL(unsigned port);
	GamepadL(unsigned port, unsigned numAxisTypes, unsigned numButtonTypes);
	virtual ~GamepadL();

	unsigned GetAxisChannel(AxisType axis);
	void SetAxisChannel(AxisType axis, unsigned channel);

	virtual float GetLeftX(void);
	virtual float GetLeftY(void);
	virtual float GetRightX(void);
	virtual float GetRightY(void);
	virtual float GetDpadX(void);
	virtual float GetDpadY(void);
	virtual float GetAxis(AxisType axis);
	float GetRawAxis(unsigned axis);

	virtual bool GetButton01(void);
	virtual bool GetButton02(void);
	virtual bool GetButton03(void);
	virtual bool GetButton04(void);
	virtual bool GetButton05(void);
	virtual bool GetButton06(void);
	virtual bool GetButton07(void);
	virtual bool GetButton08(void);
	virtual bool GetButton09(void);
	virtual bool GetButton10(void);
	virtual bool GetButton11(void);
	virtual bool GetButton12(void);
	virtual bool GetButton(ButtonType button);
	bool GetRawButton(unsigned button);
	static GamepadL* GetStickForPort(unsigned port);
	
	virtual float GetLeftMagnitude();
	virtual float GetRightMagnitude();
	virtual float GetDpadMagnitude();
	virtual float GetLeftDirectionRadians();
	virtual float GetRightDirectionRadians();
	virtual float GetDpadDirectionRadians();
	virtual float GetLeftDirectionDegrees();
	virtual float GetRightDirectionDegrees();
	virtual float GetDpadDirectionDegrees();

private:
	DISALLOW_COPY_AND_ASSIGN(GamepadL);
	void InitGamepadL(unsigned numAxisTypes, unsigned numButtonTypes);

	DriverStation *m_ds;
	unsigned m_port;
	unsigned *m_axes;
	unsigned *m_buttons;
};

#endif
