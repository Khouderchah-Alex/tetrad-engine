#pragma once

#include "UIComponent.h"

/**
 * @brief UIComponent type that serves as a button
 *
 * Provides the functionality of a UIComponent that has three distinct states
 * (default, hovered, and pressed), as well as mapping an Event to a button
 * press.
 */
class UIButton : public UIComponent
{
public:
	UIButton(Entity entity);
	~UIButton();

	void SetTextures(const std::string &defaultTex,
					 const std::string &hoverTex,
					 const std::string &pressTex);

	void OnHoverEnter();
	void OnHoverLeave();

	void OnTouchEnter();
	void OnTouchLeave();

	// TODO allow for generating an Event (or calling a callback?) on button presses!

private:
	GLuint m_DefaultTex;
	GLuint m_HoverTex;
	GLuint m_PressTex;
};