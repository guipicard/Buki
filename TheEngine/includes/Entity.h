#pragma once
#include <string>
#include <map>
#include <vector>
#include <Component.h>
#include <IUpdatable.h>
#include <IDrawable.h>
#include <RectF.h>
#include <Point2D.h>

namespace buki
{
	class Entity final
	{
	public:
		virtual ~Entity() = default;
		Entity();
		Entity(std::string _name);
		virtual void Start();
		void Draw();
		void Update(float dt);
		void Destroy();

		std::string GetName() { return m_Name; }
		void SetPos(Point2D _pos) { m_X = _pos.x, m_Y = _pos.y; }
		void SetSize(Point2D _size) { m_W = _size.x; m_H = _size.y; }
		void Scale(float dw, float dh)
		{
			m_W *= dw;
			m_H *= dh;
		}
		void Rotate(double angle)
		{
			m_Angle += angle;
		}
		float GetX() const { return m_X; }
		float GetY() const { return m_Y; }
		void SetRotation(double angle) { m_Angle = angle; }
		double GetRotation() const { return m_Angle; }
		void GetPosition(Point2D* point) { *point = Point2D(m_X, m_Y); }
		void GetSize(Point2D* point) { *point = Point2D(m_W, m_H); }
		void GetRect(RectF* rect) { *rect = { m_X, m_Y, m_W, m_H }; }

		template<typename T>
		T* AddComponent()
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
		T* GetComponent()
		{
			const type_info* type = &typeid(T);
			auto it = m_ComponentByType.find(type);
			if (it != m_ComponentByType.end())
			{
				return dynamic_cast<T*>(it->second);
			}
			return nullptr;
		}

	protected:
		std::string m_Name;

		std::map<const type_info*, Component*> m_ComponentByType;
		std::vector<IDrawable*> m_Drawable;
		std::vector<IUpdatable*> m_Updatable;

		float m_X = 0.0f;
		float m_Y = 0.0f;
		double m_Angle = 0.0f;
		float m_W = 1.0f;
		float m_H = 1.0f;
	};
}
