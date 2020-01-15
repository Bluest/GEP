#include <rend.h>

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Material.h"
#include "Core.h"

Material::Material(const std::shared_ptr<Core>& _core, const std::string& _name) : Resource(_core, _name)
{
	std::cout << " <Material> from \"";
}

void Material::onLoad(const std::string& _path)
{
	std::cout << _path << "\"" << std::endl;
	
	const char* src =
		"#ifdef VERTEX                                 \n" \
		"                                              \n" \
		"attribute vec3 a_Position;                    \n" \
		"attribute vec2 a_TexCoord;                    \n" \
		"attribute vec3 a_Normal;                      \n" \
		"                                              \n" \
		"uniform mat4 u_Projection;                    \n" \
		"uniform mat4 u_Model;                         \n" \
		"                                              \n" \
		"varying vec3 v_Normal;                        \n" \
		"varying vec2 v_TexCoord;                      \n" \
		"                                              \n" \
		"void main()                                   \n" \
		"{                                             \n" \
		"  gl_Position = u_Projection *                \n" \
		"    u_Model * vec4(a_Position, 1);            \n" \
		"                                              \n" \
		"  v_Normal = a_Normal;                        \n" \
		"  v_TexCoord = a_TexCoord;                    \n" \
		"}                                             \n" \
		"                                              \n" \
		"#endif                                        \n" \
		"#ifdef FRAGMENT                               \n" \
		"                                              \n" \
		"uniform sampler2D u_Texture;                  \n" \
		"                                              \n" \
		"varying vec3 v_Normal;                        \n" \
		"varying vec2 v_TexCoord;                      \n" \
		"                                              \n" \
		"void main()                                   \n" \
		"{                                             \n" \
		"  gl_FragColor = texture2D(u_Texture, v_TexCoord);      \n" \
		"  if(gl_FragColor.x == 9) gl_FragColor.x = v_Normal.x;  \n" \
		"}                                             \n" \
		"                                              \n" \
		"#endif                                        \n";

	shader = core->getRendContext()->createShader();
	shader->parse(src);

	texture = core->getRendContext()->createTexture();

	int w = 0, h = 0, comp = 0;

	unsigned char* tex = stbi_load(_path.c_str(), &w, &h, &comp, 3);

	if (!tex)
		throw rend::Exception("Failed to open texture file");

	texture->setSize(w, h);

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int r = y * w * 3 + x * 3;

			texture->setPixel(x, y, glm::vec3(
				tex[r] / 255.0f,
				tex[r + 1] / 255.0f,
				tex[r + 2] / 255.0f));
		}
	}

	stbi_image_free(tex);
}

std::sr1::shared_ptr<rend::Shader> Material::getShader()
{
	return shader;
}

std::sr1::shared_ptr<rend::Texture> Material::getTexture()
{
	return texture;
}
