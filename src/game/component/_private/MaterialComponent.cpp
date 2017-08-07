#include "MaterialComponent.h"
#include "DrawComponent.h"

MaterialComponent::MaterialComponent(Entity entity) :
	IComponent(entity), m_T(0.f),
	m_Time(0.f), m_ScrollRate(0.f),
	m_AddColor(0, 0, 0, 0),
	m_MultColor(1, 1, 1, 1)
{
}

MaterialComponent::~MaterialComponent()
{
}

void MaterialComponent::SetAddColor(glm::vec4 &&addColor)
{
	ASSERT_CHECK(m_Entity != nullEntity, );
	m_AddColor = addColor;
}

void MaterialComponent::SetMultColor(glm::vec4 &&multColor)
{
	ASSERT_CHECK(m_Entity != nullEntity, );
	m_MultColor = multColor;
}


void MaterialComponent::SetMultColor(glm::vec3 &&multColor)
{
	ASSERT_CHECK(m_Entity != nullEntity, );
	m_MultColor = glm::vec4(multColor, m_MultColor[3]);
}

bool MaterialComponent::SetOpacity(float opacity)
{
	ASSERT_CHECK(m_Entity != nullEntity, false);
	m_MultColor[3] = opacity;
	return IncrementOpacity(0.f);
}

bool MaterialComponent::IncrementOpacity(float delta)
{
	ASSERT_CHECK(m_Entity != nullEntity, false);
	float &opacity = m_MultColor[3];
	opacity += delta;

	if(opacity < 0.f)
	{
		opacity = 0.f;
		return true;
	}
	else if(opacity > 1.f)
	{
		opacity = 1.f;
		return true;
	}

	return false;
}

void MaterialComponent::FadeIn(deltaTime_t fadeTime)
{
	ASSERT_CHECK(m_Entity != nullEntity, );
	DEBUG_ASSERT(fadeTime > 0.f);
	m_T = fadeTime;
}

void MaterialComponent::FadeOut(deltaTime_t fadeTime)
{
	ASSERT_CHECK(m_Entity != nullEntity, );
	DEBUG_ASSERT(fadeTime > 0.f);
	m_T = -1.f * fadeTime;
}

void MaterialComponent::Refresh()
{
}

void MaterialComponent::Tick(deltaTime_t dt)
{
	if(m_T != 0.f)
	{
	    m_T *= !(IncrementOpacity(dt/m_T));
	}

	if(m_ScrollRate != 0.f)
	{
		m_Time += m_ScrollRate * dt;
	}
}
