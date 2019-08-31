#include "InspectorWindow.h"
#include "GameObject.h"


InspectorWindow::InspectorWindow()
{
}


InspectorWindow::~InspectorWindow()
{
}


void InspectorWindow::Draw()
{
	ImGui::Begin("Inspector");

	if (InspectedObject != nullptr)
	{
		const COMPONENT_MAP* attachedComponents = InspectedObject->GetAllComponents();
		COMPONENT_MAP::const_iterator it = attachedComponents->begin();

		for (;it != attachedComponents->end();++it)
		{
			if (ImGui::CollapsingHeader(it->second->name.c_str()))
			{
				it->second->DrawEditor();
			}
		}
	}

	ImGui::End();
}