#pragma once
#include <vector>
#include <map>
#include <string>
#include <typeinfo>
#include "IDrawable.h"
#include "IUpdatable.h"

namespace buki
{
	class Component;
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
		Entity(std::string _name, float _x, float _y, float _w, float _h);
		~Entity();
		template<typename T> inline T* AddComponent();
		template<typename T> inline T* GetComponent();
		template<typename T> inline std::vector<T*> GetAllComponents();
		void Draw();
		void Update(float dt);
		void Destroy();
		void SetPos(Point2D _pos) { m_X = _pos.x, m_Y = _pos.y; }
		void SetSize(Point2D _size) { m_W = _size.x; m_H = _size.y; }
		Point2D GetPos() { return Point2D(m_X, m_Y); }
		Point2D GetSize() { return Point2D(m_W, m_H); }
		std::string GetName() { return m_Name; }
		float GetSpeed() { return m_Speed; }
		void SetSpeed(float speed) { m_Speed = speed; }
	private:
		std::vector<IDrawable*>& m_Drawable = *new std::vector<IDrawable*>();
		std::vector<IUpdatable*>& m_Updatable = *new std::vector<IUpdatable*>();
		std::multimap<const type_info*, Component*>& m_ComponentByType = *new std::multimap<const type_info*, Component*>();

	private:
		float m_Speed = 50.0f;
		float m_X = 0.0f;
		float m_Y = 0.0f;
		float m_W = 0.0f;
		float m_H = 0.0f;
		std::string m_Name;
	};

	template<typename T>
	inline T* Entity::AddComponent()
	{
		T* cmp = new T(this);
		m_ComponentByType.emplace(&typeid(T), cmp);

		IDrawable* drawable = dynamic_cast<IDrawable*>(cmp);
		if (drawable != nullptr) 
		{
			m_Drawable.push_back(drawable);
		}

		IUpdatable* updatable = dynamic_cast<IUpdatable*>(cmp);
		if (updatable != nullptr)
		{
			m_Updatable.push_back(updatable);
		}
		return cmp;
	}

	template<typename T>
	inline T* Entity::GetComponent()
	{
		const type_info* type = &typeid(T);
		auto it = m_ComponentByType.find(type);
		if (it != m_ComponentByType.end())
		{
			return dynamic_cast<T*>(it->second);
		}
		return nullptr;
	}

	template<typename T>
	inline std::vector<T*> Entity::GetAllComponents()
	{
		std::vector<T*> results;
		const type_info* type = &typeid(T);
		for (auto it : m_ComponentByType)
		{
			if (it.first == type)
			{
				results.push_back(dynamic_cast<T*>(it.second));
			}
		}
		return results;
	}

}
