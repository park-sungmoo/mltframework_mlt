/**
 * MltConsumer.cpp - MLT Wrapper
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

#include "MltConsumer.h"
using namespace Mlt;

Consumer::Consumer( char *id, char *service ) :
	destroy( true ),
	instance( NULL )
{
	instance = mlt_factory_consumer( id, service );
}

Consumer::Consumer( Consumer &consumer ) :
	destroy( false ),
	instance( consumer.get_consumer( ) )
{
}

Consumer::Consumer( mlt_consumer consumer ) :
	destroy( false ),
	instance( consumer )
{
}

Consumer::~Consumer( )
{
	if ( destroy )
	{
		stop( );
		mlt_consumer_close( instance );
	}
}

mlt_consumer Consumer::get_consumer( )
{
	return instance;
}

mlt_service Consumer::get_service( )
{
	return mlt_consumer_service( get_consumer( ) );
}

int Consumer::connect( Service &service )
{
	return connect_producer( service );
}

int Consumer::start( )
{
	return mlt_consumer_start( get_consumer( ) );
}

int Consumer::stop( )
{
	return mlt_consumer_stop( get_consumer( ) );
}

bool Consumer::is_stopped( )
{
	return mlt_consumer_is_stopped( get_consumer( ) ) != 0;
}

