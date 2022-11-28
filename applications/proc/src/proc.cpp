/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                           *
 *  Ghost, a micro-kernel based operating system for the x86 architecture    *
 *  Copyright (C) 2015, Max Schlüssel <lokoxe@gmail.com>                     *
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

#include <sstream>
#include <stdio.h>
#include <string.h>

#define MAJOR 0
#define MINOR 2
#define PATCH 1

#include "list/list.hpp"

/**
 *
 */
int main(int argc, char** argv)
{

	if(argc > 1)
	{
		char* command = argv[1];

		if(strcmp(command, "-l") == 0 || strcmp(command, "--list") == 0)
		{
			return procList(argc, argv);
		}
		else if(strcmp(command, "-k") == 0 || strcmp(command, "--kill") == 0)
		{
			if(argc > 2)
			{

				for(int arg = 2; arg < argc; arg++)
				{
					std::stringstream conv;
					conv << argv[arg];
					g_tid target;
					if(conv >> target)
					{
						g_kill_status status = g_kill(target);
						if(status == G_KILL_STATUS_SUCCESSFUL)
						{
							println("task %i successfully killed", target);
						}
						else if(status == G_KILL_STATUS_NOT_FOUND)
						{
							println("task %i does not exist", target);
						}
						else
						{
							println("failed to kill task %i with status %i", target, status);
						}
					}
					else
					{
						fprintf(stderr, "invalid task id %s\n", argv[arg]);
					}
				}
			}
		}
		else if(strcmp(command, "--help") == 0)
		{
			println("proc, v%i.%i.%i", MAJOR, MINOR, PATCH);
			println("Task management utility");
			println("");
			println("The following commands are available:");
			println("");
			println("\t-l\t\tlists running tasks");
			println("\t-k <id>\tkills a process");
			println("");
		}
		else
		{
			fprintf(stderr, "unknown command: %s\n", command);
		}
	}
	else
	{
		return procList(argc, argv);
	}
}
