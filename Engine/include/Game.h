#pragma once

#include <memory>
#include <string>

#include "StateMachine.h"
#include "AssetManager.h"

#include "SFML\Graphics.hpp"


struct GameData
{
	StateMachine stateMachine;
	sf::RenderWindow window;
	AssetManager assets;
};


typedef std::shared_ptr<GameData> GameDataRef;


class Game
{
public:
	Game(const int width, const int height, std::string& title);
	~Game();

private:
	const float dt = 1.f / 60.0f;

	sf::Clock _clock;

	GameDataRef _data = std::make_shared<GameData>();

	void Run();
};

