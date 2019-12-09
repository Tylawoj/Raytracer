#include "Light.h"
#include "Scene.h"
#include "Sphere.h"

Scene::Scene()
{
    std::shared_ptr<Sphere> sphere = std::make_shared<Sphere>(glm::vec3(0.0f, 0.0f, -2.0f), 1.0f);
	m_objects = std::make_shared<std::vector<std::shared_ptr<Object>>>();
	m_objects->push_back(sphere);

    std::shared_ptr<Light> light = std::make_shared<Light>(glm::vec3(255.0f, 255.0f, 255.0f), 0.4f);
    m_lights = std::make_shared<std::vector<std::shared_ptr<Light>>>();
    m_lights->push_back(light);
}

std::shared_ptr<std::vector<std::shared_ptr<Object>>> Scene::getObjects()
{
    return m_objects;
}

std::shared_ptr<std::vector<std::shared_ptr<Light>>> Scene::getLights()
{
    return m_lights;
}
