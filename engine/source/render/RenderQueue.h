#pragma once
#include <vector>

namespace eng {
	class GraphicsAPI;
	class Material;
	class Mesh;
	struct RenderCommand {
		Material* material = nullptr;
		Mesh* mesh = nullptr;
	};

	class RenderQueue {
		public:
			void Submit(const RenderCommand& command);
			void Draw(GraphicsAPI& graphicsAPI);

		private:
			std::vector<RenderCommand> m_commands;
	};
}