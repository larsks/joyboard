#!/bin/bash

VENDOR_ID=1209
PRODUCT_ID=2642

grab=()
while [ $# -gt 0 ]; do
    case "$1" in
    -g | --grab)
        grab=(grab)
        shift
        ;;
    *)
        echo "Unknown option: $1" >&2
        exit 1
        ;;
    esac
done

args=()
for dev in /dev/input/event*; do
    info=$(udevadm info "$dev" 2>/dev/null)
    if echo "$info" | grep -q "ID_VENDOR_ID=$VENDOR_ID" &&
        echo "$info" | grep -q "ID_MODEL_ID=$PRODUCT_ID"; then
        echo "Found $dev" >&2
        args+=(--input "$dev" "${grab[@]}")
    fi
done
echo

if [ ${#args[@]} -eq 0 ]; then
    echo "No Joyboard devices found" >&2
    exit 1
fi

exec evsieve "${args[@]}" --print
