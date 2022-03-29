# Set 
SOURCE_DIR := source
BUILD_DIR := build
OUTPUT_DIR := pdf

SOURCES := $(wildcard $(SOURCE_DIR)/*.tex)

all: prepare_directories compile publish cleanup

prepare_directories:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(OUTPUT_DIR)

compile: $(SOURCES)
	@echo Building $^ from source
	xelatex -output-dir=$(BUILD_DIR) $^

publish:
	mv $(BUILD_DIR)/*.pdf $(OUTPUT_DIR)

cleanup:
	@echo Removing $(BUILD_DIR)
	rm -rf $(BUILD_DIR)