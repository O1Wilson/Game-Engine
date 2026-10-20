#include <glm/gtc/matrix_transform.hpp>

#include "scene/components/Camera.h"
#include "scene/GameObject.h"

namespace eng {
	void Camera::Update(float deltaTime) {

	}

	glm::mat4 Camera::GetViewMatrix() const {
		return glm::inverse(m_owner->GetWorldTransform());
	}

	glm::mat4 Camera::GetProjectionMatrix(float aspect) const {
		return glm::perspective(glm::radians(m_fov), aspect, m_nearPlane, m_farPlane);
	}
}