#pragma once
#include "Singleton.h"
#include "imgui.h"

class GameObject;

class InspectorWindow : public Singleton<InspectorWindow>
{
	friend class Singleton<InspectorWindow>;

public:

	/// <summary>
	/// Draw the object inspector populated with the attached components
	/// </summary>
	void Draw();

	/// <summary>
	/// Set the object that is being displayed in the inspector
	/// </summary>
	void SetInspectorObject(GameObject* object)
	{
		InspectedObject = object;
	}

protected:
	InspectorWindow();
	~InspectorWindow();

private:

	/// <summary>
	/// The object that is being displayed in the inspector
	/// </summary>
	GameObject* InspectedObject = nullptr;
};

