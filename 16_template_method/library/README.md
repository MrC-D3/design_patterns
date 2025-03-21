GTest:
    - for fixture, public inherit but protect members class.

Parameters of ctest:
    --test-dir unit_test, to specify where CTestTestfile.cmake is.
    --output-on-failure, to show stdout and sterr of failing tests;
    --no-compress-output, to show the full output;
    --output-junit results.xml, to export the result in a JUnit XML file.

CMake:
    - the file to include in Config.cmake.in has the .cmake extension.