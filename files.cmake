# list bluekyulib/
set(header_root
    "${PROJECT_SOURCE_DIR}/bluekyulib/string.hpp"
)

set(header_system
    "${PROJECT_SOURCE_DIR}/bluekyulib/system/path.hpp"
)

set(bluekyulib_headers
    ${header_root}
    ${header_system}
)

# grouping
source_group("bluekyulib" FILES ${header_root})
source_group("bluekyulib\\system" FILES ${header_system})



# list src/
set(bluekyulib_sources
)

# grouping
