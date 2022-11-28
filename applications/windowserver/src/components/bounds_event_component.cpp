/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                           *
 *  Ghost, a micro-kernel based operating system for the x86 architecture    *
 *  Copyright (C) 2022, Max Schlüssel <lokoxe@gmail.com>                     *
 *                                                                           *
 *  This program is free software: you can redistribute it and/or modify     *
 *  it under the terms of the GNU General Public License as published by     *
 *  the Free Software Foundation, either version 3 of the License, or        *
 *  (at your option) any later version.                                      *
 *                                                                           *
 *  This program is distributed in the hope that it will be useful,          *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 *  GNU General Public License for more details.                             *
 *                                                                           *
 *  You should have received a copy of the GNU General Public License        *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.    *
 *                                                                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "components/bounds_event_component.hpp"
#include "components/component.hpp"
#include <stdio.h>

void bounds_event_component_t::fireBoundsChange(g_rectangle& bounds)
{
	event_listener_info_t listener_info;
	if(self->getListener(G_UI_COMPONENT_EVENT_TYPE_BOUNDS, listener_info))
	{
		g_ui_component_bounds_event bounds_event;
		bounds_event.header.type = G_UI_COMPONENT_EVENT_TYPE_BOUNDS;
		bounds_event.header.component_id = listener_info.component_id;
		bounds_event.bounds = bounds;
		g_send_message(listener_info.target_thread, &bounds_event, sizeof(g_ui_component_bounds_event));
	}
}
