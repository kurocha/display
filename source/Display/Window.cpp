//
//  Window.cpp
//  This file is part of the "Display" project and released under the .
//
//  Created by Samuel Williams on 19/2/2019.
//  Copyright, 2019, by Samuel Williams. All rights reserved.
//

#include "Window.hpp"

#include <Input/FocusEvent.hpp>

namespace Display
{
	Window::~Window()
	{
	}
	
	Scale Window::scale() const
	{
		return 1.0;
	}
	
	bool Window::process(const Input::FocusEvent & event)
	{
		if (event.flags() & Input::FocusEvent::CLOSED) {
			this->hide();
		}
		
		return true;
	}
	
	void Window::set_title(const std::string & title)
	{
		_title = title;
	}
	
	void Window::set_cursor(Cursor cursor)
	{
		_cursor = cursor;
	}
}
