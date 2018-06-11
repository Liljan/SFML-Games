#include "Game.h"

Game::Game(const int width, const int height, std::string & title)
{
	_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

	// Add states here!

	Run();
}


Game::~Game()
{
}

void Game::Run()
{
	float currentTime = _clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (_data->window.isOpen())
	{
		_data->stateMachine.ProcessStateChanges();

		float newTime = _clock.getElapsedTime().asSeconds();
		float frameTime = newTime - currentTime;

		if (frameTime > .25f)
			frameTime = .25f;

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= dt)
		{
			_data->stateMachine.GetActiveState()->Update(dt);
		}
	}
}

