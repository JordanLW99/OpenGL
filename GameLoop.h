#pragma once
#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <stdio.h>
#include "TriangleRenderer.h"
#include "ModelRenderer.h"
#include "Model.h"
#include "Camera.h"
#include "Texture.h"
#include "FPSCamera.h"
#include "Font.h"
#include "GUIText.h"

class GameLoop {

public:
	GameLoop();
	virtual ~GameLoop();

	void init();
	bool handleInput();
	void update();
	void draw();
	void clean();

private:
	//Camera * camera;
	//TriangleRenderer * triangleRenderer;

	SDL_Window * window;
	SDL_GLContext glContext;
	ModelRenderer * modelRenderer;
	FPSCamera * camera;
	Terrain * terrain;
	Texture * terrainTexture;
	Texture * sky1;
	Skydome * skydome;
	Billboard * billboard;
	Font * f;
	GUIText * guiText;
	glm::vec3 position;
	
	Model * Tank;
	Texture * TankTexture;
	Model * Cottage;
	Texture * CottageTexture;
	Model * AbandonedFactory;
	Texture * AbandonedFactoryTexture;
	Model * Rubble;
	Texture * RubbleTexture;
	Model * RundownBuilding;
	Texture * RundownBuildingTexture;
	Model * ApocalypseCar;
	Texture * ApocalypseCarTexture;
	Model * RoadBlocker;
	Texture * RoadBlockerTexture;
	Model * RoadBlockerCOPY;
	Texture * RoadBlockerTextureCOPY;
};
