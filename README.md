What I did on a fresh ubuntu:22.04 docker container:
    apt-get update
    apt-get install -y 
        locales
        git
        python-is-python3
        python3-pip
        gcc-9
    pip install
        cmake==3.25.2
    Install GTest 