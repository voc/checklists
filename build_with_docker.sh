#!/bin/bash

docker run --rm -it -v ./:/app -w /app ghcr.io/voc/checklists:latest make all
