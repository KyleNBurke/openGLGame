.DEFAULT_GOAL := game.exe
incDir = -I C:/Users/kylen/Development/dependencies/openGL/include
libDir = -L C:/Users/kylen/Development/dependencies/openGL/lib
libFiles = -l glfw3 -l gdi32 -l opengl32
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2)$(filter $(subst *,%,$2),$d))
src = $(call rwildcard,src/,*.cpp *.c)
dep = $(wildcard build/*.d)
-include $(dep)

obj :=
define objFromSrc
$(1): $(2)
obj += $(1)

endef

$(eval $(foreach t,$(src),$(call objFromSrc,$(patsubst %,build/%.o,$(basename $(notdir $(t)))),$(t))))

$(obj): %.o:
	g++ -c -g -std=c++17 -MMD -msse $(incDir) -o $@ $<

game.exe: $(obj)
	g++ $(libDir) -o $@ $^ $(libFiles)

.PHONY: clean
clean:
	del build\*.o build\*.d

.PHONY: rebuild
rebuild:
	mingw32-make clean
	mingw32-make
