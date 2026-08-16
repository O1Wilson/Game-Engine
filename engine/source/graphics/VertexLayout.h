#pragma once
#include <GL/glew.h>

#include <vector>
#include <stdint.h>

namespace eng {
	struct VertexElement {
		GLuint index; // Attribute location
		GLuint size; // Number of components
		GLuint type; // Data type (e.g. GL_FLOAT)
		uint32_t offset; // Byte offset from start of vertex
	};

	struct VertexLayout {
		std::vector<VertexElement> elements;
		uint32_t stride = 0; // Memory size of vertex
	};
}