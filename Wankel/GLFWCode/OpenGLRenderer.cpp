#include"pch.h"

#include"OpenGLRenderer.h"
#include"Utilities.h" ////uncommenting fixes some errors, not perm, also in GLFWImplementation.cpp

#include"../glad/include/glad/glad.h"
#include"../glfw/include/GLFW/glfw3.h"

namespace wk
{
	void OpenGLRenderer::Init()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			WK_ERROR("Failed to initialize GLAD");
			return;
		}

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void OpenGLRenderer::Draw(int x, int y, Picture& pic)
	{
		float vertices[] = {
			(float)x, (float)y, 0.0f, 0.0f,
			(float)x + pic.GetWidth(), (float)y, 1.0f, 0.0f,
			(float)x, (float)y + pic.GetHeight(), 0.0f, 1.0f,
			(float)x + pic.GetWidth(), (float)y + pic.GetHeight(), 1.0f, 1.0f

		};

		unsigned int indices[] = {
			0, 1, 2,
			1, 2, 3
		};

		unsigned int VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		unsigned int VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		unsigned int EBO;
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
		glEnableVertexAttribArray(1);

		pic.Bind();

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
		glDeleteVertexArrays(1, &VAO);
	}

	void OpenGLRenderer::Clear()
	{
		glClearColor(0.8f, 0.4f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}