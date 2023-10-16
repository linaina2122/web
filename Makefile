Name = webserv
CPPFlags = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
Srcs = main.cpp \
	   parse_config.cpp \
	   read_from_file.cpp
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


