#include "GameController.h"

GameController::GameController() : m_pacman(Pacman()) {
	this->initWindow();

	this->drawMap();
	
	this->initSettingToDrawPacman();
	this->drawPacman(this->m_pacmanLeftSurface);
	
	this->updateWindow();
}

void GameController::initWindow() {
	SDL_Init(SDL_INIT_EVERYTHING);

	this->m_SDLWindow = SDL_CreateWindow("Pacman",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		this->m_nbCellsInHeight * this->m_cellSize, this->m_nbCellsInWidth * this->m_cellSize,
		SDL_WINDOW_SHOWN);

	this->m_SDLRenderer = SDL_CreateRenderer(this->m_SDLWindow, -1, 0);
	SDL_RenderClear(this->m_SDLRenderer);

	this->m_SDLWindowSurface = SDL_GetWindowSurface(this->m_SDLWindow);
}

void GameController::drawMap() {
	std::vector<std::vector<Tile>> tiles = this->m_pacman.getMap().getTiles();

	SDL_Surface* obstacleTileSurface = this->createSDLSurface("Resources/obstacle_tile.png");
	SDL_Surface* collectibleTileSurface = this->createSDLSurface("Resources/collectible_tile.png");

	SDL_Texture* obstacleTileTexture = SDL_CreateTextureFromSurface(this->m_SDLRenderer, obstacleTileSurface);
	SDL_Texture* collectibleTileTexture = SDL_CreateTextureFromSurface(this->m_SDLRenderer, collectibleTileSurface);


	SDL_Rect rectangleAsATile;
	rectangleAsATile.h = this->m_cellSize;
	rectangleAsATile.w = this->m_cellSize;

	for (int i = 0; i < this->m_nbCellsInHeight; i++) {
		for (int j = 0; j < this->m_nbCellsInWidth; j++) {
			rectangleAsATile.x = i * this->m_cellSize;
			rectangleAsATile.y = j * this->m_cellSize;

			Tile tileToDraw = this->m_pacman.getMap().getTile(i, j);
			SDL_Texture* textureToRender = NULL;

			if (tileToDraw.isObstacle()) {
				textureToRender = obstacleTileTexture;
			}
			else if (tileToDraw.isCollectible()) {
				textureToRender = collectibleTileTexture;
			}

			SDL_RenderCopy(this->m_SDLRenderer, textureToRender, NULL, &rectangleAsATile);
		}
	}
}

void GameController::initSettingToDrawPacman()
{
	this->m_pacmanLeftSurface = this->createSDLSurface("Resources/PacmanLeft.png");
	this->m_pacmanRightSurface = this->createSDLSurface("Resources/PacmanRight.png");
	this->m_pacmanUpSurface = this->createSDLSurface("Resources/PacmanUp.png");
	this->m_pacmanDownSurface = this->createSDLSurface("Resources/PacmanDown.png");

	this->m_rectangleFilledWithPacman.h = this->m_cellSize;
	this->m_rectangleFilledWithPacman.w = this->m_cellSize;
}

void GameController::drawPacman(SDL_Surface* pacmanSideSurface)
{
	SDL_Texture* pacmanTexture = SDL_CreateTextureFromSurface(this->m_SDLRenderer, pacmanSideSurface);
	this->m_rectangleFilledWithPacman.x = this->m_pacman.getX() * this->m_cellSize;
	this->m_rectangleFilledWithPacman.y = this->m_pacman.getY() * this->m_cellSize;

	SDL_RenderCopy(this->m_SDLRenderer, pacmanTexture, NULL, &this->m_rectangleFilledWithPacman);
}

void GameController::updateDisplayAfterPacmanMoved(SDL_Surface* pacmanSideSurface, SDL_Rect previousRectangleFilledWithPacman) {
	this->drawPacman(pacmanSideSurface);

	SDL_Surface* emptyTileSurface = SDL_CreateRGBSurface(0, this->m_cellSize, this->m_cellSize, 32, 0, 0, 0, 0);
	SDL_Texture* emptyTileTexture = SDL_CreateTextureFromSurface(this->m_SDLRenderer, emptyTileSurface);

	SDL_RenderCopy(this->m_SDLRenderer, emptyTileTexture, NULL, &previousRectangleFilledWithPacman);
}

void GameController::updateWindow() {
	SDL_RenderPresent(this->m_SDLRenderer);
}

SDL_Surface* GameController::createSDLSurface(std::string imgPath) {
	SDL_Surface* createdSurface;
	try {
		createdSurface = IMG_Load(imgPath.c_str());
		if (!createdSurface)
			throw(IMG_GetError);
	}
	catch (std::string const& error) {
		std::cerr << error << std::endl;
	}

	SDL_Surface* optimizedSurface = SDL_ConvertSurface(createdSurface, this->m_SDLWindowSurface->format, NULL);

	SDL_FreeSurface(createdSurface);

	return optimizedSurface;
}

void GameController::play()
{
	SDL_Event event;

	bool quit = false;

	SDL_Rect previousRectangleFilledWithPacman;
	previousRectangleFilledWithPacman.h = m_cellSize;
	previousRectangleFilledWithPacman.w = m_cellSize;

	while (SDL_PollEvent(&event) != 0 || (!quit && !this->m_pacman.isEndOfGame()))
	{
		if (event.type == SDL_QUIT)
			quit = true;

		if (event.type == SDL_KEYDOWN)
		{
			previousRectangleFilledWithPacman.x = this->m_pacman.getX() * this->m_cellSize;
			previousRectangleFilledWithPacman.y = this->m_pacman.getY() * this->m_cellSize;

			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				if (this->m_pacman.moveUp())
					this->updateDisplayAfterPacmanMoved(this->m_pacmanUpSurface, previousRectangleFilledWithPacman);

				break;

			case SDLK_DOWN:
				if (this->m_pacman.moveDown())
					this->updateDisplayAfterPacmanMoved(this->m_pacmanDownSurface, previousRectangleFilledWithPacman);

				break;

			case SDLK_LEFT:
				if (this->m_pacman.moveLeft())
					this->updateDisplayAfterPacmanMoved(this->m_pacmanLeftSurface, previousRectangleFilledWithPacman);

				break;

			case SDLK_RIGHT:
				if (this->m_pacman.moveRight())
					this->updateDisplayAfterPacmanMoved(this->m_pacmanRightSurface, previousRectangleFilledWithPacman);

				break;

			default:
				break;
			}

			this->updateWindow();

			SDL_Delay(100);
		}
	}
}

void GameController::endOfGame() {
	Score score = this->m_pacman.getScore();

	if (this->m_pacman.isEndOfGame()) {
		score.setTimer();
		score.setFinalScore();
		score.saveScore();
		printf(score.getScoreInformationToString().c_str());
	}

	printf(score.get5BestScoresToString().c_str());
}

void GameController::closeWindow() {
	SDL_DestroyWindow(this->m_SDLWindow);
}

