#!/usr/bin/env bash
build_dir=${1:-./cmake-build-debug}
>&2 echo "| Using build dir: ${build_dir}"

for t in "$build_dir"/test_*; do
    echo "| Running $t...";
    "$t";
done
