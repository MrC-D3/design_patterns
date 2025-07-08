What I did on a fresh ubuntu:22.04 docker container:
    apt-get update
    apt-get install -y 
        locales
        git
        python-is-python3
        python3-pip
        gcc-9
        vim
        gdb
        wget
    pip install
        cmake==3.25.2
        conan==1.59.0
    Install from source:
        GTest
        Boost 