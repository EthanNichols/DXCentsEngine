#include "HierarchyWindow.h"


HierarchyWindow::HierarchyWindow()
{
}


HierarchyWindow::~HierarchyWindow()
{
}

void HierarchyWindow::Draw()
{
	ObjectManager* objectManager = ObjectManager::GetInstance();
	std::vector<uint64_t>::iterator it = objectIDs.begin();

	ImGui::Begin("Hierarchy");

	if (ImGui::IsWindowHovered() && ImGui::IsMouseClicked(0))
	{
		selectedObjectID = nullptr;
		InspectorWindow::GetInstance()->SetInspectorObject(nullptr);
	}

	for (it; it != objectIDs.end(); ++it)
	{
		Object* object = objectManager->activeObjects[*it];
		bool selected = (selectedObjectID == &*it) ? true : false;
		// 1 << 11 Sets the selectable to active on mouse down instead of mouse release
		ImGuiSelectableFlags selectionFlags = 1 << 11 | ImGuiSelectableFlags_AllowDoubleClick;
		bool pressed = ImGui::Selectable(object->name.c_str(), selected, selectionFlags);

		if (pressed)
		{
			selectedObjectID = &*it;
			InspectorWindow::GetInstance()->SetInspectorObject(reinterpret_cast<GameObject*>(object));
		}
	}

	ImGui::End();
}