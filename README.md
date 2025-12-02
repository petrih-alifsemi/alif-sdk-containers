# ZAS Build Containers
Docker containers to build Alif Semiconductor Zephyr SDK.

# Getting Containers
You can simple pull a container using command line

```
$ docker pull ghcr.io/petrih-alifsemi/sdk-alif:zas-main
```

There are different version which can be found from [here](https://github.com/petrih-alifsemi/alif-sdk-containers/pkgs/container/sdk-alif).

# Using Containters

## Legacy Style
You can start the container by running

```
$ docker run --rm -it -v "${PWD}/sample_app:/root/alif/myapp" ghcr.io/petrih-alifsemi/sdk-alif:zas-main /bin/bash
```

or for example directly running a build command for Balletto device

```
$ docker run --rm -it -v "${PWD}/sample_app:/root/alif/myapp" ghcr.io/petrih-alifsemi/sdk-alif:zas-main west build -b alif_b1_dk/ab1c1f4m51820ph0/rtss_he myapp
```

## Docker Compose

[Docker compose](https://docs.docker.com/compose/) can be used to simplify build process.
You can check [the sample](compose.yaml).
