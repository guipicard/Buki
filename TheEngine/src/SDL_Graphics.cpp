#include "SDL_Graphics.h"
#include "SDL.h"
#include "Engine.h"
#include <SDL_image.h>
#include <SDL_ttf.h>

buki::SDL_Graphics::SDL_Graphics()
	: m_Gfx(nullptr)
	, m_Window(nullptr)
	, g_TextureBuffer(nullptr)
	, m_WindowWidth(0)
	, m_WindowHeight(0)
{

}

bool buki::SDL_Graphics::Initialize(const std::string& title, int w, int h)
{
	int _x SDL_WINDOWPOS_CENTERED;
	int _y = SDL_WINDOWPOS_CENTERED;
	Uint32 _flag = SDL_WINDOW_RESIZABLE;
	Uint32 _rendererFlag = SDL_RENDERER_ACCELERATED;
	m_WindowWidth = w;
	m_WindowHeight = h;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		buki::Engine::GetInstance()->Log().LogError(SDL_GetError());
		return false;
	}

	m_Window = SDL_CreateWindow(title.c_str(), _x, _y, w, h, _flag);

	if (!m_Window)
	{
		//m_Console->LogError(SDL_GetError());
		return false;
	}
	//m_Console->LogSuccess("Window initialised");
	m_Gfx = SDL_CreateRenderer(m_Window, -1, _rendererFlag);

	if (!m_Gfx)
	{
		//m_Console->LogError(SDL_GetError());
		return false;
	}
	//m_Console->LogSuccess("Renderer initialised");
	TTF_Init();
	//TTF_Font* Base_Font = TTF_OpenFont(filename.c_str(), fontSize);
	//m_FontCache.emplace(, Base_Font)

	return true;
}

void buki::SDL_Graphics::Shutdown()
{
	for (std::map<size_t, SDL_Texture*>::iterator it = m_TextureCache.begin(); it != m_TextureCache.end(); ++it)
	{
		if (it->second != nullptr)
		{
			SDL_DestroyTexture(it->second);
			it->second = nullptr;
		}
	}
	delete &m_TextureCache;

	for (std::map<size_t, TTF_Font*>::iterator it = m_FontCache.begin(); it != m_FontCache.end(); ++it)
	{
		if (it->second != nullptr)
		{
			TTF_CloseFont(it->second);
			it->second = nullptr;
		}
	}
	TTF_Quit();
	delete& m_FontCache;

	if (m_Gfx != nullptr)
	{
		SDL_DestroyRenderer(m_Gfx);
		m_Gfx = nullptr;
	}

	if (m_Window != nullptr)
	{
		SDL_DestroyWindow(m_Window);
		m_Window = nullptr;
	}
	

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
	SDL_Rect _rect{ 0 };
	_rect.x = static_cast<int>(x);
	_rect.y = static_cast<int>(y);
	_rect.h = static_cast<int>(h);
	_rect.w = static_cast<int>(w);
	SetColor(color);
	SDL_RenderDrawRect(m_Gfx, &_rect);
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
	SDL_Rect _rect{ 0 };
	_rect.x = static_cast<int>(x);
	_rect.y = static_cast<int>(y);
	_rect.h = static_cast<int>(h);
	_rect.w = static_cast<int>(w);
	SetColor(color);
	SDL_RenderFillRect(m_Gfx, &_rect);
}

void buki::SDL_Graphics::FillRect(const RectF& rect, const Color& color)
{
	SDL_Rect _rect{ 0 };
	_rect.x = static_cast<int>(rect.x);
	_rect.y = static_cast<int>(rect.y);
	_rect.h = static_cast<int>(rect.h);
	_rect.w = static_cast<int>(rect.w);
	SetColor(color);
	SDL_RenderFillRect(m_Gfx, &_rect);
}

void buki::SDL_Graphics::DrawLine(float x1, float y1, float x2, float y2, const Color& color)
{
	int _x1 = static_cast<int>(x1);
	int _x2 = static_cast<int>(x2);
	int _y1 = static_cast<int>(y1);
	int _y2 = static_cast<int>(y2);
	SetColor(color);
	SDL_RenderDrawLine(m_Gfx, _x1, _x2, _y1, _y2);
}

size_t buki::SDL_Graphics::LoadTexture(const std::string& filename)
{
	const size_t id = std::hash<std::string>()(filename);
	if (m_TextureCache.count(id) > 0)
	{
		return id;
	}

	SDL_Texture* texture = IMG_LoadTexture(m_Gfx, filename.c_str());
	if (texture != nullptr)
	{
		m_TextureCache[id] = texture;
		return id;
	}
	buki::Engine::GetInstance()->Log().LogError("did not load image");
	return -1;
}

void buki::SDL_Graphics::DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color)
{
	SDL_Texture* _texture = m_TextureCache[id];
	SDL_Rect source{ 0 };
	source.x = src.x;
	source.y = src.y;
	source.h = src.h;
	source.w = src.w;

	SDL_Rect dest{ 0 };
	dest.x = static_cast<int>(dst.x);
	dest.y = static_cast<int>(dst.y);
	dest.h = static_cast<int>(dst.h);
	dest.w = static_cast<int>(dst.w);

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
	SDL_Rect dstrect{ 0 };
	dstrect.x = static_cast<int>(dst.x);
	dstrect.y = static_cast<int>(dst.y);
	dstrect.h = static_cast<int>(dst.h);
	dstrect.w = static_cast<int>(dst.w);

	SetColor(color);

	SDL_RenderCopyEx(m_Gfx, _texture, nullptr, &dstrect, 0, nullptr, SDL_FLIP_NONE);
}

void buki::SDL_Graphics::DrawTexture(size_t id, const Color& color)
{
	SDL_Texture* _texture = m_TextureCache[id];
	SDL_Rect _rect{ 0 };
	_rect.x = 0;
	_rect.y = 0;
	GetTextureSize(id, &_rect.w, &_rect.h);
	SetColor(color);

	SDL_RenderCopyEx(m_Gfx, _texture, nullptr, &_rect, 0, nullptr, SDL_FLIP_NONE);
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
	const size_t id = std::hash<std::string>()(filename);
	if (m_FontCache.count(id) > 0)
	{
		return id;
	}
	TTF_Font* _font = TTF_OpenFont(filename.c_str(), fontSize);
	if (_font != nullptr)
	{
		m_FontCache[id] = _font;
		return id;
	}
	return -1;
}

void buki::SDL_Graphics::DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color)
{
	SDL_Color _color = { color.r, color.g, color.b, color.a };
	int w = 0;
	int h = 0;
	GetTextSize(text, fontId, &w, &h);
	SDL_Rect _dst = { static_cast<int>(x), static_cast<int>(y), w, h };
	if (m_FontCache.count(fontId) > 0)
	{
		TTF_Font* _font = m_FontCache[fontId];
		SDL_Surface* _surface = TTF_RenderText_Solid(_font, text.c_str(), _color);
		
		g_TextureBuffer = SDL_CreateTextureFromSurface(m_Gfx, _surface);
		SDL_RenderCopy(m_Gfx, g_TextureBuffer, nullptr, &_dst);
		SDL_FreeSurface(_surface);
	}
}

void buki::SDL_Graphics::GetTextSize(const std::string& text, size_t fontId, int* w, int* h)
{
	if (m_FontCache.count(fontId) > 0)
	{
		TTF_Font* _font = m_FontCache[fontId];
		TTF_SizeText(_font, text.c_str(), w, h);
	}
	else
	{
		*w = 0;
		*h = 0;
	}
}

void buki::SDL_Graphics::GetWindowSize(int* w, int* h)
{
	SDL_GetWindowSize(m_Window, w, h);
}
