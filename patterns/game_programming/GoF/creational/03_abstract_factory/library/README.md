Parameters of CTest:
    --test-dir <ut_path>
    -L "^label$"
    --output-on-failure, to show stdout and sterr of failing tests.

CMake:
    - include(CMakePackageConfigHelpers), with the -s;
    - configure_package_config_file(), with configure_ before _config_;
    - set_tests_properties().