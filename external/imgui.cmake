#ImGui
CPMAddPackage(
        NAME IMGUI
        VERSION 1.88
        URL "https://github.com/ocornut/imgui/archive/refs/tags/v1.88.zip"
)
IF(IMGUI_ADDED)
    add_library(IMGUI STATIC)

    target_sources( IMGUI
            PRIVATE
            ${IMGUI_SOURCE_DIR}/imgui_demo.cpp
            ${IMGUI_SOURCE_DIR}/imgui_draw.cpp
            ${IMGUI_SOURCE_DIR}/imgui_tables.cpp
            ${IMGUI_SOURCE_DIR}/imgui_widgets.cpp
            ${IMGUI_SOURCE_DIR}/imgui.cpp

            PRIVATE
            ${IMGUI_SOURCE_DIR}/backends/imgui_impl_sdlrenderer.cpp
            ${IMGUI_SOURCE_DIR}/backends/imgui_impl_sdl.cpp
            )
    target_include_directories( IMGUI
            PUBLIC ${IMGUI_SOURCE_DIR}
            PUBLIC ${IMGUI_SOURCE_DIR}/backends
            )

    target_link_libraries(IMGUI PUBLIC SDL2-static ${CMAKE_DL_LIBS})
ENDIF()