/**
 * MltPlaylist.h - MLT Wrapper
 * Copyright (C) 2004-2005 Charles Yates
 * Author: Charles Yates <charles.yates@pandora.be>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef _MLTPP_PLAYLIST_H_
#define _MLTPP_PLAYLIST_H_

#include <framework/mlt.h>

#include "MltProducer.h"

namespace Mlt
{
	class Producer;
	class Service;
	class Playlist;
	class Transition;

	class ClipInfo
	{
		public:
			ClipInfo( );
			ClipInfo( mlt_playlist_clip_info *info );
			~ClipInfo( );
			void update( mlt_playlist_clip_info *info );
			int clip;
			Producer *producer;
			Producer *cut;
			int start;
			char *resource;
			int frame_in;
			int frame_out;
			int frame_count;
			int length;
			float fps;
			int repeat;
	};

	class Playlist : public Producer
	{
		private:
			mlt_playlist instance;
		public:
			Playlist( );
			Playlist( Service &playlist );
			Playlist( Playlist &playlist );
			Playlist( mlt_playlist playlist );
			virtual ~Playlist( );
			virtual mlt_playlist get_playlist( );
			mlt_producer get_producer( );
			int count( );
			int clear( );
			int append( Producer &producer, int in = -1, int out = -1 );
			int blank( int length );
			int clip( mlt_whence whence, int index );
			int current_clip( );
			Producer *current( );
			ClipInfo *clip_info( int index, ClipInfo *info = NULL );
			int insert( Producer &producer, int where, int in = -1, int out = -1 );
			int remove( int where );
			int move( int from, int to );
			int resize_clip( int clip, int in, int out );
			int split( int clip, int position );
			int join( int clip, int count = 1, int merge = 1 );
			int mix( int clip, int length, Transition *transition = NULL );
			int mix_add( int clip, Transition *transition );
			int repeat( int clip, int count );
			Producer *get_clip( int clip );
			Producer *get_clip_at( int position );
			int get_clip_index_at( int position );
			bool is_mix( int clip );
			bool is_blank( int clip );
			void consolidate_blanks( int keep_length = 0 );
			Producer *replace_with_blank( int clip );
	};
}

#endif
