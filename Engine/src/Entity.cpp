#include "Entity.h"
#include "RigidBody.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
#include "Engine.h"
#include "BukiContainers.h"
#include "Shapes.h"

buki::Entity::Entity()
	: Entity("new Entity")
{
}

buki::Entity::Entity(std::string _name)
	: m_Name(_name)
{
	transform = new Transform();
	m_PhysicsBodyId = { 0,0,0 };
	m_ShapeId = { 0,0,0 };
}

void buki::Entity::Start()
{
	for (auto it = m_ComponentByType.begin(); it != m_ComponentByType.end(); ++it)
	{
		it->second->Start();
	}
}

void buki::Entity::Draw(float alpha)
{
	/*for (auto c : m_Drawable)
	{
		c->Draw(alpha);
	}*/
	/*for (size_t i = 0; i < m_Drawable.size(); i++)
	{
		m_Drawable[i]->Draw(alpha);
	}*/
	for (auto& drawable : m_Drawable) {
		drawable->Draw(alpha);
	}
}

void buki::Entity::FixedUpdate(float dt)
{
	for (auto c : m_FixedUpdatable)
	{
		c->FixedUpdate(dt);
	}
}

void buki::Entity::Update(float dt)
{
	for (auto c : m_Updatable)
	{
		c->Update(dt);
	}
}

void buki::Entity::Destroy()
{
	for (std::map<const type_info*, Component*>::iterator it = m_ComponentByType.begin(); it != m_ComponentByType.end(); ++it)
	{
		it->second->Destroy();
		delete it->second;
	}
	m_ComponentByType.clear();
	m_Drawable.clear();
	m_Updatable.clear();
	delete transform;
	transform = nullptr;
}

void buki::Entity::Initialize(Vector2 position, float rotation, Vector2 size)
{
	transform->SetPosition(position);
	transform->SetRotation(rotation);
	transform->SetSize(size);
}

void buki::Entity::ActivatePhysics()
{
	if (m_Physics) return;
	if (!GetComponent<RigidBody>())
	{
		AddComponent<RigidBody>();
	}
	m_PhysicsBodyId = Engine::GetInstance().Physics().CreatePhysicsBody(this);
	m_Physics = true;

	Shapes* shape = GetComponentOfType<Shapes>();
	if (shape)
	{
		shape->SetPhysics();
	}
}

void buki::Entity::DeactivatePhysics()
{
	if (!m_Physics) return;
	if (GetComponent<RigidBody>())
	{
		Engine::GetInstance().Physics().DestroyPhysicsBody(m_PhysicsBodyId);
		m_Physics = false;
	}
}
