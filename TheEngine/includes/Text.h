#pragma once

#include "Sprite.h"

namespace buki
{
	class Text : public Sprite
	{
	public:
		Text(Entity* _entity);
		virtual ~Text();
		virtual void Draw() override;
		virtual void Load(const std::string& path) override;
		void SetText(std::string _text) { m_Text = _text; }
	private:
		std::string m_Text = "";
		size_t m_Id = 0;
	};
}