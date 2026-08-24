# C++ Modules

42 School's C++ curriculum (CPP00–CPP09): ten modules, each a step up in modern C++ features taught from a C background — starting with classes and ending with STL containers and algorithms.

Each `exNN` folder is self-contained and builds with its own `Makefile` (`make`, `make re`, `make clean`, `make fclean`).

## CPP00 — Namespaces, Classes, Member Functions, Streams

- **ex00**: string streams and basic I/O manipulation (`megaphone`).
- **ex01**: a first real class design — `PhoneBook`/`Contact` — private data with public accessors, fixed-size arrays, and separating declaration (`.hpp`) from implementation (`.cpp`).

## CPP01 — Memory Allocation, References, Pointers

- **ex00/ex01**: stack vs. heap allocation (`new`/`delete`), and the difference between returning a pointer vs. a reference from a factory function.
- **ex02**: pointers vs. references to the same object, and address-of behavior.
- **ex03**: multiple inheritance and interfaces (`HumanA`/`HumanB` wielding a shared `Weapon` by reference vs. pointer).
- **ex04**: file I/O — reading a file and writing a modified copy (a mini `sed`).
- **ex05/ex06**: function pointers and arrays of member-function pointers to dispatch behavior without a chain of `if`/`switch`.

## CPP02 — Ad-hoc Polymorphism, Operator Overloading, Orthodox Canonical Form

- **ex00/ex01/ex02**: the `Fixed`-point number class, built incrementally — the Orthodox Canonical Form (default/copy constructor, copy assignment, destructor), then operator overloading (`+ - * / == < > ++ -- << `), converting between fixed-point and floating-point representations.

## CPP03 — Inheritance

- **ex00**: base class `ClapTrap` with hit points, energy points, and damage.
- **ex01**: `ScavTrap` inherits from `ClapTrap`, overriding behavior and adding an ability.
- **ex02**: diamond-free multiple inheritance — `FragTrap` and `ScavTrap` both derive from `ClapTrap`.

## CPP04 — Subtype Polymorphism, Abstract Classes, Interfaces

- **ex00**: virtual functions — `Animal` base with `Dog`/`Cat` overriding `makeSound`, called through a base pointer.
- **ex01**: deep vs. shallow copy — giving `Animal` a `Brain` member and managing it correctly across copy/assignment.
- **ex02**: abstract classes (pure virtual functions) — `Animal` can no longer be instantiated directly; interfaces.

## CPP05 — Repetition and Exceptions

- **ex00**: custom exceptions nested inside a class (`Bureaucrat`'s grade bounds).
- **ex01**: an abstract `Form` that a `Bureaucrat` can sign, with its own exceptions.
- **ex02**: `AForm` as a pure interface signed and executed by a `Bureaucrat`, with concrete forms (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`).
- **ex03**: an `Intern` that manufactures the right `AForm` subclass from a string name (a small factory).

## CPP06 — Casts

- **ex00**: `ScalarConverter` — parsing a literal and converting it between `char`, `int`, `float`, and `double`, handling edge cases (nan, inf, non-printable chars).
- **ex01**: `reinterpret_cast` — serializing a pointer to an integer and back.
- **ex02**: `dynamic_cast` — identifying the real derived type of a base-class pointer/reference at runtime.

## CPP07 — Templates

- **ex00**: a templated function (`whatever`) that swaps, finds min/max, and prints values generically.
- **ex01**: a templated function (`iter`) that applies another function to every element of an array.
- **ex02**: a templated `Array` class, with the implementation split into a `.tpp` file included by the header.

## CPP08 — Templated Containers, Iterators, Algorithms

- **ex00**: `easyfind` — a templated function using STL algorithms (`std::find`) over any container.
- **ex01**: `Span` — a class that stores a collection of integers and computes the shortest/longest span between any two, using STL algorithms and iterators.
- **ex02**: `MutantStack` — a `std::stack` subclass made iterable by exposing its underlying container's iterators.

## CPP09 — STL

- **ex00**: `BitcoinExchange` — parsing a CSV database and an input file, validating dates/values, and looking up exchange rates with `std::map`.
- **ex01**: `RPN` — a Reverse Polish Notation calculator using `std::stack`.
- **ex02**: `PmergeMe` — implementing the merge-insertion sort (Ford-Johnson algorithm) on two different containers (`std::vector` and `std::deque`) and comparing their performance.
