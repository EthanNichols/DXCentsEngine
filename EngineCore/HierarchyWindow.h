#pragma once
#include <vector>
#include "Singleton.h"
#include "ObjectManager.h"
#include "imgui.h"
#include "InspectorWindow.h"


class HierarchyWindow : public Singleton<HierarchyWindow>
{
	friend class Singleton<HierarchyWindow>;
	friend class ObjectManager;

public:

	/// <summary>
	/// Draw the ImGUI hierarchy with all of the gameobjects in the scene
	/// </summary>
	void Draw();

protected:

	HierarchyWindow();
	~HierarchyWindow();

private:

	/// <summary>
	/// List of gamobject IDs
	/// </summary>
	std::vector<uint64_t> objectIDs;

	/// <summary>
	/// Object ID that is currently selected in the hierarchy
	/// Null if nothing is selected in the hierarchy
	/// </summary>
	uint64_t* selectedObjectID = nullptr;
};

