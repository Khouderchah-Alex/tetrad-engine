#pragma once

#include "TransformComponent.h"

enum class EMoveType : int8_t { GLOBAL = 0, LOCAL };

/**
 * @brief Compenent that enables an entity to be moved.
 *
 * @note Obviously depends on an entity having a Transform Component.
 */
class MovableComponent : public IComponent
{
public:
	MovableComponent(Entity entity);
	~MovableComponent();

	void Refresh();

	// Translation functions
	void SetPosition(const glm::vec3& position);
	void Move(const glm::vec3& shift, EMoveType moveType = EMoveType::GLOBAL);
	void AbsoluteMove(const glm::vec3& shift, EMoveType moveType = EMoveType::GLOBAL);

	// Orientation functions
	void SetOrientation(const glm::vec3& radAngles);
	void Rotate(float rotationRads, const glm::vec3& rotationAxis);
	void Rotate(const glm::vec3& eulerAngles);
	void Rotate(const glm::mat3& rotationMatrix);

	// Scale functions
	void SetScale(const glm::vec3& scale);
	void Scale(const glm::vec3& amount);
private:
	TransformComponent* m_pTransformComp;
};

