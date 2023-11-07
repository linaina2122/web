Name = webserv
CPPFlags = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
Srcs = main.cpp \
	   parsing/parse_config.cpp \
	   parsing/read_from_file.cpp \
	   parsing/get_directives.cpp \
	   parsing/check_directives.cpp \
	   parsing/get_server.cpp \
	   parsing/get_location.cpp
Objcs = $(Srcs:.cpp=.o)
Clean = rm -rf
All : $(Name)
$(Name) : $(Objcs)
	c++ $(Srcs) $(CPPFlags) -o $(Name)
clean : 
		$(Clean) $(Objcs)
fclean : 
		$(Clean) $(Objcs) $(Name)
re : fclean All 
