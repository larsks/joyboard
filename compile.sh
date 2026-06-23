#!/bin/bash

o_update=0

while getopts u ch; do
  case $ch in
  u) o_update=1 ;;
  \?) exit 2 ;;
  esac
done
shift $((OPTIND - 1))

set -e

if type podman >&/dev/null; then
  container_runtime=podman
elif type docker >&/dev/null; then
  container_runtime=docker
else
  echo "ERROR: no container runtime available" >&2
  exit 1
fi

echo "## Using $container_runtime as container runtime"

if ! [[ -d qmk_firmware ]]; then
  cat <<EOF

##
## Cloning qmk_firmware repository.
##

EOF
  git clone --filter blob:none --recursive https://github.com/qmk/qmk_firmware qmk_firmware
fi

if ((o_update)); then
  cat <<EOF

##
## Updating qmk_firmware repository
##

EOF
  git -C qmk_firmware pull
fi

cat <<EOF

##
## Building joyboard firmware
##

EOF
"$container_runtime" run --rm -it \
  -v "$PWD/qmk_firmware:/qmk_firmware:z" \
  -v "$PWD:/qmk_firmware/keyboards/joyboard:z" \
  -w /qmk_firmware \
  ghcr.io/qmk/qmk_cli \
  qmk compile -kb joyboard -km default
