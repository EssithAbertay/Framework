#include "SFML/Window.hpp"
#include <iostream>

#pragma once
class Input
{
public:

	void setControllerButtonDown(int input_id, bool state);
	void setJoystickAxis(sf::Joystick::Axis axis, float value);


	bool a_button_down = false;
	bool b_button_down = false;
	bool x_button_down = false;
	bool y_button_down = false;

	bool left_bumper_down = false;
	bool right_bumper_down = false;

	bool select_button_down = false;
	bool start_button_down = false;

	bool lstick_button_down = false;
	bool rstick_button_down = false;

	bool left_trigger = false;
	bool right_trigger = false;


	bool dpad_down = false;
	bool dpad_up = false;
	bool dpad_left = false;
	bool dpad_right = false;



	sf::Vector2f left_joystick = {0,0};
	sf::Vector2f right_joystick = {0,0};

protected:
	float dpad_tolerance = 50;	
	float trigger_tolerance = 50;
};

