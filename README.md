_This project has been created as part of the 42 curriculum by bucolak._

# C++ Modules (CPP00 – CPP09) 

My solutions to the ten **C++98** modules of the 42 curriculum — a step-by-step introduction to object-oriented programming, from classes to templates and the STL. Every exercise compiles with `c++ -Wall -Wextra -Werror -std=c++98`.

| Module | Topics | Highlights |
|---|---|---|
| **CPP00** | Namespaces, classes, member functions, iostream | Megaphone, PhoneBook, Account |
| **CPP01** | Memory allocation, references, pointers to members, `switch` | Zombie horde, references vs pointers (Weapon), file search-and-replace, Harl complaint filter |
| **CPP02** | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form | `Fixed` fixed-point number class with arithmetic and comparison operators |
| **CPP03** | Inheritance | ClapTrap → ScavTrap / FragTrap → DiamondTrap (diamond problem) |
| **CPP04** | Subtype polymorphism, abstract classes, interfaces | Animal / Dog / Cat, deep copy with `Brain`, abstract base class |
| **CPP05** | Exceptions | Bureaucrat, abstract `AForm` with concrete forms, Intern factory |
| **CPP06** | C++ casts | `ScalarConverter`, serialization with `reinterpret_cast`, type identification with `dynamic_cast` |
| **CPP07** | Templates | `swap` / `min` / `max`, `iter`, `Array<T>` class template |
| **CPP08** | Templated containers, iterators, algorithms | `easyfind`, `Span` |
| **CPP09** | STL containers | Bitcoin exchange (`std::map` + CSV), RPN calculator (`std::stack`), Ford–Johnson merge-insertion sort (`PmergeMe`) with two containers |

## Build

```bash
cd CPP09/ex02
make
./PmergeMe 3 5 9 7 4
```

## Concepts Practised

Encapsulation · inheritance · polymorphism · Orthodox Canonical Form · RAII and memory management · exceptions · casts · templates · STL containers, iterators and algorithms

## Author

**Buket Çolak** (bucolak) — [github.com/bucolak](https://github.com/bucolak)
