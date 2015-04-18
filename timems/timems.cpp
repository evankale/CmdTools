/*
 * Copyright (c) 2015 Evan Kale
 * Email: EvanKale91@gmail.com
 * Website: www.ISeeDeadPixel.com
 *          www.evankale.blogspot.ca
 *
 * This file is part of CmdTools.
 *
 * CmdTools is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <Windows.h>

#define COMMAND_LENGTH 2048

int main(int argc, char** argv)
{
	if(argc == 1)
	{
		printf("Current Time (ms) : %i\n", GetTickCount());
	}
	else
	{
		char command[COMMAND_LENGTH];
		memset(command,0,COMMAND_LENGTH);

		char * pos = command;

		for(int i=1; i<argc; ++i)
		{
			int loc = sprintf(pos," %s",argv[i]);
			pos += loc;
		}

		long startTime = GetTickCount();
		system(command);
		unsigned int deltaTime = GetTickCount() - startTime;

		printf("Time taken (ms) : %i\n", deltaTime);
	}

	return 0;
}