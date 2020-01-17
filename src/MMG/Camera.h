#include <glm/ext.hpp>

/** \brief Viewpoint from which everything is renderered.
*/
class Camera
{
public:
	/** \brief Initialises Camera, sets aspect ratio.
		\param _winW Window width
		\param _winH Window height
	*/
	Camera(const int& _winW, const int& _winH);

	/** \brief Moves the camera.
		\param _step Vector3 distance to move
	*/
	void move(const glm::vec3& _step);

	/** \brief Rotates the camera.
		\param _step Vector3 amount to rotate
	*/
	void rotate(const glm::vec3& _step);

	/** \brief Setter for the camera's position.
		\param _position New position
	*/
	void setPosition(const glm::vec3& _position);

	/** \brief Setter for the camera's rotation.
		\param _rotation New rotation
	*/
	void setRotation(const glm::vec3& _rotation);

	/** \brief Getter for the camera's position.
		\return Camera::position
	*/
	glm::vec3 getPosition();

	/** \brief Getter for the camera's rotation.
		\return Camera::rotation
	*/
	glm::vec3 getRotation();

	/** \brief Getter for the camera's projection matrix.
		\return Camera::projection
	*/
	glm::mat4 getProjection();

	/** \brief Getter for the camera's view matrix.
		\return Camera::view
	*/
	glm::mat4 getView();

private:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::mat4 projection;
	glm::mat4 view;
};
