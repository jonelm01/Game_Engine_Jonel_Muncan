#pragma once

#include"pch.h"
#include"ShaderImplementation.h"

namespace wk
{
	class OpenGLShader : public ShaderImplementation
	{
	public:
		OpenGLShader(const std::string& vertexSF, const std::string& fragmentSF);
		OpenGLShader(std::string&& vertexSF, std::string&& fragmentSF);

		void Bind() override;

		virtual void SetUniform2Ints(const std::string& uniformName, int val1, int val2) override;
		virtual void SetUniform2Ints(std::string&& uniformName, int val1, int val2) override;

		~OpenGLShader();

	private:
		unsigned int mShaderProgram;

		std::string ReadWholeFile(const std::string& fileName); //l-type, var = "file.txt"; foo(var);
		std::string ReadWholeFile(std::string&& fileName); //r-type reference to temp string, foo("file.txt")
	};
}