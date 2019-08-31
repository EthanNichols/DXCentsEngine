#pragma once

#include "Object.h"
#include "InspectorWindow.h"
#include "imgui.h"

class GameObject;
class Transform;

class Component : public Object
{
	friend class GameObject;
	friend class InspectorWindow;

public:

	/// <summary>
	/// Reference to the GameObject this component is attached to
	/// </summary>
	GameObject* gameObject;
	/// <summary>
	/// Reference to the Transform attached to the GameObject
	/// </summary>
	Transform* transform;

	Component();

protected:

	/// <summary>
	/// Naming constructor
	/// </summary>
	/// <param name="name"></param>
	Component(std::string name);
	virtual ~Component() override;

	/// <summary>
	/// Draw the ImGUI fields
	/// </summary>
	virtual void DrawEditor() = 0;
};
