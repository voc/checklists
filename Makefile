SOURCE_DIR := source
BUILD_DIR := build
OUTPUT_DIR := pdf

SOURCES := $(wildcard $(SOURCE_DIR)/*.tex)
PDFS := $(patsubst $(SOURCE_DIR)/%.tex,$(OUTPUT_DIR)/%.pdf,$(SOURCES))

.PHONY: all prepare_directories cleanup list_sources

all: $(PDFS)

prepare_directories:
	mkdir -p $(BUILD_DIR) $(OUTPUT_DIR)

$(OUTPUT_DIR)/%.pdf: $(SOURCE_DIR)/%.tex | prepare_directories
	xelatex -output-directory=$(BUILD_DIR) $<
	xelatex -output-directory=$(BUILD_DIR) $<
	xelatex -output-directory=$(BUILD_DIR) $<
	mv $(BUILD_DIR)/$*.pdf $@

cleanup:
	@echo Removing $(BUILD_DIR)
	rm -rf $(BUILD_DIR)

list_sources:
	@for i in $(SOURCES); do echo $$i; done