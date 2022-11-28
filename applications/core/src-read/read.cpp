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

#include <ghost.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/**
 *
 */
int main(int argc, char** argv)
{

	if(argc >= 2)
	{
		char* filepath = argv[1];

		FILE* file = fopen(filepath, "r");

		if(file == NULL)
		{
			fprintf(stderr, "File not found: %s\n", filepath);
		}
		else
		{
			uint32_t bufsize = 4096;
			uint8_t* buf = new uint8_t[bufsize];

			ssize_t len;
			while((len = fread(buf, 1, bufsize, file)) > 0)
			{
				fwrite(buf, 1, len, stdout);
			}
			fflush(stdout);

			fclose(file);
		}
	}
	else
	{
		fprintf(stderr, "Usage:\tread <filename>\n");
	}
}
