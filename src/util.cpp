#include "util.h"

#include <cctype>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>
#include <ros/ros.h>

std::string normalize_name(const std::string& name) {
    std::string normalized;
    normalized.reserve(name.size());
    size_t i = 0;
    if (isalpha(name[i])) {
        normalized += name[i];
    }
    i++;
    for(; i != name.size(); i++) {
        if (isalnum(name[i]) || name[i] == '_' || name[i] == '/') {
            normalized += name[i];
        }
    }
    return normalized;
}

std::string topic_for(std::initializer_list<std::string> parts) {
    std::string path = "";
    for(auto part : parts) {
        path = ros::names::append(path, normalize_name(part));
    }
    return path;
}

std::string service_for(const std::string& name) {
    return normalize_name(name);
}

std::string topic_for(const std::string& name) {
    return normalize_name(name);
}

std::string param_for(const std::string& name) {
    return normalize_name(name);
}

std::string generate_id() {
    boost::uuids::uuid uuid = boost::uuids::random_generator()();
    return boost::lexical_cast<std::string>(uuid);
}
