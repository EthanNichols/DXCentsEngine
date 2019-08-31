#pragma once
#include "Singleton.h"
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include "HierarchyWindow.h"
#include "InspectorWindow.h"

class EditorManager : public Singleton<EditorManager>
{
	friend class Singleton<EditorManager>;

public:

	/// <summary>
	/// Draw important aspects of the editor
	/// </summary>
	/// <param name="deltaTime"></param>
	/// <param name="device"></param>
	/// <param name="context"></param>
	void Draw(float deltaTime, ID3D11Device* device, ID3D11DeviceContext* context);

protected:

	EditorManager();
	~EditorManager();
};

