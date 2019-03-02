#pragma once

#include <vector>

#include "CentsEngine.h"

class Game
	: public DXCore
{

public:
	Game(HINSTANCE hInstance);
	~Game();

	// Overridden setup and game loop methods, which
	// will be called automatically
	void Init();
	void OnResize();
	void Update(float deltaTime, float totalTime);
	void Draw(float deltaTime, float totalTime);

	// Overridden mouse input helper methods
	void OnMouseDown(WPARAM buttonState, int x, int y);
	void OnMouseUp(WPARAM buttonState, int x, int y);
	void OnMouseMove(WPARAM buttonState, int x, int y);
	void OnMouseWheel(float wheelDelta, int x, int y);

private:

	Lights lights;


	/*AmbientLight ambientLight;
	DirectionalLight directionalLight;
	DirectionalLight directionalLight2;*/

	// Initialization helper methods - feel free to customize, combine, etc.
	void LoadShaders();
	void LoadModels();
	void LoadTextures();
	void CreateMaterials();
	void CreateBasicGeometry();

	std::vector<Mesh*> meshes;
	std::vector<GameObject*> gameObjects;
	std::vector<ID3D11ShaderResourceView*> textureViews;
	std::vector<Material*> materials;
	SimpleVertexShader* vertexShader;
	SimplePixelShader* pixelShader;
	Camera* camera;
	GameObject* camObject;

	// Keeps track of the old mouse position.  Useful for 
	// determining how far the mouse moved in a single frame.
	POINT prevMousePos;
};
