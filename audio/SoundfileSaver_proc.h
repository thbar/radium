/* Copyright 2012 Kjetil S. Matheussen

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA. */


enum SOUNDFILESAVER_what{
  SAVE_SONG,
  SAVE_BLOCK,
};

extern LANGSPEC bool SOUNDFILESAVER_write(float **outputs, int num_frames);
extern LANGSPEC bool SOUNDFILESAVER_stop(void);
extern LANGSPEC void SOUNDFILESAVER_start(void);
extern LANGSPEC bool SOUNDFILESAVER_save(const char *filename, enum SOUNDFILESAVER_what what_to_save, float samplerate, int libsndfile_format, float post_recording_length, const char **error_string);
