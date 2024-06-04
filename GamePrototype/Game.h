#pragma once
#include "BaseGame.h"
#include "Player.h"
#include "Ball.h"
#include <Texture.h>

class Game : public BaseGame
{
public:
	explicit Game( const Window& window );
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game( Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	// http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rh-override
	~Game();

	void Update( float elapsedSec ) override;
	void Draw( ) const override;

	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e ) override;
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e ) override;
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e ) override;

private:
	//VARIABLES
	Player* m_Player{};
	Player* m_PlayerCopy{};
	std::vector<Ball*> m_Balls{};
	float m_BallCreationTimer{};
	Texture* m_GameOverTexture;
	Texture* m_ResetTexture;
	Texture* m_Score;
	bool m_Start;


	// FUNCTIONS
	void Initialize();
	void Cleanup( );
	void ClearBackground( ) const;

	void InitializePlayer();
	void InitializeBalls();
	void DeleteBalls();
};