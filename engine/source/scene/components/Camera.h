#pragma once

#include "glm/mat4x4.hpp"

#include "scene/Component.h"

namespace eng {
	class Camera : public Component {
		COMPONENT(Camera)
		public:
			void Update(float deltaTime) override;

			glm::mat4 GetViewMatrix() const;
			glm::mat4 GetProjectionMatrix(float aspect) const;

		private:
			float m_fov = 60.0f;
			float m_nearPlane = 0.1f;
			float m_farPlane = 1000.0f;
	};
}