#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

template<typename T1, typename T2>
class Registry
{
    std::vector<std::pair<T1,T2>> list;

public:
    void add()
    {
        T1 _key;
        T2 _value;
        std::cout << "Input the key (" << typeid(T1).name() << ") and value (" << typeid(T2).name() << ") to be added to the registry:" << std::endl;
        std::cin >> _key;
        std::cin >> _value;
        list.push_back(std::pair<T1,T2> (_key, _value));
    }
    void remove()
    {
        T1 _key;
        std::cout << "Input the key (" << typeid(T1).name() << ") to remove from the registry:" << std::endl;
        std::cin >> _key;
        for(int i=0;i < list.size();)
        {
            if(list[i].first == _key)
                list.erase(list.begin() + i);
            else ++i;
        }
    }
    void print() const
    {
        for(auto it = list.begin();it != list.end();++it)
        {
            std::cout << "Value: " << it->second << " Key: " << it->first << std::endl;
        }
    }
    void find() const
    {
        T1 _key;
        std::cout << "Input the key (" << typeid(T1).name() << ")to search in the registry:" << std::endl;
        std::cin >> _key;
        for(auto it = list.begin();it != list.end();++it)
        {
            if (it->first == _key)
                std::cout << it->second << " ";
        }
        std::cout << std::endl;
    }
};

bool correct_action(std::string _action, std::vector<std::string>& _commands)
{
    for(const auto& i : _commands)
    {
        if (i == _action) return true;
    }
    return false;
}

int main() {
    Registry<int, double> registry;
    std::vector<std::string> commands = {"add","remove","print","find","exit"};
    std::string action;

    while (action != "exit")
    {
        do
        {
            std::cout << "Enter a command from the list to execute:" << std::endl;
            std::cout << "-- add\n-- remove\n-- print\n-- find\n-- exit\n>";
            std::cin >> action;
            if (!correct_action(action, commands)) std::cout << "Incorrect operation! Repeat input." << std::endl;
        } while (!correct_action(action, commands));

        if (action == commands[0]) registry.add();
        else if (action == commands[1]) registry.remove();
        else if (action == commands[2]) registry.print();
        else if (action == commands[3]) registry.find();
    }
    return 0;
}
