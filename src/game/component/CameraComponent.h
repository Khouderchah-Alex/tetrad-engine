#pragma once

#include "IComponent.h"

class TransformComponent;
class MovableComponent;

extern void CursorCallback(GLFWwindow*, double, double);

/**
 * @brief Component that gives an entity the ability to act as a camera
 *
 * The render system uses information from this component in order to
 * generate the final MVP matrix. Having this as a component makes it
 * easy to switch between cameras as needed at runtime.
 */
class CameraComponent : public IComponent
{
public:
	CameraComponent(Entity entity);
	~CameraComponent();

	enum EProjectionType
	{
		EPT_PERSPECTIVE,
		EPT_ORTHOGRAPHIC,
	};
	EProjectionType GetProjectionType() const{ return m_ProjectionType; }
	void SetProjectionType(EProjectionType projectionType);

	float GetFOV() const{ return m_FOV; }
	void SetFOV(float FOV){ m_FOV = FOV; }

	float GetNear() const{ return m_Near; }
	void SetNear(float nearDistance){ m_Near = nearDistance; }

	float GetFar() const{ return m_Far; }
	void SetFar(float farDistance){ m_Far = farDistance; }

	const glm::mat4& GetCameraMatrix(float width, float height) const;

	void Refresh();

private:
	TransformComponent *m_pTransformComp;
	MovableComponent *m_pMover;
	EProjectionType m_ProjectionType;
	mutable glm::mat4 m_CameraMatrix;
	float m_FOV;
	float m_Near;
	float m_Far;

	friend void CursorCallback(GLFWwindow*, double, double);
};
