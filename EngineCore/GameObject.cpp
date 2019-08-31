#include "GameObject.h"
#include "MeshFilter.h"
#include "MeshRenderer.h"
#include "HierarchyWindow.h"

GameObject::GameObject() : Object("GameObject")
{
	ObjectManager::GetInstance()->RegisterGameObject(this);
	transform = AddComponent<Transform>();
}


GameObject::GameObject(std::string name) : Object(name)
{
	ObjectManager::GetInstance()->RegisterGameObject(this);
	transform = AddComponent<Transform>();
}


GameObject::GameObject(std::string name, Mesh* mesh, Material* material) : Object(name)
{
	ObjectManager::GetInstance()->RegisterGameObject(this);
	transform = AddComponent<Transform>();
	AddComponent<MeshFilter>(mesh);
	AddComponent<MeshRenderer>(material);
}


GameObject::~GameObject()
{
}
