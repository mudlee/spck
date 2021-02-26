#pragma once

#include <spck/spck.hpp>

class sandbox : public spck::application {
public:
    using spck::application::application;

    ~sandbox() override = default;
};
