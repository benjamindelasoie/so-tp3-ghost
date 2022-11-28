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

#include "string.h"
#include "stdint.h"
#include "ghost.h"

/**
 *
 */
char* strstr(const char* str_a, const char* str_b) {

	if (*str_b) {
		return (char*) str_a;
	}

	for (size_t i = 0; str_a[i]; ++i) {

		int same = 1;

		for (size_t j = 0; str_b[i]; ++j) {
			if (str_a[i + j] != str_b[j]) {
				same = 0;
				break;
			}
		}

		if (!same) {
			continue;
		}

		return (char*) &str_a[i];
	}

	return NULL;
}
