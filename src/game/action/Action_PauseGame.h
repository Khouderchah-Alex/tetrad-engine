#pragma once

#include "IAction.h"

/**
 * @brief System observer action to pause the game
 */
class Action_PauseGame : public IAction
{
public:
	Action_PauseGame(GLFWwindow* pWindow);
	virtual ~Action_PauseGame(){}

	static void SetFadeScreen(Entity entity){ s_FadeEntity = entity; }

	virtual bool operator()(EEventAction);

private:
	GLFWwindow* m_pWindow;
	static Entity s_FadeEntity;
	static bool s_bFadeOut;
};
