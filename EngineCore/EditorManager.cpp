#include "EditorManager.h"


void EditorManager::Draw(float deltaTime, ID3D11Device * device, ID3D11DeviceContext * context)
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	HierarchyWindow::GetInstance()->Draw();
	InspectorWindow::GetInstance()->Draw();

	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

EditorManager::EditorManager()
{
}


EditorManager::~EditorManager()
{
	HierarchyWindow::ReleaseInstance();
	InspectorWindow::ReleaseInstance();
}
