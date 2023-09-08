#include "Square.h"
#include <SDL.h>

buki::Square::Square(float _x, float _y, float _h, float _w, SDL_Renderer* _renderer)
	: m_x(_x)
	, m_y(_y)
	, m_h(_h)
	, m_w(_w)
	, m_Renderer(_renderer)
{
}

void buki::Square::Draw()
{
	SDL_Rect get_rect = { 0 };
	get_rect.x = m_x;
	get_rect.y = m_y;
	get_rect.h = m_h;
	get_rect.w = m_w;
	SDL_RenderDrawRect(m_Renderer, &get_rect);
}

void buki::Square::SetPosition(float x, float y)
{
	m_x = x;
	m_y = y;
}
