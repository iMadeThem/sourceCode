#!/usr/bin/env bash
set -e
set -u
set -o pipefail

REPO_ROOT="$(git rev-parse --show-toplevel)"
echo $REPO_ROOT

for cmd in "${REPO_ROOT}"/tools/git-hooks/pre-commit.d/*
do
    . "$cmd"
done
