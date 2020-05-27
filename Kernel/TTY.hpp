/*
** BOS, 2020
** TTY.hpp
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include "VGA.hpp"

////////////////////////////////////////////////////////////////////////////////

class TTY
{
public:
	TTY();
	~TTY() = default;

	void setColor(VGA::Color fg, VGA::Color bg = VGA::Color::Black);

	void clear();
	void put(char c);
	void write(const void *data, size_t size);
	void write(const char *str);

private:
	size_t m_row = 0;
	size_t m_column = 0;
	VGA::Color m_color;
	uint16_t *m_buffer = (uint16_t*)0xB8000;
};