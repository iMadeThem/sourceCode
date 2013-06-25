#!/usr/bin/env bash
set -e
set -u
set -o pipefail

THIS_DIR="$( dirname "${BASH_SOURCE[0]}" )"
REPO_ROOT=$( cd "$THIS_DIR/../../" && pwd )
echo $REPO_ROOT

for cmd in "${REPO_ROOT}"/tools/git-hooks/pre-commit.d/*
do
    . "$cmd"
done
