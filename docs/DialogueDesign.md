# File Specification for Dialogue

## File Conventions

1. All dialogue files must end with .dg
2. A .txt document must be created at the root directory, containing the file path of the first .dg file. This file must be named `diagroot.txt`
3. These files should not be modified manually. Instead see documentation for `Dialogue Editor`. This document is for developer reference

## File Format Specifications

All dialogue files are plain text files ending with the `.dg` extension. The format is as follows:

```
DIAG    // Magic

Character A(path/to/portrait.png): "Dialogue A with *formatting*";

Character B(path/to/portrait2.png): "Dialogue B with **bold**";

TimedChoice(5,
    "I choose quickly"(SetVar("DidChoseQuickly", 1), LoadDiag("path/to/next/tree_quickly.dg")))

Choice(
    "I choose A"(SetVar("DidChoseA", 1), LoadDiag("path/to/next/tree.dg")),
    "I choose B"(SetVar("DidChoseB", 1), LoadDiag("path/to/next/tree2.dg"))
);
```

Each part of this will be broken down in the next section:

### Magic Number

All `.dg` files must begin with `DIAG` in all caps on its own line. This allows the engine to double-check that this file really is a dialogue file

### Dialogue

Each piece of dialogue must begin with the characters name in plain text. This will be displayed at the top of the text box. e.x.: `Jane Doe()` will display "Jane Doe" at the top of a text box.

Inside of the parenthesis goes the path to the character portrait to appear on-screen, relative to the `Assets` folder. For example, if the PNG was in `C:\Users\username\Downloads\VisualNovel\Assets\Portraits\character2.png`, then the path inside the parenthesis would be `Portraits/character2.png`, i.e. `Jane Doe(Portraits/character2.png)`.

#### <span style="color: yellow">NOTE</span>: All paths must use `/` regardless of platform

#### <span style="color: red">TODO</span>: Add left/right/center align options

Following that, you must use a colon to indicate the start of spoken dialogue. Everything inside of the following quotation marks will be displayed inside of the text box. Formatting rules are described in [Formatting.md](Formatting.md).

#### <span style="color: red">TODO</span>: Write Formatting.md

#### <span style="color: red">TODO</span>: Add timing options

Example dialogue:

```
Jane Doe(Portraits/JaneDoe.png): "Hi, what's your name?"
```

## Decision Trees

What would a visual novel be without player choices? We have two options here: load a new dialogue tree, or save data to a variable (will be written to disk).

Choice trees begin with the `Choice` keyword, followed by the choice text in quotes (this is displayed as a bulleted list).

For example:
```
Choice "I choose A!"(...)

Choice "I choose B!"(...)
```
would appear as
```
+/P̅L̅A̅Y̅E̅R̅\-----------------+
|  1. I choose A!         |
|  2. I choose B!         |
+-------------------------+
```

Inside of the parenthesis is a comma-seperated list of items, each being a keyword.

#### Choice keywords

Inside of the comma-seperated list of choices, each one must consist of one of the following keywords first:

- `SetVar`
- `LoadTree`

These will be described in more detail below.

#### SetVar:

The `SetVar` keyword will create a variable that is saved to disk, which can then be referenced later by the engine.

Usage:  
`SetVar(varName, value)`

`varName`: ASCII string name the variable will be referenced by. Must be quoted.  
`value`: Any number, string, or boolean that will be saved to the variable.

Example:  
```
SetVar("ExampleVar", "This is an example Var");
SetVar("ExampleBooleanVar", false);
SetVar("ExampleIntVar", 100);
```


#### AddVar:

`AddVar` will add one to a pre-existing variable. Previously uncreated variables will be initialized to 0.

Usage:
`AddVar(varName amount)`

`varName`: The name of the variable to modify
`amount`: A positive or negative amount to modify the variable by

#### <span style="color: yellow">NOTE</span>: Trying to use this on a string or boolean will throw an error in the log, and execution will continue as normal, skipping the modification.

#### LoadTree:

The `LoadTree` keyword will load a new dialogue file and begin executing it. Used for branching paths in dialogue.

Usage:
`LoadTree(path)`

`path`: Path relative to the `Assets` folder in the game's install location.

Example:
```
LoadTree(Dialogue/tree.dg)
```

## TimedChoice

Exactly the same as the `Choice` keyword, except the first argument is a number, in seconds, the user has to answer. Failure to answer in the given time frame will continue execution below.