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

#include <string>

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
	
	enum class Cursor : std::uint8_t {
		// Hide the mouse cursor and constrain its input to the current window.
		HIDDEN = 0,
		
		// Display the cursor normally.
		NORMAL = 1,
	};
	
	class Window : public Input::Handler
	{
	public:
		Window(const Application & application, const Layout & layout = Layout()) : _layout(layout) {}
		virtual ~Window();
		
		const Layout & layout() const noexcept {return _layout;}
		
		// Show the window.
		virtual void show() = 0;
		
		// Hide the window.
		virtual void hide() = 0;
		
		// Close the window.
		virtual void close() = 0;
		
		using Input::Handler::process;
		bool process(const Input::FocusEvent & event) override;
		
		virtual void set_title(const std::string & title);
		const std::string & title() const noexcept {return _title;}
		
		virtual void set_cursor(Cursor cursor);
		Cursor cursor() const noexcept {return _cursor;}
		
		// The scale a pixel w.r.t. the physical display.
		virtual Scale scale() const;
		
	protected:
		Layout _layout;
		std::string _title;
		Cursor _cursor = Cursor::NORMAL;
	};
}
