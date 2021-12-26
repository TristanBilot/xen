# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.209.6/containers/debian/.devcontainer/base.Dockerfile

# [Choice] Debian version (use bullseye or stretch on local arm64/Apple Silicon): bullseye, buster, stretch
ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}

RUN apt-get update
RUN apt-get install -y make gcc libc6-dev zlib1g-dev libncurses5-dev patch libvncserver-dev libsdl-dev libjpeg62-turbo-dev
RUN apt-get install -y iasl libbz2-dev e2fslibs-dev git-core uuid-dev ocaml ocaml-findlib libx11-dev bison flex xz-utils libyajl-dev
RUN apt-get install -y gettext libpixman-1-dev libaio-dev markdown pandoc
RUN apt-get install -y libglib2.0-dev ninja-build python python-dev python3-dev

WORKDIR /app
COPY . .
RUN ls

RUN ./configure
RUN make dist
RUN ./dist/install.sh
RUN /sbin/ldconfig -v

# ** [Optional] Uncomment this section to install additional packages. **
# RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
#     && apt-get -y install --no-install-recommends <your-package-list-here>

