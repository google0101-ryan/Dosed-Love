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

Choice(
    ChoiceA(SetVar("DidChoseA", 1), LoadDiag("path/to/next/tree.dg")),
    ChoiceB(SetVar("DidChoseB", 1), LoadDiag("path/to/next/tree2.dg"))
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