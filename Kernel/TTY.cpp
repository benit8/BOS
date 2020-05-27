/*
** BOS, 2020
** TTY.cpp
*/

#include "TTY.hpp"

////////////////////////////////////////////////////////////////////////////////

TTY::TTY()
{
	setColor(VGA::Color::LightGrey);
	clear();
}

////////////////////////////////////////////////////////////////////////////////

void TTY::clear()
{
	for (size_t y = 0; y < VGA::Height; ++y)
		for (size_t x = 0; x < VGA::Width; ++x)
			m_buffer[y * VGA::Width + x] = VGA::entry(' ', m_color);
}

void TTY::setColor(VGA::Color fg, VGA::Color bg)
{
	m_color = VGA::entryColor(fg, bg);
}

void TTY::put(char c)
{
	switch (c) {
	case '\n':
		m_row++;
		m_column = 0;
		break;
	default:
		m_buffer[m_row * VGA::Width + m_column] = VGA::entry(c, m_color);
		m_column++;
		break;
	}

	if (m_column >= VGA::Width) {
		m_column = 0;
		m_row++;
		if (m_row >= VGA::Height)
			m_row = 0;
	}
}

void TTY::write(const void *data, size_t size)
{
	auto p = static_cast<const uint8_t*>(data);
	for (size_t i = 0; i < size; i++)
		put(p[i]);
}

void TTY::write(const char *str)
{
	for (size_t i = 0; str[i] != '\0'; i++)
		put(str[i]);
}