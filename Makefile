# GNU Make solution makefile autogenerated by Premake

.NOTPARALLEL:

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  gamebae_config = debug
endif
ifeq ($(config),release)
  gamebae_config = release
endif

PROJECTS := gamebae

.PHONY: all clean help $(PROJECTS)

all: $(PROJECTS)

gamebae:
ifneq (,$(gamebae_config))
	@echo "==== Building gamebae ($(gamebae_config)) ===="
	@${MAKE} --no-print-directory -C . -f gamebae.make config=$(gamebae_config)
endif

clean:
	@${MAKE} --no-print-directory -C . -f gamebae.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   gamebae"
	@echo ""
	@echo "For more information, see http://industriousone.com/premake/quick-start"
