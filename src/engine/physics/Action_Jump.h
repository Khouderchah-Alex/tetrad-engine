#pragma once

#include "core/IAction.h"

class Entity;

/**
 * @brief Action to cause the provided entity to jump.
 *
 * Obviously relies on the entity containing a PhysicsComponent. Lacking this,
 * the Action will not do anything (@todo perhaps log the event?)
 */
class Action_Jump : public IAction
{
public:
	Action_Jump(Entity entity);
	virtual ~Action_Jump();

	virtual bool operator()(EEventAction);

private:
	Entity m_Entity;
};

