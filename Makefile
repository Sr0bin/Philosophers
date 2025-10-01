# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 14:14:19 by rorollin          #+#    #+#              #
#    Updated: 2025/10/01 17:23:06 by rorollin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

#SOURCES######################

SOURCES_DIR = src

SOURCES_NAME = main.c

#---------------------------

SOURCES_MUTEX = mutex_int.c mutex_bool.c

#---------------------------

SOURCES_CONTEXT = context_init.c ft_atoi.c param_init.c parsing.c

#---------------------------

SOURCES_PHILO = philo_init.c

#---------------------------

SOURCES_TIME = time_init.c granular_sleep.c

#---------------------------

SOURCES_FORK = fork_init.c fork_pair.c

#---------------------------

SOURCES_THREAD = thread_init.c

#---------------------------

SOURCES_DEBUG = debug.c

#---------------------------

SOURCES = $(addprefix $(SOURCES_DIR)/,\
		  $(SOURCES_NAME)\
		  $(addprefix mutex/, $(SOURCES_MUTEX))\
		  $(addprefix fork/, $(SOURCES_FORK))\
		  $(addprefix philosophers/, $(SOURCES_PHILO))\
		  $(addprefix context/, $(SOURCES_CONTEXT))\
		  $(addprefix time/, $(SOURCES_TIME))\
		  $(addprefix thread/, $(SOURCES_THREAD))\
		  $(addprefix .hidden/, $(SOURCES_DEBUG))\
		  )
		  
#OBJECTS#######################

OBJ_DIR = obj

OBJECTS = $(SOURCES:%.c=$(OBJ_DIR)/%.o)

#DEPS##########################

DEPS = $(SOURCES:%.c=$(OBJ_DIR)/%.d)

#INCLUDES#######################

HEADERS_DIR = include/

INCLUDES = $(addprefix -I , $(HEADERS_DIR)) 

#COMPILER#####################

COMPILER = cc

CFLAGS_DEBUG = -Wall -Wextra -Werror -MMD -MP -ggdb3 -Wshadow -Wconversion -Wsign-conversion \
-Wformat=2 -Wformat-security -Wnull-dereference -Wstack-protector -Wfloat-equal -Wpointer-arith \
-Wcast-align -Wundef -Wbad-function-cast -Wstrict-overflow=4 -Wdouble-promotion -Walloca -Wvla \
-Wwrite-strings -Wuninitialized -fno-delete-null-pointer-checks -fno-omit-frame-pointer -std=c11 \
-Iinclude

CFLAGS_PROD = -Wall -Wextra -MMD -MP -ggdb

CFLAGS = $(CFLAGS_PROD)

export CFLAGS

all: $(NAME)

$(NAME):  $(OBJECTS)
	$(COMPILER) $(CFLAGS) $(INCLUDES) $^ -o $@
	@echo "$(NAME) built succesfully."


$(OBJ_DIR)/%.o: %.c 
	mkdir -p $(dir $@)
	$(COMPILER) $(CFLAGS) $(INCLUDES) -c $< -o $@

-include $(DEPS)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf .cache/
	@rm -f .bonus
	@echo "Cleaned !"

fclean:
	@$(MAKE) clean
	@rm -f $(NAME)
	@echo "Fcleaned !"

re:	
	$(MAKE) fclean 
	$(MAKE) all


.PHONY: all clean fclean re
