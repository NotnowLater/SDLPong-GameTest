#include "Game.h"
#include "TextureManager.h"
#include "TilesMap.h"
#include "ECS.h"
#include "Components.h"
#include "Collision.h"




TilesMap* map;

SDL_Event Game::event;
SDL_Renderer* Game::renderer = nullptr;
std::vector<ColliderComponent*> Game::colliders;
Manager manager;

// Game variables
auto& Player(manager.AddEntity());
auto& Player2(manager.AddEntity());
auto& Ball(manager.AddEntity());
auto& Score(manager.AddEntity());
auto& Score2(manager.AddEntity());

int ballPosX;

int score1 = 0;
int score2 = 0;

enum GroupLabels : std::size_t {
	groupMap,
	groupSprite,
	groupText
};


Game::Game() {

}
Game::~Game() {

}
void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen) {
	int flags = 0;
	if (fullScreen)
		flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		TTF_Init();
		std::cout << "SDL subsystems initialized" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags | SDL_WINDOW_RESIZABLE);
		if (window) {
			std::cout << "window created, size "<< width << " by " << height << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 34, 32, 52, 255);
			SDL_RenderSetLogicalSize(renderer, 1280, 720);
			std::cout << "renderer created and initialized" << std::endl;
		}
		isRunning = true;
		// start init the game down here
		std::cout << "Initializing the game" << std::endl;

		map = new TilesMap("Assets/bgmap.mapdata");
		//TilesMap::LoadMap("Assets/bgmap.mapdata", 80, 45);
		std::cout << "TilesMap initialized" << std::endl;

		Player.AddComponent<TransformComponenet>(80.0f, 338.0f, 16, 64, 1);
		Player.AddComponent<SpriteComponent>("Assets/blue.png");
		Player.AddComponent<PaddleControllerComponent>(true);
		Player.AddComponent<ColliderComponent>("Paddle");
		Player.AddGroup(groupSprite);
		std::cout << "Player1 initialized" << std::endl;

		Player2.AddComponent<TransformComponenet>(1184.0f, 338.0f, 16, 64, 1);
		Player2.AddComponent<SpriteComponent>("Assets/red.png");
		Player2.AddComponent<PaddleControllerComponent>(false);
		Player2.AddComponent<ColliderComponent>("Paddle");
		Player2.AddGroup(groupSprite);
		std::cout << "Player2 initialized" << std::endl;

		Ball.AddComponent<TransformComponenet>();
		Ball.AddComponent<SpriteComponent>("Assets/yellow.png");
		Ball.AddComponent<BallComponent>();
		Ball.AddComponent<ColliderComponent>("Ball");
		Ball.AddGroup(groupSprite);
		std::cout << "Ball initialized" << std::endl;

		Score.AddComponent<TransformComponenet>(128, 72, 0, 0, 1);
		Score.AddComponent<TextComponent>("Assets/font.ttf", 144, "0", 91, 110, 225);
		Score.AddGroup(groupText);

		Score2.AddComponent<TransformComponenet>(1098, 72, 0, 0, 1);
		Score2.AddComponent<TextComponent>("Assets/font.ttf", 144, "0", 217, 87, 99);
		Score2.AddGroup(groupText);

		std::cout << "Game initialized" << std::endl;
		std::cout << "SDLPong, Created by Notnow_Later 2022, Powered by NGamegine V0.2" << std::endl << std::endl;
		//

	}
}
void Game::HandleEvent() {
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}
void Game::Update() {
	manager.Refresh();
	manager.Update();
	ballPosX = Ball.GetComponent<TransformComponenet>().position.x;
	if (ballPosX) {
		if (ballPosX < -16) {
			//transform->velocity.x = 1;
			score2 += 1;
			Score2.GetComponent<TextComponent>().ChangeText(std::to_string(score2).c_str(), 144);
			Ball.GetComponent<BallComponent>().ResetBall();
		}
		if (ballPosX > 1296) {
			//transform->velocity.x = -1;
			score1 += 1;
			Score.GetComponent<TextComponent>().ChangeText(std::to_string(score1).c_str(), 144);
			Ball.GetComponent<BallComponent>().ResetBall();

		}
	}
	if (Collision::AABB(Player.GetComponent<ColliderComponent>().collider, Ball.GetComponent<ColliderComponent>().collider)) {
		Ball.GetComponent<TransformComponenet>().velocity.x = 1;
	}
	if (Collision::AABB(Player2.GetComponent<ColliderComponent>().collider, Ball.GetComponent<ColliderComponent>().collider)) {
		Ball.GetComponent<TransformComponenet>().velocity.x = -1;
	}
}

auto& tiles(manager.Getgroup(groupMap));
auto& sprites(manager.Getgroup(groupSprite));
auto& text(manager.Getgroup(groupText));


void Game::Render() {
	SDL_RenderClear(renderer);
	// add stuff to draw down here
	map->DrawMap();
	for (auto& tx : text) {
		tx->Draw();
	}
	/*for (auto& t : tiles) {
		t->Draw();
	}*/
	for (auto& s : sprites) {
		s->Draw();
	}
	SDL_RenderPresent(renderer);
}

void Game::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_Quit();
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}

bool Game::Running() { return isRunning; }

void Game::AddTile(int id, int x, int y) {
	auto& tile(manager.AddEntity());
	tile.AddComponent<TileComponent>(x, y, 16, 16, id);
	tile.AddGroup(groupMap);
}