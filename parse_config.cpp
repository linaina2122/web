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
// store *pars_config(store *s, int count)
// {
//     int index = 0;
//     while(index < count)
//     {
//         std::vector<char>::iterator it = s[index].vec.begin();
//         if(check_brackets(s[index]))
//         {
//             std::cout << "error brackets\n";
//             exit(0);
//         }
//         while(it != s[index].vec.end())
//         {
// 			if(*it == '{' && *(it - 1) != ' ')
// 			{
// 				std::cout << "error parsing\n";
// 				exit(0);
// 			}
// 			if(*it == ':' && (*(it + 1) != ' ' || *(it - 1) != ' '))
// 			{
// 				std::cout << "error parsing\n";
// 				exit(0);
// 			}
// 			if(*it == ';' && *(it + 1) == '}')
// 				it++;
//             else if((*it == ';' && *(it + 1) != '\t') || ((*it == '{' && *(it + 1) != '\t')))
//             {
//                 std::cout << "error parsing\n";
//                 exit(0);
//             }
//             it++;
//         }
//         index++;
//     }
//     return (s);
// }

int check_brackets(server v)
{
    int count = 0;
    int count2 = 0;
    std::vector<std::string>::iterator it = v.vec.begin();
    while(it != v.vec.end())
    {
        if(it->find("server") != std::string::npos || it->find("location") != std::string::npos)
        {
            if()
        }
            return(1);
        

    }
}