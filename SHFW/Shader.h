#ifndef SHADER_H
#define SHADER_H

class Shader
{
public:
	Shader();
	virtual ~Shader();

	GLint programID() { return _programID; };

	GLint matrixID() { return _matrixID; };

	GLint textureID() { return _textureID; };

	GLint blendColorID() { return _blendColorID; };

	GLint uvOffsetID() { return _uvOffsetID; };

	GLint customParamsID(int i) { return _customParamsID[i]; };

	GLint paletteID() { return _paletteID; };

	GLuint loadShaders(const char * vertex_file_path, const char * fragment_file_path);

private:
	GLint _programID;
	GLint _matrixID;
	GLint _textureID;
	GLint _blendColorID;
	GLint _uvOffsetID;
	GLint _customParamsID[8];
	GLint _paletteID;

	void _attachID();
};

#endif
