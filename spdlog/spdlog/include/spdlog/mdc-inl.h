// Copyright(c) 2015-present, Gabi Melman & spdlog contributors.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef SPDLOG_HEADER_ONLY
#include <spdlog/mdc.h>
#endif

namespace spdlog {

SPDLOG_INLINE mdc::mdc_map_t &mdc::get_context() {
    static thread_local mdc_map_t context;
    return context;
}

}  // namespace spdlog
