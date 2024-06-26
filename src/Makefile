CFORMAT 	= clang-format

.PHONY = fomrat verify_format

all: format

format:
	$(CFORMAT) -i -style=file ../include/*.h *.cpp

verify_format:
	$(CFORMAT) -i -style=file ../include/*.h *.cpp --dry-run --Werror
