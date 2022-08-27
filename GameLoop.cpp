#include "GameLoop.h"
#undef main
GameLoop::GameLoop() 
{
	//triangleRenderer = new TriangleRenderer(camera);
	//billboard = new Billboard(brick);
	//f = new Font("text.png");
	//guiText = new GUIText(f);

	camera = new FPSCamera(this->window);
	modelRenderer = new ModelRenderer(camera);
	terrainTexture = new Texture("terrain-texture.png");
	terrain = new Terrain("terrain-heightmap.png", terrainTexture);
	sky1 = new Texture("skydome.jpg");
	skydome = new Skydome(sky1);
	
	Tank = new Model("Tank.obj");
	TankTexture = new Texture("TankTex.jpg");

	Cottage = new Model("Cottage.obj");
	CottageTexture = new Texture("CottageTex.png");

	AbandonedFactory = new Model("AbandonedFactory.obj");
	AbandonedFactoryTexture = new Texture("AbandonedFactoryTex.jpg");

	Rubble = new Model("Rubble.obj");
	RubbleTexture = new Texture("RubbleTex.png");

	RundownBuilding = new Model("RundownBuilding.obj");
	RundownBuildingTexture = new Texture("RundownBuildingTex.png");

	ApocalypseCar = new Model("ApocCar.obj");
	ApocalypseCarTexture = new Texture("ApocCarTex.png");

	RoadBlocker = new Model("RoadBlock.obj");
	RoadBlockerTexture = new Texture("RoadBlockTex.png");

	RoadBlockerCOPY = new Model("RoadBlock.obj");
	RoadBlockerTextureCOPY = new Texture("RoadBlockTex.png");
}

GameLoop::~GameLoop()
{
	delete camera;
	delete modelRenderer;
	delete terrainTexture;
	delete terrain;
	delete skydome;

	delete Tank;
	delete TankTexture;
	delete Cottage;
	delete CottageTexture;
	delete AbandonedFactory;
	delete AbandonedFactoryTexture;
	delete Rubble;
	delete RubbleTexture;
	delete RundownBuilding;
	delete RundownBuildingTexture;
	delete ApocalypseCar;
	delete ApocalypseCarTexture;
	delete RoadBlocker;
	delete RoadBlockerTexture;
	delete RoadBlockerCOPY;
	delete RoadBlockerTextureCOPY;
}

void GameLoop::init()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	//create a window
	window = SDL_CreateWindow("SDL OpenGL", 50, 50, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		printf("SDL could not create window! SDL Error: %s\n", SDL_GetError());
		return;
	}

	glContext = SDL_GL_CreateContext(window);

	if (glContext == nullptr) {
		printf("SDL could not create GL context! SDL Error: %s\n", SDL_GetError());
		return;
	}
	//Initialize GLEW
	glewExperimental = GL_TRUE;
	GLenum glewError = glewInit();
	if (glewError != GLEW_OK)
	{
		printf("Error initializing GLEW! %s\n", glewGetErrorString(glewError));
	}
	//Use Vsync
	if (SDL_GL_SetSwapInterval(1) < 0)
	{
		printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
	}

	//billboard->init();
	//f->init();
	//guiText->setText("Welcome to my world!");

	modelRenderer->init();
	terrainTexture->init();
	terrain->init();
	sky1->init();
	skydome->init();

	//Tank
	Tank->init();
	Tank->setTexture(TankTexture);
	TankTexture->init();

	//Cottage
	Cottage->init();
	Cottage->setTexture(CottageTexture);
	CottageTexture->init();

	//Factory
	AbandonedFactory->init();
	AbandonedFactory->setTexture(AbandonedFactoryTexture);
	AbandonedFactoryTexture->init();

	//Rubble
	Rubble->init();
	Rubble->setTexture(RubbleTexture);
	RubbleTexture->init();

	//Rundown Building
	RundownBuilding->init();
	RundownBuilding->setTexture(RundownBuildingTexture);
	RundownBuildingTexture->init();

	//Apocalpyse Car
	ApocalypseCar->init();
	ApocalypseCar->setTexture(ApocalypseCarTexture);
	ApocalypseCarTexture->init();

	//Road Blocker
	RoadBlocker->init();
	RoadBlocker->setTexture(RoadBlockerTexture);
	RoadBlockerTexture->init();

	RoadBlockerCOPY->init();
	RoadBlockerCOPY->setTexture(RoadBlockerTextureCOPY);
	RoadBlockerTextureCOPY->init();
}
bool GameLoop::handleInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		camera->handleInput(e);
	}
	return true;
}

void GameLoop::update(){
	camera->update();
}

void GameLoop::draw()
{
	glClearColor(0.392f, 0.584f, 0.929f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//modelRenderer->renderText(guiText);
	//modelRenderer->renderBillboard(billboard);

	modelRenderer->renderSkydome(skydome);
	modelRenderer->renderTerrain(terrain);
	
	//tank
	modelRenderer->renderModel(Tank);
	Tank->rotation = glm::vec3(0, 0, 0);
	Tank->position = glm::vec3(400.0f, -25, 500.0f);
	Tank->scale = glm::vec3(23, 23, 23);

	//cottage
	modelRenderer->renderModel(Cottage);
	Cottage->scale = glm::vec3(0.2f,0.2f,0.2f);
	Cottage->position = glm::vec3(150, -25, 325);

	//abandoned factory
	modelRenderer->renderModel(AbandonedFactory);
	AbandonedFactory->scale = glm::vec3(0.1f, 0.1f, 0.1f);
	AbandonedFactory->position = glm::vec3(-850 ,100, 50.0f);
	AbandonedFactory->rotation = glm::vec3(0, 0.91f, 0);

	//rubble
	modelRenderer->renderModel(Rubble);
	Rubble->position = glm::vec3(250, -25, 430);
	Rubble->rotation = glm::vec3(0, 0, 0);
	Rubble->scale = glm::vec3(0.9f, 0.9f, 0.9f);

	//rundown building
	modelRenderer->renderModel(RundownBuilding);
	RundownBuilding->position = glm::vec3(0, -25, 0);
	RundownBuilding->scale = glm::vec3(1, 1, 1);
	RundownBuilding->rotation = glm::vec3(0, 0, 0);

	//apocalypse car
	modelRenderer->renderModel(ApocalypseCar);
	ApocalypseCar->position = glm::vec3(325, -10, 525);
	ApocalypseCar->scale = glm::vec3(19, 19, 19);
	ApocalypseCar->rotation = glm::vec3(0, 0, 0);

	//road blocker
	modelRenderer->renderModel(RoadBlocker);
	RoadBlocker->position = glm::vec3(275, -25, 205);
	RoadBlocker->scale = glm::vec3(0.006f, 0.006f, 0.006f);
	RoadBlocker->rotation = glm::vec3(0, 0, 0);

	modelRenderer->renderModel(RoadBlockerCOPY);
	RoadBlockerCOPY->position = glm::vec3(275, -25, 250);
	RoadBlockerCOPY->scale = glm::vec3(0.006f, 0.006f, 0.006f);
	RoadBlockerCOPY->rotation = glm::vec3(0, 0, 0);

	//present the screen
	SDL_GL_SwapWindow(window);
}

void GameLoop::clean()
{
	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
}

int main(void) {
	GameLoop * gameLoop = new GameLoop();
	gameLoop->init();

	while (gameLoop->handleInput()) {
		gameLoop->update();
		gameLoop->draw();
	}

	gameLoop->clean();
	delete gameLoop;
}
