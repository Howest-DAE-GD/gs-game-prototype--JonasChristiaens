#include "pch.h"
#include "Game.h"
#include <time.h>
#include <iostream>

Game::Game( const Window& window ) 
	:BaseGame{ window }
{
	Initialize();
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	InitializePlayer();
	InitializeBalls();
}

void Game::Cleanup( )
{
	delete m_Player;
	m_Player = nullptr;

	for (int idx{}; idx < m_Balls.size(); ++idx)
	{
		delete m_Balls[idx];
		m_Balls[idx] = nullptr;
	}
}

void Game::Update( float elapsedSec )
{
	m_Player->Update(elapsedSec);

	m_BallCreationTimer += elapsedSec;
	m_BallDeletionTimer += elapsedSec;
	
	std::cout<< m_BallCreationTimer << std::endl;

	if (m_BallCreationTimer >= 5.f)
	{
		InitializeBalls();
		m_BallCreationTimer = 0;
	}
}

void Game::Draw( ) const
{
	ClearBackground( );

	for (int idx{}; idx < m_Balls.size(); ++idx)
	{
		m_Balls[idx]->Draw();
		//std::cout << m_Balls[idx] << std::endl;
	}
	m_Player->Draw();
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}
void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	//switch ( e.keysym.sym )
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "`Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}
void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}
void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
	
}
void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}
void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::InitializePlayer()
{
	m_Player = new Player(640.0f, 400.0f);
}

void Game::InitializeBalls()
{
	srand(time(nullptr));
	int xPos = rand() % (int)(1280 - 20.f) + 10;
	int yPos = rand() % (int)(800 - 20.f) + 10;

	m_Balls.push_back(new Ball(xPos, yPos));
}
void Game::DeleteBalls()
{
	m_Balls.pop_back();
}