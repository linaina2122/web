#include "../webserv.hpp"

int ft_check(server s);
int check_tab(server s);
int check_space(server s);
server *pars_config(server *s, int count)
{
    int index = 0;
    while (index < count)
    {
        if (check_brackets(s[index]))
        {
            std::cout << "error brackets\n";
            exit(0);
        }
        if (ft_check(s[index]))
        {
            std::cout << "error parsing\n";
            exit(0);
        }
        if (check_tab(s[index]))
        {
            std::cout << "error tab\n";
            exit(0);
        }
        if(check_space(s[index]))
        {
            std::cout << "error space\n";
            exit(0);
        }
        index++;
    }
    return (s);
}

int find_first_location(server v)
{
    int index = 0;
    std::vector<std::string>::iterator it = v.vec.begin();
    while (it != v.vec.end())
    {
        if (it->find("location") != std::string::npos)
            break;
        index++;
        it++;
    }
    return (index);
}

int count_bracket(server v)
{
    int count = 0;
    int count2 = 0;
    std::vector<std::string>::iterator it = v.vec.begin();
    while (it != v.vec.end())
    {
        if (it->find("{") != std::string::npos)
            count++;
        if (it->find("}") != std::string::npos)
            count2++;
        it++;
    }
    if (count != count2)
        return (1);
    return (0);
}
int check_brackets(server v)
{
    int dis;
    int check = find_first_location(v);
    std::vector<std::string>::iterator it = v.vec.begin();
    while (it != v.vec.end())
    {
        if (it->find("{}") != std::string::npos)
            return (1);
        if (it->find("Server") != std::string::npos)
        {

            if (!(it->find("{") != std::string::npos))
                return (1);
        }
        if (it->find("location") != std::string::npos)
        {
            if (!(it->find("{") != std::string::npos))
                return (1);
            dis = std::distance(v.vec.begin(), it);
            if (dis == check)
            {
                it++;
                continue;
            }
            else
            {
                std::string tmp = *(it - 1);
                if (!((tmp.find("}") != std::string::npos)))
                    return (1);
            }
        }
        if ((it + 1) == v.vec.end())
        {
            std::string tmp = *(it - 1);
            if (!(it->find("}") != std::string::npos) || !(tmp.find("}") != std::string::npos))
                return (1);
        }
        it++;
    }
    if (count_bracket(v))
        return (1);
    return (0);
}

int ft_check(server s)
{
    std::vector<std::string>::iterator it = s.vec.begin();
    while (it != s.vec.end())
    {
        if (it->find('{') != (it->length() - 1) && it->find('}') != (it->length() - 1) && it->find(';') != (it->length() - 1))
            return (1);
        it++;
    }
    return (0);
}

int check_tab(server s)
{
    std::vector<std::string>::iterator it = s.vec.begin();
    while (it != s.vec.end() && it + 1 != s.vec.end())
    {
        if (it->find("Server") != std::string::npos)
        {
            it++;
            while (!(it->find("location") != std::string::npos))
            {
                if (it->at(0) != '\t')
                    return (1);
                it++;
            }
        }

        if ((it->find("location") != std::string::npos) || it->find("}") != std::string::npos)
        {
            if (it->at(0) != '\t')
                return (1);
        }
        else if (it->at(0) != '\t' || it->at(1) != '\t')
            return (1);
        it++;
    }
    if (*it != "}")
        return (1);
    return (0);
}

int check_space(server s)
{
    std::vector<std::string>::iterator it = s.vec.begin();
    while (it != s.vec.end() && it + 1 != s.vec.end())
    {
        if (it->find(":") != std::string::npos)
        {
            int i = it->find(":");
            if(it->at(i - 1) != ' ' || it->at(i + 1) != ' ')
                return(1);
        }
        it++;
    }
    return(0);
}

server *parsing_functions(server *s, int count)
{
    s = pars_config(s, count);
    s = location_bloc(s, count);

    // int index = 0;
    s = set_bloc(s, count);
    s = fill_default(s, count);
    check_directives(s, count);
    check_dup(s, count);
    check_root(s, count);
    // check_methode(s, count);
    // while (index < count)
    // {
    //     std::cout <<  s[index].get(s[index].s_content, "client_max_body_size") << std::endl;
    //     std::cout <<  s[index].ft_get(s[index].s_content, "host") << std::endl;
    //     std::cout << s[index].get_loc_dir(s[index].vectorOfloc, "/.mp4", "i_pattern") << std::endl;
    //     index++;
    // }
    return (s);
}
