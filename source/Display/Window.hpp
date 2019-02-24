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

#include <Geometry/Box.hpp>

namespace Display
{
	using Scale = float;
	
	struct Layout
	{
		Layout() {}
		Layout(const Numerics::Vec2 & size) : bounds({0, 0}, size) {}
		
		Geometry::Box2 bounds = {{0, 0}, {640, 480}};
		
		bool center = true;
		bool fullscreen = false;
	};
	
	class Window : public Input::Handler
	{
	public:
		Window(const Application & application, const Layout & layout = Layout()) : _layout(layout) {}
		virtual ~Window();
		
		// Show the window.
		virtual void show() = 0;
		
		// Hide the window.
		virtual void hide() = 0;
		
		// The scale a pixel w.r.t. the physical display.
		virtual Scale scale() const;
		
	protected:
		Layout _layout;
	};
}
