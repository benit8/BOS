/*
** BOS, 2020
** VGA.hpp
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stddef.h>
#include <stdint.h>

////////////////////////////////////////////////////////////////////////////////

namespace VGA
{

////////////////////////////////////////////////////////////////////////////////

const size_t Width = 80;
const size_t Height = 25;

////////////////////////////////////////////////////////////////////////////////

enum Color : uint8_t
{
	Black        = 0,
	Blue         = 1,
	Green        = 2,
	Cyan         = 3,
	Red          = 4,
	Magenta      = 5,
	Brown        = 6,
	LightGrey    = 7,
	DarkGrey     = 8,
	LightBlue    = 9,
	LightGreen   = 10,
	LightCyan    = 11,
	LightRed     = 12,
	LightMagenta = 13,
	LightBrown   = 14,
	White        = 15,
};

////////////////////////////////////////////////////////////////////////////////

inline Color entryColor(Color fg, Color bg)
{
	return (Color)(fg | bg << 4);
}

inline uint16_t entry(unsigned char uc, Color fg)
{
	return (uint16_t)uc | (uint16_t)fg << 8;
}

inline uint16_t entry(unsigned char uc, Color fg, Color bg)
{
	return (uint16_t)uc | (uint16_t)entryColor(fg, bg) << 8;
}

////////////////////////////////////////////////////////////////////////////////

}