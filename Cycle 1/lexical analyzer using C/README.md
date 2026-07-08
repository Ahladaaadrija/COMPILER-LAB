# Compiler Design Lab

This repository contains the programs implemented as part of the **Compiler Design Laboratory**. The experiments cover various phases of compiler construction, including lexical analysis, parsing techniques, syntax analysis, intermediate code generation, automata theory, and compiler construction using **Lex** and **YACC**.

## Language Used

* **C**
* **Lex (Flex)**
* **YACC (Bison)**

## Repository Structure

```text
Compiler-Design-Lab/
│
├── Cycle-1/
│   ├── Experiment-01-Lexical-Analyzer/
│   ├── Experiment-02-Recursive-Descent-Parser/
│   ├── Experiment-03-First-and-Follow/
│   ├── Experiment-04-Shift-Reduce-Parser/
│   ├── Experiment-05-Constant-Propagation/
│   ├── Experiment-06-Intermediate-Code-Generation/
│   ├── Experiment-07-Epsilon-Closure/
│   └── Experiment-08-NFA-to-DFA/
│
├── Cycle-2/
│   ├── Experiment-01-Lexical-Analyzer-Using-Lex/
│   ├── Experiment-02-Line-Word-Character-Count/
│   ├── Experiment-03-Substring-Replacement/
│   ├── Experiment-04-Vowel-and-Consonant-Count/
│   ├── Experiment-05-Arithmetic-Expression-Parser/
│   ├── Experiment-06-Identifier-Recognition/
│   ├── Experiment-07-Calculator-Using-Lex-YACC/
│   └── Experiment-08-AST-Generation/
│
└── README.md
```

## Cycle 1

| No. | Experiment                                                                                                                                                                                      |
| :-: | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|  1  | Design and implement a lexical analyzer using C language to recognize all valid tokens in the input program. The lexical analyzer should ignore redundant spaces, tabs, newlines, and comments. |
|  2  | Design and implement a recursive descent parser for a given grammar.                                                                                                                            |
|  3  | Write a program to find **FIRST** and **FOLLOW** sets of any given grammar.                                                                                                                     |
|  4  | Construct a Shift Reduce Parser for a given language.                                                                                                                                           |
|  5  | Write a program to perform constant propagation.                                                                                                                                                |
|  6  | Implement intermediate code generation for simple expressions.                                                                                                                                  |
|  7  | Write a program to find the **ε-closure** of all states of a given NFA with ε-transitions.                                                                                                      |
|  8  | Write a program to convert an NFA to a DFA.                                                                                                                                                     |

## Cycle 2

| No. | Experiment                                                                                                                           |
| :-: | ------------------------------------------------------------------------------------------------------------------------------------ |
|  1  | Implement a lexical analyzer for a given program using **Lex**.                                                                      |
|  2  | Write a Lex program to display the number of lines, words, and characters in an input text.                                          |
|  3  | Write a Lex program to convert the substring **abc** to **ABC** in the given input string.                                           |
|  4  | Write a Lex program to count the total number of vowels and consonants in the given input string.                                    |
|  5  | Generate a YACC specification to recognize a valid arithmetic expression using `+`, `-`, `*`, `/`, and parentheses.                  |
|  6  | Generate a YACC specification to recognize a valid identifier that starts with a letter followed by any number of letters or digits. |
|  7  | Implement a calculator using **Lex** and **YACC**.                                                                                   |
|  8  | Convert BNF rules into YACC form and generate an Abstract Syntax Tree (AST).                                                         |

## Prerequisites

* GCC Compiler
* Flex (Lex)
* Bison (YACC)
* Linux / macOS / Windows (WSL or MinGW)

## Compilation

### C Programs

```bash
gcc program.c -o program
./program
```

### Lex Programs

```bash
lex program.l
gcc lex.yy.c -o program -ll
./program
```

### YACC Programs

```bash
yacc -d program.y
lex program.l
gcc y.tab.c lex.yy.c -o program -ll
./program
```

## Course Outcomes

* Understand the phases of a compiler.
* Implement lexical and syntax analyzers.
* Apply parsing techniques for context-free grammars.
* Generate intermediate code for expressions.
* Perform basic code optimization.
* Understand finite automata and grammar transformations.
* Build language processors using Lex and YACC.

## License

This repository is maintained for educational and academic purposes as part of the **Compiler Design Laboratory**.
