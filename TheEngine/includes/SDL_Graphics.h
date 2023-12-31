#pragma once
#include "IGraphics.h"
#include <map>

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;

namespace buki {
	class SDL_Graphics : public IGraphics
	{
	public:
		SDL_Graphics();
		virtual bool Initialize(const std::string& title, int w, int h) override;
		virtual void Shutdown() override;
		virtual void SetColor(const Color& color) override;
		virtual void Clear() override;
		virtual void Present() override;
		virtual void DrawRect(float x, float y, float w, float h, const Color& color) override;
		virtual void DrawRect(const RectF& rect, const Color& color) override;
		virtual void FillRect(float x, float y, float w, float h, const Color& color) override;
		virtual void FillRect(const RectF& rect, const Color& color) override;
		virtual void DrawLine(float x1, float y1, float x2, float y2, const Color& color) override;
		virtual size_t LoadTexture(const std::string& filename) override;
		virtual void DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color) override;
		virtual void DrawTexture(size_t id, const RectF& dst, const Color& color) override;
		virtual void DrawTexture(size_t id, const Color& color) override;
		virtual void GetTextureSize(size_t id, int* w, int* h) override;
		virtual size_t LoadFont(const std::string& filename, int fontSize) override;
		virtual void DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color) override;
		virtual void GetTextSize(const std::string& text, size_t fontId, int* w, int* h) override;
		virtual void DrawCircle(float x, float y, float r, const Color& color) override;
		virtual void DrawPoint(float x, float y, const Color& color) override;
		virtual void GetWindowSize(int* w, int* h) override;
	private:
		SDL_Window* m_Window;
		int m_WindowWidth;
		int m_WindowHeight;
		SDL_Renderer* m_Gfx;
		std::map<size_t, SDL_Texture*> &m_TextureCache = *new std::map<size_t, SDL_Texture*>;
		std::map<size_t, TTF_Font*> &m_FontCache = *new std::map<size_t, TTF_Font*>;
		SDL_Texture* g_TextureBuffer;
	};
}