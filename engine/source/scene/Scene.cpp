#include "Scene.h"
#include "scene/Scene.h"

namespace eng {
	void Scene::Update(float deltaTime) {
		for (auto i = m_objects.begin(); i != m_objects.end();) {
			if ((*i)->IsAlive()) {
				(*i)->Update(deltaTime);
				++i;
			} else {
				i = m_objects.erase(i);
			}
		}
	}

	void Scene::Clear() {
		m_objects.clear();
	}

	GameObject* Scene::CreateObject(const std::string& name, GameObject* parent) {
		auto obj = new GameObject();
		obj->SetName(name);
		SetParent(obj, parent);
		return obj;
	}

	bool Scene::SetParent(GameObject* obj, GameObject* parent) {
		bool result = false;
		auto currentParent = obj->GetParent();

		// Create as root object
		if (parent == nullptr) {
			// Case 1: Object has parent, move to root
			if (currentParent != nullptr) {
				auto i = std::find_if(
					currentParent->m_children.begin(),
					currentParent->m_children.end(),
					[obj](const std::unique_ptr<GameObject>& el) {
						return el.get() == obj;
					}
				);

				if (i != currentParent->m_children.end()) {
					m_objects.push_back(std::move(*i));
					obj->m_parent = nullptr;
					currentParent->m_children.erase(i);
					result = true;
				}
			} 
			
			// Case 2: No parent currently, move to root
			else {
				auto i = std::find_if(
					m_objects.begin(),
					m_objects.end(),
					[obj](const std::unique_ptr<GameObject>& el) {
						return el.get() == obj;
					}
				);

				if (i == m_objects.end()) {
					std::unique_ptr<GameObject> objHolder(obj);
					m_objects.push_back(std::move(objHolder));
					result = true;
				}
			}
		} 
		
		// Create as a child of another object
		else {
			// Case 3: Object alreadty has parent, move to new parent
			if (currentParent != nullptr) {
				auto i = std::find_if(
					currentParent->m_children.begin(),
					currentParent->m_children.end(),
					[obj](const std::unique_ptr<GameObject>& el) {
						return el.get() == obj;
					}
				);

				if (i != currentParent->m_children.end()) {
					bool found = false;
					auto currentElement = parent;
					while (currentElement) {
						if (currentElement == obj) {
							found = true;
							break;
						}
						currentElement = currentElement->GetParent();
					}

					if (!found) {
						parent->m_children.push_back(std::move(*i));
						obj->m_parent = parent;
						currentParent->m_children.erase(i);
						result = true;
					}
				}
			} 

			// Case 4: No parent currently, move to new parent
			else {
				auto i = std::find_if(
					m_objects.begin(),
					m_objects.end(),
					[obj](const std::unique_ptr<GameObject>& el) {
						return el.get() == obj;
					}
				);

				if (i == m_objects.end()) {
					std::unique_ptr<GameObject> objHolder(obj);
					parent->m_children.push_back(std::move(objHolder));
					obj->m_parent = parent;
					result = true;
				} else {
					bool found = false;
					auto currentElement = parent;
					while (currentElement) {
						if (currentElement == obj) {
							found = true;
							break;
						}
						currentElement = currentElement->GetParent();
					}

					if (!found) {
						parent->m_children.push_back(std::move(*i));
						obj->m_parent = parent;
						m_objects.erase(i);
						result = true;
					}
				}
			}
		}

		return result;
	}
}