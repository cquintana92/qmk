SHELL:=/bin/bash
MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
PROJECT_ROOT := $(dir $(MAKEFILE_PATH))

QMK_ROOT:=${PROJECT_ROOT}/qmk
QMK_USERNAME:=cquintana92

QMK_CONF_DIR:="${HOME}/Library/Application Support/qmk"

.PHONY: default
default: help

.PHONY: fmt
fmt: ## Run clang-format
	@clang-format -style="file" -i ${PROJECT_ROOT}keychronv6/keymap.c
	@clang-format -style="file" -i ${PROJECT_ROOT}keychronq11/keymap.c

.PHONY: setup
setup: ## Initial repo setup
	@ln -sf ${PROJECT_ROOT}keychronv6/ ${QMK_ROOT}/keyboards/keychron/v6/iso_encoder/keymaps/${QMK_USERNAME}
	@ln -sf ${PROJECT_ROOT}keychronq11/ ${QMK_ROOT}/keyboards/keychron/q11/iso_encoder/keymaps/${QMK_USERNAME}

.PHONY: link-v6
link-v6: ## Set Keychron V6 as current keyboard
	@mkdir -p ${HOME}/.config/qmk/
	@ln -sf ${PROJECT_ROOT}/qmk.v6.ini ${HOME}/.config/qmk/qmk.ini
	@mkdir -p ${QMK_CONF_DIR}
	@ln -sf ${PROJECT_ROOT}/qmk.v6.ini ${QMK_CONF_DIR}/qmk.ini

.PHONY: link-q11
link-q11: ## Set Keychron Q11 as current keyboard
	@mkdir -p ${HOME}/.config/qmk/
	@ln -sf ${PROJECT_ROOT}/qmk.q11.ini ${HOME}/.config/qmk/qmk.ini
	@mkdir -p ${QMK_CONF_DIR}
	@ln -sf ${PROJECT_ROOT}/qmk.q11.ini ${QMK_CONF_DIR}/qmk.ini

.PHONY: build
build: ## Build firmware
	@cd qmk && qmk compile

.PHONY: flash-v6
flash-v6: ## Flash firmware (V6)
	@qmk flash qmk/keychron_v6_iso_encoder_cquintana92.bin

.PHONY: flash-q11
flash-q11: ## Flash firmware (Q11)
	@qmk flash qmk/keychron_q11_iso_encoder_cquintana92.bin

.PHONY: help
help: ## Display this help screen
	@grep -h -E '^[a-zA-Z0-9_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
