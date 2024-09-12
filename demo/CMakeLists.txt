include(FTXUI)

set(executables demo_screen demo_element demo_component demo_event demo_loop)

foreach(executable ${executables})
  add_executable(${executable} ${executable}.cpp)
  target_compile_options(${executable}
    PRIVATE ${DEFAULT_CXX_COMPILE_FLAGS}
    PRIVATE ${DEFAULT_CXX_OPTIMIZE_FLAG}
  )
  target_link_libraries(${executable}
    PRIVATE ftxui::screen
    PRIVATE ftxui::dom
    PRIVATE ftxui::component
  )
  Format(${executable} .)
endforeach()
