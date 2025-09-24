#include "Input.h"

void Input::setControllerButtonDown(int input_id, bool state)
{

	switch (input_id)
	{
	case(0):b_button_down = state;
		break;
	case(1):a_button_down = state;
		break;
	case(2):y_button_down = state;
		break;
	case(3):x_button_down = state;
		break;
	case(4):left_bumper_down = state;
		break;
	case(5):right_bumper_down = state;
		break;
	case(6):select_button_down = state;
		break;
	case(7):start_button_down = state;
		break;
	case(8):lstick_button_down = state;
		break;
	case(9):rstick_button_down = state;
		break;
	default:
		break;
	}
}

void Input::setJoystickAxis(sf::Joystick::Axis axis, float value)
{
	switch (axis)
	{
	case(sf::Joystick::Axis::X): //X axis (l stick)
		left_joystick.x = value;
		break;
	case(sf::Joystick::Axis::Y): //Y axis (l stick)
		left_joystick.y = value;
		break;
	case(sf::Joystick::Axis::U): //U axis (r stick)
		right_joystick.x = value;
		break;
	case(sf::Joystick::Axis::V): //V axis (r stick)
		right_joystick.y = value;
		break;
	case(sf::Joystick::Axis::Z): //Z Axis, triggers, r tigger is negative, l trigger is positive // Unfortunatley only supports one trigger being used at a time
		if (value >= trigger_tolerance)
		{
			left_trigger = true;
		}
		else
		{
			left_trigger = false;
		}

		if (value <= -trigger_tolerance)
		{
			right_trigger = true;
		}
		else {
			right_trigger = false;
		}
		break;
	case(sf::Joystick::Axis::PovX):
		if (value >= 50)
		{
			dpad_right = true;
		}
		else
		{
			dpad_right = false;
		}

		if (value <= -50)
		{
			dpad_left = true;
		}
		else
		{
			dpad_left = false;
		}
		break;
	case(sf::Joystick::Axis::PovY):
		if (value >= 50)
		{
			dpad_up = true;
		}
		else
		{
			dpad_up = false;
		}

		if (value <= -50)
		{
			dpad_down = true;
		}
		else
		{
			dpad_down = false;
		}
		break;
	default:
		break;
	}
}

