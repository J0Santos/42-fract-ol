#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#
#                                                                           #
#   Makefile                                                                #
#                                                                           #
#    Options:                                                               #
#     (make FLAG=1/0)                                                       #
#     DEBUG -> Compiles with "-g" flag                                      #
#     SANITIZER -> Compiles with "-g" and "-fsanitize=address" flags        #
#     NO_FLAGS -> Compiles without "-Wall", "-Wextra" and "-Werror" flags   #
#                                                                           #
#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#

#######  ~~~   Initial variable setup   ~~~  #######

NAME := fractol
SRCS_DIR := ./srcs
OBJS_DIR := ./objs
SRCS := $(wildcard $(SRCS_DIR)/*/*.c) $(wildcard $(SRCS_DIR)/*.c)
OBJS := $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
DPND := $(OBJS:.o=.d)
INCLUDES := -Iincludes -Ilibraries/libft
LIBFT_PATH := ./libraries/libft/libft.a
COMPILER := clang++
WWW_FLAGS := -Wall -Wextra -Werror
OPT_FLAGS := -O3
INC_FLAGS := -MD
TMP_FILE := Makefile.tmp

#######  ~~~   Compilation setup   ~~~  #######

# Ensures that TMP_FILE exists before calling awk
$(shell touch $(TMP_FILE))
# Reads DEBUG option from TMP_FILE if user hasn't provided it
ifndef DEBUG
	ifeq ($(shell awk 'NR==1 {print $$3}' $(TMP_FILE)),1)
		DEBUG = 1
	else
		DEBUG = 0
	endif
else
	PRE_EXECUTE = clean
endif
# Reads SANITIZER option from TMP_FILE if user hasn't provided it
ifndef SANITIZER
	ifeq ($(shell awk 'NR==2 {print $$3}' $(TMP_FILE)),1)
		SANITIZER = 1
	else
		SANITIZER = 0
	endif
else
	PRE_EXECUTE = clean
endif
# Reads NO_FLAGS option from TMP_FILE if user hasn't provided it
ifndef NO_FLAGS
	ifeq ($(shell awk 'NR==3 {print $$3}' $(TMP_FILE)),1)
		NO_FLAGS = 1
	else
		NO_FLAGS = 0
	endif
else
	PRE_EXECUTE = clean
endif
# Configure DEBUG
ifeq ($(DEBUG),1)
	DEBUG_FLAGS = -g
	OPT_FLAGS =
endif
# Configure SANITIZER
ifeq ($(SANITIZER),1)
	DEBUG_FLAGS = -g -fsanitize=address
	OPT_FLAGS =
endif
# Configure NO_FLAGS
ifeq ($(NO_FLAGS),1)
	WWW_FLAGS =
endif
$(shell echo "DEBUG = $(DEBUG)\nSANITIZER = $(SANITIZER)\nNO_FLAGS = $(NO_FLAGS)" > $(TMP_FILE))
ifeq ($(shell uname -s),Linux)
	DEBUGGER = gdb
	CURR_MLX = minilibx_linux
	MLX_FLAGS = -lbsd -Llibraries/$(CURR_MLX) -lmlx -lXext -lX11 -lm
	OS = 2
endif
ifeq ($(shell uname -s),Darwin)
	DEBUGGER = lldb
	CURR_MLX = minilibx_mms
	MLX_FLAGS = -Ilibraries/$(CURR_MLX) -Llibraries/$(CURR_MLX) -lmlx
	CP_CMD = cp ./libraries/$(CURR_MLX)/libmlx.dylib ./
	OS = 1
endif
###############################################
#######  ~~~   Rules and commands setup   ~~~  #######
.PHONY: all
all: $(PRE_EXECUTE)
	@printf "[\e[1;34mPreparing objects\e[0m]\n\n"
	@$(MAKE) $(NAME) --no-print-directory
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(shell [ ! -d $(@D) ] && mkdir -p $(@D))
	$(COMPILER) $(WWW_FLAGS) $(OPT_FLAGS) $(INC_FLAGS) $(DEBUG_FLAGS) -pthread $(INCLUDES) -DOS=$(OS) -c -o $@ $< -Ilibraries/$(CURR_MLX)
$(NAME): $(OBJS)
	@printf "\n[\e[1;34mCompiling libft\e[0m]\n\n"
	@$(MAKE) -C ./libraries/libft
	@$(MAKE) bonus -C ./libraries/libft
	@printf "\n[\e[1;34mCompiling minilibx\e[0m]\n\n"
	@$(MAKE) -C ./libraries/$(CURR_MLX)
	@$(CP_CMD)
	@printf "\n[\e[1;34mCompiling $(NAME)\e[0m]\n\n"
	$(COMPILER) $(WWW_FLAGS) $(OPT_FLAGS) $(INC_FLAGS) $(DEBUG_FLAGS) -pthread $(INCLUDES) $(OBJS) $(MLX_FLAGS) -DOS=$(OS) $(LIBFT_PATH) -o $(NAME)
	@printf "\n[\e[0;32mCompilation done. $(NAME) ready.\e[0m]\n"
.PHONY: clean
clean:
	@printf "[\e[1;33mCleaning\e[0m]\n\n"
	rm -f $(OBJS)
	rm -f $(DPND)
	@$(MAKE) fclean -C ./libraries/libft
	@$(MAKE) clean -C ./libraries/$(CURR_MLX)
	rm -f ./libmlx.dylib
	@$(shell if [[ "$(shell test -d $(OBJS_DIR) && find $(OBJS_DIR) -type f | wc -l)" -eq 0 ]]; then rm -rf $(OBJS_DIR); fi;)
.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	rm -f $(TMP_FILE)
.PHONY: re
re:
	@$(MAKE) fclean --no-print-directory
	@printf "\n"
	@$(MAKE) all --no-print-directory
.PHONY: debug
debug:
	@$(MAKE) all DEBUG=1 --no-print-directory
	@printf "\n[\e[1;34mStarting $(DEBUGGER)\e[0m]\n\n"
	$(DEBUGGER) ./$(NAME)
-include $(DPND)
######################################################






# **************************************************************************** #
#
# fract-ol
#
# **************************************************************************** #

USER := josantos
PROJECT := fract-ol

# **************************************************************************** #
#
# Project Variables
#
# **************************************************************************** #

NAME1 := fractol

NAMES := ${NAME1}

# **************************************************************************** #
#
# Configs
#
# **************************************************************************** #

# Verbose levels
# 0: Make will be totaly silenced
# 1: Make will print echos and printf
# 2: Make will not be silenced but target commands will not be printed
# 3: Make will print each command
# 4: Make will print all debug info
#
# If no value is specified or an incorrect value is given make will print each
# command like if VERBOSE was set to 3.
VERBOSE := 1

GREEN := \e[38;5;118m
YELLOW := \e[38;5;226m
RED := \e[38;5;9m
RESET := \e[0m
_SUCCESS := [${GREEN}SUCCESS${RESET}]
_INFO := [${YELLOW}INFO${RESET}]
_NORM := [${RED}norm${RESET}]
_NORM_SUCCESS := ${GREEN}      OK: ${RESET}
_NORM_INFO := ${YELLOW}FILES No: ${RESET}

# **************************************************************************** #
#
# Compiler and Flags
#
# **************************************************************************** #

CC := gcc
CLIB := ar -rc

CFLAGS := -W -W -W
DFLAGS := -g
OFLAGS := -O3
FSANITIZE := -fsanitize=address

# **************************************************************************** #
#
# Root Folders
#
# **************************************************************************** #

SRC_ROOT := srcs/
INC_ROOT := includes/
LIB_ROOT := libraries/
OBJ_ROOT := objects/
BIN_ROOT := ./

# **************************************************************************** #
#
# Content Folders
#
# **************************************************************************** #


SRC_DIRS_LIST := ${SRC_ROOT}
SRC_DIRS_LIST := $(foreach dl,${SRC_DIRS_LIST},$(subst :,:${SRC_ROOT},${dl}))

SRC_DIRS = $(subst :,${SPACE},${SRC_DIRS_LIST})
OBJ_DIRS = $(subst ${SRC_ROOT},${OBJ_ROOT},${SRC_DIRS})

INC_DIRS = ${INC_ROOT}

# **************************************************************************** #
#
# Files
#
# **************************************************************************** #

SRCS_LIST = $(foreach dl,${SRC_DIRS_LIST},$(subst ${SPACE},:,$(strip $(foreach\
	dir,$(subst :,${SPACE},${dl}),$(wildcard ${dir}*.c)))))
OBJS_LIST = $(subst ${SRC_ROOT},${OBJ_ROOT},$(subst .c,.o,${SRCS_LIST}))

SRCS = $(foreach dir,${SRC_DIRS},$(wildcard ${dir}*.c))
OBJS = $(subst ${SRC_ROOT},${OBJ_ROOT},${SRCS:.c=.o})

INCS := ${addprefix -I,${INC_DIRS}}
INCS += -I${LIB_ROOT}libft

# **************************************************************************** #
#
# VPATHS
#
# **************************************************************************** #

vpath %.o ${OBJ_ROOT}
vpath %.h ${INC_ROOT}
vpath %.c ${SRC_DIRS}

# **************************************************************************** #
#
# Conditions
#
# **************************************************************************** #

ifeq ($(shell uname), Linux)
	MLX = mlx_linux
	MLX_FLAGS = -lbsd -L${LIB_ROOT}${MLX} -lmlx -lXext -lX11 -lm -DOS=1
else ifeq ($(shell uname), Darwin)
	MLX = mlx_mac
	MLX_FLAGS = -I${LIB_ROOT}${MLX} -L${LIB_ROOT}${MLX} -lmlx -DOS=2
	CP_CMD = cp ${LIB_ROOT}${MLX}/libmlx.dylib ./
endif

ifeq (${VERBOSE}, 0)
	MAKEFLAGS += --silent
	BLOCK := &/dev/null
else ifeq (${VERBOSE}, 1)
	MAKEFLAGS += --silent
	AT := @
else ifeq (${VERBOSE}, 2)
	AT := @
else ifeq (${VERBOSE}, 4)
	MAKEFLAGS += --debug=v
endif

# **************************************************************************** #
#
# Mandatory Targets
#
# **************************************************************************** #

.PHONY: all
all: cl ${NAMES}

${NAME1}: ${OBJS}
	${AT} ${MAKE} -C ${LIB_ROOT}libft ${BLOCK}
	${AT} ${MAKE} -C ${LIB_ROOT}${MLX} ${BLOCK}
	${AT} ${CP_CMD} ${BLOCK}
	${AT} ${CC} ${CFLAGS} ${OFLAGS} ${INCS}  ${OBJS} ${MLX_FLAGS} ${LIB_ROOT}libft/libft.a -o $@ ${BLOCK}
	${AT}printf "${_SUCCESS} ${@F} created.\n\n\n" ${BLOCK}
	${AT}printf "${GREEN}HOW TO COMPILE:\n" ${BLOCK}
	${AT}printf "\t[./fractol <fractal> [x] [y] [-p <precision>] [-c <color>]\n" ${BLOCK}
	${AT}printf "\nCOLOR OPTIONS:\n\t1: black and white\n\t2: red\n\t3: green\n\t4: blue\n\t5: mix" ${BLOCK}
	${AT}printf "\n\t If not given any color, default is any other number.\n" ${BLOCK}
	${AT}printf "\nPRECISION OPTIONS:\n\t If not given any precision, default is at 85.\n${RESET}" ${BLOCK}

# **************************************************************************** #
#
# Clean Targets
#
# **************************************************************************** #

.PHONY: cl
cl:
	${AT}clear ${BLOCK}

.PHONY: clean
clean:
	${AT}mkdir -p ${OBJ_ROOT} ${BLOCK}
	${AT}find ${OBJ_ROOT} -type f -delete ${BLOCK}
	${AT} ${MAKE} fclean -C ${LIB_ROOT}libft ${BLOCK}
	${AT} ${MAKE} clean -C ${LIB_ROOT}minilibx_mms ${BLOCK}
	${AT} rm -f libmlx.dylib ${BLOCK}
	${AT}printf "$(_INFO) cleaned ${OBJ_ROOT} folder.\n" ${BLOCK}

.PHONY: fclean
fclean: clean
	${AT}rm -f ${NAMES} ${BLOCK}
	${AT}printf "$(_INFO) ${NAMES} removed.\n" ${BLOCK}

.PHONY: re
re: fclean all

# **************************************************************************** #
#
# Debug Targets
#
# **************************************************************************** #

debug_san: CFLAGS += ${DFLAGS} ${FSANITIZE}
debug_san: all

debug: CFLAGS += ${DFLAGS}
debug: all

debug_re: fclean debug

# **************************************************************************** #
#
# Norminette Targets
#
# **************************************************************************** #

.PHONY: norm
norm:
	${AT} norminette ${SRCS} ${INC_ROOT} ${BLOCK}

.PHONY: norm_status
norm_status:
	${AT} printf "${_NORM}\n\n" ${BLOCK}
	${AT} printf "${_NORM_INFO}" ${BLOCK}
	${AT} norminette ${SRCS} ${INC_ROOT}|wc -l ${BLOCK}
	${AT} printf "${_NORM_SUCCESS}" ${BLOCK}
	${AT} norminette ${SRCS} ${INC_ROOT}|grep -wc "OK" ${BLOCK}


# **************************************************************************** #
#
# Target Templates
#
# **************************************************************************** #

define make_obj
${1} : ${2}
	$${AT}mkdir -p $${@D} $${BLOCK}
	$${AT} $${CC} $${OFLAGS} $${CFLAGS} $${INCS} -I$${LIB_ROOT}$${MLX} -c $$< -o $$@ $${BLOCK}
endef

# **************************************************************************** #
#
# Target Generator
#
# **************************************************************************** #

$(foreach src,${SRCS},$(eval\
$(call make_obj,$(subst ${SRC_ROOT},${OBJ_ROOT},${src:.c=.o}),${src})))
