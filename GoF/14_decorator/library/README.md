Notes:
    - include(CMakePackageConfigHelpers) -> configure_package_config_file();
    - the EXPORT file is created and directly installed;
    - the Config file is first created and secondly installed;
    - the GTest libraries to link are all in lowercase;
    - the header of GMock is <gmock/gmock.h>;