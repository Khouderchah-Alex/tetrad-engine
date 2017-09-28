#include "CallbackContext.h"
#include "Base.h"
#include "Screen.h"
#include "Game.h"

#include "MovableComponent.h"
#include "CameraComponent.h"
#include "UI/UI.h"
#include "EventSystem.h"

Screen *CallbackContext::s_pCurrentScreen = nullptr;
Game *CallbackContext::s_pCurrentGame = nullptr;
double CallbackContext::s_PrevX = 0;
double CallbackContext::s_PrevY = 0;
UIComponent *CallbackContext::s_pPrevUI = nullptr;
UIComponent *CallbackContext::s_pPrevValidUI = nullptr;

void CallbackContext::Resize_Default(GLFWwindow*, int width, int height)
{
	glViewport(0, 0, width, height);
	s_pCurrentScreen->SetSize(width, height);
}

void CallbackContext::Cursor_GUI(GLFWwindow *, double currX, double currY)
{
	static double prevX = s_PrevX;
	static double prevY = s_PrevY;
	currY = s_pCurrentScreen->GetHeight() - currY - 1;

	// If moving button, ignore other UI elements
	if(s_pPrevValidUI && s_pPrevValidUI->IsFollowingCursor())
	{
		double xDiff = (currX - prevX) / s_pCurrentScreen->GetWidth();
		double yDiff = (currY - prevY) / s_pCurrentScreen->GetHeight();

		s_pPrevValidUI->GetMover()->AbsoluteMove(glm::vec3(xDiff, yDiff, 0));
		s_pCurrentScreen->Inform(s_pPrevValidUI, Screen::EIT_UPDATED);

		prevX = currX;
		prevY = currY;
		return;
	}

	// Inform elements of hover enter & exits
	UIComponent *pUI = s_pCurrentScreen->FindElementAt(currX, currY);
	if(pUI)
	{
		s_pPrevValidUI = pUI;
	}

	if(pUI != s_pPrevUI)
	{
		if(s_pPrevUI)
		{
			s_pPrevUI->OnHoverLeave();
		}
		if(pUI)
		{
			pUI->OnHoverEnter();
		}
	}

	s_pPrevUI = pUI;

	prevX = currX;
	prevY = currY;
}

void CallbackContext::Cursor_3DCamera(GLFWwindow*, double currX, double currY)
{
	// TODO use current UIViewport & CallbackContext!!!
	// Get current viewport - NOTE, THIS ASSUMES ONE VIEWPORT!
	static ConstVector<UIViewport*> pViewports =
		EntityManager::GetAll<UIViewport>();
	static screenBound_t screenBounds(0,0,0,0);
	screenBounds = pViewports[1]->GetScreenBounds();
	CameraComponent *pCamera = pViewports[1]->GetCamera();
	Screen *pScreen = pViewports[1]->GetScreen();

	DEBUG_ASSERT(pScreen);

	double mouseSensitivity = EventSystem::GetMouseSensitivity();

	// Calculate normalized x & y diffs, then scale by sensitivity factor
	double xDiff = mouseSensitivity * (currX - s_PrevX) /
		(pScreen->GetWidth()*(screenBounds.points[1].X - screenBounds.points[0].X));
	double yDiff = mouseSensitivity * (currY - s_PrevY) /
		(pScreen->GetHeight()*(screenBounds.points[1].Y - screenBounds.points[0].Y));

	// Apply appropriate rotations to camera
	TransformDirs localDirs = pCamera->m_pTransformComp->GetLocalDirs();
	pCamera->m_pMover->Rotate(-yDiff, localDirs.rightDir);
	pCamera->m_pMover->Rotate(-xDiff, glm::vec3(0, 1, 0));

	// Store current cursor position
	s_PrevX = currX;
	s_PrevY = currY;
}

void CallbackContext::Keyboard_3DCamera(GLFWwindow*, int key,
										int scancode, int action, int mods)
{
	(void)scancode; (void)mods;
	Event event;

	DEBUG_ASSERT(EventSystem::GetInputSystem());
	DEBUG_ASSERT(s_pCurrentGame);

	// @TODO - GO THROUGH AN INPUT MAPPER!!!!
	if(action != GLFW_REPEAT)
	{
		EGameState currState = s_pCurrentGame->GetCurrentState();
		if(currState == EGameState::STARTED)
		{
			switch(key)
			{
			case GLFW_KEY_ESCAPE:
				event.event = EGE_PAUSE;
				break;
			case GLFW_KEY_Z:
				event.event = EGE_PLAYER1_JUMP;
				break;
			case GLFW_KEY_X:
				event.event = EGE_PLAYER2_JUMP;
				break;
			case GLFW_KEY_W:
				event.event = EGE_PLAYER1_FORWARDS;
				break;
			case GLFW_KEY_A:
				event.event = EGE_PLAYER1_LEFT;
				break;
			case GLFW_KEY_S:
				event.event = EGE_PLAYER1_BACKWARDS;
				break;
			case GLFW_KEY_D:
				event.event = EGE_PLAYER1_RIGHT;
				break;
			default:
				event.event = EGE_NONE;
			}
		}
		else if(currState == EGameState::PAUSED && key == GLFW_KEY_ESCAPE)
		{
			event.event = EGE_PAUSE;
		}

		if(action == GLFW_PRESS){ event.action = EEventAction::ON; }
		else if(action == GLFW_RELEASE){ event.action = EEventAction::OFF; }

		event.state = currState;
		EventSystem::GetInputSystem()->Inform(event);
	}
}

void CallbackContext::MouseButton_Viewport(GLFWwindow *pWindow, int button, int action, int mods)
{
	(void)mods;
	static uint32_t prevCursorMode = glfwGetInputMode(pWindow, GLFW_CURSOR);

	switch(button)
	{
	case GLFW_MOUSE_BUTTON_RIGHT:
		if(action == GLFW_PRESS)
		{
			glfwSetInputMode(pWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
			glfwSetCursorPos(pWindow, s_PrevX, s_PrevY);
			glfwSetCursorPosCallback(pWindow, Cursor_3DCamera);
		}
		else
		{
			glfwSetCursorPosCallback(pWindow, Cursor_GUI);
			glfwGetCursorPos(pWindow, &s_PrevX, &s_PrevY);
			glfwSetInputMode(pWindow, GLFW_CURSOR, prevCursorMode);
		}
		break;
	case GLFW_MOUSE_BUTTON_LEFT:
		if(s_pPrevUI)
		{
			if(action == GLFW_PRESS)
			{
				s_pPrevUI->OnTouchEnter();
				s_pCurrentScreen->Inform(s_pPrevUI, Screen::EIT_UPDATED);
			}
			else //action == GLFW_RELEASE
			{
				s_pPrevUI->OnTouchLeave();
				s_pPrevValidUI = nullptr;
			}
		}
		else if(action == GLFW_RELEASE)
		{
			if(s_pPrevValidUI)
			{
				s_pPrevValidUI->OnTouchLeave();
				s_pPrevValidUI = nullptr;
			}
			// TODO Raytrace & select object
		}
		break;
	default:
		break;
	}
}


void CallbackContext::SetScreen(Screen *pScreen)
{
	s_pCurrentScreen = pScreen;

	double xpos, ypos;
	glfwGetCursorPos(pScreen->GetWindow(), &xpos, &ypos);
	s_PrevX = xpos;
	s_PrevY = ypos;
}

void CallbackContext::SetGame(Game *pGame)
{
	s_pCurrentGame = pGame;
}