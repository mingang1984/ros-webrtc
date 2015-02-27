#ifndef ROS_WEBRTC_UTIL_H_
#define ROS_WEBRTC_UTIL_H_

#include <initializer_list>
#include <string>

/**
 * \brief Removes unsupported characters from a ROS name (see http://wiki.ros.org/Names#Valid_Names-1).
 * \param group The name to normalize.
 * \return The normalized name.
 */
std::string normalize_name(const std::string& name);

/**
 * \brief Builds (e.g. name spaces, normalizes, etc) a ROS topic from its parts.
 * \param parts List of parts.
 * \return The ROS topic.
 */
std::string topic_for(std::initializer_list<std::string> part);

/**
 * \brief Builds (e.g. name spaces, normalized, etc) a ROS service name.
 * \param name Base service name.
 * \return The ROS service name.
 */
std::string service_for(const std::string& name);

/**
 * \brief Builds (e.g. name spaces, normalized, etc) a ROS param.
 * \param name Base param name.
 * \return The ROS param name.
 */
std::string param_for(const std::string& name);

/**
 * \brief Generates a unique id.
 * \return The unique id as a string.
 */
std::string generate_id();

#endif /* ROS_WEBRTC_UTIL_H_ */
