#include "PlayButton.h"
#include "IInput.h"
#include "ICollision.h"
#include "Point2D.h"
#include "Entity.h"
#include "IInput.h"
#include "IWorld.h"
#include "IGraphics.h"

buki::PlayButton::PlayButton(Entity* entity)
	: Component(entity)
{

}

buki::PlayButton::~PlayButton()
{

}

void buki::PlayButton::Update(float dt)
{
	int mouseX, mouseY;
	Point2D pos, size;
	Input().GetMousePosition(&mouseX, &mouseY);
	m_Entity->GetPosition(pos);
	m_Entity->GetSize(size);
	if (Collision().CheckPointRect(static_cast<float>(mouseX), static_cast<float>(mouseY), pos.x, pos.y, size.x, size.y))
	{
		m_Draw = true;
		if (Input().IsButtonPressed(0))
		{
			World().SetLoadScene("Game");
		}
	}
	else
	{
		m_Draw = false;
	}
}

void buki::PlayButton::Draw()
{
	if (!m_Draw) return;
	int mouseX, mouseY;
	Point2D pos, size;
	Input().GetMousePosition(&mouseX, &mouseY);
	m_Entity->GetPosition(pos);
	m_Entity->GetSize(size);
	Graphics().DrawRect(pos.x, pos.y, size.x, size.y, Color::WHITE);
}
