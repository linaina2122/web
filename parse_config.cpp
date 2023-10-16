// #include "webserv.hpp"
    // std::cout << *it << std::endl;
        //  count2 = count_location(s[index]);
        // std::cout << count2 << std::endl;    // std::cout << *it << std::endl;
        //  count2 = count_location(s[index]);
        // std::cout << count2 << std::endl;    // std::cout << *it << std::endl;
        //  count2 = count_location(s[index]);
        // std::cout << count2 << std::endl;    // std::cout << *it << std::endl;
        //  count2 = count_location(s[index]);
        // std::cout << count2 << std::endl;    // std::cout << *it << std::endl;
        //  count2 = count_location(s[index]);
        // std::cout << count2 << std::endl;    // std::cout << *it << std::endl;
        //  count2 = count_location(s[index]);
        // std::cout << count2 << std::endl;    // std::cout << *it << std::endl;
        //  count2 = count_location(s[index]);
        // std::cout << count2 << std::endl;    // std::cout << *it << std::endl;
        //  count2 = count_location(s[index]);
        // std::cout << count2 << std::endl;    // std::cout << *it << std::endl;
        //  count2 = count_location(s[index]);
        // std::cout << count2 << std::endl;    // std::cout << *it << std::endl;
        //  count2 = count_location(s[index]);
        // std::cout << count2 << std::endl;    // std::cout << *it << std::endl;
        //  count2 = count_location(s[index]);
        // std::cout << count2 << std::endl;    // std::cout << *it << std::endl;
        //  count2 = count_location(s[index]);
        // std::cout << count2 << std::endl;    // std::cout << *it << std::endl;
        //  count2 = count_location(s[index]);
        // std::cout << count2 << std::endl;

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

// store *split(store *v, int count)
// {
//     int index;
//     int i;
//     index = 0;
//     while(index < count)
//     {
//         i = 0;
//         std::vector<char>::iterator it = v[index].vec.begin();
//         while(it < v[index].vec.end())
//         {
//             if(*it == '\t' || *it == '}')
// 			{
//             	v[index].vec.insert(it ,'\n');
// 				it = it + 1;
// 			}
//             it++;
//             i++;
//         }
//         index++;
//     }
//     return(v);
// }

// int check_brackets(store v)
// {
//     int index = 0;
//     int index2 = 0;
//     std::vector<char>::iterator it = v.vec.begin();
//     while(it < v.vec.end())
//     {
//         if(*it == '{')
//             index++;
//         if(*it == '}')
//             index2++;
//         it++;
//     }
//     if(index != index2)
//         return(1);
//     return(0);
// }