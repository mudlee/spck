#pragma once

#include <spck/renderer/backend/opengl/vendor.hpp>
#include <spck/renderer/shader.hpp>

namespace spck {

class type_converter {
public:
    static GLenum shader_data_type_to_gl_enum(shader::data_type data_type){
        switch(data_type) {
        case shader::data_type::FLOAT:
            return GL_FLOAT;
        }
    }
};

}