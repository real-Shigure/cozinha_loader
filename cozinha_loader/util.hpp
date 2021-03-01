#pragma once

namespace util
{
	inline std::string to_lower( std::string str )
	{
		std::transform( str.begin( ), str.end( ), str.begin( ), static_cast< int( * )( int ) >( ::tolower ) );
		return str;
	}

	inline std::string to_upper( std::string str )
	{
		std::transform( str.begin( ), str.end( ), str.begin( ), static_cast< int( * )( int ) >( ::toupper ) );
		return str;
	}

	inline bool read_file_to_memory( const std::string &file_path, std::vector<std::uint8_t> *out_buffer )
	{
		std::ifstream file_ifstream( file_path, std::ios::binary );
		if ( !file_ifstream )
			return false;

		out_buffer->assign( ( std::istreambuf_iterator<char>( file_ifstream ) ), std::istreambuf_iterator<char>( ) );
		file_ifstream.close( );

		return true;
	}
}