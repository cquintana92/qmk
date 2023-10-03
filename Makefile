SHELL:=/bin/bash
MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
PROJECT_ROOT := $(dir $(MAKEFILE_PATH))

QMK_ROOT:=${PROJECT_ROOT}/qmk
QMK_USERNAME:=cquintana92

.PHONY: default
default: help

.PHONY: link
link: ## Create symlinks
	@mkdir -p ${HOME}/.config/qmk/
	@ln -sf ${PROJECT_ROOT}/qmk.ini ${HOME}/.config/qmk/qmk.ini
	@ln -sf ${PROJECT_ROOT}keychronv6/ ${QMK_ROOT}/keyboards/keychron/v6/iso_encoder/keymaps/${QMK_USERNAME}

.PHONY: build
build: ## Build firmware
	@cd qmk && qmk compile

.PHONY: flash
flash: ## Flash firmware
	@qmk flash qmk/keychron_v6_iso_encoder_cquintana92.bin

.PHONY: help
help: ## Display this help screen
	@grep -h -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
