#include "Action_PauseGame.h"
#include "MaterialComponent.h"
#include "Game.h"

Action_PauseGame::Action_PauseGame(Game *pGame) :
	m_pGame(pGame),
	m_ShouldPause(true)
{}

bool Action_PauseGame::operator()(EEventAction action)
{
	if(action != EEventAction::ON){ return false; }

	if(m_ShouldPause)
	{
		m_pGame->Pause();
	}
	else
	{
		m_pGame->Unpause();
	}
	m_ShouldPause = !m_ShouldPause;

	return true;
}