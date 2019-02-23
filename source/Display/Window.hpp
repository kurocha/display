//
//  Window.hpp
//  This file is part of the "Display" project and released under the .
//
//  Created by Samuel Williams on 19/2/2019.
//  Copyright, 2019, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Application.hpp"

#include <Time/Interval.hpp>
#include <Input/Handler.hpp>

namespace Display
{
	using Scale = float;
	
	class Window : public Input::Handler
	{
	public:
		Window(const Application & application) {}
		virtual ~Window();
		
		// Show the window.
		virtual void show() = 0;
		
		// Hide the window.
		virtual void hide() = 0;
		
		// The scale a pixel w.r.t. the physical display.
		virtual Scale scale() const;
	};
}
