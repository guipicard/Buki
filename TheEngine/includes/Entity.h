#pragma once
#include "IGraphics.h"
#include "Component.h"
#include <vector>
#include <map>
#include <typeinfo>

namespace buki
{
	struct Point2D
	{
		Point2D() : Point2D(0, 0) {}
		Point2D(int _x, int _y) : Point2D(static_cast<float>(_x), static_cast<float>(_y)) {}
		Point2D(float _x, float _y) : x(_x), y(_y) {}
		float x;
		float y;
	};

	class Entity final
	{
	public:
		Entity();
		Entity(std::string _name, float _x, float _y, float _h, float _w);
		~Entity();
		template<typename T> inline T* AddComponent();
		template<typename T> inline T* GetComponent();
		void Draw();
		void Update(float dt);
		void Destroy();
		void SetPos(Point2D _pos) { m_X = _pos.x, m_Y = _pos.y; }
		void SetSize(Point2D _size) { m_H = _size.x, m_W = _size.y; }
		Point2D GetPos() { return Point2D(m_X, m_Y); }
		Point2D GetSize() { return Point2D(m_H, m_W); }
		std::string GetName() { return m_Name; }
		float GetSpeed() { return m_Speed; }
		void SetSpeed(float speed) { m_Speed = speed; }
	private:
		std::vector<IDrawable*>& m_Drawable = *new std::vector<IDrawable*>();
		std::vector<IUpdatable*>& m_Updatable = *new std::vector<IUpdatable*>();
		std::map<std::string, Component*>& m_ComponentByType = *new std::map<std::string, Component*>();

	private:
		float m_Speed = 50.0f;
		float m_X = 0.0f;
		float m_Y = 0.0f;
		float m_H = 0.0f;
		float m_W = 0.0f;
		std::string m_Name;
	};

	template<typename T>
	inline T* Entity::AddComponent()
	{
		T* cmp = new T(this);
		m_ComponentByType[typeid(T).name()] = cmp;

		if constexpr (std::is_base_of_v<IDrawable, T>) 
		{
			m_Drawable.push_back(cmp);
		}

		if constexpr (std::is_base_of_v<IUpdatable, T>)
		{
			m_Updatable.push_back(cmp);
		}
		return cmp;
	}

	template<typename T>
	inline T* Entity::GetComponent()
	{
		const std::string type = typeid(T).name();
		auto it = m_ComponentByType.find(type);
		if (it != m_ComponentByType.end()) 
		{
			return dynamic_cast<T*>(it->second);
		}
		return nullptr;
	}
}