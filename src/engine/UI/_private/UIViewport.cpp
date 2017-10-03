#include "UI/UIViewport.h"
#include "MaterialComponent.h"

UIViewport::UIViewport(Entity entity) :
	UIComponent(entity),
	m_pCamera(nullptr), m_pScreen(nullptr)
{
	m_Priority = 0;
}

void UIViewport::Refresh()
{
	UIComponent::Refresh();

	//
	// Bypassing the const-ness because we can't make m_pMaterialComp a const pointer
	// (other UIComponent types may want to modify their material components)
	//
	m_pMaterialComp = (MaterialComponent*)&MaterialComponent::GetDefaultTransparent();
}