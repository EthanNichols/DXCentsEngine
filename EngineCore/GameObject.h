#pragma once
#include <string>

#include "Object.h"
#include "Transform.h"
#include "stdHelper.h"
#include "Mesh.h"
#include "Material.h"

typedef std::unordered_map<std::string, Component*> COMPONENT_MAP;

class GameObject : public Object
{
public:

	/// <summary>
	/// The Transform attached to this GameObject
	/// </summary>
	Transform* transform;

	GameObject();
	/// <summary>
	/// Naming constructor
	/// </summary>
	/// <param name="name">The name of the GameObject</param>
	GameObject(std::string name);

	GameObject(std::string name, Mesh* mesh, Material* material);

	template <class T, class ...ARGS>
	/// <summary>
	/// Create and attach a Component type to this GameObject
	/// If the component type is already attached to this GameObject, it's returned
	/// </summary>
	/// <param name="...args">The parameters for the Component type constructor</param>
	/// <returns>The component that was attached to the GameObject</returns>
	T* AddComponent(ARGS&&... args)
	{
		if (!std::is_base_of<Component, T>::value)
		{
			LOG_TRACE("Tried to add {} which is not a component, returning", GetTypeName<T>());
			return nullptr;
		}

		T* component = GetComponent<T>();
		if (component != nullptr)
		{
			LOG_TRACE("Tried to add {} which already is attached to GameObject, returning", GetTypeName<T>());
			return nullptr;
		}

		component = new T(std::forward<ARGS>(args)...);
		if (transform == nullptr && GetTypeName<T>() == GetTypeName<Transform>())
		{
			transform = reinterpret_cast<Transform*>(component);
		}

		reinterpret_cast<Component*>(component)->gameObject = this;
		reinterpret_cast<Component*>(component)->transform = transform;
		attachedComponents.insert({ GetTypeName<T>(), reinterpret_cast<Component*>(component) });

		return component;
	}

	template <class T>
	/// <summary>
	/// Get the Component attached to this GameObject based on the the Component type
	/// </summary>
	T* GetComponent() const
	{
		if (!std::is_base_of<Component, T>::value)
		{
			LOG_TRACE("Tried to find {} which is not a component, returning", GetTypeName<T>());
			return nullptr;
		}

		std::unordered_map<std::string, Component*>::const_iterator component = attachedComponents.find(GetTypeName<T>());

		if (component == attachedComponents.end())
		{
			return nullptr;
		}
		else
		{
			return reinterpret_cast<T*>(component->second);
		}
	}

	const COMPONENT_MAP* GetAllComponents() const
	{
		return &attachedComponents;
	}

	/// <summary>
	/// Remove a Component that is attached to this gameobject
	/// </summary>
	/// <param name="component">The component to remove</param>
	/// <returns>Whether the Component was removed or not</returns>
	bool RemoveComponent(Component* component)
	{
		if (static_cast<Transform*>(component) == transform)
		{
			LOG_TRACE("Tried to remove {} which cannot be removed from a GameObject, returning", component->name);
			return false;
		}

		attachedComponents.erase(attachedComponents.find(component->name));
		return true;
	}

protected:

	~GameObject();

	/// <summary>
	/// Map of all of the components attached to this GameObject
	/// Key is the name of the Component, value is the Component reference
	/// </summary>
	COMPONENT_MAP attachedComponents;
};