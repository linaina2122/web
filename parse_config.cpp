#include "webserv.hpp"

// void print(store *s, int count)
// {
//     int index = 0;
//     while(index < count)
//     {
//         std::vector<char>::iterator it = s[index].vec.begin();
//         while(it < s[index].vec.end())
//         {
//             std::cout << *it;
//             it++;
//         }
//         index++;
//     }
// }
server *pars_config(server* s, int count)
{
    int index = 0;
    while(index < count)
    {
        if(check_brackets(s[index]))
        {
            std::cout << "error brackets\n";
            exit(0);
        }
        // while(it != s[index].vec.end())
        // {
		// 	if(*it == '{' && *(it - 1) != ' ')
		// 	{
		// 		std::cout << "error parsing\n";
		// 		exit(0);
		// 	}
		// 	if(*it == ':' && (*(it + 1) != ' ' || *(it - 1) != ' '))
		// 	{
		// 		std::cout << "error parsing\n";
		// 		exit(0);
		// 	}
		// 	if(*it == ';' && *(it + 1) == '}')
		// 		it++;
        //     else if((*it == ';' && *(it + 1) != '\t') || ((*it == '{' && *(it + 1) != '\t')))
        //     {
        //         std::cout << "error parsing\n";
        //         exit(0);
        //     }
        //     it++;
        // }
        index++;
    }
    return (s);
}

int find_first_location(server v)
{
    int index = 0;
    std::vector<std::string>::iterator it = v.vec.begin();
    while(it != v.vec.end())
    {
        if(it->find("location") != std::string::npos)
            break;
        index++;
        it++;
    }
    return(index);
}

int count_bracket(server v)
{
    int count = 0;
    int count2 = 0;
    std::vector<std::string>::iterator it = v.vec.begin();
    while(it != v.vec.end())
    {
        if(it->find("{") != std::string::npos)
            count++;
        if(it->find("}") != std::string::npos)
            count2++;
        it++;      
    }
    if(count != count2)
        return(1);
    return(0);
}
int check_brackets(server v)
{
    int dis;
    int check = find_first_location(v);
    std::vector<std::string>::iterator it = v.vec.begin();
    while(it != v.vec.end())
    {
        if(it->find("Server") != std::string::npos)
        {

            if(!(it->find("{")!= std::string::npos))
                return(1);
        }
        if(it->find("location") != std::string::npos)
        {
            if(!(it->find("{")!= std::string::npos))
                return(1);
            dis = std::distance(v.vec.begin(), it);
            if(dis == check)
            {
                it++;
                continue;
            }
            else
            {
                std::string tmp = *(it - 1);
                if(!((tmp.find("}") != std::string::npos)))
                    return(1);
            }
        }
        if((it + 1) == v.vec.end())
        {
            std::string tmp = *(it - 1);
            if(!(it->find("}") != std::string::npos )|| !(tmp.find("}") != std::string::npos))
                return(1);
        }
        it++;
    }
    if(count_bracket(v))
        return(1);
    return(0);
}

// int ft_check(std::string s)
// {
//     int  i = 0;
//     while(s[i])
//     {
//         if(s[i] == ';')
//         {
//             i++;
//         if(s[i] == '\n')
//             return(1);
//     }
// }
int check_new_line(server v)
{
    std::vector<std::string>::iterator it = v.vec.begin();
    while(it != v.vec.end())
    {
        if(!(it->find(";") !=  std::string::npos))
            return(1);
        
    }
}
