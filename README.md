What to do on a docker container (ubuntu:20.04 or 22.04):
    apt-get update
    apt-get install -y 
        locales
        git
        python-is-python3
        python3-pip
        gcc-10
        g++-10, for C++20
        vim
        gdb
        wget
    pip install
        cmake==3.25.2
        conan==1.59.0
    Install from source:
        GTest
        Boost
        Valgrind

What to do to work with GitHub Actions CI/CD.
- Create at least one .yml/.yaml file in .github/workflows/. 
- You can name it as you want. 
- You can even have more than one (e.g.: main, docs, etc.) and each will create 
an indipendent workflow.
- https://github.com/actions/runner-images: available images to run on.