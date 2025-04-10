CMake:
    - @PACKAGE_INIT@, no spaces.

CTest parameters:
    --test-dir <ut_path>
    --L "^label$"
    --output-on-failure, to show stdout and sterr of failing tests.
    --no-compress-output, to show the full output.
    --output-junit ctest_result.xml, for high-level result in a JUnit XML file.