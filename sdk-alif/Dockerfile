# Based on Debian 12 (Bookworm) + Python 3.12
FROM python:3.12-slim-bookworm

ARG SDK_DIR=/root/alif

ENV PATH=$PATH:/root/.local/bin:${SDK_DIR}/zephyr/scripts \
    PIP_ROOT_USER_ACTION=ignore \
    ZEPHYR_TOOLCHAIN_VARIANT=zephyr

## Required system packages
RUN apt update && \
    apt install --fix-missing && \
    apt install --no-install-recommends --yes \
        git cmake ninja-build gperf \
        ccache dfu-util device-tree-compiler wget xz-utils \
        file make gcc gcc-multilib g++-multilib libsdl2-dev libmagic1 \
        vim nano less curl openssh-client unzip ruby && \
    apt-get clean && rm -rf /var/lib/apt/lists/* && \
    python3 -m pip install --no-cache-dir --upgrade pip && \
    pip3 install --no-cache-dir wheel six setuptools west \
        grpcio==1.65.5 grpcio-tools==1.65.5 protobuf==5.27.2 && \
    rm -rf /root/.cache/pip && \
    echo 'if [ "$GH_USER" ]; then echo "machine github.com login ${GH_USER} password ${GH_PASSWORD}" > ~/.netrc ; fi' >> /etc/bash.bashrc && \
    git config --system --add safe.directory "*" && \
    git config --system advice.detachedHead false && \
    ssh-keyscan -t rsa,dsa,ed25519 github.com 2>&1|sort -u - >> /etc/ssh/ssh_known_hosts && \
    /bin/echo -e "Host *\n  StrictHostKeyChecking=no" > /etc/ssh/ssh_config.d/01-ssh.conf && \
    chmod 644 /etc/ssh/ssh_config.d/01-ssh.conf && \
    echo 'python3 -m grpc_tools.protoc "$@"' >> /usr/bin/protoc && chmod +x /usr/bin/protoc && \
    echo "max_size = 5.0G" >> /etc/ccache.conf && \
    echo "cache_dir = /tmp/ccache" >> /etc/ccache.conf

## Toolchain (Zephyr SDK)
ARG ZEPHYR_SDK_VERSION=0.16.9
RUN wget -c https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v${ZEPHYR_SDK_VERSION}/zephyr-sdk-${ZEPHYR_SDK_VERSION}_linux-x86_64_minimal.tar.xz -O - \
    | tar -JxC /opt && \
    /opt/zephyr-sdk-${ZEPHYR_SDK_VERSION}/setup.sh -t arm-zephyr-eabi

## Alif SDK
ARG SDK_URL=https://github.com/alifsemi/sdk-alif.git
ARG SDK_VERSION=main
RUN mkdir -p ${SDK_DIR} && cd ${SDK_DIR} && \
    west init -m ${SDK_URL} --mr ${SDK_VERSION} && \
    west update && \
    west zephyr-export && \
    pip3 install --no-cache-dir -r zephyr/scripts/requirements.txt && \
    pip3 install --no-cache-dir -r bootloader/mcuboot/scripts/requirements.txt && \
    chmod -R u+rwX,go+rwX ${SDK_DIR} && \
    rm -rf /root/.cache/pip

CMD ["/bin/bash"]
WORKDIR ${SDK_DIR}
