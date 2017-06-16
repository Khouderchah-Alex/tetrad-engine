#pragma once

#include "Base.h"
#include "IComponent.h"

class TransformComponent;

/**
 * @brief Component to attach this entity to another
 *
 * @note Requires the parent entity to have a TransformComponent
 */
class AttachComponent : public IComponent
{
public:
	AttachComponent(Entity entity);
	~AttachComponent();

	void Refresh();

	bool Attach(Entity entity);
	void Unattach();

private:
	void RefreshParent(TransformComponent *pParent);

private:
	Entity m_AttachEntity;

	TransformComponent *m_pOwnedTransform;

	friend class TransformComponent;
};
