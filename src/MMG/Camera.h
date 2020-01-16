#include <glm/ext.hpp>

class Camera
{
public:
	Camera(const int& _winW, const int& _winH);

	void move(const glm::vec3& _step);
	void rotate(const glm::vec3& _step);

	void setPosition(const glm::vec3& _position);
	void setRotation(const glm::vec3& _rotation);
	glm::vec3 getPosition();
	glm::vec3 getRotation();
	glm::mat4 getProjection();
	glm::mat4 getView();

private:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::mat4 projection;
	glm::mat4 view;
};
