#pragma once
#include "scene/Component.h"

namespace eng {
	class PlayerController : public Component {
		COMPONENT(PlayerController)
		
		public:
			void Update(float deltaTime) override;

		private:
			float m_sensitivity = 0.3f;
			float m_moveSpeed = 1.0f;
	};
}