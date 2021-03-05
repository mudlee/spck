#pragma once

#define DELETE_COPY_METHODS(type) \
    type(const type &) = delete; \
    type &operator=(const type &) = delete;
