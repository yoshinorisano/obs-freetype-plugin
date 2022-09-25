/*
Plugin Name
Copyright (C) <Year> <Developer> <Email Address>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program. If not, see <https://www.gnu.org/licenses/>
*/

#include <obs-module.h>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "plugin-macros.generated.h"

OBS_DECLARE_MODULE()
OBS_MODULE_USE_DEFAULT_LOCALE(PLUGIN_NAME, "en-US")

bool obs_module_load(void)
{
	blog(LOG_INFO, "plugin loaded successfully (version %s)",
	     PLUGIN_VERSION);

	FT_Library library;
	FT_Face face;
	FT_Error error;

	error = FT_Init_FreeType(&library);
	if (error) {
		return false;
	}

	const char *filename = "C:\\Windows\\Fonts\\arial.ttf";

	error = FT_New_Face(library, filename, 0, &face);
	if (error) {
		FT_Done_FreeType(library);
		return false;
	}

	FT_Done_Face(face);
	FT_Done_FreeType(library);

	return true;
}

void obs_module_unload()
{
	blog(LOG_INFO, "plugin unloaded");
}
