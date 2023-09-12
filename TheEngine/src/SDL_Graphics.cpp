#include "SDL_Graphics.h"

buki::SDL_Graphics::SDL_Graphics(SDL_Renderer* _renderer)
	:m_Gfx(_renderer)
{
}

bool buki::SDL_Graphics::Initialize(const std::string& title, int w, int h)
{

	return false;
}

void buki::SDL_Graphics::Shutdown()
{
}

void buki::SDL_Graphics::SetColor(const Color& color)
{
	SDL_SetRenderDrawColor(m_Gfx, color.r, color.g, color.b, color.a);
}

void buki::SDL_Graphics::Clear()
{
	SDL_RenderClear(m_Gfx);
}

void buki::SDL_Graphics::Present()
{
	SDL_RenderPresent(m_Gfx);
}

void buki::SDL_Graphics::DrawRect(float x, float y, float w, float h, const Color& color)
{
}

void buki::SDL_Graphics::DrawRect(const RectF& rect, const Color& color)
{
	SDL_Rect _rect{ 0 };
	_rect.x = static_cast<int>(rect.x);
	_rect.y = static_cast<int>(rect.y);
	_rect.h = static_cast<int>(rect.h);
	_rect.w = static_cast<int>(rect.w);
	SetColor(color);
	SDL_RenderDrawRect(m_Gfx, &_rect);
}

void buki::SDL_Graphics::FillRect(float x, float y, float w, float h, const Color& color)
{
}

void buki::SDL_Graphics::FillRect(const RectF& rect, const Color& color)
{
}

void buki::SDL_Graphics::DrawLine(float x1, float y1, float x2, float y2, const Color& color)
{
}

size_t buki::SDL_Graphics::LoadTexture(const std::string& filename)
{
	const size_t id = std::hash<std::string>()(filename);
	if (m_TextureCache.count(id) > 0)
	{
		return id;
	}

	SDL_Texture* texture = IMG_LoadTexture(m_Gfx , filename.c_str());
	if (texture != nullptr)
	{
		m_TextureCache[id] = texture;
		return id;
	}
	return -1;
}

void buki::SDL_Graphics::DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color)
{
	SDL_Texture* _texture = m_TextureCache[id];
	SDL_Rect source{ 0 };
	source.x = static_cast<int>(src.x);
	source.y = static_cast<int>(src.y);
	source.h = static_cast<int>(src.h);
	source.w = static_cast<int>(src.w);

	SDL_Rect dest{ 0 };
	dest.x = dst.x;
	dest.y = dst.y;
	dest.h = dst.h;
	dest.w = dst.w;

	SetColor(color);

	SDL_RendererFlip _flip;
	if (flip.h)
	{
		_flip = SDL_FLIP_HORIZONTAL;
	}
	else if (flip.v)
	{
		_flip = SDL_FLIP_VERTICAL;
	}
	else
	{
		_flip = SDL_FLIP_NONE;
	}

	SDL_RenderCopyEx(m_Gfx, _texture, &source, &dest, angle, nullptr, _flip);
}

void buki::SDL_Graphics::DrawTexture(size_t id, const RectF& dst, const Color& color)
{
	SDL_Texture* _texture = m_TextureCache[id];
	SDL_Rect _rect{ 0 };
	_rect.x = static_cast<int>(dst.x);
	_rect.y = static_cast<int>(dst.y);
	_rect.h = static_cast<int>(dst.h);
	_rect.w = static_cast<int>(dst.w);
	GetTextureSize(id, &_rect.w, &_rect.h);

	SetColor(color);

	SDL_RenderCopyEx(m_Gfx, _texture, &_rect, nullptr, 0, nullptr, SDL_FLIP_NONE);
}

void buki::SDL_Graphics::DrawTexture(size_t id, const Color& color)
{
	SDL_Texture* _texture = m_TextureCache[id];

	SetColor(color);

	SDL_RenderCopyEx(m_Gfx, _texture, nullptr, nullptr, 0, nullptr, SDL_FLIP_NONE);
}

void buki::SDL_Graphics::GetTextureSize(size_t id, int* w, int* h)
{
	if (m_TextureCache.count(id) > 0)
	{
		SDL_Texture* _tex = m_TextureCache[id];
		SDL_QueryTexture(_tex, nullptr, nullptr, w, h);
	}
	else
	{
		*w = 0;
		*h = 0;
	}
}

size_t buki::SDL_Graphics::LoadFont(const std::string& filename, int fontSize)
{
	return size_t();
}

void buki::SDL_Graphics::DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color)
{
}

void buki::SDL_Graphics::GetTextSize(const std::string& text, size_t fontId, int* w, int* h)
{
}
