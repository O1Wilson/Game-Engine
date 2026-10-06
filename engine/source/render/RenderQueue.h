#pragma once
#include <glm/mat4x4.hpp>

#include <vector>

namespace eng {
	class GraphicsAPI;
	class Material;
	class Mesh;
	struct RenderCommand {
		Material* material = nullptr;
		Mesh* mesh = nullptr;
		glm::mat4 modelMatrix;
	};

	class RenderQueue {
		public:
			void Submit(const RenderCommand& command);
			void Draw(GraphicsAPI& graphicsAPI);

		private:
			std::vector<RenderCommand> m_commands;
	};
}